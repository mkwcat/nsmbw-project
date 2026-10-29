#pragma once

#include "egg/core/eggDisposer.h"
#include <revolution/os.h>

/**
 * Declares functions and data for a disposable singleton class
 */
#define EGG_SINGLETON_DECL(T) \
protected: \
    class T__Disposer : public EGG::Disposer { \
    public: \
        /* VT+0x8 */ virtual ~T__Disposer(); \
    }; \
\
    T__Disposer mDisposer; \
\
public: \
    static T* createInstance(); \
    static void deleteInstance(); \
\
    static T* instance() { \
        return sInstance; \
    } \
\
protected: \
    static T* sInstance

/**
 * Defines functions and data for a disposable singleton class
 */
#define EGG_SINGLETON_IMPL(T) \
    T::T__Disposer::~T__Disposer() { \
        T::deleteInstance(); \
    } \
\
    T* T::createInstance() { \
        if (sInstance == nullptr) { \
            sInstance = new T(); \
        } \
        NSMBW_ONLY(else { \
            OSPanic( \
                __FILE_NAME__, __LINE__, "Create Singleton Twice (%s) : addr %x\n", #T, \
                reinterpret_cast<unsigned int>(sInstance) \
            ); \
        }) \
\
        return sInstance; \
    } \
\
    void T::deleteInstance() { \
        MKW_ONLY(if (T* instance = sInstance) {) \
            sInstance = nullptr; \
            MKW_ONLY(delete instance; \
        }) \
    } \
\
    T* T::sInstance = nullptr
