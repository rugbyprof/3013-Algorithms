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

---

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
