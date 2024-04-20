#include <stdio.h>
#include <string.h>
#include "header.h"

#define LENGTH 100

int main()
{
    while(1)
    {
        char a[LENGTH];
        printf("Enter a string:\n");
        if (fgets(a, LENGTH, stdin) == NULL)
        {
            printf("Invalid input :(\nExiting!\n");
            return 1;
        }

        *strchr(a, '\n') = '\0';

        int l = trim_spaces(a);
        printf("%d: \"%s\"\n\n", l, a);

        printf("What substring would you like to take?\n");
        int c, d;
        if (scanf("%d%d", &c, &d) != 2)
        {
            printf("Invalid input :(\nExiting!\n");
            return 1;
        }
        getchar();

        char *b = malloc(LENGTH * sizeof(char) + 1);
        printf("It's \"%s\"\n\n", substring(a, b, c, d));
        free(b);
    }

    return 0;
}
