#pragma once

#include "d_base.h"
#include "d_mj2d_game.h"
#include "s_State.h"

class dDateFile_c;
class dInfoWindow_c;

class dFileSelect_c : public dBase_c {
    SIZE_ASSERT(0x2DE);
    VTABLE(0x060, fBase_c, 0x80943DD0);
    // 0x80943610 g_profile_FILE_SELECT
    // 0x80782AB0 dFileSelect_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80782AE0 */
    dFileSelect_c();

public:
    FILL(0x070, 0x24C);

    /* 0x24C */ dDateFile_c*   mpDateFile[SAVE_SLOT_COUNT];
    /* 0x258 */ dInfoWindow_c* mpInfoWindow;

    FILL(0x25C, 0x2A4);

    /* 0x2A4 */ int mChoice;

    FILL(0x2A8, 0x2DB);

    /* 0x2DB */ bool mChoiceDone;
    /* 0x2DC */ bool mChoiceBack;
    /* 0x2DD */ bool mChoiceTempFile;

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80783580
     * executeState:    0x807836D0
     * finalizeState:   0x80783720
     */
    sState_Extern(0x80991F30, dFileSelect_c, StartWait);

    /*
     * initializeState: 0x80783790
     * executeState:    0x80783830
     * finalizeState:   0x807838C0
     */
    sState_Extern(0x80991F70, dFileSelect_c, OpenWait);

    /*
     * initializeState: 0x807838F0
     * executeState:    0x80783980
     * finalizeState:   0x807839F0
     */
    sState_Extern(0x80991FB0, dFileSelect_c, MultiButtnOnStageAnimeEndWait);

    /*
     * initializeState: 0x80783A00
     * executeState:    0x80783B30
     * finalizeState:   0x80783BB0
     */
    sState_Extern(0x80991FF0, dFileSelect_c, ButtonSelectAnimeEndWait);

    /*
     * initializeState: 0x80783BF0
     * executeState:    0x80783C10
     * finalizeState:   0x80783F80
     */
    sState_Extern(0x80992030, dFileSelect_c, SelectWait);

    /*
     * initializeState: 0x80783FB0
     * executeState:    0x80784030
     * finalizeState:   0x807840B0
     */
    sState_Extern(0x80992070, dFileSelect_c, ButtonHitAnimeEndWait);

    /*
     * initializeState: 0x807840C0
     * executeState:    0x807840F0
     * finalizeState:   0x80784100
     */
    sState_Extern(0x809920B0, dFileSelect_c, ReturnTitle);

    /*
     * initializeState: 0x80784110
     * executeState:    0x80784150
     * finalizeState:   0x80784180
     */
    sState_Extern(0x809920F0, dFileSelect_c, GameStartWait);

    /*
     * initializeState: 0x80784190
     * executeState:    0x807841B0
     * finalizeState:   0x807841F0
     */
    sState_Extern(0x80992130, dFileSelect_c, FromCopyOrDeleteBeforeButtonReturn);

    /*
     * initializeState: 0x80784200
     * executeState:    0x80784250
     * finalizeState:   0x807842B0
     */
    sState_Extern(0x80992170, dFileSelect_c, MultiButtonExitAnimeEndWait);

    /*
     * initializeState: 0x807842C0
     * executeState:    0x80784320
     * finalizeState:   0x80784380
     */
    sState_Extern(0x809921B0, dFileSelect_c, InfoWindowOnStageAnimeEndWait);

    /*
     * initializeState: 0x80784440
     * executeState:    0x807844C0
     * finalizeState:   0x80784500
     */
    sState_Extern(0x809921F0, dFileSelect_c, FromCopyOrDeleteButtonSelectAnimeEndWait);

    /*
     * initializeState: 0x80784510
     * executeState:    0x80784520
     * finalizeState:   0x80784700
     */
    sState_Extern(0x80992230, dFileSelect_c, FromCopyOrDeleteFileSelect);

    /*
     * initializeState: 0x80784710
     * executeState:    0x80784730
     * finalizeState:   0x80784770
     */
    sState_Extern(0x80992270, dFileSelect_c, FromCopyOrDeleteButtonReturn);

    /*
     * initializeState: 0x80784780
     * executeState:    0x80784790
     * finalizeState:   0x807847F0
     */
    sState_Extern(0x809922B0, dFileSelect_c, InfoWindowExitAnimeEndWait);

    /*
     * initializeState: 0x80784830
     * executeState:    0x80784840
     * finalizeState:   0x807848A0
     */
    sState_Extern(0x809922F0, dFileSelect_c, FromCopyDecisionInfoWindowExit);

    /*
     * initializeState: 0x807848B0
     * executeState:    0x807848F0
     * finalizeState:   0x80784950
     */
    sState_Extern(0x80992330, dFileSelect_c, ToCopyInfoWindowOnStage);

    /*
     * initializeState: 0x807849E0
     * executeState:    0x80784A60
     * finalizeState:   0x80784AA0
     */
    sState_Extern(0x80992370, dFileSelect_c, ToCopyButtonSelectAnimeEndWait);

    /*
     * initializeState: 0x80784AB0
     * executeState:    0x80784AC0
     * finalizeState:   0x80784C40
     */
    sState_Extern(0x809923B0, dFileSelect_c, ToCopyFileSelect);

    /*
     * initializeState: 0x80784C50
     * executeState:    0x80784C70
     * finalizeState:   0x80784CB0
     */
    sState_Extern(0x809923F0, dFileSelect_c, ToCopyButtonReturn);

