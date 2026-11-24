#pragma once

#include <bitset>
#include <concepts>
#include <cstdio>
#include <cstring>
#include <egg/core/eggDvdFile.h>
#include <span>
#include <string_view>

namespace cJson {

enum class ErrorPolicy_e {
    pass,
    except,
};

class HandlerIf_c {
public:
    ~HandlerIf_c() {}

    virtual bool null() { return false; }

    virtual bool boolean(
        bool num
    ) {
        return number(static_cast<s64>(num));
    }

    virtual bool number(
        s64 num
    ) {
        return false;
    }

    virtual bool floatNumber(
        double num
    ) {
        return false;
    }

    virtual bool rawNumber(
        std::string_view str
    ) {
        return false;
    }

    virtual bool string(
        std::string_view str
    ) {
        return false;
    }

    virtual bool key(
        std::string_view str
    ) {
        return false;
    }

    virtual bool startObject() { return false; }

    virtual bool endObject() { return false; }

    virtual bool startArray() { return false; }

    virtual bool endArray() { return false; }
};

using ReadMethod       = int (*)(void* buffer, std::size_t size, void* userData);
using WriteMethod      = bool (*)(const void* buffer, std::size_t size, void* userData);
using TokenErrorMethod = void (*)(void* userData);

class Parser_c {
public:
    constexpr Parser_c(
        char* buffer, std::size_t bufferSize, ReadMethod read, void* userData
    )
        : mBuffer(buffer)
        , mBufferSize(bufferSize)
        , mRead(read)
        , mUserData(userData) {}

    ~Parser_c() {}

    static bool parse(
        HandlerIf_c* handler, char* buffer, std::size_t bufferSize, ReadMethod read, void* userData
    );

    enum class token_type_e : u8 {
        key,
        number,
        raw_number,
        floating_point,
        boolean,
        null,
        string,
        object_start,
        object_end,
        array_start,
        array_end,
        none,
    };

    struct token_s {
        Parser_c*    parser = nullptr;

        bool         valid  = false;
        token_type_e type   = token_type_e::none;

        explicit constexpr operator bool() const { return valid; }

        [[nodiscard]] constexpr bool is_key() const { return type == token_type_e::key; }

        [[nodiscard]] constexpr bool is_number() const { return type == token_type_e::number; }

        [[nodiscard]] constexpr bool is_raw_number() const {
            return type == token_type_e::raw_number;
        }

        [[nodiscard]] constexpr bool is_floating_point() const {
            return type == token_type_e::floating_point;
        }

        [[nodiscard]] constexpr bool is_boolean() const { return type == token_type_e::boolean; }

        [[nodiscard]] constexpr bool is_null() const { return type == token_type_e::null; }

        [[nodiscard]] constexpr bool is_string() const { return type == token_type_e::string; }

        [[nodiscard]] constexpr bool is_object_start() const {
            return type == token_type_e::object_start;
        }

        [[nodiscard]] constexpr bool is_object_end() const {
            return type == token_type_e::object_end;
        }

        [[nodiscard]] constexpr bool is_array_start() const {
            return type == token_type_e::array_start;
        }

        [[nodiscard]] constexpr bool is_array_end() const {
            return type == token_type_e::array_end;
        }

        [[nodiscard]] constexpr bool operator==(
            const std::string_view& s
        ) const {
            return string == s;
        }

        [[nodiscard]] constexpr bool operator==(
            const char* s
        ) const {
            return string == s;
        }

        [[nodiscard]] constexpr operator const std::string_view&() const { return string; }

        void print() const;

        std::string_view string;
        s64              number;
        double           floating_point;
        bool             boolean;

        bool             has_number;
    };

    token_s next();

    [[noreturn]]
    void userError(const char* fileName, int line);

    [[gnu::always_inline]]
    void userError(
        bool cond = true, const char* fileName = __builtin_FILE_NAME(), int line = __builtin_LINE()
    ) {
        if (cond) {
            userError(fileName, line);
            std::unreachable();
        }
    }

