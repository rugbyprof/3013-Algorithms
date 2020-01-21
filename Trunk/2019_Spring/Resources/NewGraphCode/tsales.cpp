// A simple representation of graph using STL
#include "graph.h"

using namespace std;

void randomEdges(graph &g, int numEdges)
{
    int r1, r2;
    latlon from;
    latlon to;
    double d;
    for (int i = 0; i < numEdges; i++)
    {
        r1 = rand() % g.vertexList.size();
        r2 = rand() % g.vertexList.size();
        from = g.vertexList[r1]->loc;
        to = g.vertexList[r2]->loc;
        d = distanceEarth(from.lat, from.lon, to.lat, to.lon);
        g.addEdge(r1, r2, (int)d, true);
    }
}

/**
 * loadGraphCSV - loads a graph with the given csv
 * Params:
 *     string filename  - filename to open
 * Returns 
 *     graph
 */
graph loadGraphCSV(string filename, int max = 0, string fstate = "")
{
    string city;
    double growth;
    double lat;
    double lon;
    int pop;
    int rank;
    string state;

    strMapInt cityCheck;

    int i = 0;

    graph G;
    int vid;
    vertex *temp;

    ifstream file(filename);

    for (CSVIterator loop(file); loop != CSVIterator(); ++loop)
    {

        // "city": "New York",
        // "growth_from_2000_to_2013": "4.8%",
        // "latitude": 40.7127837,
        // "longitude": -74.0059413,
        // "population": "8405837",
        // "rank": "1",
        // "state": "New York"

        city = (*loop)[0];
        growth = stod((*loop)[1]);
        lat = stod((*loop)[2]);
        lon = stod((*loop)[3]);
        pop = stoi((*loop)[4]);
        rank = stoi((*loop)[5]);
        state = (*loop)[6];

        if(state == "Hawaii" || state == "Alaska"){
            continue;
        }

        cout<<city<<","<<state<<","<<lat<<","<<lon<<","<<growth<<","<<pop<<","<<rank<<endl;

        vid = G.addVertex(city, state, lat, lon, growth, pop, rank);
        i++;
        cout<<i<<endl;
    }

    return G;
}

// Test Driver
int main(int argc, char **argv)
{
    srand(984325);
    int max_vertices = 0;
    int max_edges = 0;
    string state = "NY";

    // if (argc > 2)
    // {
    //     max_vertices = stoi(argv[1]);
    //     max_edges = stoi(argv[2]);
    //     state = argv[3];
    // }
    // else
    // {
    //     cout << "Usage: ./graph max_vertices max_edges" << endl;
    //     exit(0);
    // }

    //cout<<"Creating graph...\n";
    graph G = loadGraphCSV("random_data_files/alter_top_1000_cities.csv", max_vertices, state);

    //cout<<"Adding edges ... \n";
    //G.createSpanningTree();
    G.createForest();
    //G.connectForest();
    //cout<<"Done...\n";

    //cout<<"Visualizing graph ... \n";
    G.magickGraph(10000, 6000, "magick.png");

    return 0;
}