#pragma once

// Declare type RTTI and accessor function
#define NW4R_UT_RTTI_DECL(T) \
    virtual const nw4r::ut::detail::RuntimeTypeInfo* GetRuntimeTypeInfo() const { \
        return &typeInfo; \
    } \
    static nw4r::ut::detail::RuntimeTypeInfo typeInfo

// Define type RTTI (base type)
#define NW4R_UT_RTTI_DEF_BASE(T) nw4r::ut::detail::RuntimeTypeInfo T::typeInfo(NULL)

// Define type RTTI (derived type)
#define NW4R_UT_RTTI_DEF_DERIVED(T, BASE) \
    nw4r::ut::detail::RuntimeTypeInfo T::typeInfo(&BASE::typeInfo)

namespace nw4r::ut {

namespace detail {

struct RuntimeTypeInfo {
    RuntimeTypeInfo(
        const RuntimeTypeInfo* base
    )
        : mBase(base) {}

    bool IsDerivedFrom(
        const RuntimeTypeInfo* base
    ) const {
        for (const RuntimeTypeInfo* it = this; it != nullptr; it = it->mBase) {
            if (it == base) {
                return true;
            }
        }

        return false;
    }

    /* 0x0 */ const RuntimeTypeInfo* mBase;
};

template <typename T>
inline const RuntimeTypeInfo* GetTypeInfoFromPtr_(
    T* ptr
) {
    return &ptr->typeInfo;
}

} // namespace detail

template <typename TDerived, typename TBase>
inline TDerived DynamicCast(
    TBase* ptr
) {
    // Derived type info
    const detail::RuntimeTypeInfo* derivedTypeInfo =
        detail::GetTypeInfoFromPtr_(static_cast<TDerived>(nullptr));
    // Downcast if possible
    if (ptr && ptr->GetRuntimeTypeInfo()->IsDerivedFrom(derivedTypeInfo)) {
        return static_cast<TDerived>(ptr);
    }

    return nullptr;
}

} // namespace nw4r::ut
