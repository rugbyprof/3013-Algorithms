/*
DOES NOT WORK --- SEGMENTATION FAULT
This implementation uses a `FibNode` class to represent nodes in the heap, which contain a key value, pointers to their parent and children, and pointers to their neighbors in the root list. The `FibonacciHeap` class maintains a pointer to the minimum node in the heap and a count of the number of nodes.

The `insert` method inserts a new node into the heap by adding it to the root list and updating the minimum node if necessary. The `get_min` method simply returns a pointer to the minimum node.

The `extract_min` method removes the minimum node from the root list and adds its children to the root list. It then consolidates the root list to ensure that there is at most one node of each degree. The `decrease_key` method decreases the key of a node and performs a cascading cut if necessary to maintain the heap property.

The implementation uses various helper methods to manipulate the root list and perform the consolidation and cascading cut operations.

Visually, a Fibonacci heap might look something like this:

```markdown
             5
           /   \
         15     10
        /  \      \
      25    20    35
```
In this example, the minimum node is 5, and it has two children, 15 and 10. 15 has two children, 25 and 20, and 10 has one child, 35. Note that unlike in a binary heap, nodes in a Fibonacci heap can have any number of children.

Overall, a Fibonacci heap is a powerful data structure for performing priority queue operations with good time complexity. However, its implementation can be complex and may require some understanding of graph theory and advanced data structures.
*/

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class FibNode {
public:
    int key;
    FibNode *parent;
    FibNode *child;
    FibNode *left;
    FibNode *right;
    int degree;
    bool marked;

    FibNode(int k) {
        key = k;
        parent = child = left = right = nullptr;
        degree = 0;
        marked = false;
    }
};

class FibonacciHeap {
public:
    FibonacciHeap() {
        min_node_ = nullptr;
        num_nodes_ = 0;
    }

    // Insert a new node with the given key into the heap
    FibNode *insert(int key) {
        FibNode *node = new FibNode(key);
        if (min_node_ == nullptr) {
            min_node_ = node;
        } else {
            insert_node_(node, min_node_);
            if (node->key < min_node_->key) {
                min_node_ = node;
            }
        }
        num_nodes_++;
        return node;
    }

    // Get the minimum node in the heap
    FibNode *get_min() const {
        return min_node_;
    }

    // Extract the minimum node from the heap and return it
    FibNode *extract_min() {
        FibNode *min_node = min_node_;
        if (min_node != nullptr) {
            // Remove the minimum node from the root list
            remove_node_(min_node);

            // Add the minimum node's children to the root list
            FibNode *child = min_node->child;
            while (child != nullptr) {
                FibNode *next_child = child->right;
                insert_node_(child, min_node_);
                child->parent = nullptr;
                child = next_child;
            }

            // Consolidate the root list to ensure that there is at most one node of each degree
            consolidate_();

            num_nodes_--;
            min_node_ = min_node_->right;
        }
        return min_node;
    }

    // Decrease the key of a node to a new value
    void decrease_key(FibNode *node, int new_key) {
        if (new_key > node->key) {
            // New key is greater than current key, so we can't decrease it
            return;
        }

        node->key = new_key;
        FibNode *parent = node->parent;
        if (parent != nullptr && node->key < parent->key) {
            // Node violates heap property, so cut it from its parent
            cut_node_(node, parent);
            cascading_cut_(parent);
        }

        if (node->key < min_node_->key) {
            // Update min node if necessary
            min_node_ = node;
        }
    }

    void print() {
        if (min_node_ == nullptr) {
            std::cout << "Heap is empty" << std::endl;
            return;
        }

        std::cout << "Heap contents: ";
        std::vector<FibNode *> nodes;
        nodes.push_back(min_node_);
        FibNode *node = min_node_->right;
        while (node != min_node_) {
            nodes.push_back(node);
            node = node->right;
        }

        for (FibNode *node : nodes) {
            std::cout << node->key << " ";
        }
        std::cout << std::endl;
    }

private:
    FibNode *min_node_;
    int num_nodes_;

    // Insert a node into the root list
    void insert_node_(FibNode *node, FibNode *root) {
        node->left = root->left;
        node->right = root;
        root->left->right = node;
        root->left = node;
    }

    // Remove a node from the root list
    void remove_node_(FibNode *node) {
        node->left->right = node->right;
        node->right->left = node->left;
    }

    // Link two trees of the same degree
    FibNode *link_(FibNode *node1, FibNode *node2) {
        if (node1->key > node2->key) {
            std::swap(node1, node2);
        }

        remove_node_(node2);
        node2->parent = node1;
        node2->right = node2->left = node2;
        insert_node_(node2, node1->child);
        node1->degree++;
        node2->marked = false;
        return node1;
    }

    // Consolidate the root list to ensure that there is at most one node of each degree
    void consolidate_() {
        int max_degree = log2(num_nodes_) + 1;
        std::vector<FibNode *> degree_table(max_degree, nullptr);

        FibNode *node = min_node_;
        FibNode *end_node = min_node_;
        do {
            FibNode *next_node = node->right;
            int degree = node->degree;
            while (degree_table[degree] != nullptr) {
                FibNode *other_node = degree_table[degree];
                if (node->key > other_node->key) {
                    std::swap(node, other_node);
                }
                link_(node, other_node);
                degree_table[degree] = nullptr;
                degree++;
            }
            degree_table[degree] = node;
            node = next_node;
        } while (node != end_node);

        min_node_ = nullptr;
        for (FibNode *root : degree_table) {
            if (root != nullptr) {
                if (min_node_ == nullptr) {
                    min_node_ = root;
                } else {
                    insert_node_(root, min_node_);
                    if (root->key < min_node_->key) {
                        min_node_ = root;
                    }
                }
            }
        }
    }

    // Cut a node from its parent and add it to the root list
    void cut_node_(FibNode *node, FibNode *parent) {
        remove_node_(node);
        parent->degree--;
        insert_node_(node, min_node_);
        node->parent = nullptr;
        node->marked = false;
    }

    // Perform cascading cuts on a node's ancestors until a non-marked node is reached
    void cascading_cut_(FibNode *node) {
        FibNode *parent = node->parent;
        if (parent != nullptr) {
            if (!node->marked) {
                node->marked = true;
            } else {
                cut_node_(node, parent);
                cascading_cut_(parent);
            }
        }
    }
};

int main() {
    FibonacciHeap F;

    for (int i = 0; i < 30; i++) {
        F.insert(rand() % 100);
    }

    F.print();

    return 0;
}