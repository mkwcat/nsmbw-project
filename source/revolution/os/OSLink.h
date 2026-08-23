#pragma once

EXTERN_C_START

struct OSModuleInfo;

struct OSModuleLink {
    SIZE_ASSERT(0x8);

    /* 0x0 */ OSModuleInfo* next;
    /* 0x4 */ OSModuleInfo* prev;
};

struct OSModuleInfo {
    SIZE_ASSERT(0x20);

    /* 0x00 */ u32          id;
    /* 0x04 */ OSModuleLink head;
    /* 0x0C */ u32          numSections;
    /* 0x10 */ u32          sectionInfoOffset;
    /* 0x14 */ u32          nameOffset;
    /* 0x18 */ u32          nameLen;
    /* 0x1C */ u32          version;
};

struct OSModuleHeader {
    SIZE_ASSERT(0x4C);

    /* 0x00 */ OSModuleInfo info;
    /* 0x20 */ u32          bssSize;
    /* 0x24 */ u32          relOffset;
    /* 0x28 */ u32          impOffset;
    /* 0x2C */ u32          impSize;
    /* 0x30 */ u8           prologSection;
    /* 0x31 */ u8           epilogSection;
    /* 0x32 */ u8           unresolvedSection;
    /* 0x33 */ u8           bssSection;
    /* 0x34 */ u32          prolog;
    /* 0x38 */ u32          epilog;
    /* 0x3C */ u32          unresolved;
    /* 0x40 */ u32          align;
    /* 0x44 */ u32          bssAlign;
    /* 0x48 */ u32          fixSize;
};

struct OSModuleImportInfo {
    SIZE_ASSERT(0x8);

    /* 0x0 */ u32 moduleId;
    /* 0x4 */ u32 offset;
};

struct OSModuleSectionInfo {
    SIZE_ASSERT(0x8);

    /* 0x0 */ u32 offset;
    /* 0x4 */ u32 length;
};

enum {
    R_PPC_NONE             = 0,
    R_PPC_ADDR32           = 1,
    R_PPC_ADDR24           = 2,
    R_PPC_ADDR16           = 3,
    R_PPC_ADDR16_LO        = 4,
    R_PPC_ADDR16_HI        = 5,
    R_PPC_ADDR16_HA        = 6,
    R_PPC_ADDR14           = 7,
    R_PPC_ADDR14_BRTAKEN   = 8,
    R_PPC_ADDR14_BRNKTAKEN = 9,
    R_PPC_REL24            = 10,
    R_PPC_REL14            = 11,
    R_PPC_REL14_BRTAKEN    = 12,
    R_PPC_REL14_BRNTAKEN   = 13,
    R_RVL_NONE             = 201,
    R_RVL_SECT             = 202,
    R_RVL_STOP             = 203,
};

struct OSModuleRelInfo {
    SIZE_ASSERT(0x8);

    /* 0x0 */ u16 offset;
    /* 0x2 */ u8  type;
    /* 0x3 */ u8  section;
    /* 0x4 */ u32 addend;
};

/* 0x801B2060 */
bool OSLink(OSModuleInfo* info, void* bss);

/* 0x801B2070 */
bool OSLinkFixed(OSModuleInfo* info, void* bss);

//
EXTERN_C_END
