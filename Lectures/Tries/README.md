## Trie - Not A Tree (but it is...)

#### Due: N/A

Thanks Chat Gpt (with many fixes):

### First Explanation:

A `Trie` data structure, also known as a `prefix tree`, is a tree-like data structure used for efficient string matching and retrieval operations. The Trie structure represents a set of strings as a tree in which each node represents a prefix or complete string, with the root of the tree representing the empty string.

A `Trie` is typically used in situations where we need to store a large set of strings and perform operations such as searching for a string or finding all strings that share a common prefix. Tries can be used in various applications such as `spelling correction`, `autocomplete`, and `DNA sequence analysis`.

### Second Explanation:

A `Trie` is a tree-like data structure used for storing and searching strings efficiently. Each node in the Trie represents a prefix or complete string, with the root representing the empty string. Each edge leaving a node represents a character, and the path from the root to a leaf represents a complete string stored in the Trie.

A `Trie` can be used for a variety of applications, such as:

1. **Autocomplete**: A Trie can be used to efficiently search for all words in a dictionary that start with a given prefix. This is often used in search engines and text editors to provide autocomplete suggestions to users.
2. **Spell checking**: A Trie can be used to check if a given word is spelled correctly. This is often used in word processors and other applications that require spelling and grammar checking.
3. **IP routing**: A Trie can be used to efficiently route packets in a computer network. Each node in the Trie represents a portion of an IP address, and the path from the root to a leaf represents the route to a particular network.

Both coding examples below serve nearly the same purpose, load some words then search using a partial string match. I have plenty of data for you to do much more even in this directory! Look [HERE](dictionary.txt)

The Chat GPT code looks skimpy so if you want a full born implementation, go [HERE](https://replit.com/@rugbyprof/3013TrieSpring2021-1) and look at this code!!

```cpp

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Trie {
private:
    unordered_map<char, Trie*> children;
    bool is_end;

public:
    Trie() {
        is_end = false;
    }

    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new Trie();
            }
            node = node->children[c];
        }
        node->is_end = true;
    }

    vector<string> search(string prefix) {
        Trie* node = this;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return vector<string>();
            }
            node = node->children[c];
        }
        return find_words(node, prefix);
    }

    vector<string> find_words(Trie* node, string prefix) {
        vector<string> res;
        if (node->is_end) {
            res.push_back(prefix);
        }
        for (auto it : node->children) {
            char c = it.first;
            Trie* child = it.second;
            vector<string> words = find_words(child, prefix + c);
            res.insert(res.end(), words.begin(), words.end());
        }
        return res;
    }
};

int main() {
    vector<string> words = {"apple", "banana", "orange", "pear", "peach"};
    Trie* trie = new Trie();
    for (string word : words) {
        trie->insert(word);
    }
    string prefix = "p";
    vector<string> results = trie->search(prefix);
    cout << "Words with prefix '" << prefix << "': ";
    for (string word : results) {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}
```

```cpp
#include <iostream>
#include <unordered_map>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool is_word;

    TrieNode() {
        is_word = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->is_word = true;
    }

    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        }
        return curr->is_word;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("banana");
    trie.insert("orange");
    trie.insert("pear");

    if (trie.search("apple")) {
        cout << "Found apple in the Trie!" << endl;
    }

    return 0;
}
```

In this example, we created a `Trie` data structure that used a `TrieNode class` to represent the nodes of the Trie. We use an unordered_map to store the child nodes for each node in the Trie. We also define two methods, `insert` and `search`, to insert words into the Trie and search for words in the Trie, respectively.

As a real-world example, we could use this Trie to implement `autocomplete functionality` in a `search engine` or `text editor`. When a user types a prefix, we can use the search method to find all words in the Trie that start with that prefix and suggest them as autocomplete options to the user.
