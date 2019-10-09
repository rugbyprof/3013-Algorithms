## Minimum Spanning Trees - Prims & Kruskels

## Kruskal's Algorithm 

**Kruskal's algorithm** is a [greedy algorithm](http://en.wikipedia.org/wiki/Greedy_algorithm) used for finding a minimum spanning tree for a **connected**, **weighted**, and **undirected** graph. Meaning that the algorithm finds the set of edges that forms a tree including ***every vertex*** and has the ***lowest weight*** possible, without any [cycles](http://en.wikipedia.org/wiki/Cycle_(graph_theory)).

Starting off we have a priority queue with least cost on top of the heap.

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/kruskels.3.01.png" width="500">

----- 

We choose the "least cost" edge, in this case `A → D` with a cost of 5.

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/kruskels.3.02.png" width="500">

----- 

It doesn't create a cycle, so we add it to our MST. 

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/kruskels.3.03.png" width="500">

----- 

We choose the next "least cost" edge  `C → E` also with a cost of 5. This could just as easily have been the first edge selected instead of `A → D`.

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/kruskels.3.04.png" width="500">

----- 

It also doesn't create a cycle, so we add it to our MST.

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/kruskels.3.05.png" width="500">

----- 

Next we choose `D → F` with a cost of 6.

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/kruskels.3.06.png" width="500">

----- 

It doesn't cause a cycle, so we add it to our MST.

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/kruskels.3.07.png" width="500">

----- 

Next we choose `A → B` with a cost of 7.

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/kruskels.3.08.png" width="500">

----- 

It doesn't cause a cycle, so we add it to our MST.

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/kruskels.3.09.png" width="500">

----- 

Next we choose `B → E` also with a cost of 7.

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/kruskels.3.10.png" width="500">

----- 

It doesn't cause a cycle, so we add it to our MST.

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/kruskels.3.11.png" width="500">

----- 

Next we choose `E → F` also with a cost of 8.

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/kruskels.3.12.png" width="500">

----- 

This edge **does** cause a cycle, so we do not add it. We go get the next edge from the priority queue.

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/kruskels.3.13.png" width="500">

----- 
`E → F`  is no longer a candidate. 


<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/kruskels.3.14.png" width="500">

----- 
Continuing on, we get the next available edge: `B → D` with a cost of 9.


<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/kruskels.3.15.png" width="500">

----- 

This edge **does** cause a cycle as well!, so we go get the next edge from the priority queue.


<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/kruskels.3.16.png" width="500">

----- 

`B → D`  is no longer a candidate. 

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/kruskels.3.17.png" width="500">

----- 

Next available edge is `E → G` with a cost of 9.

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/kruskels.3.18.png" width="500">

----- 

No cycles! We add it.

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/kruskels.3.19.png" width="500">

----- 

Behold our minumum spanning tree...

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/kruskels.3.20.png" width="500">


----- 

### Kruskels Code

#### Pseudo Code

```
	KruskalMST
       Tree = Ø
       while |Tree| < n-1 do
          choose e in E of minimum cost
          E := E - {e}
          if e does not create a cycle in T then
             T := T union {e}
```

#### C++

```cpp
	#include <cstdio>
	#include <vector>
	#include <algorithm>
	using namespace std;

	#define edge pair< int, int >
	#define MAX 1001

	// ( w (u, v) ) format
	vector< pair< int, edge > > GRAPH, MST;
	int parent[MAX], total, N, E;

	int findset(int x, int *parent)
	{
    if(x != parent[x])
        parent[x] = findset(parent[x], parent);
    return parent[x];
	}

	void kruskal()
	{
    	int i, pu, pv;
    	sort(GRAPH.begin(), GRAPH.end()); // increasing weight
    	for(i=total=0; i<E; i++)
    	{
        	pu = findset(GRAPH[i].second.first, parent);
        	pv = findset(GRAPH[i].second.second, parent);
        	if(pu != pv)
        	{
            	MST.push_back(GRAPH[i]); // add to tree
            	total += GRAPH[i].first; // add edge cost
            	parent[pu] = parent[pv]; // link
        	}
    	}
	}

	void reset()
	{
    	// reset appropriate variables here
    	// like MST.clear(), GRAPH.clear(); etc etc.
    	for(int i=1; i<=N; i++) parent[i] = i;
	}

	void print()
	{
    	`int i, sz;
    	// this is just style...
    	sz = MST.size();
    	for(i=0; i<sz; i++)
    	{
       		printf("( %d", MST[i].second.first);
        	printf(", %d )", MST[i].second.second);
        	printf(": %d\n", MST[i].first);
    	}
    	printf("Minimum cost: %d\n", total);`
	}

	int main()
	{
		int i, u, v, w;

    	scanf("%d %d", &N, &E);
    	reset();
    	for(i=0; i<E; i++)
    	{
        	scanf("%d %d %d", &u, &v, &w);
        	GRAPH.push_back(pair< int, edge >(w, edge(u, v)));
    	}
    	kruskal(); // runs kruskal and construct MST vector
    	print(); // prints MST edges and weights

    	return 0;
	}
```


