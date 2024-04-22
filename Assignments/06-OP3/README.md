## Hashing - Mini Experiment
#### Due: Optional Program


## Evaluating Hash Function Performance

### Overview:
In this assignment, you will explore the performance of a specific hash function `H` (see [PolynomialHash.md](./PolynomialHash.md)) by applying it to different data types such as words, numbers, and larger text blocks. You will assess how effectively the hash function distributes data across a hash table and analyze the impact of different collision resolution techniques and table sizes on performance. The key techniques for collision resolution you will explore are linear probing and chaining.

### Objectives:
- Implement the given hash function `H`.
- Understand and implement two collision resolution techniques: linear probing and chaining.
- Analyze the effect of hash table size on the performance of the hash function and collision resolution mechanisms.
- Compare and contrast the efficiency of different collision resolution techniques across various scenarios and data types.

### Assignment Tasks:
1. **Implementation of Hash Function `H`**
   - Implement the hash function `H` as described. Ensure it can handle inputs of varying types and sizes, including individual words, numbers, and blocks of text.

2. **Setup of Hash Table**
   - Create a hash table implementation that can switch between linear probing and chaining for collision resolution.
   - Prepare to adjust the size of the hash table (small, medium, large) to observe the impact on performance.

3. **Data Preparation**
   - Generate datasets of words, numbers, and text blocks. Ensure you have a mix of dataset sizes and content diversity.
   - You may choose to use existing text corpora (e.g., from books or articles) or generate synthetic datasets of numbers and words.

4. **Experimentation**
   - Insert data into the hash table using both collision resolution techniques (linear probing and chaining) for each type of dataset.
   - Record metrics such as the number of collisions, average search time, and load factor for each scenario.

5. **Performance Analysis**
   - Analyze the data collected during experimentation. Discuss how the hash table size influences the performance metrics.
   - Compare the efficiency of linear probing versus chaining across different data types and table sizes.

6. **Report Writing**
   - Compile your findings into a comprehensive report. Include:
     - Introduction to hashing and the specific hash function used.
     - Detailed methodology of your implementation and experiments.
     - Results with graphs or tables showing performance metrics.
     - Discussion of findings, including any surprising behaviors or particularly good/bad performance scenarios.
     - Conclusion summarizing the key takeaways and potential real-world applications of your findings.
