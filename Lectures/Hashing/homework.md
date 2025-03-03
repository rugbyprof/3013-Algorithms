## Hashing Homework - Strategies and Collision Resolution

#### Due: 03-17-2025 (Mon @ 2:00)

This assignment is designed to deepen your understanding of hash tables by exploring both open addressing (closed hashing) and open hashing (separate chaining). You will simulate insertions using different collision resolution techniques and analyze the impact of hash table sizes on performance and collisions.

---

## Objectives

1. **Differentiate** between open hashing (separate chaining) and closed hashing (open addressing).
2. **Apply** various collision resolution methods such as linear probing, quadratic probing, and chaining.
3. **Analyze** the effects of poor hash table size choices on collision frequency.
4. **Simulate** the insertion of a given set of keys and illustrate the resulting hash table state.

---

## Part A: Conceptual Questions

1. **Define Hashing and Collision Resolution**

   - What is a hash table and why is collision resolution necessary?
   - Explain the key differences between open hashing (chaining) and closed hashing (open addressing).

2. **Collision Resolution Techniques**

   - Briefly describe at least two methods for resolving collisions in open addressing (e.g., linear probing, quadratic probing, double hashing).
   - Explain the pros and cons of each method.

3. **Impact of Hash Table Size**
   - How does the choice of table size affect the distribution of keys?
   - What are the pitfalls of using a poor table size (for example, a table size that is a round number or a power of 2)?

---

## Part B: Simulation and Diagram Exercises

### Exercise 1: Open Hashing (Separate Chaining)

Given the following set of keys:

$5, 22, 17, 18, 35, 101, 16, 0, 8$

- **Task:**
  1. Assume a hash table size of $10$.
  2. Use the division method hash function: $h(k) = k\ mod\ 10$.
  3. Insert the keys in the given order using **separate chaining** (each table slot holds a linked list of entries).
  4. Draw a diagram showing the hash table buckets and the contents of each bucket after all insertions.
  5. Identify any buckets with collisions and note how many elements are stored in each.

### Exercise 2: Closed Hashing (Open Addressing)

**Using the same set of keys:**

$5, 22, 17, 18, 35, 101, 16, 0, 8$

- **Task:**
  1. Assume a hash table size of $10$.
  2. Use the same hash function: $h(k) = k\ \mod\ 10$.
  3. Insert the keys in the given order using **linear probing** for collision resolution.
  4. Draw a diagram of the hash table showing the index positions and the key stored at each index.
  5. Discuss any clustering effects you observe.

### Exercise 3: Impact of Poor Table Sizes

- **Task:**
  1. **Consider the set of keys:**
     ```
     5, 10, 15, 20, 25, 30, 35, 40
     ```
  2. Simulate insertion using the division method with a table size of $10$ and then with a table size of $11$ (a prime number).
  3. For each scenario, draw the resulting hash table (choose either open or closed addressing for consistency).
  4. Compare the distribution of keys and discuss which table size appears to offer a more uniform distribution and why.

### Optional Extra Credit:

- **Experiment with Other Collision Resolution Techniques**
  - Choose quadratic probing or double hashing.
  - Simulate the insertion of a new set of keys (e.g., $12, 23, 34, 45, 56, 67, 78, 89$) using your chosen method.
  - Draw the resulting hash table and briefly explain the benefits or drawbacks of your chosen technique.

---

## Part C: Reflection & Short-Answer Questions (optional)

1. **Real-World Impact:**

   - Explain how choosing a poor hash table size can lead to performance degradation in real-world applications.
   - How do open and closed hashing strategies differ in their handling of collisions in high-load scenarios?

2. **Design Considerations:**

   - If you were to design a hash table for a high-frequency trading system where every millisecond counts, which collision resolution strategy might you choose and why?

3. **Extension:**
   - How might you combine the benefits of chaining and open addressing to design a hybrid hash table? (Brief discussion)

---
