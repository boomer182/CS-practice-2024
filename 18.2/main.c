#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "header.h"

int main()
{
    setlocale(LC_CTYPE, "Russian");

    char string[1000];
    printf("Введите строку: ");
    fgets(string, sizeof(string), stdin);

    int word_count = 0;
    struct word* words = get_words(string, &word_count);
    struct word* inital_words = get_words(string, &word_count);

    for (int i = 0; i < word_count; ++i)
    {
        puts(words[i].word);
    }

    printf("\n");

    int real_word_count = diff_words_count(words, word_count);

    printf("%d", real_word_count);

    printf("\n\n");

    occurrence_frequency_computing(inital_words, words, word_count, real_word_count);

    printf("Список различных слов: \n");
    for (int i = 0; i < real_word_count; ++i)
    {
        puts(words[i].word);
        printf("Длина = %d, встречаемость = %d, частота появления = %lf\n", words[i].word_len, words[i].occurrence, words[i].frequency);
    }

    sorted_by_alphabet(words, real_word_count);

    printf("\n\n");

    printf("Сортировка по алфавиту: \n");
    for (int i = 0; i < real_word_count; ++i)
    {
        puts(words[i].word);
    }

    sorted_by_length(words, real_word_count);

    printf("\n\n");

    printf("Сортировка по длине: \n");
    for (int i = 0; i < real_word_count; ++i)
    {
        puts(words[i].word);
    }

    free(words);
    free(inital_words);

    return 0;
}
