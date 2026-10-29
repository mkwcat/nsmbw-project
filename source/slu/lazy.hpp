//
//  slu/member_pointer.hpp
//  supplemental-language-utilities
//

#pragma once

namespace slu {

template <class T>
constexpr T&& forward(
    __remove_reference_t(T)& t
) noexcept {
    return static_cast<T&&>(t);
}

template <class T>
constexpr T&& forward(
    __remove_reference_t(T)&& t
) noexcept {
    return static_cast<T&&>(t);
}

} // namespace slu

// Hack to allow constexpr placement new
namespace std::__ {

template <class T, class... Args>
constexpr T* slu_construct_at(
    void* p, Args&&... args
) {
    return ::new (p) T(::slu::forward<Args>(args)...);
}

} // namespace std::__

namespace slu {

template <class T>
class lazy_unsafe {
    alignas(alignof(T)) char m_data[sizeof(T)];

public:
    constexpr lazy_unsafe() = default;

    template <class... Args>
    constexpr T* construct(
        Args&&... args
    ) {
        return ::std::__::slu_construct_at<T>(&m_data, forward<Args>(args)...);
    }

    constexpr void destroy() { ptr()->~T(); }

    constexpr char* raw_data() { return m_data; }

    constexpr const char* raw_data() const { return m_data; }

    constexpr T* ptr() { return reinterpret_cast<T*>(m_data); }

    constexpr const T* ptr() const { return reinterpret_cast<const T*>(m_data); }

    constexpr bool valid() const { return ptr() != nullptr; }

    constexpr T& operator*() { return *ptr(); }

    constexpr const T& operator*() const { return *ptr(); }

    constexpr T* operator->() { return ptr(); }

    constexpr const T* operator->() const { return ptr(); }
};

template <class T>
class lazy {
    alignas(alignof(T)) char m_data[sizeof(T)];
    T* m_ptr;

public:
    constexpr lazy()
        : m_ptr(nullptr) {}

    constexpr ~lazy() { destroy(); }

    template <class... Args>
    constexpr T* construct(
        Args&&... args
    ) {
        return m_ptr = ::std::__::slu_construct_at<T>(&m_data, forward<Args>(args)...);
    }

    constexpr void destroy() {
        if (m_ptr) {
            T* ptr = m_ptr;
            m_ptr  = nullptr;
            ptr->~T();
        }
    }

    constexpr char* raw_data() { return m_data; }

    constexpr const char* raw_data() const { return m_data; }

    constexpr T* ptr() { return m_ptr; }

    constexpr const T* ptr() const { return m_ptr; }

    constexpr bool valid() const { return m_ptr != nullptr; }

    constexpr T& operator*() { return *m_ptr; }

    constexpr const T& operator*() const { return *m_ptr; }

    constexpr T* operator->() { return m_ptr; }

    constexpr const T* operator->() const { return m_ptr; }
};

} // namespace slu
