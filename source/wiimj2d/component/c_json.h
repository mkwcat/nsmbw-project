#pragma once

class cJsonParser_c
{
public:
    using ReadMethod = int (*)(void* buffer, std::size_t size, void* userData);

    class HandlerIf_c
    {
    public:
        virtual bool null() = 0;

        virtual bool value(bool number)
        {
            return value(s64(number));
        }

        virtual bool value(s64 number) = 0;
        virtual bool value(double number) = 0;
        virtual bool rawNumber(const char* str, std::size_t length, bool copy) = 0;
        virtual bool string(const char* str, std::size_t length, bool copy) = 0;
        virtual bool key(const char* str, std::size_t length, bool copy) = 0;
        virtual bool startObject() = 0;
        virtual bool endObject() = 0;
        virtual bool startArray() = 0;
        virtual bool endArray() = 0;
    };

    static bool parse(
      HandlerIf_c* handler, char* buffer, std::size_t bufferSize, ReadMethod read, void* userData
    );

private:
    int take();
    int peek();
    int consume();
    bool error();

    cJsonParser_c(char* buffer, std::size_t bufferSize, ReadMethod read, void* userData)
      : mBuffer(buffer)
      , mBufferSize(bufferSize)
      , mRead(read)
      , mUserData(userData)
    {
    }

    char* const mBuffer;
    const std::size_t mBufferSize;
    std::size_t mBufferAmount = 0;
    std::size_t mTotalSize = 0;
    std::size_t mBufferPos = 0;
    bool mEof = false;
    int mPeekChar = -1;
    const ReadMethod mRead;
    void* const mUserData;
};