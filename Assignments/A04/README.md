## Assignment 4 - Fix delete method
Due: February 13<sup>th</sup> by Classtime.


### Overview

Given the code available [here](../Lectures/bstree2.cpp) fix the delete method so that it can handle deleting the root node when it doesn't have a left or a right child. Your code should work with the following snippet and terminate cleanly.

```cpp
    // Continously delete root node, until tree is empty.
    while(B.top()){
        cout<<"removing: "<<B.top()<<endl;
        B.deleteNode(B.top());
    }
```

### Deliverables

- Create a folder called `assignment_4` in your assignments folder.
- Rename the given `bstree2` file to `BSTree`.
- Refactor the `bstree2.cpp` so that it has an implementation file and a definition file (`.cpp` and `.h` or `.hpp`).
- Comment thoroughly!! Meaning a comment for each method and comment block at the top of each file. 
- Your finished folder should have:
    - `main.cpp`
    - `BSTree.cpp`
    - `BSTree.h` 
