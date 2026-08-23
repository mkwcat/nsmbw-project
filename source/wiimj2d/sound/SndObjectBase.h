#pragma once

#include <nw4r/snd/SoundActor.h>

class Snd2DCalc;

class NMSndObjectBase : public nw4r::snd::SoundActor {
    SIZE_ASSERT(0x64);

    /* 0x00 VTABLE 0x8032E318 */

public:
    // Constants and Types
    // ^^^^^^

    enum class OBJ_TYPE {
        TYPE_0 = 0,
        TYPE_1 = 1,
    };

public:
    // Structors
    // ^^^^^^

    /* 0x80197440 */
    NMSndObjectBase(OBJ_TYPE objType, nw4r::snd::SoundArchivePlayer& soundArchivePlayer);

    /* VT+0x08 0x801974C0 */
    virtual ~NMSndObjectBase();

public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0x1C 0x801976B0 */
    virtual s8 VT_0x1C(s32 param1, s32 param2);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x54 */ u32        mNumHandles;
    /* 0x58 */ s32        mRemotePlayer;
    /* 0x5C */ Snd2DCalc* mpSnd2DCalc;
    /* 0x60 */ OBJ_TYPE   mObjType;
};
