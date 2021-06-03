// Stage 2. Create a guess the number game in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Declare Variables
char Bar[20] = "####################";
char ellip[3] = "...";
int N = 0;
int ans,guess = 0;

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
            printf("Lets generate a random number between 1 - %i\n", N);
            int ans = 1+rand() % N;                   // Generate random number between (+1 as it would use 0 in the guess check) and upper limit  

            for (int i =0; i < 19; i++)
            {
                printf("\rGenerating... %d", Bar[i]);
                sleep(1);
                fflush(stdout);                       // Flush the standard output as it's being buffered and stored
            }
            /*
            for (int i = 0; i < 19; i++)              // Progress Bar
            {
                printf("\r%c", Bar[i]);
                fflush(stdout);
                sleep(.1);
            }
            */
            printf("\nPlease guess the number!\n");
            scanf("%i", &guess);                      // Let the player guess the number
            
            while ( guess != ans )
            {
                for (int i = 0; i < 2; i++)
                {
                    printf("Checking \r%c", ellip[i]);
                    sleep(.5);
                }
                printf("Please guess again!\n");
                sleep(1);
                scanf("%i", &guess);
            }
            for (int i = 0; i <2; i++)
            {
                printf("Checking \r%c", ellip[i]);
                sleep(0.5);
            }
            printf("Well Done! You have guessed correctly!");
        }
    }
    return 0;
}