    void setUserErrorCallback(
        TokenErrorMethod method, void* userData
    ) {
        mTokenError         = method;
        mTokenErrorUserData = userData;
    }

protected:
    int take();
    int peekRaw();
    int peek();
    int consume();
    bool error();

private:
    char* const       mBuffer;
    const std::size_t mBufferSize;
    std::size_t       mBufferAmount = 0;
    std::size_t       mTotalSize    = 0;
    std::size_t       mBufferPos    = 0;

protected:
    bool mError = false;
    bool mEof   = false;

private:
    bool             mNeedComma   = false;
    int              mPeekChar    = -1;
    int              mRawPeekChar = -1;
    const ReadMethod mRead;
    void* const      mUserData;
    TokenErrorMethod mTokenError         = nullptr;
    void*            mTokenErrorUserData = nullptr;
    char             mTempStringBuffer[512];
};

class Writer_c : public HandlerIf_c {
public:
    constexpr Writer_c(
        WriteMethod write, void* userData
    )
        : mWrite(write)
        , mUserData(userData) {}

    explicit Writer_c(std::FILE* file);

    constexpr ~Writer_c() {}

    bool null() final;
    bool boolean(bool num) final;
    bool number(s64 num) final;
    bool floatNumber(double num) final;
    bool rawNumber(std::string_view str) final;
    bool string(std::string_view str) final;
    bool key(std::string_view str) final;
    bool startObject() final;
    bool endObject() final;
    bool startArray() final;
    bool endArray() final;

    template <std::integral T>
    bool field(
        std::string_view name, const T& num
    ) {
        if constexpr (std::same_as<T, bool>) {
            return key(name) && boolean(num);
        } else {
            return key(name) && number(static_cast<s64>(num));
        }
    }

    bool field(
        std::string_view name, std::floating_point auto num
    ) {
        return key(name) && boolean(num);
    }

    bool field(
        std::string_view name, std::string_view str
    ) {
        return key(name) && string(str);
    }

    bool field(
        std::string_view name, const std::convertible_to<std::string_view> auto& str
    ) {
        if constexpr (std::convertible_to<decltype(str), bool>) {
            if (str) {
                return field(name, std::string_view{str});
            }
            return field(name, std::string_view{});
        } else {
            return field(name, str);
        }
    }

    [[gnu::format(printf, 3, 4)]]
    bool fieldFmt(std::string_view name, const char* format, ...);

    [[gnu::format(printf, 2, 3)]]
    bool keyFmt(const char* format, ...);

    [[nodiscard]] std::size_t getTotalSize() const { return mTotalSize; }

private:
    bool postValue(bool result);
    bool write(std::string_view str);
    bool writeQuoted(std::string_view str);

    const WriteMethod mWrite;
    void* const       mUserData;
    int               mDepth = 0;
    std::bitset<64>   mIsArrayContext;
    bool              mExpectValue = false;
    bool              mNeedComma   = false;
    std::size_t       mTotalSize   = 0;
};

class Reader_c : public Parser_c {
public:
    constexpr Reader_c(
        char* buffer, std::size_t bufferSize, ReadMethod read, void* userData
    )
        : Parser_c(buffer, bufferSize, read, userData) {}

    constexpr ~Reader_c() {}

private:
public:
    template <ErrorPolicy_e E = ErrorPolicy_e::except>
    [[gnu::always_inline]] token_s key(
        const char* fileName = __builtin_FILE_NAME(), int line = __builtin_LINE()
    ) {
        return consume<E>(token_type_e::key, fileName, line);
    }

    template <ErrorPolicy_e E = ErrorPolicy_e::except>
    [[gnu::always_inline]] token_s null(
        const char* fileName = __builtin_FILE_NAME(), int line = __builtin_LINE()
    ) {
        return consume<E>(token_type_e::null, fileName, line);
    }

    template <ErrorPolicy_e E = ErrorPolicy_e::except>
    [[gnu::always_inline]] token_s number(
        const char* fileName = __builtin_FILE_NAME(), int line = __builtin_LINE()
    ) {
        return consume<E>(token_type_e::number, fileName, line);
    }

    template <ErrorPolicy_e E = ErrorPolicy_e::except>
    [[gnu::always_inline]] token_s rawNumber(
        const char* fileName = __builtin_FILE_NAME(), int line = __builtin_LINE()
    ) {
        return consume<E>(token_type_e::raw_number, fileName, line);
    }

    template <ErrorPolicy_e E = ErrorPolicy_e::except>
    [[gnu::always_inline]] token_s floatNumber(
        const char* fileName = __builtin_FILE_NAME(), int line = __builtin_LINE()
    ) {
        return consume<E>(token_type_e::floating_point, fileName, line);
    }

    template <ErrorPolicy_e E = ErrorPolicy_e::except>
    [[gnu::always_inline]] token_s boolean(
        const char* fileName = __builtin_FILE_NAME(), int line = __builtin_LINE()
    ) {
        return consume<E>(token_type_e::boolean, fileName, line);
    }

