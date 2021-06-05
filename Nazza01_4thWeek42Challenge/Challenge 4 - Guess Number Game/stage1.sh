#!/bin/bash
# Stage 1. Create a guess the number game in bash
B='####################'            # Fancy Bar :o
ellip='...'
declare -i N=-1                     # init Upper limit (N) so while loop works :P

echo "Welcome to the !/bin/bash guessing numbers game. Please set the guess limit!"

# While N is less than 1, get input and evaluate
while [ $N -lt 1 ]; do
    read N
    # If the input is incorrect, force a re-try
    if [ $N -lt 1 ]; then
        echo "Your number is less than 1 - or not a number! Please try again"
    # Otherwise, generate a number and get the player to guess!
    else

        echo "Lets generate a random number between 1 - " $N
        # Generate a number and assign it to a variable for comparison!
        ans=$((1 + $RANDOM % $N))

        # "Progress bar"
        for i in {1..20}; do
            echo -ne "\r${B:0:$i}"
            sleep .1
        done
        # Let echo interpret the new line thingy?(can't remember the name right now lol)
        echo -e "\nPlease guess the number!"
        read guess
        
        while [[ $guess != $ans ]]; do   
            # "ellipses "
            for i in {1..3}; do
                echo -ne " Checking \r${ellip:1:$i}"
                sleep .5
            done
            echo "Please guess again!"
            sleep 1
            read guess
        done
        for i in {1..3}; do
            echo -ne " Checking \r${ellip:1:$i}"
            sleep .5
        done
        echo "Well Done! You have guessed correctly!"
    fi
done