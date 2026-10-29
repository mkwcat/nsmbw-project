#pragma once

#include <revolution/arc.h>

extern "C" {
int preinit(s32 param1, void* param2);
int main(int argc, char** argv);
}

class dProject_c {
private:
    // Structors
    // ======

    dProject_c();
    ~dProject_c() = delete;

    // Static Methods
    // ======

    friend int preinit(s32 param1, void* param2);
    friend int main(int argc, char** argv);
    static void preCModuleInit(s32 arcEntryNum, void* arcStart);

    // Static Variables
    // ======

    static inline dProject_c* m_instance;

    // Instance Methods
    // ======

    void loadVersionJson();

    // Instance Variables
    // ======

    char m_name[64];
    char m_version[16];

public:
    // Public Methods
    // ======

    static bool initialized() { return m_instance; }

    static const dProject_c& instance() { return *m_instance; };

    const char* getName() const { return m_name; }

    const char* getVersion() const { return m_version; }
};
