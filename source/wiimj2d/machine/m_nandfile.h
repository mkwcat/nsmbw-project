#pragma once

#include <egg/core/eggFile.h>
#include <revolution/nand.h>
#include <utility>

/**
 * Custom EGG::File interface for NAND files.
 */
class mNandFile_c : public EGG::File {
public:
    template <class... Args>
    mNandFile_c(
        Args... args
    ) {
        (void) open(std::forward<Args>(args)...);
    }

    mNandFile_c() = default;

    /* VT+0x08 */
    virtual ~mNandFile_c() override;

    /* VT+0x0C */
    bool open(const char* path) override;

    bool open(const char* path, u8 mode);

    bool open(NANDFileInfo&& fileInfo);

    /* VT+0x0C */
    void close() override;

    /* VT+0x10 */
    virtual s32 readData(void* data, s32 length, s32 offset) override;

    /* VT+0x14 */
    virtual s32 writeData(const void* data, s32 length, s32 offset) override;

    /* VT+0x18 */
    virtual s32 getFileSize() const override;

    virtual bool setNandError(NANDResult result);

    constexpr NANDResult getNandError() const { return mError; }

protected:
    mutable NANDFileInfo mFileInfo = {};
    NANDResult           mError    = NAND_RESULT_OK;
};
