#pragma once

#include "component/c_random.h"

class dNextGotoRndizer_c final
{
public:
    // Nested Types
    // ^^^^^^

    using Index = u16;

    struct Entry_s {
        SIZE_ASSERT(sizeof(u32));

        u32 world : 7;
        u32 stage : 9;
        u32 course : 2;
        u32 nextgoto : 8;
        u32 group_start : 1;
        u32 group_end : 1;
    };

    struct LookupEntry_s {
        SIZE_ASSERT(sizeof(Index));

        u16 index : 14;
        u16 group_start : 1;
        u16 group_end : 1;
    };

public:
    // Structors
    // ^^^^^^

    dNextGotoRndizer_c(Entry_s* input, Index inputCount, Index* lookupTable, cRnd_c& rnd);

    ~dNextGotoRndizer_c()
    {
        delete[] m_entList;
        delete[] m_excEntList;
    }

public:
    // Instance Methods
    // ^^^^^^

    void createLookupTable();
    LookupEntry_s select1();
    LookupEntry_s select2();
    void setExclusive(Index idx);
    void remove(Index idx);
    void removeUpdate(Index idx);

private:
    // Instance Variables
    // ^^^^^^

    const Index m_inputCount;
    Entry_s* const m_input;

    LookupEntry_s* const m_entList;
    Index m_entCount;
    LookupEntry_s* m_ptrEntList;

    LookupEntry_s* const m_excEntList;
    Index m_excEntCount;
    Index m_excEntIndex;

    Index m_curGroupEnd;
    Index m_lastEntrance;

    Index* m_entryLookup;

    cRnd_c m_rnd;
};