    template <ErrorPolicy_e E = ErrorPolicy_e::except>
    [[gnu::always_inline]] token_s string(
        const char* fileName = __builtin_FILE_NAME(), int line = __builtin_LINE()
    ) {
        return consume<E>(token_type_e::string, fileName, line);
    }

    template <ErrorPolicy_e E = ErrorPolicy_e::except>
    [[gnu::always_inline]] token_s startObject(
        const char* fileName = __builtin_FILE_NAME(), int line = __builtin_LINE()
    ) {
        return consume<E>(token_type_e::object_start, fileName, line);
    }

    template <ErrorPolicy_e E = ErrorPolicy_e::except>
    [[gnu::always_inline]] token_s endObject(
        const char* fileName = __builtin_FILE_NAME(), int line = __builtin_LINE()
    ) {
        return consume<E>(token_type_e::object_end, fileName, line);
    }

    template <ErrorPolicy_e E = ErrorPolicy_e::except>
    [[gnu::always_inline]] token_s startArray(
        const char* fileName = __builtin_FILE_NAME(), int line = __builtin_LINE()
    ) {
        return consume<E>(token_type_e::array_start, fileName, line);
    }

    template <ErrorPolicy_e E = ErrorPolicy_e::except>
    [[gnu::always_inline]] token_s endArray(
        const char* fileName = __builtin_FILE_NAME(), int line = __builtin_LINE()
    ) {
        return consume<E>(token_type_e::array_end, fileName, line);
    }

    [[gnu::noinline]]
    token_s anyNumber() {
        if (!mToken) {
            mToken = next();
        }
        if (!mToken.has_number) {
            return {};
        }
        token_s token = mToken;
        mToken        = {};
        return token;
    }

    template <ErrorPolicy_e E = ErrorPolicy_e::except>
    [[gnu::noinline]]
    token_s anyValue()
        requires(E == ErrorPolicy_e::pass)
    {
        if (!mToken) {
            mToken = next();
        }
        if (mToken.is_key() || mToken.is_object_start() || mToken.is_object_end() ||
            mToken.is_array_start() || mToken.is_array_end()) {
            return {};
        }
        token_s token = mToken;
        mToken        = {};
        return token;
    }

    template <ErrorPolicy_e E = ErrorPolicy_e::except>
    token_s anyValue(
        const char* fileName = __builtin_FILE_NAME(), int line = __builtin_LINE()
    )
        requires(E == ErrorPolicy_e::except)
    {
        return anyValueOrError(fileName, line);
    }

    bool end() {
        if (mEof) {
            return !mToken;
        }
        return peek() < 0;
    }

private:
    token_s consume(token_type_e type);

    template <ErrorPolicy_e E>
    token_s consume(
        [[maybe_unused]] token_type_e type, [[maybe_unused]] const char* fileName,
        [[maybe_unused]] int line
    ) {
        static_assert(false);
    }

    template <>
    token_s consume<ErrorPolicy_e::pass>(
        token_type_e type, [[maybe_unused]] const char* fileName, [[maybe_unused]] int line
    ) {
        return consume(type);
    }

    template <>
    token_s consume<ErrorPolicy_e::except>(token_type_e type, const char* fileName, int line);

    token_s anyValueOrError(const char* fileName, int line);

    token_s mToken;
};

class DvdReader_c : public Reader_c {
public:
    DvdReader_c(
        const char* path, std::span<char> buffer
    )
        : Reader_c(buffer.data(), buffer.size(), readCallback, this)
        , mFile(path) {}

    DvdReader_c(
        const char* path
    )
        : DvdReader_c(path, {mBuffer, std::size(mBuffer)}) {}

    ~DvdReader_c() {
#ifndef __has_macintosh_dt_fix
        mFile.~DvdFile();
#endif
    }

private:
    static int readCallback(
        void* buffer, std::size_t size, void* userData
    ) {
        auto* self   = static_cast<DvdReader_c*>(userData);

        s32   result = self->mFile.readData(
            buffer, std::min<s32>(size, self->mFile.getFileSize() - self->mFileOffset),
            self->mFileOffset
        );
        self->mFileOffset += result;
        return result;
    }

    EGG::DvdFile mFile;
    s32          mFileOffset = 0;
    alignas(32) char mBuffer[128];
};

using token_s = Parser_c::token_s;

} // namespace cJson
