## Test 1 - Various Topics

#### Due: 02-12-2025 (Wed @ 2:00)

### Topics

- [Algorithm vs Data Structure](../../Lectures/AlgorithmJourney/README.md)
- [Array Based Binary Tree](../../Lectures/ArrayBasedBinaryTree/README.md)
- [Big-Oh](../../Lectures/Big-Oh/README.md)
- [Binary Heap](../../Lectures/BinaryHeap/README.md)
- [Array Based Binary Search](../../Lectures/BinarySearch/README.md)
- [Binary Search Trees](../../Lectures/BinaryTrees/README.md)
- [Bubble Sort Vs Selection Sort](../../Lectures/BubbleVSelection/README.md)
- [List Based Structures vs Array Based Structures](../../Lectures/ListVsArray/README.md)
- [Ordered List (priority queue)](../../Lectures/OrderedList/README.md)
- [Recursion](../../Lectures/Recursion/README.md)
- [Heap Memory vs Stack Memory](../../Lectures/StackMemVsHeapMem/README.md)
- [Stacks & Queues](../../Lectures/StacksQueues/README.md)

<!-- #### Heaps

[Overview](../../Resources/L01-Heaps/README.md) -->

#### Run Time Complexities

|                                                 Cheat Sheet 1                                                  |                                                 Cheat Sheet 2                                                  |
| :------------------------------------------------------------------------------------------------------------: | :------------------------------------------------------------------------------------------------------------: |
| [<img src="https://images2.imgbox.com/62/f0/eMsdwHxM_o.png">](https://images2.imgbox.com/a5/36/z6BvQv7x_o.png) | [<img src="https://images2.imgbox.com/64/37/2mFwTJ2K_o.png">](https://images2.imgbox.com/28/6d/JrAyZA2z_o.jpg) |

## **1. Fundamental Concepts**

### **Searching in Different Structures**

- **List**: Sequentially search for an element.
- **Array**: Direct access via index; searching requires iteration unless sorted.
- **Ordered List**: Can utilize binary search for faster lookup.
- **Ordered Array**: Allows binary search for O(log n) search time.
- **Binary Search Tree (BST)**: If balanced, provides O(log n) search time; if unbalanced, could degrade to O(n).

### **Stack Memory vs. Heap Memory**

- **Stack Memory**: Temporary, exists within function calls.
- **Heap Memory**: Persists across function calls; must be manually managed.
- **Keyword for Heap Memory**: `new` (in languages like C++, Java, etc.).
- **Memory Leaks**: Caused by improper memory management, especially in heap allocations.

---

## **2. Data Structures and Their Uses**

### **Binary Trees**

#### **Key Terms:**

- **Root**: The topmost node.
- **Leaf**: A node with no children.
- **Inner Node**: A node with at least one child.
- **Height**: The longest path from the root to a leaf.
- **Balanced Tree**: Tree where height difference between left and right subtrees is minimized.
- **Complete Tree**: Every level is fully filled except possibly the last.
- **Full Tree**: Every node has either 0 or 2 children.
- **Predecessor & Successor**: Nodes immediately before and after a given node in an in-order traversal.
- **Sibling**: Nodes that share the same parent.
- **Ascendant & Descendant**: Nodes above and below a given node in the hierarchy.

#### **Time Complexity:**

- **Search in a Balanced BST**: O(log n)
- **Search in an Unbalanced BST**: O(n)

### **Priority Queue**

- **Definition**: A queue where elements are dequeued based on priority rather than order of arrival.
- **Uses**:
  - Task scheduling
  - Dijkstra’s shortest path algorithm (used to choose next shortest path)(**not on test!**)
  - Event-driven simulations

#### **Time Complexity:**

- **Implemented as a Binary Heap**: O(log n)
- **Implemented as an array or list**: O(n)

---

## **3. Practical Applications and Scenarios**

### **Stack and Queue Applications**

- **Website Browsing Session History**: Implemented with stacks to enable forward/backward navigation.
- **Undo Functionality in a Text Editor**: Uses a stack to revert the most recent actions first.
- **Print Job Scheduling**: Combination of queue (FIFO for standard jobs) and stack (LIFO for cancellation of recent jobs).
- **Customer Service Call Center**: Implemented with a priority queue to prioritize VIP callers.
- **Parentheses Matching in Code Editors**: Uses a stack to verify balanced parentheses.
- **Sequential Task Processing**: Managed with a queue where tasks with dependencies are processed in order.

### **Efficient Storage and Retrieval**

- **Efficient Contact Lookup**: ~Uses BST or hash table for fast retrieval.~ (**no hash tables on exam**)
- **Autocomplete Suggestions**: Uses a trie or BST for efficient searching. (**no trie's on exam**)
- **Tracking Most Visited Websites**: Hash table or BST to keep frequently accessed entries. (**no hash tables on exam**)
- **Stock Price History**: BST or array to store and retrieve prices by date efficiently.

### **Resource Allocation and Scheduling**

- **Memory Management in an OS**: Uses linked lists for dynamic allocation and deallocation.
- **Balancing Load in a Network**: Uses arrays/lists to track server loads and distribute requests.
- **Emergency Room Triage**: Uses a priority queue to handle urgent cases first.
- **Task Scheduler with Priorities**: Managed using a priority queue to execute high-priority tasks first.

### **Specialized Uses**

- **Routing in GPS Navigation**: ~~Uses a BST for location lookup and pathfinding algorithms.~~
- **AI Decision-Making in Games**: ~~Uses a tree structure to evaluate multiple decision branches.~~
- **Event Ticketing System**: Uses an array for seat reservations with direct access.
- **Playlist Management**: Uses a linked list for dynamic reordering of tracks.

### **Choosing Between Arrays and Linked Lists**

- **Advantages of Arrays**:
  - Fast random access
  - Cache-friendly
  - Lower memory overhead
- **Advantages of Linked Lists**:
  - Dynamic size allocation
  - Fast insertions/deletions in the middle
- **Trade-offs**:
  - Resizing an array is costly.
  - Linked lists have extra memory overhead due to pointers.

---

## **4. Practice Exercises**

**Given a list of unordered numbers, perform the following:**

1. Load them into an **array-based BST**.
2. Load them into a **regular BST**.
3. Load them into a **heap** (priority queue).

**Discussion Questions:**

1. Explain how a binary search tree can become unbalanced and its impact on performance.
2. Describe a real-world situation where a queue is a better choice than a stack.
3. What are the pros and cons of implementing an undo feature using a stack?
4. Given a dataset of customer transactions, which data structure would you use to quickly retrieve a customer’s most recent purchases?
5. ~~How would you implement a file system using tree structures?~~

---

### Choose Data Structure

**Available choices: Array, Linked List, Stack, Queue, Priority Queue, Binary Search Tree (BST)**

Some of these questions are better answered with more than a single data structure, but on the exam, I won't ask such questions unless I specify in the question itself and give you some hints. Others may go beyond what we currently know, and I will try and cross those out (but not delete them as not to stifle your curious minds).

1. **Real-Time Leaderboard in a Game**

   - ✅ You need to efficiently insert new scores and keep them sorted to display the top players at any time.

2. **Implementing an Undo/Redo Feature in a Text Editor**

   - ✅ Implementing an 'undo' feature in a text editor that allows users to revert their actions, one at a time, in the reverse order that they were made.
   - 📌 Which simple data structure(s) would you use to implement the 'undo' functionality and how?

3. **Task Scheduler with Varying Priorities**

   - ✅ You need a system that processes incoming tasks, but some tasks need to be executed before others based on their importance.
   - 📌 What would you implement to keep the most important things at the front of the line?

4. **Autocomplete Suggestions in a Search Bar**

   - ✅ ~~You need to store words in a way that allows efficient searching for suggestions as the user types.~~ (trie trees)

5. **Managing a Call Center’s Incoming Calls**

   - ✅ (1) Calls should be answered in the order they arrive, ensuring fairness in customer support.
   - ✅ (2) A customer service call center receives calls that are categorized into 'regular' and 'VIP'. VIP calls must be answered before regular ones, regardless of the order they come in.
   - 📌 How do you handle each scenario?

6. **Memory Management in an Operating System**

   - ✅ The system must dynamically allocate and free memory blocks of different sizes, with frequent insertions and deletions.
   - 📌 What dynamic structures might fit this bill?

7. **Web Browser Back and Forward Navigation**

   - ✅ A web browser needs to manage a user's browsing session history to support forward and backward navigation.
   - 📌 How would you design the session history feature using stacks and/or queues, and why?
   - 📌 Could you use an array or a linked list?

8. **Processing Requests to a Printer**

   - ✅ The printer should handle requests by number of pages, where shortest jobs go first.
   - 📌 Think of the least number of pages as more important.

9. **Routing System for GPS Navigation**

   - ✅ ~~You need to maintain an efficiently searchable set of locations to find the shortest path between two points.~~

10. **Stock Price History with Efficient Searching**

    - ✅ You need to store stock prices over time and allow efficient retrieval of past values based on a given date.
    - 📌 What structure is good at keeping things in order AND allows fast retreival?

11. **Organizing a Playlist with Custom Ordering**

    - ✅ Users should be able to reorder songs and insert/remove tracks frequently.
    - 📌 Based on your **current** knowledge of data structures, explain why this question is hard to answer. Reordering and frequent insertion or deletion go against each other, not only based on your current knowledge, but almost always! This is a frequent problem.

12. **AI Decision-Making in a Game**

    - ✅ ~~The AI must frequently make optimal decisions based on hierarchical conditions (e.g., enemy detection, health level).~~

13. **Efficient Contact Search in a Phonebook**

    - ✅ The system should allow rapid lookup of contacts based on names while allowing insertions and deletions.
    - 📌 What structure allows fast lookups, but also keeps things in order quite inherently?

14. **Tracking a Browser’s Most Visited Websites**

    - ✅ Frequently accessed sites should be stored and updated dynamically for fast lookup.
    - 📌 This is not straight forward, and doesn't have a single answer. Trick is to justify your answer.
    - 📌 Think of a variation of a known data structure, with some extra methods to make it work.

15. **Event Ticketing System with Seat Reservations**

    - ✅ Customers should be able to pick specific available seats from a predefined list.
    - 📌 What would allow you to remove random chosen seats from the available choices easily?

16. **Parentheses Matching**

    - ✅ A code editor needs a feature to check if all opened parentheses, brackets, and braces are correctly matched and closed.
    - 📌 Which simple data structure(s) would you use to implement this feature, and what's the logic behind it?

17. **Sequential Task Processing**

    - ✅ Tasks come into a system in a sequence where each task has a prerequisite task that must be completed first. Some tasks can only start once their specific predecessor is done.
    - 📌 How would you manage the execution order of these tasks using the simple data structures discussed?

18. **Balancing Load in a Network**

- ✅ You're tasked with designing a load balancer that evenly distributes incoming network requests to a set of servers. Upon receiving a request, the load balancer should forward it to the server with the least current load.
- 📌 Using only arrays/lists and basic operations, how would you implement a system to track and update the load on each server as requests are assigned and completed?

19. **Efficient Inventory Management**

- ✅ You are developing an inventory system for a retail store. The system frequently adds and removes items from the middle of the inventory list, but random access to item details is also needed.
- 📌 Would you use an array or a linked list to store the inventory, and why?
- 📌 Again, this is another question that contradicts itself. A classic problem of "random access" (array) vs frequent "adds and removes" (lists). You can only choose one, so what would your criteria be based on?

20. **Emergency Room Triage**

- ✅ In a hospital emergency room, patients arrive with different levels of urgency (low, med, high, and critical) where low is the least worriesome and critical is extremely urgent. Patients with higher urgency must be treated before those with less problematic conditions, even if they arrived later. However, patients with the same conditions, must be treated in the order they arrived.
- 📌 How would you handle this "two fold" ordering? It can be done in one of the data structures we discuessed, whith a little extra twist.

21. **Efficient Contact Lookup**

    - ✅ ~~A mobile phone contact list must allow users to quickly search for a contact’s phone number by typing part of their name. The list is sorted alphabetically.~~
    - 📌 ~~What algorithm would you use to efficiently retrieve a contact’s details, and why is it better than a linear search?~~
