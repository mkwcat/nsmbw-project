#pragma once

#include "d_system/d_base.h"
#include "d_system/d_mj2d_game.h"

class dDateFile_c;
class dInfoWindow_c;

class dFileSelect_c : public dBase_c {
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
};
