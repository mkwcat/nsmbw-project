#pragma once

#include "d_static/d_lytbase.h"
#include "d_static/d_lyttextbox.h"
#include <nw4r/lyt/Picture.h>

class dCourseSelectGuide_c
{
    SIZE_ASSERT(0x450 + 16);

public:
    // Structors
    // ^^^^^^

    /* VT+0x8 0x80010140 */
    virtual ~dCourseSelectGuide_c();

public:
    // Constants and Types
    // ^^^^^^

    static constexpr std::size_t LytPlayerCount = 8;

    struct Extra_s {
        ~Extra_s()
        {
        }

        nw4r::lyt::Pane* mpNExIconPos[4];

        LytTextBox_c* mpTExLifeNumber[4];

        nw4r::lyt::Picture* mpPKinopicoFace;
        nw4r::lyt::Picture* mpPPurpleKinopicoFace;
        nw4r::lyt::Picture* mpPOKinoFace;
        nw4r::lyt::Picture* mpPBlKinoFace;
    };

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80010290 */
    bool createBaseLayout();

    /* 0x80010290.x */
    bool createLayout();

    /* 0x80010690 @unofficial */
    void PlayerIconDisp();

    /* 0x80010800 */
    void RestNumberDisp();

    /* 0x800108C0 */
    void RestAlphaDisp();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x004 */ u32 m0x004;
    /* 0x008 */ LytBase_c mLayout;

    FILL(0x1A0, 0x384);

    /* 0x384 */ nw4r::lyt::Pane* mpNIconPos[4];

    FILL(0x394, 0x3B0);

    /* 0x3B0 */ LytTextBox_c* mpTWorldNum;
    /* 0x3B4 */ LytTextBox_c* mpTCSelect;
    /* 0x3B8 */ LytTextBox_c* mpTCSelectPic;
    /* 0x3BC */ LytTextBox_c* mpTLifeNumber[4];
    /* 0x3CC */ LytTextBox_c* mpTGuideViewLS;
    /* 0x3CC */ LytTextBox_c* mpTGuideViewL;

    /* 0x3D4 */ nw4r::lyt::Picture* mpPCC1;
    /* 0x3D8 */ nw4r::lyt::Picture* mpPCC2;
    /* 0x3DC */ nw4r::lyt::Picture* mpPCC3;
    /* 0x3E0 */ nw4r::lyt::Picture* mpPCC1s;
    /* 0x3E4 */ nw4r::lyt::Picture* mpPCC2s;
    /* 0x3E8 */ nw4r::lyt::Picture* mpPCC3s;
    /* 0x3EC */ nw4r::lyt::Picture* mpPFlagSkull;
    /* 0x3F0 */ nw4r::lyt::Picture* mpPMarioFace;
    /* 0x3F4 */ nw4r::lyt::Picture* mpPLuigiFace;
    /* 0x3F8 */ nw4r::lyt::Picture* mpPBKinoFace;
    /* 0x3FC */ nw4r::lyt::Picture* mpPYKinoFace;
    /* 0x400 */ nw4r::lyt::Picture* mpPBgShadow;

    FILL(0x404, 0x414);

    // Used in one function so we can replace the type int -> short
    /* 0x414 */ s16 mStoredRestNumber[8];

    FILL(0x424, 0x42C);

    /* 0x42C */ int mRestAlpha;
    /* 0x430 */ int mRestAlphaTarget;

    FILL(0x434, 0x44E);

    /* 0x44E */ bool mRestDispNeeded;

    // Added 16 bytes
    /* 0x450 */ Extra_s* mpExtra;

    FILL(0x454, 0x460);

public:
    // Static Variables
    // ^^^^^^

    /* 0x80429EDC */ static dCourseSelectGuide_c* m_instance;
};
