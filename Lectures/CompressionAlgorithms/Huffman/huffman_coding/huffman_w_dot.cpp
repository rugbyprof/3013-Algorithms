#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int uuid() {
    static int id = 0;
    return id++;
}

// Node structure for Huffman tree
struct HuffmanNode {
    char ch;  // Character (for leaf nodes)
    int freq; // Frequency (or sum for internal nodes)
    int id;
    HuffmanNode *left;  // Left child
    HuffmanNode *right; // Right child

    // Constructor for leaf node
    HuffmanNode(char character, int frequency)
        : ch(character), freq(frequency), left(nullptr), right(nullptr), id(uuid()) {}

    // Constructor for internal node
    HuffmanNode(HuffmanNode *l, HuffmanNode *r)
        : ch('\0'), freq(l->freq + r->freq), left(l), right(r), id(uuid()) {}
};

// Custom comparator for the priority queue (min-heap)
struct Compare {
    bool operator()(HuffmanNode *a, HuffmanNode *b) {
        return a->freq > b->freq;
    }
};

// Recursive function to generate Huffman codes and store them in a map
void generateCodes(HuffmanNode *root, const string &code, unordered_map<char, string> &huffmanCodes) {
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
HuffmanNode *buildHuffmanTree(const unordered_map<char, int> &frequencies) {
    priority_queue<HuffmanNode *, vector<HuffmanNode *>, Compare> minHeap;

    // Create leaf nodes for each character and add to the heap
    for (auto pair : frequencies) {
        minHeap.push(new HuffmanNode(pair.first, pair.second));
    }

    // Iterate until the heap contains only one node (the root)
    while (minHeap.size() != 1) {
        // Remove two nodes with smallest frequency
        HuffmanNode *left = minHeap.top();
        minHeap.pop();
        HuffmanNode *right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with these two nodes as children
        HuffmanNode *internalNode = new HuffmanNode(left, right);

        // Add the new node to the heap
        minHeap.push(internalNode);
    }

    return minHeap.top();
}

// Recursive function to print DOT nodes and edges, including edge labels and binary code
void printDotNodes(HuffmanNode *node, const string &codeSoFar) {
    if (!node)
        return;

    // Use the pointer address as unique ID.
    cout << "    \"" << node->id << "\" [label=";
    if (!node->left && !node->right) {
        // Leaf node: show character, frequency, and its Huffman code.
        cout << '"' << "'" << node->ch << "'" << "\n"
             << codeSoFar;
    } else {
        // Internal node: show frequency only.
        cout << '"' << node->id;
    }
    cout << "\"];" << endl;

    if (node->left) {
        // Label left edge as "0"
        cout << "    \"" << node->id << "\" -> \"" << node->left->id << "\" [label=\"0\"];" << endl;
        printDotNodes(node->left, codeSoFar + "0");
    }
    if (node->right) {
        // Label right edge as "1"
        cout << "    \"" << node->id << "\" -> \"" << node->right->id << "\" [label=\"1\"];" << endl;
        printDotNodes(node->right, codeSoFar + "1");
    }
}

void printHuffmanTreeDot(HuffmanNode *root) {
    cout << "digraph HuffmanTree {" << endl;
    cout << "    node [shape=ellipse, fontname=\"Arial\"];" << endl;
    printDotNodes(root, "");
    cout << "}" << endl;
}

int main() {
    // Example input: a string from which to build frequency table
    string text = "this is an example for huffman encoding";

    ifstream fin;
    fin.open("data.txt"); // open a file
    if (!fin.is_open()) {
        cout << "Error in opening the file" << endl;
        return 0;
    }

    text = "";

    while (!fin.eof()) {
        string line;
        getline(fin, line);
        text += line;
    }
    // Build frequency table
    unordered_map<char, int> frequencies;
    for (char ch : text) {
        frequencies[ch]++;
    }

    // Build Huffman Tree from frequency table
    HuffmanNode *root = buildHuffmanTree(frequencies);

    // Generate Huffman codes from the tree
    unordered_map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    // Print the Huffman codes for each character
    cout << "Huffman Codes:" << endl;
    for (auto pair : huffmanCodes) {
        cout << pair.first << " : " << pair.second << endl;
    }

    // Print DOT code for the Huffman tree with edge labels and binary codes at leaves
    cout << "\nDOT Code for the Huffman Tree:" << endl;
    printHuffmanTreeDot(root);

    // (Optional) Clean up memory by deleting nodes (not shown here for brevity)

    return 0;
}