## Prim's Algorithm

----- 

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/prims.1.1.png" width="500">

----- 

- Choose a starting point (it could be any of the vertices).  
- Add this vertex to your set if vertices belonging to your MST.
- Cut the graph so that vertices belonging to the MST are on one side of the cut, and all others are on the other side.
- This cut crosses: `A → D` cost 5 and `A → B` cost 7.
- We want to choose the "edge" with the least cost that cross the cut. 
- In this case edge `A → D` has least cost of 5.

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/prims.1.2c.png" width="500">

----- 

- We have our first "edge" added to the MST and our set of vertices now contains `A` and `D`


<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/prims.1.3.png" width="500">

----- 

- We again cut the graph seperating the vertices in the MST vs those not.
- This cut crosses 4 edges: 
  - `A → B` (7) , `B → D`(9), `D → E`(15), and `D → F`(6)
- The least cost is `D → F`

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/prims.1.4.png" width="500">

----- 

- We add `D → F` to our MST.

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/prims.1.5.png" width="500">

----- 

- We continue cutting the graph seperating the vertices in the MST vs those not.
- This cut crosses 5 edges.
  - `A → B` (7) , `B → D`(9), `D → E`(15), `E → F`(8), and `F → G`(11)
- The least cost is `A → B` 

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/prims.1.7.png" width="500">

----- 

- `A → B` is now in our MST adding `B` to our set of MST vertices.

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/prims.1.15.png" width="500">


----- 

- We continue cutting the graph seperating the vertices in the MST vs those not.
- This cut crosses 5 edges.
  - `B → C` (8) , `B → E`(7), `D → E`(15), `E → F`(8), and `F → G`(11)
- - The least cost is `B → E` 

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/prims.1.9.png" width="500">

----- 
- Now we have `B → E` added to the MST with `E` getting added to our vertex set in the MST.
  
<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/prims.1.16.png" width="500">

----- 

- We continue cutting the graph seperating the vertices in the MST vs those not.
- This cut crosses 4 edges.
  - `B → C` (8) , `C → E`(5), `E → G`(9), and `F → G`(11)
- - The least cost is `C → E` 

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/prims.1.10.png" width="500">

----- 
- `C → E` added to our MST also adding `C` to our MST's vertex set.
  
<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/prims.1.11.png" width="500">

----- 

- We continue cutting the graph seperating the vertices in the MST vs those not.
- This cut crosses 2 edges.
  - `E → G` (9) and `F → G`(11)
- `E → G` is the cheapest.

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/prims.1.12.png" width="500">


----- 

- We add `E → G` to  the MST
- The vertex set of vertices NOT in the MST is empty.
- We stop.

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/prims.1.13.png" width="500">

----- 

- Here is your MST

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/prims.1.14.png" width="500">

### Prims Code

**Prim's algorithm** is very similar to **Kruskal's Algorithm**. Both are very greedy and are used to find minimum spanning trees in weighted, connected, undirected graphs. The only real differences between the two is that Prim's algorithm can only add nodes adjacent to the current tree and any node can be added as the starting node.


#### Pseudo Code
```
	Given a graph, G, with edges E of the form (v1, v2) and vertices V

	dist : array of distances from the source to each vertex
	edges: array indicating, for a given vertex, which vertex in the tree it 
	       is closest to
	i    : loop index
	F    : list of finished vertices
	U    : list or heap unfinished vertices

	/* Initialization: set every distance to INFINITY until we discover a way to
	link a vertex to the spanning tree */
	for i = 0 to |V| - 1
	    dist[i] = INFINITY
	    edge[i] = NULL
	end

	pick a vertex, s, to be the seed for the minimum spanning tree

	/* Since no edge is needed to add s to the minimum spanning tree, its distance
	from the tree is 0 */
	dist[s] = 0

	
	while(F is missing a vertex)
	   pick the vertex, v, in U with the shortest edge to the group of vertices in
	       the spanning tree add v to F
	
	   /* this loop looks through every neighbor of v and checks to see if that
	    * neighbor could reach the minimum spanning tree more cheaply through v
	    * than by linking through a previous vertex */
	   for each edge of v, (v1, v2)
	        if(length(v1, v2) < dist[v2])
	            dist[v2] = length(v1, v2)
	            edges[v2] = v1
	            possibly update U, depending on implementation
	        end if
	    end for
	end while
```

#### C++

