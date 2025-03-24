## Test 2 - Various Topics

#### Due: 03-26-2025 (Wed @ 2:00)

## Expanded Topics and Subtopics

---

<!-- ## Balanced Trees
- **Definition and Motivation**
  - What are balanced trees?
  - Advantages over unbalanced trees (e.g., performance guarantees).
- **Types of Balanced Trees**
  - AVL Trees
  - Red-Black Trees
  - B-Trees and B+ Trees
  - Splay Trees and Treaps
- **Operations and Complexity**
  - Insertion, deletion, and search complexity.
  - Rebalancing techniques and rotations.
- **Applications**
  - Database indexing
  - Memory management
  - Compiler design
- **Comparison with Other Data Structures**
  - Trade-offs with hash tables, binary search trees, etc.
- **History and Evolution**
  - Key milestones in the development of balanced tree algorithms.

--- -->

## Consistent Topics

- There will always be questions about

## AVL Tree

- **Definition and Motivation**
  - What are balanced trees?
  - Advantages over unbalanced trees (e.g., performance guarantees).
- **Introduction and Properties**
  - Definition and history of AVL trees.
  - Balance factor and its significance.
- **Rotations and Rebalancing**
  - Single and double rotations (LL, RR, LR, RL cases).
  - Algorithm for insertion and deletion.
- **Performance Analysis**
  - Time complexity of operations.
  - Comparison with other balanced trees.
- **Use Cases and Applications**
  - Scenarios where AVL trees are preferred.
- **Limitations**
  - Overhead of rebalancing
  - Memory usage compared to simpler trees.

title: "AVL Tree Study Guide"
description: "Expanded notes and explanations to support students learning about AVL trees, including their definition, mechanics, and trade-offs."
author: "ChatGPT"
audience: "Students preparing for exams on data structures and algorithms"

Hey Terry, below is an expanded AVL Tree study guide your students can use. It covers core concepts, rotation mechanics, time complexities, and trade-offs—basically most of what they need to tackle your exams confidently without buying a $200 doorstop.

⸻

## 📘 AVL Trees Study Guide

⸻

### 🧠 1. Definition and Motivation

#### What are balanced trees?

- A balanced tree is a binary tree where the height difference between left and right subtrees is kept in check.
- In AVL trees, this means for every node, the height of the left and right subtrees differs by at most 1.

#### Why do we care?

- Because search, insertion, and deletion operations in unbalanced binary search trees (BSTs) can degrade to O(n) in the worst case (e.g., a degenerate tree that’s just a linked list).
- Balanced trees like AVL maintain O(log n) time for operations even in the worst case.

⸻

### 🌳 2. Introduction and Properties

#### Definition

- An AVL tree is a self-balancing binary search tree.
- Named after Adelson-Velsky and Landis, who introduced it in 1962.
- First tree-based structure that ensured balance after every insertion and deletion.

#### Balance Factor (BF)

- Defined as:
  $\text{BF} = \text{height(left subtree)} - \text{height(right subtree)}$
- Valid balance factors for AVL nodes: $–1, 0, 1$
- If the balance factor becomes $< –1 or > 1$, the tree needs to be rebalanced using rotations.

⸻

### 🔁 3. Rotations and Rebalancing

#### Why rotate?

- Rotations are used to restore AVL balance after insertion or deletion messes it up.

#### Single Rotations:

1. LL (Left-Left): Heavy on left child’s left.
   - Fix with a right rotation.
2. RR (Right-Right): Heavy on right child’s right.
   - Fix with a left rotation.

#### Double Rotations:

3. LR (Left-Right): Left child is heavy on its right.

   - Fix with left rotation on child, then right rotation on parent.

4. RL (Right-Left): Right child is heavy on its left.

   - Fix with right rotation on child, then left rotation on parent.

#### Insertion Algorithm (high-level steps):

1. Insert as you would in a BST.
2. Walk back up and update heights.
3. Check balance factor.
4. If node is unbalanced, identify LL, RR, LR, or RL and rotate accordingly.

#### Deletion Algorithm:

- Similar to BST deletion.
- After deletion, walk up and rebalance where necessary.
- May trigger multiple rebalancing operations up the tree.

⸻

### 📈 4. Performance Analysis

| Operation | Time Complexity |
| :-------- | :-------------- |
| Search    | O(log n)        |
| Insertion | O(log n)        |
| Deletion  | O(log n)        |
| Rotation  | (single) O(1)   |

#### Why O(log n)?

- AVL trees are always balanced, which means the height is logarithmic in the number of nodes:
  $h(n) \leq 1.44 \cdot \log_2(n + 2) - 0.328$

#### Compared to Other Trees:

