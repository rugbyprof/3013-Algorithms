## AVL Tree's

This is just a textual summary of AVL tree attributes. A great resource that includes images can be found at the [programiz website](https://www.programiz.com/dsa/avl-tree).

### AVL Tree Overview

An **AVL tree** is a self-balancing binary search tree where the difference in heights between the left and right subtrees (`balance factor`) of any node is no more than one. This ensures that the tree remains approximately balanced, thereby guaranteeing that operations like `insertion`, `deletion`, and `lookup` can be performed in `O(log n)` time in the worst case, where n is the number of nodes in the tree (data set size). ***The AVL tree is named after its inventors, Adelson-Velsky and Landis***.

AVL trees consist of nodes that are just like a BST:

```c++
struct Node{
    // Some data element (int, string, struct of some kind, etc.)
    Node* left;
    Node* right;
};
```

But we add another data member that represents the nodes "balance factor".

```c++
struct Node{
    // Some data element (int, string, struct of some kind, etc.)
    Node* left;
    Node* right;
    int balance_factor;
};
```

The **Balance Factor**: for any given node, it is the `height` of the `left subtree` minus the `height` of the `right subtree.` AVL trees maintain this factor to be ***[-1, 0, 1]***. **Height** is defined as the number of edges on a downward path between some node and the furthest leaf. So, the balance factor of node N, is the height of N's left child minus the height of N's right child. When the `balance factor` goes below ***-1*** or above ***1***, we must perform some operations to get it back to an acceptable value. The operations change a nodes position in the tree, and they are called `rotations`.

## Rotations: 

- Rotations are the key operations that allow AVL trees to maintain balance. There are four types of rotations:
  - **Right Rotation (Single Left Rotation)**: Applied when a left-left case imbalance is detected.
  - **Left Rotation (Single Right Rotation)**: Applied when a right-right case imbalance is detected.
  - **Left-Right Rotation (Double Rotation)**: Applied when a left-right case imbalance is detected. It's a combination of a left rotation on the left child, followed by a right rotation on the node.
  - **Right-Left Rotation (Double Rotation)**: Applied when a right-left case imbalance is detected. It's a combination of a right rotation on the right child, followed by a left rotation on the node.

### Single Rotations

#### Right Rotation (Single Left Rotation)

**Use Case**: Applied when a left-left case imbalance occurs, i.e., inserting into the left subtree of the left child.

**Algorithm**:
1. **Identify Rotation Point**: Let `Y` be the node that has become unbalanced due to insertion in its left subtree's left side.
2. **Rotate**: Set `X` as `Y`'s left child. Make `X`'s right child the new left child of `Y`. Now, make `Y` the right child of `X`.
3. **Update Heights**: Recalculate the heights of the original nodes `X` and `Y`.

**Pseudo Code**:
```plaintext
RightRotation(Y):
    X = Y.left
    Y.left = X.right
    X.right = Y
    UpdateHeights(Y)
    UpdateHeights(X)
    return X  // New root of this subtree
```

#### Left Rotation (Single Right Rotation)

**Use Case**: Applied when a right-right case imbalance occurs, i.e., inserting into the right subtree of the right child.

**Algorithm**:
1. **Identify Rotation Point**: Let `X` be the node that has become unbalanced due to insertion in its right subtree's right side.
2. **Rotate**: Set `Y` as `X`'s right child. Make `Y`'s left child the new right child of `X`. Now, make `X` the left child of `Y`.
3. **Update Heights**: Recalculate the heights of the original nodes `X` and `Y`.

**Pseudo Code**:
```plaintext
LeftRotation(X):
    Y = X.right
    X.right = Y.left
    Y.left = X
    UpdateHeights(X)
    UpdateHeights(Y)
    return Y  // New root of this subtree
```

### Double Rotations

#### Left-Right Rotation

**Use Case**: Applied when a left-right case imbalance occurs, i.e., inserting into the left subtree's right child.

**Algorithm**:
1. **First Rotation (Left Rotation on Child)**: Perform a left rotation on the left child of the unbalanced node.
2. **Second Rotation (Right Rotation on Root)**: Perform a right rotation on the unbalanced node.

**Pseudo Code**:
```plaintext
LeftRightRotation(Z):
    Z.left = LeftRotation(Z.left)
    return RightRotation(Z)
```

#### Right-Left Rotation

**Use Case**: Applied when a right-left case imbalance occurs, i.e., inserting into the right subtree's left child.

**Algorithm**:
1. **First Rotation (Right Rotation on Child)**: Perform a right rotation on the right child of the unbalanced node.
2. **Second Rotation (Left Rotation on Root)**: Perform a left rotation on the unbalanced node.

**Pseudo Code**:
```plaintext
RightLeftRotation(Z):
    Z.right = RightRotation(Z.right)
    return LeftRotation(Z)
```

### Key Notes

- Rotations adjust the structure of the tree but do not alter the in-order sequence of the elements, preserving the BST property.
- Height updates are essential after rotations to maintain correct height information for future balance checks.
- These rotations ensure that the tree remains balanced, preserving the AVL tree's O(log n) operation time complexities.

Rotations are fundamental to how AVL trees self-balance and are instrumental in ensuring that operations on the tree remain efficient regardless of the sequence of insertions and deletions.
 

### Why AVL Trees?

AVL trees are designed to maintain balance to ensure that the tree's height is kept in check, preventing the skewed scenarios that can occur in an unbalanced BST. By maintaining a height-balanced tree, AVL trees ensure that operations remain efficient, avoiding the degradation to linear time complexity that can occur with unbalanced trees.

### Operations:

AVL tree operations are the same as a Binary Search Tree's, with the addition of calculating `balance factor` for each node.

- **Insertion**: When a new node is inserted, the tree is traversed down from the root to find the correct spot for insertion. After insertion, the tree is retraced back, and the balance factor of each node is updated. If any node becomes unbalanced, rotations are applied to restore balance.
- **Deletion**: Similar to insertion, after a node is deleted, the tree is retraced back from the node to the root, balance factors are updated, and rotations are applied as necessary to maintain the AVL balance property.
- **Lookup**: Lookup in an AVL tree follows the same principles as in a BST, benefiting from the balanced nature of the tree to provide efficient search times.


### Use Cases:

Remember that if the need for fast lookups and searches is not necessary, then adding the overhead of maintaining a balanced tree via rotations may not be worth the cost. However, assuming speed is critical:

- When **frequent insertions** and **frequent deletions** occur, maintaining a balanced tree ensures fast lookup times.
- Used as database "indexes" to ensure database queries are fast as possible. 

In summary, AVL trees offer a robust solution for maintaining dynamically balanced binary search trees, ensuring efficient performance across a variety of operations, which is particularly valuable in performance-sensitive applications.

-----


To identify whether a subtree in an AVL tree is left-heavy or right-heavy, you can define a simple method in C++ that checks the balance factor of a given node. The balance factor is the height of the left subtree minus the height of the right subtree. Here’s how you can implement it:

### Preliminaries

First, ensure you have a basic structure for a node in your AVL tree. Each node should store its value, pointers to its left and right children, and its height.

```cpp
struct AVLNode {
    int value;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int val) : value(val), left(nullptr), right(nullptr), height(1) {}
};
```

### Height Utility Function

You'll need a utility function to safely get the height of a node (considering `nullptr` as a height of `0`).

```cpp
int getHeight(AVLNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}
```

### Balance Factor and Identification Method

Now, you can write a method to calculate the balance factor and identify whether a subtree is left-heavy, right-heavy, or balanced.

```cpp
int getBalanceFactor(AVLNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

void identifySubtreeType(AVLNode* node) {
    if (node == nullptr) {
        std::cout << "The node is nullptr." << std::endl;
        return;
    }
    
    int balanceFactor = getBalanceFactor(node);
    if (balanceFactor > 1) {
        std::cout << "The subtree rooted at node with value " << node->value << " is left-heavy." << std::endl;
    } else if (balanceFactor < -1) {
        std::cout << "The subtree rooted at node with value " << node->value << " is right-heavy." << std::endl;
    } else {
        std::cout << "The subtree rooted at node with value " << node->value << " is balanced." << std::endl;
    }
}
```

### Example Usage

To use this method, you'll construct an AVL tree (or a portion of it) and then call `identifySubtreeType` on the node you wish to check. Here’s a simple example:

```cpp
int main() {
    AVLNode* root = new AVLNode(10);
    root->left = new AVLNode(5);
    root->right = new AVLNode(15);
    
    // Assuming the tree is manually balanced and heights are correctly set for this example.
    root->left->left = new AVLNode(3); // Adding to make the subtree left-heavy
    
    identifySubtreeType(root); // Should identify the type based on the current structure

    return 0;
}
```

This method provides a straightforward way to check the balance of subtrees in an AVL tree, which is crucial for maintaining the overall balance of the tree during insertions and deletions. Remember, in a fully implemented AVL tree, you would also need to adjust the heights of the nodes and perform rotations to maintain the AVL balance property after any modifications.