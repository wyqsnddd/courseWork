#!/bin/bash -e

# The Python code "million.py" adds two random integers
# in a loop 1,000,000 times. Type this into your editor,
# save the file, and use the "time" command to summarize
# the time it took for the program to run
time python million.py

# Type the program "million.c" into your editor, save it
# and compile "million.c". This is the simple C 
# implementation of the same code
gcc million.c -o million

# Run the compiled C code
time ./million

# How much faster is C than Python on your computer?

# clean up and exit the exercise
rm million million.o
echo "End of Exercise01"