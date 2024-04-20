#include "header.h"
#include <stdlib.h>
#include <string.h>

char** get_words(const char* input, int* word_count) {
    char** words = malloc(100 * sizeof(char*)); // ������������, ��� �� ����� 100 ����
    char* temp_word; // ��� �������� �������� ����� (��������� strtok)
    char* word; // ��� �������� �������������� �����
    int word_index = 0; // ��� ������������ ������� �������� ����� � �������

    char* input_copy = strdup(input);
    temp_word = strtok(input_copy, " ,.!?;\n\r\t"); // ���������� ������� � ����� ���������� � �������� ������������

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
