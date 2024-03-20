## Test 1 - Various Topics
#### Due: 02-12-2024 (Friday @ 2:00 p.m.)

### Topics

- [List Based Structures vs Array Based Structures](../../Lectures/LectureMaterials/04-ListVsArray/README.md)
- [Stacks & Queues](../../Lectures/LectureMaterials/01-StacksQueues/README.md)
- [Linked Lists](../../Lectures/LectureMaterials/00-LinkedList/README.md)
- [Bubble Sort Vs Selection Sort](../../Lectures/LectureMaterials/00-BubbleVSelection/README.md)
- [Array Based Binary Search](../../Lectures/LectureMaterials/02-BinarySearch/README.md)
- [Array Based Binary Tree](../../Lectures/LectureMaterials/00-ArrayBasedBinaryTree/)
- [Heap Memory vs Stack Memory](../../Lectures/LectureMaterials/05-StackMemVsHeapMem/README.md)



<!-- #### Heaps

[Overview](../../Resources/L01-Heaps/README.md) -->

#### Run Time Complexities

|                                                 Cheat Sheet 1                                                  |                                                 Cheat Sheet 2                                                  |
| :------------------------------------------------------------------------------------------------------------: | :------------------------------------------------------------------------------------------------------------: |
| [<img src="https://images2.imgbox.com/62/f0/eMsdwHxM_o.png">](https://images2.imgbox.com/a5/36/z6BvQv7x_o.png) | [<img src="https://images2.imgbox.com/64/37/2mFwTJ2K_o.png">](https://images2.imgbox.com/28/6d/JrAyZA2z_o.jpg) |



### Example Random Questions

- For everything you do on this test, know its complexity.
- Be able to write a basic sorting routine like a bubble sort or selection sort and know the difference between them.
- Given an array, perform a binary search to find a specific key.
- Describe the difference between searching:
  - a list
  - an array
  - an ordered list
  - an ordered array
  - a bst (binary search)

- Priority Queue
  - What is it?
  - What can it be used for?
  <br>
- Given a list of unordered numbers, load them into an array based binary search tree
- Given a list of unordered numbers, load them into a binary search tree
- Given a list of unordered numbers, load them into a priority queue.

- Run time stack memory vs Heap memory. 
  - Know which is which.
  - Which memory lasts entire program, and which one goes away at a functions end?
  - What keyword allows someone to place a variable in heap memory?
- Which scenarios or structures are more likely to cause a memory leak?

- For now you should know these "tree" terms:
  - Complete (fills in from left to right)
  - Full (all slots are "taken", no gaps)
  - Height (distance from the root to the furthest leaf node, and the left and right "subtrees" each can have their own height)
  - Balanced (Height of left subtree differs by no more than 1 with the right subtree)
- You may have to "draw" an example of 1 or more of the above trees.
- What is the time complexity of search in a balanced binary tree?
- What is the time complexity of search in an unbalanced binary tree?

-----

**Website Browsing Session History**
   - **Situation**: A web browser needs to manage a user's browsing session history to support forward and backward navigation.
   - **Question**: How would you design the session history feature using only stacks and/or queues, and why?

**Undo Functionality in a Text Editor**
   - **Situation**: Implementing an 'undo' feature in a text editor that allows users to revert their actions, one at a time, in the reverse order that they were made.
   - **Question**: Which simple data structure(s) would you use to implement the 'undo' functionality and how?

**Customer Service Call Center**
   - **Situation**: A customer service call center receives calls that are categorized into 'regular' and 'VIP'. VIP calls must be answered before regular ones, regardless of the order they come in.
   - **Question**: How would you organize the incoming calls using only queues and/or stacks such that VIP calls are prioritized?

**Parentheses Matching in Code Editors**
   - **Situation**: A code editor needs a feature to check if all opened parentheses, brackets, and braces are correctly matched and closed.
   - **Question**: Which simple data structure would you use to implement this feature, and what's the logic behind it?

**Sequential Task Processing**
   - **Situation**: Tasks come into a system in a sequence where each task has a prerequisite task that must be completed first. Some tasks can only start once their specific predecessor is done.
   - **Question**: How would you manage the execution order of these tasks using the simple data structures discussed?

- **Balancing Load in a Network**
  - **Situation**: You're tasked with designing a load balancer that evenly distributes incoming network requests to a set of servers. Upon receiving a request, the load balancer should forward it to the server with the least current load.
  - **Question**: Using only arrays/lists and basic operations, how would you implement a system to track and update the load on each server as requests are assigned and completed?

-----

- What is a primary advantage of using an array over a linked list?

- What is a primary advantage of using a list over an array?

- Why might resizing an array be considered costly?

- What aspect of arrays makes them easy and fast to use in many languages?

- Describe a situation where a linked list's overhead of managing pointers might be a justifiable trade-off.

- Explain how the contiguous memory allocation of arrays affects their performance and usability.

Both arrays and linked lists have their benefits, and hinderences. Know them. For example: Deleting an element from the front of a list and/or the front of an array both have the same "cost". Right?

Arrays and linked lists both have their upsides and downsides. So you should be able to list a few examples when you should or should not use an array or when you should or should not use a linked list.

-----

#### List or Array
- Data structure with elements stored in contiguous memory locations.  
- Efficient random access of elements by their index.  
- Insertion and deletion of elements at the beginning are typically faster.  
- Elements can be of varying sizes and types (heterogeneous).  
- Size can dynamically grow or shrink as elements are added or removed.  
- Fixed size, determined at the time of allocation.  
- Preferred for applications where memory layout and access speed are critical.  
- Better suited for scenarios where frequent insertions and deletions occur at various positions.  
- Memory overhead due to storing pointers to the next (and possibly previous) elements.  
- Elements are accessed sequentially starting from the head.

-----

#### Stack Queue or Priority Queue

- Operates on a First In, First Out (FIFO) principle.  
- Used for managing tasks in order of importance, not just arrival time.  
- Ideal for scenarios like undo mechanisms in text editors.  
- Elements are processed in the order they arrive unless one has higher priority.  
- Commonly used in breadth-first search algorithms in graph theory.  
- Follows a Last In, First Out (LIFO) principle.  
- Can be used to implement a scheduler for tasks that need to be executed in a specific order.  
- Utilized in balancing parentheses in compilers.  
- Elements with higher priority are moved to the front of the queue.  
- Suitable for queueing requests for a resource like a printer.

