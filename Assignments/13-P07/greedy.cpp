// CPP code for printing shortest path between
// two vertices of unweighted graph
#include <iostream>
#include <list>
#include <vector>

using namespace std;

typedef vector<int> vi;     // vector of integers
typedef pair<int, int> ii;  // pair of integers
typedef vector<ii> vii;     // vector of pairs

// utility function to form edge between two vertices
// source and dest
void add_edge(vector<vii> &adj, int src, int dest,int weight) {
    adj[src].push_back(make_pair(dest,weight));
    adj[dest].push_back(make_pair(src,weight));
}

// a modified version of BFS that stores predecessor
// of each vertex in array p
// and its distance from source in array d
bool BFS(vector<vii> &adj, int src, int dest, int v, int pred[], int dist[]) {
    // a queue to maintain queue of vertices whose
    // adjacency list is to be scanned as per normal
    // DFS algorithm
    list<int> queue;

    // boolean array visited[] which stores the
    // information whether ith vertex is reached
    // at least once in the Breadth first search
    bool visited[v];

    // initially all vertices are unvisited
    // so v[i] for all i is false
    // and as no path is yet constructed
    // dist[i] for all i set to infinity
    for (int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }

    // now source is first to be visited and
    // distance from source to itself should be 0
    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);

    // standard BFS algorithm
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        cout<<"u: "<<adj[u].size()<<endl;
        for (int i = 0; i < adj[u].size(); i++) {
            if (visited[adj[u][i].first] == false) {
                visited[adj[u][i].first] = true;
                
                cout<<dist[u]<<" + "<<adj[u][i].second<<" < "<<dist[adj[u][i].first]<<endl;
                if(dist[u] + adj[u][i].second < dist[adj[u][i].first]){
                    dist[adj[u][i].first] = dist[u] + adj[u][i].second;
                    pred[adj[u][i].first] = u;
                }

                cout<<"pushing: "<<adj[u][i].first<<endl;
                queue.push_back(adj[u][i].first);

                // We stop BFS when we find
                // destination.
                if (adj[u][i].first == dest)
                    return true;
            }
        }
    }

    for(int i=0;i<v;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;

    return false;
}

// utility function to print the shortest distance
// between source vertex and destination vertex
void printShortestDistance(vector<vii> &adj, int s, int dest, int v) {
    // predecessor[i] array stores predecessor of
    // i and distance array stores distance of i
    // from s
    int pred[v], dist[v];

    if (BFS(adj, s, dest, v, pred, dist) == false) {
        cout << "Given source and destination"
             << " are not connected";
        return;
    }

    // vector path stores the shortest path
    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }

    // distance from source is in distance array
    cout << "Shortest path length is : "
         << dist[dest];

    // printing path from source to destination
    cout << "\nPath is::\n";
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
}

// Driver program to test above functions
int main() {
    // no. of vertices so we can create a vector of the
    // correct size.
    int v,w;
    char s,t;
    char source; 
    char dest;

    cin>>v;

    // array of vectors is used to store the graph
    // in the form of an adjacency list
    vector<vii> adj;

    adj.resize(v+1);


    // Creating graph given in the above diagram.
    // add_edge function takes adjacency list, source
    // and destination vertex as argument and forms
    // an edge between them.

    for(int i=0;i<v;i++){
        cin>>s>>t>>w;
        add_edge(adj, (int)s-65, (int)t-65, w);
        cout<<(int)s-65<<","<<(int)t-65<<","<<w<<endl;
    }
    cin>>source>>dest;
    cout<<source<<" "<<dest<<endl;
    // add_edge(adj, 0, 1, 3);
    // add_edge(adj, 0, 3, 4);
    // add_edge(adj, 1, 2, 2);
    // add_edge(adj, 3, 4, 1);
    // add_edge(adj, 3, 7, 5);
    // add_edge(adj, 4, 5, 4);
    // add_edge(adj, 4, 6, 3);
    // add_edge(adj, 4, 7, 7);
    // add_edge(adj, 5, 6, 2);
    // add_edge(adj, 6, 7, 3);

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < (int)adj[i].size(); j++) {
            cout << i << " -> " << adj[i][j].first << "  ["
                 << adj[i][j].second << "]" << endl;
        }
    }

   
    printShortestDistance(adj, (int)source-65, (int)dest-65, v);
    return 0;
}
