#include <stddef.h>
#include <string.h>

size_t delete_spaces(char *a)
{
    if (a[strlen(a)-1] == '\n') a[strlen(a)-1] = '\0';

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
