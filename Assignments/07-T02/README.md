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

## 📘 AVL Trees Study Guide

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

- **Defined as:**
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

- **AVL trees are always balanced, which means the height is logarithmic in the number of nodes:**
  $h(n) \leq 1.44 \cdot \log_2(n + 2) - 0.328$

#### Compared to Other Trees:

- `Red-Black Trees`: Slightly faster inserts/deletes on average, but AVL trees are more strictly balanced → better for read-heavy workloads.
- `Unbalanced BSTs`: Only good if data is randomly distributed (and even then, dangerous).

⸻

### 🛠️ 5. Use Cases and Applications

#### When should I use AVL trees?

- When you need fast lookups and data is frequently read, not just inserted/deleted.
- **Ideal for:**
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

# 📘 A Graph Theory Study Guide

## 1. Fundamentals of Graph Theory

- **Vertices and Edges**
  - **Vertices (Nodes)**: Fundamental units representing entities (e.g., cities, network nodes).
  - **Edges (Links)**: Connections between vertices. They may represent roads, communication links, etc.
- **Weighted vs. Unweighted Graphs**
  - **Weighted Graphs:** Each edge carries a numerical value (weight) indicating cost, distance, or capacity.
  - **Unweighted Graphs:** Edges are considered equal; the focus is on connectivity rather than cost.
- **Directed vs. Undirected Graphs**
  - **Directed Graphs (Digraphs):** Edges have direction, meaning the connection is one-way.
  - U**ndirected Graphs:** Edges imply a two-way, mutual relationship between vertices.

⸻

## 2. Graph Representations

Adjacency matrices and lists are two common ways to represent graphs, with matrices using a 2D array to store connections, while lists use linked lists to store neighbors of each vertex, each with its own space and time complexity trade-offs.

### Graphic One

|   Graph    |            | Adjacency List |            | Adjacency Matrix |
| :--------: | :--------: | :------------: | :--------: | :--------------: |
| ![][graph] | ![][arrow] |   ![][list]    | ![][arrow] |   ![][matrix]    |

### Graphic Two

| Adjency Matrix | Pros | Cons |
| :------------- | :--- | :--- |
| ![][matrix2]   |      |      |
| Adjacency List |      |      |
| ![][list2]     |      |      |
| Edge List      |      |      |
| ![][edge2]     |      |      |

### Adjacency Matrix

![][matrix2]

- **Representation:** A 2D array where each cell $(i, j)$ indicates whether there's an edge between vertex $i$ and vertex $j$.
- **Space Complexity:** $O(V^2)$, where V is the number of vertices, as it stores potential edges even if they don't exist.
- **Time Complexity:**

  - Checking for an edge between two vertices: $O(1)$.
  - Finding all neighbors of a vertex: $O(V)$.

- **Advantages:**

  - Efficient for checking the existence of edges.
  - Suitable for dense graphs (graphs with many edges).

- **Disadvantages:**

  - Space-inefficient for sparse graphs (graphs with few edges).
  - Adding or deleting vertices can be costly.

- **Adjacency List**

  - An array or list where each element (vertex) holds a list of its adjacent vertices (and edge weights, if applicable).
  - **Pros:** Efficient for sparse graphs with O(V + E) space.
  - **Cons:** Checking the existence of a specific edge may take O(degree).

- **Edge List**
  - A simple list of edges, where each edge is a pair (or triple, if weighted) representing the connection between vertices.
  - **Pros:** Simple structure; good for algorithms that process all edges (like Kruskal’s).
  - **Cons:** Less efficient for neighbor queries.

### Adjacency List:

![][list2]

- **Representation:** An array of linked lists, where each element represents a vertex and its linked list stores its neighbors.
- **Space Complexity:** $O(V + E)$, where $V$ is the number of vertices and $E$ is the number of edges, making it more space-efficient for sparse graphs.
- **Time Complexity:**

  - Checking for an edge between two vertices: $O(E)$ in the worst case, where $E$ is the number of edges.
  - Finding all neighbors of a vertex: $O(degree of the vertex)$.

- **Advantages:**

  - Space-efficient for sparse graphs.
  - Efficient for finding neighbors of a vertex.

- **Disadvantages:**
  - Checking for the existence of edges can be slow.
  - Less suitable for dense graphs.

### When to use which:

- **Adjacency Matrix:**

  - When you need to frequently check for the existence of edges between vertices.
  - When the graph is dense.

- **Adjacency List:**
  - When you need to iterate over the neighbors of a vertex frequently.
  - When the graph is sparse.
  - When memory is a concern.

![][edge2]
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
- **Bipartite Graphs:**
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

## 📘 MST Study Guide

### 1. Overview and Purpose

#### Concept of Minimum Spanning Trees (MST)

- **Definition:**
  - An MST is a spanning tree of a connected, undirected graph that connects all vertices with the smallest possible total edge weight.
