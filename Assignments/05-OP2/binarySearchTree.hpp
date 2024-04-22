#pragma once
#include <iostream>
#include <sstream>

using namespace std;


struct Node {
    int key;
    Node *left;
    Node *right;
    Node(int key) : key(key), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {

protected:
    Node *root;


    void toDotFormat(Node *node, std::stringstream &stream) const {
        if (!node) return;

        // Output the node itself
        stream << "    " << node->key << " [label=\"" << node->key << "\"];\n";

        // Output the connection to the left child if it exists
        if (node->left) {
            stream << "    " << node->key << " -- " << node->left->key << ";\n";
            toDotFormat(node->left, stream);
        }

        // Output the connection to the right child if it exists
        if (node->right) {
            stream << "    " << node->key << " -- " << node->right->key << ";\n";
            toDotFormat(node->right, stream);
        }
    }

    int treeHeight(Node* node){
        if(!node){
            return 0;
        }
        return 1 + max(treeHeight(node->left), treeHeight(node->right));
        
    }

    // Function to insert a new key into the BST
    virtual Node *insert(Node *&node, int key) {
        if (!node) {
            node = new Node(key);
        } else if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        }
        return node;
    }

    // Function to do inorder traversal of BST
    void inorder(Node *node) {
        if (node != nullptr) {
            inorder(node->left);
            std::cout << node->key << " ";
            inorder(node->right);
        }
    }

    // Function to search a given key in a given BST
    bool search(Node *node, int key) {
        // Base Cases: root is null or key is present at root
        if (node == nullptr)
            return false;
        else if (node->key == key)
            return true;

        // Key is greater than root's key
        if (node->key < key)
            return search(node->right, key);

        // Key is smaller than root's key
        return search(node->left, key);
    }

public:
    BinarySearchTree() : root(nullptr) {}
    virtual void insert(int key) {
        insert(root, key);
    }
    void inorder() {
        inorder(root);
    }

    bool search(int key) {
        return search(root, key);
    }

    int treeHeight(){
        return treeHeight(root);
    }

    std::string toDotFormat() const {
        std::stringstream stream;
        stream << "graph BST {\n";
        stream << "    node [fontname=\"Helvetica\"];\n";

        if (!root) {
            stream << "\n";
        } else {
            toDotFormat(root, stream);
        }

        stream << "}\n";
        return stream.str();
    }
};
