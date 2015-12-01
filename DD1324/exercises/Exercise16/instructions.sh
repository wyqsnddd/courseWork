#!/bin/bash -e

# Exercise16 - Dynamic memory
# Look at the code in dynamicmemory.c and try to understand 
# how to allocate and manipulate memory on the heap.
 
# Specifications:
# 1. Ask the user to specify the size of an array
# 2. Allocate an array of the requested size on the heap using malloc
# 3. Write a function to display the array
# 4. Write a function to fill the array with monotonically increasing integers (1,2,3,4,…)
# 5. Allocate an array of the requested size on the heap using calloc
# 6. Reduce the size of the array by 2 elements using realloc
# 7. Release the memory on the heap using free



# compile the code (use the -g debugger option)
make all

# run the code
./dynamicmemory

# clean up and exit the exercise
make clean
echo "End of Exercise16"