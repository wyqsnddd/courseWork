#!/bin/bash -e

# Type the file "hello_world.c" into your editor and save it.

# Compile the code with this instruction. This will produce
# an executable with the name specified after -o
gcc hello_world.c -o hello_world

# Run the executable, what does it do?
./hello_world

# Type this command to see the "return code" of the program. 
# The value should be 0 for success, it tells the OS that
# the code ran and exited cleanly.
echo $?

# Comment out the return statement (line 8) and run the code again.
# What does the return code indicate? 
echo $?
# It is the return code of the last instruction, in this case 
# the printf() telling you that it wrote 13 characters. If the OS
# sees this return code it will assume the program did not exit
# correctly.


# Compile again. This time we will save all the intermediate 
# files. List the files in the folder to see what you have produced. 
# We do not specify an output file, so gcc names the executable to 
# "a.out" by default
rm hello_world
gcc -save-temps hello_world.c
ls -alF

# "hello_world.i" is the preprocessed output from hello_world.c
# The preprocessor addes include-files, conditional 
# compilation instructions and macros. It does this using text 
# substitution on special preprocessor directives denoted by 
# #. (eg. #include <stdio.h>). Whenever it finds these 
# directives, it substitutes tokenized strings for others. Open
# at "hello_world.i" and find your code from "hello_world.c"
gedit hello_world.i

# "hello_world.s" contains the assembly instructions
# generated from "hello_world.c". The assembler is invoked by
# the compiler to generate object files from the assembly
# file, which are later linked by the linker. Have a look at
# what is in hello_world.s. Can you find the instruction "puts"
# corresponding to printf?
gedit hello_world.s

# "hello_world.o" is an object file. An object file is the 
# real output from the compilation phase. It's mostly 
# machine code, but has info that allows a linker to see 
# what symbols are in it as well as symbols it requires 
# in order to work. ("symbols" are basically names of 
# global objects, functions, etc.). A linker takes all 
# these object files and combines them to form one executable. 
# Most compilers (including GCC) will link for you. Have a 
# look at what's in hello_world.o using "readelf"
file hello_world.o
readelf -s hello_world.o
# The object file contains the function main() and a function
# puts() (put string).

# Remove all the intermediate files
rm a.out hello_world.i hello_world.o hello_world.s

# Instead of producing an executable, use the -c flag to
# produce compiled object files WITHOUT ANY LINKING. List 
# the files in the folder and see what it produced.
gcc -c hello_world.c
ls -alF

# Now compile the executable again and list the folder contents
gcc hello_world.c -o hello_world
ls -alF

# Notice the difference in the file size between "hello_world"
# and "hello_world.o". What is causing this? To investigate,
# use the Linux command "nm filename" to list the symbols in 
# an objectfile or executable
nm hello_world.o
nm hello_world
# You can see that "hello_world.o" has only 2 entries. 
# T (main is in the text/code) and U (puts is undefined). 
# In the executable "hello_world" we see many more 
# instructions, including calls to the kernel (denoted by 
# "__". We can see that the undefined function puts is now 
# pointing to "puts@@GLIBC_2.2.5", which is a library 
# resolved when the program is run. This is called a 
# "Dynamic Link".

# Now let's remove the executable and create a dynamic-linked
# executable on our own.
rm hello_world
gcc hello_world.o -o hello_world
# We were able to create the exact same executable from an
# object file using the linker, without any source code!

# We can also make a "Static Link". When your program is 
# linked against a static library, the machine code of 
# external functions used in your program is copied into 
# the executable. In this case, we will link the standard C
# library to "hello_world_static"
gcc hello_world.o -o hello_world_static --static -lc
ls -alF

# We can view a list of the dynamic dependencies associated
# to executable using "ldd". These are the shared libraries
# required to run the program.
ldd hello_world
ldd hello_world_static
# We receive the message "not a dynamic executable" for the
# second command, indicating that all the libraries are 
# contained in the file. However, the file size is much larger.


# clean up and exit the exercise
rm hello_world hello_world.o hello_world_static
echo "End of Exercise01"