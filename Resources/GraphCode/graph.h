#pragma once

#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include "edge_heap.h"
#include "geo.h"
#include "csv.h"
#include <limits.h>

using namespace std;

// Used as a lookup from city name to ID.
// And to filter duplicate cities.
typedef map<string, int> strMapInt;

typedef map<int, int> intint;

/**
 * vertex - represents a vertex in a graph.
 */
struct vertex
{
    int ID;         // integer id
    string city;    // city name
    string state;   // state abbr (TX)
    latlon loc;     // latlon point type
    point p;        // xy point type
    vector<edge> E; // vector of outedges
    bool visited;   // flag used for traversals
    vector<int> network;

    /**
     * Constructor: vertex
     * Params:
     *     int    id: integer unique identifier
     *     string  c: city name
     *     string  s: state abbr
     *     latlon ll: city location
     * Returns 
     *     void
     */
    vertex(int id, string c, string s, latlon ll = latlon())
    {
        ID = id;
        city = c;
        state = s;
        loc = ll;
        p.setXY(lon2x(ll.lon), lat2y(ll.lat));
        visited = false;
    }

    /**
     * Method: update 
     *     Updates the vertex location
     * Params:
     *     latlon ll: city location
     * Returns 
     *     void
     */
    void update(latlon ll)
    {
        loc = ll; // set location
        p.setXY(lon2x(ll.lon), lat2y(ll.lat));
        // update xy based on new ll
    }

