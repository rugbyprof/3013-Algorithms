#include <iostream>
#include <fstream>
#include <string.h>
#include "Heap.hpp"
#include "JsonFacade.hpp"
#include "json.hpp"

using namespace std;

using json = nlohmann::json;

struct City{
    int Priority;
    string Name;
    City(){
        Priority = 0;
        Name = "";
    }
    City(json obj){
        Name = obj["city"];
        Priority = obj["population"];
    }
};

int main(){
    json obj;
    City** Cities;
    City* temp;
    string filename = "cities.json";
    JsonFacade J(filename);

    Heap <City> H(1000,false);

    int size = J.getSize();
    Cities = new City *[size];
    // loads an array of cities with the json data
    for (int i = 0; i < size; i++) {
        obj = J.getNext();
        Cities[i] = new City(obj);
    }


    // calling heapify 
    H.Heapify(Cities,size);

    int i = 0;
    while(!H.Empty()){
        temp = H.Extract();
        cout<<i<<" "<<temp->Name<< " " <<temp->Priority << endl;
        i++;
    }
}

