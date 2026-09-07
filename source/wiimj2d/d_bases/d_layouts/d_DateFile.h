#pragma once

#include "d_base.h"
#include "s_State.h"

class dDateFile_c : public dBase_c {
    SIZE_ASSERT(0xE54);
    VTABLE(0x060, fBase_c, 0x80942058);
    // 0x80941D18 g_profile_DATE_FILE
    // 0x8077CAE0 dDateFile_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8077CB10 */
    dDateFile_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0xE54);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8077D360
     * executeState:    0x8077D410
     * finalizeState:   0x8077D440
     */
    sState_Extern(0x80991858, dDateFile_c, InitialSetup);

    /*
     * initializeState: 0x8077D490
     * executeState:    0x8077D4A0
     * finalizeState:   0x8077D5E0
     */
    sState_Extern(0x80991898, dDateFile_c, ActionWait);

    /*
     * initializeState: 0x8077D5F0
     * executeState:    0x8077D630
     * finalizeState:   0x8077D690
     */
    sState_Extern(0x809918D8, dDateFile_c, OnAnimeEndWait);

    /*
     * initializeState: 0x8077D6A0
     * executeState:    0x8077D6E0
     * finalizeState:   0x8077D770
     */
    sState_Extern(0x80991918, dDateFile_c, HitAnimeEndWait);

    /*
     * initializeState: 0x8077D780
     * executeState:    0x8077D7D0
     * finalizeState:   0x8077D830
     */
    sState_Extern(0x80991958, dDateFile_c, InterruptSaveMarkExit);

    /*
     * initializeState: 0x8077D840
     * executeState:    0x8077D880
     * finalizeState:   0x8077D8A0
     */
    sState_Extern(0x80991998, dDateFile_c, SelectCopyFileAnimeStart);

    /*
     * initializeState: 0x8077D8B0
     * executeState:    0x8077D910
     * finalizeState:   0x8077D990
     */
    sState_Extern(0x809919D8, dDateFile_c, OffAnimeEndWait);
};
