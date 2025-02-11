#include "graphviz.h"

// https://graphviz.readthedocs.io/en/stable/manual.html
// https://dreampuf.github.io/GraphvizOnline/

using namespace std;

using json = nlohmann::json;

const string NIL = "";
const string SHAPES[] = {"box", "circle", "diamond", "doublecircle", "doubleoctagon",
                         "egg", "ellipse", "hexagon", "house", "invhouse", "invtrapezium",
                         "invtriangle", "Mcircle", "Mdiamond", "Msquare", "none", "octagon",
                         "oval", "parallelogram", "pentagon", "plain", "plaintext", "point",
                         "polygon", "rect", "rectangle", "septagon", "square", "star",
                         "trapezium", "triangle", "tripleoctagon"};

const string NODESTYLES[] = {"bold", "dashed", "diagonals", "dotted", "filled", "invis",
                             "radial", "rounded", "solid", "striped", "wedged"};

const string EDGESTYLES[] = {"bold", "dashed", "dotted", "invis", "solid", "tapered"};

Names::Names() {
    j["shape_name"] = SHAPES;
    j["node_style"] = NODESTYLES;
    j["edge_style"] = EDGESTYLES;
    std::ifstream i("x11_colors.json");
    i >> j["colors"];
}

/**
 * makeLower
 * 
 * @param  string s: string to lowercase
 * @retval string
 */
string Names::makeLower(string s) {
    // 97-122 lowercase
    // 65-90 capital
    string lowered = "";
    for (int i = 0; i < s.size(); i++) {
        int a = int(s[i]);
        if (a >= 65 and a <= 90) {
            lowered += char(a + 32);
        } else {
            lowered += s[i];
        }
    }
    return lowered;
}

bool Names::validShape(string name) {
    for (json::iterator it = j["shapes"].begin(); it != j["shapes"].end(); ++it) {
        if (*it == name) {
            return true;
        }
    }
    return false;
}

bool Names::validNodeStyle(string name) {
    for (json::iterator it = j["node_style"].begin(); it != j["node_style"].end(); ++it) {
        if (*it == name) {
            return true;
        }
    }
    return false;
}

bool Names::validEdgeStyle(string name) {
    for (json::iterator it = j["edge_style"].begin(); it != j["edge_style"].end(); ++it) {
        if (*it == name) {
            return true;
        }
    }
    return false;
}

bool Names::validColor(string name) {

    for (json::iterator it = j["colors"].begin(); it != j["colors"].end(); ++it) {
        //cout<<*it["name"].get<std::string>()<<endl;

        string color = makeLower((*it)["name"].get<std::string>());
        name = makeLower(name);
        if (color == name) {
            return true;
        }
    }
    return false;
}

bool GraphViz::_nodeExists(string id) {
    for (json::iterator it = graph["nodes"].begin(); it != graph["nodes"].end(); ++it) {

        string dd = (*it)["id"].get<std::string>();
        if (dd == id) {
            //cout << "Node exists!!" << endl;
            return true;
        }
    }
    return false;
}

bool GraphViz::_edgeExists(string id) {
    for (json::iterator it = graph["edges"].begin(); it != graph["edges"].end(); ++it) {

        string dd = (*it)["id"].get<std::string>();
        if (dd == id) {
            //cout << "Node exists!!" << endl;
            return true;
        }
    }
    return false;
}

json GraphViz::_getNodeStyle(string id = "") {
    json j = json::object();
    if (id == "") {
        j["color"] = nodeColor;
        j["shape"] = nodeShape;
        j["style"] = nodeStyle;
    } else {
        j = nodeStyles[id];
    }
    return j;
}

json GraphViz::_getEdgeStyle(string id = "") {
    json j = json::object();
    if (id == "") {
        j["color"] = edgeColor;
        j["style"] = edgeStyle;
    } else {
        j = edgeStyles[id];
    }
    return j;
}

json GraphViz::_getNeighborstyle(string from = "", string to = "") {
    json j = json::object();
    if (from == "" && to == "") {
        j["color"] = nodeColor;
        j["style"] = nodeStyle;
    } else {
        j = edgeStyles[from + "." + to];
    }
    return j;
}

/**
 * protected: _addNode - actually inserts node if it doesn't exist.
 * params:
 *      [string] id : uid of node getting added
 * returns:
 *      bool : success = true / false = fail
 */
bool GraphViz::_addNode(string id, string label) {

    if (!_nodeExists(id)) {
        if (label == "") {
            label = id;
        }
        json node = _getNodeStyle();

        node["id"] = id;
        node["label"] = label;
        graph["nodes"].push_back(node);

        nodeStyles[id] = node;
        return true;
    }
    return false;
}

/**
 * protected: _addEdge - actually inserts edge if it doesn't exist.
 * params:
 *      [string] from : uid of start of edge
 *      [string] to   : uid of end of edge
 * returns:
 *      bool : success = true / false = fail
 */
bool GraphViz::_addEdge(string from, string to) {
    json edge = json::object(); // empty json object
    string id = "";             // edge id = from.to

    edge["from"] = from; // add from id to json
    edge["to"] = to;     // add to id to json

    id = from + "." + to; // from.to

    edge["id"] = id; // load into json object

    if (!_edgeExists(id)) { // if edge does not exist

        json edgeStyle = _getEdgeStyle();

        edgeStyles[id] = edgeStyle;

        if (!_nodeExists(from)) { // if from is not a node already
            _addNode(from, from); //    then make it one
        }
        if (!_nodeExists(to)) { // same with to ...
            _addNode(to, to);
        }

        graph["edges"].push_back(edge); // add edge to json array

        return true;
    }
    return false;
}

