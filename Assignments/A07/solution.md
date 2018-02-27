## Test 1 

Name: _________________________

<center>

| #  | Possible | Earned |
|:--:|:--------:|:------:|
|  1  |      10    |        |
| 2   |   10       |        |
| 3   |  15        |        |
| 4   |   10       |        |
|  5  |   10       |        |
| 6   |   10       |        |
| 7   |   10       |        |
|  8  |   15       |        |
|  **Total**  |   **90**       |        |

</center>

<div style="page-break-after:always"></div>

#### Question 1 <sup>(10 points)</sup> 

Draw the binary search tree that is created if the following numbers are inserted in the tree in the given order. 

**<center>12 15 3 35 21 42 14</center>**

#### Solution:

<center><img src="https://cl.ly/pptK/3013.test1.q1.sol.png" width="200"></center>

<div style="page-break-after:always"></div>

#### Question 2 <sup>(10 points)</sup>

Insert the value **21** into the following avl tree and adjust as appropriate:

<center><img src="https://cl.ly/pn1P/avl_tree_insert_21.png" width="200"></center>

#### Solution:

<center><img src="https://cl.ly/ppUs/3013.test1.avl_insert.sol.png" width="500"></center>

<div style="page-break-after:always"></div>

#### Question 3 <sup>(15 points)</sup>

Draw the binary min heap that results from inserting  **11, 9, 12, 14, 3, 15, 7, 8, 1** in that order into an initially empty binary **min-heap**. You do not need to show the array representation of the heap. You are only required to show the final tree, although if you draw intermediate trees, make clear which is your final answer.

#### Solution:

<center><img src="https://cl.ly/ppz0/heap_build_sol.png" width="600"></center>

<div style="page-break-after:always"></div>

#### Question 4 <sup>(10 points)</sup>

Draw the binary heap that results from doing 2 delete-mins on the heap you
created in question 3. You are only required to show the final tree, although if you draw
intermediate trees make clear which is your final answer.

#### Solution:

<center><img src="https://cl.ly/ppBp/heap_del_min_sol.png" width="600"></center>

<div style="page-break-after:always"></div>

#### Question 5 <sup>(10 points)</sup>

Delete the root of the following binary tree, and draw the resulting tree.

#### Solution:

<img src="https://cl.ly/ppKb/delete_from_binary_tree.png" width="600">

<div style="page-break-after:always"></div>

#### Question 6 <sup>(10 points)</sup>

Given:

```cpp
struct Node{
   int data;
   Node* next;
};
```

Write a recursive **`function`** to traverse a linked list. Your function will return the sum of the integer values contained in the nodes of the list. The function header would look like:

```cpp
int traverse(Node* root);
```

#### Solution:

```cpp
int traverse(Node* root){
	if(!root){
	   return 0;
	}else{
	   return root->data + traverse(root->next);
	}
}
```

<div style="page-break-after:always"></div>

#### Question 7 <sup>(10 points)</sup>

Write a function to calculate the height of a BST. Your function header would look like:


```cpp
int height(Node* root);
```

#### Solution:

```cpp
int height(Node* root){
   if(!root){
       return 0;
   }else{
       int l = height(root->left);
       int r = height(root->right);
       
       if(l>r){
       	return l + 1;
       }else{
          return r + 1;
       }
   }
}
```


<div style="page-break-after:always"></div>

#### Question 8 <sup>(15 points)</sup>

<img src="https://cl.ly/ppyI/delete_root_example.png" width="400">

Using the tree above, show the output of a:

- Pre Order Traversal

```
25 13 10 18 21 35 28 27 45

```

- In Order Traversal

```
10 13 18 21 25 27 28 35 45

```

- Post Order Traversal

```
10 21 18 13 27 28 45 35 25

```
