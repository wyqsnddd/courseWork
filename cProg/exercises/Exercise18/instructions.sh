#!/bin/bash 

# Exercise18 - Debugging with gdb 
#
# Use the program gdb to search the code in testit.c 
# and factorial.c to identify bugs and the causes of 
# segmentation faults.
 
# Steps:
# 1. Compile the code in testit.c
# 2. Run the compiled executable
# 3. Use gdb on the core dump to identify the 
#    cause of the segmentation fault 
# 4. Compile the code in factorial.c
# 5. Run the compiled executable
# 6. Use gdb to identify the cause of the 
#    unexpected behavior (bug)



# compile the code (use the -g debugger option so gdb can
# do its thing)
gcc -c -g testit.c
gcc -g testit.o -o testit

# run the code, it should crash and result in a 
# Segmentation fault (core dumped)
./testit

# In debug mode, the core dump generates a file called core which
# is used for debugging. Use the following command to star the 
# debugger using the core file
gdb testit core

# once in gdb, you can get a list of command by typing "help". To
# run the code and see what caused it to crash, type "run".
#(gdb) run

# You should recieve a message like:
# rogram received signal SIGSEGV, Segmentation fault.
# 0x000000000040054c in main () at testit.c:13
# 13		temp[3]='F';
# This tells you that the command on line 13 in testic.c caused the
# program to crash. This is because we tried to modify a string
# literal, which is immutable. Type "quit" to exit gdb.

# compile the code (use the -g debugger option so gdb can
# do its thing)
gcc -c -g factorial.c
gcc -g factorial.o -o factorial

# run the code, it should give an incorrect answer because
# the source code contains a bug
./factorial

# start gdb on our executable so we can locate the bug
gdb factorial

# at the gdb prompt, type the following to set a breakpoint
# at line 13
#(gdb) break 13
# Breakpoint 1 at 0x400615: file factorial.c, line 13.

# Next, run the program until the breakpoint
#(gdb) run
#Starting program: /home/ksmith/DD1324/Exercise18/factorial 
#Type an integer > 0:
#4
#Breakpoint 1, main () at factorial.c:13
#13		result = factorial(n);

# now step into the function
#(gdb) step
#factorial (n=4) at factorial.c:26
#26		while(n > 0)

# Set gdb to keep watch of variables result and n
#(gdb) watch n
#Hardware watchpoint 2: n
#(gdb) watch result
#Hardware watchpoint 3: result

# Print the value of result, it shows the value is zero
# Aha! This is our bug. We should have initialized result
# to 1, otherwise multiplying it by n will always set the
# result to 0!
#(gdb) print result
#$1 = 0

# Continue running the program
#(gdb) continue
#Continuing.
#Hardware watchpoint 2: n
#Old value = 4
#New value = 3
#factorial (n=3) at factorial.c:26
#26		while(n > 0)

# Print the value of result, it shows the value is zero
#(gdb) print result
#$1 = 0

# Press <Enter> to keep continuing
#Continuing.
#Hardware watchpoint 2: n
#
# Old value = 3
# New value = 2
# factorial (n=2) at factorial.c:26
# 26		while(n > 0)
#(gdb)
# Continuing.
# Hardware watchpoint 2: n
#
# Old value = 2
# New value = 1
# factorial (n=1) at factorial.c:26
# 26		while(n > 0)
# (gdb) 
# Continuing.
# Hardware watchpoint 2: n
#
# Old value = 1
# New value = 0
# factorial (n=0) at factorial.c:26
# 26		while(n > 0)
#(gdb)
# Continuing.
#
# Watchpoint 2 deleted because the program has left the block in
# which its expression is valid.
#
# Watchpoint 3 deleted because the program has left the block in
# which its expression is valid.
# 0x000000000040061f in main () at factorial.c:13
# 13		result = factorial(n);

# Print the value of result, it shows the value is zero
#(gdb) print result
#$1 = 0

# Continue to the end of the program
#(gdb) continue
#Continuing.
#Result 4! = 0
#[Inferior 1 (process 7991) exited normally]

# quit gdb
#(gdb) quit

rm testit testit.o factorial factorial.o
echo "End of Exercise18"