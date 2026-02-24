#pragma once

class dCdFile_c
{
public:
    // Structors
    // ^^^^^^

    dCdFile_c();

    /* VT+0x8 */
    virtual ~dCdFile_c();

public:
    // Constants and Types
    // ^^^^^^

    // @unofficial
    struct CourseInfo_s {
        SIZE_ASSERT(0x14);

        FILL(0x00, 0x11);

        /* 0x11 */ bool mIsAmbush;

        FILL(0x12, 0x14);
    };

    struct NextGoto_s {
        SIZE_ASSERT(0x14);

        /* 0x00 */ u16 x;
        /* 0x02 */ u16 y;
        /* 0x04 */ u16 m0x4;
        /* 0x06 */ u16 m0x6;
        /* 0x08 */ u8 num;
        /* 0x09 */ u8 nextCourseNum;
        /* 0x0A */ u8 nextNextGotoNum;
        /* 0x0B */ u8 type;
        /* 0x0C */ u8 m0xC;
        /* 0x0D */ u8 nextAreaNum;
        /* 0x0E */ u8 layer;
        /* 0x0F */ u8 pathNode;
        /* 0x10 */ u16 flags;
        /* 0x12 */ u16 m0x12;
    };

public:
    // Instance Methods
    // ^^^^^^

    /* 0x8008E3D0 */
    NextGoto_s* getNextGotoP(u8);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x004 */ u8 mCourseID;
    /* 0x008 */ void* mpPaletteList;
    /* 0x00C */ CourseInfo_s* mpCourseInfo;
    /* 0x010 */ void* mpOptions;
    /* 0x014 */ void* mpScrollData;
    /* 0x018 */ void* mpBlock4;
    /* 0x01C */ void* mpBg2Data; 
    /* 0x020 */ void* mpBg3Data; 
    /* 0x024 */ NextGoto_s* mpNextGotos;
    /* 0x028 */ void* mpBlock8;
    /* 0x02C */ void* mpAreas;
};

class dCd_c
{
public:
    // Static Methods
    // ^^^^^^

    /* 0x8005EE70 */
    static dCdFile_c* getFileP(int course);

public:
    // Instance Variables
    // ^^^^^^
    dCdFile_c mFiles[4];

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A178 */ static dCd_c* m_instance;
};
