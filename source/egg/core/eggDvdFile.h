#pragma once

#include "eggFile.h"
#include <nw4r/ut/List.h>
#include <revolution/dvd.h>

namespace EGG {

class DvdFile : public File {
    SIZE_ASSERT(0xF4);

    /* 0x00 VTABLE 0x8034FF20 */

public:
    /* 0x802B7C00 */
    static void initialize();

    /* 0x802B7C40 */
    DvdFile();

    /* +++ */
    DvdFile(
        const char* path
    )
        : DvdFile() {
        open(path);
    }

    /* VT+0x08 0x802B7C90 */
    virtual ~DvdFile();

public:
    /* VT+0x20 0x802B7D70 */
    virtual bool open(s32 entryNum);

    /* VT+0x0C 0x802B7DF0 */
    virtual bool open(const char* path);

    /* VT+0x24 0x802B7E40 */
    bool open(const char* path, void* param_2);

    /* VT+0x10 0x802B7E50 */
    virtual void close();

    /* VT+0x14 0x802B7EB0 */
    virtual s32 readData(void* data, s32 len, s32 offset);

    /* VT+0x18 0x802B7F80 */
    virtual s32 writeData(const void* data, s32 len, s32 offset);

    /* VT+0x1C */
    [[nsmbw(0x8008F750) /* d_dylink.cpp */]]
    virtual s32 getFileSize() const;

private:
    /* 0x802B7D00 */
    void initiate();

    /* 0x802B7F90 */
    s32 sync();

    /* 0x802B7FF0 */
    void doneProcess(s32 result, DVDFileInfo* fileInfo);

public:
    /* 0x04 */ bool mIsOpen;

    FILL(0x08, 0x3C);

    /* 0x3C */ DVDFileInfo mFileInfo;
    /* 0x78 */ DvdFile*    mDvdFile; // Pointer to itself?

    FILL(0x7C, 0xF4);

private:
    /* 0x8042B0E0 */
    static bool sIsInitialized;

    /* 0x80423B70 */
    static nw4r::ut::List sDvdList;
};

} // namespace EGG
