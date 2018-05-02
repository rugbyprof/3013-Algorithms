// A simple representation of graph using STL
#include "graph.h"
#include <SFML/Graphics.hpp>
#include <unistd.h>

using namespace std;

void randomEdges(graph &g, int numEdges)
{
    int r1, r2;
    latlon from;
    latlon to;
    double d;
    for (int i = 0; i < numEdges; i++)
    {
        r1 = rand() % g.vertexList.size();
        r2 = rand() % g.vertexList.size();
        from = g.vertexList[r1]->loc;
        to = g.vertexList[r2]->loc;
        d = distanceEarth(from.lat, from.lon, to.lat, to.lon);
        g.addEdge(r1, r2, (int)d, true);
    }
}

/**
 * loadGraphCSV - loads a graph with the given csv
 * Params:
 *     string filename  - filename to open
 * Returns 
 *     graph
 */
graph loadGraphCSV(string filename, int max = 0, string fstate = "")
{
    int zip;
    double lat;
    double lon;
    string city;
    string state;
    string county;

    strMapInt cityCheck;

    int i = 0;

    graph G;
    int vid;
    vertex *temp;

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

            if (fstate == "" || fstate == state)
            {
                if ((int)lat == 0 || (int)lon == 0)
                {
                    cout << "oops: " << city << ", " << state << ", " << lat << ", " << lon << endl;
                }

                vid = G.addVertex(city, state, lat, lon);
            }
            i++;
        }

        if (i > max && max != 0)
        {
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
void filterDups(string filename, string outfile)
{
    int zip;
    double lat;
    double lon;
    string city;
    string state;
    string county;

    strMapInt cityCheck;

    int i = 0;

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

        if (cityCheck.find(city) == cityCheck.end() && abs(lat) > 0 && abs(lon) > 0)
        {
            // Add the city as a key to the map.
            cityCheck[city] = 0;
            out << zip << "," << lat << "," << lon << "," << city << "," << state << "," << county << "\n";
        }
    }
}

point adjust(graph &G, point o,int width, int height){
    if(o.x == G.box.minx || o.x == G.box.maxx){
        o.x = 0;
    }else{
        o.x = ((o.x - G.box.minx) / (G.box.maxx - G.box.minx)) * width;
    }

    if(o.y == G.box.miny || o.y == G.box.maxy){
        o.y = 0;
    }else{
        o.y = height - (((o.y - G.box.miny) / (G.box.maxy - G.box.miny)) * height);
    }
    
    return o;
}

void createForest(graph &G, int v1, sf::VertexArray &lines, int width, int height)
{
    edgePriorityList E;
    edge *e;

    double distance = 0;
    double minDistance = MAXFLOAT;

    // Inner loop through vertices finds closes neighbors
    for (int v2 = 0; v2 < G.vertexList.size(); v2++)
    {
        if (G.vertexList[v2]->visited == false)
        {
            distance = distanceEarth(G.vertexList[v1]->loc.lat, G.vertexList[v1]->loc.lon, G.vertexList[v2]->loc.lat, G.vertexList[v2]->loc.lon);
            if (distance > 0)
            {
                // add edge to vertex: c's priority queue
                // closest edge to "c" in front of list
                E.Insert(new edge(G.vertexList[v1]->ID, G.vertexList[v2]->ID, distance, "Pink"));
            }
        }
    }

    //cout<<"Length: "<<E.length<<endl;

    // Connect close neighbors and create a disconnected forest
    // using the priority queue's for each vertex

    for (int i = 0; i < 2; i++)
    {
        e = E.Pop();

        if(G.vertexList[e->toID]->visited){
            continue;
        }

        G.addEdge(e->fromID, e->toID, e->weight, false, "Green");
        point p1 = G.vertexList[e->fromID]->p;

        G.vertexList[e->fromID]->visited = true;
        G.vertexList[e->toID]->visited = true;

        point p2 = G.vertexList[e->toID]->p;

        p1 = adjust(G,p1,width,height);
        p2 = adjust(G,p2,width,height);

        // p1.x = abs(((p1.x - G.box.minx) / (G.box.maxx - G.box.minx)) * width);
        // p1.y = abs(height - (((p1.y - G.box.miny) / (G.box.maxy - G.box.miny)) * height));

        // p2.x = abs(((p2.x - G.box.minx) / (G.box.maxx - G.box.minx)) * width);
        // p2.y = abs(height - (((p2.y - G.box.miny) / (G.box.maxy - G.box.miny)) * height));

        cout << p1 << endl;
        cout << p2 << endl;

        if(p1.x > width || p1.y > height || p2.x > width || p2.y > height){
            cout<<"shut up glebe :) "<<endl;
            return;
        }

        lines.append(sf::Vector2f(p1.x, p1.y));
        lines.append(sf::Vector2f(p2.x, p2.y));
    }

    E.ClearList();
}



int main()
{
    srand(984325);
    int max_vertices = 0;
    int max_edges = 0;
    string state = "TX";

    sf::Color color(255, 0, 0);

    int width = 1000;
    int height = 800;

    vertex *temp;
    point p;

    cout << "Creating graph...\n";
    graph G = loadGraphCSV("./random_data_files/filtered_cities.csv", max_vertices, state);

    cout<<G.box<<endl;

    cout << G.maxID() << endl;

    //cout<<"Adding edges ... \n";
    //G.createForest();
    //G.connectForest();

    //create window
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");

    vector<sf::CircleShape *> nodes;

    sf::VertexArray lines(sf::LinesStrip, 0);

    for (int i = 0; i < G.maxID(); i++)
    {
        temp = G.getVertex(i);
        p = temp->p;

        p = adjust(G,p,width,height);
        // p.x = abs(((p.x - G.box.minx) / (G.box.maxx - G.box.minx)) * width);
        // p.y = abs(height - (((p.y - G.box.miny) / (G.box.maxy - G.box.miny)) * height));

        //cout<<p<<endl;

        nodes.push_back(new sf::CircleShape(5));

        nodes[i]->setPosition(p.x, p.y);

        //cout << p << endl;
    }

    sf::CircleShape *node = new sf::CircleShape(25.f);
    float x = 1.0;
    float y = 1.0;
    float yinc = 4;
    float xinc = 4;
    node->setPosition(x, y);
    node->setFillColor(sf::Color(255,0,0));


    int i = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        

        node->setPosition(x += xinc, y += yinc);

        //if ball hits border
        if (x <= 0 || x > width)
        {
            xinc *= -1;
            node->setFillColor(sf::Color(rand()%255,rand()%255,rand()%255));
        }
        if (y <= 0 || y > height)
        {
            yinc *= -1;
            node->setFillColor(sf::Color(rand()%255,rand()%255,rand()%255));
        }

        for (int i = 0; i < nodes.size(); i++)
        {
            window.draw(*nodes[i]);
        }

        temp = G.getVertex(i);
        p = temp->p;

        p = adjust(G,p,width,height);

        // p.x = ((p.x - G.box.minx) / (G.box.maxx - G.box.minx)) * width;
        // p.y = height - (((p.y - G.box.miny) / (G.box.maxy - G.box.miny)) * height);

        lines.append(sf::Vector2f(p.x, p.y));

        i++;

        cout<<"v="<<G.AllVisited()<<endl;
        if (G.AllVisited() || i > G.maxID() )
        {
            i = 0;
            lines.clear();
            G.Reset();
            //exit(0);
        }

        createForest(G, i, lines, width, height);
        //usleep(5000);

        window.draw(lines);
        window.draw(*node);
        window.display();
    }
    return 0;
}