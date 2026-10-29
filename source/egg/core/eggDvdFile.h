#pragma once

#include "eggFile.h"
#include <nw4r/ut/List.h>
#include <revolution/dvd.h>

namespace EGG {

class DvdFile : public File {
    SIZE_ASSERT(0xF4);

public:
    static void initialize();
    DvdFile();

    /* +++ */
    DvdFile(
        const char* path
    )
        : DvdFile() {
        open(path);
    }

    /* VT+0x08 */
    virtual ~DvdFile();

public:
    /* VT+0x20 */
    virtual bool open(s32 entryNum);

    /* VT+0x0C */
    virtual bool open(const char* path);

    /* VT+0x24 */
    bool open(const char* path, void* param_2);

    /* VT+0x10 */
    virtual void close();

    /* VT+0x14 */
    virtual s32 readData(void* data, s32 len, s32 offset);

    /* VT+0x18 */
    virtual s32 writeData(const void* data, s32 len, s32 offset);

    /* VT+0x1C */
    [[nsmbw(0x8008F750) /* d_dylink.cpp */]]
    virtual s32 getFileSize() const;

private:
    void initiate();
    s32 sync();
    void doneProcess(s32 result, DVDFileInfo* fileInfo);

public:
    /* 0x04 */ bool        mIsOpen;

    /* 0x08 */ u8          FILL(0x08, 0x3C);

    /* 0x3C */ DVDFileInfo mFileInfo;
    /* 0x78 */ DvdFile*    mDvdFile; // Pointer to itself?

    /* 0x7C */ u8          FILL(0x7C, 0xF4);

private:
    static bool           sIsInitialized;
    static nw4r::ut::List sDvdList;
};

} // namespace EGG
