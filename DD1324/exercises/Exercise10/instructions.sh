#!/bin/bash -e

# Exercise10 - Reading a file in C. 
#
# Write a program that opens the file "constants.txt“, 
# reads the contents of the file, and displays the 
# contents to the screen.
# 
# Specifications:
# 1. First, the program should read the file line-by-line 
#    in a formatted way using fscanf.
# 2. Next, the program should read the file in an 
#    unformatted manner, loading the whole file contents 
#    into a string. To do this, you can use fread,
#    ftell, fseek.


# compile the code
make clean all

# run the code
./file_reader

# clean up and exit the exercise
echo "End of Exercise10"