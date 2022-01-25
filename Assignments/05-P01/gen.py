#!/usr/local/bin/python3
"""I used this python code to generate the input files for your programs. 

"""
import random
from random import randint


def randchoice(p):
    if p == "Push":
        return (random.randint(0, 100000000)) * 2
    else:
        return (random.randint(0, 100000000)) * 2 + 1


f = open(
    "/Users/griffin/Dropbox/_Courses/3013-Algorithms/.trunk/ArrayBasedStackCode/nums_test3.dat",
    "w",
)

# Generate a list with 50000 "Push" and 50000 "Pop" values in it.
choices = ["Push"] * 50000 + ["Pop"] * 60000


# Shuffle does what it says. It shuffles the items in a list
# as if they were cards in a deck. So all the "Push" and "Pops"
# are now all mixed up.
random.shuffle(choices)


for p in choices:
    r = randchoice(p)
    f.write(f"{r}\n")
