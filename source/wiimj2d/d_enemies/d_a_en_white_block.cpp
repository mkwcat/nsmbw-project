// d_a_en_white_block.cpp
// NSMBW d_enemies.text: 0x80AC8270 - 0x80ACA0F0

#include "d_a_en_white_block.h"

#include "revolution/os/OSLink.h"
#include <mkwcat/Relocate.hpp>

[[nsmbw(0x80AC8270)]]
fBase_c* daEnWhiteBlock_c_classInit() {
    return new daEnWhiteBlock_c;
}

daEnWhiteBlock_c::daEnWhiteBlock_c()
    : m_pResFile(nullptr) {
    mkwcat::VTable::Fix<fBase_c>(this);
}

[[nsmbw(0x80AC8A80)]]
void daEnWhiteBlock_c::clear() {
    m0x744.fill(0);
    m0x748.fill(0);
    m0x74C.fill(0);
    m0x737 = m0x732 = 0;
}

[[nsmbw(0x80AC9260)]]
void daEnWhiteBlock_c::FUN_80AC9260() {
    if (m0x73C != 1) {
        return;
    }

    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (m0x74C[i] != 0) {
            m0x748[i] = 2;
        }
    }
}

PATCH_REFERENCES(
    offsetof(daEnWhiteBlock_c, m0x744), //
    {
        {0x80AC8EE0 + 2, R_PPC_ADDR16_LO},

        {0x80AC9048 + 2, R_PPC_ADDR16_LO},

        {0x80AC90C8 + 2, R_PPC_ADDR16_LO},
        {0x80AC9118 + 2, R_PPC_ADDR16_LO},
    }
);

PATCH_REFERENCES(
    offsetof(daEnWhiteBlock_c, m0x748), //
    {
        {0x80AC8DC0 + 2, R_PPC_ADDR16_LO},
        {0x80AC8E98 + 2, R_PPC_ADDR16_LO},
        {0x80AC8EC0 + 2, R_PPC_ADDR16_LO},
        {0x80AC8EE4 + 2, R_PPC_ADDR16_LO},

        {0x80AC8FF8 + 2, R_PPC_ADDR16_LO},
        {0x80AC9024 + 2, R_PPC_ADDR16_LO},

        {0x80AC904C + 2, R_PPC_ADDR16_LO},
        {0x80AC9130 + 2, R_PPC_ADDR16_LO},

        {0x80AC91F4 + 2, R_PPC_ADDR16_LO},
        {0x80AC9214 + 2, R_PPC_ADDR16_LO},
    }
);

PATCH_REFERENCES(
    offsetof(daEnWhiteBlock_c, m0x74C), //
    {
        {0x80AC8B88 + 2, R_PPC_ADDR16_LO},

        {0x80AC8EE8 + 2, R_PPC_ADDR16_LO},

        {0x80AC9100 + 2, R_PPC_ADDR16_LO},
    }
);
