#pragma once

#include "d_system/d_course_data.h"
#include "d_system/d_fader.h"

class dNext_c
{
    SIZE_ASSERT(0x24);

public:
    // Instance Methods
    // ^^^^^^

    /* 0x800D0360 */
    void execute();

private:
    /* 0x800D01F0 */
    void changeScene();

    void changeSceneRndizer(int index);

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A2A0 */ static dNext_c* m_instance;

public:
    // Nested Types
    // ^^^^^^

    enum class ChangeType_e {
        NEW_COURSE = 0, // Course means Area
        NEW_AREA = 1, // Area means Zone
        SAME_AREA = 2,
    };

public:
    // Instance Variables
    // ^^^^^^

    /* 0x00 */ dCdFile_c::NextGoto_s m_nextGoto;
    /* 0x14 */ ChangeType_e m_changeType;
    /* 0x18 */ bool m_exitReq;
    /* 0x19 */ bool m_isSimpleChange;
    /* 0x1A */ bool m_isChangeScene;
    /* 0x1C */ short m_timer;
    /* 0x20 */ dFader_c::fader_type_e m_faderType;
};
