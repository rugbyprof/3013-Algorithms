## BSTvAVL - Balanced vs Unbalanced
#### Due: Optional Program

# UPDATE: 

I cleaned up the BST and AVL class implementations. I made the AVL class extend the BST class just cause it was the right thing to do. I also added some helper code which I will explain below.  

- In main I added a function and two STL Maps. One map holds floating point vals (or ints) and the other holds string. 
```cpp
std::map<std::string, float> floatArgs;
std::map<std::string, std::string> stringArgs;

void parseArguments(int argc, char** argv)
```

The purpose of this function is so that you can generate an experiment using command line arguments like this:
```bash
./main f_minval=0 f_maxval=1024 f_nums=500 s_runtype=randomMix s_output=run0.1024.500.txt 
```
What does this do?
- Each keyvalue pair will get loaded into one of the STL Maps.
- If the `key` starts with an `f_` it goes to the floatArgs map, if it starts with an `s_` it goes to the stringArgs map.
- Why is this helpful? Given the following:
```bash
./main f_minval=0 f_maxval=256 f_nums=256 s_runtype=randomMix s_output=run0.256.256.txt 
./main f_minval=0 f_maxval=512 f_nums=512 s_runtype=randomMix s_output=run1.512.512.txt 
./main f_minval=0 f_maxval=1024 f_nums=1024 s_runtype=randomMix s_output=run2.1024.1024.txt 
./main f_minval=0 f_maxval=256 f_nums=256 s_runtype=searches s_output=run3.256.256.txt  
./main f_minval=0 f_maxval=512 f_nums=512 s_runtype=searches s_output=run4.512.512.txt 
./main f_minval=0 f_maxval=1024 f_nums=1024 s_runtype=searches s_output=run5.1024.1024.txt 
```
I can run 6 experiments without changing any of the code inside the main file. These params
could tell your code to generate 256 random numbers, do a random mix of insertions deletions and searches, 
save the output to a file called run0.256.256.txt 

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



