#pragma once

#include "d_static/d_res.h"
#include <egg/core/eggHeap.h>

class dResMng_c
{
    VTABLE(0x00, dResMng_c, 0x80319868);

public:
    // Structors
    // ^^^^^^

    virtual ~dResMng_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x800DF8C0 */
    void setRes(const char* dir, const char** files, int count, EGG::Heap* heap);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x04 */ dRes_c mRes;

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A318 */
    static dResMng_c* m_instance;
};
