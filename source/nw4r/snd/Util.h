#pragma once

namespace nw4r::snd::detail::Util {

template <typename T0, typename T1 = void, typename T2 = void, typename T3 = void>
struct DataRef {
    SIZE_ASSERT(0x8);
    /* 0x0 */ u8  refType;
    /* 0x1 */ u8  dataType;
    /* 0x2 */ u16 reserved;
    /* 0x4 */ u32 value;
};

template <typename T>
struct Table {
    /* 0x0 */ u32 count;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc99-extensions"
    /* 0x4 */ T items[];
#pragma clang diagnostic pop
};

enum class RefType {
    ADDRESS = 0,
    OFFSET  = 1,
};

template <typename T0, typename T1, typename T2, typename T3>
inline const T0* GetDataRefAddress0(
    const DataRef<T0, T1, T2, T3>& rRef, const void* pBase
) {
    return static_cast<const T0*>(
        GetDataRefAddressImpl(static_cast<RefType>(rRef.refType), rRef.value, pBase)
    );
}

template <typename T0, typename T1, typename T2, typename T3>
inline const T1* GetDataRefAddress1(
    const DataRef<T0, T1, T2, T3>& rRef, const void* pBase
) {
    return static_cast<const T1*>(
        GetDataRefAddressImpl(static_cast<RefType>(rRef.refType), rRef.value, pBase)
    );
}

template <typename T0, typename T1, typename T2, typename T3>
inline const T2* GetDataRefAddress2(
    const DataRef<T0, T1, T2, T3>& rRef, const void* pBase
) {
    return static_cast<const T2*>(
        GetDataRefAddressImpl(static_cast<RefType>(rRef.refType), rRef.value, pBase)
    );
}

template <typename T0, typename T1, typename T2, typename T3>
inline const T3* GetDataRefAddress3(
    const DataRef<T0, T1, T2, T3>& rRef, const void* pBase
) {
    return static_cast<const T3*>(
        GetDataRefAddressImpl(static_cast<RefType>(rRef.refType), rRef.value, pBase)
    );
}

/* 0x80283BA0 */
const void* GetDataRefAddressImpl(RefType type, u32 value, const void* pBase);

} // namespace nw4r::snd::detail::Util
