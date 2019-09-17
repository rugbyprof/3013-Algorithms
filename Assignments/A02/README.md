## Program 1 - Balanced tree's
#### Due: September 18<sup>th</sup> by classtime.

### Overview

Using some implementation of a binary searth tree that holds integers, take the provided file of numbers and insert them in such a manner that the resulting tree is complete and / or full.

***Complete Tree***

![](https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/complete_tree.png)


***Full Tree***

![](https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/full_tree.png)

When a tree is unbalanced, its search times start to degrade. For example, the minumum number of nodes in a tree that has height `H` is ... `H+1`. This means we have a skewed tree (more like a linked list). But, when a tree is balanced, we can hold up to `2^`<sup>`(h+1)`</sup>`-1` nodes. This will let us get our guaranteed `O(lg n)`  times for BST operations (see below).

#### BST performance:

| Algorithm | Average  | Worst case |
| :-------- | :------- | :--------- |
| Space     | O(n)     | O(n)       |
| Search    | O(log n) | O(n)       |
| Insert    | O(log n) | O(n)       |
| Delete    | O(log n) | O(n)       |

### Requirements

- Given a text file that has 1 - N integers one per line and not in any particular order.
- Take those numbers and load them into a binary search tree such that the tree will end up:
  - Complete
  - Possibly Full
  - A balanced tree will give you partial credit
- You can do whatever you want to the numbers. 
  - Read them all in.
  - Sort them.
  - Shuffle them.
  - Etc.
- Whatever will help you create a proper complete or full tree. 
- Remember, a completely sorted list inserted into a binary tree will result in a ... linked list (basically).

### Deliverables

- Create a folder called `assignments`
- In `assignments` create a folder called `A02`
- In `A02` place your code in a file called `bst_builder.cpp`
- Name your input file `input.dat` and one number per line.
- Include any input files you used to test your code as well.
- Comment your code. My touched up lecture code should be a good enough example.
- Here is a binary tree but with graphviz output to "see your tree".
- Turn in a printed copy of your source code (NOT from github). 
  - There is a way to print source code from github, ask me in class to show you.
- Staple your pages together at the top left (very close to the corner).
- No hand writing on your pages at all! 
- Top page should be your first source code page with a BIG comment block that explains the program and tells me who you are with date etc.
- Back pages are your printed trees. If your tree is huge, shrink it to fit on a single page.
