#include "graphviz.hpp"

// https://graphviz.readthedocs.io/en/stable/manual.html
// https://dreampuf.github.io/GraphvizOnline/

using namespace std;


int main() {
    GraphViz G;

    G.setEdgeStyle("tapered");

    G.addNode("A","Alpha");
    G.addNode("B");
    G.addNode("C","Charlie");
    G.addNode("D");

    G.addEdge("D","A");
    G.addEdge("C","A");
    G.addEdge("A","B");
    G.addEdge("B","C");
    G.addEdge("B","A");
    G.addEdge("B","D");
    G.addEdge("A","F");

    G.addNodeStyle("A","shape","box");
    G.addNodeStyle("A","style","filled");
    G.addNodeStyle("A","fontcolor","white");

    G.addEdgeStyle("C.A","color","red");
    G.addEdgeStyle("C.A","style","dashed");
    // G.printNodes();

    // G.setFillNodes(true);

    cout<<G.getNeighbors("B")<<endl;
    cout<<G<<endl;
    return 0;
}