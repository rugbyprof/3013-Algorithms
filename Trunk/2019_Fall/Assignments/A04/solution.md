## Test 1

- Put your name on all papers turned in.
- Do not put your answers on the test, use the paper given to you as an answer sheet.
- Write clear and clean. 
- Do not use pen.
- Clearly number and delineate each answer. 
- Place your answers on the given paper in order. 
- Do not split an answer between two pages or between front and back.
- You can lose points for not following instructions or making your answers hard to read.
- Each question is worth 10 points.
  

------

### Question 1

  
Write a function to remove an item from a singly linked list. Call your function `Remove` and assume the function is not within a class.

```cpp
void Remove(Node*& Head, int key){
`	// Copy head pointer 
	Node* Temp = Head;
	// If head data is key, remove it.
	if(Temp->Data == key){
		Head = Head->Next;
		delete temp;
		return;
	}
	// Go find item to be deleted
	while(Temp->Next && Temp->Next->Data != key){
		Temp = Temp->Next;
	}
	if(Temp->Next){
		Node* Hold = Temp->Next;
		Temp->Next = Hold->Next;
		delete Hold;
	}
	return;
}

```


-----

###  Question 2


 <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/test.1.1b.png">

**Answer:**

|  Question          |   Answer          |
|:-------|:-----------:|
| What is the height of this tree? | **5 or 6** acceptable | 
| What is the root of this tree? | **33** |
| How many leaves does this tree have? List them. | **5,12,19,25,30,37,53** |
| How many descendants does **23** have? | **9** |
| How many siblings does **23** have? | **1**  |
| Who is the predecessor of **23**? | **19** |
| Who is the successor of **23**? | **25** |

 -----
  
### Question 3


| Given this   |   Make this    | 
|:---:|:-----:|
| <img  src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/node_snippet.png" width="150"> | <img  src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.test.1.1.png"> |

Write a function that will return a 3 node tree. The values for each node are always 1,2,3.

**Answer:**
```cpp
Node* makeTree(){
	Node* A = new node(1);
	Node* B = new Node(2);
	Node* C = new Node(3)
	
	B->left = A;
	B->right = C;
	return B;
}

```
 -----
    
### Question 4

Draw the binary search tree that is created if the following numbers are inserted in the tree in the given order.
Values: **2, 5, 7, 12, 15, 3, 35, 21, 42, 14** (insert 2  then 5 etc.)

**Answer:**
<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/test.1.ans.4.png">

------  

### Question 5

Perform a A) ***Pre-Order*** B) ***In-Order*** and C) ***Post-Order*** traversal on the following tree:

 <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/test.1.1b.png">

<br><br><br>

**Answer:**

```
Pre-Order: 33, 23, 10, 5, 15, 12, 17, 19, 27, 25, 30, 40, 37, 53
In-Order: 5, 10, 12, 15, 17, 19, 23, 25, 27, 30, 33, 37, 40, 53 
Post-Order: 5, 12, 19, 17, 15, 10, 25, 30, 27, 23, 37, 53, 40, 33
```

-----

### Question 6 


Write a recursive function to Count all the ***leaves*** in a BST. Call it ***countLeaves***.

```cpp

int countLeaves(Node* Root){
	if(!Root){
		return 0;
	}
	if(!Root->left && !Root->right){
		return 1;
	}
		
	return countLeaves(Root->left) + countLeaves(Root->right);
	
}
```

-----

### Question 7 

  Write a recursive function to Calculate the ***height*** of a BST. Call it ***treeHeight***.
  
```cpp
int treeHeight(Node* Root){
	if(!Root){
		return  0;
	}else{
		int left_height = 1 + _treeHeight(Root->left);
		int right_height = 1 + _treeHeight(Root->right);
	}
	if(left_height > right_height){
		return left_height;
	}else{
		return right_height;
	}
}
```

-----

### Question 8

Given two binary trees, return true if they are structurally identical -- they are made of nodes with the same values arranged in the same way. Your function header would look like: 
***`bool sameTree(Node* a, Node* b)`***

```cpp
bool sameTree(Node* a, Node* b){
    // Both empty
    if (a == NULL && b == NULL)  
        return true;  
  
    if (a != NULL && b != NULL)  
    {  
        return
        (  
            a->data == b->data &&  
            identicalTrees(a->left, b->left) &&  
            identicalTrees(a->right, b->right)  
        );  
    }  
      
     //
    return 0;  	
}
```

-----

###  Question 9 

We discussed searching for items when dealing with certain structures. How long would it take a `search` method to find an item in:

**Choices:**
| | | | | | | | |
|:----|:----:|:----:|:----:|:----:|:----:|:----:|:----:|
| *O(1)* | *O(log n)* | *O(n)* | *O(n log n)* | *O(n*<sup>*2*</sup>)| *O(n*<sup>*3*</sup>*)* | *O(2*<sup>*n*</sup>)|

<br>

| | Searching: |  Takes How Long?
|:----|:----|:-----:|
| **A** | Unsorted Array of numbers | *O(n)* 
| **B** | Sorted Array of numbers | *O(log n)* 
| **C** | Sorted List of numbers| *O(n)*
| **D** | Binary Search Tree |  *O(log n)*

**E)** How long would it take to Heapsort an array of numbers? *O(n log n)*

  <br><br><br>
  
-----  

### Question 10 

Write an insert Method for a Binary Search Tree. Method implies it is a `class` member function.

```cpp
void Insert(int val){
	Node* Temp = new Node(val);
	_Insert(Root, Temp);
}

void _Insert(Node*& Root, Node* Temp){
	if(!Root){
		Root = Temp;
	}else{
		if(Root->Data > Temp->Data){
			_Insert(Root->left);
		}else{
			_Insert(Root->right;
		}
	}
}

```


-----

### Question 11


<img  src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.test.1.3a.png">

Delete the 23 and 25 from this tree with the least amount of tree alteration as possible.

Describe what order you would do this in and whether you are replacing nodes with a predecessor or successor.

**Answer:**

- Delete 25 its a leaf.
- Swap 23 and 15 (23's predecessor).
- Delete 23 its now a leaf.
