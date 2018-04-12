// A simple representation of graph using STL
#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <string>
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
 * edge - represents the edge of a graph.
 */
struct edge
{
    int toID;      // id of vertex edge is going to
    double weight; // weight of edge if any
    bool used;     // was edge used in some traversal
    edge(int id, double w)
    {

        toID = id;
        weight = w;
        used = false;
    }

    /**
     * operator<< - overload cout for edge
     * Params:
     *     const edge e     - edge to print
     * Returns 
     *     formatted output for an edge
     */
    friend ostream &operator<<(ostream &output, const edge &e)
    {
        output << "(To:" << e.toID << " W: " << e.weight << " U: " << e.used << ")";
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
    void createSpanningTree()
    {

        vector<vertex *>::iterator i;
        vector<vertex *>::iterator j;
        vector<edge>::iterator eit;

        double distance = 999999;
        int closestID;

        // loop through vertices
        for (i = vertexList.begin(); i != vertexList.end(); i++)
        {
            cout<<(*i)->ID<<endl;
            for (j = vertexList.begin(); j != vertexList.end(); j++)
            {
                cout<<(*j)->ID<<endl;
                // calculate distance between the two
                // be careful some lat lon pairs are the same 
                // and don't add an edge to yourself.
            }
            // addEdge(int fromID, int toID, double weight = 0, bool directed = false);
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

void randomEdges(graph &g,int numEdges){
    int r1,r2;
    latlon from;
    latlon to;
    double d;
    for(int i=0;i<numEdges;i++){
        r1 = rand() % g.vertexList.size();
        r2 = rand() % g.vertexList.size();
        from = g.vertexList[r1]->loc;
        to = g.vertexList[r2]->loc;
        d = distanceEarth(from.lat,from.lon,to.lat,to.lon);
        g.addEdge(r1,r2,(int)d,true);
    }
}

/**
 * loadGraphCSV - loads a graph with the given csv
 * Params:
 *     string filename  - filename to open
 * Returns 
 *     graph
 */
graph loadGraphCSV(string filename,int max=0)
{
    int zip;
    double lat;
    double lon;
    string city;
    string state;
    string county;

    strMapInt cityCheck;

    int i=0;

    graph G;

    ifstream file(filename);

    for (CSVIterator loop(file); loop != CSVIterator(); ++loop)
    {
        zip = stoi((*loop)[0]);
        if ((*loop)[1].length() > 0)
        {
            lat = stod((*loop)[1]);
        }
        else
        {
            lat = 0.0;
        }

        if ((*loop)[2].length() > 0)
        {
            lon = stod((*loop)[2]);
        }
        else
        {
            lon = 0.0;
        }

        city = (*loop)[3];
        state = (*loop)[4];
        county = (*loop)[5];

        
        if (cityCheck.find(city) == cityCheck.end())
        {   
            // Add the city as a key to the map.
            cityCheck[city] = 0;

            if(state != "PR"){
                G.addVertex(city, state, lat, lon);
                i++;
            }
        }

        if(i > max && max != 0){
            return G;
        }
        
    }

    return G;
}

/**
 * filterDups - filters out duplicate cities and creates new output file
 * Params:
 *     string filename  - filename to open
 *     string outfile   - filename to write to
 * Returns 
 *     graph
 */
void filterDups(string filename,string outfile)
{
    int zip;
    double lat;
    double lon;
    string city;
    string state;
    string county;

    strMapInt cityCheck;

    int i=0;


    ifstream file(filename);
    ofstream out(outfile);

    for (CSVIterator loop(file); loop != CSVIterator(); ++loop)
    {
        zip = stoi((*loop)[0]);
        if ((*loop)[1].length() > 0)
        {
            lat = stod((*loop)[1]);
        }
        else
        {
            lat = 0.0;
        }

        if ((*loop)[2].length() > 0)
        {
            lon = stod((*loop)[2]);
        }
        else
        {
            lon = 0.0;
        }

        city = (*loop)[3];
        state = (*loop)[4];
        county = (*loop)[5];

        
        if (cityCheck.find(city) == cityCheck.end())
        {   
            // Add the city as a key to the map.
            cityCheck[city] = 0;
            out<<zip<<","<<lat<<","<<lon<<","<<city<<","<<state<<","<<county<<"\n";

        }

        
    }

}

// Test Driver
int main(int argc, char **argv)
{
    srand(984325);
    int max_vertices = 0;
    int max_edges = 0;

    if(argc > 2){
        max_vertices = stoi(argv[1]);
        max_edges = stoi(argv[2]);
    }else{
        cout<<"Usage: ./graph max_vertices max_edges"<<endl;
        exit(0);
    }

    graph G = loadGraphCSV("filtered_cities.csv",max_vertices);

    //filterDups("cities.csv","filtered_cities.csv");
    
    randomEdges(G,max_edges);

    //G.printGraph();
    cout<<G.searchGraph("truro")<<endl;

    //cout<<G.graphViz(false);

    //G.printVids();

    //int *size = G.graphSize();

    //cout<<"V= "<<size[0]<<" E= "<<size[1]<<endl;

    // for(int i=0;i<G.vertexList.size();i++){
    //     cout<<(*G.vertexList[i])<<endl;
    // }
    return 0;
}