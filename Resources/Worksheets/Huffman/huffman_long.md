# Huffman Compression Worksheet

This worksheet will help you walk through the Huffman compression algorithm step-by-step. By the end, you should be able to:

1. Understand how Huffman trees are constructed.
2. Practice combining frequencies and subtrees.
3. Encode a given set of pangrams using the Huffman method.

---

## 1. Background: Huffman Compression

**Huffman compression** is a technique used to assign variable-length codes to characters, with the most frequently occurring characters receiving shorter codes than those that appear less often. The process involves:

1. Gathering frequency counts (or probabilities) of each character.
2. Building a **Huffman tree** by iteratively combining the two least-frequent nodes.
3. Assigning **binary codes** to each character based on its path from the root of the Huffman tree.

---

## 2. Frequency Distribution (Rounded Up)

Below is a **standard approximate frequency** distribution for English letters, where all frequencies are **rounded up** to the nearest whole number. Use these frequencies when constructing your Huffman tree (unless you need to adapt them for a custom dataset).

| Letter | Frequency |
| ------ | --------- |
| E      | 12        |
| T      | 9         |
| A      | 8         |
| O      | 8         |
| I      | 8         |
| N      | 7         |
| S      | 7         |
| R      | 7         |
| H      | 6         |
| D      | 5         |
| L      | 4         |
| U      | 3         |
| C      | 3         |
| M      | 3         |
| F      | 3         |
| Y      | 3         |
| W      | 3         |
| G      | 3         |
| P      | 2         |
| B      | 2         |
| V      | 2         |
| K      | 1         |
| X      | 1         |
| Q      | 1         |
| J      | 1         |
| Z      | 1         |

> **Note:** The sum of these frequencies doesn’t matter as much as their **relative** values. But you’ll use these **whole numbers** directly when creating your nodes.

---

## 3. Pangrams for Testing

A **pangram** is a sentence that contains every letter of the alphabet at least once. Below are 10 pangrams you can use to test your Huffman encoding. Feel free to pick one or more:

1. The quick brown fox jumps over the lazy dog.
2. Pack my box with five dozen liquor jugs.
3. Sphinx of black quartz, judge my vow.
4. Waltz, bad nymph, for quick jigs vex.
5. Jived fox nymph grabs quick waltz.
6. Glib jocks quiz nymph to vex dwarf.
7. Sly dog quits job, vixen pard.
8. Cwm fjord bank glyphs vext quiz.
9. Amazingly few discotheques provide jukeboxes.
10. Jackdaws love my big sphinx of quartz.

---

## 4. Assignment Tasks

### **Task A: Frequency Count of Pangrams**

1. **Pick** at least one pangram (or more if you want extra practice).
2. **Ignore** punctuation (commas, periods, etc.) for simplicity (or keep them if your assignment requires it).
3. **Convert** all letters to uppercase or lowercase for consistency.
4. **Count** how many times each letter appears in your chosen pangram(s).
5. **Compare** these counts with the default frequencies above — do they match or differ significantly? (This step is just for insight; you’ll use the standard distribution in Section 2 for your tree.)

### **Task B: Construct Initial Huffman Nodes**

You will create **one node for each letter** of the alphabet. In your worksheet/notebook:

1. **List** all 26 letters.
2. **Assign** each letter its (rounded) frequency from Section 2.
3. **Create** a node for each letter, showing:
   - The **letter** itself.
   - The **node’s frequency**.

> **Suggested Graphic:**  
> Draw 26 small circles or boxes. Label each with `Letter` and `Frequency`, e.g., `(E,12)`, `(T,9)`, `(A,8)`, etc.

### **Task C: Build the Huffman Tree Iteratively**

The standard Huffman algorithm proceeds like this:

1. **Identify** the two nodes with the **smallest frequencies**.
2. **Combine** them into a new subtree, where the new node’s frequency = sum of the two combined nodes.
3. **Remove** the two old nodes from your “available node” list and **insert** the new subtree.
4. **Repeat** until there’s only one node left — the root of your Huffman tree.

**Instructions for Graphics:**

1. **Stage 1:** Draw the initial 26 nodes (letters).
2. **Stage 2:** Highlight the two nodes with the smallest frequencies, combine them into a subtree.
   - For example, `(Z,1)` and `(J,1)` might become a new subtree with a combined frequency of 2.
   - Draw a node above them labeled `(2)` to show their sum.
3. **Stage 3:** Replace these two letters with the newly formed subtree in your “pool” of available nodes.
4. **Stage 4:** Continue combining the next smallest pairs (like `(Q,1)` with `(K,1)`, etc.).
5. **Stage 5:** Each time you combine nodes, **update** the diagram by drawing a new subtree node (the “parent”) and connecting the two child subtrees.
6. **Final Stage:** You’ll end up with a **single** root node that has all 26 letters beneath it in a hierarchical structure.

Throughout these steps, document or sketch the tree so you have a record at each iteration.

### **Task D: Assign Binary Codes**

Once your full Huffman tree is constructed:

1. **Start** at the root node.
2. **Go left:** Assign a `0` to that branch.
3. **Go right:** Assign a `1` to that branch.
4. **Record** the code for each letter by writing the sequence of bits from the root to that letter.

> **Example (Hypothetical)**:
>
> - If the path from the root to the letter `E` is `Left, Right, Left`, the code might be `0-1-0` → `010`.
> - The exact code length depends on the tree’s structure, which in turn depends on the actual frequencies.

### **Task E: Encode a Test Pangram**

After you have the Huffman tree and codes:

1. **Take** a pangram (or part of it).
2. **Replace** each letter with its Huffman code.
3. **Count** the total number of bits used to encode the pangram.
4. Compare it to the length of the pangram in **8-bit ASCII**. See how many bits you saved by using Huffman compression!

---

## 5. Submission or Follow-Along Items

In summary, here’s what you’ll either submit or bring to class:

1. **List of Nodes**: A table or diagram showing each letter with its frequency (using the table in Section 2).
2. **Tree-Building Stages**:
   - Optional sketches or a step-by-step record of combining nodes.
3. **Final Huffman Tree**:
   - A clear diagram that indicates the structure and combined frequencies.
4. **Binary Codes per Letter**:
   - A small table: `Letter -> Huffman Code -> Original Frequency`
5. **Encoded Pangram**:
   - Show the final bit string and a short calculation of total bits required.

---

## 6. Additional Notes

- **Case Sensitivity**: Typically, Huffman encoding merges uppercase and lowercase. If you prefer to distinguish them, your table would need 52 letters.
- **Handling Spaces & Punctuation**: If you want to encode spaces and punctuation, treat them as separate symbols with their own frequencies.
- **Edge Cases**:
  - If a letter doesn’t appear at all in your test data (like `Z` in many sentences), it still has a nonzero “theoretical” frequency in the standard table.
  - For real compression tasks, you only build the tree for symbols that actually appear, but in this assignment, we’re practicing the full approach.

---

### Good luck and have fun building your Huffman tree!

Remember that the key idea is to always combine the **lowest-frequency** nodes first, which ensures the most common symbols end up with the shortest possible bit patterns. If you get stuck or need clarification, ask questions in class or consult the recommended resources from your instructor.