```cpp

	#include "ggraaf.h"
	#include <fstream>
	#include <queue>
	#include <map>
	#include <vector>
	using namespace std;

	// KnoopRelation is a class that represent a single connection
	// knoop_from = the connection starts
	// knoop_to = the connection ends
	// weight = the weight of the connection
	//
	// the operator < needs to be overloaded because we will create
	// objects of this class which will be added to a priority_queue
	// so the priority_queue needs to know on which values he need
	// to differentiate them from each other. 
	struct KnoopRelation {
		int knoop_from;
		int knoop_to;
		int weight;
		KnoopRelation(int k, int l, int g) : knoop_from(k), knoop_to(l), weight(g) {};

		bool operator<(const KnoopRelation& knoopje) const 
		{
       		return weight>knoopje.weight;   
    	}
	};

	// The prim class just calculates the minimal spanning tree
	// thats all...
	template <GraafType TYPE,typename T>
	class Prim {
		public:
			void setGraph(GewogenGraaf<TYPE, T> g);
			void minimalSpanningTree();
			bool contains(int k);
		protected:
			GewogenGraaf<TYPE, T> graph;
			priority_queue<KnoopRelation> priorqueue;
			vector<int> pad;
			vector<bool> discovered;
	};


	// Contains(int node)
	// check if a connection is not between 2 nodes that are already in the pad.
	// so only connections to nodes which aren't allready in the pad vector.
	template <GraafType TYPE,typename T>
	bool Prim<TYPE,T>::contains(int k){
		for(unsigned int i=0; i < pad.size();i++)
		if(k == pad[i])
			return true;
		else 
			return false;
	}

	// calculates minimal spanning tree with prim's algorithm
	template <GraafType TYPE,typename T>
	void Prim<TYPE,T>::minimalSpanningTree()
	{
		
		cout << "Running prim's legendary algorithm:" << endl;
		// sum of weights to calculate the total weight
		int weight = 0;
		
		// number of nodes
		unsigned int countnodes = graph.aantal_knopen();
		
		// initialize discovered
		discovered.reserve(countnodes);
		pad.reserve(countnodes);
		for(unsigned int i = 0; i < countnodes; i++)
			discovered[i] = false;
		
		// we start in 0 so this one is discovered
		int starting_point = 0;
		pad.push_back(starting_point);
		discovered[starting_point] = true;
		
		// loop for each node of the graph (so all nodes will contain the minimal spanning tree)
		// we need to add n-1 other nodes
		for(unsigned int i = 1; i < countnodes; i++)
		{
		
			// Get the connections
			// from our starting point
			map<int, int> connections = graph[starting_point];
			for(map<int, int>::iterator itr = connections.begin(); itr != connections.end(); ++itr)
			{
				// check if a connection to a new node
				if(!discovered[itr->first])
				{
					// create a new object and push it to the priority queue
					KnoopRelation rknoop(starting_point,(*itr).first,graph.gewicht((*itr).second));
					priorqueue.push(rknoop);
				}
			}

			// we cancel all bad nodes (which are already in our MOB)
			while(pad.size()!=countnodes && discovered[priorqueue.top().knoop_to])
				priorqueue.pop();
			
			// we discovered our new node that we will add
			// to our MOB
			discovered[priorqueue.top().knoop_to] = true;
			
			// get the minimal pad from the priority queue
			pad.push_back(priorqueue.top().knoop_to);
			
			// add new weight to total weight
			weight += priorqueue.top().weight;
			
			// prints out the minimal destination , from --- (weight)--> to
			cout << priorqueue.top().knoop_from << "---- (weight:"<< 
				priorqueue.top().weight <<") ---->" << 
				priorqueue.top().knoop_to << endl;
			
			// Our new starting_point
			starting_point = priorqueue.top().knoop_to;
			
		}
	
		cout << "Total weight: " << weight << endl;
	
	}

	// sets graph in the prim class
	template <GraafType TYPE,typename T>
	void Prim<TYPE,T>::setGraph(GewogenGraaf<TYPE, T> g)
	{
		graph = g;
	}


	int main() {
	
		GewogenGraaf<ONGERICHT, int> g;
		
		ifstream fileReader;
		string file = "graaf.txt";
		fileReader.open(file.c_str());
		
		// check if file exists (try opening it)
		if(!fileReader.is_open()){
			cout << "Can't open: " << file << endl;
			return 1;
		}
	
		// pass file to lees method of class ggraph.ccp
		// this method reads out the file and creates a graph structure
		try {
			g.lees(fileReader);
		} catch (GraafExceptie ge) {
			cout << ge << endl;
			return 1;
		}
	
		// create prim object and runs prim's algorithm on the weighted graph object
		Prim<ONGERICHT, int> primalgoritme;
		primalgoritme.setGraph(g);
		primalgoritme.minimalSpanningTree();
	 
		int end;
		cin >> end;
		return 0;
```

#### Works Cited

- [http://en.wikipedia.org/wiki/Prim's_algorithm](http://en.wikipedia.org/wiki/Prim's_algorithm)
- [http://blog.cedric.ws/c-prims-algortihm](http://blog.cedric.ws/c-prims-algortihm)
- [http://www.cprogramming.com/tutorial/computersciencetheory/mst.html](http://www.cprogramming.com/tutorial/computersciencetheory/mst.html)
- [http://zobayer.blogspot.com/2010/01/kruskals-algorithm-in-c.html](http://zobayer.blogspot.com/2010/01/kruskals-algorithm-in-c.html)
- [http://en.wikipedia.org/wiki/Kruskal's_algorithm](http://en.wikipedia.org/wiki/Kruskal's_algorithm)
- [http://en.wikipedia.org/wiki/Greedy_algorithm](http://en.wikipedia.org/wiki/Greedy_algorithm)

