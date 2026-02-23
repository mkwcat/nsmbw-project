#pragma once

#include <cstring>
#include <egg/core/eggDvdRipper.h>
#include <egg/core/eggHeap.h>
#include <optional>

namespace mDvd
{

class UncompressInfo_c
{
public:
    // Structors
    // ^^^^^^

    constexpr UncompressInfo_c(u8 type, const char* extension)
      : mType(type)
      , mExtension(extension)
    {
    }

    /* VT+0x08 */
    virtual ~UncompressInfo_c()
    {
    }

public:
    // Virtual Methods
    // ^^^^^^

    /* VT+0x0C */
    virtual EGG::StreamDecomp* Construct() const = 0;

    /* VT+0x10 */
    virtual void Destruct() const = 0;

public:
    // Instance Variables
    // ^^^^^^

    u8 mType;
    const char* mExtension;

public:
    // Static Variables
    // ^^^^^^

    /* 0x80429758 */ static void* m_UnionObjectBuffer;
};

template <class T>
class TUncompressInfo_c : public UncompressInfo_c
{
public:
    // Structors
    // ^^^^^^
    constexpr TUncompressInfo_c(u8 type, const char* extension)
      : UncompressInfo_c(type, extension)
    {
    }

public:
    // Virtual Methods
    // ^^^^^^

    virtual T* Construct() const override
    {
        return new (m_UnionObjectBuffer) T();
    }

    virtual void Destruct() const override
    {
    }
};

/* 0x80377DE4 */
extern TUncompressInfo_c<EGG::StreamDecompSZS> s_UncompressInfoSZS;

/* 0x80377DF0 */
extern TUncompressInfo_c<EGG::StreamDecompLZ> s_UncompressInfoLZ;

/* 0x80377DFC */
extern TUncompressInfo_c<EGG::StreamDecompLH> s_UncompressInfoLH;

/* 0x80377E08 */
extern TUncompressInfo_c<EGG::StreamDecompLRC> s_UncompressInfoLRC;

/* 0x80377E14 */
extern TUncompressInfo_c<EGG::StreamDecompRL> s_UncompressInfoRL;

/* 0x8016B1D0 @unofficial */
void initAutoStreamDecompInfo(
  const UncompressInfo_c* const* begin, const UncompressInfo_c* const* end
);

/* 0x8016B3E0 */
void* loadToMainRAM(
  int entryNum, char* dst, EGG::Heap* heap, EGG::DvdRipper::EAllocDirection allocDir, s32 offset,
  u32* outAmountRead, u32* outFileSize, u32 decompressorType
);

void* loadToMainRAM(
  const char* path, char* dst, EGG::Heap* heap, EGG::DvdRipper::EAllocDirection allocDir,
  s32 offset, u32* outAmountRead, u32* outFileSize, u32 decompressorType
);

bool getFileSize(const char* path, u32* outFileSize);

/* 0x8016BD60 */
bool isAutoStreamDecomp();

void setOverlayRes(std::optional<bool> isRndizerRes);
void getOverlayRes(bool* isRndizerRes);

// +++
class MultiArchiveBuilder_c
{
public:
    // Constants
    // ++++++

    static constexpr s32 ENTRY_NONE = -1;

public:
    // Structors
    // ++++++

    MultiArchiveBuilder_c(
      EGG::Heap* heap, EGG::DvdRipper::EAllocDirection allocDir = EGG::DvdRipper::ALLOC_DIR_BOTTOM,
      u32 dstMaxCount = 0, u32 dstStrTabMaxSize = 1
    );

    ~MultiArchiveBuilder_c();

public:
    // Instance Methods
    // ++++++

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
    // ++++++

    static void* loadArchive(
      EGG::DvdFile* dvdFile, char* path, EGG::Heap* heap, EGG::DvdRipper::EAllocDirection allocDir,
      u32* outAmountRead, u32* outFileSize
    );

public:
    // Instance Variables
    // ++++++

    EGG::Heap* mHeap;
    EGG::DvdRipper::EAllocDirection mAllocDir;

    FstEntry* mDst = nullptr;
    u32 mDstCount = 0;
    u32 mDstMaxCount;

    char* mDstStrTab = nullptr;
    u32 mDstStrTabSize = 0;
    u32 mDstStrTabMaxSize;
};

} // namespace mDvd

class mDvd_command_c
{
public:
    // Structors
    // ^^^^^^

    /* VT+0x8 0x */
    virtual ~mDvd_command_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x8016B630 */
    void waitDone() const;

public:
    // Instance Variables
    // ^^^^^^
};

class mDvd_toMainRam_c : public mDvd_command_c
{
public:
    // Static Methods
    // ^^^^^^

    /* 0x8016C0B0 */
    static mDvd_toMainRam_c* create(const char* path, u8 param2, EGG::Heap* heap);

    /* 0x8016C0B0 - repl */
    static mDvd_toMainRam_c* createNoWait(const char* path, u8 param2, EGG::Heap* heap);
};
