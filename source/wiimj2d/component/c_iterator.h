#pragma once

template <class T>
class cIter_c {
public:
    // Type Aliases
    // ^^^^^^

    using value_type = T;
    using pointer    = T*;
    using reference  = T&;

public:
    // Structors
    // ^^^^^^

    constexpr cIter_c(
        pointer start, pointer end
    )
        : mpBegin(start)
        , mpEnd(end) {}

    constexpr cIter_c(
        pointer start, std::size_t count
    )
        : mpBegin(start)
        , mpEnd(start + count) {}

    template <std::size_t N>
    constexpr cIter_c(
        T (&array)[N]
    )
        : mpBegin(array)
        , mpEnd(array + N) {}

public:
    // Instance Methods
    // ^^^^^^

    constexpr pointer begin() const { return mpBegin; }

    constexpr pointer end() const { return mpEnd; }

public:
    // Instance Variables
    // ^^^^^^

    pointer mpBegin;
    pointer mpEnd;
};
