#pragma once

#include "d_mj2d_data.h"

namespace EGG
{
class Heap;
}

class dMj2dGame_c;

class dSaveMng_c
{
public:
    // Structors
    // ^^^^^^

    /* 0x800E02C0 */
    dSaveMng_c();

public:
    // Functions
    // ^^^^^^

    /* 0x800E03C0 */
    void refresh();

    /* 0x800E0470 */
    dMj2dGame_c* getSaveGame(s8 file = -1);

    /* 0x800E04A0 */
    dMj2dGame_c* getTempGame(s8 file = -1);

    /* 0x800E04D0 */
    void saveGameCopy(s8 to, s8 from);

    /* 0x800E05A0 */
    void calcCRC();

    /* 0x800E0630 */
    bool startNandSave();

    /* 0x800E0D10 */
    bool startMultiModeNandSave();

    /* 0x800E0E10 */
    bool startQuickNandSave();

    /* 0x800E12C0 */
    bool startDeleteQuickNandSave();

    /* 0x800E1A30 */
    void loadQuickSaveData(u8 file);

    /* 0x800E1780 */
    void prepareSave();

    /* 0x800E1930 */
    void initLoadGame(s8 file);

public:
    // Instance Variables
    // ^^^^^^

    bool mSaving;
    dMj2dData_c mData;

public:
    // Static Methods
    // ^^^^^^

    /* 0x800E0270 */
    static void create(EGG::Heap* heap);

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A320 */ static dSaveMng_c* m_instance;
};
