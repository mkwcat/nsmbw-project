#pragma once

#include <bitset>
#include <concepts>
#include <cstdio>
#include <cstring>
#include <string_view>

namespace cJson {

class HandlerIf_c
{
public:
    virtual bool null() = 0;

    virtual bool value(
        bool number
    ) {
        return value(s64(number));
    }

    virtual bool value(s64 number)               = 0;
    virtual bool value(double number)            = 0;
    virtual bool rawNumber(std::string_view str) = 0;
    virtual bool string(std::string_view str)    = 0;
    virtual bool key(std::string_view str)       = 0;
    virtual bool startObject()                   = 0;
    virtual bool endObject()                     = 0;
    virtual bool startArray()                    = 0;
    virtual bool endArray()                      = 0;
};

using ReadMethod  = int (*)(void* buffer, std::size_t size, void* userData);
using WriteMethod = bool (*)(const void* buffer, std::size_t size, void* userData);

class Parser_c
{
public:
    constexpr Parser_c(
        char* buffer, std::size_t bufferSize, ReadMethod read, void* userData
    )
        : mBuffer(buffer)
        , mBufferSize(bufferSize)
        , mRead(read)
        , mUserData(userData) {}

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
        bool         valid = false;
        token_type_e type  = token_type_e::none;

        constexpr operator bool() const { return valid; }

        constexpr bool is_key() const { return type == token_type_e::key; }

        constexpr bool is_number() const { return type == token_type_e::number; }

        constexpr bool is_raw_number() const { return type == token_type_e::raw_number; }

        constexpr bool is_floating_point() const { return type == token_type_e::floating_point; }

        constexpr bool is_boolean() const { return type == token_type_e::boolean; }

        constexpr bool is_null() const { return type == token_type_e::null; }

        constexpr bool is_string() const { return type == token_type_e::string; }

        constexpr bool is_object_start() const { return type == token_type_e::object_start; }

        constexpr bool is_object_end() const { return type == token_type_e::object_end; }

        constexpr bool is_array_start() const { return type == token_type_e::array_start; }

        constexpr bool is_array_end() const { return type == token_type_e::array_end; }

        std::string_view string;
        s64              number;
        double           floating_point;
        bool             boolean;

        bool             has_number;
    };

    token_s next();

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
    char             mTempStringBuffer[512];
};

class Writer_c : public HandlerIf_c
{
public:
    constexpr Writer_c(
        WriteMethod write, void* userData
    )
        : mWrite(write)
        , mUserData(userData) {}

    explicit Writer_c(std::FILE* file);

    bool null() final;
    bool value(bool number) final;
    bool value(s64 number) final;
    bool value(double number) final;
    bool rawNumber(std::string_view str) final;
    bool string(std::string_view str) final;
    bool key(std::string_view str) final;
    bool startObject() final;
    bool endObject() final;
    bool startArray() final;
    bool endArray() final;

    template <std::integral T>
    bool field(
        std::string_view name, const T& number
    ) {
        if constexpr (std::same_as<T, bool>) {
            return key(name) && value(number);
        } else {
            return key(name) && value(static_cast<s64>(number));
        }
    }

    bool field(
        std::string_view name, std::floating_point auto number
    ) {
        return key(name) && value(number);
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
            } else {
                return field(name, std::string_view{});
            }
        } else {
            return field(name, str);
        }
    }

    [[gnu::format(printf, 3, 4)]]
    bool fieldFmt(std::string_view name, const char* format, ...);

    [[gnu::format(printf, 2, 3)]]
    bool keyFmt(const char* format, ...);

    std::size_t getTotalSize() const { return mTotalSize; }

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

class Reader_c : public Parser_c
{
public:
    token_s key() { return consume(token_type_e::key); }

    token_s null() { return consume(token_type_e::null); }

    token_s number() { return consume(token_type_e::number); }

    token_s rawNumber() { return consume(token_type_e::raw_number); }

    token_s floatNumber() { return consume(token_type_e::floating_point); }

    token_s boolean() { return consume(token_type_e::boolean); }

    token_s string() { return consume(token_type_e::string); }

    token_s startObject() { return consume(token_type_e::object_start); }

    token_s endObject() { return consume(token_type_e::object_end); }

    token_s startArray() { return consume(token_type_e::array_start); }

    token_s endArray() { return consume(token_type_e::array_end); }

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

    [[gnu::noinline]]
    token_s anyValue() {
        if (!mToken) {
            mToken = next();
        }
        if (!mToken.is_key() && !mToken.is_object_start() && !mToken.is_object_end() &&
            !mToken.is_array_start() && !mToken.is_array_end()) {
            return {};
        }
        token_s token = mToken;
        mToken        = {};
        return token;
    }

    bool end() {
        if (mEof) {
            return !mToken;
        }
        return peek() < 0;
    }

private:
    [[gnu::noinline]]
    token_s consume(
        token_type_e type
    ) {
        if (!mToken) {
            mToken = next();
        }
        if (type != mToken.type) {
            return {};
        }
        token_s token = mToken;
        mToken        = {};
        return token;
    }

    token_s mToken;
};

} // namespace cJson
