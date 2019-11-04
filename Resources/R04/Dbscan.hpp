#include "json.hpp"


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

class Dbscan{
    Dbscan(){
        
    }
};