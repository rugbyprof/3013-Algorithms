## Baruvkas - Spanning Trees

#### Due: None

### Boruvka's Algorithm

`Boruvka's Algorithm`, also known as `Sollin's Algorithm`, is a greedy algorithm used for finding the minimum spanning tree (MST) of an undirected weighted graph. A minimum spanning tree is a subgraph of the original graph that connects all vertices while minimizing the total weight of its edges.

The algorithm was initially proposed by `Otakar Boruvka` in 1926 for constructing an efficient electrical network in the Czech Republic. The main idea of the algorithm is to find the minimum-weight edge connected to each vertex and then merge the connected components at each step, gradually building the MST.

Here's a high-level description of the algorithm:

1. Initialize a forest F to be a set of one-vertex trees, one for each vertex in the graph.
2. While F does not form a spanning tree (i.e., it has more than one connected component):
   - **a.** For each connected component in F, find the minimum-weight edge that connects the component to a vertex outside the component.
   - **b.** Add all the edges found in step 2a to F.
3. Return F as the minimum spanning tree.

Boruvka's Algorithm has a time complexity of `O(E log V)`, where `E` is the number of edges and `V` is the number of vertices in the graph. This makes it an efficient algorithm for solving `MST` problems, although it's typically less common in practice than other MST algorithms like Kruskal's and Prim's algorithms.
