#pragma once
#include <string.h>
#include "json.hpp"
using json = nlohmann::json;


struct Edge{
    string name;
    double priority;
    Edge(string n, double p){
        priority = p;
        name = n;
    }
    Edge(json j){
        name = j['city'];
        priority = random() % 5000;
    }

};