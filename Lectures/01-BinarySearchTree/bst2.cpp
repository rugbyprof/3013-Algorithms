#include <iostream>

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BST {
private:
    Node *root;

    Node *insertRecursive(Node *node, int data) {
        if (node == nullptr) {
            return new Node(data);
        }

        if (data < node->data) {
            node->left = insertRecursive(node->left, data);
        } else if (data > node->data) {
            node->right = insertRecursive(node->right, data);
        }

        return node;
    }

    Node *findMinNode(Node *node) {
        Node *current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node *deleteRecursive(Node *node, int data) {
        if (node == nullptr) {
            return node;
        }

        if (data < node->data) {
            node->left = deleteRecursive(node->left, data);
        } else if (data > node->data) {
            node->right = deleteRecursive(node->right, data);
        } else {
            if (node->left == nullptr) {
                Node *temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node *temp = node->left;
                delete node;
                return temp;
            }

            Node *temp = findMinNode(node->right);
            node->data = temp->data;
            node->right = deleteRecursive(node->right, temp->data);
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

    void insert(int data) {
        root = insertRecursive(root, data);
    }

    void remove(int data) {
        root = deleteRecursive(root, data);
    }

    void printInorder() {
        inorderPrint(root);
    }
};

int main() {
    BST bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.printInorder();
    return 0;
}