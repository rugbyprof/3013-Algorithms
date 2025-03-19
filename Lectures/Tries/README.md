## Trie - Not A Tree (but it is...)

#### Due: N/A

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

### Node Structure

```cpp
Below is a simple C++ struct for a trie node that stores child pointers for the 26 letters of the English alphabet (assuming all letters are lowercase a–z). It also includes a boolean flag endOfWord that indicates whether the node represents the end of a valid word.

#include <cstddef> // for nullptr

struct TrieNode {
    // Each child pointer corresponds to a letter (a = 0, b = 1, ..., z = 25)
    TrieNode* children[26];

    // True if this node marks the end of a word
    bool endOfWord;

    // Constructor: initialize all children to nullptr, endOfWord to false
    TrieNode() : endOfWord(false) {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};
```

#### Explanation

- children[26]:
- Each index corresponds to a letter in the alphabet. For example, children[0] is for a, children[1] is for b, and so on. If your trie needs to handle uppercase letters or symbols, you could expand this array or use another data structure (like a map).
- endOfWord:
- A flag to mark the node as the end of a word. This way, words like "cat" and "car" can share a path for "ca", but differ at the final node where endOfWord is set to true.
- Constructor:
- Initializes endOfWord to false and sets all child pointers to nullptr (or NULL in older C++ code).

#### Variations

- Using a map or unordered_map<char, TrieNode>\*
- Instead of a fixed array of size 26, you can dynamically store children keyed by characters. This is more flexible if you have to handle punctuation, uppercase letters, or extended character sets.
- Storing Additional Data
- You might include frequency counts, word definitions, or any other metadata needed for your application.

This basic structure is enough to implement common trie operations such as inserting a word, searching for a word, and deleting a word.

## Implementation

Go [HERE](https://replit.com/@rugbyprof/3013TrieSpring2021-1) on repl.it to see a full implementation

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

## Complexity

When discussing the complexity of a trie, we typically focus on time and space complexity for the core operations (insertion, search, and deletion) and the overall storage requirements:

### 1. Time Complexity

**Let:**

- L = the maximum length of a word (e.g., the number of characters in the word being inserted or searched).
- k = the size of the character set (26 for lowercase English letters, or more if you handle extra symbols).

#### a. Insertion

- Worst-case: $O(L)$ You traverse (or create) one node per character in the word.
- At each step, you index into the child pointer (or map) that corresponds to the current character.
- This operation takes $O(1)$ if using an array (e.g., children[26]) or $O(log k) /div O(1)$ if using some kind of map/hashtable, repeated $L$ times.

#### b. Search

- Worst-case: $O(L)$
  Similar to insertion: you traverse up to L nodes in the trie, once per character, to see if the path exists.

#### c. Deletion

- Worst-case: $O(L)$
  You must first find the last character of the word (as in search) and then remove or mark the end-of-word flag. If you need to fully remove unused nodes (i.e., if they are no longer needed by other words), you might walk back up and deallocate, which still remains proportional to L.

#### Key takeaway:

Insertion, search, and deletion each have time complexity proportional to the word length, $O(L)$.
This is especially efficient compared to, say, a binary search tree (BST) in which operations can degrade to $O(N)$ if the tree becomes unbalanced.

### 2. Space Complexity

#### a. Storage Requirements

- In the worst case, if there’s no overlap among prefixes of the stored words, the trie can become quite large.
- Typically, each node has an array of size $k$ (26 for letters) or a map/dictionary keyed by characters.

For $N$ words with an average length $L$, the total space can be:

- $O(N * L)$ nodes in practice, since each new node is only created when a word path diverges.
- Each node has up to $k$ child pointers/entries, so if you account for those pointers, you might see an additional factor of $k$ in some analyses. Often, we treat $k$ as a constant when we’re only dealing with a fixed alphabet (like 26 letters).

Hence, the practical space complexity for storing $N$ words of average length $L$ is often cited as $O(N * L)$, ignoring the constant factorn $k$.

## 3. Summary

1. Time Complexity (Insertion/Search/Deletion): $O(L)$

- You only need to visit at most L nodes.

2. Space Complexity: $O(N * L)$ for N words of average length L (assuming a fixed alphabet).

This makes a trie extremely efficient for prefix lookups, autocorrect-like features, or any application where quick searches and prefix manipulations are needed—at the cost of higher memory usage than more compact data structures (e.g., a hash-based approach) if many words do not share common prefixes.
