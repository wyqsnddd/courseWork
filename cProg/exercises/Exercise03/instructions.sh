#!/bin/bash -e

# Exercise03 - become familiar with the basic operation of char data
# type, strings, arrays of characters. Type the code from "strings.c"
# into your editor.
#
#Specifications:
#1. Define an array, fill each element with chars, and print each element
#2. Print it as a string
#3. Define a similar array, but fill with numeric values instead of characters
#4. Add 32 to each element of the array
#5. Define the array using a string literal
#6. Define the array using a string pointer

# compile the code
gcc strings.c -o strings

# run the code
./strings

# clean up and exit the exercise
rm strings
echo "End of Exercise03"