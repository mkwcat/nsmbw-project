//
//  slu/vtable.hpp
//  supplemental-language-utilities
//

#pragma once

#include <type_traits>

namespace slu {

class vtable {
    const void* m_data[2];

    template <class T>
    using class_type = __remove_cvref(__remove_pointer(__remove_reference_t(T)));

public:
    const void* const* raw() const { return m_data; }

    template <class Base>
    static constexpr const vtable* get(
        const Base* base
    ) {
#if __has_builtin(__builtin_get_vtable_pointer)
        return static_cast<const vtable*>(__builtin_get_vtable_pointer(base));
#else
        return *reinterpret_cast<const vtable* volatile const* volatile>(
            reinterpret_cast<const char*>(base) +
            class_type<Base>::__VTableOffset(static_cast<const Base*>(nullptr))
        );
#endif
    }

    template <class T, class Base = T>
    static constexpr const vtable* get() {
        return T::__VTable(static_cast<const Base*>(nullptr));
    }

    template <class Base>
    static constexpr bool is(
        const Base* base, const vtable* vtable
    ) {
        return get(base) == vtable;
    }

    template <class T, class Base>
    static constexpr bool is(
        const Base* base
    ) {
        return get(base) == get<T>();
    }

    template <class T, class... DerivedFromT, class Base>
    static constexpr T cast(
        Base* base
    ) {
        static_assert(
            (std::is_base_of_v<class_type<Base>, class_type<T>> && ... &&
             (std::is_base_of_v<class_type<T>, class_type<DerivedFromT>>) ),
            "All optional derived types must derive from T"
        );

        if (const vtable* vtable = get(base);
            ((get<class_type<T>>() == vtable) || ... ||
             (vtable == get<class_type<DerivedFromT>>()))) {
            return static_cast<T>(base);
        }
        return nullptr;
    }

    template <class... Base, class T>
    static void fix(
        T* obj
    ) {
        ((*reinterpret_cast<const vtable* volatile*>(
              reinterpret_cast<char*>(static_cast<Base*>(obj)) +
              Base::__VTableOffset(static_cast<const Base*>(nullptr))
          ) = get<T, Base>()),
         ...);
    }

#define __VTABLE_SYM(_OFFSET, _BASE_CLASS, _SYMBOL, _COUNTER) \
    friend class ::slu::vtable; \
\
private: \
    static consteval const ::slu::vtable* __VTable(const _BASE_CLASS*) { \
        extern const ::slu::vtable CONCAT(__vtable, _COUNTER) __asm__(_SYMBOL); \
        return &CONCAT(__vtable, _COUNTER); \
    } \
    static consteval unsigned __VTableOffset(const _BASE_CLASS*) { return _OFFSET; }

#define VTABLE_SYM(_OFFSET, _BASE_CLASS, _SYMBOL) \
    __VTABLE_SYM(_OFFSET, _BASE_CLASS, _SYMBOL, __COUNTER__)

#define VTABLE(_OFFSET, _BASE_CLASS, _ADDRESS) \
    __VTABLE_SYM(_OFFSET, _BASE_CLASS, "ext_" STRINGIFY(_ADDRESS), __COUNTER__)

#define VTABLE_NONE(_OFFSET, _BASE_CLASS) \
    friend class ::slu::vtable; \
\
private: \
    static consteval const ::slu::vtable* __VTable(const _BASE_CLASS*) { return nullptr; } \
    static consteval unsigned __VTableOffset(const _BASE_CLASS*) { return _OFFSET; }
};

#define ABSTRACT \
    { \
        __builtin_trap(); \
        __builtin_unreachable(); \
    }

} // namespace slu
