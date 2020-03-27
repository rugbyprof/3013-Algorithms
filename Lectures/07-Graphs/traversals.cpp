#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define endl "\n"

using namespace std;

typedef vector<int> vi;     // vector of integers
typedef pair<int, int> ii;  // pair of integers
typedef vector<ii> vii;     // vector of pairs

const int VISITED = 1;
const int UNVISITED = -1;

vi been_visited;            // container to keep track of who get visited
vector<vii> AdjList;        // AdjList stores our edge lists

/**
 * Depth First Search
 * 
 * Params:
 *  int u - starting node id
 * 
 */
void dfs(int u) {
    // In DFS we use a stack structure to keep track of who to visit next.
    // Recursive acts just like a stack so we dont need to declare any 
    // structure to keep track for us, we let the recursive calls do it for us

    been_visited[u] = VISITED;  // mark u as visited
    cout << u << " ";           // write u to stdout

    // Loop overadjacency list looking for connections
    for (int j = 0; j < (int)AdjList[u].size(); j++) {

        // v is a pair representing a neighbor and the 
        // weight of the edge from u->v
        ii v = AdjList[u][j];

        cout<<u<<"->"<<v.first<<" with weight "<<v.second<<endl;

        // check to see if our neighbor was visited
        if (been_visited[v.first] == UNVISITED) {
            dfs(v.first);
        }
    }
}

/**
 * Breadth First Search
 * 
 * Params:
 *     int u - starting node id
 */
void bfs(int u) {
    // This is an iterative solution, so we declare a 
    // queue to keep track of who gets visited next
    queue<int> q;

    // Add u to our q
    q.push(u);

    // While q has nodes in it
    while (!q.empty()) {
        
        int s = q.front();          // remove front node 
        
        been_visited[s] = VISITED;  // visit front node
        q.pop();                    // remove from queue

        cout << s << " ";           // output

        // look for any unvisited neighbors of u
        for (int t = 0; t < (int)AdjList[s].size(); t++) {

            // v is a pair representing a neighbor and the 
            // weight of the edge from s->v
            ii v = AdjList[s][t];

            // if neighbor hasn't been visited, add to queue
            // and mark as visited
            if (been_visited[v.first] == UNVISITED) {
                q.push(v.first);
                been_visited[v.first] = VISITED;
            }
        }
    }

    cout << endl;
}

void greedy() {
}

int main(int argc, char **argv) {
    int n, m;
    int u, v;

    // vi been_visited;
    // vector<vii> AdjList;

    cin >> n >> m;

    AdjList.resize(n + 1);
    been_visited.resize(n + 1, UNVISITED);

    for (int i = 0; i < m; i++) {
        cin >> u >> v;

        // Here u is the start of the edge
        // So u connects to v (or u->v)
        // The 10 is a "weight" assigned to the edge 
        // 10 is just an arbitrary number 
        AdjList[u].push_back(make_pair(v, 10));
    }

    // To print the edges stored in the adjacency list
    cout<<"Adjacency List"<<endl;
    cout<<"U -> V  Weight"<<endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (int)AdjList[i].size(); j++) {
            cout << i << " -> " << AdjList[i][j].first << "  ["
                 << AdjList[i][j].second << "]" << endl;
        }
    }

    cout<<"Depth First Search:"<<endl;
    dfs(1);

    // reset values in been_visited vector
    fill(been_visited.begin(), been_visited.end(), UNVISITED);

    cout << endl;
    cout<<"Breadth First Search:"<<endl;
    bfs(1);

    return 0;
}