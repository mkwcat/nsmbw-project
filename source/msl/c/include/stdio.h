#pragma once

EXTERN_C_START

// Type Definitions
// ^^^^^^

typedef struct _FILE FILE;
#include "msl/c/internal/size_t.h"
typedef size_t fpos_t;

// Macro Constants
// ^^^^^^

#define __STDC_VERSION_STDIO_H__ 202311L

#include "msl/c/internal/NULL.h"

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2
#define _IONBF 0
#define _IOLBF 1
#define _IOFBF 2
#define BUFSIZ 0x400
#define FOPEN_MAX 1024
#define FILENAME_MAX 1024
#define L_tmpnam 21 // (sizeof ".\\tmp" + sizeof "-2147483647" + sizeof ".tmp" - 2)
#define TMP_MAX 2147483647
#define EOF -1
#define _PRINTF_NAN_LEN_MAX 4

extern FILE __stdin;
extern FILE __stdout;
extern FILE __stderr;

#define stdin (&__stdin)
#define stdout (&__stdout)
#define stderr (&__stderr)

// Functions
// ^^^^^^

int remove(const char* filename);
int rename(const char* oldname, const char* newname);
FILE* tmpfile(void);
char* tmpnam(char* s);
/* 0x802DEC0C */ int fclose(FILE* stream);
/* 0x802DECC8 */ int fflush(FILE* stream);
FILE* fopen(const char* restrict filename, const char* restrict mode);
FILE* freopen(const char* restrict filename, const char* restrict mode, FILE* restrict stream);
void setbuf(FILE* restrict stream, char* restrict buf);
int setvbuf(FILE* restrict stream, char* restrict buf, int mode, size_t size);
[[gnu::format(printf, 1, 2)]]
int printf(const char* restrict format, ...);
[[gnu::format(scanf, 1, 2)]]
int scanf(const char* restrict format, ...);
[[gnu::format(printf, 3, 4)]]
/* 0x802E19D8 */ int snprintf(char* restrict s, size_t n, const char* restrict format, ...);
[[gnu::format(printf, 2, 3)]]
/* 0x802E1ACC */ int sprintf(char* restrict s, const char* restrict format, ...);
[[gnu::format(scanf, 2, 3)]]
int sscanf(const char* restrict s, const char* restrict format, ...);
[[gnu::format(printf, 2, 3)]]
int vfprintf(FILE* restrict stream, const char* restrict format, __builtin_va_list arg);
[[gnu::format(scanf, 2, 3)]]
int vfscanf(FILE* restrict stream, const char* restrict format, __builtin_va_list arg);
[[gnu::format(printf, 1, 2)]]
/* 0x802E1850 */ int vprintf(const char* restrict format, __builtin_va_list arg);
[[gnu::format(scanf, 1, 2)]]
int vscanf(const char* restrict format, __builtin_va_list arg);
[[gnu::format(printf, 3, 4)]]
/* 0x802E18CC */ int
vsnprintf(char* restrict s, size_t n, const char* restrict format, __builtin_va_list arg);
[[gnu::format(printf, 2, 3)]]
/* 0x802E1954 */ int vsprintf(char* restrict s, const char* restrict format, __builtin_va_list arg);
[[gnu::format(scanf, 2, 3)]]
int vsscanf(const char* restrict s, const char* restrict format, __builtin_va_list arg);
int fgetc(FILE* stream);
char* fgets(char* restrict s, int n, FILE* restrict stream);
int fputc(int c, FILE* stream);
int fputs(const char* restrict s, FILE* restrict stream);
int getc(FILE* stream);
int getchar(void);
int putc(int c, FILE* stream);
int putchar(int c);
int puts(const char* s);
int ungetc(int c, FILE* stream);
size_t fread(void* restrict ptr, size_t size, size_t nmemb, FILE* restrict stream);
size_t fwrite(const void* restrict ptr, size_t size, size_t nmemb, FILE* restrict stream);
int fgetpos(FILE* restrict stream, fpos_t* restrict pos);
int fseek(FILE* stream, long int offset, int whence);
int fsetpos(FILE* stream, const fpos_t* pos);
long int ftell(FILE* stream);
void rewind(FILE* stream);
void clearerr(FILE* stream);
int feof(FILE* stream);
int ferror(FILE* stream);
void perror(const char* s);
[[gnu::format(printf, 2, 3)]]
int fprintf(FILE* restrict stream, const char* restrict format, ...);
[[gnu::format(scanf, 2, 3)]]
int fscanf(FILE* restrict stream, const char* restrict format, ...);

EXTERN_C_END
