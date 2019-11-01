/**
* Example 4
 * This example loads a bunch of geoPoints representing all the 
 * cities in Texas. It then prints a geoJson file including all
 * of those geoJson features.
 * 
 */
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
    GeoJson GJ;                                 // geojson object

    // Get all the cities loaded into our vector
    TexasCities = LoadCities(filename,state);

    // Loop through the vector and create "geoPoints" adding property information including descriptions and colors.
    for(int i=0;i<TexasCities.size();i++){

        // Add the point using the city's lat and lon getting back the feature id from GeoJson
        int id = GJ.AddGeoPoint(TexasCities[i]->lon,TexasCities[i]->lat);

        // Create a string description to place inside the marker for mouse clicks and such
        string description = "Pop: " + to_string(TexasCities[i]->population) + " Growth: " + to_string(TexasCities[i]->growth);

        // Using the "id" we got back from GJ, we can add properties for this geoPoint
        // An overloaded method to add a point along with its properties would be handy, so you write it :) 
        GJ.AddProperties(id,{
            {"title",TexasCities[i]->name},
            {"description",description},
            {"marker-symbol","city"},
            {"marker-color",Colors.GetRandomColor()},
            {"marker-size","small"},
        });
    }

    // Generate our geojson output.
    GJ.PrintJson("example_4.geojson");

}