//
//  Literals.hpp
//  nsmbw-project
//

namespace mkwcat::Literals
{

constexpr u64 operator""_bit(u64 bit)
{
    return 1ull << bit;
}

} // namespace mkwcat::Literals