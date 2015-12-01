#!/bin/bash -e

# Exercise09 - File writing in C 
#
# Write a program that opens a file and writes 
# some data to the file. The name of the file 
# should be an argument of the program given 
# at the command line.
 
# Specifications:
# 1. The program should use main(int argc, char* argv[]) 
#    to capture command-line arguments.
# 2. The program should use stdio.h functions to open a 
#    file for writing (fopen), write some data to the file 
#    using fprintf, and close the file before exiting.




# compile the code
make clean all

# run the code with a filename argument
./file_writer  myfile.txt

# see what we wrote in myfile.txt
more myfile.txt

# clean up and exit the exercise
echo "End of Exercise09"