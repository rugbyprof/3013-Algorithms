## Program 05 - STL Maps
#### Due: 04-05-2020 (Sunday @ 11:59 p.m.)

### Overview

I chose this problem because it represents a trick that I thought I invented myself and then came to find out I just re-discovered something. It has to do with counting unique values in a data set. It could be integers, it could be strings, or words in a book. Example: "what word occurs the most in Moby Dick"? Not a life or death question, but finding number of occurrences has its merits (voting, surveys, etc.). 

In python there is a data structure called a dictionary. In C++ its called a Map. We talked about key value pairs when we discussed the JSON library we used for another program. Thats how Map's and Dictionaries work. They use a "key" as the index, and it points to some "value". One thing that messes many people up when starting is they try to access a specific key (like add to it) before it exists! You need to make sure it exists in the structure before trying to access it. See below.

>**NOTE:** Php will let you add to a key in an associative array (their version of a dictionary or map) before it exists. If it cannot find it, it simply creates it, and sets it to zero! Worthless trivia.

I'm going to write an example in Python, otherwise I would be writing the solution to your UVA problem :) 

I have some input that I need to count occurrences. In this case fruit.

#### input.txt
```
apple
banana
apple
banana
kiwi
kiwi
banana
pear
kiwi
banana
apple
orange
```

Here is how I would do it using a dictionary and python (equivalent to STL Map):

Here is the repl.it: https://repl.it/@rugbyprof/countfruits

```python
f = open("input.txt","r")
fruits = [] # create a list to hold inputs
counts = {}   # create a dictionary to help count

fruits = f.readlines()      # reads every value from f into an array (list actually)

for fruit in fruits:        # loop through list of fruits
    fruit = fruit.strip()           # clean spaces and newlines from variable
    if not fruit in counts: # if the key is not in the dictionary
        counts[fruit] = 0   # add it and initialize to zero
    counts[fruit] += 1      # now we add 1 (key has to exist before we add to it!)

print(counts)               # yes python will print out the dictionary without complaining
                            # c++ would have a stroke.
```

#### Output:
```json
{
    "apple":3,
    "banana":4,
    "kiwi":3,
    "pear":1,
    "orange":1
}
```

### Stl Map

Here is a nice overview on geeks for geeks: https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/

Below is a snippet that will help you emulate what I did in the python snippet, seeing if a key exists in a Map. If it doesn't, you need 
to initialize the count to zero, and then you can add to it. 

```cpp
if ( m.find("key") == m.end() ) {
  // not found
} else {
  // found
}
```

### Debug

Don't forget about your debug site: https://www.udebug.com/UVa/484 for extra data sets to test.

### Deliverables

- Again: Make sure your UVA username is on this [google doc](https://docs.google.com/spreadsheets/d/1ShN0rIHHMi8mdyPhNDfehTJcw3GRApJPUboiSi2mBxA/edit?usp=sharing) version of our class roster.
- Create a folder called 484 in your `assignments` folder.
- Call your program `main.cpp` 
- Include all input files you used to test your code with. 
- Include the pdf of the problem in your `484` folder as well. 
- Upload to UVA online judge by due date.
- Upload to github soon after (not before).