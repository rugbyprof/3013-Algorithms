#include "Graph.hpp"
#include "Heap.hpp"
#include "JsonFacade.hpp"
#include "json.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string.h>

using namespace std;

using json = nlohmann::json;

int LoadCities(City **&Cities, string filename) {
    json obj;
    JsonFacade J(filename);
    int size;

    size = J.getSize();
    Cities = new City *[size];
    // loads an array of cities with the json data
    for (int i = 0; i < size; i++) {
        obj = J.getNext();
        //cout << obj["city"] << endl;
        Cities[i] = new City(obj, i);
        if (Cities[i]->name == "Dallas")
            cout << i << " " << Cities[i]->name << endl;
    }
    return size;
}

int main(int argc, char **argv) {

    int numEdges = 5;                // Initial number of edges
    json obj;                        // json object
    City **Cities;                   // Array of city pointers
    Edge *edge;                      // edge pointer to push onto heap
    string filename = "cities.json"; // our json city file
    double distance = 0.0;           // distance var
    int NumCities = 0;               // city count

    Heap<Edge> H(1000, false);

    Graph G;

    if (argc > 1) {
        numEdges = stoi(argv[1]);
    }

    NumCities = LoadCities(Cities, filename);

    // load all vertices (cities) into graph
    for (int i = 0; i < NumCities; i++) {
        G.AddVertex(Cities[i]);
    }

    // Generate edges
    for (int i = 0; i < NumCities; i++) {
        for (int j = 0; j < NumCities; j++) {
            if(i != j){
                distance = Cities[i]->Distance(Cities[j]->lat, Cities[j]->lon);
                edge = new Edge(Cities[i]->id, Cities[j]->id, distance);
                edge = new Edge(Cities[j]->id, Cities[i]->id, distance);
                H.Insert(edge);
            }
        }
        for (int c = 0; c < numEdges; c++) {
            edge = H.Extract();
            if(!G.AddEdge(edge->from, edge->to, edge->distance)){
                cout<<"double edge!!\n";
            }
        }
        H.Clear();
    }
    //G.PrintGraph();
    G.DepthFirst();
    cout<<endl<<endl<<endl;
    G.ResetGraph();
    queue<City*> path = G.BreadthFirst();
    G.buildGeoJson(path);
}