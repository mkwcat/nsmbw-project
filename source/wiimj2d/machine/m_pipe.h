#pragma once

#include <cstdio>
#include <msl/c/common/ansi_files.h>
#include <type_traits>

namespace EGG {
class File;
class Heap;
} // namespace EGG

static_assert(std::is_same_v<std::FILE, struct _FILE>);

/**
 * Custom interface for piping file I/O through std::FILE objects.
 */
class mPipe_c final {
public:
    // Structors
    // ^^^^^^

    mPipe_c() = delete;

    ~mPipe_c();

    mPipe_c(EGG::File* file, const char* mode, void* buffer, std::size_t bufferSize);
    mPipe_c(EGG::File* file, const char* mode, EGG::Heap* heap = nullptr);

    std::FILE* open(EGG::File* file, const char* mode, EGG::Heap* heap = nullptr);

public:
    // Instance Methods
    // ^^^^^^

    constexpr bool valid() const { return mValid; }

    constexpr std::FILE* file() { return mValid ? &mFile : nullptr; }

    constexpr const std::FILE* file() const { return mValid ? &mFile : nullptr; }

    constexpr operator std::FILE*() { return file(); }

    constexpr operator const std::FILE*() const { return file(); }

    constexpr void detach() { mDetached = true; }

private:
    // Private Static Methods
    // ^^^^^^

    static int
    writeProc(::__file_handle file, u8* buff, std::size_t* count, ::__idle_proc idle_proc);
    static int closeProc(::__file_handle file);

private:
    // Instance Variables
    // ^^^^^^

    struct _FILE   mFile;
    EGG::File*     mEggFile;
    unsigned char* mDynBuffer;
    bool           mValid;
    bool           mDetached;
};
