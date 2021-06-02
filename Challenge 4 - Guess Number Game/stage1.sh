#! /bin/bash
# Ask user for input 
echo "Welcome to the guessing numbers game"
echo "Please enter a number above 1!"
read N

if [ $N -lt 1 ]; then
    echo "Sorry, your number was less than 1, try again!"
    read N
else
    echo "Great lets get started!"
fi


 