## Test 2 - Various Topics
#### Due: 03-25-2024 (Monday @ 2:00 p.m.)

### Topics

- [Complexity](../../Lectures/LectureMaterials/00-Big-Oh/README.md)
- [Binary Tree's](./bst.md)
- [Balanced Trees (AVL)](./avl.md)
- [Tree Traversals](./bst.md)
- [Basic Recursion Concepts](./recursion.md)
- [Json](./jsonVc++.md)
- [Getch](./getch.md)


Resources/03-Json/jsonVc++.md


<!-- #### Heaps

[Overview](../../Resources/L01-Heaps/README.md) -->

#### Run Time Complexities

|                                                 Cheat Sheet 1                                                  |                                                 Cheat Sheet 2                                                  |
| :------------------------------------------------------------------------------------------------------------: | :------------------------------------------------------------------------------------------------------------: |
| [<img src="https://images2.imgbox.com/62/f0/eMsdwHxM_o.png">](https://images2.imgbox.com/a5/36/z6BvQv7x_o.png) | [<img src="https://images2.imgbox.com/64/37/2mFwTJ2K_o.png">](https://images2.imgbox.com/28/6d/JrAyZA2z_o.jpg) |



### Example Random Questions

- Given an algorithm or data structure (something we have covered in class from week one up till now) know its Big Oh complexity.
- Given a list of values, insert them into a Binary Search Tree.
- Given a list of values, insert them into an AVL Tree. 
- What are the 3 necessary components you need  to write a recursive function.
```python
# This is python, write your code in c++ on exam
def print(root):
  
  if not root:# 1.  base case
    return
  else:
    # 2. approach base case [ 3. by calling ourself ]
    print(root.left)

    # do something
    print(root)

    # approach base case  [ 3. by calling ourself ]
    print(root.right)
}
```
- Be able to write a Recursive Binary Tree Traversal.
  - [c++ version here](../../Lectures/LectureMaterials/03-BinaryTrees/Bst.hpp)
```cpp
Look up (at the python version)
```
- For everything you do on this test, know its complexity.
- Be able to write a basic sorting routine like a bubble sort or selection sort and know the difference between them. [example code here](//Lectures/LectureMaterials/00-BubbleVSelection/README.md)
- Given an array, perform a binary search to find a specific key. [example code](../../Lectures/LectureMaterials/02-BinarySearch/README.md)
- Describe the difference between searching:
  - a list (****`O(N)`**** stuck looking at every node)
  - an array (**`O(N)`** unless ordered then **`O(lg N)`** why?)
  - an ordered list (**`O(N)`**)
  - an ordered array (**`O(lg N)`**)
  - a binary search tree (**`O(N)`**) (really kinda **`O(lg N) `**if its remotely balanced.)
  - a balanced binary search tree (guaranteed **`O(lg n)`**)




