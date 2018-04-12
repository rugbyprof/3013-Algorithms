#pragma once

#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include "edge_heap.h"
#include "distance.h"
#include "csv.h"

using namespace std;

// Might use as a lookup from city name to ID.
// And to filter duplicate cities.
typedef map<string, int> strMapInt;

typedef map<int,int> intint;

struct latlon
{
    double lat;
    double lon;
    latlon()
    {
        lat = 0.0;
        lon = 0.0;
    }

    latlon(double y, double x)
    {
        lat = y;
        lon = x;
    }

    /**
     * operator= - overload assignment for latlon
     * Params:
     *     const latlon ll     - lat lon to assign
     * Returns 
     *     reference to assignment for chaining (e.g. a = b = c )
     */
    latlon &operator=(const latlon &ll)
    {
        // do the copy
        lat = ll.lat;
        lon = ll.lon;

        // return the existing object so we can chain this operator
        return *this;
    }

    /**
     * operator<< - overload cout for latlon
     * Params:
     *     const latlon ll     - lat lon to print
     * Returns 
     *     formatted output for a latlon
     */
    friend ostream &operator<<(ostream &output, const latlon &ll)
    {
        output << "(" << ll.lat << "," << ll.lon << ")";
        return output;
    }
};



/**
 * vertex - represents a vertex in a graph.
 */
struct vertex
{
    int ID;
    string city;
    string state;
    latlon loc;
    vector<edge> E;
    bool visited;

    /**
     * vertex<< - overload cout for vertex
     * Params:
     *     const vertex v     - vertex to print
     * Returns 
     *     formatted output for a vertex
     */
    vertex(int id, string c, string s, latlon ll = latlon())
    {
        ID = id;
        city = c;
        state = s;
        loc = ll;
        visited = false;
    }

    /**
     * operator<< - overload cout for vertex
     * Params:
     *     const vertex v     - vertex to print
     * Returns 
     *     formatted output for a vertex
     */
    friend ostream &operator<<(ostream &output, const vertex &v)
    {
        output << "(ID:" << v.ID << " C: " << v.city << " S: " << v.state << " L: " << v.loc << " Edges:"<<v.E.size()<< ")";
        return output;
    }
};

/**
 * graph - set of vertices and edges
 * 
 * Methods (private):
 *     vertex* createVertex(string city,string state)
 * Methods (public):
 *     graph()
 */
class graph
{
  public:
    int id;                      // id counter for new vertices
    int num_edges;               // edge count
    vector<vertex *> vertexList; // vector to hold vertices
    strMapInt cityLookup;

    /**
     * private: createVertex - returns a new vertex with unique id.
     * Params:
     *     string city
     *     string state
     */
    vertex *createVertex(string city, string state, latlon ll)
    {
        return new vertex(id++, city, state, ll);
    }

    /**
     * graph - constructor
     */
    graph()
    {
        id = 0;
        num_edges = 0;
    }

    graph(const graph &G)
    {
        id = G.id;
        num_edges = G.num_edges;
        vertexList = G.vertexList;
        cityLookup = G.cityLookup;
    }

    /**
     * addVertex - adds a vertex to the graph
     * Params:
     *     string   city     - name of city
     *     string   state    - two letter abbr of state
     *     double   lat      - latitude 
     *     double   lon      - longitude 
     * Returns 
     *     void
     */
    int addVertex(string city, string state, double lat = 0.0, double lon = 0.0)
    {
        if (cityLookup.find(city) == cityLookup.end())
        {   
            // Add the city as a key to the map.
            cityLookup[city] = 0;
        }
        else
        {
            return -1;
        }

        vertex *temp = createVertex(city, state, latlon(lat, lon));
        vertexList.push_back(temp);

        //update the value that city points to.
        cityLookup[city] = temp->ID;
        return temp->ID;
    }

    /**
     * addEdge - adds a relationship between two vertices to the graph
     * Params:
     *     int      fromID   - the ID of the vertex in which the edge is leaving
     *     int      toID     - ID of the receiving vertex
     *     double   weight   - weight of the edge if any 
     *     bool     directed - is the edge directed or not
     * Returns 
     *     void
     */
    void addEdge(int fromID, int toID, double weight = 0, bool directed = false)
    {
        edge e1(toID, weight);
        vertexList[fromID]->E.push_back(e1);
        num_edges++;

        //cout<<"adding "<<fromID<<" to "<<toID<<endl;

        if (!directed)
        {
            edge e2(fromID, weight);
            vertexList[toID]->E.push_back(e2);

            //cout<<"adding "<<toID<<" to "<<fromID<<endl;
            
            num_edges++;
        }
    }

    /**
     * addEdge - adds a relationship between two vertices to the graph
     * Params:
     *     string   fromCity   - the city of the vertex in which the edge is leaving
     *     string   toCity     - city of the receiving vertex
     *     double   weight     - weight of the edge if any 
     *     bool     directed   - is the edge directed or not
     * Returns:
     *     void
     */
    void addEdge(string fromCity, string toCity, double weight = 0, bool directed = false)
    {
    }

