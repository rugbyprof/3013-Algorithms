## Huffman Coding : Example with input file

#### Code Files

- [Heap.hpp](./huffman_coding/Heap.hpp) Heap Implementation
- [Huffman.hpp](huffman_coding/Huffman.hpp) Huffman Tree Implementation
- [Node.hpp](huffman_coding/Node.hpp) Node for Heap
- [main.cpp](huffman_coding/main.cpp) driver code

#### Input Files

- [data.txt](huffman_coding/data.txt) Big input file
- [data2.txt](huffman_coding/data2.txt) Smaller test input file

# Huffman Coding Walkthrough and Explanation (C++)

Huffman Coding is a widely used algorithm for lossless data compression. It assigns variable-length codes to input characters, with shorter codes for more frequent characters. This document provides a walkthrough of the Huffman Coding process and a C++ code example that builds a Huffman tree and prints out the generated codes.

---

## Overview

1. **Frequency Calculation:**

   - Determine the frequency of each character in the input.

2. **Building the Huffman Tree:**

   - Create a leaf node for each character and add it to a priority queue (min-heap) based on frequency.
   - While there is more than one node in the queue, remove the two nodes with the smallest frequencies, create a new internal node with these nodes as children (and frequency equal to the sum of their frequencies), and add the new node back to the queue.
   - The remaining node is the root of the Huffman tree.

3. **Generating Codes:**
   - Traverse the tree from the root to each leaf. Assign a `0` for left branches and a `1` for right branches. The path from the root to a leaf forms the Huffman code for that character.

---

## C++ Code Example

Below is an example implementation in C++:

```cpp
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

// Node structure for Huffman tree
struct HuffmanNode {
    char ch;                // Character (for leaf nodes)
    int freq;               // Frequency of the character or sum of frequencies for internal nodes
    HuffmanNode* left;      // Left child
    HuffmanNode* right;     // Right child

    // Constructor for leaf node
    HuffmanNode(char character, int frequency)
        : ch(character), freq(frequency), left(nullptr), right(nullptr) {}

    // Constructor for internal node
    HuffmanNode(HuffmanNode* l, HuffmanNode* r)
        : ch('\0'), freq(l->freq + r->freq), left(l), right(r) {}
};

// Custom comparator for the priority queue (min-heap)
struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->freq > b->freq;
    }
};

// Custom comparator for the priority queue (min-heap)
struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->freq > b->freq;
    }
};


// Recursive function to generate Huffman codes and store them in a map
void generateCodes(HuffmanNode* root, const string &code, unordered_map<char, string> &huffmanCodes) {
    if (!root)
        return;

    // If this is a leaf node, assign the code to the character
    if (!root->left && !root->right) {
        huffmanCodes[root->ch] = code;
    }

    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

// Function to build Huffman Tree and return its root
HuffmanNode* buildHuffmanTree(const unordered_map<char, int> &frequencies) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> minHeap;

    // Create leaf nodes for each character and add to the heap
    for (auto pair : frequencies) {
        minHeap.push(new HuffmanNode(pair.first, pair.second));
    }

    // Iterate until the heap contains only one node (the root)
    while (minHeap.size() != 1) {
        // Remove two nodes with smallest frequency
        HuffmanNode* left = minHeap.top(); minHeap.pop();
        HuffmanNode* right = minHeap.top(); minHeap.pop();

        // Create a new internal node with these two nodes as children
        HuffmanNode* internalNode = new HuffmanNode(left, right);

        // Add the new node to the heap
        minHeap.push(internalNode);
    }

    return minHeap.top();
}

// Function to print DOT code for the Huffman tree
void printDotNodes(HuffmanNode* node) {
    if (!node) return;

    // Use the pointer address as unique ID.
    cout << "    \"" << node << "\" [label=\"";
    if (!node->left && !node->right) {
        // Leaf node: show character and frequency.
        cout << node->ch << " (" << node->freq << ")";
    } else {
        // Internal node: show frequency.
        cout << node->freq;
    }
    cout << "\"];" << endl;

    if (node->left) {
        cout << "    \"" << node << "\" -> \"" << node->left << "\";" << endl;
        printDotNodes(node->left);
    }
    if (node->right) {
        cout << "    \"" << node << "\" -> \"" << node->right << "\";" << endl;
        printDotNodes(node->right);
    }
}

void printHuffmanTreeDot(HuffmanNode* root) {
    cout << "digraph HuffmanTree {" << endl;
    cout << "    node [shape=ellipse, fontname=\"Arial\"];" << endl;
    printDotNodes(root);
    cout << "}" << endl;
}


int main() {
    // Example input: a string from which to build frequency table
    string text = "this is an example for huffman encoding";

    // Build frequency table
    unordered_map<char, int> frequencies;
    for (char ch : text) {
        // Consider spaces as well, or skip if desired
        frequencies[ch]++;
    }

    // Build Huffman Tree from frequency table
    HuffmanNode* root = buildHuffmanTree(frequencies);

    // Generate Huffman codes from the tree
    unordered_map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    // Print the Huffman codes for each character
    cout << "Huffman Codes:" << endl;
    for (auto pair : huffmanCodes) {
        cout << pair.first << " : " << pair.second << endl;
    }

    // Print DOT code for the Huffman tree
    cout << "\nDOT Code for the Huffman Tree:" << endl;
    printHuffmanTreeDot(root);

    // (Optional) Clean up memory by deleting nodes (not shown here for brevity)

    return 0;
}
```

## Explanation

- Data Structures:
- HuffmanNode represents a node in the Huffman tree.
- A priority queue (min-heap) is used to build the tree by always combining the two nodes with the smallest frequencies.
- Tree Building:
- The tree is built by repeatedly combining the two least frequent nodes until one node remains (the root).
- Code Generation:
- The generateCodes() function recursively traverses the tree, assigning 0 for left branches and 1 for right branches.
- The resulting codes are stored in an unordered_map<char, string>.
- Output:
- The Huffman codes for each character in the input text are printed.

Final Thoughts

This implementation of Huffman Coding in C++ demonstrates how to:

- Build a frequency table.
- Construct a Huffman tree.
- Generate variable-length binary codes based on character frequency.
