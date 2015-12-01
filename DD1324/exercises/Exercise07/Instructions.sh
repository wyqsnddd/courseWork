#!/bin/bash -e

# Exercise07 - Makefiles and multi-file projects in C. 
#
# Write a multi-file program that performs the basic 
# arithmetic operations of a calculator (addition, subtraction, 
# multiplication, division). Write a Makefile to automate the 
# compiling and linking of the project.

# Specifications:
# 1. Write a main function that parses arguments from the 
#    command line to perform simple arithmetic operations 
#    (eg. calculator 4 + 5) and calls external functions to 
#    perform the operation
# 2. In another .c file, write functions to perform the 
#    desired operations. The corresponding header file should 
#    be protected using #ifndef and #define preprocessor macros.
# 3. In another .c file, write a function to print formatted 
#    output of the calculation to the screen.
# 4. Write a  general Makefile to automate the building and 
#    cleaning of the multi-file project.
# 5. Structure the project in different folders (eg. source 
#    files in /src, executables in /bin, etc.).


# compile the code
make clean all

# run the code
cd bin
./calculator 5 + 7

# clean up and exit the exercise
cd ..
echo "End of Exercise07"




