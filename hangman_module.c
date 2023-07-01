
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hangman.h"

int chooseword(hangman_t *hangman)
{
    // Later add size adjustment, for now just including header to clean
    char chosenword[50];
    srand(time(NULL));
    int number_slot = rand() % 50;
    printf("CHOSEN WORD = %s\n", chosenword);
    char *p_chosenword = chosenword;
    // *hangman->word = *word_list[number_slot]; // Assigns chosen word to hangman struct
    return 0;
}

int hangman_init(hangman_t *hangman)
{
    hangman->choose_word = chooseword;
    return 0;
}