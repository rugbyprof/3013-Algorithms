## Test 3
# NOT DONE
Name: _____________________

•	Use pencil only.
•	Write answers on the paper provided.
•	Write clearly and legibly






### 1) Dijkstra’s Algorithm
 

Use Dijkstra’s algorithm to compute the shortest paths from vertex A to every other vertex. Show your work in the space provided below. As the algorithm proceeds, cross out old values and write in new ones, from left to right in each cell. If during your algorithm two unvisited vertices have the same distance, use alphabetical order to determine which one is selected first. Also list the vertices in the order which Dijkstra's algorithm marks them as discovered.

		

 
### 2) Prims Algorithm

 
Step through Prim’s algorithm to calculate a minimum spanning tree starting from vertex G. Show your steps in the table below. As the algorithm proceeds, cross out old values and write in new ones, from left to right in each cell. If during your algorithm two unvisited vertices have the same distance, use alphabetical order to determine which one is selected first. Also list the vertices in the order which Prims algorithm discovers them. 



		
		
		
		

 
### 3) Kruskel’s Algorithm

 
Use Kruskal’s algorithm to calculate a minimum spanning tree of the graph. Show your steps in the table below, including the disjoint sets at each iteration. If you can select two edges with the same weight, select the edge that would come alphabetically last (e.g., select E—F before B—C. Also, select A—F before A—B). 
•	Edge Added: put edges added to MST marked as (A B), (E G), etc.
•	Edge Cost: weight of edge added
•	Running cost is total weight of spanning tree at the point another edge is added.
•	Disjoint sets starts as: (A) (B) (C) (D) (E) (F) (G) , and as edges are added => (A) (B C) (D) (E) (F) (G) 
Edge Added 	Edge Cost 	Running Cost	Disjoint Sets
			
			
			
			
			
			
			
		
 
### 4) Prims Vs Kruskels 

- A.	Explain why Prim’s algorithm is better for dense graphs, while Kruskal’s algorithm is better for sparse graphs. 
- B.	What data structures are used when implementing each algorithm?
- C.	What are the run times for each algorithm?

> **Answer:**
> A: If the run times for both Prims and Kruskels were the same, as they can be depending on thier implementation: `O(E lg V)` then one algorithm would be no better than the other in sparse or dense graphs. However, since there is one implementation of Prims algorithm that improves its performance to `O(E + V lg V)` and this makes the difference. The difference between **dense** and **sparse** depends on the number edges vs the number of vertices. Dense implies that the number of edges is approaching the max (like for a fully connected graph) and sparse implies that edges are closer to the number of vertices (above or below). If Prims is implemented using a `Fibonacci Heap` that can run in `O(1)` amortized time<sup>see note below this answer</sup>, then its ability to choose edges is extremely fast, and the mojority of cost is placed on simply the number of nodes. Kruskels on the other hand cannot find a faster way of being implemented because it MUST analyze every edge by placing it in a min-heap. Even if you were to use a `Fibonacci Heap`, the savings in amortized costs won't allow it run as efficiently as Prims simply because of ALL the edges that must be placed in the heap. 

>**Note:** Amortization
 
### 5) Greedy Algorithms

- A.	Define “Greedy Algorithm”
- B.	Give an example of a greedy algorithm with explanation of its greediness and performance. 
- C.	Can greedy algorithms produce “optimal” solutions? Short explanation.

 
### 6) A-Star

- A.	Describe how the A-Star algorithm works using a list of steps.
- B.	What makes A-Star different from Dijkstra’s algorithm?







