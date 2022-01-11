## Test 2 - Study Guide
#### Due: TBD

First go look at the [README](../../README.md) file for the course which lists topics to be covered. I'm pretty happy with how far we have gotten.  

Otherwise, here is the study guide for our second test. I welcome any and all feedback / questions!! Bring it! 

## Sorting

-------

Be able to distinguish the differences between: bubble sort, insertion sort, selection sort. 

-------

- ~~Learn how to write a Recursive Bubble Sort:~~ (maybe final exam 😏)
  - https://www.ritambhara.in/recursive-bubble-sort/

-------

- What are the 2 major categories of sorting algorithms, and which sorting algorithms (discussed in class) fit into each. 
- What is a stable sorting algorithm?
- Which sorting algorithms use divide and conquer techniques? Why or why is this not a good strategy?
- Hint1: [Nice Summary of Sorting Algorithms](https://www.happycoders.eu/algorithms/sorting-algorithms/)
- Hint2: [Nice Summary of Sorting Algorithms 2](https://medium.com/@tssovi/comparison-of-sorting-algorithms-298fdf037c8f)

-------

- How do counting sort and radix sort relate, and what makes them a great pair? This doesn't mean that you need to understand how to implement counting or radix sort. In fact, can counting sort run on it's own?

-------

- Quicksort and Merge-sort have the same complexity. Briefly explain why, despite similar complexity, Quicksort is the more popular sorting algorithm?

-------

- Given the following array [10, 5, 3, 9, 22, 24, 28, 27, ?] and assuming that Quicksort will be used to sort this array in ascending order, select a value for the last element of the array (indicated by “?”) such that the partitioning performed by Quicksort is most balanced. Explain why this makes Quicksort perform efficiently.

-------
Give your answers in big O notation.

- What is the complexity of dividing and merging an array of length n? 
- What is the complexity of dividing arrays in Merge-sort? 
- What is the overall complexity of Merge-sort? 

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


## Hashing

### Basics 

- When to choose which type of collision resolution:
  - Read this: https://stackoverflow.com/questions/2556142/chained-hash-tables-vs-open-addressed-hash-tables
  - Read this: https://www.geeksforgeeks.org/hashing-set-3-open-addressing/#:~:text=Open%20addressing%20requires%20extra%20care,number%20of%20keys%20is%20known.
   
- General Questions
  - Does the data being hashed have an impact on the hash function being chosen?
  - What is the `load factor`, and give a general overview of how certain load factors are chosen.
  - Table size is important when implementing a hash table. Explain how we should choose a certain table size and why after you learn how many items you will be hashing. 
  - Explain what `Collision resolution` is. Describe as many collision resolution schemes as you can find :) 
  - What does the term `avalanche` mean when discussing hash functions?
    - https://simple.wikipedia.org/wiki/Avalanche_effect
  - How does a hash table allow for O(1) searching? 
  - What is the worst case efficiency of a look up in a hash table using separate chaining?
  - The bigger the ratio between the size of the hash table and the number of data elements, the less chance there is for collision. What is a drawback to making the hash table big enough so the chances of collision is ignorable?
  - How could a hash table be used to implement a spell checker? 
  - How long would a deletion operation take from hash table implemented using separate chaining? 

-------

**Ascii Values:**

Here are some quick lookup tables to help with your hashing application question: 

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/ascii_values_letters.png" width="600">


-------

### Application Hashing

- Using the hash function below: 

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/hash_function_one_29_mar_2021.gif" width="200">

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




