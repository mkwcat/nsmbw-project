// d_nextgoto_randomizer.cpp
// nsmbw-project

#include "d_nextgoto_randomizer.h"

#include <cstring>

#pragma clang diagnostic ignored "-Wc++11-narrowing"

dNextGotoRndizer_c::dNextGotoRndizer_c(
  Entry_s* input, Index inputCount, Index* lookupTable, cRnd_c& rnd
)
  : m_inputCount(inputCount)
  , m_input(input)
  , m_entList(new LookupEntry_s[inputCount])
  , m_entCount(0)
  , m_ptrEntList(m_entList)
  , m_excEntList(new LookupEntry_s[inputCount])
  , m_excEntCount(0)
  , m_excEntIndex(0)
  , m_curGroupEnd(0)
  , m_lastEntrance(0)
  , m_entryLookup(lookupTable)
  , m_rnd(rnd)
{
    // Add grouped entries to the list first
    bool inGroup = false;
    for (u16 i = 0; i < m_inputCount; i++) {
        LookupEntry_s entry = {i, m_input[i].group_start, m_input[i].group_end};
        if (!inGroup && entry.group_start == 0 && entry.group_end == 0) {
            continue;
        }

        // Write index and group flags
        m_entList[m_entCount++] = entry;

        if (entry.group_start && entry.group_end) {
            // If the entrance is by itself in a group then move it to
            // exclusive
            setExclusive(m_entCount - 1);
        } else if (entry.group_end) {
            inGroup = false;
        } else if (entry.group_start) {
            inGroup = true;
        }

        m_entryLookup[i] = 0;
    }

    // Add non-grouped entries to the list
    inGroup = false;
    u32 lastGroupedEnt = m_entCount;
    for (u16 i = 0; i < m_inputCount; i++) {
        // Write index and copy group flags
        LookupEntry_s entry = {i, m_input[i].group_start, m_input[i].group_end};
        if (entry.group_end) {
            inGroup = false;
            continue;
        } else if (entry.group_start) {
            inGroup = true;
            continue;
        } else if (inGroup) {
            continue;
        }

        // Write index
        m_entList[m_entCount++] = entry;
    }

    // Reserve a random non-exclusive entrance for the last link
    u32 idx = lastGroupedEnt + m_rnd.next(m_entCount - lastGroupedEnt);
    m_lastEntrance = m_entList[idx].index;
    remove(idx);
}

void dNextGotoRndizer_c::createLookupTable()
{
    while (m_entCount > 0) {
        LookupEntry_s ent1 = select1();
        LookupEntry_s ent2 = select2();

        m_entryLookup[ent1.index] = ent2.index;
        m_entryLookup[ent2.index] = ent1.index;
    }
}

dNextGotoRndizer_c::LookupEntry_s dNextGotoRndizer_c::select1()
{
    // Exclusive entrances always go first
    if (m_excEntCount != 0) {
        m_excEntCount--;
        return m_excEntList[m_excEntIndex++];
    }

    // Reset exclusive index
    m_excEntIndex = 0;

    if (m_curGroupEnd == 0) {
        // Not in a group
        LookupEntry_s entry = m_ptrEntList[0];
        if (!entry.group_start) {
            removeUpdate(0);
            return entry;
        }

        // Start of a group, let's find the end
        for (u32 i = 0; i < m_entCount; i++) {
            if (m_ptrEntList[i].group_end) {
                m_curGroupEnd = i + 1;
                break;
            }
        }

        // Then fall through to the group code
    }

    // Randomly select an entrance within the group. This will make sure
    // that which entry ends up exclusive will be evenly distributed.
    u32 i = m_rnd.next(m_curGroupEnd);
    LookupEntry_s entry = m_ptrEntList[i];
    removeUpdate(i);

    return entry;
}

dNextGotoRndizer_c::LookupEntry_s dNextGotoRndizer_c::select2()
{
    // Entrance 2 cannot be an exclusive entrance
    u32 i = m_rnd.next(m_entCount);
    LookupEntry_s entry = m_ptrEntList[i];
    removeUpdate(i);

    return entry;
}

void dNextGotoRndizer_c::setExclusive(Index idx)
{
    LookupEntry_s val = m_ptrEntList[idx];
    remove(idx);
    m_excEntList[m_excEntIndex + m_excEntCount] = val;
    m_excEntCount++;
}

void dNextGotoRndizer_c::remove(Index idx)
{
    if (idx < m_curGroupEnd) {
        m_curGroupEnd--;
    }

    if (idx == 0) {
        m_ptrEntList += 1;
        m_entCount -= 1;
        return;
    }

    if (idx == (m_entCount - 1)) {
        m_entCount -= 1;
        return;
    }

    std::memmove(
      m_ptrEntList + idx, m_ptrEntList + idx + 1, (m_entCount - idx - 1) * sizeof(LookupEntry_s)
    );
    m_entCount -= 1;
}

void dNextGotoRndizer_c::removeUpdate(Index idx)
{
    LookupEntry_s entry = m_ptrEntList[idx];

    if (entry.group_start) {
        m_ptrEntList[idx + 1].group_start = true;
        if (m_ptrEntList[idx + 1].group_start && m_ptrEntList[idx + 1].group_end) {
            setExclusive(idx + 1);
        }
    }

    if (entry.group_end) {
        m_ptrEntList[idx - 1].group_end = true;
        if (m_ptrEntList[idx - 1].group_start && m_ptrEntList[idx - 1].group_end) {
            setExclusive(idx - 1);
            idx--;
        }
    }

    remove(idx);
}
