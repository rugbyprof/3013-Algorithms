#pragma once
#include "graphviz.h"
#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node *left;
    Node *right;
    Node();
    Node(T);
};

template <typename T>
class Bst {
private:
    Node<T> *root;
    GraphViz G;
    int size;
    void Print(Node<T> *);
    void Insert(Node<T> *&, T);
    bool Find(Node<T> *, T);
    void BuildGraphViz(Node<T> *);

public:
    Bst();
    Bst(T *);
    void Insert(T);
    void Print();
    bool Find(T);
    void Delete();
    void BuildGraphViz();
    void PrintGraphViz();
};

template <typename T>
Node<T>::Node() {
    data = 0;
    left = right = NULL;
}

template <typename T>
Node<T>::Node(T x) {
    data = x;
    left = right = NULL;
}

template <typename T>
Bst<T>::Bst() {
    size = 0;
    root = NULL;
}

// Bst<T>::Bst(T *A) {
// }

template <typename T>
void Bst<T>::Insert(Node<T> *&root, T val) {
    if (!root) {
        root = new Node<T>(val);
        return;
    } else {
        if (root->data > val) {
            Insert(root->left, val);
        } else {
            Insert(root->right, val);
        }
    }
}

template <typename T>
void Bst<T>::Insert(T data) {

    if (!root) {
        Node<T> *temp = new Node<T>(data);
        root = temp;
    } else {
        Insert(root, data);
    }
}

template <typename T>
void Bst<T>::Print() {
    Print(root);
}

template <typename T>
void Bst<T>::Print(Node<T> *root) {
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

template <typename T>
void Bst<T>::BuildGraphViz(Node<T> *root) {
    if (!root) {
        return;
    } else {
        BuildGraphViz(root->left);

        if (!G.nodeExists(root->data)) {
            G.addNode(root->data);
        }

        if (root->left) {
            string id = root->data + "." + root->left->data;
            if (!G.edgeExists(id)) {
                G.addEdge(root->data, root->left->data);
                G.addEdgeStyle(id, "color", "blue");
                G.addEdgeStyle(id, "label", "-");
            }

        } else if (root->right) {
            string id = root->data + "." + root->right->data;
            if (!G.edgeExists(id)) {
                G.addEdge(root->data, root->right->data);
                G.addEdgeStyle(id, "color", "red");
                G.addEdgeStyle(id, "label", "+");
            }
        } else {
            string toid = "NULL" + to_string(rand());
            string id = root->data + "." + toid;
            G.addEdge(root->data, toid);
            G.addNodeStyle(toid, "shape", "point");
            G.addNodeStyle(toid, "label", "NULL");
            G.addNodeStyle(root->data, "style", "filled");
            G.addNodeStyle(root->data, "fontcolor", "white");
            G.addEdgeStyle(id, "minlen", "1");
        }
        BuildGraphViz(root->right);
    }
}

template <typename T>
void Bst<T>::BuildGraphViz() {
    BuildGraphViz(root);
}

template <typename T>
void Bst<T>::PrintGraphViz() {
    cout << G.dumpGraph() << endl;
}

template <typename T>
bool Bst<T>::Find(Node<T> *root, T key) {
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

template <typename T>
bool Bst<T>::Find(T key) {

    return Find(root, key);
}

template <typename T>
void Bst<T>::Delete() {
    // needs implementing
    
}