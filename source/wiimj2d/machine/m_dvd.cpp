// m_dvd.cpp
// NSMBW .text: 0x8016B090 - 0x8016C540

#include "m_dvd.h"

#include "machine/m_archive.h"
#include <cstring>
#include <egg/core/eggDvdFile.h>
#include <egg/core/eggDvdRipper.h>
#include <egg/core/eggExpHeap.h>
#include <optional>
#include <revolution/arc.h>
#include <revolution/dvd.h>
#include <revolution/os.h>
#include <revolution/os/OSCache.h>

namespace mDvd
{

int maxChunkSize = 0x10000;

[[nsmbw_data(0x8042A708)]]
/* static */ bool l_IsAutoStreamDecomp;

static bool l_IsRndizerRes = false;

/* 0x8016BBE0 */
/* static */ int ConvertPathToEntrynumASD_(const char* name, u8* outType);

static int ConvertPathToEntrynumBase(const char* path, u8* outType);

/* 0x8016BD70 */
/* static */ int ConvertPathToEntrynum(const char* path, u8* outType);

/* 0x8016B230 */
/* static */ EGG::StreamDecomp* newUncompressObj(u8 type);

/* 0x8016B270 */
/* static */ void deleteUncompressObj(u8 type);

} // namespace mDvd

[[nsmbw(0x8016B230)]]
/* static */ EGG::StreamDecomp* mDvd::newUncompressObj(u8 type);

[[nsmbw(0x8016B270)]]
/* static */ void mDvd::deleteUncompressObj(u8 type);

[[nsmbw(0x8016B3E0)]]
void* mDvd::loadToMainRAM(
  int entryNum, char* dst, EGG::Heap* heap, EGG::DvdRipper::EAllocDirection allocDir, s32 offset,
  u32* outAmountRead, u32* outFileSize, u32 decompressorType
)
{
    void* result = nullptr;
    u32 amountRead = 0;
    u32 fileSize = 0;

    static EGG::DvdFile dvdFile;

    if (decompressorType != 0) {
        EGG::StreamDecomp* decomp = newUncompressObj(decompressorType);

        dvdFile.open(entryNum);
        result = EGG::DvdRipper::loadToMainRAMDecomp(
          &dvdFile, decomp, (u8*) dst, heap, allocDir, offset, 0, maxChunkSize, nullptr, nullptr
        );
        fileSize = amountRead = EGG::ExpHeap::getSizeForMBlock(result);
        deleteUncompressObj(decompressorType);
        dvdFile.close();
        if (result != nullptr) {
            DCStoreRangeNoSync(result, EGG::ExpHeap::getSizeForMBlock(result));
        }
    } else {
        char path[256] = {};
        if (DVDEntrynumIsDir(entryNum) && dst == nullptr && heap != nullptr && offset == 0 && //
            DVDConvertEntrynumToPath(entryNum, path, sizeof(path) - 1)) {
            // Check if the path ends with .arc
            if (std::strlen(path) > 4 && std::strcmp(path + std::strlen(path) - 4, ".arc") == 0) {
                // Try arc subfile replacement
                dvdFile.open(__DVDPathToEntrynum(path));
                result = mMultiArchiveBuilder_c::loadArchive(
                  &dvdFile, path, heap, allocDir, &amountRead, &fileSize
                );
                dvdFile.close();
            }
        }

        if (result == nullptr) {
            result = EGG::DvdRipper::loadToMainRAM(
              entryNum, (u8*) dst, heap, allocDir, offset, &amountRead, &fileSize
            );
        }
    }

    if (outAmountRead != nullptr) {
        *outAmountRead = amountRead;
    }
    if (outFileSize != nullptr) {
        *outFileSize = fileSize;
    }

    return result;
}

void* mDvd::loadToMainRAM(
  const char* path, char* dst, EGG::Heap* heap, EGG::DvdRipper::EAllocDirection allocDir,
  s32 offset, u32* outAmountRead, u32* outFileSize, u32 decompressorType
)
{
    int entryNum = DVDConvertPathToEntrynum(path);
    if (entryNum < 0) {
        return nullptr;
    }

    return loadToMainRAM(
      entryNum, dst, heap, allocDir, offset, outAmountRead, outFileSize, decompressorType
    );
}

[[nsmbw(0x8016B630)]]
void mDvd_command_c::waitDone() const;

[[nsmbw(0x8016BBE0)]]
/* static */ int mDvd::ConvertPathToEntrynumASD_(const char* name, u8* outType);

[[nsmbw(0x8016BD60)]]
bool mDvd::isAutoStreamDecomp();

void mDvd::setOverlayRes(std::optional<bool> isRndizerRes)
{
    if (isRndizerRes.has_value()) {
        l_IsRndizerRes = *isRndizerRes;
    }
}

void mDvd::getOverlayRes(bool* isRndizerRes)
{
    if (isRndizerRes) {
        *isRndizerRes = l_IsRndizerRes;
    }
}

static int mDvd::ConvertPathToEntrynumBase(const char* path, u8* outType)
{
    int num = DVDConvertPathToEntrynum(path);
    if (num != -1) {
        if (outType != nullptr) {
            *outType = 0;
        }
    } else if (mDvd::isAutoStreamDecomp()) {
        num = mDvd::ConvertPathToEntrynumASD_(path, outType);
    }
    return num;
}

[[nsmbw(0x8016BD70)]]
/* static */ int mDvd::ConvertPathToEntrynum(const char* path, u8* outType)
{
    bool isRndizerRes = false;
    getOverlayRes(&isRndizerRes);

    if (isRndizerRes) {
        char pathBuffer[512] = "/RndizerRes/";
        std::strncat(
          pathBuffer, path + (path[0] == '/' ? 1 : 0),
          sizeof(pathBuffer) - std::strlen("/RndizerRes/") - 1
        );
        if (int num = ConvertPathToEntrynumBase(pathBuffer, outType); num != -1) {
            return num;
        }
    }

    return ConvertPathToEntrynumBase(path, outType);
}

EXTERN_REPL(
  0x8016C0B0, //
  mDvd_toMainRam_c* mDvd_toMainRam_c::createNoWait(const char* path, u8 param2, EGG::Heap* heap)
);

[[nsmbw(0x8016C0B0)]]
mDvd_toMainRam_c* mDvd_toMainRam_c::create(const char* path, u8 param2, EGG::Heap* heap)
{
    mDvd_toMainRam_c* cmd = createNoWait(path, param2, heap);
    if (cmd != nullptr) {
        cmd->waitDone();
    }
    return cmd;
}

bool mDvd::getFileSize(const char* path, u32* outFileSize)
{
    EGG::DvdFile file;
    if (!file.open(path)) {
        return false;
    }

    *outFileSize = file.mFileInfo.length;
    file.close();
    return true;
}
