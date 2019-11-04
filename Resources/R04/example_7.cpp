/**
 * Example 7
 * This example places all edges on a heap with the highest priority
 * going to the shortest edges. It adds edges to a "spanning tree"
 * based on whethor or not both "from" and "to" are NOT in the tree
 * already. Not a good method as you can see by the geojson.
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
vector<City *> LoadCities(string filename, string state="") {
    json obj;
    JsonFacade J(filename);
    vector<City *> Cities;

    // loads an array of cities from specified state
    for (int i = 0, id = 0; i < J.getSize(); i++) {
        obj = J.getNext();

        if (obj["state"] == state || state == "") {
            Cities.push_back(new City(obj, id));
            id++;
        }
    }
    return Cities;
}

json EdgeToLine(vector<City *> Cities,Edge* e){
    json temp = json::object();
    temp["line"] = {
            {Cities[e->from]->lon,Cities[e->from]->lat},
            {Cities[e->to]->lon,Cities[e->to]->lat}
    };
    temp["from"] = Cities[e->from]->name;
    temp["to"] = Cities[e->to]->name;
    return temp;
}


int main(int argc, char **argv) {

    int numEdges = 3;
    if(argc >= 2){
        numEdges = stoi(argv[1]);
    }

    string filename = "cities_all.json"; // our json city file
    string state = "Texas";              // Filter cities for Texas only
    vector<City *> Cities;          // Array of city pointers
    HexColors Colors;                    // Random colors
    GeoJson GJ;
    Heap<City> cityHeap(false);          // A heap that holds cities to find closest city.
    Graph G;

    double lat;                          // used to help with distance calculations
    double lon;                          // and for code readability
    double distance;
    City* city;


    // Get all the cities loaded into our vector
    Cities = LoadCities(filename);

    for (int i = 0; i < Cities.size(); i++) {
        G.AddVertex(Cities[i]);
        int markerID = GJ.AddGeoPoint(Cities[i]->lon,Cities[i]->lat);
        GJ.AddProperties(markerID,{{"name",Cities[i]->name},{"marker-color",Colors.GetRandomColor()}});
    }

    // Build a heap with ALL the edges (fully connected)
    // between every city in Texas.
    for (int i = 0; i < Cities.size(); i++) {
        lat = Cities[i]->lat;
        lon = Cities[i]->lon;
        for (int j = 0; j < Cities.size(); j++) {
            if(i != j){
                Cities[j]->priority = Cities[j]->Distance(lat,lon);
                cityHeap.Insert(Cities[j]);
            }
        }

        for(int e=0;e<numEdges;e++){
            city = cityHeap.Extract();
            G.AddEdge(Cities[i]->id,city->id,city->priority);
        }
        cityHeap.Clear();
    }


    //G.PrintGraph();
    queue<City*> Path = G.BreadthFirst();
    City* temp;
    json line = json::array();
    int lineNumber = 0;


    while(Path.size()){
        temp = Path.front();
        Path.pop();
        if(temp->name != ""){
            line.push_back({temp->lon,temp->lat});
            cout<<"adding connection->";
        }else{
            if(line.size() > 1){
                GJ.AddLineString(line);
            }else{

                //GJ.AddGeoPoint(line);
            }
            
            line = json::array();
            cout<<"adding line\n";
        }
        
        
    }

   

    // Generate our geojson output.
    GJ.PrintJson("example_7.geojson");

    
 
}

