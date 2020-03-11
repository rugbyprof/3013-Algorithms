#include <iostream>
#include <vector>
#include <string>
#include <queue>

#define endl "\n"

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int VISITED = 1;
const int UNVISITED = -1;

vi search_order;
vector<vii> AdjList;

void dfs(int u) {
    search_order[u] = VISITED;
    cout << u << " ";
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        
        if (search_order[v.first] == UNVISITED) {
            dfs(v.first);
        }
    }
}

void bfs(int u) {
    queue<int> q;

    q.push(u);

    while (!q.empty()) {
        int s = q.front();
        search_order[s] = VISITED;
        q.pop();

        cout << s << " ";

        for (int t = 0; t < (int)AdjList[s].size(); t++) {
            ii v = AdjList[s][t];
           
            if (search_order[v.first] == UNVISITED) {
                q.push(v.first);
                search_order[v.first] = VISITED;
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

    // vi search_order;
    // vector<vii> AdjList;

    cin >> n >> m;

    AdjList.resize(n + 1);
    search_order.resize(n + 1, UNVISITED);

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        cout << u << " " << v << endl;

    /*Here u->v is the edge and pair second term can be used to store weight in
      case of weighted graph.
    */
        AdjList[u].push_back(make_pair(v, 10));
    }

    // To print the edges stored in the adjacency list
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (int)AdjList[i].size(); j++) {
            cout << "Edge is " << i << " -> " << AdjList[i][j].first << "["
                 << AdjList[i][j].second << "]" << endl;
        }
    }

    dfs(1);

    // reset values in search_order vector
    fill(search_order.begin(), search_order.end(), UNVISITED);

    cout << endl;

    bfs(1);

    return 0;
}