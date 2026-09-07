#pragma once

#include "d_enemy.h"

class daEnMaxUE_c : public dEn_c {
    SIZE_ASSERT(0x528);
    VTABLE(0x060, fBase_c, 0x80AFB670);

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnMaxUE_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x528);
};

class daEnMaxUELeft_c : public daEnMaxUE_c {
    SIZE_ASSERT(0x528);
    // 0x80AFB640 g_profile_EN_MAX_UE_LEFT
    // 0x80A63C60 daEnMaxUELeft_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnMaxUELeft_c();
};

class daEnMaxUERight_c : public daEnMaxUE_c {
    SIZE_ASSERT(0x528);
    // 0x80AFB64C g_profile_EN_MAX_UE_RIGHT
    // 0x80A63CB0 daEnMaxUERight_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnMaxUERight_c();
};

class daEnMaxUE2Left_c : public daEnMaxUE_c {
    SIZE_ASSERT(0x528);
    // 0x80AFB658 g_profile_EN_MAX_UE2_LEFT
    // 0x80A63D00 daEnMaxUE2Left_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnMaxUE2Left_c();
};

class daEnMaxUE2Right_c : public daEnMaxUE_c {
    SIZE_ASSERT(0x528);
    // 0x80AFB664 g_profile_EN_MAX_UE2_RIGHT
    // 0x80A63D50 daEnMaxUE2Right_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnMaxUE2Right_c();
};
