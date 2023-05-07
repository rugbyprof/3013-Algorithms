# Study Guide - Everything you need to know

#### Due: 05-10-2023 (Wednesday @ 10:30 a.m.)

# NOT DONE NEEDS FIXING!! 

Below is a list the topics with a few additional helper items.

### Complexity:

- Time complexity analysis
- Big O notation
- Comparing the running time of different algorithms
- For example be able to look at a code snippet like the following and determine its complexity:

```cpp
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        // perform constant-time operation
    }
}

//OR

for(int i=0;i<n;i++){
    // perform constant-time operation
}

for(int j=0;j<n;j++){
    // perform constant-time operation
}
```

## Data Structures

- Stacks
- Queues
- Priority Queues (Heaps)
- Binary Search Trees
- Self-balancing Trees (AVL and Red-Black)
- Trie Trees
- Hash Tables
- Singly Linked Lists
- Doubly Linked Lists
- Circular Lists

- Choose the appropriate data structure given a posed problem to solve.

### Stacks:

- **Function call stack:** A stack is used by the computer's operating system to keep track of function calls and return addresses.
- **Expression evaluation:** A stack is used to evaluate expressions in programming languages, such as arithmetic expressions or boolean expressions.
- **Undo and redo functionality:** A stack can be used to implement undo and redo functionality in text editors or graphic design software.
- **Parenthesis matching:** A stack can be used to check whether parentheses, brackets, and braces are balanced in an expression.
- **Backtracking:** A stack can be used to implement backtracking algorithms that involve exploring all possible solutions to a problem.
- **Depth-First Search (DFS):** A stack can be used to implement DFS algorithms for traversing a graph or a tree.
- **Infix to postfix conversion:** A stack can be used to convert infix expressions to postfix expressions, which are easier to evaluate.

---

### Queues

- **Event-driven simulation:** A priority queue can be used to schedule events in an event-driven simulation, where each event has a priority and events are processed in order of their priority.
- **Dijkstra's algorithm:** A priority queue can be used to implement Dijkstra's algorithm for finding the shortest path in a weighted graph.
- **Huffman coding:** A priority queue can be used to implement Huffman coding, which is a technique for lossless data compression.
- **Job scheduling:** A priority queue can be used to schedule jobs with varying priorities, where jobs with higher priority are executed first.
- **A\* algorithm:** A priority queue can be used to implement the A\* algorithm for finding the shortest path in a graph, where the priority of each node is determined by its estimated distance to the goal node.
- **Prim's algorithm:** A priority queue can be used to implement Prim's algorithm for finding the minimum spanning tree of a weighted graph.

---

### Binary Search Trees

#### Unbalanced

- **Heaps**: A binary search tree can be used as a heap data structure to implement priority queues and heapsort.

#### Balanced

- **Symbol table:** A balanced binary search tree can be used as a symbol table to store key-value pairs, where keys are unique and can be searched efficiently.
- **Insertion and deletion of elements:** A balanced binary search tree can be used to efficiently insert and delete elements in logarithmic time complexity.
- **In-order traversal:** A balanced binary search tree can be used to traverse the tree in order, from smallest to largest key.
- **Binary search:** A balanced binary search tree can be used to perform binary search operations on the elements in the tree.
- **Sorted data storage:** A balanced binary search tree can be used to store data in a sorted order, making it easy to retrieve data in sorted order.
- **Database indexing:** A balanced binary search tree can be used as an indexing data structure to store and search for data in a database.
- **Sets and maps:** A balanced binary search tree can be used to implement sets and maps data structures, where elements are stored in sorted order and can be searched efficiently.
- **Range queries:** A balanced binary search tree can be used to efficiently perform range queries, where all elements within a certain range are retrieved.

---

### Trie trees:

Trie trees are commonly used for solving problems that involve working with sets of strings or sequences of characters. They are particularly useful for tasks that involve searching or pattern matching within large collections of strings, such as:

- **Auto-completion:** Trie trees can be used to implement an efficient auto-completion feature in text editors or search engines. As the user types each character, the trie tree is traversed to find all possible completions for the current prefix.
- **Spell checking:** Trie trees can be used to efficiently check whether a word is spelled correctly or not by searching for the word in a dictionary trie.
- **Searching for patterns:** Trie trees can be used to efficiently search for patterns in a text or set of strings. For example, finding all strings that start with a certain prefix or contain a certain substring.
- **Genome sequencing:** Trie trees can be used to efficiently store and search for DNA sequences in genome sequencing applications.
- **Internet Protocol (IP) routing:** Trie trees can be used to implement efficient IP routing algorithms for forwarding packets between routers in a computer network.

4. Graph algorithms:

   - Depth-first search (DFS) and breadth-first search (BFS)
   - Applications and use cases for DFS and BFS
   - Example: Depth first search goes away from initial start area quickly, while breadth first search concentrates on surrounding nodes.

### Spanning tree algorithms:

- Kruskal's and Prim's algorithms for minimum spanning trees
- Applications and use cases for spanning trees
- **Notes:**
  - **Kruskal's** is more advantageous for sparse graphs and it also chooses edges finding the lightest edge first since they are all sorted at the beginning and placed into a heap ordered by weight.
  - **Prim's** is more advantageous for dense graphs, but also can be utilized in cases where a spanning tree can be "grown" from a specific location, since it starts at a known place and chooses edges based on the cut between added nodes and nodes not in the spanning tree.

6. Shortest path algorithms:

   - Dijkstra's
   - Applications and use cases for spanning tree and shortest path algorithms

6) List-based vs. array-based implementations:
   - Differences between list-based and array-based data structures
   - Advantages and disadvantages of each implementation
   - Choosing the appropriate implementation for a given problem
   - Example: lists grow and shrink easily while arrays give easy access to specific array locations.

For each of these topics, students should focus on the following:

1. Understand the key concepts and definitions.
2. Study the basic algorithms and data structures, along with their time and space complexity.
3. Practice implementing the algorithms and data structures in a programming language (C++ was mentioned in our interaction).
4. Analyze the problem requirements and constraints to determine the most suitable data structure or algorithm for solving the problem.
5. Review examples and exercises related to the topics, focusing on understanding the reasons behind choosing a particular data structure or algorithm.

You are developing a maze-solving application that finds a path from the entrance to the exit. Which graph algorithm would be more suitable to use for exploring the maze and backtracking when reaching a dead end?

2. Graph Algorithms

   - Depth-First Search
   - Breadth-First Search
   - Minimum Spanning Trees (Prim's and Kruskal's Algorithms)
   - Shortest Path Algorithms (Dijkstra's and Bellman-Ford Algorithms)

3. Time Complexity

   - Big O notation
   - Understanding the performance of different data structures and algorithms
   - Comparing the time complexity of different algorithms

4. Choosing Data Structures and Algorithms

   - Understanding the trade-offs between different data structures and algorithms
   - Selecting the most appropriate data structure or algorithm for a given problem
   - List-based vs. Array-based implementations of data structures
   - Self-balancing Binary Search Trees vs. generic Binary Search Trees

5. Implementations
   - Implementing various data structures and algorithms in C++

To study for the exam, students should focus on understanding the principles and concepts behind each data structure and algorithm, as well as the advantages and disadvantages of each. They should also practice implementing these data structures and algorithms in C++ and be able to analyze the time complexity of different operations.

Be prepared to answer questions that require you to choose the most appropriate data structure or algorithm for a given problem or scenario. This includes understanding the trade-offs between different options and being able to explain their reasoning.
