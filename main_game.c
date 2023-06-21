#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hangman.h"
enum things
{
    TRUE,
    FALSE,
    CORRECT_LETTER,
    CORRECT_WORD,
    INCORRECT_LETTER,
    INCORRECT_WORD,
    VALID_INPUT,
    INVALID
};
char INCORRECT_GUESSES[100];       // Stores guessed letters that were incorrect
char chosen[20] = "word";          // The word that the user has to guess
char input[100];                   // Checks users guess
int lives = 6;                     // Lives the user has
char INCORRECT_GUESS_PASS = FALSE; // Checks if the user has guessed incorrectly
char HINT_DISPLAY[20];             // Stores correct guesses for use in hint display
int main(int argc, int arg)

{

    hangman_t hangman_module;
    int err = hangman_init(&hangman_module);

    if (err)
    {
        printf("AN ERROR HAS OCCURED\n\n");
        exit(-1);
    }

    /*
    Here We prep the game, choosing the word
    */

    /*

       err = hangman_module.choose_word(&hangman_module);
       char chosen[50];
       strcpy(chosen, hangman_module.word);
       printf("CHOSEN WORD: %s\n", chosen);

      copied out till can be fixed







       */

    // Start of the game itself
    printf("Welcome to hangman\n");
    printf("Please enter a letter: ");

    while (lives > 0) // Looping to check for potential answers
    {
        printf("=============================================\n\n"); // Used to make the game look nicer

        printf("The word is: ");

        for (int i = 0; chosen[i]; i++)
        {
            if (HINT_DISPLAY[i] == chosen[i] && chosen[i] != '\0')
            {
                printf("%c ", HINT_DISPLAY[i]); // Properly guessed letters
            }
            else
            {
                printf("_ "); // Prints blank spot if the letter has not been guessed yet
            }
        }

        INCORRECT_GUESS_PASS = FALSE;
        printf("You have %d lives left\n", lives);

        printf("Incorrect guesses: %s\n", INCORRECT_GUESSES);

        printf("Please enter a letter: ");

        scanf(" %s", input); // Detecting input from user

        int length = strlen(input);

        if (length > 1 && input != "guess")
        {
            printf("Whoops! One letter at a time!\n");
            continue;
        }
        if (input != "guess")
        {
            printf("YOURE GUESSING\n");
        }

        for (int i = 0; chosen[i] != '\0'; i++)
        {
            if (*input == chosen[i]) // If the user guesses correctly --------------- WHEN COMPARING 2 ARRAYS, IF A SLOT IS NOT SPECIFIED A POINTER MUST BE INCLUDED IN ORDER TO PROPERLY REFERENCE IT
            {
                HINT_DISPLAY[i] = *input; // Storing the correct values, also used in hint display
                printf("YOU GUESSED CORRECTLY!\n");
                INCORRECT_GUESS_PASS = TRUE;
            }
        }

        if (INCORRECT_GUESS_PASS == FALSE)
        {
            if (strchr(INCORRECT_GUESSES, *input)) // Once again, a pointer is needed as C needs pointers when referencing non-specific Arrays
            {
                printf("You've already guessed that letter!\n");
                continue;
            }
            else
            {

                lives--;
                strcpy(INCORRECT_GUESSES, input);
            }
        }
        if (strcmp(HINT_DISPLAY, chosen) == 0)
        {
            printf("You've guessed the word! Congratulations!\n");
            exit(1);
        }
    }

    if (lives == 0)
    {
        printf("You have no lives left! If you'd like to try again reactive the file\n");
        exit(1);
    }
    return 0;
}
