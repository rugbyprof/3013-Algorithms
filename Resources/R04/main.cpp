#include "Graph.hpp"
#include "Heap.hpp"
#include "GeoJson.hpp"
#include "JsonFacade.hpp"
#include "json.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string.h>
#include "HexColors.hpp"

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

    }
    return size;
}

int main(int argc, char **argv) {

    int numEdges = 5;                // Initial number of edges
    json obj;                        // json object
    City **Cities;                   // Array of city pointers
    Edge *edge;                      // edge pointer to push onto heap
    string filename = "cities_all.json"; // our json city file
    double distance = 0.0;           // distance var
    int NumCities = 0;               // city count

    HexColors Colors;

    Heap<Edge> H(1000, false);

    Graph G;

    GeoJson geoJsonCities;

    if (argc > 1) {
        numEdges = stoi(argv[1]);
    }

    NumCities = LoadCities(Cities, filename);

    // load all vertices (cities) into graph
    for (int i = 0; i < NumCities; i++) {
        G.AddVertex(Cities[i]);
        int markerID = geoJsonCities.AddGeoPoint(Cities[i]->lon,Cities[i]->lat);
        geoJsonCities.AddProperties(markerID,{{"name",Cities[i]->name},{"marker-color",Colors.GetRandomColor()}});
    }

    geoJsonCities.PrintJson("pretty99.json");

    // Generate edges
    for (int i = 0; i < NumCities; i++) {
        for (int j = 0; j < NumCities; j++) {
            if(i != j){
                distance = Cities[i]->Distance(Cities[j]->lat, Cities[j]->lon);
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

    std::vector<std::pair<double, double>> path2;

    G.DepthFirst();
    cout<<endl<<endl<<endl;
    G.ResetGraph();
    queue<City*> path = G.BreadthFirst();
    G.buildGeoJson(path);

    json linearray = json::array();

    GeoJson GJ4;
    int cutoff = 0;

    City* temp1 = path.front();
    path.pop();

    string color = Colors.GetRandomColor();

    while(path.size() > 0){
        City* temp2 = path.front();
        path.pop();

        if(temp2->lat == 0 && temp2->lon == 0){
            color = Colors.GetRandomColor();
            temp1 = path.front();
            path.pop();
            temp2 = path.front();
            path.pop();
        }

        int id = GJ4.AddLineString(json {{temp1->lon,temp1->lat},{temp2->lon,temp2->lat}});
        GJ4.AddProperty(id,"stroke",color);
        GJ4.AddProperty(id,"stroke-width","3");

        temp1 = temp2;

        // cutoff++;
        // if(cutoff > 100){
        //     break;
        // }
    }

    GJ4.PrintJson("pretty55.json");

    // for(int j=0;j<300;j++){
    //     path.pop();
    // }

    // GeoJson GJ;

    // cutoff = 0;
    // while(path.size() > 0){
    //     City* temp = path.front();
    //     path.pop();
    //     //linearray.push_back({});
    //     int cid = GJ.AddGeoPoint(temp->lon,temp->lat);
    //     GJ.AddProperty(cid,"marker-color",Colors.GetRandomColor());
        
    //     cutoff++;
    //     if(cutoff > 10){
    //         break;
    //     }
    // }
    

    
    // int line1 = GJ.AddLineString(path2);
    // int line2 = GJ.AddLineString(linearray);

    // json obj2 = json::object();

    // obj2["stroke"] = Colors.GetRandomColor();
    // obj2["stroke-width"] = "2";
    // obj2["stroke-opacity"] = "0.8";

    // GJ.AddProperty(line1,"stroke","#0000FF");
    // GJ.AddProperty(line1,"stroke-width","2");
    // GJ.AddProperty(line1,"stroke-opacity","0.8");

    // obj2["stroke"] = "#00FFFF";

    // GJ.AddProperties(line2,obj2);


    // GJ.PrintJson("pretty5.json");

}