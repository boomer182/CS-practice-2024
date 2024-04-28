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
        printf("\n%d: \"%s\"\n\n", l, a);

        printf("Examples of take substing: \n\n");
        printf("\t1) Start pos and substring length more than zero: start pos = 4, substring length = 6\n\n");

        char *b = malloc(LENGTH * sizeof(char) + 1);

        printf("\t \"%s\"\n\n", substring(a, b, 4, 6));

        printf("\t2) Start pos and substring length less than zero: start pos = -3, substring length = -4\n\n");
        printf("\t \"%s\"\n\n", substring(a, b, -3, -4));

        printf("\t3) Start pos less than zero, substring length more than zero: start pos = -3, substring length = 5\n\n");
        printf("\t \"%s\"\n\n", substring(a, b, -3, 5));

        printf("\t4) Start pos more than zero, substring length less than zero: start pos = 5, substring length = -6\n\n");
        printf("\t \"%s\"\n\n", substring(a, b, 5, -6));

        printf("What substring would you like to take?\n");
        int c, d;
        if (scanf("%d%d", &c, &d) != 2)
        {
            printf("Invalid input :(\nExiting!\n");
            return 1;
        }
        getchar();

        realloc(b, LENGTH * sizeof(char) + 1);
        printf("It's \"%s\"\n\n", substring(a, b, c, d));
        free(b);
    }

    return 0;
}
