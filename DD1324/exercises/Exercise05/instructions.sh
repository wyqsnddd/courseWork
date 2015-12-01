#!/bin/bash -e

# Exercise05- Write a program that demonstrates the 
# various ways to call functions in C. 

#
# Specifications:
# 1. Write a function that increments an integer using pass by value
# 2. Write a function that swaps the values to two integers 
#    using pass by reference
# 3. Write a function that prints out the contents of an integer 
#    array. Note that it must use pass by reference.
# 4. Write a function that reverses a string (character array). 
#    Note that it must pass by reference.


# compile the code
gcc functions.c -o functions

# run the code
./functions

# clean up and exit the exercise
rm functions
echo "End of Exercise05"