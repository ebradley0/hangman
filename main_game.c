#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hangman.h"
#include "words.h"
enum things
{
    TRUE,
    FALSE,
};
char INCORRECT_GUESSES[100];       // Stores guessed letters that were incorrect
                                   // The word that the user has to guess
char input[100];                   // Checks users guess
int lives;                         // Lives the user has
int slot;                          // Used for slotting incorrect guesses into the array and avoid overwrite of previous guesses
char INCORRECT_GUESS_PASS = FALSE; // Checks if the user has guessed incorrectly
char HINT_DISPLAY[20];
char *chosen = NULL; // Stores correct guesses for use in hint display

int word_generator()
{
    srand(time(NULL));
    int number_slot = rand() % 50;             // Chooses slot of words array
    int size = strlen(word_list[number_slot]); // Finds the size of the chosen word
    printf("Size of chosen word = %d\n", size);
    chosen = (char *)malloc(size);          // Ad;justs the memory to make enough room for the chosen word
    strcpy(chosen, word_list[number_slot]); // Copies the chosen word into the chosen array
    return 0;
}

int main(int argc, int arg)

{
    word_generator();
    lives = strlen(chosen);
    // Start of the game itself
    printf("Welcome to hangman\n");

    while (lives > 0) // Looping to check for potential answers
    {
        printf("=============================================\n\n\n\n"); // Used to make the game look nicer

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

        // print the list of incorrect guesses array
        printf("Incorrect guesses: %s\n", INCORRECT_GUESSES);

        printf("Please enter a letter: ");

        scanf(" %s", input); // Detecting input from user

        int length = strlen(input);

        if (length > 1 && input != "guess")
        {
            printf("Whoops! One letter at a time!\n");
            continue;
        }
        if (argc > 1 && input != "guess")
        {
            printf("Whoops! One letter at a time!\n");
            continue;
        }
        if (input == "guess")
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
                INCORRECT_GUESSES[slot] = *input; // Slots incorrect guess
                slot++;                           // Moves slot to next available slot
            }
        }
        if (strcmp(HINT_DISPLAY, chosen) == 0)
        {
            printf("You've guessed the word! Congratulations!\n");
            free(chosen);
            exit(1);
        }
        printf("\n\n\n");
    }

    if (lives == 0)
    {
        printf("You have no lives left! If you'd like to try again reactive the file\n");
        printf("The word was: %s\n", chosen);
        free(chosen);
        exit(1);
    }
    return 0;
}
