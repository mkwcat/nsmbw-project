// m_pipe.cpp
// nsmbw-project

#include "m_pipe.h"

#include <cstdlib>
#include <cstring>
#include <egg/core/eggFile.h>
#include <egg/core/eggHeap.h>
#include <msl/c/common/ansi_files.h>
#include <msl/c/common/file_io.h>

mPipe_c::mPipe_c(
    EGG::File* file, const char* mode, EGG::Heap* heap
)
    : mPipe_c(file, mode, new (heap ?: EGG::Heap::getCurrentHeap()) unsigned char[0x1000], 0x1000) {
    mDynBuffer = mFile.buffer;
}

mPipe_c::mPipe_c(
    EGG::File* file, const char* mode, void* buffer, std::size_t bufferSize
)
    : mEggFile(file)
    , mValid(false)
    , mDetached(false) {
    file_modes modes;
    if (__get_file_modes(mode, &modes) == 0) {
        return;
    }

    std::memset(&mFile, 0, sizeof(mFile));
    __init_file(&mFile, modes, static_cast<unsigned char*>(buffer), bufferSize);

    mFile.handle                   = reinterpret_cast<::__file_handle>(this);
    mFile.is_dynamically_allocated = 0;
    mFile.write_fn                 = writeProc;
    mFile.close_fn                 = closeProc;
    mValid                         = true;
    mDynBuffer                     = nullptr;
}

mPipe_c::~mPipe_c() {
    if (mValid) {
        std::fclose(&mFile);
    } else if (mDynBuffer) {
        delete[] mDynBuffer;
        mDynBuffer = nullptr;
    }
}

std::FILE* mPipe_c::open(
    EGG::File* file, const char* mode, EGG::Heap* heap
) {
    mPipe_c* pipe;
    if (heap == nullptr) {
        pipe = static_cast<mPipe_c*>(std::malloc(sizeof(mPipe_c)));
        new (pipe) mPipe_c(file, mode, heap);
    } else {
        pipe = new (heap) mPipe_c(file, mode, heap);
    }

    if (!pipe->mValid) {
        delete pipe;
        return nullptr;
    }

    pipe->mFile.is_dynamically_allocated = 1;

    return *pipe;
}

int mPipe_c::writeProc(
    ::__file_handle file, u8* buff, std::size_t* count, ::__idle_proc idle_proc
) {
    if (file == 0 || buff == nullptr || count == nullptr || *count == 0) {
        return -1;
    }

    mPipe_c* pipe   = reinterpret_cast<mPipe_c*>(file);
    s32      length = pipe->mEggFile->writeData(buff, *count, -1);
    if (length < 0) {
        *count = 0;
        return -1;
    }
    *count = length;

    return 0;
}

int mPipe_c::closeProc(
    ::__file_handle file
) {
    if (file == 0) {
        return -1;
    }

    mPipe_c* pipe = reinterpret_cast<mPipe_c*>(file);
    if (pipe->mDetached) {
        pipe->mEggFile->close();
    }
    if (pipe->mDynBuffer) {
        delete[] pipe->mDynBuffer;
        pipe->mDynBuffer = nullptr;
    }
    pipe->mValid = false;

    return 0;
}
