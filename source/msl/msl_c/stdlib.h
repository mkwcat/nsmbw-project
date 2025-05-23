#pragma once

#include "string.h"

// Compiler intrinsic functions.
#define abs(x) __builtin_abs(x)
#define labs(x) __builtin_abs(x)

long strtol(const char* restrict nptr, char** restrict endptr, int base);
unsigned long int strtoul(const char* str, char** endptr, int base);
unsigned long __strtoul(int, int, int (*)(void*, int, int), void*, int*, int*, int*);

int atoi(const char* nptr);
long atol(const char* nptr);
long long atoll(const char* nptr);
long long atoq(const char* nptr);
double atof(const char* nptr);

void qsort(void* base, size_t nitems, size_t size, int (*compar)(const void*, const void*));

void srand(unsigned int seed);
int rand(void);

/* 0x802DF0EC */
size_t mbstowcs(wchar_t* dest, const char* src, size_t len);