- **Purpose:**
  - It ensures that all nodes are connected at minimum cost, which is crucial in network design, road networks, and many optimization problems.

#### How Prim’s Algorithm Constructs an MST

- **Starting Point:**
  - The algorithm begins with an arbitrary vertex.
- **Growth Strategy:**
  - At each step, it selects the minimum-weight edge that connects a vertex in the growing MST to a vertex outside it.
- **Iteration:**
  - This process repeats until all vertices are included, thus ensuring the resulting tree has the minimum total edge weight.

### 2. Algorithm Details

#### Data Structures Typically Used

- **Priority Queue / Min-Heap:**
  - Used to efficiently select the edge with the smallest weight at each step.
- **Arrays/Lists:**
  - Often employed to track which vertices are included in the MST and to store key values (the minimum weight to connect each vertex).

#### Step-by-Step Process of Prim’s Algorithm

1. **Initialization:**

   - Start with an arbitrary vertex and mark it as part of the MST.
   - Initialize a min-heap with all edges from this vertex.

2. **Selection:**

   - Extract the edge with the minimum weight from the min-heap.

3. **Inclusion:**

   - If the edge connects to a vertex not already in the MST, add that vertex (and edge) to the MST.

4. **Update:**

   - Update the min-heap with the new edges from the recently added vertex.

5. **Iteration:**

   - Continue until all vertices are included in the MST.

⸻

### 3. Complexity Analysis

**Time Complexity**

- **Using a Binary Heap and Adjacency List:**
  - $O((V + E) \log V)$ or $O(E \log V)$, where $V$ is the number of vertices and $E$ is the number of edges.
- **Using a Fibonacci Heap:**
  - Can improve the time complexity to $O(E + V \log V)$.

#### Graph Representations

- **Adjacency List:**
  - Efficient for sparse graphs since it only stores edges that exist.
- **Adjacency Matrix:**
  - Typically less efficient due to its $O(V^2)$ space and time usage for dense graphs.

### 4. Applications

- **Network Design**

  - **Usage:**
    - MSTs help design cost-efficient networks by minimizing the total length or cost of cables, pipes, or roads connecting all nodes.
  - **Examples:**
    - Computer network layouts, electrical grid planning, and road networks.

- **Clustering in Data Mining**

  - **Usage:**
    - MSTs can be used to perform clustering by cutting the most expensive edges, thereby partitioning the graph into clusters.
  - **Applications:**
    - Image segmentation, gene expression analysis, and other unsupervised learning problems.

### 5. Historical Notes

- **Origins and Development of MST Algorithms**

- **Early Concepts:**
  - The concept of spanning trees emerged as researchers sought to connect networks at minimal cost.
- **Key Milestones:**
  - Prim’s Algorithm: Developed in the 1950s as an efficient method for constructing an MST.
  - Kruskal’s Algorithm: Introduced in 1956, using a different approach based on sorting and union-find data structures.
- **Impact:**
  - These algorithms have had significant influence in combinatorial optimization and network design, paving the way for further research in graph theory.

### 6. Comparisons

- **Prim’s vs. Kruskal’s Algorithm**

- **Prim’s Algorithm:**
  - **Method**: Greedy expansion from a starting vertex, growing a single tree.
  - **Data Structures**: Typically uses a min-heap (or priority queue) for edge selection.
  - **Best Use**: Generally performs better on dense graphs (especially with an adjacency matrix) and when the graph is connected.
- **Kruskal’s Algorithm:**
  - **Method**: Sorts all edges by weight and adds them one by one, using a union-find structure to avoid cycles.
  - **Best Use**: Often preferred for sparse graphs because it processes edges directly.
- **Summary:**
  - Both algorithms yield an MST, but the choice between them depends on graph density, implementation complexity, and the nature of the problem.

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

### 1. Overview and Purpose

- **Concept**:
  - Kruskal’s Algorithm finds an MST by sorting all edges of the graph in ascending order of weight and adding them one by one to the growing forest, ensuring no cycles form.
- **Purpose**:
  - It is used to connect all vertices with the minimal total edge weight, ideal for designing cost-effective networks.

### 2. Algorithm Details

- **Step-by-Step Process:**

1. Sort Edges:

- Sort all the edges in non-decreasing order by their weight.

2. **Initialize Forest:**

- Start with each vertex as its own separate tree.

3. **Edge Selection:**

- **Iterate through the sorted edges, and for each edge:**
  - Use a union-find data structure to check if the current edge connects two different trees.
  - If it does, add the edge to the MST and merge the trees.

4. **Termination:**

- Stop once all vertices are connected (i.e., when the MST has V - 1 edges).
- **Data Structures Used:**
  - Union-Find (Disjoint Set): Efficiently tracks and merges trees while preventing cycles.