- `Red-Black Trees`: Slightly faster inserts/deletes on average, but AVL trees are more strictly balanced → better for read-heavy workloads.
- `Unbalanced BSTs`: Only good if data is randomly distributed (and even then, dangerous).

⸻

### 🛠️ 5. Use Cases and Applications

#### When should I use AVL trees?

- When you need fast lookups and data is frequently read, not just inserted/deleted.
- Ideal for:
  - Databases where reads dominate.
  - Memory-constrained applications where predictable performance is critical.
  - Search engines, dictionary data, caches.

⸻

### ⚠️ 6. Limitations

#### Rebalancing Overhead

- AVL trees do more work to stay balanced. After insertion or deletion, rotations and height recalculations may propagate up the tree.
- While each rotation is O(1), total overhead for an insertion or deletion can reach O(log n).

#### Memory Usage

- Each node stores extra height or balance factor info → slightly more memory per node than basic BSTs.

#### Insert/Delete Speed

- Insertion and deletion are slower than Red-Black trees due to strict balancing.

⸻

### 📝 Sample Review Questions

1. True or False: Every AVL tree is a binary search tree.
2. What is the maximum allowed balance factor of a node in an AVL tree?
3. After inserting into an AVL tree, the balance factor of a node is –2. What type of rotation is needed?
4. Why might AVL trees perform better than Red-Black trees for search-heavy applications?
5. What is the worst-case height of an AVL tree with n nodes?

Stay balanced, just like an AVL tree 😄🌲

---

## Graph Algorithms

- **Fundamentals of Graph Theory**
  - Definitions (vertices, edges, weighted vs unweighted, directed vs undirected).
  - Representations (adjacency matrix, list, edge list).
- **Traversal Techniques**
  - Overview of search algorithms (DFS, BFS).
- **Shortest Path Algorithms**
  - Concepts of weighted graphs and path relaxation.
- **Minimum Spanning Tree (MST) Algorithms**
  - Overview and applications.
- **Connectivity and Components**
  - Strongly connected components
  - Bipartite graphs
- **Complexity Analysis**
  - Time and space complexity for various graph representations.
- **Historical Context**
  - Evolution of graph algorithms and their impact on computer science.

Below is some expanded info covering core concepts in graph theory.

⸻

## 📘 AGraph Theory Study Guide

### 1. Fundamentals of Graph Theory

- Vertices and Edges
  - Vertices (Nodes): Fundamental units representing entities (e.g., cities, network nodes).
  - Edges (Links): Connections between vertices. They may represent roads, communication links, etc.
- Weighted vs. Unweighted Graphs
  - Weighted Graphs: Each edge carries a numerical value (weight) indicating cost, distance, or capacity.
  - Unweighted Graphs: Edges are considered equal; the focus is on connectivity rather than cost.
- Directed vs. Undirected Graphs
  - Directed Graphs (Digraphs): Edges have direction, meaning the connection is one-way.
  - Undirected Graphs: Edges imply a two-way, mutual relationship between vertices.

⸻

### 2. Graph Representations

- **Adjacency Matrix**
  - A 2D array where the element at row i and column j indicates the presence (and possibly the weight) of an edge from vertex i to vertex j.
  - Pros: O(1) edge look-up.
  - Cons: Requires $O(V^2)$ space, which can be inefficient for sparse graphs.
- **Adjacency List**
  - An array or list where each element (vertex) holds a list of its adjacent vertices (and edge weights, if applicable).
  - Pros: Efficient for sparse graphs with O(V + E) space.
  - Cons: Checking the existence of a specific edge may take O(degree).
- **Edge List**
  - A simple list of edges, where each edge is a pair (or triple, if weighted) representing the connection between vertices.
  - Pros: Simple structure; good for algorithms that process all edges (like Kruskal’s).
  - Cons: Less efficient for neighbor queries.

⸻

### 3. Traversal Techniques

- **Depth-First Search (DFS)**:
  - Method: Uses recursion or an explicit stack to explore as far as possible along one branch before backtracking.
  - Applications: Cycle detection, topological sorting, and exploring connected components.
- **Breadth-First Search (BFS)**:
  - Method: Uses a queue to explore all neighbors of a vertex before moving to the next level.
  - Applications: Shortest path in unweighted graphs, level order traversal, and checking bipartiteness.

⸻

### 4. Shortest Path Algorithms

- **Weighted Graph Concepts:**
  - Path Relaxation: The process of updating the best-known distance to a vertex if a shorter path is found.
- **Key Algorithms:**
  - Dijkstra’s Algorithm: Efficiently finds the shortest path from a single source to all other vertices in a graph with non-negative weights.
  - Bellman-Ford Algorithm: Works even with negative edge weights (provided there are no negative cycles) and also detects negative cycles.

⸻

### 5. Minimum Spanning Tree (MST) Algorithms

