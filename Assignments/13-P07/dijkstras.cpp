// A C++ program for Dijkstra's single source shortest path algorithm. 
// The program is for adjacency matrix representation of the graph 

#include <iostream>

using namespace std;

// Number of vertices in the graph 
//#define V 9 

int ctoi(char c){
    return (int)c-65;
}

char itoc(int i){
    return (char)i+65;
}

// A utility function to find the vertex with minimum distance value, from 
// the set of vertices not yet included in shortest path tree 
int minDistance(int dist[], bool sptSet[],int V) 
{ 
	// Initialize min value 
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (sptSet[v] == false && dist[v] <= min) 
			min = dist[v], min_index = v; 

	return min_index; 
} 

// A utility function to print the constructed distance array 
void printSolution(int dist[],int V) 
{ 
	printf("Vertex \t\t Distance from Source\n"); 
	for (int i = 0; i < V; i++){
        cout<<itoc(i)<<"\t\t"<<dist[i]<<endl;
		//printf("%s \t\t %d\n", itoc(i), dist[i]);
    }
} 

// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
void dijkstra(int** graph, int src,int V) 
{ 
	int dist[V]; // The output array. dist[i] will hold the shortest 
	// distance from src to i 

	bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest 
	// path tree or shortest distance from src to i is finalized 

	// Initialize all distances as INFINITE and stpSet[] as false 
	for (int i = 0; i < V; i++) 
		dist[i] = INT_MAX, sptSet[i] = false; 

	// Distance of source vertex from itself is always 0 
	dist[src] = 0; 

	// Find shortest path for all vertices 
	for (int count = 0; count < V - 1; count++) { 
		// Pick the minimum distance vertex from the set of vertices not 
		// yet processed. u is always equal to src in the first iteration. 
		int u = minDistance(dist, sptSet,V); 

		// Mark the picked vertex as processed 
		sptSet[u] = true; 

		// Update dist value of the adjacent vertices of the picked vertex. 
		for (int v = 0; v < V; v++) 

			// Update dist[v] only if is not in sptSet, there is an edge from 
			// u to v, and total weight of path from src to v through u is 
			// smaller than current value of dist[v] 
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
				&& dist[u] + graph[u][v] < dist[v]) 
				dist[v] = dist[u] + graph[u][v]; 
	} 

	// print the constructed distance array 
	printSolution(dist,V); 
} 

int** Make2dArray(int width,int height){

    int** graph;

    graph = new int*[height];

    for(int i=0;i<height;i++){
        graph[i] = new int[width];
    }

    return graph;

}



// driver program to test above function 
int main() 
{ 
    int v,w,e,is,id;
    char s,t,cs,cd;


    cin>>v;
    cout<<v<<endl;

    cin>>e;

    v = v+1;

    int** graph = Make2dArray(v,v);

    for(int i=0;i<e;i++){
        cin>>s>>t>>w;
        cout<<ctoi(s)<<","<<ctoi(t)<<","<<w<<endl;
        graph[ctoi(s)][ctoi(t)] = w;
        graph[ctoi(t)][ctoi(s)] = w;
        cout<<(int)s-65<<","<<(int)t-65<<","<<w<<endl;
    }
    cin>>cs>>cd;
    is = ctoi(cs);
    id = ctoi(cd);

    dijkstra(graph, 0,v); 

    //Print the array if needed.
    // for(int i=0;i<v;i++){
    //     for(int j=0;j<v;j++){
    //         cout<<graph[i][j]<<", ";
    //     }
    //     cout<<endl;
    // }
    

	return 0; 
} 
