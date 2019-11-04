#pragma once
#include "json.hpp"
#include "JsonFacade.hpp"
#include <string.h>
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

using json = nlohmann::json;



struct Color{
    string name;
    string hex;
    Color(string n,string h){
        name = n;
        hex = h;
    }
    Color(json obj){
        name = obj["name"];
        hex = obj["hex"];
    }
};

class HexColors{
private:
    Color** Colors;
    int size;
    string color_vals;
public:
    HexColors(){
        LoadColors("color_names.json");
        srand (time(NULL));
        color_vals = "123456789ABCDEF";
    }

    void LoadColors(string filename) {
        JsonFacade J(filename);
        json obj;

        size = J.getSize();

        Colors = new Color *[size];
        // loads an array of cities with the json data
        for (int i = 0; i < size; i++) {
            obj = J.getNext();
            Colors[i] = new Color(obj);
        }
    }

    string GetRandomColor(){
        int r = rand() % size;
        return Colors[r]->hex;
    }

    string GetRandomDarkColor(){
        string color = "#";
        for(int i=0;i<6;i++){

            color += color_vals[rand()%7];
            
        }
        return color;
    }
};
