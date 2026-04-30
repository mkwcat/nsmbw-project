#pragma once

#include "d_system/d_system.h"
#include "framework/f_base.h"
#include "framework/f_profile.h"
#include <mkwcat/Concepts.hpp>
#include <type_traits>

class dBase_c;

using dProfName = fProfName;

namespace dProf
{

constexpr std::size_t BASE_COUNT = 754;

constexpr std::size_t COUNT = [] -> std::size_t {
    std::size_t max = 0;
#define PROFILE(_ID, _NAME, _CLASS) _ID > max ? max = _ID : 0;
#include "d_profile_table.inc"
#undef PROFILE
    return max + 1;
}();

constexpr std::size_t CUSTOM_COUNT = COUNT - BASE_COUNT;

template <dProfName V>
struct Name_c {
    static constexpr dProfName StaticNonRegionalValue = V;

    static inline constexpr dProfName toNative();

    constexpr operator dProfName() const
    {
        return toNative();
    }
};

#define PROFILE(_ID, _NAME, _CLASS) constexpr Name_c<_ID> _NAME;
#include "d_profile_table.inc"
#undef PROFILE

template <dProfName V>
inline constexpr dProfName Name_c<V>::toNative()
{
    // Apply the region-dependant changes to the value
    dProfName value = V;

    if constexpr (V > LASTACTOR.StaticNonRegionalValue) {
        // Custom actors are not region-dependent
        return value;
    }

    if constexpr (V >= TIME_UP.StaticNonRegionalValue) {
        if (dSys_c::m_codeRegion < dSys_c::CODE_REGION_e::K) {
            value -= 2;
        }
    }
    if constexpr (V >= WM_CS_SEQ_MNG.StaticNonRegionalValue) {
        if (dSys_c::m_codeRegion < dSys_c::CODE_REGION_e::C) {
            value -= 2;
        }
    }
    return value;
}

template <class Owner, auto... Profiles>
struct Info {
};

template <class Owner, auto... Profiles>
inline constexpr bool hasProfile(dProfName prof, const Info<Owner, Profiles...>*)
{
    return (false || ... || (Profiles == prof));
}

/**
 * Downcast the base to the specified type. Verifies the object's profile with the specified type's
 * profile, and returns nullptr if the profile doesn't match.
 */
template <class T>
constexpr T* cast(fBase_c* base)
{
    static_assert(mkwcat::CompleteType<T>, "Cast to an incomplete type");

    if constexpr (std::is_same_v<T, dBase_c>) {
        // Everything is a dBase_c
        return static_cast<T*>(base);
    } else {
        if (hasProfile<T>(base->mProfName, static_cast<const T*>(nullptr))) {
            return static_cast<T*>(base);
        }
    }

    // Wrong type
    return nullptr;
}

/* 0x801018C0 @renamed */
const char* getName(dProfName profile);

const char* getFormattedName(dBase_c* base);

dProfName getProfByName(const char* string);

} // namespace dProf
