/**
* Implementation File
*/
#include "Bst.h"

Node::Node() {
    data = 0;
    left = right = NULL;
}

Node::Node(int x) {
    data = x;
    left = right = NULL;
}

Bst::Bst() {
    size = 0;
    root = NULL;
}

Bst::Bst(int *A) {
}

void Bst::Insert(Node *&root, int val) {
    if (!root) {
        root = new Node(val);
        return;
    } else {
        if (root->data > val) {
            Insert(root->left, val);
        } else {
            Insert(root->right, val);
        }
    }
}

void Bst::Insert(int data) {

    if (!root) {
        Node *temp = new Node(data);
        root = temp;
    } else {
        Insert(root, data);
    }
}

void Bst::Print() {
    Print(root);
}

void Bst::Print(Node *root) {
    if (!root) {
        return;
    } else {
        //PreOrder
        Print(root->left);
        cout << root->data << " ";
        //InOrder
        Print(root->right);
        //PostOrder
    }
}

void Bst::BuildGraphViz(Node *root) {
    if (!root) {
        return;
    } else {
        BuildGraphViz(root->left);

        if (!G.nodeExists(to_string(root->data))) {
            G.addNode(to_string(root->data));
        }

        if (root->left) {
            string id = to_string(root->data) + "." + to_string(root->left->data);
            if (!G.edgeExists(id)) {
                G.addEdge(to_string(root->data), to_string(root->left->data));
                G.addEdgeStyle(id, "color", "blue");
                G.addEdgeStyle(id, "label", "-");
            }

        } else if (root->right) {
            string id = to_string(root->data) + "." + to_string(root->right->data);
            if (!G.edgeExists(id)) {
                G.addEdge(to_string(root->data), to_string(root->right->data));
                G.addEdgeStyle(id, "color", "red");
                G.addEdgeStyle(id, "label", "+");
            }
        } else {
            string toid = "NULL" + to_string(rand());
            string id = to_string(root->data) + "." + toid;
            G.addEdge(to_string(root->data), toid);
            G.addNodeStyle(toid, "shape", "point");
            G.addNodeStyle(toid, "label", "NULL");
            G.addNodeStyle(to_string(root->data), "style", "filled");
            G.addNodeStyle(to_string(root->data), "fontcolor", "white");
            G.addEdgeStyle(id, "minlen", "1");
        }
        BuildGraphViz(root->right);
    }
}

void Bst::BuildGraphViz() {
    BuildGraphViz(root);
}

void Bst::PrintGraphViz() {
    cout << G.dumpGraph() << endl;
}

bool Bst::Find(Node *root, int key) {
    if (!root) {
        return false;
    } else {
        //PreOrder
        if (root->data == key) {
            return true;
        } else if (key < root->data) {
            return Find(root->left, key);
        } else {
            return Find(root->right, key);
        }
    }
}

bool Bst::Find(int key) {

    return Find(root, key);
}

void Bst::Delete() {
}