#pragma once
#include <iostream>
#include "graphviz.h"

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node();
    Node(int);
};

class Bst{
private:
    Node* root;
    GraphViz G;
    int size;
    void Print(Node*);
    void Insert(Node*& , int);
    bool Find(Node*,int);
    void BuildGraphViz(Node*);
public:
    Bst();
    Bst(int *);
    void Insert(int);
    void Print();
    bool Find(int);
    void Delete();
    void BuildGraphViz();
    void PrintGraphViz();
};