#include <iostream>

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

class BST {
private:
    Node *root;
    void addHelper(Node *node, int data) {
        if (data < node->data) {
            if (node->left == nullptr) {
                node->left = new Node(data);
            } else {
                addHelper(node->left, data);
            }
        } else {
            if (node->right == nullptr) {
                node->right = new Node(data);
            } else {
                addHelper(node->right, data);
            }
        }
    }
    bool searchHelper(Node *node, int data) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == data) {
            return true;
        }
        if (data < node->data) {
            return searchHelper(node->left, data);
        } else {
            return searchHelper(node->right, data);
        }
    }
    Node *removeHelper(Node *node, int data) {
        if (node == nullptr) {
            return nullptr;
        }
        if (data < node->data) {
            node->left = removeHelper(node->left, data);
        } else if (data > node->data) {
            node->right = removeHelper(node->right, data);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            } else if (node->left == nullptr) {
                Node *temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node *temp = node->left;
                delete node;
                return temp;
            } else {
                Node *minNode = findMinNode(node->right);
                node->data = minNode->data;
                node->right = removeHelper(node->right, minNode->data);
            }
        }
        return node;
    }
    Node *findMinNode(Node *node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    void inorderPrint(Node *node) {
        if (node == nullptr) {
            return;
        }

        inorderPrint(node->left);
        std::cout << node->data << " ";
        inorderPrint(node->right);
    }

public:
    BST() {
        root = nullptr;
    }
    void add(int data) {
        if (root == nullptr) {
            root = new Node(data);
        } else {
            addHelper(root, data);
        }
    }
    bool search(int data) {
        return searchHelper(root, data);
    }
    void remove(int data) {
        root = removeHelper(root, data);
    }
    void printInorder() {
        inorderPrint(root);
    }
};

int main() {

    BST bst;
    bst.add(5);
    bst.add(3);
    bst.add(7);
    bst.printInorder();
    return 0;
}