## Graphs - Introduction

<sup>Source: https://www.cs.cmu.edu/~adamchik/21-127/lectures/graphs_1_print.pdf</sup>

### Introduction

The basic idea of graphs were introduced in 18th century by the Swiss mathematician
Leonhard Euler. He used graphs to solve the famous Königsberg bridge problem.

#### Problem:
The German city of Königsberg was situated on the river Pregel. It had a park situated on the banks of the river and two islands. Mainland and islands were joined by seven bridges. 

The problem was whether it was possible to take a walk through the town in such a way as to cross over every bridge once, and only once.

|                                                                                            |                                                                                            |
| :----------------------------------------------------------------------------------------: | :----------------------------------------------------------------------------------------: |
| <img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/graphs.2.1.png" width="300"> | <img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/graphs.2.2.png" width="200"> |
|                                   Bridges of Königsberg                                    |                                    Graph of Königsberg                                     |

A **graph** is a set of points (we call them **vertices** or **nodes**) connected by lines (**edges** or
**arcs**).

Some Examples of what Graphs can represent (a tiny example):

- Networks
- The Internet (a big network)
- Heierarchical Structures
- Topology
- State Diagrams

### Basic Vocabulary

#### Simple Graph

- A graph that have nonempty set of vertices connected at most by one edge

#### Multi Graph

- Allow multiple edges between two vertices.

#### Multi Graph

- Allow edges connect a vertex to itself.


|                                                                                            |                                                                                            |                                                                                            |
| :----------------------------------------------------------------------------------------: | :----------------------------------------------------------------------------------------: | :----------------------------------------------------------------------------------------: |
| <img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/graphs.2.3.png" width="150"> | <img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/graphs.2.4.png" width="150"> | <img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/graphs.2.5.png" width="150"> |
|                                        Simple Graph                                        |                                        Multi Graph                                         |                                        Pseudo Graph                                        |

These are all **undirected** graphs and edges are **unordered**.

#### Directed Graph

- A `directed graph` consist of `vertices` and `ordered pairs` of `edges`. 
- Note, multiple edges in the same direction are not allowed.
- If multiple edges in the same direction are allowed, then a graph is called **directed multigraph**.

|       | 
|:----:|
|<img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/graphs.2.6.png" width="400">|
|  Directed Graphs   | 

#### Weighted Graph

- An edge may also have a **weight** or **cost** associated with it.
- If `a, b` is an edge we might denote the cost by `c(a,b)`
- In the example below: `c(a,b) = c(b,a) = 7`.

|                                                                                            | 
| :----------------------------------------------------------------------------------------: | 
| <img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/graphs.2.7.png" width="200"> |
|                                       Weighted Graph                                       |

#### Adjacency and Degree

- Two vertices are called **adjacent** if there is an edge between them
- The **degree** of a vertex in an undirected graph is the number of edges associated with it.
- If a vertex has a loop, it contributes twice.

|  |
|:----:|
|The degree of vertex **a** is 2, and the degree of vertex **c** is 4.|
|<img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/graphs.2.8.png" width="200">|
| Weighted Graph   | 

#### Number of Edges

- Let `G` be an undirected graph (or multigraph) with `V` vertices and `N` edges. Then:

|      |     |
|:----:|:----:|
|<img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/graphs.2.10.png" width="150">|<img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/graphs.2.9.png" width="200">|


#### Directed Graphs

- In a directed graph vertex **v** is **adjacent** to **u**, if there is an edge leaving **v** and coming to **u**. 
- In a directed graph the **in-degree** of a vertex denotes the number of edges **coming to** this vertex. 
- The **out-degree** of a vertex is the number of edges **leaving** the vertex.

|       | 
|:----:|
|<img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/graphs.2.11.png" width="300">|
|  Directed Graph| 

#### Number of Edges

|       | 
|:----:|
| Let `G` be a directed graph (or multigraph) with `V` vertices and `N` edges. Then: |
|<img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/graphs.2.12.png" width="300">|
|  Theorem| 

### Regular Graph

- A graph in which every vertex has the **same degree** is called a regular graph.

|       |  | |
|:----:|:----:|:----:|
|<img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/graphs.2.13.png" width="300">|<img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/graphs.2.14.png" width="300">|<img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/graphs.2.15.png" width="300">|
|  |  |

- The **complete graph** on n vertices, denoted K<sub>n</sub>, is a simple graph in which there is an edge between every pair of distinct vertices.
- How many edges in K<sub>n</sub>?


#### Connectivity

- A **path** is a sequence of distinctive **vertices** connected by **edges**. 
- Vertex **v** is reachable from **u** if there is a path from **u** to **v**. 
- A graph is **connected**, if there is a path between any two vertices.
- A directed graph is **strongly** connected if there is a path from **u** to **v** and from **v** to **u** for any **u** and **v** in the graph. 
- A directed graph is **weakly connected** if the underlying undirected graph is connected

|       | 
|:----:|
|<img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/graphs.2.16.png" width="300">|
| Connectivity| 

#### Representing Graphs

- If you can determine that your graph will be **dense** (number of edges is close to `V * log V`) then you can use a matrix to represent your graph.
- Otherwise if your edges will be less than `V * log V`, its considered **sparse**, and you would want to use a list representation.

|             |    |
| :------------------: | :---------------------: |
| <img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/graphs.2.18.png" width="250"> | <img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/graphs.2.19.png" width="150"> |
|   Directed Graph         |     Adjacency List    |


|             |    |
| :------------------: | :---------------------: |
| <img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/graphs.2.24.png" width="250"> | <img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/graphs.2.25.png" width="200"> |
|   Undirected Weighted Graph         |     Adjacency List    |

|             |    |
| :------------------: | :---------------------: |
| <img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/graphs.2.18.png" width="250"> | <img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/graphs.2.21.png" width="150"> |
|    Directed  Graph         |     Adjacency Matrix    |

|             |    |
| :------------------: | :---------------------: |
| <img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/graphs.2.18a.png" width="250"> | <img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/graphs.2.20.png" width="150"> |
|    Undirected Graph         |     Adjacency Matrix    |

|             |    |
| :------------------: | :---------------------: |
| <img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/graphs.2.22.png" width="250"> | <img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/graphs.2.23.png" width="150"> |
|    Undirected Weighted Graph         |     Adjacency Matrix    |

### Trees 

- A **tree** is a connected simple graph without cycles. 
- A **cycle** is a sequence of distinctive adjacent vertices that begins and ends at the same vertex.
- A tree with `V` vertices must have `V-1` edges. 
- A connected graph with `V` vertices and `V-1` edges must be a tree.
- A **rooted tree** is a tree with one vertex designated as a root. 
- A **forest** is a graph without cycles. In orther words, a forest is a set of trees.

|       | 
|:----:|
|<img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/graphs.2.28.png" width="300">|
| Tree| 

- A **spanning tree** of a graph is a subgraph, which is a tree and contains all vertices of the graph. 
- In the figure below, the right picture represents a spanning tree for the graph on the left. 
- A spanning tree is not unique.

|    |     |    |    |
| :------------------------------------: | :---------------: |:---------------: |:---------------: |
| <img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/graphs.2.26.png" width="150"> | <img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/graphs.2.27.png" width="150"> |<img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/graphs.2.29.png" width="150"> |<img src="http://cs.msutexas.edu/~griffin/zcloud/zcloud-files/graphs.2.30.png" width="150"> |
|Graph|Spanning Tree 1 |Spanning Tree 2|Spanning Tree 3 |

- Can you find another one??
