/**
 * Example 7
 * This example will use a heap to push "edges" onto allowing us to find
 * edges based on a "priority" (whatever we determine the priority to be).
 * In this case each edge will have a distance between "from" and "to" and
 * we will use that as a priority to find short or long edges. If we load 
 * the Heap with edges, then pick off only the shortest edges, we can create
 * a minimum spanning tree! This will be a cheat MST implementation, because we
 * are creating edges solely based on distance and also creating a fully connected
 * graph (convenient), and not any other pre-existing criteria. 
 * 
 */
#include "City.hpp"
#include "GeoJson.hpp"
#include "Graph.hpp"
#include "Heap.hpp"
#include "HexColors.hpp"
#include "JsonFacade.hpp"
#include "json.hpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

using json = nlohmann::json;

/**
 * Description:
 *     This function gets a filename and a state. It loads
 *     a vector of city pointers and returns it. 
 * Depends on:
 *     json.hpp
 *     City.hpp
 * Params:
 *     string filename : json file to open 
 *     string state : name of us state to filter by
 * 
 * Returns:
 *     vector of city pointers. 
 */
vector<City *> LoadCities(string filename, string state) {
    json obj;
    JsonFacade J(filename);
    vector<City *> Cities;

    // loads an array of cities from specified state
    for (int i = 0, id = 0; i < J.getSize(); i++) {
        obj = J.getNext();

        if (obj["state"] == state) {
            Cities.push_back(new City(obj, id));
            id++;
        }
    }
    return Cities;
}

json EdgeToLine(vector<City *> TexasCities,Edge* e){
    json temp = json::object();
    temp["line"] = {
            {TexasCities[e->from]->lon,TexasCities[e->from]->lat},
            {TexasCities[e->to]->lon,TexasCities[e->to]->lat}
    };
    temp["from"] = TexasCities[e->from]->name;
    temp["to"] = TexasCities[e->to]->name;
    return temp;
}

bool inSpanTree(vector<int> st,int key){
    for(int i=0;i<st.size();i++){
        if(st[i] == key){
            return true;
        }
    }
    return false;
}

int main(int argc, char **argv) {

    string filename = "cities_all.json"; // our json city file
    string state = "Texas";              // Filter cities for Texas only
    vector<City *> TexasCities;          // Array of city pointers
    HexColors Colors;                    // Random colors
    GeoJson *GJ = new GeoJson();         // geojson object
    Heap<Edge> edgeHeap(false);          // A heap that holds edges to find shortest edges.

    double lat;                          // used to help with distance calculations
    double lon;                          // and for code readability
    double distance;
    Edge* edge;
    vector<int> SpanTree;

    // Get all the cities loaded into our vector
    TexasCities = LoadCities(filename, state);


    // Build a heap with ALL the edges (fully connected)
    // between every city in Texas.
    for (int i = 0; i < TexasCities.size(); i++) {
        lat = TexasCities[i]->lat;
        lon = TexasCities[i]->lon;
        for (int j = 0; j < TexasCities.size(); j++) {
            if(i != j){
                distance = TexasCities[j]->Distance(lat,lon);

                edge = new Edge(i,j,distance);

                edgeHeap.Insert(edge);
            }
        }
    }

    while(SpanTree.size() < TexasCities.size()){

        edge = edgeHeap.Extract();

        while(!inSpanTree(SpanTree,edge->from) || !inSpanTree(SpanTree,edge->to)){
            edge = edgeHeap.Extract();
            json temp = EdgeToLine(TexasCities,edge);
            
            string description = "From: " + to_string(temp["from"]) + " To: " + to_string(temp["to"]);

            if(!inSpanTree(SpanTree,edge->from)){
                SpanTree.push_back(edge->from);
            }

            if(!inSpanTree(SpanTree,edge->to)){
                SpanTree.push_back(edge->to);
            }

            int id = GJ->AddLineString(temp["line"]);
            GJ->AddProperties(id,{
                {"description",description},
                {"stroke",Colors.GetRandomDarkColor()},
                {"stroke-opacity","0.7"},
            });
        }
    }
    // Generate our geojson output.
    GJ->PrintJson("example_7.geojson");
    cout<<edgeHeap.Size()<<endl;
    cout<<TexasCities.size()<<endl;
}

