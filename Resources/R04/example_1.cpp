/**
 * This is an example of how to add points to a "GeoJson" json object. 
 * It creates 3 points and colors adds colors (properties) to them. 
 * Then it writes out the resulting geojson to a file.
 * 
 */ 

#include <fstream>
#include <iostream>
#include <string.h>
#include "GeoJson.hpp"
#include "HexColors.hpp"

using namespace std;


int main(int argc, char **argv) {

    GeoJson GJ;
    HexColors Hex;

    double wichita_falls_latitude = 33.9137085;
    double wichita_falls_longitude = -98.4933873;

    double dallas_latitude = 32.7766642;
    double dallas_longitude = -96.7969878999;

    double norman_latitude = 35.2225668;
    double norman_longitude = -97.4394777;


    // The returned id is so we can reference the point in the object and add
    // colors etc to that geojson feature
    int id1 = GJ.AddGeoPoint(wichita_falls_longitude,wichita_falls_latitude);

    // Change the marker color for this marker using hex green
    GJ.AddProperty(id1,"marker-color","#00FF00");
    GJ.AddProperty(id1,"name","Wichita Falls");


    // We added a point for wichita falls, now lets add dallas
    int id2 = GJ.AddGeoPoint(dallas_longitude,dallas_latitude);

    // Change the marker color for this marker using a random color
    GJ.AddProperty(id2,"marker-color",Hex.GetRandomColor());  
    GJ.AddProperty(id2,"name","Dallas");

    // We added 1 more point for norman
    int id3 = GJ.AddGeoPoint(norman_longitude,norman_latitude);

    // Change the marker color for this marker using a random color
    GJ.AddProperty(id3,"marker-color",Hex.GetRandomColor());  
    GJ.AddProperty(id3,"name","Dallas");

    // Print the geojson to an output file
    GJ.PrintJson("example_1.geojson");

}