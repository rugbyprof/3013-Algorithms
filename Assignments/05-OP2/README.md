## BSTvAVL - Balanced vs Unbalanced
#### Due: Optional Program

### Problem Overview: 

Using the implementations given (or your own), compare the performance of a BST that is not actively balanced vs a tree that actively uses rotations to maintain a balanced tree. 

### Project Description:
1. **Implementation:** 
   - Implement a simple binary tree data structure with operations for insertion, deletion, and searching.
   - Implement a balanced tree data structure such as an AVL tree or a Red-Black tree.
   - Additional methods or data members need to be added / maintained to help with the assessment of the tree's performance. (e.g height method, comparisons variable to count comparisons during searches)
2. **Experiment:**
   - Generate random datasets of different sizes.
   - Perform a series of operations (e.g., insertions, deletions, searches) on both the unbalanced tree and the balanced tree using the same datasets.

3. **Analysis:**
   - Measure and compare:
     - Build cost (time and comparisons)
     - Execution times
     - Number of comparisons
   - Analyze and compare the performance of the unbalanced tree and the balanced tree for various operations.
   - Discuss the advantages and disadvantages of each tree structure.
   - Provide insights into the importance of balancing in maintaining efficient tree operations, especially for large datasets.
   - Taylor your experiments to vary between:
     - Lots of insertions and deletions
     - Lots of searches
     - Equal amount of both
  
>***Comparison***: Any time a value (whether being inserted or searched for) is compared to a node value to determine if the search or insertion should go left or right. Insertion stops when a null ptr is found and item is inserted at that location. Search stops when the key is found, or a null ptr implying that the value isn't in the tree. 



### Expected Learning Outcomes:
- Understanding the concepts of balanced and unbalanced trees.
- Practical experience in implementing and comparing tree data structures.
- Appreciation for the impact of data structure choice on algorithm performance.



