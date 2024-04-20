#include <stddef.h>

size_t delete_spaces(char *a)
{
    char *read = a;
    char *write = a;

    size_t pos = 0;

    while (*read == ' ') ++read;

    int flag = 0;
    while (*read != '\0')
    {
        if (*read == ' ') flag = 1;
        else
        {
            if (flag)
            {
                *write = ' ';
                ++write;
                flag = 0;
                ++pos;
            }
            *write = *read;
            ++write;
            ++pos;
        }
        ++read;
    }
    *write = '\0';

    return pos;
}
