## Test 2 - Avl, Tree Traversals, Hashing
#### Due: 03-24-2023 (Friday @ 10:00 a.m.)

## Avl Trees

- Here is a pdf on rotations: [Tree Rotations](AVL-Tree-Rotations.pdf)
- Be able to insert a list of values into an AVL tree applying single and double rotations when appropriate so that you resulting tree is correct.
- Ensure you label the balance factors for each tree node. 
- Try to show work when you can. 

- Be able to describe the differences between a BST and AVL tree. Know the differences in implementation and performance (costs for insertion, searching, and deletion). Do we implement one or both using arrays or pointers?


## Tree Traversals

- Perform the following traversals on a binary tree:
    - PreOrder traversal
    - InOrder traversal
    - PostOrder traversal
    - LevelOrder traversal.

## Hashing

- When to choose which type of collision resolution:
  - Read this: https://stackoverflow.com/questions/2556142/chained-hash-tables-vs-open-addressed-hash-tables
  
  - Read this: https://www.geeksforgeeks.org/hashing-set-3-open-addressing/#:~:text=Open%20addressing%20requires%20extra%20care,number%20of%20keys%20is%20known.
   
### General Hashing Questions

  - Does the data being hashed have an impact on the hash function being chosen?
  - What is the `load factor`, and give a general overview of how certain load factors are chosen.
  - Table size is important when implementing a hash table. Explain how we should choose a certain table size and why.
  - Explain what `Collision resolution` is, the two major categories, and the three major open addressing types we discussed in class.
  - What does the term [`avalanche`](https://ieeexplore.ieee.org/document/9923931) mean when discussing hash functions?
    - https://simple.wikipedia.org/wiki/Avalanche_effect
  - How does a hash table allow for O(1) searching? 
  - What is the worst case efficiency of a look up in a hash table using:  chaining and open addressing?
  - The bigger the ratio between the size of the hash table and the number of data elements, the less chance there is for collision. What is a drawback to making the hash table big enough so the chances of a collision are extremely small?
  - How long would a deletion operation take from hash table implemented using separate chaining? 

-------


Given the input {4371, 1323, 6173, 4199, 4344, 9679, 1989}, a fixed
table size of 10, and a hash function H(X) = X mod 10, show the
resulting

- [Linear probing](https://www.baeldung.com/cs/hashing-linear-probing) hash table
- [Quadratic probing](https://www.tutorialspoint.com/quadratic-probing-in-data-structure) hash table
- [Separate chaining](https://www.baeldung.com/cs/hashing-separate-chaining) hash table



------

**Ascii Values:**

Here are some quick lookup tables to help with your hashing application question: 

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/ascii_values_letters.png" width="600">


-------

### Application Hashing

- Using the hash function below: 

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/hash_function.png" width="200">

- Hash the following values:
```
Epd, DcS, Fcf, Gco, Qzj, Wvc, RUC, ejJ, iwR, zyz
```

- Placing them in 3 separate hash tables using the following collision resolution techniques:

1. Linear Probing 
2. Quadratic Probing 
3. Chaining

- Choose an appropriate table size as well. 



-------

## Binary Search Tree Deletion

(NOT THIS TEST BUT WANTED TO LEAVE IT ON THE STUDY GUIDE)

Delete the root from the following binary search tree:

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/binary_search_tree_deletion_3013_sp_2021.png" width="100">

Which of the following are reasonable?

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/reasonable_answers_bst_deletion_3013.png" width="500">


-------

- Label the in-order predecessor and in-order successor of the root of this tree:

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/avl_tree_again_sp_2021.png" width="200">

- For practice, 
  - delete the in-order predecessor then draw the tree
  - delete the in-order successor then draw the tree

- Ok now delete the root of the tree, 
  - and then replace it with the in-order predecessor and redraw
  - and then replace it with the in-order successor and redraw

-------
Think about this: There is a general property in a BST where the in-order successor of a node whose right child is always null. Where might this be?

------

Algorithm to find in-order successor and predecessor
```txt
Input: root node, key
output: predecessor node, successor node

1. If root is NULL
      then return
2. if key is found then
    a. If its left subtree is not null
        Then predecessor will be the right most 
        child of left subtree or left child itself.
    b. If its right subtree is not null
        The successor will be the left most child 
        of right subtree or right child itself.
    return
3. If key is smaller then root node
        set the successor as root
        search recursively into left subtree
    else
        set the predecessor as root
        search recursively into right subtree
```

-------

Suppose `deleteMe` is the root node in a BST with both a left child and a right child. Will the in-order successor of `deleteMe`, always have a null left child?

1. Yes, always
2. No, only sometimes
3. No, never




