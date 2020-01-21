//https://stackoverflow.com/questions/55116344/how-to-setup-vs-code-for-c-14-c-17
//https://github.com/nlohmann/json

#include "json_helper.cpp"
#include <fstream>
#include <iostream>

#define _USE_MATH_DEFINES

#include <math.h>

using namespace std;

const static double EarthRadiusKm = 6372.8;

inline double DegreeToRadian(double angle) {
    return M_PI * angle / 180.0;
}

class Coordinate {
public:
    Coordinate(double latitude, double longitude) : myLatitude(latitude), myLongitude(longitude) {}

    double Latitude() const {
        return myLatitude;
    }

    double Longitude() const {
        return myLongitude;
    }

private:
    double myLatitude;
    double myLongitude;
};

double HaversineDistance(const Coordinate &p1, const Coordinate &p2) {
    double latRad1 = DegreeToRadian(p1.Latitude());
    double latRad2 = DegreeToRadian(p2.Latitude());
    double lonRad1 = DegreeToRadian(p1.Longitude());
    double lonRad2 = DegreeToRadian(p2.Longitude());

    double diffLa = latRad2 - latRad1;
    double doffLo = lonRad2 - lonRad1;

    double computation = asin(sqrt(sin(diffLa / 2) * sin(diffLa / 2) + cos(latRad1) * cos(latRad2) * sin(doffLo / 2) * sin(doffLo / 2)));
    return 2 * EarthRadiusKm * computation;
}

struct Animal {
    string animal_name;
    long date;
    double latitude;
    double longitude;
    float adjuster;
    bool validated;
    string version;
    float priority;

    Animal() {
        animal_name = "";
        date = 0;
        latitude = 0.0;
        longitude = 0.0;
        adjuster = 0.0;
        validated = 0;
        version = "";
        priority = 0.0;
    }

    Animal(string name, long _date, double lat, double lon, float adj, bool val, string ver) {
        animal_name = name;
        date = _date;
        latitude = lat;
        longitude = lon;
        adjuster = adj;
        validated = val;
        version = ver;
        priority = 0.0;
    }

    Animal(json j) {
        animal_name = j["animal_name"];
        date = j["date"];
        latitude = j["latitude"];
        longitude = j["longitude"];
        adjuster = j["adjuster"];
        validated = j["validated"];
        version = j["version"];
        priority = 0.0;
    }
};

class AnimalHelper {
private:
    Animal **Animals;
    JsonHelper *J;
    json obj;
    int size;

public:
    AnimalHelper(string filename) {
        J = new JsonHelper(filename);
        size = J->getSize();
        Animals = new Animal *[size];
        for (int i = 0; i < size; i++) {
            obj = J->getNext();
            Animals[i] = new Animal(obj);
        }
    }



    void PrintAnimals() {

        for (int i = 0; i < size; i++) {

            cout << Animals[i]->animal_name << " " 
            << Animals[i]->latitude << " " 
            << Animals[i]->longitude << " " 
            << Animals[i]->date << " " 
            << Animals[i]->adjuster << " " 
            << Animals[i]->validated << " " 
            << Animals[i]->version << " "
            << Animals[i]->priority << endl;

        }
    }
};


int main(int argc, char **argv) {

    AnimalHelper AH("animals.json");
    char ch;

    AH.PrintAnimals();

    return 0;
}