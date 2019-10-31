#include "json.hpp"
#include <cmath>
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

using json = nlohmann::json;

static double Haversine(double lat1, double lon1, double lat2, double lon2) {
    // distance between latitudes
    // and longitudes
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    // convert to radians
    lat1 = (lat1)*M_PI / 180.0;
    lat2 = (lat2)*M_PI / 180.0;

    // apply formulae
    double a =
        pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
}

struct Edge;

struct City {
    string name;
    double growth;
    double lat;
    double lon;
    int population;
    int rank;
    string state;
    int id;
    double priority;
    bool visited;

    City() {
        id = 0;
        name = "";
        growth = 0.0;
        lat = 0.0;
        lon = 0.0;
        population = 0;
        rank = 0;
        state = "";
        priority = 0.0;
        visited = false;
    }

    City(json obj, int _id) {
        name = obj["city"];
        growth = obj["growth"];
        lat = obj["latitude"];
        lon = obj["longitude"];
        population = obj["population"];
        rank = obj["rank"];
        state = obj["state"];
        id = _id;
        priority = 0.0;
        visited = false;
    }

    double Distance(double toLat, double toLon) {
        return Haversine(lat, lon, toLat, toLon);
    }

    friend ostream &operator<<(ostream &os, const City &c) {
        os << c.name << '/' << c.lat << '/' << c.lon;
        return os;
    }
};

struct Node {
    // from
    City *C;
    vector<Edge *> Edges;
    bool visited;
    int lastVisitor;
    int id;

    Node() {
        C = new City;
        visited = false;
        lastVisitor = -1;
        id = -1;
    }
    Node(City *c) {
        C = c;
        id = c->id;
        visited = false;
        lastVisitor = -1;
    }

    Node(json j, int _id) {
        C = new City(j, _id);
        id = _id;
        visited = false;
        lastVisitor = -1;
    }

    int NumEdges() {
        return Edges.size();
    }
};

struct Edge {
    int from;
    int to;
    double distance;
    double priority;

    Edge(int f, int t, double d) {
        distance = d;
        to = t;
        from = f;
        priority = d;
    }

    friend ostream &operator<<(ostream &os, const Edge &e) {
        os << "[From:" << e.from << " To:" << e.to << " Distance: " << e.distance<<"]";
        return os;
    }
};

class Graph {
private:
    vector<Node *> Nodes;
    vector<Edge *> Edges;   // Just to keep track of existing edges

public:
    Graph() {
    }

    void ResetGraph() {
        for (int i=0; i < Nodes.size(); i++) {
            Nodes[i]->lastVisitor = -1;
            Nodes[i]->visited = false;
        }
    }

    void AddVertex(City *C) {
        Node *N = new Node(C);
        Nodes.push_back(N);
    }

    bool EdgeExists(int from, int to){
        for(int i=0;i<Edges.size();i++){
            if(Edges[i]->from == from && Edges[i]->to == to){
                return true;
            }
        }
        return false;
    }

    bool AddEdge(int from, int to, double d = 0.0) {
        if(!EdgeExists(from,to)){
            Edge *E = new Edge(from, to, d);    // make the edge
            Edges.push_back(E);                 // add it to big list of edges
            Nodes[from]->Edges.push_back(E);    // add it to particular node
            return true;
        }
        return false;
    }

    int NumVertices() {
        return Nodes.size();
    }

    int NumEdges() {
        int edgeCount = 0;

        for (auto it = Nodes.begin(); it != Nodes.end(); ++it) {
            edgeCount += (*it)->Edges.size();
        }

        return edgeCount;
    }

    Node *FindVertexByName(string _name) {
        for (auto it = Nodes.begin(); it != Nodes.end(); ++it) {
            if ((*it)->C->name == _name) {
                return (*it);
            }
        }
        return NULL;
    }

    int FindUnvisited() {
        for (int i = 0; i < Nodes.size(); i++) {
            if (Nodes[i]->visited == false) {
                return i;
            }
        }
        return -1;
    }

    Node *GetVertex(int i) {
        return Nodes[i];
    }

    void Traverse(int start_id = 0) {
        vector<int> path;
        int current;

        path.push_back(start_id);

    }

    queue<City*> DepthFirst(int start_id = 0) {
        int Current;
        int Visited = 0;
        vector<int> S;
        queue<City*> path;
        int to;

        S.push_back(start_id);

        while (S.size() > 0) {
            Current = S.back();
            S.pop_back();

            if (!Nodes[Current]->visited) {
                Nodes[Current]->visited = 1;
                cout<<Nodes[Current]->C->name<<"->";
                path.push(Nodes[Current]->C);
                Visited++;
            }

           
            for (int i=0; i < Nodes[Current]->Edges.size(); i++) {
                to = Nodes[Current]->Edges[i]->to;
                if (!Nodes[to]->visited) {
                    S.push_back(to);
                }
            }

            if (S.size() == 0) {
                Current = FindUnvisited();
                if (Current >= 0) {
                    cout << endl << "disconnected" << endl;
                    S.push_back(Current);
                }
            }
        }
        cout <<endl<< "Visited: " << Visited << endl;
        return path;
    }

 
    queue<City*> BreadthFirst(int start_id = 0) {
        int Current;
        int Visited = 0;
        queue<int> Q;
        queue<City*> path;
        int to;

        Q.push(start_id);

        while (Q.size() > 0) {
            Current = Q.front();
            Q.pop();

            if (!Nodes[Current]->visited) {
                Nodes[Current]->visited = 1;
                cout <<Nodes[Current]->C->name << "->";
                path.push(Nodes[Current]->C);
                Visited++;
            }

            

            for (int i=0; i < Nodes[Current]->Edges.size(); i++) {
                to = Nodes[Current]->Edges[i]->to;
                if (!Nodes[to]->visited) {
                    Nodes[to]->lastVisitor = Nodes[Current]->id;
                    Q.push(to);
                }
            }
            
            if (Q.size() == 0) {
                Current = FindUnvisited();
                if (Current >= 0) {
                    cout << endl << "disconnected" << endl;
                    Q.push(Current);
                }
            }
        }
        cout <<endl<< "Visited: " << Visited << endl;
        return path;
    }