GraphViz::GraphViz() {

    graph["graph_type"] = "digraph";
    graph["nodes"] = json::array();
    graph["edges"] = json::array();

    nodeColor = "black";
    edgeColor = "black";
    nodeStyle = "solid";
    nodeShape = "ellipse";
    edgeStyle = "solid";
    nodeFill = false;
}

/**
 * public: addNode - calls private add method to add a node
 * params:
 *      [string] id : uid of node getting added
 * returns:
 *      bool : success = true / false = fail
 */
bool GraphViz::addNode(string id, string label = "") {
    return _addNode(id, label);
}

bool GraphViz::addNode(string id) {
    return _addNode(id, id);
}

/**
 * public: add - calls private add method to add node
 * params:
 *      [string] id : uid of node getting added
 * returns:
 *      bool : success = true / false = fail
 */
bool GraphViz::addEdge(string from, string to) {
    return _addEdge(from, to);
}

/**
 * public: setNodeColor - set color of the nodes
 * params:
 *      [string] color : color to set nodes to (see top of file for colors)
 * returns:
 *      void
 */
void GraphViz::setNodeColor(string color) {
    if (validNames.validColor(color)) {
        nodeColor = color;
    } else {
        cout << "Invalid color!" << endl;
    }
}

/**
 * public: setEdgeColor - set color of the edges
 * params:
 *      [string] color : color to set edges to (see top of file for colors)
 * returns:
 *      void
 */
void GraphViz::setEdgeColor(string color) {
    if (validNames.validColor(color)) {
        edgeColor = color;
    } else {
        cout << "Invalid color!" << endl;
    }
}

/**
 * public: setNodeStyle - set style of the nodes
 * params:
 *      [string] color : "the" style (see top of file for styles)
 * returns:
 *      void
 */
void GraphViz::setNodeStyle(string style) {
    if (validNames.validNodeStyle(style)) {
        nodeStyle = style;
    } else {
        cout << "Invalid Node style!" << endl;
    }
}

void GraphViz::addNodeStyle(string id, string key, string val) {
    nodeStyles[id][key] = val;
}

void GraphViz::addEdgeStyle(string id, string key, string val) {
    edgeStyles[id][key] = val;
}


bool GraphViz::nodeExists(string id){
    return _nodeExists(id);
}

bool GraphViz::edgeExists(string id){
    return _edgeExists(id);
}

/**
 * public: setEdgeStyle - set style of the edges
 * params:
 *      [string] color : "the" style (see top of file for styles)
 * returns:
 *      void
 */
void GraphViz::setEdgeStyle(string style) {
    if (validNames.validEdgeStyle(style)) {
        edgeStyle = style;
    } else {
        cout << "Invalid Edge style!" << endl;
    }
}

/**
 * public: setFillNodes - fill nodes when printing or not
 * params:
 *      [bool] fill : T/F (fill or not)
 * returns:
 *      void
 */
void GraphViz::setFillNodes(bool fill) {
    nodeFill = fill;
    if (fill) {
        nodeStyle = "filled";
    } else {
        nodeStyle = "solid";
    }
}

void GraphViz::printNodes() {
    for (json::iterator it = graph["nodes"].begin(); it != graph["nodes"].end(); ++it) {
        cout << *it << endl;
    }
}

json GraphViz::getNeighbors(string id) {
    json edges = json::array();
    for (json::iterator it = graph["edges"].begin(); it != graph["edges"].end(); ++it) {
        //cout<<*it["name"].get<std::string>()<<endl;

        string from = (*it)["from"].get<std::string>();
        //cout<<from<<","<<id<<endl;
        if (from == id) {
            edges.push_back(*it);
        }
    }
    return edges;
}

string GraphViz::dumpGraph() {
    string key, val; // key value from json objects
    string dot = "";
    string edge = "->"; // directed edges

    if (graph["graph_type"].get<std::string>() == "graph") {
        edge = "--"; // undirected edges
    }

    // print out first line of dot language for graph
    // e.g. digraph G {
    // or   graph G {
    dot += graph["graph_type"].get<std::string>() + " G {\n";

    // loop through nodes and add them to the graph
    for (json::iterator it = graph["nodes"].begin(); it != graph["nodes"].end(); ++it) {
        string id = (*it)["id"].get<std::string>();
        string label = (*it)["label"].get<std::string>();
        //os << rhs.nodeStyles[id] << endl;
        dot += "\t" + id + "  [";
        for (json::iterator it = nodeStyles[id].begin(); it != nodeStyles[id].end(); ++it) {
            key = it.key();
            val = it.value();
            dot += "\"" + key + "\" = \"" + val + "\", ";
        }
        dot += "];\n";
    }

    for (json::iterator it = graph["edges"].begin(); it != graph["edges"].end(); ++it) {
        string from = (*it)["from"].get<std::string>();
        string to = (*it)["to"].get<std::string>();
        string id = from + "." + to;

        //os << rhs.nodeStyles[id] << endl;
        dot += "\t" + from + edge + to + " [";
        for (json::iterator it = edgeStyles[id].begin(); it != edgeStyles[id].end(); ++it) {
            key = it.key();
            val = it.value();
            dot += "\"" + key + "\" = \"" + val + "\", ";
        }
        dot += "];\n";
    }
    dot += "}\n";
    return dot;
}

/**
 * This method prints a dot graph to output. 
 */
ostream &operator<<(ostream &os, GraphViz &rhs) {

    return os << rhs.dumpGraph();
}
