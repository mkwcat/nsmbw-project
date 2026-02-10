#pragma once

#include <cstring>
#include <egg/core/eggDvdRipper.h>

class mMultiArchiveBuilder_c
{
public:
    // Constants
    // ^^^^^^

    static constexpr s32 ENTRY_NONE = -1;

public:
    // Structors
    // ^^^^^^

    mMultiArchiveBuilder_c(
      EGG::Heap* heap, EGG::DvdRipper::EAllocDirection allocDir = EGG::DvdRipper::ALLOC_DIR_BOTTOM,
      u32 dstMaxCount = 0, u32 dstStrTabMaxSize = 1
    );

    ~mMultiArchiveBuilder_c();

public:
    // Instance Methods
    // ^^^^^^

    bool
    copyArchive(const char* srcFst, u32 fstSize, u32 startIndex = 0, u32 offsetDisplacement = 0);

    /**
     * Retuns the destination FST. The data will be invalidated if copyArchive is called, or if the
     * object is destroyed.
     */
    FstEntry* getDst() const
    {
        return mDst;
    }

    /**
     * Returns the number of entries in the destination FST. This will be 0 if copyArchive has not
     * been called. This value will no longer reflect the number of entries if copyArchive is called
     * again.
     */
    u32 getDstCount() const
    {
        return mDstCount;
    }

    /**
     * Returns the destination string table. The data will be invalidated if copyArchive is called,
     * or if the object is destroyed.
     */
    const char* getDstStrTab() const
    {
        return mDstStrTab;
    }

    /**
     * Returns the size of the destination string table. This will be 0 if copyArchive has not been
     * called. This value will no longer reflect the size of the string table if copyArchive is
     * called again.
     */
    u32 getDstStrTabSize() const
    {
        return mDstStrTabSize;
    }

    /**
     * Adds up the file size of every file in the destination FST.
     * @returns The total size of all files in the destination FST.
     */
    u32 getTotalFileSize() const;

    /**
     * Adds a root entry with the provided name if it doesn't already exist.
     */
    void addRootEntry(const char* name);

private:
    static bool isSkippableName(const char* name)
    {
        return name[0] == '\0' || std::strcmp(name, ".") == 0;
    }

    s32 addString(const char* str);

    s32 addEntry(FstEntry entry, const char* name, s32 dstIndex, s32 parent);

    s32 addEntryStrTab(FstEntry entry, const char* strTab, s32 dstIndex, s32 parent);

    s32 copyArchive2(const char* srcFst, u32 startIndex, s32 dstIndex, u32 offsetDisplacement);

public:
    // Static Methods
    // ^^^^^^

    static void* loadArchive(
      EGG::DvdFile* dvdFile, char* path, EGG::Heap* heap, EGG::DvdRipper::EAllocDirection allocDir,
      u32* outAmountRead, u32* outFileSize
    );

public:
    // Instance Variables
    // ^^^^^^

    EGG::Heap* mHeap;
    EGG::DvdRipper::EAllocDirection mAllocDir;

    FstEntry* mDst = nullptr;
    u32 mDstCount = 0;
    u32 mDstMaxCount;

    char* mDstStrTab = nullptr;
    u32 mDstStrTabSize = 0;
    u32 mDstStrTabMaxSize;
};
