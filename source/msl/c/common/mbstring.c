// mbstring.c
// NSMBW .text: 0x802DF06C - 0x802DF264

#include <cstdlib>

[[nsmbw(0x802DF0EC)]]
std::size_t mbstowcs(wchar_t* dest, const char* src, std::size_t n);