- **Edge List:** Often used to store and sort the graph’s edges.

⸻

### 3. Complexity Analysis

- **Time Complexity:**
  - Sorting the edges: $O(E \log E)$ (or $O(E \log V)$, since $E \leq V^2$).
  - Union-find operations: Nearly $O(1)$ on average per edge (with path compression and union by rank).
- **Overall Complexity:**
  - Typically $O(E \log E)$ or $O(E \log V)$, making it efficient for sparse graphs.

### 4. Applications

- **Network Design:**
  Ideal for designing efficient networks (e.g., electrical grids, road networks) where cost minimization is critical.
- **Clustering:**
  Used in data mining to form clusters by removing the most expensive edges in the MST.
- **Other Uses:**
  Helps in problems where connecting disparate components at minimum cost is essential.

### 5. Historical Notes

- **Origins**:
  - Developed by Joseph Kruskal in 1956.
  - One of the foundational algorithms in combinatorial optimization and graph theory.
- **Impact**:
  - Has influenced numerous network design and clustering techniques, and remains a staple in algorithm courses.

### 6. Comparisons

- **Kruskal’s vs. Prim’s:**
- **Approach:**
  - **Kruskal’s:** Edge-based, builds the MST by choosing the smallest edges first.
  - **Prim’s:** Vertex-based, grows the MST starting from an arbitrary vertex.
- **Data Structures:**
  - **Kruskal’s:** Relies heavily on union-find for cycle detection.
  - **Prim’s:** Uses priority queues (min-heaps) to select the next vertex.
- **Best Use Case:**
  - **Kruskal’s:** Often better for sparse graphs.
  - **Prim’s:** Typically performs well on dense graphs or when using an adjacency matrix.

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

### Overview and Purpose

- **Definition:**
  - Dijkstra’s Algorithm finds the shortest path from a given source vertex to all other vertices in a weighted graph with non-negative edge weights.
- **Purpose:**
  - It is designed to determine the minimum cost (or distance) paths, making it fundamental for routing, navigation, and network optimization tasks.

### Algorithm Details

#### Initialization:

- Set the distance to the source vertex as 0 and to all other vertices as infinity.
- Use a priority queue (min-heap) to manage vertices by their current distance estimates.

#### Main Loop (Relaxation Process):

1. **Extract Minimum:**
   - Remove the vertex with the smallest distance from the priority queue.
2. **Relaxation:**
   - For each neighbor of this vertex, compute the tentative distance as the sum of the current vertex’s distance and the weight of the connecting edge.
3. **Update:**
   - If the computed distance is smaller than the currently recorded distance for the neighbor, update its distance and reinsert it into the queue.

- **Termination:**
  - The process repeats until all vertices have been processed (or until the target vertex’s shortest path is found, if only one destination is needed).

## Complexity Analysis

- **Time Complexity:**
  - With a binary min-heap: $O((V + E) \log V)$, where $V$ is the number of vertices and $E$ is the number of edges.
  - With a Fibonacci heap (less common in practice): $O(E + V \log V)$.
- **Space Complexity:**
  - $O(V)$ for storing distances and the priority queue.

## Applications

- **Routing and Navigation:**
  - GPS systems use it to find the shortest driving routes.
- **Network Routing:**
  - Internet protocols use Dijkstra’s Algorithm for path selection in networks.
- **Urban Planning:**
  - It assists in designing efficient transportation and infrastructure networks.
- **Telecommunications:**
  - Optimizes communication paths to minimize latency and cost.

## Historical Notes

- **Development:**
  - Introduced by Edsger W. Dijkstra in 1956 and published in 1959.
- **Impact:**
  - It was one of the first algorithms to use a greedy strategy for path optimization and has since become a fundamental tool in computer science.
- **Legacy:**
  - Its concepts have inspired numerous other algorithms, such as A\* for heuristic pathfinding.

## Comparisons

- **Bellman-Ford Algorithm:**
  - Use Case: Handles negative edge weights, but runs slower ($O(VE)$).
  - Dijkstra’s Edge: More efficient when all edge weights are non-negative.
- **A\* Search:**
  - Enhances Dijkstra’s by incorporating heuristics for faster pathfinding in spatial graphs.
- **Prim’s Algorithm:**
  - Although similar in structure, Prim’s focuses on constructing a Minimum Spanning Tree (MST) rather than shortest paths.

<!--
#################################################################################################################################
#################################################################################################################################
#################################################################################################################################

Images Used Above
Shorthand Syntax
-->

[graph]: ./images/graph_image.png
[list]: ./images/adjacency_list.png
[matrix]: ./images/adjacency_matrix.png
[arrow]: ./images/represented_as.png
[list2]: ./images/00_adjacency_list.png
[matrix2]: ./images/00_adjacency_matrix.png
[edge2]: ./images/00_edge_list.png
