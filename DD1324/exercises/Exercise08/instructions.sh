#!/bin/bash -e

# Exercise10 - Handling command-line parameters in C. 
#
# Write a program that accepts parameter input from 
# the command line. It should read the arguments from 
# the command line and print them out to the console. 
#
# Specifications:
# 1. The program should print out how many arguments 
#    were passed
# 2. The program should print out each parameter 
#    string in order, preceded by the pointer 
#    reference argv[x]
# 3. If one of the arguments is “-e” the program 
#    should print “eureka!” to the console



# compile the code
make clean all

# run the code with some test arguments
./print_arguments -a -f "a string" -e -d

# clean up and exit the exercise
cd ..
echo "End of Exercise08"