#!/bin/bash -e

# Exercise17 - Memory leak detection in C 
#
# Use the program valgrind to check the code in 
# memoryproblems.c for potential memory leaks and 
# other memory management proglems.
# 
# Steps:
# 1. Compile the code in memoryproblems.c
# 2. Identify the two memory leaks in the code
# 3. Identify the attempt to access an array out-of-bounds
# 4. Identify the attempt to perform operations on an initialized variable



# compile the code (use the -g debugger option so
# that valgrind can provide line numbers)
gcc -c -g memoryproblems.c
gcc -g memoryproblems.o -o memoryproblems

# run valgrind on your code
valgrind --tool=memcheck --leak-check=yes ./memoryproblems

# identify the first memory leaks (line 8, line 13)
#==7943== 100 bytes in 1 blocks are definitely lost in loss record 2 of 2
#==7943==    at 0x4C2AC3D: malloc (vg_replace_malloc.c:299)
#==7943==    by 0x400614: main (memoryproblems.c:8)
#==7943== 10 bytes in 1 blocks are definitely lost in loss record 1 of 2
#==7943==    at 0x4C2AC3D: malloc (vg_replace_malloc.c:299)
#==7943==    by 0x400622: main (memoryproblems.c:13)

# identify the attempt to access memory out-of-bounds (line 14)
#==7943== Invalid write of size 1
#==7943==    at 0x40062F: main (memoryproblems.c:14)
#==7943==  Address 0x51fc0fb is 1 bytes after a block of size 10 alloc'd
#==7943==    at 0x4C2AC3D: malloc (vg_replace_malloc.c:299)
#==7943==    by 0x400622: main (memoryproblems.c:13)

# identify the attempt to perform operations
# on an unitialized variable (line 19)
#==7943== Conditional jump or move depends on uninitialised value(s)
#==7943==    at 0x400636: main (memoryproblems.c:19)

# also notice that there is no error for
# line 27, which attempt to access an arry
# on the stack out-of-bounds


# clean up and exit the exercise
rm memoryproblems memoryproblems.o
echo "End of Exercise17"