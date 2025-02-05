## Test 1 - Various Topics

#### Due: 02-12-2025 (Wed @ 2:00)

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
  - Dijkstra’s shortest path algorithm
  - Event-driven simulations

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

- **Efficient Contact Lookup**: Uses BST or hash table for fast retrieval.
- **Autocomplete Suggestions**: Uses a trie or BST for efficient searching.
- **Tracking Most Visited Websites**: Hash table or BST to keep frequently accessed entries.
- **Stock Price History**: BST or array to store and retrieve prices by date efficiently.

### **Resource Allocation and Scheduling**

- **Memory Management in an OS**: Uses linked lists for dynamic allocation and deallocation.
- **Balancing Load in a Network**: Uses arrays/lists to track server loads and distribute requests.
- **Emergency Room Triage**: Uses a priority queue to handle urgent cases first.
- **Task Scheduler with Priorities**: Managed using a priority queue to execute high-priority tasks first.

### **Specialized Uses**

- **Routing in GPS Navigation**: Uses a BST for location lookup and pathfinding algorithms.
- **AI Decision-Making in Games**: Uses a tree structure to evaluate multiple decision branches.
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
3. Load them into a **priority queue**.

**Discussion Questions:**

1. Explain how a binary search tree can become unbalanced and its impact on performance.
2. Describe a real-world situation where a queue is a better choice than a stack.
3. What are the pros and cons of implementing an undo feature using a stack?
4. Given a dataset of customer transactions, which data structure would you use to quickly retrieve a customer’s most recent purchase?
5. How would you implement a file system using tree structures?

---

### Choose Data Structure

**Available choices: Array, Linked List, Stack, Queue, Priority Queue, Binary Search Tree (BST)**

1. Real-Time Leaderboard in a Game

- 📌 You need to efficiently insert new scores and keep them sorted to display the top players at any time.

2. Implementing an Undo/Redo Feature in a Text Editor

- 📌 The application must support multiple undo and redo actions, where the most recent action is undone first.

3. Task Scheduler with Varying Priorities

- 📌 You need a system that processes incoming tasks, but some tasks need to be executed before others based on their priority.

4. Autocomplete Suggestions in a Search Bar

- 📌 You need to store words in a way that allows efficient searching for suggestions as the user types.

5. Managing a Call Center’s Incoming Calls

- 📌 Calls should be answered in the order they arrive, ensuring fairness in customer support.

6. Memory Management in an Operating System

- 📌 The system must dynamically allocate and free memory blocks of different sizes, with frequent insertions and deletions.

7. Web Browser Back and Forward Navigation

- 📌 The browser should allow users to navigate back to the previous page and forward again when needed.

8. Processing Requests to a Printer

- 📌 The printer should handle requests in the order they arrive, but priority should be given to urgent documents.

9. Routing System for GPS Navigation

- 📌 You need to maintain an efficiently searchable set of locations to find the shortest path between two points.

10. Stock Price History with Efficient Searching

- 📌 You need to store stock prices over time and allow efficient retrieval of past values based on a given date.

11. Organizing a Playlist with Custom Ordering

- 📌 Users should be able to reorder songs and insert/remove tracks frequently.

12. AI Decision-Making in a Game

- 📌 The AI must frequently make optimal decisions based on hierarchical conditions (e.g., enemy detection, health level).

13. Efficient Contact Search in a Phonebook

- 📌 The system should allow rapid lookup of contacts based on names while allowing insertions and deletions.

14. Tracking a Browser’s Most Visited Websites

- 📌 Frequently accessed sites should be stored and updated dynamically for fast lookup.

15. Event Ticketing System with Seat Reservations

- 📌 Customers should be able to pick specific available seats from a predefined list.

---

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

**Balancing Load in a Network**

- **Situation**: You're tasked with designing a load balancer that evenly distributes incoming network requests to a set of servers. Upon receiving a request, the load balancer should forward it to the server with the least current load.
- **Question**: Using only arrays/lists and basic operations, how would you implement a system to track and update the load on each server as requests are assigned and completed?

**Efficient Inventory Management**

- **Situation:** You are developing an inventory system for a retail store. The system frequently adds and removes items from the middle of the inventory list, but random access to item details is also needed.

- **Question:** Would you use an array or a linked list to store the inventory, and why?

**Print Job Scheduling**

- **Situation:** A shared office printer receives print jobs from multiple users. Some jobs must be printed in the order they were received, but there is also an option for users to cancel their most recently submitted job before it starts printing.

- **Question:** Which data structure(s) (stack, queue, or both) would you use to manage print jobs efficiently, and how would you handle cancellations?

**Emergency Room Triage**

- **Situation:** In a hospital emergency room, patients arrive with different levels of urgency. Critical patients must be treated before those with minor conditions, even if they arrived later.

- **Question:** Which data structure would you use to manage patient intake, ensuring that the most urgent cases are attended to first while still allowing new patients to arrive dynamically?

**Efficient Contact Lookup**

- **Situation:** A mobile phone contact list must allow users to quickly search for a contact’s phone number by typing part of their name. The list is sorted alphabetically.

- **Question:** What algorithm would you use to efficiently retrieve a contact’s details, and why is it better than a linear search?
