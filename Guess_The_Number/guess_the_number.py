#! /usr/bin/env python3

import sys
from random import *

#    If an argument was passed on the command line, set max to it's value.    #

if len(sys.argv) > 1:
    max = int(sys.argv[1]) # Converts the parameter (String) to an integer.
else:
    max = 100              # Else, default value is 100.


#    -------- Generates a random number in the range [0 - max]. ----------    #

n = randrange(max+1)

#    ------------------------ Start the game. ----------------------------    #

print("Guess the number! Range is: [0 - " + str(max) + "]")

while True:
    g = int(input("Imput number: "))
    if   g > n:
        print('Lower! Try again!\n')
    elif g < n:
        print('Higher! Try again!\n')
    else:
        break

#    --------------- End game: Terminates the program. -------------------    #

print('Found!')
