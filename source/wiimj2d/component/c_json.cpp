// c_json.cpp
// nsmbw-project

#include "c_json.h"
#include "mkwcat/BaseTypes.hpp"
#include "revolution/os/OSError.h"
#include <cstdlib>

[[gnu::noinline]]
int cJsonParser_c::take()
{
    int c = -1;
    if (mBufferPos < mBufferAmount) {
        c = int(mBuffer[mBufferPos++]) & 0xFF;
    } else if (!mEof) {
        mTotalSize += mBufferAmount;
        mBufferAmount = 0;
        mBufferPos = 0;
        int readResult = mRead(mBuffer, mBufferSize, mUserData);
        if (readResult > 0) {
            mBufferAmount = readResult;
            if (mBufferAmount < mBufferSize) {
                mEof = true;
            }
        } else {
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

// Consume the next non-whitespace character
[[gnu::noinline]]
int cJsonParser_c::consume()
{
    if (mPeekChar >= 0) {
        int c = mPeekChar;
        mPeekChar = -1;
        return c;
    }
    mPeekChar = -1;
    while (true) {
        if (int c = take(); c > ' ' || c < 0) {
            if (c == '/' && peek() == '/') {
                // Skip line comment
                while (true) {
                    c = take();
                    if (c == '\n' || c < 0) {
                        break;
                    }
                }
                continue;
            } else if (c == '/' && peek() == '*') {
                // Skip block comment
                take();
                while (true) {
                    c = take();
                    if (c < 0) {
                        return -1;
                    }
                    if (c == '*' && peek() == '/') {
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
int cJsonParser_c::peek()
{
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
bool cJsonParser_c::error()
{
    OS_REPORT("cJsonParser_c: parse error at offset %zu\n", mTotalSize + mBufferPos);
    return false;
};

bool cJsonParser_c::parse(
  HandlerIf_c* handler, char* buffer, std::size_t bufferSize, ReadMethod read, void* userData
)
{
    cJsonParser_c p(buffer, bufferSize, read, userData);

    bool end = false;

    while (true) {
        int c = p.consume();
        if (c < 0) {
            return p.mEof || p.error();
        }

        if (end) {
            if (c == ',') {
                end = false;
                continue;
            }
            if (c != '}' && c != ']') {
                return p.error();
            }
        }
        end = false;

        bool result = false;
        switch (c) {
        case '{':
            result = handler->startObject();
            break;
        case '}':
            result = handler->endObject();
            end = true;
            break;
        case '[':
            result = handler->startArray();
            break;
        case ']':
            result = handler->endArray();
            end = true;
            break;
        case 'n': {
            // Expect "null"
            if (p.take() != 'u' || p.take() != 'l' || p.take() != 'l') {
                return p.error();
            }
            result = handler->null();
            end = true;
            break;
        }
        case 't': {
            // Expect "true"
            if (p.take() != 'r' || p.take() != 'u' || p.take() != 'e') {
                return p.error();
            }
            result = handler->value(true);
            end = true;
            break;
        }
        case 'f': {
            // Expect "false"
            if (p.take() != 'a' || p.take() != 'l' || p.take() != 's' || p.take() != 'e') {
                return p.error();
            }
            result = handler->value(false);
            end = true;
            break;
        }
        case '"': {
            // Parse string
            char string[256];
            std::size_t strPos = 0;
            while (true) {
                if (strPos >= sizeof(string) - 1) {
                    return p.error();
                }

                int c = p.take();
                if (c < 0) {
                    return p.error();
                }
                if (c == '"') {
                    break;
                }
                if (c == '\\') {
                    c = p.take();
                    if (c < 0) {
                        return p.error();
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
                        return p.error();
                    }
                }

                string[strPos++] = char(c);
            }
            string[strPos] = '\0';

            if (p.peek() == ':') {
                p.consume();
                result = handler->key(string, strPos, false);
            } else {
                result = handler->string(string, strPos, false);
                end = true;
            }
            break;
        }

        case '-':
        case '+':
        case '0' ... '9': {
            // Parse number
            char number[64];
            std::size_t numPos = 0;
            number[numPos++] = char(c);
            bool isFloat = false;
            while (true) {
                int c = p.peek();
                if ((c >= '0' && c <= '9') || c == '.' || c == 'e' || c == 'E' || c == '-' ||
                    c == '+') {
                    p.consume();
                    if (numPos >= sizeof(number) - 1) {
                        return p.error();
                    }
                    if (c == '.' || c == 'e' || c == 'E' || c == '-' || c == '+') {
                        isFloat = true;
                    }
                    number[numPos++] = char(c);
                } else {
                    break;
                }
            }
            number[numPos] = '\0';

            if (isFloat) {
                result = handler->rawNumber(number, numPos, false);
                end = true;
            } else {
                s64 intValue = std::atoi(number);
                result = handler->value(intValue);
                end = true;
            }
            break;
        }
        }

        if (!result) {
            return p.error();
        }
    }

    return true;
}