- **Overview:**
  - An MST connects all vertices with the minimum possible total edge weight.
- **Key Algorithms:**
  - Kruskal’s Algorithm: Sorts edges by weight and uses a union-find structure to avoid cycles.
  - Prim’s Algorithm: Starts from a single vertex and grows the MST by adding the smallest edge connecting the tree to a new vertex.
- **Applications:**
  - Network design, clustering, and cost minimization problems.

⸻

### 6. Connectivity and Components

- **Strongly Connected Components (SCC):**
  - In directed graphs, SCCs are subgraphs where every vertex is reachable from every other vertex.
  - Algorithms: Kosaraju’s, Tarjan’s, and Gabow’s algorithms are commonly used.
- B**ipartite Graphs:**
  - A graph whose vertices can be divided into two disjoint sets such that every edge connects a vertex from one set to the other.
  - Detection: BFS or DFS with a coloring method can check bipartiteness.

⸻

### 7. Complexity Analysis

- **Adjacency Matrix:**
  - Space: $O(V^2)$
  - Edge Check: $O(1)$
  - Iteration over Neighbors: $O(V)$ per vertex
- **Adjacency List:**
  - Space: $O(V + E)$
  - Edge Check: $O(degree)$ per vertex
  - Iteration over Neighbors: Efficient for sparse graphs
- **Edge List:**
  - Space: $O(E)$
  - Processing: Often requires sorting, so operations can be $O(E \log E)$
- A**lgorithm Complexities:**
  - DFS/BFS: $O(V + E)$
  - Dijkstra’s: $O((V + E) \log V)$ using a binary heap (can vary based on data structures)
  - MST (Kruskal’s): $O(E \log E)$ or $O(E \log V)$
  - MST (Prim’s): $O((V + E) \log V)$ with a priority queue

⸻

### 8. Historical Context

- **Evolution of Graph Algorithms:**
  - Early work in graph theory can be traced back to Euler’s solution to the Seven Bridges of Königsberg.
  - Modern graph algorithms were developed in the mid-20th century, with landmark algorithms like Dijkstra’s (1959) and Ford-Fulkerson (1956).
  - These algorithms have paved the way for advancements in network routing, operations research, and many applied areas of computer science.
- **Impact on Computer Science:**
  - Graph algorithms are foundational in many domains such as social network analysis, web page ranking, scheduling, and bioinformatics.
  - The evolution of these algorithms has driven significant improvements in efficiency and resource management in computer systems.

---

## Depth First Search (DFS)

- **Concept and Intuition**
  - How DFS works (recursion and stack-based approaches).
  - Traversal order and backtracking.
- **Applications**
  - Path finding
  - Topological sorting
  - Cycle detection in graphs
  - Solving puzzles and mazes
- **Variants**
  - Recursive vs. iterative implementations.
  - DFS in tree structures vs. general graphs.
- **Complexity and Performance**
  - Time and space complexity.
- **Related Concepts**
  - Graph connectivity
  - Strongly connected components (Tarjan’s algorithm, Kosaraju’s algorithm)

## 📘 DFS Study Guide

### Concept and Intuition

- **How DFS Works:**
  - **Exploration**: DFS dives deep into a graph (or tree) by following one branch as far as possible before backtracking.
  - **Techniques:**
    - Recursion: Uses the call stack to remember the path.
    - Stack-based: Uses an explicit stack data structure to manage nodes.
- **Traversal Order and Backtracking:**
  - **Order**: In trees, DFS can be described as Preorder, Inorder, or Postorder; in general graphs, it simply explores one branch fully then returns.
  - **Backtracking**: When a node has no unvisited neighbors, DFS backtracks to explore other branches.

### Applications

- **Path Finding**: Explore paths in puzzles or maze-like structures.
- **Topological Sorting**: Order vertices in a Directed Acyclic Graph (DAG) based on dependencies.
- **Cycle Detection**: Identify cycles in graphs by tracking nodes in the current recursion stack.
- **Solving Puzzles and Mazes**: DFS can efficiently traverse all possible paths to find a solution.

### Variants

- R**ecursive DFS vs. Iterative DFS:**
  - **Recursive DFS:** Cleaner code; however, it may lead to stack overflow for very deep graphs.
  - **Iterative DFS:** Uses an explicit stack, avoiding recursion depth limits.
- **DFS in Trees vs. General Graphs:**
  - **Trees:** No cycles to worry about, so DFS is straightforward.
  - **General Graphs:** Requires a mechanism (e.g., a “visited” set) to avoid infinite loops due to cycles.

### Complexity and Performance

- Time Complexity: $O(V + E)$ — Every vertex and edge is explored once.
- Space Complexity: $O(V)$ — In the worst case (e.g., a deep graph), the recursion stack or explicit stack may hold all vertices.

