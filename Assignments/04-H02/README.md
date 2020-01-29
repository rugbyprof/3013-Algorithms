## Assignment 4 - Shrinking the Stack
#### Due: 02-03-2020 (Monday @ 3:30 p.m.)

### Overview

The stack implementation [here:](../../Lectures/01-ArrayBasedStack/main.cpp) has a `Resize` method that ONLY will make the stack larger as we add items. This means that the stack will never shrink if we remove many items. We should probably remedy this issue.

### Requirements

- Create a folder in your `Assignments` folder called `04-H02` 
- Place your re-written `main.cpp` file into this `04-H02` folder.
- In `main.cpp` rename the `Resize` method to be `ContainerGrow` and comment it.
- Also in `main.cpp` add a method called `ContainerShrink` that performs the following:
  - When the size of the stack is half full (or less)
  - Resize the stack array to be 50% 
- In your main function 
  - insert 10000 items, then write out the stack size. 
  - delete 9999 items, then write out the stack size. 

- Banner info will be:

```
H02
3013
LASTNAME
```

### Deliverables

- Bring a printed copy of your code (with your banner) to class on Monday.
- Comment your code according to the style [here](../../Resources/01-Comments/README.md)
- Late to class = late program
- Checklist for program is [here](./checklist.md)