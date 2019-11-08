#include "Dbscan.hpp"

using namespace std;

int main(int argc, char** argv){
    Dbscan DB("cities_all.json",5,30.0);
    DB.MakeGeoJson();
    return 0;
}