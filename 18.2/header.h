#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

struct word* get_words(char* string, int* word_count);

int diff_words_count(struct word* words, int word_count);
int compare_words(char* a, char* b);
int compare_word_lengths(char* a, char* b);

void occurrence_frequency_computing(struct word* initial_words,
        struct word* real_words, int initial_word_count, int real_word_count);
void sorted_by_alphabet(struct word* words, int word_count);
void sorted_by_length(struct word* words, int word_count);

struct word
{
    char* word;
    int word_len;
    int occurrence;
    double frequency;
};

#endif // HEADER_H_INCLUDED
