#pragma once
#include "json.hpp"
#include <fstream>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>

// https://graphviz.readthedocs.io/en/stable/manual.html
// https://dreampuf.github.io/GraphvizOnline/

using namespace std;

using json = nlohmann::json;


/**
 * @brief   Organizes all the valid shape, style, or color names so we can check
 *          for valid ones.
 * @note   
 * @retval None
 */
struct Names {
    json j;
    Names();
    string makeLower(string);
    bool validShape(string);
    bool validNodeStyle(string);
    bool validEdgeStyle(string);
    bool validColor(string);
};


class GraphViz {
    json graph;
    map<string,json> nodeStyles;
    map<string,json> edgeStyles;
    Names validNames;
    string nodeColor;
    string edgeColor;
    string nodeStyle;
    string nodeShape;
    string edgeStyle;
    string nodeFill;

protected:
    string dotText; // string var to hold dot graph text
    string graphType;

    bool _nodeExists(string);
    bool _edgeExists(string);
    json _getNodeStyle(string);
    json _getEdgeStyle(string);
    json _getNeighborstyle(string,string);
    bool _addNode(string ,string );
    bool _addEdge(string, string);

public:
    GraphViz();
    bool addNode(string);
    bool addNode(string,string);
    bool addEdge(string, string);
    void setNodeColor(string);
    void setEdgeColor(string);
    void setNodeStyle(string);
    void addNodeStyle(string , string , string);
    void addEdgeStyle(string , string , string);
    void setEdgeStyle(string);
    bool nodeExists(string);
    bool edgeExists(string);
    void setFillNodes(bool);
    void printNodes();
    json getNeighbors(string);
    string dumpGraph();
    friend ostream &operator<<(ostream &,  GraphViz &);
};