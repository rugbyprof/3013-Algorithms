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

/**
 * Node
 * 
 * Graph node the holds City's in this case. 
 * Should be templated, but its not.
 * 
 */
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

/**
 * Edge
 * 
 * Has a "from" id and a "to" id where "id" is the id of a city.
 * It also holds the "distance" between the two cities.
 * The "priority" is distance in our examples for this program
 */
struct Edge {
    int from;           // city id
    int to;             // city id
    double distance;    // distance between from and to
    double priority;    // priority (for use in our heap)

    /**
     * Edge - constructor
     * 
     * int    f : from
     * int    t : to
     * double d : distance
     */
    Edge(int f, int t, double d) {
        distance = d;
        to = t;
        from = f;
        priority = d;
    }

    /**
     * Overloaded ostream to print an edge. Alter as
     * you see fit... 
     */
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
    /**
     * Constructor -  
     */
    Graph() {
    }

    /**
     * ResetGraph
     * 
     * This loops through the vector of nodes and 
     * sets every node to NOT visited and erases last visitor.
     * 
     */
    void ResetGraph() {
        for (int i=0; i < Nodes.size(); i++) {
            Nodes[i]->lastVisitor = -1;
            Nodes[i]->visited = false;
        }
    }

    /**
     * AddVertex
     * 
     * Params:
     * 
     *      City *C  : city struct to add to a new node
     * 
     * Return:
     * 
     *      void
     */
    void AddVertex(City *C) {
        Node *N = new Node(C);
        Nodes.push_back(N);
    }

    /**
     * EdgeExists
     * 
     *      Lets us check before adding an edge between the same two nodes.
     *      You may want to add multiple edges between same nodes, but not
     *      for what we are doing.
     *      
     * 
     * Params:
     * 
     *      int from : from node id
     *      int to   : to node id
     * 
     * Return:
     * 
     *      bool : true - edge exists
     */
    bool EdgeExists(int from, int to){
        for(int i=0;i<Edges.size();i++){
            if(Edges[i]->from == from && Edges[i]->to == to){
                return true;
            }
        }
        return false;
    }

    /**
     * AddEdge
     * 
     *      Add a new edge to graph
     *      
     * 
     * Params:
     * 
     *      int    from : from node id
     *      int    to   : to node id
     *      double d    : distance 
     * 
     * Return:
     * 
     *      bool : true - edge added
     */
    bool AddEdge(int from, int to, double d = 0.0) {
        if(!EdgeExists(from,to)){
            Edge *E = new Edge(from, to, d);    // make the edge
            Edges.push_back(E);                 // add it to big list of edges
            Nodes[from]->Edges.push_back(E);    // add it to particular node
            return true;
        }
        return false;
    }

    /**
     * NumVertices
     * 
     *      How many vertices in graph. Not really necessary.
     *      
     * 
     * Params:
     *     void
     * 
     * Return:
     * 
     *      int : num of verts
     */
    int NumVertices() {
        return Nodes.size();
    }

    /**
     * NumEdges
     * 
     *      How many edges in graph. Not really necessary, but could
     *      give is info on how connected or dense the graph is.
     *      
     * 
     * Params:
     *     void
     * 
     * Return:
     * 
     *      int : num of edges
     */
    int NumEdges() {
        int edgeCount = 0;

        for (auto it = Nodes.begin(); it != Nodes.end(); ++it) {
            edgeCount += (*it)->Edges.size();
        }

        return edgeCount;
    }

    /**
     * FindVertexByName
     * 
     *      Use this to find a starting node in the graph. If you wanted to start
     *      in a particular city, this is how you would do it. 
     *      
     * 
     * Params:
     *     string _name : name of city
     * 
     * Return:
     * 
     *      Node* 
     */
    Node *FindVertexByName(string _name) {
        for (auto it = Nodes.begin(); it != Nodes.end(); ++it) {
            if ((*it)->C->name == _name) {
                return (*it);
            }
        }
        return NULL;
    }

    /**
     * FindUnvisited
     * 
     *      In an unconnected graph, when traversing you need to be able to jump to
     *      another vertex to continue the traversal even if there are no edges to 
     *      follow. This method finds an unvisited node so we can keep going.
     *      
     * 
     * Params:
     *     void
     * 
     * Return:
     * 
     *      int : node id or -1 if everyone visited
     */
    int FindUnvisited() {
        for (int i = 0; i < Nodes.size(); i++) {
            if (Nodes[i]->visited == false) {
                return i;
            }
        }
        return -1;
    }

    /**
     * GetVertex
     * 
     *      Not used for anything.
     *      
     * 
     * Params:
     *     int : node id
     * 
     * Return:
     * 
     *      Node*
     */
    Node *GetVertex(int i) {
        return Nodes[i];
    }


    /**
     * PrintNodes
     * 
     *      Print method for debugging purposes
     *      
     * 
     * Params:
     *     void
     * 
     * Return:
     * 
     *     void
     */

    void PrintNodes() {
        for (auto it = Nodes.begin(); it != Nodes.end(); ++it) {
            cout << (*it)->C->name << " " << (*it)->C->visited << endl;
        }
    }

    /**
     * PrintGraph
     * 
     *      Print method for debugging purposes
     *      
     * 
     * Params:
     *     void
     * 
     * Return:
     * 
     *     void
     */
    void PrintGraph() {
        for (auto it = Nodes.begin(); it != Nodes.end(); ++it) {
            cout << (*it)->C->name << endl;
            for (auto et = (*it)->Edges.begin(); et != (*it)->Edges.end(); ++et) {
                cout << "\t" << Nodes[(*et)->to]->C->name << " : " << (*et)->distance << endl;
            }
        }
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
                //cout <<Nodes[Current]->C->name << "->";
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
                    //cout << endl << "disconnected" << endl;
                    path.push(new City());
                    Q.push(Current);
                }
            }
        }
        //cout <<endl<< "Visited: " << Visited << endl;
        return path;
    }

};


