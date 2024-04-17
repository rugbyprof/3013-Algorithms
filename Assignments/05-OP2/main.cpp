#include "AVLTree.hpp"
#include "BST.hpp"

int main() {
    BinarySearchTree bst;

    // Insert values into BST
    bst.root = bst.insert(bst.root, 50);
    bst.root = bst.insert(bst.root, 30);
    bst.root = bst.insert(bst.root, 20);
    bst.root = bst.insert(bst.root, 40);
    bst.root = bst.insert(bst.root, 70);
    bst.root = bst.insert(bst.root, 60);
    bst.root = bst.insert(bst.root, 80);

    // Print in-order traversal of the BST
    std::cout << "Inorder traversal of the BST: ";
    bst.inorder(bst.root);
    std::cout << std::endl;

    // Search for a key in the BST
    int key = 40;
    Node *result = bst.search(bst.root, key);
    if (result != nullptr) {
        std::cout << "Element " << key << " found in the BST." << std::endl;
    } else {
        std::cout << "Element " << key << " not found in the BST." << std::endl;
    }

    return 0;
}
