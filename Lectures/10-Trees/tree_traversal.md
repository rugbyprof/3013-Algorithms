## Tree Traversals (Inorder, Preorder and Postorder)

Unlike linear data structures (Array, Linked List, Queues, Stacks, etc) which have only one logical
way to traverse them, trees can be traversed in different ways. Following are the generally used
ways for traversing trees.

![ExampleTree](https://media.geeksforgeeks.org/wp-content/cdn-uploads/2009/06/tree12.gif%20%22tree12%22)

Example Tree

Depth First Traversals:  
(a) Inorder (Left, Root, Right) : 4 2 5 1 3  
(b) Preorder (Root, Left, Right) : 1 2 4 5 3  
(c) Postorder (Left, Right, Root) : 4 5 2 3 1

Breadth First or Level Order Traversal : 1 2 3 4 5  
Please see [this](https://www.geeksforgeeks.org/level-order-tree-traversal/) post for Breadth First
Traversal.

**Inorder Traversal ([Practice](https://practice.geeksforgeeks.org/problems/inorder-traversal/1)):**

- Algorithm Inorder(tree)
    1. Traverse the left subtree, i.e., call Inorder(left-subtree)
    2. Visit the root.
    3. Traverse the right subtree, i.e., call Inorder(right-subtree)

Uses of Inorder  
In case of binary search trees (BST), Inorder traversal gives nodes in non-decreasing order. To get
nodes of BST in non-increasing order, a variation of Inorder traversal where Inorder traversal s
reversed can be used.  
Example: Inorder traversal for the above-given figure is 4 2 5 1 3.

**Preorder Traversal ( [Practice](https://practice.geeksforgeeks.org/problems/preorder-traversal/1)):**

- Algorithm Preorder(tree)
    1. Visit the root.
    2. Traverse the left subtree, i.e., call Preorder(left-subtree)
    3. Traverse the right subtree, i.e., call Preorder(right-subtree) 

Uses of Preorder  
Preorder traversal is used to create a copy of the tree. Preorder traversal is also used to get
prefix expression on of an expression tree. Please see
<http://en.wikipedia.org/wiki/Polish_notation> to know why prefix expressions are useful.  
Example: Preorder traversal for the above given figure is 1 2 4 5 3.

**Postorder Traversal ( [Practice](https://practice.geeksforgeeks.org/problems/postorder-traversal/1)):**

- Algorithm Postorder(tree)
    1. Traverse the left subtree, i.e., call Postorder(left-subtree)
    2. Traverse the right subtree, i.e., call Postorder(right-subtree)
    3. Visit the root.

Uses of Postorder  
Postorder traversal is used to delete the tree. Please see [the question for deletion of
tree](https://www.geeksforgeeks.org/write-a-c-program-to-delete-a-tree/) for details. Postorder
traversal is also useful to get the postfix expression of an expression tree. Please see
<http://en.wikipedia.org/wiki/Reverse_Polish_notation> to for the usage of postfix expression.

Example: Postorder traversal for the above given figure is `4 5 2 3 1`.

**Output:**
```
    Preorder traversal of binary tree is
    1 2 4 5 3 
    Inorder traversal of binary tree is
    4 2 5 1 3 
    Postorder traversal of binary tree is
    4 5 2 3 1
```

**One more example:**  
![](https://media.geeksforgeeks.org/wp-content/cdn-uploads/Preorder-from-Inorder-and-Postorder-traversals.jpg)

**Time Complexity:** O(n)  
Let us see different corner cases.  
Complexity function T(n) — for all problem where tree traversal is involved — can be defined as:

<span class="underline"></span>

T(n) = T(k) + T(n – k – 1) + c

Where k is the number of nodes on one side of root and n-k-1 on the other side.

Let’s do an analysis of boundary conditions

Case 1: Skewed tree (One of the subtrees is empty and other subtree is non-empty )

k is 0 in this case.  
T(n) = T(0) + T(n-1) + c  
T(n) = 2T(0) + T(n-2) + 2c  
T(n) = 3T(0) + T(n-3) + 3c  
T(n) = 4T(0) + T(n-4) + 4c

…………………………………………  
………………………………………….  
T(n) = (n-1)T(0) + T(1) + (n-1)c  
T(n) = nT(0) + (n)c

Value of T(0) will be some constant say d. (traversing a empty tree will take some constants time)

T(n) = n(c+d)  
T(n) = Θ(n) (Theta of n)

Case 2: Both left and right subtrees have equal number of nodes.

T(n) = 2T(|\_n/2\_|) + c

This recursive function is in the standard form (T(n) = aT(n/b) + (-)(n) ) for master method
<http://en.wikipedia.org/wiki/Master_theorem> . If we solve it by master method we get (-)(n)

**Auxiliary Space :** If we don’t consider size of stack for function calls then O(1) otherwise
O(n).
