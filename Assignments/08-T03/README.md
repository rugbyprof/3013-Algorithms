## Test 3 - Huffman, Hashing, Tries, Graphs
#### Due: 04-24-2024 (Wed @ 2:00 p.m.)

### Topics

- [Complexity](../../Lectures/LectureMaterials/00-Big-Oh/README.md)

## Huffman Coding

- Huffman Coding is a compression algorithm.
- It performs lossless compression. 
- It uses a binary tree as a container and a greedy algorithm to make choices as it runs. 
- You won't need to write any code on the exam, but if your curious:  https://replit.com/@rugbyprof/3013huffmansp23#main.cpp
- Huffman Trees create binary codes based on the frequency of occuring letters or symbols in which the most occuring letters get the smallest binary string (since they occur more).
  - Below is a somewhat contrived example using "War and Peace" and only keeping the letters and the space character and showing the encoding for letter. We won't do anything like this on the exam, this is just a full size(ish) example. 

| Letter | Code            |
| :----: | :-------------- |
|   e    | 011             |
|  ' '   | 111             |
|   d    | 0010            |
|   r    | 0101            |
|   s    | 1000            |
|   h    | 1001            |
|   i    | 1010            |
|   n    | 1011            |
|   o    | 1100            |
|   a    | 1110            |
|   t    | 1111            |
|   f    | 00001           |
|   w    | 00010           |
|   m    | 00011           |
|   c    | 00110           |
|   u    | 01000           |
|   l    | 11011           |
|   v    | 000000          |
|   b    | 001110          |
|   p    | 010010          |
|   y    | 110100          |
|   g    | 110101          |
|   k    | 0100110         |
|   P    | 00000100        |
|   A    | 00000101        |
|   T    | 00000111        |
|   I    | 00111110        |
|   M    | 000001100       |
|   B    | 001111000       |
|   N    | 001111001       |
|   x    | 001111010       |
|   H    | 001111111       |
|   O    | 0000011010      |
|   F    | 0011110110      |
|   D    | 0011110111      |
|   C    | 0011111100      |
|   E    | 0011111101      |
|   j    | 0100111000      |
|   z    | 0100111001      |
|   q    | 0100111010      |
|   W    | 0100111101      |
|   S    | 0100111110      |
|   R    | 0100111111      |
|   V    | 00000110111     |
|   K    | 01001110110     |
|   Y    | 01001110111     |
|   G    | 01001111000     |
|   J    | 000001101100    |
|   X    | 010011110010    |
|   L    | 010011110011    |
|   U    | 0000011011011   |
|   Q    | 00000110110100  |
|   Z    | 00000110110101' |

- On the exam, I will give you a small alphabet and have you create your own Huffman codes. 
- For example the words below: 
  - **`bat hat fat smart smack smear smoke`**
- Give us the following letter breakdown:
  - `aaaaaattttssssmmmmrrkkeebhfco`
- Which when counted out gives us the following frequency table: 

| letter | frequency |
| :----: | :-------: |
|   a    |     6     |
|   t    |     4     |
|   s    |     4     |
|   m    |     4     |
|   r    |     2     |
|   k    |     2     |
|   e    |     2     |
|   b    |     1     |
|   h    |     1     |
|   f    |     1     |
|   c    |     1     |
|   o    |     1     |

### Actual Algorithm

#### 1. **Prepare Frequency List**
   - Create a list of nodes, where each node represents a character and its associated frequency. Each node is initially considered a leaf node in the Huffman Tree (we have one above).

#### 2. **Sort Nodes**
   - Sort the list of nodes in ascending order based on their frequencies. This can be done using any stable sorting method (again, already done.)

> BONUS QUESTION: What is a "stable sort"? 

#### 3. **Create the Huffman Tree**
   - While there are more than one node in the list, perform the following steps:
     - **Select the Two Nodes with the Lowest Frequencies**: These will be the first two nodes in the sorted list because it is sorted in ascending order.
     - **Create a New Node**:
       - The new node will have a frequency equal to the sum of the frequencies of the two selected nodes.
       - Assign the first selected node as the left child and the second selected node as the right child of the new node.
     - **Remove the Two Selected Nodes from the List**: They are now part of the newly created node.
     - **Insert the New Node Back into the List**: Place this node in the correct position to maintain the order by frequency.
     - **Re-sort the List if Necessary**: Ensure the list is sorted by frequency. Efficient methods might update the position iteratively or use a data structure that maintains order automatically, like a priority queue.
     