    void PrintNodes() {
        for (auto it = Nodes.begin(); it != Nodes.end(); ++it) {
            cout << (*it)->C->name << " " << (*it)->C->visited << endl;
        }
    }

    void PrintGraph() {
        for (auto it = Nodes.begin(); it != Nodes.end(); ++it) {
            cout << (*it)->C->name << endl;
            for (auto et = (*it)->Edges.begin(); et != (*it)->Edges.end(); ++et) {
                cout << "\t" << Nodes[(*et)->to]->C->name << " : " << (*et)->distance << endl;
            }
        }
    }


    void buildGeoJson(queue<City*> path){
        json j;
        City* from;
        City* to; 

        json featureCollection;

        featureCollection["type"]="FeatureCollection";
        featureCollection["features"] = json::array();
        

        json feature;

        feature["type"] = "Feature";
        feature["properties"] = {};
        feature["geometry"] = {};
        feature["geometry"]["type"] = "LineString";
        feature["geometry"]["coordinates"] = json::array();

        from = path.front();
        path.pop();
        while(!path.empty()){
            to = path.front();
            path.pop();

            json coord1;
            json coord2;
            json line;

            coord1.push_back(from->lon);
            coord1.push_back(from->lat);
            coord2.push_back(to->lon);
            coord2.push_back(to->lat);

            line.push_back(coord1);
            line.push_back(coord2);

            feature["geometry"]["coordinates"].push_back(coord1);
            feature["geometry"]["coordinates"].push_back(coord2);

            from = to;
        }

        featureCollection["features"].push_back(feature);

        ofstream fout("pretty.json");
        fout << std::setw(4) << featureCollection << std::endl;
        cout << std::setw(4) << featureCollection << std::endl;
    }


    
    // void PrintJson() {
    //     Node* startNode = FindVertexByName("Miami");
    //     int start_id = startNode->C->id;
    //     Node* Current;
    //     vector<Node*> S;
    //     vector<double> lats;
    //     vector<double> lons;

    //     S.push_back(Nodes[start_id]);
    //     lats.push_back(Nodes[start_id]->C->lat);
    //     lons.push_back(Nodes[start_id]->C->lon);

    //     while(S.size() > 0){
    //         Current=S.back();
    //         S.pop_back();

    //         if(!Current->visited){
    //             Current->visited = 1;
    //         }

    //         lats.push_back(Current->C->lat);
    //         lons.push_back(Current->C->lon);

    //         for (auto et = Current->Edges.begin(); et != Current->Edges.end(); ++et) {
    //             if(!Nodes[(*et)->to]->visited){
    //                 S.push_back(Nodes[(*et)->to]);
    //             }
    //         }
    //     }
    //     printJson(lats,lons);
    // }

    // void printJson(vector<double>lats,vector<double>lons){
    //     cout<<"{\"lats\":[";
    //     for (auto it = lats.begin(); it != lats.end(); ++it) {
    //         cout<<*it<<",\n";
    //     }
    //     cout<<"],";
    //     cout<<"{\"lons\":[";
    //     for (auto it = lons.begin(); it != lons.end(); ++it) {
    //         cout<<*it<<",\n";
    //     }
    //     cout<<"]\n}";

    // }
};

class GeoJson{
private:
    json Collection;
    int FeatureId;

    json AddFeature(string feature_type){

        json Feature;

        Feature["type"] = "Feature";
        Feature["properties"] = {};
        Feature["geometry"] = {};
        Feature["geometry"]["type"] = feature_type;
        Feature["geometry"]["coordinates"] = json::array();

        return Feature;
    }

public:

    GeoJson(){
        Collection = {};
        Collection["type"]="FeatureCollection";
        Collection["features"]= json::array();
        Collection["properties"] = {};
        FeatureId = 0;
    }

    int AddLineString(json line){
        return 0;
    }

    int AddLineString(std::vector<std::pair<double, double>> vline){
        json feature = AddFeature("LineString");
  
        for (auto ptr = vline.begin(); ptr != vline.end(); ++ptr){
            feature["geometry"]["coordinates"].push_back({ptr->first,ptr->second});
        }

        Collection["FeatureCollection"]["features"].push_back(feature);

        return 0;
    }            

    void AddGeoPoint(double lat,double lon,json properties={}){
        json feature = AddFeature("Point");

        feature["properties"] = properties;

        feature["geometry"]["coordinates"].push_back(lon);
        feature["geometry"]["coordinates"].push_back(lat);

        Collection["features"].push_back(feature);
    }

    void AddPolygon(){
        
    }

    void AddProperties(int id,string key,string val){
        Collection["features"][id]["properties"][key]=val;
    }

    void PrintJson(string filename){
        ofstream fout(filename);
        fout << std::setw(4) << Collection << std::endl;
        cout << std::setw(4) << Collection << std::endl;
    }


};
