/**
 * DBSCAN:
 * 
 * Find the points in the ε (eps) neighborhood of every point, and identify the core 
 * points with more than minPts neighbors.
 * 
 * Find the connected components of core points on the neighbor graph, ignoring all 
 * non-core points.
 * 
 * Assign each non-core point to a nearby cluster if the cluster is an ε (eps) neighbor, 
 * otherwise assign it to noise.
 * 
 */

#include "City.hpp"
#include "Heap.hpp"
#include "JsonFacade.hpp"
#include "json.hpp"
#include "GeoJson.hpp"
#include "HexColors.hpp"
#include <iostream>
#include <string>
#include <vector>

struct Cluster {
    vector<City *> points;
    int size;
    double eps;
    bool merged;

    //center ??
    Cluster(double e) {
        size = 0;
        eps = e;
        merged = false;
    }

    void AddPoint(City *c) {
        size++;
        points.push_back(c);
    }

    City* RemovePoint(){

        City* temp = points.back();
        points.pop_back();
        size--;
        return temp;
    }

    int Size() {
        return points.size();
    }

    void Merge(Cluster* c){
        for(int i=0;i<c->points.size();i++){
            AddPoint(c->points[i]);
        }
    }

    bool InNeighborhood(City *p) {
        double d;
        for (int i = 0; i < points.size(); i++) {
            d = p->Distance(points[i]->lat, points[i]->lon);
            // your not me
            if (p->lat == points[i]->lat && p->lon == points[i]->lon) {
                continue;
            }

            // close to me, then your in.
            if (d <= eps && !p->visited) {
                AddPoint(p);
                return true;
            }
        }
        return false;
    }
};

class Dbscan {
private:
    vector<City *> Cities;
    int minPoints;
    double eps;
    vector<Cluster *> Clusters;
    vector<Cluster *> Combined;
    Heap<City> *H;
    string objectId; // its a number but a string for json reasons


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
    void LoadCities(string filename, string state = "") {
        json obj;
        JsonFacade J(filename);

        // loads an array of cities from specified state
        for (int i = 0, id = 0; i < J.getSize(); i++) {
            obj = J.getNext();

            if (obj["state"] == state || state == "") {
                Cities.push_back(new City(obj, id));
                id++;
            }
        }
    }

    void LoadHeap(int city_id) {
        H->Clear();
        double lat = Cities[city_id]->lat;
        double lon = Cities[city_id]->lon;
        for (int j = 0; j < Cities.size(); j++) {
            Cities[j]->priority = Cities[j]->Distance(lat, lon);
            H->Insert(Cities[j]);
        }
    }

public:
    Dbscan(string filename, int mp, double d) {
        LoadCities(filename);
        objectId = "0";
        minPoints = mp;
        eps = d;
        H = new Heap<City>(false);
        findClusters();
    }

    int inCluster(City *c) {
        for (int i = 0; i < Clusters.size(); i++) {
            if (Clusters[i]->InNeighborhood(c)) {
                return i;
            }
        }
        return -1;
    }

    bool checkCombine(Cluster* s,Cluster* t){
        double lat;
        double lon;
        double distance;
        for (int i = 0; i < s->points.size(); i++) {
            lat = s->points[i]->lat;
            lon = s->points[i]->lon;
            for (int j = 0; j < t->points.size(); j++) {
                distance = t->points[j]->Distance(lat, lon);
                if(distance <= eps){
                    return true;
                }
            }
        }
        return false;
    }


    void findClusters() {
        int processedCities = 0;
        int cityId = rand() % Cities.size();
        double lat, lon, distance;
        int clusterSize = 0;
        int index;
        bool added;
        Cluster *c;

        

        // new empty cluster
        c = new Cluster(eps);
        c->AddPoint(Cities[0]);
        Cities[0]->visited = true;
        Clusters.push_back(c);

        for (int j = 0; j < Cities.size(); j++) {
            for (int c = 0; c < Clusters.size(); c++) {
                added = Clusters[c]->InNeighborhood(Cities[j]);
                if (added) {
                    Cities[j]->visited = true;
                    break;
                }
            }
            if (!added) {
                c = new Cluster(eps);
                c->AddPoint(Cities[j]);
                Clusters.push_back(c);
                cout << Clusters.size() << endl;
            }
        }

        while(Clusters.size()) {
            c = Clusters.back();
            Clusters.pop_back();
            if(c->merged){
                continue;
            }
            Combined.push_back(c);
            for (int i = 0; i < Clusters.size(); i++) {
                if(!Clusters[i]->merged && checkCombine(c,Clusters[i])){
                    c->Merge(Clusters[i]);
                    Clusters[i]->merged = true;
                }
            }
        }

        while(Combined.size()){
            Clusters.push_back(Combined.back());
            Combined.pop_back();
        }

        while(Clusters.size()) {
            c = Clusters.back();
            Clusters.pop_back();
            if(c->merged){
                continue;
            }
            Combined.push_back(c);
            for (int i = 0; i < Clusters.size(); i++) {
                if(!Clusters[i]->merged && checkCombine(c,Clusters[i])){
                    c->Merge(Clusters[i]);
                    Clusters[i]->merged = true;
                }
            }
        }
        
        cout<<endl;
        cout<<Clusters.size()<<endl;
        cout<<Combined.size()<<endl;

        // for (int c = 0; c < Clusters.size(); c++) {
        //     cout << Clusters[c]->points.size() << endl;
        // }
    }

    void MakeGeoJson(){
        GeoJson GJ;
        json obj = json::array();
        City* c;
        double lat,lon;
        int id;
        string color;
        HexColors Colors;

        for (int i = 0; i < Combined.size(); i++) {
            if(Combined[i]->points.size() >= minPoints){
                obj = json::array();
                c = Combined[i]->points[0];
                color  = Colors.GetRandomColor();
                for(int j=0;j<Combined[i]->points.size();j++){
                    c = Combined[i]->points[j];
                    lat = c->lat;
                    lon = c->lon;
                    obj.push_back({lon,lat});
                    id = GJ.AddGeoPoint(lon,lat);
                    GJ.AddProperty(id,"marker-size","small");
                    GJ.AddProperty(id,"marker-color",color);
                    GJ.AddProperty(id,"marker-label",to_string(i));
                    GJ.AddProperty(id,"description",to_string(lat)+","+to_string(lon));
                }
                c = Combined[i]->points[0];
                lat = c->lat;
                lon = c->lon;
                obj.push_back({lon,lat});
                //GJ.AddPolygon(obj);
                
            }
        }
        GJ.PrintJson("clusters.geojson");

    }
};