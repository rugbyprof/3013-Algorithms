## Assignment 4 - Resizing the Stack
#### Due: 02-05-2020 (Wednesday @ 3:30 p.m.)

### Overview

- The stack implementation [here:](../../Lectures/01-ArrayBasedStack/main.cpp) has a `Resize` method that ONLY will make the stack larger as we add items. 
- This means that the stack will never shrink if we remove many items. 
- We should probably remedy this issue.

#### Stack Resizing

- Full and Empty are determined by number of items in stack vs current stack size.
- Increase stack size by **1.75** times when stack is full.
  - Full = `No More Array Locations` 
  - Resize should be when a value is pushed onto a FULL stack.
- Decrease stack by **.5** when stack becomes half empty. 
  - Resize when ratio goes below .50 
- Rename `Resize` method to be `ContainerGrow`.
- Add a `ContainerShrink` method.
- A third method: `CheckResize` could be a good addition. This method would calculate the ratios then call appropriated resize method if necessary. 
- Make sure you comment your code.

#### Testing Your Code

- You will read numbers from the file [nums.dat](./nums.dat).
- If a number is even, push it onto the stack. 
- If a number is odd, perform a pop operation removing the last even value from the stack. 
- You need to keep track of the following:
  - the **max size** the stack ever reached
  - **how many times** the stack was resized (grown or reduced)
  - **final size** of stack when program completed

#### Example Output

```
######################################################################
    Assignment 4 - Resizing the Stack
    CMPS 3013
    Your Name

    Max Stack Size: xxxxxx
    End Stack Size: xxxxxx
    Stack Resized: xxxxx times

######################################################################
```

### Requirements

- Create a folder in your `Assignments` folder called `04-StackResize` 
- Place your re-written `main.cpp` file into this `04-StackResize` folder.
- Add your folder with all input and/or output files to your github repo.

- Banner info will be:

```
P01
3013
LASTNAME
```

### Deliverables

- Bring a printed copy of your code (with your banner) to class on Monday.
- Comment your code according to the style [here](../../Resources/01-Comments/README.md)
- Late to class = late program
- Checklist for program is [here](./checklist.md)