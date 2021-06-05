#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Declare Variables
int N = 0;
int ans,guess = 0;

// Stage 2. Create a guess the number game in C
int main()
{
    srand ( time(NULL) );                           // Seed the random number generator using time so it's not the same every time the program is executed.
    printf("Welcome to the C guessing numbers game. Please set the guess limit!\n");
    while (N < 1)                                   // While the players upper limit is less than 1
    {
        scanf("%d",&N);                             // Get the players' upper limit 
        if (N < 1)                                  // If the input is incorrect force a re-try
        {
            printf("Your number is less than 1 - or not a number! Please try again\n");        
        }
        else                                        // If the input is a number, start the game!
        {
            printf("Generating a random number between 1 - %i", N);
            ans = 1+rand() % N;                 // Generate random number between (+1 as it would use 0 in the guess check) and upper limit  
            printf("\nChecking"); sleep(2);
            printf("\nPlease guess the number!\n");
            scanf("%i", &guess);                    // Let the player guess the number
            while ( guess != ans )
            {
                printf("Checking..\n"); sleep(2);
                printf("Please guess again!\n");
                scanf("%i", &guess);
            }
            printf("Checking..\n");
            sleep(2);
            printf("Well Done! You have guessed correctly!\n");
        }
    }
    return 0;
}