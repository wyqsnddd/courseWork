#!/bin/bash -e

# Exercise12 - Pointer arithmetic
#
# Look at the code in arithmetic.c and try to understand 
# the basics of pointer arithmetic.
 
# Specifications:
# 1. Create an integer and a pointer to the integer
# 2. Display the memory, size, and address of the integer
# 3. Create a char* pointer and use typecasting to point it at the integer
# 4. Display the memory address and size of each pointer
# 5. Increment each pointer and print the results


# compile the code (use the -g debugger option)
make all

# run the code
./arithmetic


# clean up and exit the exercise
make clean
echo "End of Exercise12"