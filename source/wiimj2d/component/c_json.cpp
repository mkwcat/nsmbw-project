// c_json.cpp
// nsmbw-project

#include "c_json.h"

#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <revolution/os/OSError.h>

namespace cJson {

namespace {
bool writeToFile(
    const void* buffer, std::size_t length, void* userData
) {
    std::FILE* const file = static_cast<std::FILE*>(userData);
    return std::fwrite(buffer, sizeof(char), length, file) == length;
}
} // namespace

[[gnu::noinline]]
int Parser_c::take() {
    if (mRawPeekChar >= 0) {
        int c        = mRawPeekChar;
        mRawPeekChar = -1;
        return c;
    }

    int c = -1;
    if (mBufferPos < mBufferAmount) {
        c = int(mBuffer[mBufferPos++]) & 0xFF;
    } else if (!mEof) {
        mTotalSize += mBufferAmount;
        mBufferAmount  = 0;
        mBufferPos     = 0;
        int readResult = mRead(mBuffer, mBufferSize, mUserData);
        if (readResult > 0) {
            mBufferAmount = readResult;
            if (mBufferAmount < mBufferSize) {
                mEof = true;
            }
        } else {
            mEof |= (readResult == 0);
            return -1;
        }
    } else {
        return -1;
    }
    if (c == -1) {
        c = int(mBuffer[mBufferPos++]) & 0xFF;
    }
    return c;
};

// Peek the next raw character without consuming it
[[gnu::noinline]]
int Parser_c::peekRaw() {
    if (mRawPeekChar >= 0) {
        return mRawPeekChar;
    }
    if (int c = take(); c >= 0) {
        mRawPeekChar = c;
        return c;
    }
    return -1;
}

// Consume the next non-whitespace character
[[gnu::noinline]]
int Parser_c::consume() {
    if (mPeekChar >= 0) {
        int c     = mPeekChar;
        mPeekChar = -1;
        return c;
    }
    mPeekChar = -1;
    while (true) {
        if (int c = take(); c > ' ' || c < 0) {
            if (c == '/' && peekRaw() == '/') {
                // Skip line comment
                while (true) {
                    c = take();
                    if (c == '\n' || c < 0) {
                        break;
                    }
                }
                continue;
            } else if (c == '/' && peekRaw() == '*') {
                // Skip block comment
                take();
                while (true) {
                    c = take();
                    if (c < 0) {
                        return -1;
                    }
                    if (c == '*' && peekRaw() == '/') {
                        take();
                        break;
                    }
                }
                continue;
            }
            return c;
        }
    }
};

// Peek the next non-whitespace character
[[gnu::noinline]]
int Parser_c::peek() {
    if (mPeekChar >= 0) {
        return mPeekChar;
    }
    if (int c = consume(); c >= 0) {
        mPeekChar = c;
        return c;
    }
    return -1;
}

// Report a parse error and return false
[[gnu::noinline]]
bool Parser_c::error() {
    OS_REPORT("Parser_c: parse error at offset %zu\n", mTotalSize + mBufferPos);
    mError = true;
    return false;
};

bool Parser_c::parse(
    HandlerIf_c* handler, char* buffer, std::size_t bufferSize, ReadMethod read, void* userData
) {
    Parser_c p(buffer, bufferSize, read, userData);
    for (token_s t; (t = p.next());) {
        bool result = false;
        switch (t.type) {
        case token_type_e::key:
            result = handler->key(t.string);
            break;
        case token_type_e::number:
            result = handler->value(t.number);
            break;
        case token_type_e::raw_number:
            result = handler->rawNumber(t.string);
            break;
        case token_type_e::floating_point:
            result = handler->value(t.floating_point);
            break;
        case token_type_e::boolean:
            result = handler->value(t.boolean);
            break;
        case token_type_e::null:
            result = handler->null();
            break;
        case token_type_e::string:
            result = handler->string(t.string);
            break;
        case token_type_e::object_start:
            result = handler->startObject();
            break;
        case token_type_e::object_end:
            result = handler->endObject();
            break;
        case token_type_e::array_start:
            result = handler->startArray();
            break;
        case token_type_e::array_end:
            result = handler->endArray();
            break;
        default:
            result = false;
            break;
        }
        if (!result) {
            return false;
        }
    }
    return !p.mError;
}

Parser_c::token_s Parser_c::next() {
    token_s t = {};

    int     c = consume();

    if (mNeedComma) {
        mNeedComma = false;
        if (c == ',') {
            c = consume();
            if (c == '}' || c == ']') {
                error();
                return t;
            }
        } else if (c > 0 && c != '}' && c != ']') {
            error();
            return t;
        }
    }

    if (c <= 0) {
        if (!mEof) {
            error();
        }
        return t;
    }

    switch (c) {
    case '{':
        t.valid = true;
        t.type  = token_type_e::object_start;
        return t;
    case '}':
        t.valid    = true;
        t.type     = token_type_e::object_end;
        mNeedComma = true;
        return t;
    case '[':
        t.valid = true;
        t.type  = token_type_e::array_start;
        return t;
    case ']':
        t.valid    = true;
        t.type     = token_type_e::array_end;
        mNeedComma = true;
        return t;

    case 'n': {
        // Expect "null"
        if (take() != 'u' || take() != 'l' || take() != 'l') {
            break;
        }
        t.valid    = true;
        t.type     = token_type_e::null;
        mNeedComma = true;
        break;
    }
    case 't': {
        // Expect "true"
        if (take() != 'r' || take() != 'u' || take() != 'e') {
            break;
        }
        t.valid      = true;
        t.type       = token_type_e::boolean;
        t.has_number = true;
        t.number     = 1;
        mNeedComma   = true;
        break;
    }
    case 'f': {
        // Expect "false"
        if (take() != 'a' || take() != 'l' || take() != 's' || take() != 'e') {
            break;
        }
        t.valid      = true;
        t.type       = token_type_e::boolean;
        t.has_number = true;
        t.number     = 0;
        mNeedComma   = true;
        break;
    }

    case '"': {
        // Parse string
        std::size_t strPos = 0;
        while (true) {
            if (strPos >= sizeof(mTempStringBuffer) - 1) {
                error();
                return t;
            }

            int c = take();
            if (c < 0) {
                error();
                return t;
            }
            if (c == '"') {
                break;
            }
            if (c == '\\') {
                c = take();
                if (c < 0) {
                    error();
                    return t;
                }
                switch (c) {
                case '"':
                case '\\':
                case '/':
                    break;
                case 'b':
                    c = '\b';
                    break;
                case 'f':
                    c = '\f';
                    break;
                case 'n':
                    c = '\n';
                    break;
                case 'r':
                    c = '\r';
                    break;
                case 't':
                    c = '\t';
                    break;
                default:
                    error();
                    return t;
                }
            }

            mTempStringBuffer[strPos++] = static_cast<char>(c);
        }

        mTempStringBuffer[strPos] = '\0';
        t.valid                   = true;
        t.string                  = {mTempStringBuffer, strPos};
        if (peek() == ':') {
            consume();
            t.type = token_type_e::key;
        } else {
            t.type     = token_type_e::string;
            mNeedComma = true;
        }
        break;
    }

    case '-':
    case '+':
    case '0' ... '9': {
        // Parse number
        std::size_t numPos          = 0;
        mTempStringBuffer[numPos++] = char(c);
        bool isFloat                = false;
        while (true) {
            int c = peek();
            if ((c >= '0' && c <= '9') || c == '.' || c == 'e' || c == 'E' || c == '-' ||
                c == '+') {
                consume();
                if (numPos >= sizeof(mTempStringBuffer) - 1) {
                    error();
                    return t;
                }
                if (c == '.' || c == 'e' || c == 'E' || c == '-' || c == '+') {
                    isFloat = true;
                }
                mTempStringBuffer[numPos++] = char(c);
            } else {
                break;
            }
        }

        mTempStringBuffer[numPos] = '\0';
        t.valid                   = true;
        t.string                  = {mTempStringBuffer, numPos};
        if (isFloat) {
            // Floats not currently supported
            t.type = token_type_e::raw_number;
        } else {
            t.type       = token_type_e::number;
            t.number     = std::atoi(mTempStringBuffer);
            t.has_number = true;
        }
        mNeedComma = true;
        break;
    }
    }

    if (!t.valid) {
        error();
        return t;
    }

    if (t.has_number) {
        t.boolean        = !!t.number;
        t.floating_point = static_cast<double>(t.number);
    }

    return t;
}

Writer_c::Writer_c(
    std::FILE* file
)
    : mWrite(writeToFile)
    , mUserData(file) {
}

bool Writer_c::null() {
    if (!mExpectValue) {
        return false;
    }

    bool result;
    if (mNeedComma) {
        result = write(",null");
    } else {
        result = write("null");
    }
    return postValue(result);
}

bool Writer_c::value(
    bool number
) {
    if (!mExpectValue) {
        return false;
    }

    if (mNeedComma && !write(",")) {
        return false;
    }

    bool result;
    if (number) {
        result = write("true");
    } else {
        result = write("false");
    }
    return postValue(result);
}

bool Writer_c::value(
    s64 number
) {
    if (!mExpectValue) {
        return false;
    }

    char buffer[32]; // 18446744073709551615
    int  len = std::snprintf(buffer, sizeof(buffer), "%s%llu", mNeedComma ? "," : "", number);
    return postValue(write({buffer, static_cast<std::size_t>(len)}));
}

bool Writer_c::value(
    double number
) {
    if (!mExpectValue) {
        return false;
    }

    char buffer[32]; // 1.7976931348623157e+308
    int  len = std::snprintf(buffer, sizeof(buffer), "%s%.17g", mNeedComma ? "," : "", number);
    return postValue(write({buffer, static_cast<std::size_t>(len)}));
}

bool Writer_c::rawNumber(
    std::string_view str
) {
    return string(str);
}

bool Writer_c::string(
    std::string_view str
) {
    if (str.data() == nullptr) {
        return null();
    }

    if (!mExpectValue) {
        return false;
    }
    if (mNeedComma && !write(",")) {
        return false;
    }

    return postValue(writeQuoted(str));
}

bool Writer_c::key(
    std::string_view str
) {
    if (mExpectValue || mDepth == 0 || mIsArrayContext[mDepth - 1]) {
        return false;
    }

    if (mNeedComma && !write(",")) {
        return false;
    }
    if (!writeQuoted(str) || !write(":")) {
        return false;
    }

    mNeedComma   = false;
    mExpectValue = true;
    return true;
}

bool Writer_c::startObject() {
    if (!mExpectValue && mDepth != 0) {
        return false;
    }

    if (!write("{")) {
        return false;
    }
    mNeedComma                = false;
    mExpectValue              = false;
    mIsArrayContext[mDepth++] = false;
    return true;
}

bool Writer_c::endObject() {
    if (mExpectValue || mDepth == 0 || mIsArrayContext[mDepth - 1]) {
        return false;
    }

    if (!write("}")) {
        return false;
    }
    mDepth--;
    mNeedComma   = true;
    mExpectValue = mDepth != 0 && mIsArrayContext[mDepth - 1];
    return true;
}

bool Writer_c::startArray() {
    if (!mExpectValue) {
        return false;
    }

    if (!write("[")) {
        return false;
    }
    mNeedComma = false;
    [[assume(mExpectValue)]];
    mExpectValue              = true;
    mIsArrayContext[mDepth++] = true;
    return true;
}

bool Writer_c::endArray() {
    if (!mExpectValue || mDepth == 0 || !mIsArrayContext[mDepth - 1]) {
        return false;
    }

    if (!write("]")) {
        return false;
    }
    mDepth--;
    mNeedComma   = true;
    mExpectValue = mDepth != 0 && mIsArrayContext[mDepth - 1];
    return true;
}

bool Writer_c::postValue(
    bool result
) {
    mNeedComma   = true;
    mExpectValue = mIsArrayContext[mDepth - 1];
    return result;
}

bool Writer_c::write(
    std::string_view str
) {
    mTotalSize += str.size();
    return mWrite(str.data(), str.size(), mUserData);
}

bool Writer_c::writeQuoted(
    std::string_view str
) {
    if (!write("\"")) {
        return false;
    }

    std::size_t i = 0, writePos = 0;

    const auto  commit = [this, str, &writePos, &i](const std::string_view& escape) -> bool {
        bool result = true;
        if (writePos < i) {
            result   = write(str.substr(writePos, i));
            writePos = i;
        }
        if (result && escape.size()) {
            result = write(escape);
        }
        return result;
    };

    for (; i < str.size(); i++) {
        char c[2] = {'\\', 0};
        switch (str[i]) {
        case '"':
        case '\\':
            c[1] = str[i];
            break;
        case '\b':
            c[1] = 'b';
            break;
        case '\f':
            c[1] = 'f';
            break;
        case '\n':
            c[1] = 'n';
            break;
        case '\r':
            c[1] = 'r';
            break;
        case '\t':
            c[1] = 't';
            break;
        case '\0':
            c[1] = '0';
            break;
        }

        if (c[1] && !commit({c, 2})) {
            return false;
        }
    }

    return commit({}) && write("\"");
}

bool cJson::Writer_c::fieldFmt(
    std::string_view name, const char* format, ...
) {
    std::va_list args;
    va_start(args, format);

    char buffer[512];
    int  len = std::vsnprintf(buffer, std::size(buffer), format, args);

    va_end(args);

    return key(name) && string({buffer, static_cast<std::size_t>(len)});
}

bool cJson::Writer_c::keyFmt(
    const char* format, ...
) {
    std::va_list args;
    va_start(args, format);

    char buffer[512];
    int  len = std::vsnprintf(buffer, std::size(buffer), format, args);

    va_end(args);

    return key({buffer, static_cast<std::size_t>(len)});
}

} // namespace cJson
