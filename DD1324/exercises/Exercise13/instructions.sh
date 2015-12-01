#!/bin/bash -e

# Exercise13 - Pointers to pointers
# Look at the code in ptrptr.c and try to understand 
# the how chaining pointers works.
 
# Specifications:
# 1. Create an integer and a pointer to the integer
# 2. Create a pointer to a pointer to an integer
# 3. Create a pointer to a pointer to a pointer to an integer
# 4. De-reference the pointers you created above and print their values

# compile the code (use the -g debugger option)
make all

# run the code
./ptrptr


# clean up and exit the exercise
make clean
echo "End of Exercise13"