#include "graphviz.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    string position;

    Node *parent;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = left = parent = nullptr;
        position = "";
    }
};

struct TreeStats{
    int height;
    int lWidth;
    int rWidth;
    TreeStats(){
        height=lWidth=rWidth=0;
    }
    TreeStats(const TreeStats &s){
        height = s.height;
        lWidth = s.lWidth;
        rWidth = s.rWidth;
    }
    friend ostream& operator<<(ostream &os, TreeStats &s){
        return os << "[ lw:"<<s.lWidth<<" rw: "<<s.rWidth<<" h: "<<s.height<<" ]";
    }
};

int letterCount(string s, char l){
    int count = 0;
    for(int i=0;i<s.size();i++){
        // cout<<s[i]<<" "<<l<<endl;
        if(s[i] == l){
            count++;
        }
    }
    cout<<"count: "<<count<<endl;
    return count;
}



class Bst {
    Node *root;
    GraphViz G;

    void Insert(Node *&root, Node *newNode, Node *Parent) {
        if (!root) {
            root = newNode;
            newNode->parent = Parent;
        } else {
            if (newNode->data < root->data) {
                newNode->position += "L";
                Insert(root->left, newNode, root);
            } else {
                newNode->position += "R";
                Insert(root->right, newNode, root);
            }
        }
    }
    void Print(Node *root) {
        if (!root) {
            return;
        } else {
            Print(root->left);
            cout << root->data << " "<<root->position<<endl;
            Print(root->right);
        }
    }

    bool Find(Node *root, int key) {
        if (!root) {
            return false;
        } else {
            if (root->data == key) {
                return true;
            } else {

                bool left = Find(root->left, key);
                bool right = Find(root->right, key);
                if (left || right) {
                    return true;
                } else {
                    return false;
                }
            }
        }
    }

    int Height(Node *root) {
        if (!root) {
            return 0;
        } else {
            int leftH = Height(root->left);
            int rightH = Height(root->right);
            if (leftH > rightH) {
                return 1 + leftH;
            } else {
                return 1 + rightH;
            }
        }
    }

    void treeSize(Node *root,int &lcount,int &rcount){
        if (!root) {
            return;
        }
        int r,l;
        treeSize(root->left,lcount,rcount);
        r = letterCount(root->position,'R');
        if(r>rcount){
            rcount = r;
        }
        l = letterCount(root->position,'L');
        if(l>lcount){
            lcount = l;
        }
        treeSize(root->right,lcount,rcount);
    }

    void Traverse(Node *root) {
        if (!root) {
            return;
        }
        Traverse(root->left);
        cout << "[" << root->data << " ";
        if (root->parent)
            cout << root->parent->data;

        cout << "]";
        Traverse(root->right);
    }

    void addEdges(Node *root) {
        string from, to, id;
        if (!root) {
            return;
        }
        from = to_string(root->data);
        if (root->left) {
            to = to_string(root->left->data);
            G.addEdge(from, to);
        } else {
            id = from + "7";
            G.addEdge(from, id);

            //[label= "", shape=none,height=.0,width=.0]
            G.addNodeStyle(id, "label", "\"\"");
            G.addNodeStyle(id, "shape", "none");
            G.addNodeStyle(id, "height", ".0");
            G.addNodeStyle(id, "width", ".0");
            G.addNodeStyle(id, "style", "invis");
        }
        addEdges(root->left);
        from = to_string(root->data);
        if (root->right) {
            to = to_string(root->right->data);
            G.addEdge(from, to);
        } else {
            id = from + "5";
            G.addEdge(from, id);
            //[label= "", shape=none,height=.0,width=.0]
            G.addNodeStyle(id, "label", "\"\"");
            G.addNodeStyle(id, "shape", "none");
            G.addNodeStyle(id, "height", ".0");
            G.addNodeStyle(id, "width", ".0");
            G.addNodeStyle(id, "style", "invis");
        }
        addEdges(root->right);
    }

public:
    Bst() {
        root = nullptr;
        G.setEdgeColor("blue");
    }

    TreeStats treeSize(){
        TreeStats w;
        treeSize(root,w.lWidth,w.rWidth);
        w.height = Height(root);
        return w;
    }

    void Insert(int x) {
        G.addNode(to_string(x));
        if (!root) {
            root = new Node(x);

        } else {
            Insert(root, new Node(x), root);
        }
    }

    bool Find(int key) {
        return Find(root, key);
    }

    void Print() {
        Print(root);
    }

    void Traverse() {
        Traverse(root);
    }

    int Height() {
        return Height(root);
    }

    void dumpGraph() {
        addEdges(root);
        cout << G << endl;
    }
};
