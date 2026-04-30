//
//  mkwcat/VTable.hpp
//  nsmbw-project
//

#include <type_traits>

namespace mkwcat
{

class VTable
{
    const void* __data[2];

    template <class T>
    using Class = std::remove_cvref_t<std::remove_pointer_t<std::remove_reference_t<T>>>;

public:
    const void* const* Raw() const
    {
        return __data;
    }

    template <class Base>
    static constexpr const VTable* Get(const Base* base)
    {
#if __has_builtin(__builtin_get_vtable_pointer)
        return static_cast<const VTable*>(__builtin_get_vtable_pointer(base));
#else
        return *reinterpret_cast<const VTable* volatile const* volatile>(
          reinterpret_cast<const char*>(base) + Class<Base>::__VTableOffset
        );
#endif
    }

    template <class T, class Base = T>
    static constexpr const VTable* Get()
    {
        return T::__VTable(static_cast<const Base*>(nullptr));
    }

    template <class Base>
    static constexpr bool Is(const Base* base, const VTable* vtable)
    {
        return Get(base) == vtable;
    }

    template <class T, class Base>
    static constexpr bool Is(const Base* base)
    {
        return Get(base) == Get<T>();
    }

    template <class T, class... DerivedFromT, class Base>
    static constexpr T Cast(Base* base)
    {
        static_assert(
          (std::is_base_of_v<Class<Base>, Class<T>> && ... &&
           (std::is_base_of_v<Class<T>, Class<DerivedFromT>>) ),
          "All optional derived types must derive from T"
        );

        if (const VTable* vtable = Get(base);
            ((Get<Class<T>>() == vtable) || ... || (vtable == Get<Class<DerivedFromT>>()))) {
            return static_cast<T>(base);
        }
        return nullptr;
    }

#define __VTABLE_SYM(_OFFSET, _BASE_CLASS, _SYMBOL, _COUNTER)                                      \
    friend class ::mkwcat::VTable;                                                                 \
                                                                                                   \
private:                                                                                           \
    static consteval const ::mkwcat::VTable* __VTable(const _BASE_CLASS*)                          \
    {                                                                                              \
        extern const ::mkwcat::VTable CONCAT(__vtable, _COUNTER) __asm__(_SYMBOL);                 \
        return &CONCAT(__vtable, _COUNTER);                                                        \
    }                                                                                              \
    static constexpr unsigned __VTableOffset = _OFFSET

#define VTABLE_SYM(_OFFSET, _BASE_CLASS, _SYMBOL)                                                  \
    __VTABLE_SYM(_OFFSET, _BASE_CLASS, _SYMBOL, __COUNTER__)

#define VTABLE(_OFFSET, _BASE_CLASS, _ADDRESS)                                                     \
    __VTABLE_SYM(_OFFSET, _BASE_CLASS, "ext_" STRINGIFY(_ADDRESS), __COUNTER__)

#define VTABLE_NONE(_OFFSET, _BASE_CLASS)                                                          \
    friend class ::mkwcat::VTable;                                                                 \
                                                                                                   \
private:                                                                                           \
    static consteval const ::mkwcat::VTable* __VTable(const _BASE_CLASS*)                          \
    {                                                                                              \
        return nullptr;                                                                            \
    }                                                                                              \
    static constexpr unsigned __VTableOffset = _OFFSET
};

#define MACINTOSH_ABSTRACT                                                                         \
    {                                                                                              \
        __builtin_trap();                                                                          \
        __builtin_unreachable();                                                                   \
    }

} // namespace mkwcat