#### 4. **Resulting Tree**
   - The last remaining node in the list becomes the root of the Huffman Tree. At this point, all characters are represented as leaves of the tree, with their paths from the root defining their corresponding Huffman codes.

#### 5. **Generate Huffman Codes**
   - To generate Huffman codes for each character:
     - Start from the root and traverse to each leaf. Use a depth-first search.
     - Assign a '0' for every left branch taken and a '1' for every right branch.
     - The sequence of '0's and '1's from the root to a leaf node forms the Huffman code for the character at that leaf.

#### 6. **Code Optimization (Optional)**
   - Review the tree for any possible optimizations, such as adjusting the structure to reduce the depth of frequently used characters, which could help in reducing the overall cost of the tree.

#### 7. **Testing and Validation**
   - Verify the tree by encoding some sample text and checking if the encoded version is as compact as expected.
   - Test decoding the encoded text to ensure it correctly translates back to the original text using the Huffman Tree.

#### 8. Verify Your Tree 
  - Cut and paste the words being used **`bat hat fat smart smack smear smoke`**
  - Or these letters: `aaaaaattttssssmmmmrrkkeebhfco`
  - At this site: https://cmps-people.ok.ubc.ca/ylucet/DS/Huffman.html to visualize tree creation

#### Complexity
    - [https://en.wikipedia.org/wiki/Huffman_coding#Basic_technique](https://en.wikipedia.org/wiki/Huffman_coding#Basic_technique)

#### Question
  1. Given a small sentence, 
  2. calculate the frequencies of the letters, 
  3. build a tree, 
  4. get binary encoding for each letter
  5. write out your binary encoded answer

## Trie Trees

  - https://en.wikipedia.org/wiki/Trie

  - [Trie Trees](prefix trees)

## Hashing
    - Avalanche
    - Table Size. Typical choices of table size (load factor). 
    - Why is table size important especially when using open addressing? 
    - What is Clustering and how does it effect performance?
    - What is Secondary Clustering?
    - You don't need to know all the hash functions listed in my study guide, just understand what components make a good hash function (see below).
    - Hashing Strings
    - Open Addressing (3 types)
    - Chaining
    - Can chaining have a load facter over 1? Why?
  
### Good Hash Function

Here are some key characteristics that make a good hash function for use in hash tables or cryptography:

1. **Uniform Distribution**: It should distribute entries uniformly across the hash table to minimize collisions.
2. **Deterministic**: The same input must always yield the same output every time it is processed.
3. **Fast Computation**: It should be quick to compute, providing efficient performance even with large inputs.
4. **Non-Invertibility**: For **cryptographic** uses, it should be hard (ideally impossible) to reverse-engineer the original input from the hash output (pre-image resistance). Again, this is for cryptographic hashing when trying to protect data.
5. **Avalanche Effect**: A small change in the input should result in a significantly different hash, spreading the outputs widely. Has a lot to do with bit manipulation. 
6. **Collision Resistance**: It should be hard to find two different inputs that produce the same hash key (collide).
7. **Minimal Collision**: In non-cryptographic contexts, the function should minimize the number of collisions even if absolute collision resistance isn't achievable. 
8. **Cluster Resistant**: Fits with a few of the above terms. Again, I will ask, how does clustering effect a hash functions perfoormance?

### Open Addressing Collision Resolution Techniques

Open addressing resolves collisions by finding another open slot within the hash table itself for the item that caused the collision. Here are the most commonly used open addressing strategies:

1. **Linear Probing**:
   - **Description**: When a collision occurs, linear probing checks the next slot, and then the slot after that, and so on, in a linear sequence, until an empty slot is found.
   - **Primary Issue**: This method can lead to clustering, where a group of consecutive slots gets filled, increasing the chance of collisions and reducing hash table efficiency.

2. **Quadratic Probing**:
   - **Description**: Similar to linear probing, but instead of checking consecutive slots, it checks slots by adding increasingly large squares of integers (1, 4, 9, etc.) to the original hash index.
   - **Benefit**: Reduces the clustering problem seen in linear probing by spreading out the probe locations.
Quadratic probing is a collision resolution method in hash tables that resolves collisions by trying to place a colliding item into the next available slot based on a quadratic function of the number of attempts already made. Here is the general formula used in quadratic probing:

### Formula for Quadratic Probing

When a collision occurs, quadratic probing uses the following formula to find the next slot:

<img src="https://images2.imgbox.com/8c/73/vJgCUPzC_o.png">

Where:
- <img src="https://images2.imgbox.com/c3/57/BSQpKkk7_o.png">is the hash function for the *i*-th probe.
- <img src="https://images2.imgbox.com/11/f5/DPtuMTXi_o.png"> is the initial hash function, often a simple modulo operation \( h'(k) = k \mod m \).
- c<sub>1</sub> and c<sub>2</sub> are constants. Typically, c<sub>1</sub> = 1 and c<sub>2</sub> = 1 are common choices, but these can vary depending on the specific implementation to ensure good dispersion.
- *i* is the index of the probe, starting from 0 and increasing by 1 with each subsequent probe until an open slot is found or a loop is detected.
- *m* is the size of the hash table.

### Example

Let’s say your initial hash function <img src="https://images2.imgbox.com/11/f5/DPtuMTXi_o.png">  simply computes *k mod 10*. If a collision occurs at the slot for *k*, the next slots to try would be computed as follows for the first few attempts:
- First probe <img src="https://images2.imgbox.com/9e/3f/ItENd07X_o.png">
- Second probe <img src="https://images2.imgbox.com/13/92/VykhTlnJ_o.png">
- Third probe <img src="https://images2.imgbox.com/bf/28/IEoTuxeP_o.png">





### Notes on Quadratic Probing

- **Secondary Clustering**: Unlike linear probing, which suffers from primary clustering where long runs of occupied slots build up, quadratic probing tends to have less clustering. However, it can still experience secondary clustering, where different keys that hash to the same initial slot follow the same probe sequence.
  
- **Cycle Problem**: The choice of \( c_1 \), \( c_2 \), and \( m \) needs to be such that the probe sequence does not cycle back to previously tried slots before all slots have been tried. This can be particularly challenging to manage, especially in tables that are close to full.

- **Optimal Table Size**: For certain configurations, especially where *m* (table size) is prime, quadratic probing can explore all slots without cycling prematurely, thereby ensuring that if the table is not full, the item can be placed.

Quadratic probing offers a good trade-off between complexity and performance and is effective at distributing hash collisions in a table. However, the choice of parameters and table size needs careful consideration to avoid cycling and ensure that all slots are potentially accessible.
   
1. **Double Hashing**:
   - **Description**: Uses a second hash function to determine the probe sequence when a collision occurs. The distance to the next slot is calculated using this second hash function.
   - **Benefit**: Provides one of the best performances for open addressing by minimizing clustering and providing high probe dispersal.

### Relationship to Chaining

Unlike open addressing, **chaining** handles collisions by maintaining a linked list of all elements that hash to the same slot. Each slot in the hash table points to the head of a linked list of entries that collide at this hash index.

- **Differences**: Chaining allows the hash table to remain efficient even under high load factors because it simply adds more nodes to the existing lists. In contrast, open addressing might require rehashing to a larger table size as it fills up, because once the table becomes too full, performance degrades significantly.
- **Load Factor Consideration**: Open addressing usually performs well when the load factor (the ratio of the number of elements to the table size) is below 0.7 or 0.8. Beyond this, performance decreases due to too many collisions requiring resolution. Chaining can handle higher load factors more gracefully.

### Can Chaining Have a Load Factor Larger Than 1?

Yes, chaining can indeed have a load factor greater than 1. The load factor is calculated as the number of stored entries divided by the number of slots in the hash table. In chaining, each slot in the table points to a potentially empty or non-empty linked list. When the total number of entries exceeds the number of slots (e.g., more entries than slots), the load factor exceeds 1.

- **Implications**: A load factor greater than 1 implies that the average length of the lists is greater than 1. This is typically acceptable with chaining, as the primary degradation in performance comes from the length of these lists rather than the filling of the slots themselves.
- **Performance**: Although chaining can operate with a load factor greater than 1, the average lookup time increases linearly with the average list length. For optimal performance, it's still advisable to keep the load factor at or below 1, or consider rehashing to a larger table if performance becomes an issue due to very long chains.

In summary, open addressing and chaining represent two fundamentally different approaches to handling collisions in hash tables. Open addressing tries to find another slot within the table, while chaining stores collisions directly in linked lists at each hash index, allowing for easier handling of high load factors but potentially at the cost of increased lookup time if the chains become too long.

#### Applied Hashing

Sure! Here's a comprehensive hashing problem that you can present to your students. This problem will involve using a simple hash function, choosing an appropriate table size, and applying different collision resolution techniques, including linear probing, quadratic probing, and chaining. This will help students understand the practical applications and differences between these methods.

### Hashing Problem Statement

**Objective**: Use the given hash function and list of values to populate a hash table. Determine an appropriate table size based on the values and the collision resolution technique. Then, apply linear probing, quadratic probing, and chaining to manage collisions.

**Given**:
- **Hash Function**: <img src="https://images2.imgbox.com/38/05/w0lxMnpW_o.png">
- **Values to Insert**: [15, 25, 35, 20, 50, 60, 75, 40, 30, 55]

#### Tasks:

1. **Determine the Table Size**: Based on the provided values, recommend an appropriate table size that you think will minimize collisions while remaining efficient. You can see above and below that the numbers are all divisible by 5 and all the example table sizes are 10. You may want to change the table size, which in turn changes the table size.

2. **Populate the Hash Table Using Different Collision Resolution Techniques**:
   - **Linear Probing**
   - **Quadratic Probing**
   - **Chaining**

   For each technique, provide the final state of the hash table.


**Empty Table Template**:

```
+----+----+----+----+----+----+----+----+----+----+
| 0  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  |
+----+----+----+----+----+----+----+----+----+----+
|    |    |    |    |    |    |    |    |    |    |
+----+----+----+----+----+----+----+----+----+----+
```

**Linear Probing Start** 
```
+----+----+----+----+----+----+----+----+----+----+
| 0  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  |
+----+----+----+----+----+----+----+----+----+----+
|    |    |    |    |    | 15 | 25 | 35 |    |    |
+----+----+----+----+----+----+----+----+----+----+
```

**Quadratic Probing Start** (for the same elements):

```
+----+----+----+----+----+----+----+----+----+----+
| 0  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  |
+----+----+----+----+----+----+----+----+----+----+
|    |    |    | 15 | 25 |    | 35 |    |    |    |
+----+----+----+----+----+----+----+----+----+----+
```

**Chaining Example**:

```txt
+----+
| 0  | 
+----+
| 1  |
+----+
| 2  |
+----+
| 3  |->15->25->35
+----+
| 4  |
+----+
| 5  | 
+----+
| 6  |
+----+
| 7  |
+----+
| 8  |
+----+
| 9  |
+----+
```

### Instructions for Students

- **Explain your choice** for the table size and how each collision resolution technique affects where you place each number.
- **Fill in the hash tables** for each method using ASCII art or similar representation.
- **Discuss the pros and cons** of each method given the scenario.

This problem encourages critical

 thinking about hash table design and collision resolution, giving students practical experience with these key data structures.

## Graph Terms

   1. **Vertex (Node)**: The main component in a graph. Stores data.
   2. **Edge (Link)**: A connection between two vertices in a graph, connects related vertices and can have its own associated value (typically called edge weight).
   3. **Adjacent**: Two vertices are adjacent if there is an edge connecting them. (Also **incident** ... stupid word).
   4. **Degree**: The number of edges connected to a vertex.
   5.  **Directed Graph (Digraph)**: A graph where edges have a direction, indicating a one-way relationship between vertices.
   6. **Undirected Graph**: A graph where edges do not have a direction, indicating a two-way relationship between vertices.
   7. **In Degree**: In a directed graph, this is the number of edges __________________________?
   8. **Out Degree**: In a directed graph, this is the number of edges _________________________?
   9. **Path**: A sequence of edges that allows you to go from one vertex to another. 
      -  List 3 shortest path algorithms 1) Dijkstra's  2)______________ 3) _______________.
   10. **Cycle**: A path that starts and ends at the same vertex without repeating any edges or vertices.

   11.  **Weighted Graph**: A graph where edges have weights or values associated with them, often representing costs, lengths, or capacities.
   12. **Unweighted Graph**: A graph where all edges are of equal value.
   13. **Connected Graph**: An undirected graph in which there is a path between every pair of vertices.
   14. **Strongly Connected Graph**: A directed graph in which there is a directed path from any vertex to every other vertex.
   15. **Weakly Connected Graph**: A directed graph where replacing all of its directed edges with undirected edges produces a connected (undirected) graph.
   16. **Acyclic Graph**: A graph containing no cycles.
   17. **Cyclic Graph**: A graph that contains at least one cycle.
   18. **Graph Traversal**: The process of visiting every vertex in a graph.
   19. **Breadth-First Search (BFS)**: A traversal approach where you start at the tree root (or some arbitrary node) and explore each neighbor before going on to any of their children.
   20. **Depth-First Search (DFS)**: A traversal method where you start at the tree root (or some arbitrary node) and explore as far as possible along each branch before backtracking.
   21. **Subgraph**: A graph whose set of nodes and edges are a subset of another graph.
   22. **Spanning Tree**: A subgraph which is a tree and connects all the vertices together without any cycles.
   23. **Minimum Spanning Tree (MST)**: A spanning tree with weight less than or equal to the weight of every other spanning tree.
   24. **Graph Isomorphism**: A condition where two graphs contain the same number of graph vertices connected in the same way. Find one or two nuggets of information that determining if two graphs are isomorphic will tell us.


### Edge Count in Graphs

We had a discussion in class about "strongly connected" vs "weak" or "sparsely connected", so I had to get some clarification. 

1. **Fully Connected Graph (Complete Graph)**:
   - **Undirected Graph**: Has <img src="https://images2.imgbox.com/92/71/evSZ3pOK_o.png"  height=30> edges, where \(V\) is the number of vertices.
   - **Directed Graph**: Has <img src="https://images2.imgbox.com/91/f0/GW3MfNcO_o.png" height=15> edges, as each pair of vertices has two directed edges (one in each direction).
   - Each vertex in a complete graph has a degree of *V-1*.

2. **Sparse vs. Dense Graphs**:
   - A **sparse graph** is a graph in which the number of edges is much less than the maximum number of edges. Typically, the edge count might be close to the number of vertices, often *O(V)* or a small multiple thereof.
   - A **dense graph** is one where the number of edges is close to the maximum number of edges, which for undirected graphs is <img src="https://images2.imgbox.com/92/71/evSZ3pOK_o.png" height=30>.

There isn't a strict numerical threshold that divides sparse from dense graphs as it often depends on the context of the application and the specific characteristics of the graph being handled.

### Graph Connectivity

- **Strongly Connected**: In the context of **directed graphs**, a graph is strongly connected if there is a directed path from any vertex to every other vertex in the graph. This implies that from any point, you can reach any other point following the direction of the edges.

- **Weakly Connected**: A directed graph is weakly connected if replacing all of its directed edges with undirected edges results in a connected (undirected) graph. Essentially, a weakly connected graph becomes connected if the direction of its edges is ignored.

### Graph Representation

When deciding how to represent a graph in code, consider the following based on the connectivity and the edge count:

1. **Adjacency Matrix**:
   - Suitable for dense graphs or graphs where quick edge lookup (to check if an edge exists between two vertices) is frequently necessary.
   - Space complexity is always <img src="https://images2.imgbox.com/5d/9d/KBl9Kyva_o.png" height=20>, which can be costly for large, sparse graphs.

2. **Adjacency List**:
   - Efficient for sparse graphs as it reduces memory usage when there are relatively few edges.
   - Space complexity is <img src="https://images2.imgbox.com/2a/36/3qFfPQf0_o.png" height=18>, which is beneficial when *E* is much less than V<sup>2</sup>.

3. **Edge List**:
   - A simple list of edges, which is rarely used alone but can be useful for certain edge-centric algorithms or when the graph needs to be sorted or frequently manipulated by edge properties.
   - This representation is also space-efficient for very sparse graphs.

### Example Scenarios

- If you’re implementing an algorithm like Dijkstra's shortest path, which benefits from quick access to all neighbors but does not require checking for the existence of specific edges frequently, an adjacency list would typically be preferred due to its space efficiency and direct neighbor access.
- For algorithms that need to frequently check the presence of an edge between any two vertices, such as checking for subgraphs or completing certain types of clustering, an adjacency matrix might be preferred despite its higher space cost.

Choosing the right representation and understanding the connectivity of your graph are crucial for implementing efficient and effective graph algorithms.