### Related Concepts

- **Graph Connectivity:** DFS can help determine connected components.
- **Strongly Connected Components:**
  - **Tarjan’s Algorithm:** Uses DFS to identify strongly connected components in a directed graph.
  - **Kosaraju’s Algorithm:** Uses two passes of DFS to find strongly connected components.

---

## Breadth First Search (BFS)

- **Concept and Intuition**
  - How BFS works (using a queue).
  - Level order traversal.
- **Applications**
  - Shortest path in unweighted graphs.
  - Web crawlers and social networking analysis.
  - Network flow problems
- **Variants**
  - BFS for trees vs. general graphs.
  - Modifications for weighted graphs (e.g., 0-1 BFS).
- **Complexity Analysis**
  - Time and space complexity.
- **Comparison with DFS**
  - Advantages and trade-offs in different scenarios.

## 📘 BFS Study Guide

### Concept and Intuition

- **How BFS Works:**
  - **Exploration:** BFS explores the graph level by level, starting from a source node.
  - **Queue-based:** It uses a queue to maintain the order of vertex exploration.
- **Level Order Traversal:**
  - **Process:** Visit all nodes at the current depth before moving on to nodes at the next depth level.

### Applications

- **Shortest Path in Unweighted Graphs:**
  - BFS guarantees finding the shortest path (in terms of number of edges) from the source to any vertex.
- **Web Crawlers and Social Networking Analysis:**
  - Explore links or connections level by level.
- **Network Flow Problems:**
  - BFS is used in the Edmonds-Karp implementation of the Ford-Fulkerson method to find augmenting paths.

### Variants

- **BFS for Trees vs. General Graphs:**
  - **Trees:** Straightforward level-order traversal.
  - **Graphs:** Must track visited nodes to avoid processing cycles.
- **Modifications for Weighted Graphs:**
  - 0-1 BFS: Uses a deque to process graphs with edge weights of 0 or 1, efficiently finding the shortest path.

### Complexity Analysis

- **Time Complexity:** $O(V + E)$ — Each vertex and edge is processed.
- **Space Complexity:** $O(V)$ — In the worst case, the queue holds all vertices at a given level, which can be significant for wide graphs.

### Comparison with DFS

- **Advantages of BFS:**
  - **Shortest Path Guarantee:** In unweighted graphs, BFS finds the shortest path.
  - **Level-order Exploration:** Useful for problems where the distance from the source matters.
- **Trade-offs:**
  - **Memory Usage:** BFS can consume more memory than DFS in graphs with a large branching factor.
  - **Implementation:** DFS is often simpler and more memory efficient in cases where path length isn’t critical.

⸻

## Prim's Algorithm (Prim’s)

- **Overview and Purpose**
  - Concept of Minimum Spanning Trees (MST).
  - How Prim's algorithm constructs an MST.
- **Algorithm Details**
  - Data structures typically used (priority queues, min-heaps).
  - Step-by-step process.
- **Complexity Analysis**
  - Time complexity with different graph representations.
- **Applications**
  - Network design (e.g., computer networks, road networks).
  - Clustering algorithms in data mining.
- **Historical Notes**
  - Origins and development of MST algorithms.
- **Comparisons**
  - Comparison with Kruskal's algorithm.

---

## Kruskal's Algorithm (Kruskal’s)

- **Overview and Purpose**
  - Understanding the MST problem.
  - How Kruskal’s algorithm differs from Prim's.
- **Algorithm Details**
  - The role of disjoint set (union-find) data structures.
  - Greedy approach and sorting of edges.
- **Complexity Analysis**
  - Time complexity analysis based on union-find optimizations.
- **Applications**
  - Similar to Prim’s: network design, clustering.
- **Historical Context**
  - Evolution and importance in algorithm design.
- **Comparisons**
  - Trade-offs with Prim's algorithm for different types of graphs.

---

## Dijkstra's Algorithm (Dijkstra’s)

- **Concept and Intuition**
  - Finding the shortest path in weighted graphs.
  - The idea of "relaxation" and maintaining a priority queue.
- **Algorithm Steps**
  - Initialization, updating distances, and final path extraction.
- **Complexity Analysis**
  - Time complexity with various implementations (e.g., using min-heap).
- **Applications**
  - GPS and route planning.
  - Network routing protocols.
- **Limitations and Variants**
  - Handling negative weights (and why Dijkstra’s isn’t suited for them).
  - Variants like A\* (which adds heuristics).
- **Historical Background**
  - The development of the algorithm and its impact on graph theory.

---

These subtopics should provide a thorough roadmap for students to explore each major topic in depth, understanding both the theoretical and practical implications of each algorithm and data structure. Feel free to adjust or expand these subtopics based on the level and focus of your course.
