// A simple representation of graph using STL
#include <vector>
#include <map>
#include <iostream>
#include <string>

using namespace std;

struct latlon{
    double lat;
    double lon;
    latlon(){
        lat=0.0;
        lon=0.0;
    }

    latlon(double y,double x){
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
    latlon& operator= (const latlon &ll)
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
    friend ostream &operator<<(ostream &output,const latlon &ll ) { 
        output << "(" << ll.lat << ","<< ll.lon <<")";
        return output;            
    }
};

struct edge{
    int toID;
    double weight;
    bool used;
    edge(int id,double w){
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
    friend ostream &operator<<(ostream &output,const edge &e ) { 
        output << "(To:" << e.toID << " W: "<< e.weight <<" U: "<<e.used<<")";
        return output;            
    }
};

struct vertex{
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
    vertex(int id,string c,string s,latlon ll=latlon()){
        ID = id;
        city = c;
        state = s;
        visited = false;
    }

    /**
     * operator<< - overload cout for vertex
     * Params:
     *     const vertex v     - vertex to print
     * Returns 
     *     formatted output for a vertex
     */
    friend ostream &operator<<(ostream &output,const vertex &v ) { 
        output << "(ID:" << v.ID << " C: "<< v.city <<" S: "<<v.state<<" L: "<<v.loc<<")";
        return output;            
    }
};



typedef map<string, int> strMapInt;

class graph{    
private:
    int id;
    vector<vertex*> vertexList;

    /*--------  private methods  --------*/

    vertex* createVertex(string city,string state){
        return new vertex(id++,city,state);
    }

    
    /*--------  public methods  --------*/
    
public:

    graph(){
        id = 0;
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
    int addVertex(string city,string state,double lat=0.0, double lon=0.0){
        vertex* temp = createVertex(city,state);
        vertexList.push_back(temp);
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
    void addEdge(int fromID, int toID, double weight = 0, bool directed = false){
        edge e1(toID,weight);
        vertexList[fromID]->E.push_back(e1);
        if(!directed){
            edge e2(fromID,weight);
            vertexList[toID]->E.push_back(e2);
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
    void addEdge(string fromCity, string toCity, double weight=0,bool directed = false){

    }

    /**
     * printGraph - prints the graph out for debugging purposes
     * Params:
     *     void
     */
    void printGraph()
    {

        vector<vertex*>::iterator vit;
        vector<edge>::iterator eit;

        for (vit = vertexList.begin(); vit != vertexList.end(); vit++)
        {
            cout<<*(*vit)<<endl;

            if((*vit)->E.size() > 0){
                for (eit = (*vit)->E.begin(); eit != (*vit)->E.end(); eit++)
                {
                    cout<<"\t"<<(*eit)<<endl;
                }
            }
        }
    }


};


 
// Test Driver
int main()
{
    graph G;
    cout<<G.addVertex("austin","tx")<<endl;
    cout<<G.addVertex("san antonio","tx")<<endl;
    cout<<G.addVertex("dallas","tx")<<endl;
    G.addEdge(0,1,60);
    G.addEdge(0,2,200);
    // G.addEdge(2,0,130);
    // G.addEdge(2,1,140);
    G.printGraph();
    return 0;
}