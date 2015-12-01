#!/bin/bash -e

# Exercise15 - Multi-dimensional arrays
# Look at the code in multidimensionalarrays.c and try 
# to understand the how pointers and arrays work.
 
# Specifications:
# 1. Create a multidimensional integer array A[2][3]
# 2. Use 5 different statements to print the address of A[0][0]
# 3. Use 5 different statements to print the address of A[1][0]
# 4. Use 3 different statements to print the address of A[1][2]
# 5. Use 2 different statements to print the value of A[0][1]
# 6. Write a function that takes a 2-dimensional array as an
#    argument.
# 7. Use 3 different for loops to print the contents of A



# compile the code (use the -g debugger option)
make all

# run the code
./multidimensionalarrays


# clean up and exit the exercise
make clean
echo "End of Exercise15"