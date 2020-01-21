## Test 3

Name: _____________________

•	Use pencil only.
•	Write answers on the paper provided.
•	Write clearly and legibly



### 1) Dijkstra’s Algorithm
 

Use Dijkstra’s algorithm to compute the shortest paths from vertex A to every other vertex. Show your work in the space provided below. As the algorithm proceeds, cross out old values and write in new ones, from left to right in each cell. If during your algorithm two unvisited vertices have the same distance, use alphabetical order to determine which one is selected first. Also list the vertices in the order which Dijkstra's algorithm marks them as discovered.

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.test.3.graph1.png" width="300">	
<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.test.3.dijkstra_sol2.png" width="400">

 



### 2) Prims Algorithm

 
Step through Prim’s algorithm to calculate a minimum spanning tree starting from vertex G. Show your steps in the table below. As the algorithm proceeds, cross out old values and write in new ones, from left to right in each cell. If during your algorithm two unvisited vertices have the same distance, use alphabetical order to determine which one is selected first. Also list the vertices in the order which Prims algorithm discovers them. 

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.test.3.graph4.png" width="300">

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.test3.prims_sol.png" width="400">
		
		
		
		
### 3) Kruskel’s Algorithm

 
Use Kruskal’s algorithm to calculate a minimum spanning tree of the graph. Show your steps in the table below, including the disjoint sets at each iteration. If you can select two edges with the same weight, select the edge that would come alphabetically last (e.g., select E—F before B—C. Also, select A—F before A—B). 
•	Edge Added: put edges added to MST marked as (A B), (E G), etc.
•	Edge Cost: weight of edge added
•	Running cost is total weight of spanning tree at the point another edge is added.
•	Disjoint sets starts as: (A) (B) (C) (D) (E) (F) (G) , and as edges are added => (A) (B C) (D) (E) (F) (G) 
Edge Added 	Edge Cost 	Running Cost	Disjoint Sets

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.test.3.graph4.png" width="300">	
			
<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.test3.kruskels_sol2.png" width="400">
			
			
			
			
		
 
### 4) Prims Vs Kruskels 

- A.	Explain why Prim’s algorithm is better for dense graphs, while Kruskal’s algorithm is better for sparse graphs. 
- B.	What data structures are used when implementing each algorithm?
- C.	What are the run times for each algorithm?

> **Answer:**
> 
> **A:** If the run times for both Prims and Kruskels were the same, as they can be depending on thier implementation: `O(E lg V)` then one algorithm would be no better than the other in sparse or dense graphs. However, there is one implementation of Prims algorithm that improves its performance to `O(E + V lg V)` and this makes the difference. The difference between **dense** and **sparse** depends on the number edges vs the number of vertices. Dense implies that the number of edges is approaching the max (like for a fully connected graph) and sparse implies that edges are closer to the number of vertices (above or below). If Prims is implemented using a `Fibonacci Heap` that can run in `O(1)` amortized time, then its ability to choose edges is extremely fast, and the mojority of cost is placed on simply the number of nodes. Kruskels on the other hand cannot find a faster way of being implemented because it MUST analyze every edge by placing it in a min-heap. Even if you were to use a `Fibonacci Heap`, the savings in amortized costs won't allow it run as efficiently as Prims simply because of ALL the edges that must be placed in the heap. 
> 
> **B:**
> **Prims**: Needs some kind of heap or priority queue to choose the smallest edge to cross the cut. It also needs two structures to hold items IN the MST and those NOT in the MST. For this the proper way is to use a `Disjoint Set` algorithm, however we could also use `arrays of pointers` or `lists`. 
> **Kruskels**: This is pretty easy, since we only need to choose smallest edge, then check for a cycle. Checking for a cycle stays within the graph structure, and finding the smallest edge fits perfectly with a `min heap` using weight as the priority. 
> 
> **C:** See above
 
### 5) Greedy Algorithms

- A.	Define “Greedy Algorithm”
- B.	Give an example of a greedy algorithm with explanation of its greediness and performance. 
- C.	Can greedy algorithms produce “optimal” solutions? Short explanation.

>***Answer:***
>**A:** Any algorithm that makes choices based on a "current state" in which the choice maximizes its goal regardless of past or future choices. It makes the "greedy" choice.
>
>***B:*** **Dijkstras** is a good example of a greedy algorithm since it chooses the "smallest" current distance for a given node when discovering new paths. **Prims** and **Kruskels** are greedy as well since each choice is made based on the either the lightest edge across the cut or the lightest overall edge (respectively).
> ***C:*** Some greedy algorithms can result in an optimal solution. Dijkstras (again) is one of the algorithms that is greedy and always results in the optimal solution. However, many greedy algorithms or (heuristics) do not result in optimal solutions. Take the traversal of a maze, simply choosing a path that shortens your distance to the exit (greedy choice) may get you trapped, and you would need to back track to eventually solve the maze. 
 
### 6) A-Star

- A.	Describe how the A-Star algorithm works using a list of steps.
- B.	What makes A-Star different from Dijkstra’s algorithm?

>**Answer:**
>**A:** A-star can be thought of as Dijkstra's algorithm plus an added heuristic. 
> Broad Explanation:
> - Start a some vertex: A
> 1. Look at all edges leaving A and choose the shortest distance from A to "discover", lets call it D.
> 2. Update the distance to D AND all of its neighbors by adding the edge weight to each nodes current distance. 
> 3. Keep each node in a min priority queue based on distance (smallest at the top).
> 4. Continuously remove the top node as the next node to be discovered (call it A). Goto step one until all nodes have been discovered. 
>
> We can turn the above "algorithm" into A-Star by adding a "heuristic". The heuristic is usually a "distance to target" and we try to "minimize" the distance to target when making choices on a path. So, when updating values at each node as we discover them, we add the current distance from A to the current distance to target as our nodes "cost". So, as we discover nodes, we update thier cost as `cost = distance_from_start + distance_to_target` wich allows us to follow a shortest path to a target. 
>
>**A:** What makes A-Star different from Dijkstra's is the added heuristic incorporated into the algorithm. 



