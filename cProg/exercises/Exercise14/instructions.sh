#!/bin/bash -e

# Exercise14 - Pointers and arrays
# Look at the code in arrays.c and try to understand the 
# how pointers and arrays work.
 
# Specifications:
# 1. Create an integer array
# 2. Create a pointer to an integer array
# 3. Print the addresses of each
# 4. Print the values of each (by de-referencing)
# 5. Loop through the array and print each address and value 
#    using the equivalent methods in the previous slide
# 6. Call a function using an array as an argument. Investigate
#    how functions call arrays by reference


# compile the code (use the -g debugger option)
make all

# run the code
./arrays


# clean up and exit the exercise
make clean
echo "End of Exercise14"