#pragma once

#include <egg/core/eggDvdRipper.h>
#include <egg/core/eggHeap.h>
#include <optional>

namespace mDvd
{

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
