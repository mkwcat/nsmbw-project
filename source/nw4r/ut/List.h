#pragma once

namespace nw4r::ut {

struct List {
    SIZE_ASSERT(0xC);

    /* 0x0 */ void* headObject;
    /* 0x4 */ void* tailObject;
    /* 0x8 */ u16   numObjects;
    /* 0xA */ u16   offset;
};

struct Link {
    SIZE_ASSERT(0x8);

    /* 0x0 */ void* prevObject;
    /* 0x4 */ void* nextObject;
};

/**
 * Declares a member Link.
 */
#define NW4R_UT_LIST_LINK_DECL() nw4r::ut::Link link

/* 0x80228F10 */
void List_Init(List* list, u16 offset);

/* 0x80228F30 */
void List_Append(List* list, void* object);

/* UNUSED */
void List_Prepend(List* list, void* object);

/* 0x80228FA0 */
void List_Insert(List* list, void* target, void* object);

/* 0x802290C0 */
void List_Remove(List* list, void* object);

/* 0x80229130 */
void* List_GetNext(const List* list, const void* object);

/* 0x80229150 */
void* List_GetPrev(const List* list, const void* object);

/* UNUSED */
void* List_GetNth(const List* list, u16 n);

} // namespace nw4r::ut
