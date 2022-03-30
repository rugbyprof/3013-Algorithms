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

|                                                                                    Cheat Sheet 1                                                                                     |                                                                                      Cheat Sheet 2                                                                                       |
| :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------: | :--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------: |
| [<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/bigoh_cheet_sheet_2020_thumb.png">](https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/bigoh_cheet_sheet_2020.png) | [<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/bigoh_cheet_sheet_2_2020_thumb.png">](https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/bigoh_cheet_sheet_2_2020.png) |


## Tree Traversals:

Follow the path around the example below. To do a specific traversal, you would print the values at each node when you cross the specific color. For example, pre order traversal prints the node data at the red dot. In order at the green dot, and post order at the blue dot.

- Preorder (red dot) 
- Inorder (blue dot) 
- Postorder (green dot) 


<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/tree_traversal.png" width="300">


|   Order   |      Solution       | 
| :-------: | :-----------------: |
| Preorder  | **F,B,A,D,C,E,G,I,H** |
|  Inorder  | **A,B,C,D,E,F,G,H,I** |
| Postorder | **A,C,E,D,B,H,I,G,F** |

Another way to remember is to look at the recursive method that does the actual traversals. If you print before you recursively call left, then its a pre order. If you print in between your recursive calls, its a in order. If you print after you go left and then right, its a post order.

- PreOrder = Print GoLeft GoRight (or print left right)
- InOrder = GoLeft Print GoRight (or left print right)
- PostOrder = GoLeft GoRight Print (or left right print)

```cpp
void Traversal(Node* root){
  if(!root){
    return;
  }
  // preorder would cout node data here 
  Traversal(root->left);
  // inorder would cout node data here 
  Traversal(root->right);
  // postorder would cout node data here 
}
```


## Binary Search Tree Deletion

Delete the root from the following binary search tree:

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/binary_search_tree_deletion_3013_sp_2021.png" width="100">

Which of the following are reasonable?

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/reasonable_answers_bst_deletion_3013.png" width="500">

You should know the 4 cases when deleting a node, and how to handle them:

1. Leaf
2. Left Child 
3. Right Child
4. Both Chilren

I won't list here how to handle them, they are easily found. You won't have to write code to do a deletion, but you will have to re-draw a tree after you delete a value. 

-------

### Necessary for Tree Node Deletion

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
|                                          Insert 37                                          |
| :-----------------------------------------------------------------------------------------: |
| <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/avl_rotate.png" width="200"> |

3. 
|                                          Insert 13                                          |
| :-----------------------------------------------------------------------------------------: |
| <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/avl_rotate.png" width="200"> |


## Tries

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/trie_example.png" width="600">

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





