//
//  slu/array.hpp
//  supplemental-language-utilities
//

#pragma once

#include "slu/base_types.hpp"
#include "slu/concepts.hpp"

namespace slu {

template <class T, base_types::size_type N, class S = base_types::size_type>
class array {
public:
    // Nested Types
    // ^^^^^^

    class ref;

public:
    // Type Aliases
    // ^^^^^^

    using value_type      = T;
    using size_type       = S;
    using difference_type = ptrdiff_type;
    using reference       = T&;
    using const_reference = const T&;
    using pointer         = T*;
    using const_pointer   = const T*;

public:
    // Instance Variables
    // ^^^^^^

    value_type m_data[N];

public:
    // Instance Methods
    // ^^^^^^

    constexpr reference at(
        size_type index
    ) noexcept {
        return m_data[static_cast<base_types::size_type>(index)];
    }

    constexpr const_reference at(
        size_type index
    ) const noexcept {
        return m_data[static_cast<base_types::size_type>(index)];
    }

    constexpr reference operator[](
        size_type index
    ) noexcept {
        return m_data[static_cast<base_types::size_type>(index)];
    }

    constexpr const_reference operator[](
        size_type index
    ) const noexcept {
        return m_data[static_cast<base_types::size_type>(index)];
    }

    constexpr pointer data() noexcept { return m_data; }

    constexpr const_pointer data() const noexcept { return m_data; }

    constexpr pointer begin() noexcept { return m_data; }

    constexpr const_pointer begin() const noexcept { return m_data; }

    constexpr pointer end() noexcept { return m_data + static_cast<base_types::size_type>(N); }

    constexpr const_pointer end() const noexcept {
        return m_data + static_cast<base_types::size_type>(N);
    }

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

    constexpr ref operator&() noexcept { return ref{m_data}; }

public:
    // Static Methods
    // ^^^^^^

    constexpr static size_type size() noexcept { return static_cast<size_type>(N); }

    constexpr static array of(
        const value_type& value
    ) noexcept {
        array array = {};
        for (base_types::size_type i = 0; i < static_cast<base_types::size_type>(N); i++) {
            array.m_data[i] = value;
        }
        return array;
    }
};

template <class T, base_types::size_type N, class S>
class array<T, N, S>::ref {
    friend class array<T, N, S>;

public:
    // Type Aliases
    // ^^^^^^

    using value_type      = T;
    using size_type       = S;
    using difference_type = ptrdiff_type;
    using reference       = T&;
    using const_reference = const T&;
    using pointer         = T*;
    using const_pointer   = const T*;

private:
    // Instance Variables
    // ^^^^^^

    pointer m_data;

public:
    // Structors
    // ^^^^^^

    constexpr ref(
        pointer data
    ) noexcept
        : m_data(data) {}

    constexpr ref(const ref&) noexcept = default;

public:
    // Instance Methods
    // ^^^^^^

    constexpr reference at(
        size_type index
    ) noexcept {
        return m_data[static_cast<base_types::size_type>(index)];
    }

    constexpr const_reference at(
        size_type index
    ) const noexcept {
        return m_data[static_cast<base_types::size_type>(index)];
    }

    constexpr reference operator[](
        size_type index
    ) noexcept {
        return m_data[static_cast<base_types::size_type>(index)];
    }

    constexpr const_reference operator[](
        size_type index
    ) const noexcept {
        return m_data[static_cast<base_types::size_type>(index)];
    }

    constexpr ref& operator=(
        const ref& other
    ) noexcept {
        m_data = other.m_data;
        return *this;
    }

    constexpr ref& operator*() noexcept { return *this; }

    constexpr pointer data() noexcept { return m_data; }

    constexpr const_pointer data() const noexcept { return m_data; }

    constexpr pointer begin() noexcept { return m_data; }

    constexpr const_pointer begin() const noexcept { return m_data; }

    constexpr pointer end() noexcept { return m_data + static_cast<base_types::size_type>(N); }

    constexpr const_pointer end() const noexcept {
        return m_data + static_cast<base_types::size_type>(N);
    }

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
};

template <class T, concepts::enum_type S>
using enum_array = array<T, static_cast<base_types::size_type>(S::COUNT), S>;

} // namespace slu
