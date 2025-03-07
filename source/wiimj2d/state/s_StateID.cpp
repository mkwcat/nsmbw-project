// s_StateID.cpp
// NSMBW .text: 0x8015F900 - 0x8015FAE0

#include "s_StateID.h"

/**
 * A null state instance.
 */
[[address(0x80377D04)]]
sStateID_c sStateID::null;

[[address(0x8015F900)]]
sStateID_c::sStateID_c(const char* name);

[[address(0x8015F940)]]
sStateID_c::~sStateID_c();

[[address(0x8015F980)]]
bool sStateID_c::isNull() const;

[[address(0x8015F990)]]
bool sStateID_c::isEqual(const sStateIDIf_c& other) const;

[[address(0x8015FA00)]]
bool sStateID_c::operator==(const sStateIDIf_c& other) const;

[[address(0x8015FA10)]]
bool sStateID_c::operator!=(const sStateIDIf_c& other) const;

[[address(0x8015FA50)]]
bool sStateID_c::isSameName(const char* name) const;

[[address(0x8015FA60)]]
const char* sStateID_c::name() const;

[[address(0x8015FA70)]]
unsigned int sStateID_c::number() const;

// 8015FA80: __sinit_\s_StateID_cpp