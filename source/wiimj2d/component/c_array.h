#pragma once

#include <mkwcat/Concepts.hpp>

template <class T, std::size_t N, class S = std::size_t>
class cArrayRef_c;

template <class T, std::size_t N, class S = std::size_t>
class cArray_c {
public:
    // Type Aliases
    // ^^^^^^

    using value_type      = T;
    using size_type       = S;
    using difference_type = std::ptrdiff_t;
    using reference       = T&;
    using const_reference = const T&;
    using pointer         = T*;
    using const_pointer   = const T*;

public:
    // Instance Methods
    // ^^^^^^

    constexpr reference at(
        size_type index
    ) noexcept {
        return m_data[static_cast<std::size_t>(index)];
    }

    constexpr const_reference at(
        size_type index
    ) const noexcept {
        return m_data[static_cast<std::size_t>(index)];
    }

    constexpr reference operator[](
        size_type index
    ) noexcept {
        return m_data[static_cast<std::size_t>(index)];
    }

    constexpr const_reference operator[](
        size_type index
    ) const noexcept {
        return m_data[static_cast<std::size_t>(index)];
    }

    constexpr pointer data() noexcept { return m_data; }

    constexpr const_pointer data() const noexcept { return m_data; }

    constexpr pointer begin() noexcept { return m_data; }

    constexpr const_pointer begin() const noexcept { return m_data; }

    constexpr pointer end() noexcept { return m_data + static_cast<std::size_t>(N); }

    constexpr const_pointer end() const noexcept { return m_data + static_cast<std::size_t>(N); }

    constexpr size_type index(
        const_pointer ptr
    ) const noexcept {
        return static_cast<size_type>(ptr - m_data);
    }

    constexpr size_type index(
        const_reference ref
    ) const noexcept {
        return static_cast<size_type>(&ref - m_data);
    }

    constexpr cArrayRef_c<T, N, S> operator&() noexcept { return cArrayRef_c<T, N, S>{m_data}; }

public:
    // Static Methods
    // ^^^^^^

    constexpr static size_type size() noexcept { return static_cast<size_type>(N); }

    constexpr static cArray_c of(
        const value_type& value
    ) noexcept {
        cArray_c array = {};
        for (std::size_t i = 0; i < static_cast<std::size_t>(N); i++) {
            array.m_data[i] = value;
        }
        return array;
    }

public:
    // Instance Variables
    // ^^^^^^

    value_type m_data[N];
};

template <class T, std::size_t N, class S>
class cArrayRef_c {
    friend class cArray_c<T, N, S>;

public:
    // Type Aliases
    // ^^^^^^

    using value_type      = T;
    using size_type       = S;
    using difference_type = std::ptrdiff_t;
    using reference       = T&;
    using const_reference = const T&;
    using pointer         = T*;
    using const_pointer   = const T*;

public:
    // Structors
    // ^^^^^^

    constexpr cArrayRef_c(
        pointer data
    ) noexcept
        : m_data(data) {}

    constexpr cArrayRef_c(const cArrayRef_c&) noexcept = default;

public:
    // Instance Methods
    // ^^^^^^

    constexpr reference at(
        size_type index
    ) noexcept {
        return m_data[static_cast<std::size_t>(index)];
    }

    constexpr const_reference at(
        size_type index
    ) const noexcept {
        return m_data[static_cast<std::size_t>(index)];
    }

    constexpr reference operator[](
        size_type index
    ) noexcept {
        return m_data[static_cast<std::size_t>(index)];
    }

    constexpr const_reference operator[](
        size_type index
    ) const noexcept {
        return m_data[static_cast<std::size_t>(index)];
    }

    constexpr cArrayRef_c& operator=(
        const cArrayRef_c& other
    ) noexcept {
        m_data = other.m_data;
        return *this;
    }

    constexpr reference operator=(
        const cArray_c<T, N, S>& other
    ) noexcept {
        this->operator=(other.m_data);
    }

    constexpr cArray_c<T, N, S>& operator*() noexcept { return *this; }

    constexpr pointer data() noexcept { return m_data; }

    constexpr const_pointer data() const noexcept { return m_data; }

    constexpr pointer begin() noexcept { return m_data; }

    constexpr const_pointer begin() const noexcept { return m_data; }

    constexpr pointer end() noexcept { return m_data + static_cast<std::size_t>(N); }

    constexpr const_pointer end() const noexcept { return m_data + static_cast<std::size_t>(N); }

    constexpr size_type index(
        const_pointer ptr
    ) const noexcept {
        return static_cast<size_type>(ptr - m_data);
    }

    constexpr size_type index(
        const_reference ref
    ) const noexcept {
        return static_cast<size_type>(&ref - m_data);
    }

public:
    // Static Methods
    // ^^^^^^

    constexpr static size_type size() noexcept { return static_cast<size_type>(N); }

private:
    // Instance Variables
    // ^^^^^^

    pointer m_data;
};

template <class T, mkwcat::Test<std::is_enum> S>
using cEnumArray_c = cArray_c<T, static_cast<std::size_t>(S::COUNT), S>;

template <class T, mkwcat::Test<std::is_enum> S>
using cEnumArrayRef_c = cArrayRef_c<T, static_cast<std::size_t>(S::COUNT), S>;
