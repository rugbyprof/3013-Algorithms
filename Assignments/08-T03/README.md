## Test 2 - Various Topics
#### Due: 04-24-2024 (Wed @ 2:00 p.m.)

### Topics

- [Complexity](../../Lectures/LectureMaterials/00-Big-Oh/README.md)

## Huffman Coding

- Huffman Coding is a compression algorithm.
- It performs lossless compression. 
- It uses a binary tree as a container and a greedy algorithm to make choices as it runs. 
- You won't need to write any code on the exam, but if your curious:  https://replit.com/@rugbyprof/3013huffmansp23#main.cpp
- Huffman Trees create binary codes based on the frequency of occuring letters or symbols in which the most occuring letters get the smallest binary string (since they occur more).
  - Below is a somewhat contrived example using "War and Peace" and only keeping the letters and the space character and showing the encoding for letter. We won't do anything like this on the exam, this is just a full size(ish) example. 

| Letter | Code            |
| :----: | :-------------- |
|   e    | 011             |
|  ' '   | 111             |
|   d    | 0010            |
|   r    | 0101            |
|   s    | 1000            |
|   h    | 1001            |
|   i    | 1010            |
|   n    | 1011            |
|   o    | 1100            |
|   a    | 1110            |
|   t    | 1111            |
|   f    | 00001           |
|   w    | 00010           |
|   m    | 00011           |
|   c    | 00110           |
|   u    | 01000           |
|   l    | 11011           |
|   v    | 000000          |
|   b    | 001110          |
|   p    | 010010          |
|   y    | 110100          |
|   g    | 110101          |
|   k    | 0100110         |
|   P    | 00000100        |
|   A    | 00000101        |
|   T    | 00000111        |
|   I    | 00111110        |
|   M    | 000001100       |
|   B    | 001111000       |
|   N    | 001111001       |
|   x    | 001111010       |
|   H    | 001111111       |
|   O    | 0000011010      |
|   F    | 0011110110      |
|   D    | 0011110111      |
|   C    | 0011111100      |
|   E    | 0011111101      |
|   j    | 0100111000      |
|   z    | 0100111001      |
|   q    | 0100111010      |
|   W    | 0100111101      |
|   S    | 0100111110      |
|   R    | 0100111111      |
|   V    | 00000110111     |
|   K    | 01001110110     |
|   Y    | 01001110111     |
|   G    | 01001111000     |
|   J    | 000001101100    |
|   X    | 010011110010    |
|   L    | 010011110011    |
|   U    | 0000011011011   |
|   Q    | 00000110110100  |
|   Z    | 00000110110101' |

- On the exam, I will give you a small alphabet and have you create your own Huffman codes. 
- For example the words below: 
  - **`bat hat fat smart smack smear smoke`**
- Give us the following letter breakdown:
  - `aaaaaattttssssmmmmrrkkeebhfco`
- Which when counted out gives us the following frequency table: 

| letter | frequency |
| :----: | :-------: |
|   a    |     6     |
|   t    |     4     |
|   s    |     4     |
|   m    |     4     |
|   r    |     2     |
|   k    |     2     |
|   e    |     2     |
|   b    |     1     |
|   h    |     1     |
|   f    |     1     |
|   c    |     1     |
|   o    |     1     |

### Actual Algorithm

#### 1. **Prepare Frequency List**
   - Create a list of nodes, where each node represents a character and its associated frequency. Each node is initially considered a leaf node in the Huffman Tree (we have one above).

#### 2. **Sort Nodes**
   - Sort the list of nodes in ascending order based on their frequencies. This can be done using any stable sorting method (again, already done.)

> BONUS QUESTION: What is a "stable sort"? 

#### 3. **Create the Huffman Tree**
   - While there are more than one node in the list, perform the following steps:
     - **Select the Two Nodes with the Lowest Frequencies**: These will be the first two nodes in the sorted list because it is sorted in ascending order.
     - **Create a New Node**:
       - The new node will have a frequency equal to the sum of the frequencies of the two selected nodes.
       - Assign the first selected node as the left child and the second selected node as the right child of the new node.
     - **Remove the Two Selected Nodes from the List**: They are now part of the newly created node.
     - **Insert the New Node Back into the List**: Place this node in the correct position to maintain the order by frequency.
     - **Re-sort the List if Necessary**: Ensure the list is sorted by frequency. Efficient methods might update the position iteratively or use a data structure that maintains order automatically, like a priority queue.
     
#### 4. **Resulting Tree**
   - The last remaining node in the list becomes the root of the Huffman Tree. At this point, all characters are represented as leaves of the tree, with their paths from the root defining their corresponding Huffman codes.

#### 5. **Generate Huffman Codes**
   - To generate Huffman codes for each character:
     - Start from the root and traverse to each leaf. Use a depth-first search.
     - Assign a '0' for every left branch taken and a '1' for every right branch.
     - The sequence of '0's and '1's from the root to a leaf node forms the Huffman code for the character at that leaf.

#### 6. **Code Optimization (Optional)**
   - Review the tree for any possible optimizations, such as adjusting the structure to reduce the depth of frequently used characters, which could help in reducing the overall cost of the tree.

#### 7. **Testing and Validation**
   - Verify the tree by encoding some sample text and checking if the encoded version is as compact as expected.
   - Test decoding the encoded text to ensure it correctly translates back to the original text using the Huffman Tree.

#### 8. Verify Your Tree 
  - Cut and paste the words being used **`bat hat fat smart smack smear smoke`**
  - Or these letters: `aaaaaattttssssmmmmrrkkeebhfco`
  - At this site: https://cmps-people.ok.ubc.ca/ylucet/DS/Huffman.html to visualize tree creation

#### Complexity
    - [https://en.wikipedia.org/wiki/Huffman_coding#Basic_technique](https://en.wikipedia.org/wiki/Huffman_coding#Basic_technique)

#### Question
  1. Given a small sentence, 
  2. calculate the frequencies of the letters, 
  3. build a tree, 
  4. get binary encoding for each letter
  5. write out your binary encoded answer

  - [Trie Trees](prefix trees)
  - [Hashing]
  - [Graphs]
    - Depth First Search
    - Breadth First Search
  - 
