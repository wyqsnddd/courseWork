#!/bin/bash -e

# Exercise02 - Write a simple program that simulates 
# jumping from an airplane without a parachute. 
#
# Specifications:
# 1. prompt the user for an initial height 
# 2. print the height (m) of the jumper every second
# 3. define a function fallOneSec which updates the jumpers 
#    speed and height every second
# 4. define a function hitTheground to stop the program when 
#    the jumper hits the ground and print “splat!”
# 5. take into account acceleration from gravity and terminal 
#    velocity from wind resistance
#
# The goal of this exercise is to become familiar with the basic 
# organization of a C program. Inspect the code, complete the 
# missing sections, then compile it.
gcc falling.c -o falling

# run the code
./falling

# how long does it take for you to free fall from 1000m?

# clean up and exit the exercise
rm falling
echo "End of Exercise02"