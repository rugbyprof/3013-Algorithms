#include <iostream>
#include <string>
#include "Graph.hpp"
#include "Heap.hpp"
#include "JsonFacade.hpp"

using namespace std;
using json = nlohmann::json;


int main(int argc, char** argv){
    JsonFacade JF("cities.json");        // Instance of our json animal helper
    Heap<Edge*> H(1000,true);
    json j;
    Edge* E;

    for(int i=0;i<JF.getSize();i++){
        j = JF.getIth(i);
        E = new Edge(j);
        H.Insert(E);
    }

    return 0;
}