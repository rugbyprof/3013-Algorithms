## Test 1 - Study Guide
### Due: 14<sup>th</sup> of October


## Question

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.test.1.7.png">

Write a function to remove an item from a list. Here's a header to start with.  

`int remove(Node* head,int key)`

Where `head` is the head of the list and `key` is the value to be removed (if it's in the list).
You may need to alter the header a tiny bit to make your changes take effect.

## Question

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.test.1.5.png">

- What is the height of this tree?
- What is the root of this tree?
- How many leaves does this tree have? List them.
- How many descendants does **D** have?
- How many siblings does  **A** have?
- Assuming this tree is ordered: 
	- Who is the predecessor of **E**?
	- Who is the successor of **E**?

## Question

- What is the minimum number of nodes in a full binary tree with height **3**?
- What is the maximum height of a Binary Tree (not search tree) with **N** nodes?
- What is the height of a complete Binary Tree  with **N** nodes?

## Question

Write some `c++` code to allocate the memory and link these items together so that it represents the little tree above. Do not assume there are any class methods (like `insert`) to help you. Write all your code as if you were in main. No functions necessary.

## Question

**A)** Is the following tree 1) **Full** 2) **Complete** 3) **Both** 

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.test.1.2.png">

**B)** If it is not, how would you fix it to make it both?

## Question

#### Part A
Values: **12,  15,  3,  35,  21,  42,  14**

Draw the binary search tree that is created if the following numbers are inserted in the tree in the given order. 

#### Part B

Using the values above, put them into this balanced tree in an order that will keep the tree correct.

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.test.1.6.png">

## Question

Perform a 1) **Pre-Order** 2) **In-Order** and 3) **Post-Order** traversal on the following tree:

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.test.1.3a.png">

|        |      |
|:----|:---|
|Pre-Order: | <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.test.1.4.png"> |
| In-Order: |<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.test.1.4.png"> |
| Post-Order: | <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.test.1.4.png"> |
><sup> There are extra cells, don't freak out</sup>

## Question

Write a recursive function to:

- **Count** all the nodes in a BST.
- **Count** all the **leaves** in a BST.
- Calculate the **Height** of a BST.

## Question

Given two binary trees, return true if they are structurally identical -- they are made of nodes with the same values arranged in the same way. Your function header would look like: `bool sameTree(Node* a, Node* b) `

## Question

We discussed searching for items when dealing with certain structures. How long would it take a `search` method to  find an item in:

|         |       |      |     |      |     |       |      |
|----:|:----:|:----:|:----:|:----:|:----:|:----:|:----:|
| Sorted Array of numbers: |  *O(1)* | *O(log n)* | *O(n)* | *O(n log n)* | *O(n*<sup>*2*</sup>) | *O(n*<sup>*3*</sup>*)* | *O(2*<sup>*n*</sup>)|
Sorted List of numbers:|  *O(1)* | *O(log n)* | *O(n)* | *O(n log n)* | *O(n*<sup>*2*</sup>) | *O(n*<sup>*3*</sup>*)* | *O(2*<sup>*n*</sup>)|
Binary Search Tree: |  *O(1)* | *O(log n)* | *O(n)* | *O(n log n)* | *O(n*<sup>*2*</sup>)| *O(n*<sup>*3*</sup>*)* | *O(2*<sup>*n*</sup>)|

## Question

Assume you have:
```cpp
struct Node{
	int data;
	Node* left;
	Node* right;
}
```

Write code that builds the following little 1-2-3 binary search tree...

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.test.1.1.png">

## Question

Write an insert Method for a Binary Search Tree.

## Question

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.test.1.3a.png">

Delete the 23 and 25 from this tree with the least amount of tree alteration as possible.
Describe what order you would do this in and whether your replacing nodes with a predecessor
or successor.

