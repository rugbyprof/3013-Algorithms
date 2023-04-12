#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

class Node {
public:
    char symbol;
    int frequency;
    Node *left;
    Node *right;

    Node(char symbol, int frequency) {
        this->symbol = symbol;
        this->frequency = frequency;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class NodeCompare {
public:
    bool operator()(Node *node1, Node *node2) {
        return node1->frequency > node2->frequency;
    }
};

void build_encoding_table_helper(Node *, string, unordered_map<char, string> &);

// Function to read a file into a string
string read_file(string filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }
    string data((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    return data;
}

// Function to write a string to a file
void write_file(string filename, string data) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }
    file.write(data.c_str(), data.size());
    file.close();
}

// Function to compress data using Huffman coding
string compress(string input) {
    unordered_map<char, int> freq_table;
    priority_queue<Node *, vector<Node *>, NodeCompare> pq;
    for (char c : input) {
        freq_table[c]++;
    }
    for (auto it = freq_table.begin(); it != freq_table.end(); ++it) {
        Node *node = new Node(it->first, it->second);
        pq.push(node);
    }
    while (pq.size() > 1) {
        Node *node1 = pq.top();
        pq.pop();
        Node *node2 = pq.top();
        pq.pop();
        Node *combined_node = new Node('\0', node1->frequency + node2->frequency);
        combined_node->left = node1;
        combined_node->right = node2;
        pq.push(combined_node);
    }
    unordered_map<char, string> encoding_table;
    build_encoding_table_helper(pq.top(), "", encoding_table);
    string compressed_data = "";
    for (char c : input) {
        compressed_data += encoding_table[c];
    }
    return compressed_data;
}

// Function to decompress data using Huffman coding
string decompress(string input, Node *root) {
    string decompressed_data = "";
    Node *current_node = root;
    for (char bit : input) {
        if (bit == '0') {
            current_node = current_node->left;
        } else {
            current_node = current_node->right;
        }
        if (!current_node->left && !current_node->right) {
            decompressed_data += current_node->symbol;
            current_node = root;
        }
    }
    return decompressed_data;
}

unordered_map<char, int> build_frequency_table(string input) {
    unordered_map<char, int> freq_table;
    for (char c : input) {
        freq_table[c]++;
    }
    return freq_table;
}

priority_queue<Node *, vector<Node *>, NodeCompare> build_priority_queue(unordered_map<char, int> freq_table) {
    priority_queue<Node *, vector<Node *>, NodeCompare> pq;
    for (auto it = freq_table.begin(); it != freq_table.end(); ++it) {
        Node *node = new Node(it->first, it->second);
        pq.push(node);
    }
    return pq;
}

unordered_map<char, string> build_encoding_table(Node *root) {
    unordered_map<char, string> encoding_table;
    build_encoding_table_helper(root, "", encoding_table);
    return encoding_table;
}

void build_encoding_table_helper(Node *node, string code, unordered_map<char, string> &encoding_table) {
    if (!node) {
        return;
    }
    if (!node->left && !node->right) {
        encoding_table[node->symbol] = code;
    }
    build_encoding_table_helper(node->left, code + "0", encoding_table);
    build_encoding_table_helper(node->right, code + "1", encoding_table);
}

Node *build_huffman_tree(priority_queue<Node *, vector<Node *>, NodeCompare> pq) {
    while (pq.size() > 1) {
        Node *node1 = pq.top();
        pq.pop();
        Node *node2 = pq.top();
        pq.pop();
        Node *combined_node = new Node('\0', node1->frequency + node2->frequency);
        combined_node->left = node1;
        combined_node->right = node2;
        pq.push(combined_node);
    }
    return pq.top();
}

string compress(string input, unordered_map<char, string> encoding_table) {
    string output = "";
    for (char c : input) {
        output += encoding_table[c];
    }
    return output;
}

void write_compressed_file(string input_filename, string output_filename) {
    // Read input file
    ifstream input_file(input_filename);
    string input_data((istreambuf_iterator<char>(input_file)), istreambuf_iterator<char>());
    input_file.close();

    // Build frequency table, priority queue, and Huffman tree
    unordered_map<char, int> freq_table = build_frequency_table(input_data);
    priority_queue<Node *, vector<Node *>, NodeCompare> pq = build_priority_queue(freq_table);
    Node *root = build_huffman_tree(pq);
    unordered_map<char, string> encoding_table = build_encoding_table(root);

    // Compress input data
    string compressed_data = compress(input_data, encoding_table);

    // Write compressed data to binary file
    ofstream output_file(output_filename, ios::binary);
    int num_bits_written = 0;
    char current_byte = 0;
    for (char bit : compressed_data) {
        if (bit == '1') {
            current_byte |= (1 << (7 - num_bits_written));
        }
        num_bits_written++;
        if (num_bits_written == 8) {
            output_file.write(&current_byte, 1);
            num_bits_written = 0;
            current_byte = 0;
        }
    }
    if (num_bits_written > 0) {
        current_byte <<= (8 - num_bits_written);
        output_file.write(&current_byte, 1);
    }
    output_file.close();
}

// Main function
int main() {
    string input_filename = "war_and_peace.txt";
    string compressed_filename = "compressed.bin";
    string decompressed_filename = "decompressed.txt";

    // Read input file
    string input_data = read_file(input_filename);

    // Compress data
    string compressed_data = compress(input_data);

    // Write compressed data to binary file
    write_file(compressed_filename, compressed_data);

    // Read compressed data from binary file
    string compressed_data_read = read_file(compressed_filename);

    // Decompress data
    string decompressed_data = decompress(compressed_data_read, build_huffman_tree(build_priority_queue(build_frequency_table(input_data))));

    // Write decompressed data to text file
    write_file(decompressed_filename, decompressed_data);

    write_compressed_file("war_and_peace.txt", "war_and_peace.bin");

    return 0;
}
