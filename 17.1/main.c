#include <stdio.h>
#include <stdlib.h>
#include "header.h"

#define LENGTH 100

int main()
{
    while (1)
    {
        char str[LENGTH];
        if (fgets(str, LENGTH, stdin) == NULL)
        {
            printf("Invalid input :(\nExiting!\n");
            return 1;
        }

        delete_spaces(str);

        puts(str);
    }

    return 0;
}
