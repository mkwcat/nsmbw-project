#pragma once

#include "d_profile/d_profile.h"
#include "d_static/d_base.h"

class sPhase_c;

class dScene_c : public dBase_c {
    SIZE_ASSERT(0x74);

public:
    // Structors
    // ^^^^^^

    /* 0x800E1AA0 */
    dScene_c();

    /* VT+0x48 0x800E1B10 */
    virtual ~dScene_c() override;

public:
    // Instance Methods
    // ^^^^^^

    /* 0x800E2040 */
    void setFadeInFrame(u16 frames);

    /* 0x800E2050 */
    void setFadeOutFrame(u16 frames);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x70 */ sPhase_c* mpPhase;

public:
    // Static Methods
    // ^^^^^^

    /* 0x800E1F50 */
    static void setNextScene(u16 profile, u32 param, bool param2);

    static inline bool isWorldMap() { return m_nowScene == dProf::WORLD_MAP; }

public:
    // Static Variables
    // ^^^^^^

    /* 0x80428A42 */ static u16 m_nowScene;
};
