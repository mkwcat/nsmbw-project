// m_nandfile.cpp
// nsmbw-project

#include "m_nandfile.h"

#include <cstdio>

mNandFile_c::~mNandFile_c() {
    close();
}

bool mNandFile_c::open(
    const char* path
) {
    return open(path, 1);
}

bool mNandFile_c::open(
    const char* path, u8 mode
) {
    if (NANDResult result = NANDOpen(path, &mFileInfo, mode); result != NAND_RESULT_OK) {
        return setNandError(result);
    }
    return true;
}

bool mNandFile_c::open(
    NANDFileInfo&& fileInfo
) {
    mFileInfo = fileInfo;
    return fileInfo.fileDescriptor >= 0;
}

void mNandFile_c::close() {
    if (NANDResult result = NANDClose(&mFileInfo); result != NAND_RESULT_OK) {
        (void) setNandError(result);
    }
}

s32 mNandFile_c::readData(
    void* data, s32 length, s32 offset
) {
    if (offset >= 0) {
        if (NANDResult result = NANDSeek(&mFileInfo, offset, SEEK_SET);
            result != NAND_RESULT_OK && !setNandError(result)) {
            return result;
        }
    }

    NANDResult result = NANDRead(&mFileInfo, data, length);
    if (result < 0 && setNandError(result)) {
        result = static_cast<NANDResult>(0);
    }
    return result;
}

s32 mNandFile_c::writeData(
    const void* data, s32 length, s32 offset
) {
    if (offset >= 0) {
        if (NANDResult result = NANDSeek(&mFileInfo, offset, SEEK_SET);
            result != NAND_RESULT_OK && !setNandError(result)) {
            return result;
        }
    }

    NANDResult result = NANDWrite(&mFileInfo, data, length);
    if (result < 0 && setNandError(result)) {
        result = static_cast<NANDResult>(0);
    }
    return result;
}

s32 mNandFile_c::getFileSize() const {
    u32 length;
    if (NANDResult result = NANDGetLength(&mFileInfo, &length); result != NAND_RESULT_OK) {
        return result;
    }
    return length;
}

bool mNandFile_c::setNandError(
    NANDResult result
) {
    mError = result;
    return false;
}
