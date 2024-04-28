#include <string.h>
#include "header.h"

long max(long a, long b)
{
    return a > b ? a : b;
}

long min(long a, long b)
{
    return a < b ? a : b;
}

char* substring(const char *src, char* dst, long start, long new_length)
{
    long length = 0;
    while (*(src + length) != '\0')
        ++length;

    if (start < 0)
        start = max(length + start, 0);

    if ((start >= length && start + new_length >= length) || (start == 0 && new_length <= 0))
    {
        dst = "";
        return dst;
    }

    long end = min(length, max(start, min(start + new_length, length)));
    start = max(0, min(start + new_length, start));

    if (start < 0 || end < 0)
    {
        dst = "";
        return dst;
    }

    new_length = end - start;

    memcpy(dst, src + start, new_length + 1);
    dst[new_length] = '\0';

    return dst;
}

size_t trim_spaces(char *a)
{
    char *reading = a, *writing = a;
    size_t pos = 0;

    while (*reading == ' ')
        ++reading;

    int previous_char_was_space = 0;
    while (*reading != '\0')
    {
        if (*reading == ' ')
            previous_char_was_space = 1;
        else
        {
            if (previous_char_was_space)
            {
                *writing = ' ';
                ++writing;
                previous_char_was_space = 0;
                ++pos;
            }
            *writing = *reading;
            ++writing;
            ++pos;
        }
        ++reading;
    }
    *writing = '\0';
    return pos;
}

