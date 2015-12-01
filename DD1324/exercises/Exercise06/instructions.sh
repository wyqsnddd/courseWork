#!/bin/bash -e

# Exercise06- Understanding scope in C. 
#
#Specifications:
#1. Read & understand the program scope.c
#2. Predict the output.
#Notes: Block scope – refers to any set of statements enclosed by 
#braces { }. Function scope – refers to a variable visible throughout 
#a function (only goto labels). Global scope – refers to a variable 
#declared outside of a function. Global variables are visible within 
#a file. They can be shared between files using the extern keyword.

# compile the code
gcc scope.c -o scope

# run the code
./scope

# clean up and exit the exercise
rm scope
echo "End of Exercise06"




