# Simple Compression Algorithms to Discuss

When introducing **data compression** to students, it helps to start with simple concepts and build up. Below are a few straightforward algorithms that demonstrate the **core ideas** of compression:

---

## 1. Run-Length Encoding (RLE)

### Concept

- **RLE** replaces **consecutive repeated data** (e.g., `AAAAA`) with a count and symbol (e.g., `5A`).
- Works best on data with **long runs** of the same character (e.g., simple images, black & white bitmaps).

### Example

- Data: `AAAABBBCCD`
- RLE: `4A3B2C1D`
- Gains: Very easy to implement and understand.
- Limitations: If data is highly variable, RLE might **increase** size (e.g., `ABC` → `1A1B1C`).

---

## 2. Huffman Coding

### Concept

- **Huffman coding** assigns **shorter bit patterns** to more frequent symbols and **longer bit patterns** to less frequent symbols.
- Often represented as a **binary tree**, where traversing left/right yields a unique bit code for each character.

### Example

1. Calculate frequency of each character in a text (e.g., `{'A': 10, 'B': 5, 'C': 2}`).
2. Build a **Huffman tree** from bottom up:
   - Combine least-frequent nodes repeatedly until you form a single tree.
3. Generate **codes** by traversing from root to leaves (left=0, right=1).
4. Encode data using these codes.

### Gains & Limitations

- Gains: Works well for data with a known **frequency distribution** of characters.
- Limitations: Must **store the tree** or a code table. Less effective on very short files or uniform data.

---

## 3. Dictionary-Based Methods (LZ Family)

### Concept

- **LZ77** or **LZ78**–type algorithms scan the data for **repeated sequences**, then replace those sequences with references (pointers) to earlier occurrences.
- **LZW** (Lempel–Ziv–Welch) is a variant that builds a **dictionary** of repeated patterns on the fly.

### Simple LZ78 Overview

1. Start with an **empty dictionary**.
2. Read characters until you match an existing entry in the dictionary (longest match).
3. When you find a new sequence not in the dictionary, store it along with a **dictionary index** that references a previous sequence.
4. Replace the repeated sequence with a `(dictionary_index, next_character)` pair in the compressed stream.

### Gains & Limitations

- Gains: No prior knowledge of the data is needed; dictionary builds dynamically.
- Limitations: Implementation more complex than RLE or Huffman. Less efficient on short data or if repeated sequences are rare.

---

## 4. Simple Statistical Coding (Optional Mention)

### Example: Shannon–Fano

- **Shannon–Fano** is conceptually similar to Huffman, but splits characters into halves by cumulative frequency rather than combining smallest pairs.
- Generally less optimal than Huffman but simpler to teach as an example of **statistical coding**.

---

## Which to Teach First?

1. **RLE** is an **easy starting point** – straightforward, quick payoff in demonstration.
2. **Huffman Coding** introduces **frequency-based** compression and a **tree** concept.
3. **LZ algorithms** offer an **on-the-fly** or **dictionary** perspective, bridging the gap to more advanced formats (like `.zip`, `.gz`).

---

## Classroom Tips

- **Demonstrate** RLE on a simple image or text with repeated characters.
- **Use a small text** (e.g., `"AAAAABBBCC"`) to walk through the steps of **Huffman coding**.
- **Small dictionary** example for **LZ** to show how sequences are replaced by references.

---

## Final Thoughts

These algorithms provide an excellent stepping stone:

1. **RLE** → Basic concept of “reducing repeated data.”
2. **Huffman** → Frequency-based compression and the idea of a **variable-length code**.
3. **LZ-based** → Introduces dynamic dictionary building for repeated substrings.

By understanding these simple approaches, students gain insight into the **fundamental ideas** behind many modern compression tools and standards (e.g., ZIP, PNG, GIF).
