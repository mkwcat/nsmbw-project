#pragma once

#include <dynamic/d_a_player_manager.h>
#include <dynamic/d_base.h>
#include <dynamic/d_bases/d_CharacterChangeIndicator.h>
#include <dynamic/d_bases/d_CharacterChangeSelectArrow.h>
#include <dynamic/d_bases/d_CharacterChangeSelectBase.h>
#include <dynamic/d_bases/d_CharacterChangeSelectContents.h>
#include <state/s_State.h>

class da2DPlayer_c;

class dNumberOfPeopleChange_c : public dBase_c
{
public:
    // ----------------
    // Member Functions
    // ----------------

    void UNDEF_807A0060();
    void UNDEF_807A0170();

    /* 0x807A0440 */
    void assignPositions();

    /* 0x807A07C0 */
    void disableInactiveControllers();

    /* 0x807A0D20 */
    bool checkCancel();

    void setPlayer(u32 playerIndex, da2DPlayer_c* player)
    {
        if (playerIndex < 4) {
            mpaPlayers[playerIndex] = player;
        } else {
            mpaExPlayers[playerIndex - 4] = player;
        }
    }

    da2DPlayer_c* getPlayer(u32 playerIndex)
    {
        if (playerIndex < 4) {
            return mpaPlayers[playerIndex];
        } else {
            return mpaExPlayers[playerIndex - 4];
        }
    }

    void setControllerActive(u32 playerIndex, u32 active)
    {
        if (playerIndex < 4) {
            mControllerActive[playerIndex] = active;
        } else {
            mExControllerActive[playerIndex - 4] = active;
        }
    }

    u32 getControllerActive(u32 playerIndex)
    {
        if (playerIndex < 4) {
            return mControllerActive[playerIndex];
        } else {
            return mExControllerActive[playerIndex - 4];
        }
    }

    void set0x6A0(u32 playerIndex, u32 value)
    {
        if (playerIndex < 4) {
            m0x6A0[playerIndex] = value;
        } else {
            mEx0x6A0[playerIndex - 4] = value;
        }
    }

    u32 get0x6A0(u32 playerIndex)
    {
        if (playerIndex < 4) {
            return m0x6A0[playerIndex];
        } else {
            return mEx0x6A0[playerIndex - 4];
        }
    }

    void set0x6E0(u32 playerIndex, u32 value)
    {
        if (playerIndex < 4) {
            m0x6E0[playerIndex] = value;
        } else {
            mEx0x6E0[playerIndex - 4] = value;
        }
    }

    u32 get0x6E0(u32 playerIndex)
    {
        if (playerIndex < 4) {
            return m0x6E0[playerIndex];
        } else {
            return mEx0x6E0[playerIndex - 4];
        }
    }

    void set0x6F0(u32 playerIndex, u32 value)
    {
        if (playerIndex < 4) {
            m0x6F0[playerIndex] = value;
        } else {
            mEx0x6F0[playerIndex - 4] = value;
        }
    }

    u32 get0x6F0(u32 playerIndex)
    {
        if (playerIndex < 4) {
            return m0x6F0[playerIndex];
        } else {
            return mEx0x6F0[playerIndex - 4];
        }
    }

public:
    // ---------
    // State IDs
    // ---------

    sState_Extern(0x809944C8, dNumberOfPeopleChange_c, InitialSetup);
    sState_Extern(0x80994508, dNumberOfPeopleChange_c, OnStageAnimeEndWait);
    sState_Extern(0x80994548, dNumberOfPeopleChange_c, InfoOnStageAnimeEndWait);
    sState_Extern(0x80994588, dNumberOfPeopleChange_c, NowEntrantRecruit);
    sState_Extern(0x809945C8, dNumberOfPeopleChange_c, StoryModeCourseSelectExitWait);
    sState_Extern(0x80994608, dNumberOfPeopleChange_c, InfoWindowExitWait);
    sState_Extern(0x80994648, dNumberOfPeopleChange_c, ButtonOnStageAnimeEndWait);
    sState_Extern(0x80994688, dNumberOfPeopleChange_c, ButtonChangeAnimeEndWait);
    sState_Extern(0x809946C8, dNumberOfPeopleChange_c, ButtonSelect);
    sState_Extern(0x80994708, dNumberOfPeopleChange_c, ButtonDecision);
    sState_Extern(0x80994748, dNumberOfPeopleChange_c, ExitAnimeEndCheck);

public:
    // -----------
    // Member Data
    // -----------

    FILL(0x70, 0x74);

    /* 0x74 */ dCharacterChangeSelectBase_c* mpaCcSelBase[4];
    /* 0x84 */ dCharacterChangeSelectContents_c* mpaCcSelContents[4];
    /* 0x94 */ dCharacterChangeSelectArrow_c* mpaCcSelArrow[4];
    /* 0xA4 */ dCharacterChangeIndicator_c* mpaCcIndicator[4];

    FILL(0xB4, 0x64C);

    /* 0x64C */ da2DPlayer_c* mpaPlayers[4];

    FILL(0x65C, 0x67F);

    /* 0x67F */ u8 m0x67F;

    FILL(0x680, 0x690);

    /* 0x690 */ u32 mControllerActive[4];
    /* 0x6A0 */ u32 m0x6A0[4];

    FILL(0x6B0, 0x6E0);

    /* 0x6E0 */ u32 m0x6E0[4];
    /* 0x6F0 */ u32 m0x6F0[4];

    FILL(0x700, 0x710);

    OFFSET_ASSERT(0x710);

#define OFFSET_dNumberOfPeopleChange_c_mpaExPlayers 0x710
    /* 0x710 */ da2DPlayer_c* mpaExPlayers[PLAYER_COUNT - 4];

    /* 0x720 */ u32 mExControllerActive[PLAYER_COUNT - 4];
    /* 0x730 */ u32 mEx0x6A0[PLAYER_COUNT - 4];
    /* 0x740 */ u32 mEx0x6E0[PLAYER_COUNT - 4];
    /* 0x750 */ u32 mEx0x6F0[PLAYER_COUNT - 4];
};