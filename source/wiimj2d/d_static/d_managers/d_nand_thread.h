#pragma once

#include "d_mj2d_data.h"
#include <cstdio>
#include <revolution/os/OSMutex.h>
#include <revolution/os/OSThread.h>

class dNandThread_c {
public:
    // Instance Methods
    // ^^^^^^

    /* 0x800CF170 @unofficial */
    bool cmdSave(dMj2dData_c* data);

private:
    /* 0x800CEF80 */
    void existCheck();

    /* 0x800CF200 */
    int save();

    /* 0x800CF680 */
    int load();

    /* 0x800CFA50 */
    void deleteFile();

    /* 0x800CFC20 */
    void setNandError(s32 result);

    inline bool isError() const { return mError != 0; }

    inline bool isNandFailure() const { return mError == 6; }

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x00, 0x54);
    /* 0x54 */ OSMutex       mMutex;
    /* 0x6C */ OSThreadQueue mThreadQueue;
    /* 0x74 */ s32           mState;
    /* 0x78 */ s32           mError;
    /* 0x7C */ bool          mExists;

public:
    // Static Methods
    // ^^^^^^

    static void reinitialize();

    /* 0x800CFCA0 */
    static dMj2dData_c* getSaveData();

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A298 */
    static dNandThread_c* m_instance;
};
