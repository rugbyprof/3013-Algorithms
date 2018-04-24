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
    int zip;
    double lat;
    double lon;
    string city;
    string state;
    string county;

    strMapInt cityCheck;

    int i = 0;

    graph G;
    int vid;
    vertex* temp;

    ifstream file(filename);

    for (CSVIterator loop(file); loop != CSVIterator(); ++loop)
    {
        zip = stoi((*loop)[0]);
        if ((*loop)[1].length() > 0)
        {
            lat = stod((*loop)[1]);
        }
        else
        {
            lat = 0.0;
        }

        if ((*loop)[2].length() > 0)
        {
            lon = stod((*loop)[2]);
        }
        else
        {
            lon = 0.0;
        }

        city = (*loop)[3];
        state = (*loop)[4];
        county = (*loop)[5];


        if (cityCheck.find(city) == cityCheck.end())
        {
            // Add the city as a key to the map.
            cityCheck[city] = 0;

            if (fstate == "" || fstate == state)
            {   
                if((int)lat == 0 || (int) lon == 0){
                    cout<<"oops: "<<city<<", "<<state<<", "<<lat<<", "<<lon<<endl;
                }

                vid = G.addVertex(city, state, lat, lon);
            
            }
            i++;
        }

        if (i > max && max != 0)
        {
            return G;
        }
    }

    return G;
}

/**
 * filterDups - filters out duplicate cities and creates new output file
 * Params:
 *     string filename  - filename to open
 *     string outfile   - filename to write to
 * Returns 
 *     graph
 */
void filterDups(string filename, string outfile)
{
    int zip;
    double lat;
    double lon;
    string city;
    string state;
    string county;

    strMapInt cityCheck;

    int i = 0;

    ifstream file(filename);
    ofstream out(outfile);

    for (CSVIterator loop(file); loop != CSVIterator(); ++loop)
    {
        zip = stoi((*loop)[0]);
        if ((*loop)[1].length() > 0)
        {
            lat = stod((*loop)[1]);
        }
        else
        {
            lat = 0.0;
        }

        if ((*loop)[2].length() > 0)
        {
            lon = stod((*loop)[2]);
        }
        else
        {
            lon = 0.0;
        }

        city = (*loop)[3];
        state = (*loop)[4];
        county = (*loop)[5];

        if (cityCheck.find(city) == cityCheck.end() && abs(lat) > 0 && abs(lon) > 0)
        {
            // Add the city as a key to the map.
            cityCheck[city] = 0;
            out << zip << "," << lat << "," << lon << "," << city << "," << state << "," << county << "\n";
        }
    }
}

// Test Driver
int main(int argc, char **argv)
{
    srand(984325);
    int max_vertices = 0;
    int max_edges = 0;

    if (argc > 2)
    {
        max_vertices = stoi(argv[1]);
        max_edges = stoi(argv[2]);
    }
    else
    {
        cout << "Usage: ./graph max_vertices max_edges" << endl;
        exit(0);
    }

    cout<<"Creating graph...\n";
    graph G = loadGraphCSV("filtered_cities.csv", max_vertices, "TX");

    //filterDups("cities.csv","filtered_cities.csv");
    //randomEdges(G, max_edges);
    //G.printGraph();

    // cout << G.searchGraph("wichita falls") << endl;
    // cout << G.searchGraph("dallas") << endl;
  
    cout<<"Adding edges ... \n";
    G.createSpanningTree2();
    cout<<"Done...\n";
    
    //cout<<G.graphViz(false);

    cout<<"Visualizing graph ... \n";
    G.magickGraph(10000,6000,"magick2.png");

    //G.printVids();
    //int *size = G.graphSize();
    //cout<<"V= "<<size[0]<<" E= "<<size[1]<<endl;
    // for(int i=0;i<G.vertexList.size();i++){
    //     cout<<(*G.vertexList[i])<<endl;
    // }

    return 0;
}