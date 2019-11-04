/**
 * Example 5
 * Based on example  4, this will take a starting city, then wastefully
 * loop through each other city finding the closest neighbor then drawing
 * a line to that city. This will be a greedy shortest tour, but NOT
 * guaranteed to be the actual shortest tour when visiting all cities.
 * Or is it ? ....
 * 
 * 
 */
#include <fstream>
#include <iostream>
#include <string>
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

    ///// END EXAMPLE 4 

    /// START EXAMPLE 5
    string start = "El Paso";

    // we can change starting city by command line param
    if(argc > 1){
        start = argv[1];
    }

    int current_id=0;               // current city looking for closest neighbor
    int num_visited = 0;            // how many cities have we visited
    double min_distance = 99999;    // current min distance start big so first will be lower
    int min_id = 0;                 // current closest city.
    double distance = 0;            // current distance to compare to min_distance
    string description = "";        // for later when we put a description on a line
    int id;                         // id for later when we add properties to a line


    // First we need to find the starting city in the array of cities
    // so we can get its "id" (index number)
    for(int i=0;i<TexasCities.size();i++){
        if(TexasCities[i]->name == start){
            current_id = i;
            TexasCities[i]->visited = 1;
            num_visited++;
            break;
        }
    }

    // While we have not visited everyone
    // - find closest neighbor
    // - mark them as visited
    // - make them the current city
    // - go again
    while(num_visited < TexasCities.size()){
        for(int i=0;i<TexasCities.size();i++){

            // skip already visited cities
            if(TexasCities[i]->visited){
                continue;
            }
            // get lat lon to calc distance
            double lat = TexasCities[i]->lat;
            double lon = TexasCities[i]->lon;
            distance = TexasCities[current_id]->Distance(lat,lon);

            // if distance is smaller than the previous closest
            // then make it the new closest
            if(distance < min_distance && i != current_id){
                min_distance = distance;
                min_id = i;
            }
        }

        // Mark closest city as visited (so we don't go back)
        TexasCities[min_id]->visited = 1;

        // increment number visited so we know when to stop
        num_visited++;

        // make my geojson line
        id = GJ.AddLineString(json {{TexasCities[current_id]->lon,TexasCities[current_id]->lat},{TexasCities[min_id]->lon,TexasCities[min_id]->lat}});
        description = TexasCities[current_id]->name + " to " + TexasCities[min_id]->name;
        GJ.AddProperties(id,{
            {"description",description},
            {"stroke",Colors.GetRandomColor()},
            {"stroke-opacity","0.7"},
        });
        // reset the values and make the closest the new current
        min_distance = 99999;
        current_id = min_id;
    }

    // Generate our geojson output.
    GJ.PrintJson("example_5.geojson");

}