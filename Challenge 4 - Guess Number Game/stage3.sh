#!/bin/bash

# Run stage1.sh - the bash script
./stage1.sh


# Check if the C program will compile and throw an error if it doensnt run
if gcc stage2.c -o stage2; then
    echo "Thankyou :)"
else
    echo "Failed to compile! :("
fi