    /**
     * Method: Neighbors 
     *     Are you a neighbor with vertex of id passed in,
     * Params:
     *     int id: potential neighbor id
     * Returns 
     *     bool: true = neighbor false = nope
     */
    bool Neighbors(int id)
    {
        vector<edge>::iterator eit;
        if (E.size() == 0)
        {
            return false;
        }
        else
        {
            for (eit = E.begin(); eit != E.end(); eit++)
            {
                if ((*eit).toID == id)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool buildNetwork(int id)
    {
        if (find(network.begin(), network.end(), id) != network.end())
        {
        }
        if (E.size() == 0)
        {
            return false;
        }
        else
        {
            for (int e = 0; e < E.size(); e++)
            {
                if (E[e].toID == id)
                {
                    return true;
                }
            }
        }
        return false;
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
        output << "(ID:" << v.ID << ", " << v.city << ", " << v.state << ", LatLon: " << v.loc << " Point: " << v.p << ", Edges:" << v.E.size() << ")";
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
    strMapInt cityLookup;        // dictionary of unique cities
    llBox box;                   // bounding box of coords
    edgePriorityList *E;
    string *colors;

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
     * Constructor
     */
    graph()
    {
        id = 0;
        num_edges = 0;
        colors = new string[9];
        colors[0] = "Black";
        colors[1] = "Blue";
        colors[2] = "Green";
        colors[3] = "Red";
        colors[4] = "Purple";
        colors[5] = "Orange";
        colors[6] = "Yellow";
        colors[7] = "Brown";
        colors[8] = "Pink";
    }

    /**
     * Constructor
     * Params:
     *     graph G: another graph to init with
     */
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

        //create a bounding box of values to help with scaling for drawing.
        box.addLatLon(latlon(lat, lon));

        vertex *temp = createVertex(city, state, latlon(lat, lon));
        vertexList.push_back(temp);

        //update the value that city points to.
        cityLookup[city] = temp->ID;
        return temp->ID;
    }

    /**
     * Method: getVertex
     * Params:
     *     int id: id of wanted vertex
     * Returns:
     *     vertex* of wanted vertex (if found) NULL otherwise
     */
    vertex *getVertex(int id)
    {
        if (id >= 0 && id < vertexList.size())
        {
            return vertexList[id];
        }
        return NULL;
    }

    /**
     * Method: Connected
     * Params:
     *     void
     * Returns:
     *     False if ANY vertex as zero edges.
     */
    bool Connected()
    {
        vector<vertex *>::iterator i;

        for (i = vertexList.begin(); i != vertexList.end(); i++)
        {
            if ((*i)->E.size() == 0)
            {
                return false;
            }
        }
        return true;
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
    void addEdge(int fromID, int toID, double weight = 0, bool directed = false, string color = "Black")
    {
        edge e1(fromID, toID, weight, color);
        vertexList[fromID]->E.push_back(e1);
        num_edges++;

        //cout<<"adding "<<fromID<<" to "<<toID<<endl;

        if (!directed)
        {
            edge e2(toID, fromID, weight, color);
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
    void addEdge(string fromCity, string toCity, double weight = 0, bool directed = false, string color = "Black")
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

            double brng = bearing((*(*vit)).loc, box.center);

            (*(*vit)).update(geo_destination((*(*vit)).loc, 100, brng));
            cout << (*(*vit)) << endl;

            if ((*vit)->E.size() > 0)
            {
                for (eit = (*vit)->E.begin(); eit != (*vit)->E.end(); eit++)
                {
                    cout << "\t" << (*eit) << endl;
                }
            }
        }
    }
    /**
     * magickGraph - instance of drawGraph included from mymagick.h
     * Params:
     *    int             w: width of image
     *    int             h: height of image
     *    string imageName : name of saved image
     */
    /*
    //NEEDS Magick++
    void magickGraph(int w, int h, string imageName)
    {
        drawGraph dg(w, h, "white");
        vector<vertex *>::iterator vit;
        vector<edge>::iterator eit;

        // For calculating new coords to stretch

        int x1;
        int y1;
        int x2;
        int y2;

        // For counting how much more
        int vsize = vertexList.size();
        int i = 0;
        double op = -10.0;
        double np = 0.0;

        // center point of bounding box
        int cx = ((box.c_p.x - box.minx) / (box.maxx - box.minx)) * w;
        int cy = h - (((box.c_p.y - box.miny) / (box.maxy - box.miny)) * h);

        for (vit = vertexList.begin(); vit != vertexList.end(); vit++)
        {

            x1 = (((*(*vit)).p.x - box.minx) / (box.maxx - box.minx)) * w;
            y1 = h - ((((*(*vit)).p.y - box.miny) / (box.maxy - box.miny)) * h);

            cout << (*(*vit)).city << endl;

            dg.setFontSize(20);
            dg.setFillColor("White");
            dg.setStrokeColor("Black");
            dg.drawRectangleNode(x1, y1, 150, 60, (*(*vit)).city);

            if ((*vit)->E.size() > 0)
            {
                cout << (*vit)->E.size() << endl;
                for (eit = (*vit)->E.begin(); eit != (*vit)->E.end(); eit++)
                {
                    x2 = (((*vertexList[(*eit).toID]).p.x - box.minx) / (box.maxx - box.minx)) * w;
                    y2 = h - ((((*vertexList[(*eit).toID]).p.y - box.miny) / (box.maxy - box.miny)) * h);
                    if (x1 > 0 && y1 > 0 && x2 > 0 && y2 > 0)
                    {
                        cout << "stupid color: " << (*eit).color << endl;
                        if ((*eit).color == "")
                        {
                            (*eit).color = colors[rand() % 9];
                        }
                        dg.drawLine(x1, y1, x2, y2, (*eit).color);
                        cout << x1 << "," << y1 << "," << x2 << "," << y2 << endl;
                    }
                }
            }

            i = i + 1;
            np = (double(i) / double(vsize)) * 100;
            if ((abs(np) - abs(op)) >= 10)
            {
                op = np;
                cout << np << " complete" << endl;
            }
        }

        dg.writeImage(imageName);
    }
    */
    /**
     * expandGraph - calculates a center and moves points away from the center
     *               to "grow" the graph if necessary for visualization.
     * Params:
     *    int distance: distance in miles to expand the graph.
     */
    void expandGraph(int distance)
    {
        vector<vertex *>::iterator vit;

        latlon ll;
        latlon destination;
        latlon center = box.center;

        box.reset();
        for (vit = vertexList.begin(); vit != vertexList.end(); vit++)
        {
            ll = (*(*vit)).loc;

            // get a bearing from the center
            // function in geo.h
            double brng = bearing(center, ll);

            // Calculate destination from center of graph through "this" point
            // moving away a specified distance at a specified bearing.
            destination = geo_destination(ll, distance, brng);

            //update the vertex's location
            (*(*vit)).update(destination);

            //update the bounding box I keep track of
            //encompassing the points in the graph
            box.addLatLon(destination);
        }
    }

    string mylower(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                s[i] += 32;
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
            if (mylower((*i)->city) == mylower(c))
            {
                cout << *(*i) << endl;
                return (*i)->city;
            }
        }
        return "";
    }

    void createSpanningTree(string filter = "")
    {
        vector<vertex *>::iterator i;
        vector<vertex *>::iterator j;
        vector<edge>::iterator eit;
        edgeHeap E;
        edge *e;
        vertex *ftemp;
        vertex *ttemp;
        vertex *current;

        double distance = 0;
        double d = 0;
        double minDistance = MAXFLOAT;
        int closestID;
        int count = 0;
        int ecount = 0;
        string minCity;
        int c;

        c = 0;

        while (!Connected())
        {
            cout << "Connecting: " << vertexList[c]->city << endl;
            // Inner loop through vertices finds closes neighbors
            for (j = vertexList.begin(); j != vertexList.end(); j++)
            {
                if ((*j)->visited == false)
                {
                    distance = distanceEarth(vertexList[c]->loc.lat, vertexList[c]->loc.lon, (*j)->loc.lat, (*j)->loc.lon);

                    if (distance > 0)
                    {
                        E.Insert(new edge(vertexList[c]->ID, (*j)->ID, distance, colors[rand() % 9]));
                    }
                }
            }

            e = E.Extract();

            addEdge(e->fromID, e->toID, e->weight, false, colors[count % 9]);
            vertexList[e->fromID]->visited = true;
            vertexList[e->toID]->visited = true;

            E.ClearHeap();
            c++;
            if (c == vertexList.size())
            {
                c = 0;
                cout << "looping around\n";
            }
        }
    }

    void createForest()
    {
        E = new edgePriorityList[vertexList.size()];
        edge *e;

        double distance = 0;
        double minDistance = MAXFLOAT;

        // for every vertex, find its closest neighbors and push on its list
        for (int v1 = 0; v1 < vertexList.size(); v1++)
        {
            cout << "Connecting: " << vertexList[v1]->city << endl;

            // Inner loop through vertices finds closes neighbors
            for (int v2 = 0; v2 < vertexList.size(); v2++)
            {
                if (vertexList[v2]->visited == false)
                {
                    distance = distanceEarth(vertexList[v1]->loc.lat, vertexList[v1]->loc.lon, vertexList[v2]->loc.lat, vertexList[v2]->loc.lon);

                    if (distance > 0)
                    {
                        // add edge to vertex: c's priority queue
                        // closest edge to "c" in front of list
                        E[v1].Insert(new edge(vertexList[v1]->ID, vertexList[v2]->ID, distance, "Pink"));
                    }
                }
            }
        }

        // Connect close neighbors and create a disconnected forest
        // using the priority queue's for each vertex
        for (int v = 0; v < vertexList.size(); v++)
        {
            e = E[v].Pop();

            e->color = "Green";

            cout << "edge weight: " << e->weight << endl;

            addEdge(e->fromID, e->toID, e->weight, false, "Green");
        }

        for (int v = 0; v < vertexList.size(); v++)
        {
            E[v].ClearList();
        }
        delete E;
    }

    void connectForest()
    {
        bool neighbor;
        double distance;
        edge *e;

        E = new edgePriorityList[vertexList.size()];

        // for every vertex, find its non neighbor
        for (int v1 = 0; v1 < vertexList.size(); v1++)
        {
            // Inner loop through vertices finds closes non neighbors
            for (int v2 = 0; v2 < vertexList.size(); v2++)
            {
                neighbor = vertexList[v1]->Neighbors(vertexList[v2]->ID);
                cout << "neighbor: " << neighbor << endl;
                if (!neighbor)
                {
                    distance = distanceEarth(vertexList[v1]->loc.lat, vertexList[v1]->loc.lon, vertexList[v2]->loc.lat, vertexList[v2]->loc.lon);

                    if (distance > 0)
                    {
                        // add edge to vertex: c's priority queue
                        // closest edge to "v1" that is a non-neighbor
                        E[v1].Insert(new edge(vertexList[v1]->ID, vertexList[v2]->ID, distance, "Purple"));
                    }
                }
            }
        }

        // Connect close neighbors and create a disconnected forest
        // using the priority queue's for each vertex
        for (int v = 0; v < vertexList.size(); v++)
        {
            e = E[v].Pop();
            e->color = "Orange";

            cout << "edge weight: " << e->weight << endl;
            cout << "edge color:  " << e->color << endl;

            addEdge(e->fromID, e->toID, e->weight, false, "Orange");
        }
    }

    // vector<vector<int>> BuildNetwork()
    // {
    //     vector<vector<int>> network;

    //     for (int v = 0; v < vertexList.size(); v++)
    //     {
    //         network[0][0] = 0;
    //     }
    //     return network;
    // }

    void printVids()
    {
        vector<vertex *>::iterator vit;
        vector<edge>::iterator eit;

        for (vit = vertexList.begin(); vit != vertexList.end(); vit++)
        {
            cout << (*vit)->ID << endl;
        }
    }

    string graphViz(bool directed = true, int scale = 0)
    {
        vector<vertex *>::iterator vit;
        vector<edge>::iterator eit;

        // [label="hi", weight=100];

        string viz = "";
        string labels = "";
        string conns = "";
        int weight = 0;
        string arrow = "";
        int x;
        int y;

        if (directed)
        {
            viz = "digraph G {\n";
            arrow = "->";
        }
        else
        {
            viz = "graph G {\n";
            arrow = "--";
        }

        for (vit = vertexList.begin(); vit != vertexList.end(); vit++)
        {
            if ((*vit)->E.size() > 0)
            {
                x = (*vit)->p.x;
                y = (*vit)->p.y;

                labels += "\t" + to_string((*vit)->ID) + " [\n\t\tlabel=\"" + (*vit)->city + ", " + (*vit)->state + "\" \n\t\tpos = \"" + to_string(x) + "," + to_string(y) + "!\"\n\t]\n";

                for (eit = (*vit)->E.begin(); eit != (*vit)->E.end(); eit++)
                {
                    x = vertexList[eit->toID]->p.x;
                    y = vertexList[eit->toID]->p.y;
                    labels += "\t" + to_string(eit->toID) + " [\n\t\tlabel=\"" + vertexList[eit->toID]->city + ", " + vertexList[eit->toID]->state + "\"]\n\t\tpos = \"" + to_string(x) + "," + to_string(y) + "!\"\n\t]\n";
                    weight = eit->weight;
                    conns += "\t" + to_string((*vit)->ID) + arrow + to_string(eit->toID) + " [weight=" + to_string(weight) + ", label=" + to_string(weight) + "]\n";
                }
            }
            else
            {
                x = (*vit)->p.x;
                y = (*vit)->p.y;

                labels += "\t" + to_string((*vit)->ID) + " [\n\t\tlabel=\"" + (*vit)->city + ", " + (*vit)->state + "\" \n\t\tpos = \"" + to_string(x) + "," + to_string(y) + "!\"\n\t]\n";
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
    int *graphSize()
    {
        int *vals = new int[2];
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