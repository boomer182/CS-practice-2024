#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdlib.h>

size_t trim_spaces(char *a);
long max(long a, long b);
long min(long a, long b);
char* substring(const char *src, char* dst, long start, long new_length);

#endif // HEADER_H_INCLUDED
