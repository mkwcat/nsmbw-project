#pragma once

// Declare type RTTI and accessor function
#define NW4R_UT_RTTI_DECL(T) \
    virtual const nw4r::ut::detail::RuntimeTypeInfo* GetRuntimeTypeInfo() const { \
        return &typeInfo; \
    } \
    static nw4r::ut::detail::RuntimeTypeInfo typeInfo

// Define type RTTI (base type)
#define NW4R_UT_RTTI_DEF_BASE(T) nw4r::ut::detail::RuntimeTypeInfo T::typeInfo(nullptr)

// Define type RTTI (derived type)
#define NW4R_UT_RTTI_DEF_DERIVED(T, BASE) \
    nw4r::ut::detail::RuntimeTypeInfo T::typeInfo(&BASE::typeInfo)

namespace nw4r::ut {

namespace detail {

struct RuntimeTypeInfo {
    constexpr RuntimeTypeInfo(
        const RuntimeTypeInfo* base
    )
        : mParentTypeInfo(base) {}

    bool IsDerivedFrom(
        const RuntimeTypeInfo* typeInfo
    ) const {
        for (const RuntimeTypeInfo* it = this; it != nullptr; it = it->mParentTypeInfo) {
            if (it == typeInfo) {
                return true;
            }
        }

        return false;
    }

    /* 0x0 */ const RuntimeTypeInfo* mParentTypeInfo;
};

template <class T>
inline const RuntimeTypeInfo* GetTypeInfoFromPtr_(
    const T* obj
) {
    return &obj->typeInfo;
}

} // namespace detail

template <class TDerived, class TBase>
inline TDerived DynamicCast(
    TBase* obj
) {
    // Derived type info
    const detail::RuntimeTypeInfo* typeInfoU =
        detail::GetTypeInfoFromPtr_(static_cast<TDerived>(nullptr));
    // Downcast if possible
    if (obj && obj->GetRuntimeTypeInfo()->IsDerivedFrom(typeInfoU)) {
        return static_cast<TDerived>(obj);
    }

    return nullptr;
}

} // namespace nw4r::ut
