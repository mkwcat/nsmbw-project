#pragma once

#include "d_PanelObjList.h"

class dPanelObjMgr_c
{
public:
    // Structors
    // ^^^^^^

    /* 0x800148F0 */
    dPanelObjMgr_c();

    /* 0x80014910 */
    ~dPanelObjMgr_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80014820 */
    void addPanelObjList(dPanelObjList_c*);

    /* 0x80014860 */
    void removePanelObjList(dPanelObjList_c*);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x00 */ u32 mCount;
    /* 0x04 */ dPanelObjList_c* mpFirst;
    /* 0x08 */ dPanelObjList_c* mpLast;
};