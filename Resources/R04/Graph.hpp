#pragma once
#include <cmath>
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <iomanip>
#include "json.hpp"
#include "City.hpp"

using namespace std;

using json = nlohmann::json;


struct Edge;

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
                    path.push(new City());
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

};


