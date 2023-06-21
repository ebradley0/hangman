
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "hangman.h"

int chooseword(hangman_t *hangman)
{
    // Later add size adjustment, for now just including header to clean
    char chosenword[] = "word";
    *hangman->word = *chosenword;
    return 0;
}

int hangman_init(hangman_t *hangman)
{
    hangman->choose_word = chooseword;
    return 0;
}