#ifndef HANGMAN_H__
#define HANGMAN_H__

typedef struct hangman_s hangman_t;

typedef int (*H_COMMAND)(hangman_t *hangman);

struct hangman_s
{
    char word[20];
    H_COMMAND choose_word;
};

int hangman_init(hangman_t *hangman);

#endif // HANGMAN_H__