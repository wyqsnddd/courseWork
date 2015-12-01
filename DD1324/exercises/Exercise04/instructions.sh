#!/bin/bash -e

# Exercise04 - become familiar with the basic types in C.
#
#Specifications:
#For each basic type in C, do the following
#1. Assign and print a variable of that type
#2. Determine and print the type's size in your computer's memory
#3. Determine and print the range of the type

# compile the code
gcc types.c -o types

# run the code
./types

# clean up and exit the exercise
rm types
echo "End of Exercise04"