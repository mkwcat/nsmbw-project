#pragma once

#include "s_StateInterfaces.h"

/**
 * A generic implementation of a state ID. It simply contains a name string and a unique number.
 */
class sStateID_c : public sStateIDIf_c {
public:
    class NumberMemo_c {
    public:
        constexpr NumberMemo_c()
            : curr(0) {}

        constexpr unsigned get() {
            curr++;
            return curr;
        }

        unsigned curr;
    };

    constexpr sStateID_c()
        : mpName(nullptr)
        , mNumber(-1) {}

    /* 0x8015F900 */
    sStateID_c(const char* name);

    /* VT+0x08 0x8015F940 */
    virtual ~sStateID_c();

    /* VT+0x0C 0x8015F980 */
    virtual bool isNull() const;

    /* VT+0x10 0x8015F990 */
    virtual bool isEqual(const sStateIDIf_c& other) const;

    /* VT+0x14 0x8015FA00 */
    virtual bool operator==(const sStateIDIf_c& other) const;

    /* VT+0x18 0x8015FA10 */
    virtual bool operator!=(const sStateIDIf_c& other) const;

    /* VT+0x1C 0x8015FA50 */
    virtual bool isSameName(const char* name) const;

    /* VT+0x20 0x8015FA60 */
    virtual const char* name() const;

    /* VT+0x24 0x8015FA70 */
    virtual unsigned number() const;

protected:
    /**
     * The name of this state ID.
     */
    /* 0x04 */ const char* mpName;

    /**
     * The number of this state ID.
     */
    /* 0x08 */ mutable unsigned mNumber;

    /**
     * Used to give each state a unique number.
     */
    /* 0x8042A640 */ static NumberMemo_c sm_numberMemo;
};

namespace sStateID {

/**
 * 0x80377D04
 * A null state instance.
 */
extern sStateID_c null;

} // namespace sStateID