    /*
     * initializeState: 0x80784CC0
     * executeState:    0x80784CD0
     * finalizeState:   0x80784D30
     */
    sState_Extern(0x80992430, dFileSelect_c, ToCopyCancelWindowExit);

    /*
     * initializeState: 0x80784D40
     * executeState:    0x80784D80
     * finalizeState:   0x80784DE0
     */
    sState_Extern(0x80992470, dFileSelect_c, FromCopyInfoWindowOnStage);

    /*
     * initializeState: 0x80784EB0
     * executeState:    0x80784EE0
     * finalizeState:   0x80784F40
     */
    sState_Extern(0x809924B0, dFileSelect_c, CopyDecisionWindowExit);

    /*
     * initializeState: 0x80784F50
     * executeState:    0x80784F90
     * finalizeState:   0x80784FF0
     */
    sState_Extern(0x809924F0, dFileSelect_c, CopyNoSelectButtonOff);

    /*
     * initializeState: 0x80785000
     * executeState:    0x80785040
     * finalizeState:   0x807850A0
     */
    sState_Extern(0x80992530, dFileSelect_c, CopyButtonMoveEndWait);

    /*
     * initializeState: 0x807850B0
     * executeState:    0x80785110
     * finalizeState:   0x80785170
     */
    sState_Extern(0x80992570, dFileSelect_c, CopyArrowConfirmationButtonOnStage);

    /*
     * initializeState: 0x80785180
     * executeState:    0x807851F0
     * finalizeState:   0x80785250
     */
    sState_Extern(0x809925B0, dFileSelect_c, ConfirmationWindowOsStage);

    /*
     * initializeState: 0x80785270
     * executeState:    0x80785350
     * finalizeState:   0x807853B0
     */
    sState_Extern(0x809925F0, dFileSelect_c, ConfirmationButtonAnimeEndWait);

    /*
     * initializeState: 0x807853C0
     * executeState:    0x807853F0
     * finalizeState:   0x80785580
     */
    sState_Extern(0x80992630, dFileSelect_c, ConfirmationButtonSelect);

    /*
     * initializeState: 0x80785590
     * executeState:    0x807855F0
     * finalizeState:   0x80785680
     */
    sState_Extern(0x80992670, dFileSelect_c, ConfirmationButtonHitAnimeEndWait);

    /*
     * initializeState: 0x80785690
     * executeState:    0x80785700
     * finalizeState:   0x80785760
     */
    sState_Extern(0x809926B0, dFileSelect_c, ConfirmationButtonExit);

    /*
     * initializeState: 0x80785770
     * executeState:    0x80785780
     * finalizeState:   0x80785820
     */
    sState_Extern(0x809926F0, dFileSelect_c, ConfirmationWindowExit);

    /*
     * initializeState: 0x80785830
     * executeState:    0x80785870
     * finalizeState:   0x807858D0
     */
    sState_Extern(0x80992730, dFileSelect_c, CopyConfirmationButtonReturn);

    /*
     * initializeState: 0x807858F0
     * executeState:    0x80785900
     * finalizeState:   0x807859A0
     */
    sState_Extern(0x80992770, dFileSelect_c, CopyConfirmationOffButtonReturn);

    /*
     * initializeState: 0x807859B0
     * executeState:    0x80785AA0
     * finalizeState:   0x80785B60
     */
    sState_Extern(0x809927B0, dFileSelect_c, NowCopyOrDeleteDispWait);

    /*
     * initializeState: 0x80785B70
     * executeState:    0x80785BA0
     * finalizeState:   0x80785BD0
     */
    sState_Extern(0x809927F0, dFileSelect_c, NowCopyOrDeleteDispExitAnimeEndWait);

    /*
     * initializeState: 0x80785BE0
     * executeState:    0x80785C80
     * finalizeState:   0x80785D20
     */
    sState_Extern(0x80992830, dFileSelect_c, CopyOrDeleteEndDispWait);

    /*
     * initializeState: 0x80785D30
     * executeState:    0x80785D50
     * finalizeState:   0x80785DA0
     */
    sState_Extern(0x80992870, dFileSelect_c, CopyOrDeleteEndMessageWindowExitAnimeEndWait);

    /*
     * initializeState: 0x80785DB0
     * executeState:    0x80785DC0
     * finalizeState:   0x80785E20
     */
    sState_Extern(0x809928B0, dFileSelect_c, DeleteDecisionInfoWindowExit);

    /*
     * initializeState: 0x80785E30
     * executeState:    0x80785E90
     * finalizeState:   0x80785EF0
     */
    sState_Extern(0x809928F0, dFileSelect_c, DeleteOtherDispOff);

    /*
     * initializeState: 0x80785F00
     * executeState:    0x80785F20
     * finalizeState:   0x80785F80
     */
    sState_Extern(0x80992930, dFileSelect_c, DeleteFileCenterMove);

    /*
     * initializeState: 0x80785F90
     * executeState:    0x80785FE0
     * finalizeState:   0x80786040
     */
    sState_Extern(0x80992970, dFileSelect_c, DeleteConfirmationButtonOnStage);

    /*
     * initializeState: 0x80786050
     * executeState:    0x80786070
     * finalizeState:   0x807860D0
     */
    sState_Extern(0x809929B0, dFileSelect_c, DeleteFileCenterToBack);

    /*
     * initializeState: 0x807860E0
     * executeState:    0x80786140
     * finalizeState:   0x807861A0
     */
    sState_Extern(0x809929F0, dFileSelect_c, DeleteOtherDispOn);
};
