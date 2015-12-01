#!/bin/bash -e

# Exercise11 - Pointer basics
#
# Exercise11
# Look at the code in pointers.c and try to understand the 
# basics of declaring, accessing, and dereferencing pointers.
 
#Steps:
#1. Compile the code in pointers.c
#2. Read through the code and the comments
#3. Understand how to declare pointers
#4. Understand how to assign an address to a pointer
#5. Understand how to dereference a pointer
#6. Understand how to change the value of a pointer



# compile the code (use the -g debugger option)
make all

# run the code
./pointers


# clean up and exit the exercise
make clean
echo "End of Exercise11"