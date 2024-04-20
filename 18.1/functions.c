#include "header.h"
#include <stdlib.h>
#include <string.h>

char** get_words(const char* input, int* word_count) {
    char** words = malloc(100 * sizeof(char*)); // Предполагаем, что не более 100 слов
    char* temp_word; // Для хранения текущего слова (результат strtok)
    char* word; // Для хранения скопированного слова
    int word_index = 0; // Для отслеживания индекса текущего слова в массиве

    char* input_copy = strdup(input);
    temp_word = strtok(input_copy, " ,.!?;\n\r\t"); // Используем пробелы и знаки препинания в качестве разделителей

    while (temp_word != NULL) {
        word = malloc((strlen(temp_word) + 1) * sizeof(char));
        strcpy(word, temp_word);
        words[word_index] = word;
        word_index++;

        temp_word = strtok(NULL, " ,.!?;\n\r\t");
    }

    *word_count = word_index;
    free(input_copy);

    return words;
}
