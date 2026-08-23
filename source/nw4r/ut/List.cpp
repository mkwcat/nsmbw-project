// ut_list.cpp
// NSMBW .text: 0x80228F10 - 0x80229170

#include "List.h"

namespace nw4r::ut {

[[nsmbw(0x80228F10)]]
void List_Init(List* list, u16 offset);

[[nsmbw(0x80228F30)]]
void List_Append(List* list, void* obj);

// UNUSED: void List_Prepend(List* list, void* obj)

[[nsmbw(0x80228FA0)]]
void List_Insert(List* list, void* target, void* obj);

[[nsmbw(0x802290C0)]]
void List_Remove(List* list, void* obj);

[[nsmbw(0x80229130)]]
void* List_GetNext(const List* list, const void* obj);

[[nsmbw(0x80229150)]]
void* List_GetPrev(const List* list, const void* obj);

// UNUSED: void* List_GetNth(const List* list, u16 index)

} // namespace nw4r::ut
