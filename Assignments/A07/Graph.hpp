#include "json.hpp"
#include <cmath>
#include <iostream>
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

    Node() {
        C = new City;
        visited = false;
    }
    Node(City *c) {
        C = c;
        visited = false;
    }

    Node(json j, int id) {
        C = new City(j, id);
        visited = false;
    }

    int NumEdges(){
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
        os << "From:"<< e.from << " To:" << e.to << " Distance: " << e.distance;
        return os;
    }
};

class Graph {
private:
    vector<Node *> Nodes;

public:
    Graph() {
    }

    void ResetGraph(){
        for (auto it = Nodes.begin(); it != Nodes.end(); ++it) {
            (*it)->C->visited = false;
        }
    }

    void AddVertex(City *C) {
        Node *N = new Node(C);
        Nodes.push_back(N);
    }

    void AddEdge(int from, int to, double d = 0.0) {
        Edge *E = new Edge(from,to, d);
        Nodes[from]->Edges.push_back(E);
    }

    int NumVertices(){
        return Nodes.size();
    }

    int NumEdges(){
        int edgeCount = 0;

        for (auto it = Nodes.begin(); it != Nodes.end(); ++it) {
            edgeCount += (*it)->Edges.size();
        }

        return edgeCount;
    }

    Node* FindVertexByName(string _name){
        for (auto it = Nodes.begin(); it != Nodes.end(); ++it) {
            if((*it)->C->name == _name){
                return (*it);
            }
        }
        return NULL;
    }

    Node* GetVertex(int i){
        return Nodes[i];
    }

    void Traverse(int start_id=-1,string type="Depth"){
        if(start_id < 0){
            start_id = 0;
        }
        if(type=="Depth"){
            DepthFirst(start_id);
        }else{
            BreadthFirst(start_id);
        }
    }

    void DepthFirst(int start_id){
        Node* Current;
        int Visited = 0;
        vector<Node*> S;

        S.push_back(Nodes[start_id]);

        while(S.size() > 0){
            Current=S.back();
            S.pop_back();
            
            if(!Current->visited){
                Current->visited = 1;
                Visited++;
            }

            cout<<Current->C->name<<" -> ";
            
            for (auto et = Current->Edges.begin(); et != Current->Edges.end(); ++et) {
                if(!Nodes[(*et)->to]->visited){
                    S.push_back(Nodes[(*et)->to]);
                }
            }
        }
        cout<<"Visited: "<<Visited<<endl;
    }

    void BreadthFirst(int start_id){
        Node* Current;
        int Visited = 0;
        queue<Node*> Q;

        Q.push(Nodes[start_id]);

        while(Q.size() > 0){
            Current = Q.front();
            Q.pop();
            
            if(!Current->visited){
                Current->visited = 1;
                Visited++;
            }

            cout<<Current->C->name<<endl;
            
            for (auto et = Current->Edges.begin(); et != Current->Edges.end(); ++et) {
                if(!Nodes[(*et)->to]->visited){
                    Q.push(Nodes[(*et)->to]);
                }
            }
        }
        cout<<"Visited: "<<Visited<<endl;
    }

    void PrintNodes() {
        for (auto it = Nodes.begin(); it != Nodes.end(); ++it) {
            cout << (*it)->C->name << endl;
        }
    }

    void PrintGraph() {
        for (auto it = Nodes.begin(); it != Nodes.end(); ++it) {
            cout << (*it)->C->name << endl;
            for (auto et = (*it)->Edges.begin(); et != (*it)->Edges.end(); ++et) {
                cout <<"\t"<< Nodes[(*et)->to]->C->name <<" : " <<(*et)->distance<<endl;
            }
        }
    }

    void PrintJson() {
        Node* startNode = FindVertexByName("Miami");
        int start_id = startNode->C->id;
        Node* Current;
        vector<Node*> S;
        vector<double> lats;
        vector<double> lons;

        S.push_back(Nodes[start_id]);
        lats.push_back(Nodes[start_id]->C->lat);
        lons.push_back(Nodes[start_id]->C->lon);

        while(S.size() > 0){
            Current=S.back();
            S.pop_back();
            
            if(!Current->visited){
                Current->visited = 1;
            }

            lats.push_back(Current->C->lat);
            lons.push_back(Current->C->lon);
            
            for (auto et = Current->Edges.begin(); et != Current->Edges.end(); ++et) {
                if(!Nodes[(*et)->to]->visited){
                    S.push_back(Nodes[(*et)->to]);
                }
            }
        }
        printJson(lats,lons);
    }

    void printJson(vector<double>lats,vector<double>lons){
        cout<<"{\"lats\":[";
        for (auto it = lats.begin(); it != lats.end(); ++it) {
            cout<<*it<<",\n";
        }
        cout<<"],";
        cout<<"{\"lons\":[";
        for (auto it = lons.begin(); it != lons.end(); ++it) {
            cout<<*it<<",\n";
        }
        cout<<"]\n}";

    }
};