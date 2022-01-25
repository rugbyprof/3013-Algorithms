## Program 1 - Resizing the Stack
#### Due: 01-27-2022 (Thursday @ 12:30 p.m.)

### Overview

- The stack implementation [here:](ArrayBasedStackCode/main.cpp) has a `Resize` method that ONLY will make the stack larger as we add items. 
- This means that the stack will never shrink if we remove many items. 
- We should probably remedy this issue.

#### Stack Resizing

- Full and Empty are determined by number of items in stack vs current stack size.
- This obviously gives us a ratio. So if I have a stack of size `50` and it has `17` items in it, then its `0.34` percent full. 
- You will resize your stack when it gets too full, or too empty. But what is `too full` or `too empty` and how much do we resize it by??
- Those parameters are determined by command line parameters entered when you run your program. 
- For testing, and to get up and running (if you don't know about `argc` and `argv`) simply use the following thresholds to resize your stack:
  - Too Full = 100% meaning no extra slots available in your array. 
  - Too Empty = 15% meaning in a stack of 100, if you get down to 15 items you need to shrink your stack.
  - Enlarging = Double the size of the stack.
  - Shrinking - Cut the size of the stack in half. 
- When you do use command line params, your program should expect 0 (which implies use defaults) or 4 params (in this order):
  - Too Full Threshold : a real number like .85, .77,  or 1.0  (threshold to grow)
  - Too Empty Threshold: a real number like .15, .20, or 0.0  (threshold to shrink)
  - Enlarging Threshold: a real number like 2.0 (double size), or 1.5 or 1.75 (how much to grow)
  - Shrinking Threshold: a real number like .5 or .75 or .25  (how much to shrink)
- If you want to handle a param count of other than 0 or 4, that would be a nice touch. 
- One hard rule: Never let your stack get below **size 10**.
- Rename `Resize` method to be `ContainerGrow`.
- Add a `ContainerShrink` method.
- A third method: `CheckResize` could be a good addition. This method would calculate the ratios then call appropriated resize method if necessary. 
- Make sure you comment your code.

#### Testing Your Code

- You will read numbers from the file [nums_test.dat](./nums_test.dat).
- If a number is even, push it onto the stack. 
- If a number is odd, perform a pop operation removing the last even value from the stack. 
- Don't let your stack get smaller than **10** (our starting stack size).
- You need to keep track of the following:
  - the **max size** the stack ever reached
  - **how many times** the stack was resized (grown or reduced)
  - **final size** of stack when program completed
  - number of **commands processed** (how many values read from the input file) 
  - fullThreshold : ratio you go over to grow the stack (e.g. .85)
  - shrinkThreshold to shrink : ratio to go under to shrink the stack (e.g. .15) but not below size 10!
  - growRatio : how much to grow the stack (e.g. 2.0 = double the size) 
  - shrinkRatio : how much to shrink the stack (e.g. .5 = half its size)


#### Example Output

```
######################################################################
    Assignment 4 - Resizing the Stack
    CMPS 3013
    Your Name

    Config Params:
      Full Threshold: xx.x
      Shrink Threshold: xx.x
      Grow Ratio: xx.x
      Shrink Ratio: xx.x

    Processed xxxxxxx commands.

    Max Stack Size: xxxxxx
    End Stack Size: xxxxxx
    Stack Resized: xxxxx times

######################################################################
```

### Requirements

- Create a folder in your `Assignments` folder called `P01` 
- Place your re-written `main.cpp` file into this `P01` folder.
- Add your folder with all input and/or output files to your github repo.
- Banner info will be:

```
P01
3013
LASTNAME
```

### Deliverables

- Bring a printed copy of your code (with your banner) to class on Tuesday.
- You should print the example output out as well. Probably writing it to a file would be the best way.
- Comment your code according to the style [here](../../Resources/01-Comments/README.md)
- Banner for your assignment [here](../../Resources/02-Banner/README.md)
- Late to class = late program
- Checklist for program is [here](./checklist.md)


#### What to bring to class:

A stapled stack in the order below:
```
+----------------+
| Banner         |
| Output         |
| Commented Code |
+----------------+
```

