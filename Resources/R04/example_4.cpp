#include <fstream>
#include <iostream>
#include <string.h>
#include "GeoJson.hpp"
#include "JsonFacade.hpp"
#include "json.hpp"
#include "HexColors.hpp"
#include "City.hpp"

using namespace std;

using json = nlohmann::json;


vector<City*> LoadCities(string filename,string state) {
    json obj;
    JsonFacade J(filename);
    vector<City*> Cities;

   
    // loads an array of cities from specified state
    for (int i = 0,id=0; i < J.getSize(); i++) {
        obj = J.getNext();

        if(obj["state"] == state){
            Cities.push_back(new City(obj, id));
            id++; 
        }
    }
    return Cities;
}

int main(int argc, char **argv) {


    string filename = "cities_all.json";        // our json city file
    string state = "Texas";                     // Filter cities for Texas only
    vector<City*> TexasCities;                  // Array of city pointers
    HexColors Colors;                           // Random colors
    GeoJson GJ;

    TexasCities = LoadCities(filename,state);

    for(int i=0;i<TexasCities.size();i++){
        int id = GJ.AddGeoPoint(TexasCities[i]->lon,TexasCities[i]->lat);
        string description = "Pop: " + to_string(TexasCities[i]->population) + " Growth: " + to_string(TexasCities[i]->growth);
        GJ.AddProperties(id,{
            {"title",TexasCities[i]->name},
            {"description",description},
            {"marker-name","city"},
            {"marker-color",Colors.GetRandomColor()},
            {"marker-size","small"},
        });
    }

    GJ.PrintJson("example_4.geojson");

}