#!/bin/bash

# Run stage1.sh - the bash script
./stage1.sh
figlet "You Win!!"

# Check if the C program will compile and throw an error if it doensnt run
if gcc stage2.c -o stage2.out; then
    ./stage2.out
    figlet "You win!! Congratulations :D"
else
    echo "Sorry, something went wrong. Please contact me!"
fi