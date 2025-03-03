# Visualizing Poor Hash Table Sizes: Low-Order Bit Collision Effects

## Objective

Demonstrate how a poorly chosen hash table size forces the hash function to use only the low-order bits of keys, resulting in significant clustering (many keys hashing to the same buckets).

---

## Visualization Ideas

### 1. Bucket Distribution Bar Graph

- **Method:**
  - Write a script that inserts a set of keys into a hash table using a poor table size (e.g., 10) with a simple modulo hash function.
  - Use a bar graph (e.g., with Python's matplotlib) to display bucket indices (x-axis) versus the number of keys in each bucket (y-axis).
- **Observation:**
  - With a poor table size, a few buckets will have high counts while others remain empty, illustrating clustering.

### 2. Animated Insertion with Manim

- **Method:**
  - Create an animation where each bucket is represented as a box on a horizontal line.
  - Animate keys (as labeled circles or boxes) being hashed (showing their binary form) and then moving to their corresponding bucket based on `key % tableSize`.
- **Observation:**
  - Highlight that many keys end up in only a few buckets.
  - Visually emphasize that only a subset of the binary bits (the low-order bits) determine placement.

### 3. Binary Representation Overlay

- **Method:**
  - For each key, display its binary representation.
  - Show the modulo operation extracting the low-order bits.
  - Overlay the computed bucket index.
- **Observation:**
  - Clearly illustrates that if keys share similar low-order bits, they will hash to the same bucket.

### 4. Interactive Web Simulation

- **Method:**
  - Develop a simple web app (using JavaScript/HTML/CSS) where users can enter keys and choose a table size.
  - The simulation dynamically visualizes a hash table and shows key distribution as they are inserted.
  - Use visual cues (e.g., colors or animations) to indicate buckets with high collision rates.
- **Observation:**
  - Enables students to experiment with different table sizes (poor vs. optimal) and immediately see the effects on distribution.

### 5. ASCII Terminal Visualization

- **Method:**
  - Write a command-line program that prints out each bucket and lists the keys that hash into it.
  - Optionally, use color-coding (e.g., via ANSI escape codes) to highlight buckets that are overloaded.
- **Observation:**
  - Provides a simple, text-based way to see how keys are clustered when using a poor table size.

---

## Conclusion

These visualization techniques help students understand:

- How a **poor table size** (e.g., a round number or a power of 2) can force the hash function to use only low-order bits.
- The resulting **clustering** where only a few buckets are utilized, leading to performance degradation.
- The importance of choosing a **good hash table size** (often a prime number) to achieve a more uniform key distribution.

Happy visualizing and hashing!
