#ifndef STR_FUNCTION_H_INCLUDED
#define STR_FUNCTION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int putsi (const char* str);

char* strchri (char* str, int ch);

size_t strleni(const char* str);

char* strcpyi(char* str1, const char* str2);

char* strncpyi(char* str1, const char* str2, size_t num);

char* strcati(char* str1, const char* str2);

char* strncati(char* str1, const char* str2, size_t num);

char* fgetsi(char* str, int num, FILE* stream);

char* strdupi(const char* str);

size_t getlinei(char** lineptr, size_t* n, FILE* stream);

#include "str_function.c"

#endif // STR_FUNCTION_H_INCLUDED
