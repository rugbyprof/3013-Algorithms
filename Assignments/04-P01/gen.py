#!/usr/local/bin/python3 
import random
from random import randint

def randchoice(p):
    if p == "Push":
        return (random.randint(0,100000000)) * 2
    else:
        return (random.randint(0,100000000)) * 2 +1

f = open('nums_test.dat','w')

choice1 = ['Push'] * 40000 + ['Pop'] * 10000
choice2 = ['Push'] * 10000 + ['Pop'] * 40000

random.shuffle(choice1)
random.shuffle(choice2)

choice1.extend(choice2)

for p in choice1:
    r = randchoice(p)
    f.write(f"{r}\n")