    /**
     * printGraph - prints the graph out for debugging purposes
     * Params:
     *     void
     */
    void printGraph()
    {

        vector<vertex *>::iterator vit;
        vector<edge>::iterator eit;

        for (vit = vertexList.begin(); vit != vertexList.end(); vit++)
        {
            cout << *(*vit) << endl;

            if ((*vit)->E.size() > 0)
            {
                for (eit = (*vit)->E.begin(); eit != (*vit)->E.end(); eit++)
                {
                    cout << "\t" << (*eit) << endl;
                }
            }
        }
    }

    string mylower(string s){
        for(int i=0;i<s.length();i++){
            if(s[i]>='A' && s[i]<='Z'){
                s[i]+= 32;
            }
        }
        return s;
    }

    string searchGraph(string c)
    {

        vector<vertex *>::iterator i;
        vector<edge>::iterator eit;

        for (i = vertexList.begin(); i != vertexList.end(); i++)
        {
            if(mylower((*i)->city) == mylower(c)){
                cout << *(*i) << endl;
                return (*i)->city;
            }
        }
        return "";
    }

    // find the three closest vertices and create edges between them.
    void createSpanningTree(string filter="")
    {

        vector<vertex *>::iterator i;
        vector<vertex *>::iterator j;
        vector<edge>::iterator eit;
        edgeHeap E; 

        double distance = 0;
        double minDistance = pow(2.0,30.0);
        int closestID;

        // loop through vertices
        for (i = vertexList.begin(); i != vertexList.end(); i++)
        {
            //if((*i)->state == filter){
                for (j = vertexList.begin(); j != vertexList.end(); j++)
                {
                    distance = distanceEarth((*i)->loc.lat, (*i)->loc.lon, (*j)->loc.lat, (*j)->loc.lon);
                    // if(distance > 0 && distance < minDistance){
                    //     closestID = (*j)->ID;
                    //     minDistance = distance;
                    // }
                    edge *e = new edge((*i)->ID,(*j)->ID,distance);
                    E.Insert(e);
                }
                //E.PrintHeap();
                cout<<*E.Extract()<<endl;
                cout<<*E.Extract()<<endl;
                cout<<*E.Extract()<<endl;
                exit(0);
           // }
        }
        
    }

    void printVids(){
        vector<vertex *>::iterator vit;
        vector<edge>::iterator eit;

        for (vit = vertexList.begin(); vit != vertexList.end(); vit++)
        {
            cout << (*vit)->ID << endl;
        }
    }

    string graphViz(bool directed = true){
        vector<vertex *>::iterator vit;
        vector<edge>::iterator eit;

        // [label="hi", weight=100];

        string viz = "";
        string labels = "";
        string conns = "";
        int weight = 0;
        string arrow = "";

        if(directed){
            viz = "digraph G {\n";
            arrow = "->";

        }else{
            viz = "graph G {\n";
            arrow = "--";
        }

        for (vit = vertexList.begin(); vit != vertexList.end(); vit++)
        {
            if ((*vit)->E.size() > 0)
            {
                labels += "\t" + to_string((*vit)->ID) + " [label=\"" + (*vit)->city + ", " + (*vit)->state +  "\"]\n";

                for (eit = (*vit)->E.begin(); eit != (*vit)->E.end(); eit++)
                {


                    labels += "\t" + to_string(eit->toID) + " [label=\"" +  vertexList[eit->toID]->city + ", " + vertexList[eit->toID]->state +  "\"]\n";

                    weight = eit->weight;
                    conns += "\t" + to_string((*vit)->ID) + arrow 
                        + to_string(eit->toID) + " [weight="+ to_string(weight) + ", label="+ to_string(weight) +"]\n";
                }
            }
        }

        viz += labels;
        viz += conns;
        viz += "}\n";

        return viz;
    }

    /**
     * maxID - returns the max id assigned to any vertex
     * Params:
     *     void
     * Returns:
     *     int
     */
    int maxID()
    {
        return id;
    }

    /**
     * graphSize - returns the number of vertices and edges
     * Params:
     *     void
     * Returns:
     *     int
     */
    int* graphSize(){
        int* vals = new int[2];
        vals[0] = vertexList.size();
        vals[1] = num_edges;
        return vals;
    }

    /**
     * operator= - overload assignment for Graph
     * NOT DONE
     * Params:
     *     const latlon ll     - lat lon to assign
     * Returns 
     *     reference to assignment for chaining (e.g. a = b = c )
     */
    graph &operator=(const graph &g)
    {
        // do the copy
        vertexList = g.vertexList;
        id = g.id;

        // return the existing object so we can chain this operator
        return *this;
    }
};