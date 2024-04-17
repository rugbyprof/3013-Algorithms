#include <iostream>

using namespace std;

struct AVLNode {
    int value;
    AVLNode *left;
    AVLNode *right;
    int height;

    // Constructor to create a new node
    AVLNode(int val) : value(val), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
public:
    AVLNode *root;

    AVLTree() : root(nullptr) {}

    // Utility function to get the height of a node
    int height(AVLNode *N) {
        if (N == nullptr)
            return 0;
        return N->height;
    }

    // Utility function to get the balance factor of a node
    int getBalance(AVLNode *N) {
        if (N == nullptr)
            return 0;
        return height(N->left) - height(N->right);
    }

    // Right rotate utility
    AVLNode *rightRotate(AVLNode *y) {
        AVLNode *x = y->left;
        AVLNode *T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = std::max(height(y->left), height(y->right)) + 1;
        x->height = std::max(height(x->left), height(x->right)) + 1;

        // Return new root
        return x;
    }

    // Left rotate utility
    AVLNode *leftRotate(AVLNode *x) {
        AVLNode *y = x->right;
        AVLNode *T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = std::max(height(x->left), height(x->right)) + 1;
        y->height = std::max(height(y->left), height(y->right)) + 1;

        // Return new root
        return y;
    }

    // Recursive function to insert a value in the AVL tree and return the new root
    AVLNode *insert(AVLNode *node, int value) {
        // 1. Perform normal BST insertion
        if (node == nullptr)
            return new AVLNode(value);

        if (value < node->value)
            node->left = insert(node->left, value);
        else if (value > node->value)
            node->right = insert(node->right, value);
        else // Duplicate values are not allowed in BST
            return node;

        // 2. Update height of this ancestor node
        node->height = 1 + std::max(height(node->left), height(node->right));

        // 3. Get the balance factor to check whether this node became unbalanced
        int balance = getBalance(node);

        // 4. If unbalanced, then there are 4 cases

        // Left Left Case
        if (balance > 1 && value < node->left->value)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && value > node->right->value)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && value > node->left->value) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && value < node->right->value) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        // Return the unchanged node pointer
        return node;
    }

    // Function to insert a value in the AVL tree. It uses the insert utility function.
    void insert(int value) {
        root = insert(root, value);
    }

    // Utility function to do inorder traversal of the AVL tree
    void inorderTraversal(AVLNode *node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            std::cout << node->value << " ";
            inorderTraversal(node->right);
        }
    }

    // Function to call inorderTraversal
    void inorder() {
        inorderTraversal(root);
    }
};
