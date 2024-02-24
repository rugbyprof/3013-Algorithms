#include <iostream>

using namespace std;

class Node {
public:
    int key;
    Node *left;
    Node *right;

    Node(int key) : key(key), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    Node *root;

    BinarySearchTree() : root(nullptr) {}

    // Function to insert a new key into the BST
    Node *insert(Node *node, int key) {
        // If the tree is empty, return a new node
        if (node == nullptr)
            return new Node(key);

        // Otherwise, recur down the tree
        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        }

        // Return the (unchanged) node pointer
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
    Node *search(Node *node, int key) {
        // Base Cases: root is null or key is present at root
        if (node == nullptr || node->key == key)
            return node;

        // Key is greater than root's key
        if (node->key < key)
            return search(node->right, key);

        // Key is smaller than root's key
        return search(node->left, key);
    }
};

// int main() {
//     BinarySearchTree bst;

//     // Insert values into BST
//     bst.root = bst.insert(bst.root, 50);
//     bst.root = bst.insert(bst.root, 30);
//     bst.root = bst.insert(bst.root, 20);
//     bst.root = bst.insert(bst.root, 40);
//     bst.root = bst.insert(bst.root, 70);
//     bst.root = bst.insert(bst.root, 60);
//     bst.root = bst.insert(bst.root, 80);

//     // Print in-order traversal of the BST
//     std::cout << "Inorder traversal of the BST: ";
//     bst.inorder(bst.root);
//     std::cout << std::endl;

//     // Search for a key in the BST
//     int key = 40;
//     Node* result = bst.search(bst.root, key);
//     if (result != nullptr) {
//         std::cout << "Element " << key << " found in the BST." << std::endl;
//     } else {
//         std::cout << "Element " << key << " not found in the BST." << std::endl;
//     }

//     return 0;
// }
