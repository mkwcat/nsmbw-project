#pragma once

#include "component/c_json.h"
#include "component/c_random.h"
#include <vector>

struct dNextGotoEntry_s {
    SIZE_ASSERT(sizeof(u32));

    u32 world : 7;
    u32 stage : 9;
    u32 course : 2;
    u32 nextgoto : 8;
    u32 group_start : 1;
    u32 group_end : 1;
};

class dNextGotoList_c final : private cJsonParser_c::HandlerIf_c,
                              public std::vector<dNextGotoEntry_s>
{
public:
    // Type Aliases
    // ^^^^^^

    using Entry_s = dNextGotoEntry_s;

    using Index = u16;

public:
    // Nested Types
    // ^^^^^^

    struct LookupEntry_s {
        SIZE_ASSERT(sizeof(Index));

        u16 index : 14;
        u16 group_start : 1;
        u16 group_end : 1;
    };

    class Randomizer_c;

public:
    // Structors
    // ^^^^^^

    constexpr dNextGotoList_c() = default;

    dNextGotoList_c(const char* data, std::size_t dataSize);

public:
    // Instance Methods
    // ^^^^^^

    void randomize(s32 seed);

    s32 getSeed() const
    {
        return m_seed;
    }

private:
    // Instance Variables
    // ^^^^^^

    enum class State_e {
        NONE,
        ROOT,
        STAGE,
        COURSE,
        GROUP,
    } m_state = State_e::NONE, m_nextState = State_e::NONE;

    Entry_s m_entry = {};
    bool m_groupHasEntry = false;

    std::vector<Index> m_lookupTable;
    s32 m_seed = 0;

public:
    // Static Methods
    // ^^^^^^

    static dNextGotoList_c& create();

    static char* readResource(std::size_t& outSize);
    static void freeResource(char* data);

public:
    // Static Variables
    // ^^^^^^

    static dNextGotoList_c ms_instance;
    static std::vector<Index>& ms_lookup;

private:
    // JSON interface
    // ^^^^^^^

    bool null() override
    {
        return false;
    }

    bool value(s64 number) override;

    bool value(double number) override
    {
        return false;
    }

    bool rawNumber(const char* str, std::size_t length, bool copy) override
    {
        return false;
    }

    bool string(const char* str, std::size_t length, bool copy) override;

    bool key(const char* str, std::size_t length, bool copy) override;

    bool startObject() override;
    bool endObject() override;
    bool startArray() override;
    bool endArray() override;
};

constinit inline std::vector<dNextGotoList_c::Index>& dNextGotoList_c::ms_lookup =
  dNextGotoList_c::ms_instance.m_lookupTable;

class dNextGotoList_c::Randomizer_c final
{
public:
    // Structors
    // ^^^^^^

    Randomizer_c(Entry_s* input, Index inputCount, Index* lookupTable, cRnd_c&& rnd);

    ~Randomizer_c()
    {
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
    Entry_s* const m_pInput;

    std::vector<LookupEntry_s> m_entList;
    std::vector<LookupEntry_s> m_excEntList;

    Index m_curGroupEnd;
    Index m_lastEntrance;

    Index* m_pEntryLookup;

    cRnd_c m_rnd;
};