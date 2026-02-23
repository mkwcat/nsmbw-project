// m_archive.cpp
// nsmbw-project

#include "m_dvd.h"

#include <algorithm>
#include <cassert>
#include <cstring>
#include <revolution/os/OSCache.h>
#include <revolution/os/OSError.h>

namespace mDvd
{

MultiArchiveBuilder_c::MultiArchiveBuilder_c(
  EGG::Heap* heap, EGG::DvdRipper::EAllocDirection allocDir, u32 dstMaxCount, u32 dstStrTabMaxSize
)
  : mHeap(heap)
  , mAllocDir(allocDir)
  , mDstMaxCount(dstMaxCount)
  , mDstStrTabMaxSize(dstStrTabMaxSize)
{
}

MultiArchiveBuilder_c::~MultiArchiveBuilder_c()
{
    if (mDst != nullptr) {
        delete[] mDst;
    }

    if (mDstStrTab != nullptr) {
        delete[] mDstStrTab;
    }
}

s32 MultiArchiveBuilder_c::addString(const char* str)
{
    // Find if the string already exists
    for (u32 i = 0; i < mDstStrTabSize; i++) {
        if (std::strcmp(mDstStrTab + i, str) == 0) {
            return i;
        }
    }

    // Add the string to the table
    u32 strLen = std::strlen(str) + 1;
    assert(mDstStrTabSize + strLen <= mDstStrTabMaxSize);

    std::memcpy(mDstStrTab + mDstStrTabSize, str, strLen);
    mDstStrTabSize += strLen;

    return mDstStrTabSize - strLen;
}

s32 MultiArchiveBuilder_c::addEntry(FstEntry entry, const char* name, s32 dstIndex, s32 parent)
{
    if (dstIndex < 0) {
        dstIndex = mDstCount + dstIndex + 1;
    }

    if (dstIndex > mDstCount || dstIndex < 0 || dstIndex >= mDstMaxCount) {
        return ENTRY_NONE;
    }

    if (parent > ENTRY_NONE) {
        if (entry.isDir) {
            entry.dir.parent = std::max<s32>(parent, 0);
        }

        // Update all parents of this entry
        for (s32 last = ENTRY_NONE, next = parent; next != last; next = mDst[next].dir.parent) {
            mDst[next].dir.next += 1;
            last = next;
        }
    } else if (!entry.isDir) {
        // First entry has to be a directory
        return ENTRY_NONE;
    }

    if (dstIndex < mDstCount) {
        // Push all entries after this one down
        for (s32 i = mDstCount - 1; i >= dstIndex; i--) {
            mDst[i + 1] = mDst[i];
            if (mDst[i + 1].isDir) {
                mDst[i + 1].dir.parent += mDst[i + 1].dir.parent >= dstIndex;
                mDst[i + 1].dir.next += mDst[i + 1].dir.next >= dstIndex;
            }
        }
    }

    // Now add the entry
    FstEntry* dstEntry = mDst + dstIndex;
    *dstEntry = {
      .isDir = !!entry.isDir,
      .stringOffset = static_cast<u32>(addString(name)),
      .dir = {
        .parent = entry.dir.parent,
        .next = entry.isDir ? dstIndex + 1 : entry.file.length,
      },
    };

    mDstCount++;

    return dstIndex;
}

s32 MultiArchiveBuilder_c::addEntryStrTab(
  FstEntry entry, const char* strTab, s32 dstIndex, s32 parent
)
{
    return addEntry(entry, strTab + entry.stringOffset, dstIndex, parent);
}

s32 MultiArchiveBuilder_c::copyArchive2(
  const char* srcFst, u32 startIndex, s32 dstIndex, u32 offsetDisplacement
)
{
    const FstEntry* srcFstEntries = reinterpret_cast<const FstEntry*>(srcFst);
    const char* srcStrTab = srcFst + (srcFstEntries[0].dir.next * sizeof(FstEntry));

    assert(srcFstEntries[startIndex].isDir);
    s32 parent = dstIndex - 1;

    // Check if the destination has a root entry yet
    if (mDstCount == 0) {
        dstIndex = addEntryStrTab(srcFstEntries[startIndex], srcStrTab, 0, ENTRY_NONE);
        assert(dstIndex >= 0);
        dstIndex++;
    }

    u32 copyCount = srcFstEntries[startIndex].dir.next;

    for (u32 index = startIndex + 1; index < copyCount; index++) {
        const FstEntry* srcEntry = srcFstEntries + index;
        const char* srcEntryName = srcStrTab + srcEntry->stringOffset;
        if (isSkippableName(srcEntryName)) {
            continue;
        }

        FstEntry* dstEntry = nullptr;
        s32 cond = 1;

        // Check if the entry already exists, or find a place to insert this entry
        for (; dstIndex < mDstCount; dstIndex++) {
            dstEntry = mDst + dstIndex;
            const char* dstEntryName = mDstStrTab + dstEntry->stringOffset;
            if (isSkippableName(dstEntryName)) {
                continue;
            }

            cond = std::strcmp(srcEntryName, dstEntryName);
            if (cond <= 0) {
                break;
            }
        }

        FstEntry entryToAdd = *srcEntry;
        if (!entryToAdd.isDir) {
            entryToAdd.file.startAddr >>= 2;
            entryToAdd.file.startAddr += offsetDisplacement;
        }

        if (cond == 0) {
            // Replace an existing entry
            if (entryToAdd.isDir) {
                assert(dstEntry->isDir);
                // Recursively copy the directory
                dstIndex = copyArchive2(srcFst, index, dstIndex + 1, offsetDisplacement);
                assert(dstIndex >= 0);
                index = srcFstEntries[index].dir.next - 1;
            } else {
                dstEntry->file = entryToAdd.file;
                dstIndex++;
            }

            continue;
        }

        // Add a new entry
        dstIndex = addEntry(entryToAdd, srcEntryName, dstIndex, parent);
        assert(dstIndex >= 0);

        if (entryToAdd.isDir) {
            // Recursively copy the directory
            dstIndex = copyArchive2(srcFst, index, dstIndex + 1, offsetDisplacement);
            assert(dstIndex >= 0);
            index = srcFstEntries[index].dir.next - 1;
        } else {
            dstIndex++;
        }
    }

    return dstIndex;
}

bool MultiArchiveBuilder_c::copyArchive(
  const char* srcFst, u32 fstSize, u32 startIndex, u32 offsetDisplacement
)
{
    // Get max copy size
    FstEntry* srcFstEntries = (FstEntry*) srcFst;
    u32 oldDstMaxCount = mDstMaxCount;
    u32 oldDstStrTabMaxSize = mDstStrTabMaxSize;
    mDstMaxCount += srcFstEntries[startIndex].dir.next - startIndex;
    mDstStrTabMaxSize += fstSize - (srcFstEntries[0].dir.next * sizeof(FstEntry));

    u32 tmpAllocAlign = mAllocDir == EGG::DvdRipper::ALLOC_DIR_BOTTOM ? -4 : 4;

    // Allocate destination FST
    FstEntry* dstFst =
      static_cast<FstEntry*>(mHeap->alloc(sizeof(FstEntry) * mDstMaxCount, tmpAllocAlign));
    assert(dstFst != nullptr);

    // Allocate destination string table
    char* dstStrTab = static_cast<char*>(mHeap->alloc(mDstStrTabMaxSize, tmpAllocAlign));

    if (mDst != nullptr) {
        std::memcpy(dstFst, mDst, sizeof(FstEntry) * oldDstMaxCount);
        delete[] mDst;
    }
    mDst = dstFst;

    if (mDstStrTab != nullptr) {
        std::memcpy(dstStrTab, mDstStrTab, oldDstStrTabMaxSize);
        delete[] mDstStrTab;
    }
    mDstStrTab = dstStrTab;

    // Copy the FST
    return copyArchive2(srcFst, startIndex, 1, offsetDisplacement) >= 0;
}

u32 MultiArchiveBuilder_c::getTotalFileSize() const
{
    u32 totalSize = 0;
    for (u32 i = 0; i < mDstCount; i++) {
        if (!mDst[i].isDir) {
            totalSize += (mDst[i].file.length + 0x1F) & ~0x1F;
        }
    }

    return totalSize;
}

void MultiArchiveBuilder_c::addRootEntry(const char* name)
{
    if (mDstCount != 0) {
        return;
    }

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wvla-cxx-extension"

    // Create empty filesystem
    const u32 dataSize = sizeof(FstEntry) + std::strlen(name);
    char data[dataSize];

#pragma clang diagnostic pop

    FstEntry* rootEntry = reinterpret_cast<FstEntry*>(data);
    *rootEntry = {
      .isDir = 1,
      .stringOffset = 0,
      .dir = {
        .parent = 0,
        .next = 1,
      },
    };

    if (name != nullptr) {
        std::strcpy(data + sizeof(FstEntry), name);
    }

    copyArchive(data, dataSize);
}

void* MultiArchiveBuilder_c::loadArchive(
  EGG::DvdFile* dvdFile, char* path, EGG::Heap* heap, EGG::DvdRipper::EAllocDirection allocDir,
  u32* outAmountRead, u32* outFileSize
)
{
    ARCHandle* exArcHandle = DVDGetExArcHandle();
    if (exArcHandle == nullptr) {
        return nullptr;
    }

    ARCDir arcDir;
    if (!ARCOpenDir(exArcHandle, path, &arcDir)) {
        return nullptr;
    }

    const EGG::DvdRipper::EAllocDirection tmpAllocDir = allocDir == EGG::DvdRipper::ALLOC_DIR_BOTTOM
                                                          ? EGG::DvdRipper::ALLOC_DIR_TOP
                                                          : EGG::DvdRipper::ALLOC_DIR_BOTTOM;
    const u32 finalAllocAlign = allocDir == EGG::DvdRipper::ALLOC_DIR_BOTTOM ? -0x20 : 0x20;
    const u32 tmpAllocAlign = tmpAllocDir == EGG::DvdRipper::ALLOC_DIR_BOTTOM ? -0x20 : 0x20;

    MultiArchiveBuilder_c builder(heap, tmpAllocDir);

    if (dvdFile->mIsOpen) {
        ARCHeader arcHeader alignas(32);
        if (dvdFile->readData(&arcHeader, sizeof(ARCHeader), 0) != sizeof(ARCHeader)) {
            OS_REPORT("Failed to read ARC header\n");
            return nullptr;
        }

        if (arcHeader.magic != ARC_MAGIC) {
            OS_REPORT("Invalid ARC magic: %08lX\n", arcHeader.magic);
            return nullptr;
        }

        void* fstData = heap->alloc(arcHeader.fstSize, tmpAllocAlign);
        if (fstData == nullptr) {
            OS_REPORT("Failed to allocate FST buffer\n");
            return nullptr;
        }

        if (dvdFile->readData(fstData, arcHeader.fstSize, arcHeader.fstOffset) !=
            arcHeader.fstSize) {
            OS_REPORT("Failed to read FST\n");
            heap->free(fstData);
            return nullptr;
        }

        if (!builder.copyArchive(
              (char*) fstData, arcHeader.fstSize, 0, dvdFile->mFileInfo.startAddr
            )) {
            OS_REPORT("Failed to copy archive\n");
            heap->free(fstData);
            return nullptr;
        }

        heap->free(fstData);
    }

    builder.addRootEntry("");

    // Copy the ex ARC FST now
    {
        void* exArcFstData = exArcHandle->FSTStart;
        u32 exArcFstSize = exArcHandle->FSTLength;

        EGG::DvdFile exArcDvdFile;
        if (!exArcDvdFile.open(DVDGetExArchiveEntrynum())) {
            OS_REPORT("Failed to open ex ARC archive\n");
            return nullptr;
        }

        if (!builder.copyArchive(
              (char*) exArcFstData, exArcFstSize, arcDir.entryNum, exArcDvdFile.mFileInfo.startAddr
            )) {
            OS_REPORT("Failed to copy ex ARC archive\n");
            return nullptr;
        }
    }

    // Build the new archive
    const ARCHeader newArcHeader = {
      .magic = ARC_MAGIC,
      .fstOffset = sizeof(ARCHeader),
      .fstSize = builder.getDstCount() * sizeof(FstEntry) + builder.getDstStrTabSize(),
      .fileStart = ((newArcHeader.fstOffset + newArcHeader.fstSize) + 0x1F) & ~0x1F,
      .reserved = {0},
    };

    const u32 fileDataSize = builder.getTotalFileSize();

    char* newArcData =
      static_cast<char*>(heap->alloc(newArcHeader.fileStart + fileDataSize, finalAllocAlign));
    if (newArcData == nullptr) {
        OS_REPORT("Failed to allocate new ARC buffer\n");
        return nullptr;
    }

    std::memset(newArcData, 0, newArcHeader.fileStart + fileDataSize);

    std::memcpy(newArcData, &newArcHeader, sizeof(ARCHeader));
    const u32 fstEntrySize = sizeof(FstEntry) * builder.getDstCount();
    std::memcpy(newArcData + newArcHeader.fstOffset, builder.getDst(), fstEntrySize);
    std::memcpy(
      newArcData + newArcHeader.fstOffset + fstEntrySize, builder.getDstStrTab(),
      builder.getDstStrTabSize()
    );

    // Load the file data
    u32 fileDataOffset = newArcHeader.fileStart;
    FstEntry* fst = reinterpret_cast<FstEntry*>(newArcData + newArcHeader.fstOffset);
    const u32 fstCount = builder.getDstCount();
    for (u32 i = 0; i < fstCount; i++) {
        if (fst[i].isDir) {
            continue;
        }

        const u32 length = (fst[i].file.length + 0x1F) & ~0x1F;
        // This is silly but it's necessary for loading the file data!!
        dvdFile->mFileInfo.startAddr = fst[i].file.startAddr;
        dvdFile->mFileInfo.length = length;
        if (dvdFile->readData(newArcData + fileDataOffset, length, 0) != length) {
            OS_REPORT("Failed to read file data\n");
            heap->free(newArcData);
            return nullptr;
        }

        fst[i].file.startAddr = fileDataOffset;
        fileDataOffset += length;
    }

    DCStoreRange(newArcData, newArcHeader.fileStart + fileDataSize);

    OS_REPORT("Loaded archive %s\n", path);

    *outAmountRead = newArcHeader.fileStart + fileDataSize;
    *outFileSize = newArcHeader.fileStart + fileDataSize;

    return newArcData;
}

} // namespace mDvd