## Test 2 - Study Guide
#### Due: 03-31-2022 (Thursday @ 12:30 p.m.)


#### List VS Array

[Overview](../../Resources/L03-ListVsArray/README.md)

#### Heap Memory VS Stack Memory

[Overview](../../Resources/L02-StackVsHeap/README.md)

### Binary Search
- Given a set of values determine if, and then perform a binary search if possible.

### Priority Queue

- Discuss multiple ways of implementing a priority queue
- What data structure (container) and why. 
- Which run faster?
- Which are easier to implement?

#### Run Time Complexities

|  Cheat Sheet 1 | Cheat Sheet 2 |
|:---------:|:---------------:|
| [<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/bigoh_cheet_sheet_2020_thumb.png">](https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/bigoh_cheet_sheet_2020.png) | [<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/bigoh_cheet_sheet_2_2020_thumb.png">](https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/bigoh_cheet_sheet_2_2020.png)



## Binary Search Tree Deletion

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

## Balanced Trees

### Avl Trees

1. Given a list of values, insert them into an AVL tree keeping track of balance factors and doing proper rotations when necessary.

2. 
| Insert 37 |
|:---:|
| <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/avl_rotate.png" width="200"> |

3. 
| Insert 13 |
|:---:|
| <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/avl_rotate.png" width="200"> |


## Tries

Given a set of words, be able to build a Trie data structure. For example add the following words to a Trie data structure: 

- peter
- piper 
- picked
- peck
- pickled
- peppers

-------

- What is the complexity of creating a Trie?
- What is the complexity of searching for a specific word in a Trie?
- What is the complexity of searching for all words with a given prefix in a Trie?
- A Trie is better for searching certain situations, where a BST is better for other situations. Explain what situations call for a Trie vs a Binary Search Tree. 
- To take this question a little further, would a Trie be a replacement for a hash table?!?



-------

## Next Exam

- Red Black Trees
- Graphs
- Spanning Trees
- Hashing





