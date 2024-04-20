#include <stdio.h>
#include <locale.h>
#include "header.h"

int main() {
    setlocale(LC_CTYPE, "Russian");

    char input[1000];
    printf("¬ведите строку: ");
    fgets(input, sizeof(input), stdin);

    int word_count = 0;
    char** words = get_words(input, &word_count);

    printf("–езультат:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s\n", words[i]);
        free(words[i]);
    }

    free(words);

    return 0;
}
