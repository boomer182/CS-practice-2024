#include "header.h"
#include <stdlib.h>
#include <string.h>

struct word* get_words(char* string, int* word_count)
{
    struct word* words = malloc(sizeof(struct word)*100);
    char* word;
    char* temp_word;
    int word_index = 0;

    char* input_copy = strdup(string);
    temp_word = strtok(input_copy, " ,.!?;\n\r\t");

    while (temp_word != NULL)
    {
        word = malloc(sizeof(char)*(strlen(temp_word)+1));
        strcpy(word, temp_word);
        words[word_index].word = word;
        words[word_index].word_len = strlen(word);
        word_index++;

        temp_word = strtok(NULL, " ,.!?;\n\r\t");
    }

    *word_count = word_index;
    free(input_copy);

    return words;
}

int diff_words_count(struct word* words, int word_count)
{
    struct word* read = words;
    struct word* write = words;

    int counter = 0;

    while (read < words + word_count)
    {
        struct word* temp = words;
        int flag = 0;

        while (temp < write)
        {
            if (strcmp((*temp).word, (*read).word) == 0)
            {
                flag = 1;
                counter++;
                break;
            }
            temp++;
        }
        if (!flag)
        {
            strcpy((*write).word, (*read).word);
            write++;
        }
        read++;
    }

    return word_count - counter;
}

void occurrence_frequency_computing(struct word* initial_words, struct word* real_words, int initial_word_count, int real_word_count)
{
    int word_occurrence = 0;

    if (initial_word_count == real_word_count)
    {
        for (int i = 0; i < real_word_count; ++i)
        {
            real_words[i].occurrence = 1;
            real_words[i].frequency = (1.0 / (double)real_word_count) * 100;
        }
    }
    else
    {
        for (int i = 0; i < real_word_count; ++i)
        {
            for (int j = 0; j < initial_word_count; ++j)
            {
                if (strcmp(real_words[i].word, initial_words[j].word) == 0) word_occurrence++;
            }

            real_words[i].occurrence = word_occurrence;
            real_words[i].frequency = ((double)word_occurrence / real_word_count) * 100;
            word_occurrence = 0;
        }
    }
}

int compare_words(char* a, char* b)
{
    struct word* word1 = (struct word*)a;
    struct word* word2 = (struct word*)b;
    return strcmp(word1->word, word2->word);
}

void sorted_by_alphabet(struct word* words, int word_count)
{
    qsort(words, word_count, sizeof(struct word), compare_words);
}

int compare_word_lengths(char* a, char* b)
{
    struct word* word1 = (struct word*)a;
    struct word* word2 = (struct word*)b;
    return word1->word_len - word2->word_len;
}

void sorted_by_length(struct word* words, int word_count)
{
    qsort(words, word_count, sizeof(struct word), compare_word_lengths);
}
