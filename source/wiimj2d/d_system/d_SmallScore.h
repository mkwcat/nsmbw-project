#pragma once

#include "d_system/d_lytbase.h"
#include "d_system/d_lyttextbox.h"
#include "machine/m_vec.h"

/**
 * Handles the creation, animation, and rendering of a single small score popup, which appears when
 * performing actions such as stomping enemies, collecting coins, or earning 1-UPs.
 */
class dSmallScore_c {
public:
    // Constants
    // ^^^^^^

    /**
     * The possible states of the score popup.
     */
    enum class STATE_e {
        MAKE_START = 0,
        UP_MOVE    = 1,
        DISP_WAIT  = 2,
        GOAL_DISP  = 3,
        COUNT      = 4,
        NONE       = COUNT,
    };

    /**
     * The different types of the small score popups.
     */
    enum class POPUP_TYPE_e {
        C_100           = 0,  // The number 100.
        C_200           = 1,  // The number 200.
        C_400           = 2,  // The number 400.
        C_800           = 3,  // The number 800.
        C_1000          = 4,  // The number 1000.
        C_2000          = 5,  // The number 2000.
        C_4000          = 6,  // The number 4000.
        C_8000          = 7,  // The number 8000.
        C_1             = 8,  // The number 1, used for red coins and toad balloons.
        C_2             = 9,  // The number 2, used for red coins and toad balloons.
        C_3             = 10, // The number 3, used for red coins and toad balloons.
        C_4             = 11, // The number 4, used for red coins and toad balloons.
        C_5             = 12, // The number 5, used for red coins and toad balloons.
        C_6             = 13, // The number 6, used for red coins and toad balloons.
        C_7             = 14, // The number 7, used for red coins and toad balloons.
        C_8             = 15, // The number 8, used for red coins and toad balloons.
        C_1UP           = 16, // The text "1-UP".
        C_2UP           = 17, // The text "2-UP".
        C_3UP           = 18, // The text "3-UP".
        C_4UP           = 19, // The text "4-UP".
        C_1UP_COLOR_CHG = 20, // The text "1-UP", but changes color (see chgColor).
                              // Used when a 1-UP is awarded to multiple players.
        COIN_2          = 21, // [Coin icon]x2. Used in Coin Battle.
        COIN_3          = 22, // [Coin icon]x3. Used in Coin Battle.
        COIN_5          = 23, // [Coin icon]x5. Used in Coin Battle.
        COIN_10         = 24, // [Coin icon]x10. Used in Coin Battle.
        COIN_15         = 25, // [Coin icon]x15. Used in Coin Battle.
        COIN_20         = 26, // [Coin icon]x20. Used in Coin Battle.
        INVALID         = -1, // Invalid popup type.
    };

    /**
     * The text boxes used for the layout.
     */
    enum T_PANE_e {
        T_100_00       = 0,
        T_1000_00      = 1,
        T_red2_00      = 2,
        T_1UP_00       = 3,
        T_coin_x_00    = 4,
        T_coinPoint_00 = 5,
        T_COUNT        = 6,
    };

    /**
     * The null panes used for the layout.
     */
    enum N_PANE_e {
        N_coin_00 = 0,
        N_COUNT   = 1,
    };

public:
    // Structors
    // ^^^^^^

    dSmallScore_c();

    virtual ~dSmallScore_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80014FF0 */ void createLayout(d2d::ResAccMultLoader_c* res);
    /* 0x80015160 */ void execute();
    /* 0x800151D0 */ void draw();
    /* 0x800151F0 */ void doDelete();
    /* 0x80015200 */ void setPlayer1upColor(int player);
    /* 0x80015210 */ void setPlayer1000Color(int player);
    /* 0x800153B0 */ void setPlayer100Color(int player);
    /* 0x800154E0 */ void chgColor();
    /* 0x80015580 */ void setNormalOrBlueColor();
    /* 0x800156B0 */ void ScissorMaskSet();
    /* 0x80015780 */ void BigSmallAnime();
    /* 0x80015860 */ void MakeStart();
    /* 0x80015A50 */ void UpMove();
    /* 0x80015AD0 */ void DispWait();
    /* 0x80015C00 */ void GoalScoreDisp();
    /* 0x80015C10 */ void PositionSet();
    /* 0x80015CE0 */ void CreateSmallScore(const mVec3_c&, int, int);
    /* 0x80015D40 */ void PosSet(const mVec3_c&);

public:
    // Inline Instance Methods
    // ^^^^^^

    void setClipScale(
        mVec2_c v
    ) {
        mClipScale = v;
    }

private:
    // Instance Variables
    // ^^^^^^

    /* 0x004 */ LytBase_c        mLayout;
    /* 0x19C */ mVec2_c          mPos;
    /* 0x1A4 */ mVec2_c          mPosDelta;
    /* 0x1AC */ mVec2_c          mPosDeceleration;
    /* 0x1B4 */ mVec2_c          mPosOffset;
    /* 0x1BC */ mVec2_c          mScale;
    /* 0x1C4 */ mVec2_c          mClipScale;
    /* 0x1CC */ mVec2_c          mAnimScale;
    /* 0x1D4 */ nw4r::lyt::Pane* mpRootPane;
    /* 0x1D8 */ LytTextBox_c*    mpTextBoxes[T_COUNT];
    /* 0x1F0 */ nw4r::lyt::Pane* mpNullPanes[N_COUNT];
    /* 0x1F4 */ float   mMaxHeight;   // The maximum height the score popup can be displayed at.
    /* 0x1F8 */ STATE_e mState;       // The state the score popup is in.
    /* 0x1FC */ int     mPopupType;   // The popup type. Value is a POPUP_TYPE_e.
    /* 0x200 */ int mDispWaitCounter; // The amount of frames the @p DispWait state has been active.
    /* 0x204 */ int mDispWaitTime;    // The number of frames to wait in the @p DispWait state.
    /* 0x208 */ int mPlayerType;
    /* 0x20C */ int mChgColorCounter; // Counter that is incremented every call to chgColor(),
                                      // which ensures that the 1-UP color is only set once every
                                      // 10 calls.
    /* 0x210 */ u32      mPlayerColor;
    /* 0x214 */ int      mAnimCounter;
    /* 0x218 */ T_PANE_e mCurTextbox; // The textbox currently displayed.
    /* 0x21C */ bool     mIsGoalScore;
    /* 0x21D */ bool     mInitialized; // Whether the layout has been initialized.
    /* 0x21E */ bool     mEnableColorChange;
    /* 0x21F */ bool     mEnableBigSmallAnim;
    /* 0x220 */ bool     mAnimIsShrinking;
    /* 0x221 */ bool     mHasBlueColor; // Whether counter type score popups should be colored blue
                                        // instead of red.

    static dSmallScore_c* m_instance; // The instance of the score popup creator. @unused
};
