

## 3013 - Final Exam
  
#### Name ________________________________
  
#### Terminology
  
**1)**  ____ A collection of key-value pairs that associate a key with a value.
  
**2)**  ____ A hierarchical structure that place elements in nodes along branches that originate from a root.
  
**3)**  ____ A tree structure in which each node can have at most two children, and in which a unique path exists from the root to every other node.
  
**4)**  ____ A type of tree in which the key value of each node is less than every key value in its right subtree, and greater than every key value in its left subtree.
  
**5)**  ____ A type of binary tree in which the height of each node’s subtrees differs by no more than one.
  
**6)**  ____ A two-dimensional structure that corresponds to a row-column table of entries of a specified data type.
  
**7)**  ____ A binary tree in which all of the leaves are on the same level and every non-leaf node has exactly two children
  
**8)**  ____ A binary tree that is either full or full through the next-to-last level, with the leaves on the last level as far to the left as possible
  
**9)**  ____ A complete binary tree in which each node has a value stored in it that is greater than or equal to the value in each of its children.
  
**10)**  ____ Nodes in a binary tree that have only NULL children
  
**11)**  ____ A node in a binary tree that does not have a parent
  
**12)**  ____ A data structure that consists of a set of nodes and a set of edges that relate the nodes to each other
  
**13)**  ____ A graph in which each edge is directed from one vertex to another (or the same) vertex
  
**14)**  ____ A graph in which every vertex is directly connected to every other vertex
  
**15)**  ____ A graph in which each edge carries a value
  
**16)**  ____ This occurs when 2 different identifiers are hashed into the same location
  
**17)**  ____ A method for finding the shortest path from one vertex to another in a weighted digraph
  
**18)**  ____ A graph traversal method that visits the nodes from a starting vertex “level by level”
  
**19)**  ____ Extreme change in resulting value by simply changing a single bit.
  
**20)**  As the ________ approaches 1, the number of collisions increases in a hash table.
  
  
| Terms |  | | |
|:-----------------|:-----------------|:-----------|------|
| A. Avalanche 				| J. Hash table  |R. Dijkstra’s algorithm 	|Z. Digraph |
| B. Balanced 				| K. Heap 	 	 | S. Set 					|AA. Set difference |
| C. Array 					| L. Graph       | T. AVL tree 				|BB. Korat 
| E. Binary tree 			| M. Leaf 		 | U. Load Factor  			|CC. Prim’s algorithm |
| F. Binary search tree 	| N. Map 		 | V. Device miniaturization |DD. Complete |
| G. Black box testing 		| O. Matrix      | W. Full 	                | EE. Weighted graph |
| H. Breadth First Search 	| P. Overflow    | X. Tree               |  FF. Root |
| I. Collision 				| Q. Partially filled array | Y. Depth First Search | |

<img  src="https://d3vv6lp55qjaqc.cloudfront.net/items/1Q180P0f3r0X0L0V062B/final_tree.png"  width="400px">
  
**21)** What is the parent of node 5? ___________________
**22)** What is the height of this tree? ____________________
**23)** List the children of node 12. ___________________________
**24)** List all of the non leaf nodes. ______________________________

**25)** Give the order that the nodes are visited in a pre-order traversal of the tree.
<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.final.box_row.png" width="700">

**26)** Give the order that the nodes are visited in a in-order traversal of the tree.
<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.final.box_row.png" width="700">
  
  
#### Multiple Choice

**1)** Insert 70 into the following tree AVL Tree:
<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.final.avl.1.png">  

Choose the correct result:
<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.final.avl.2.ans.png">  

**2)** Avl Tree's:

**`(A)`** Always balanced
**`(B)`** Perform Double Rotations
**`(C)`** Perform single rotations
**`(D)`** Maintain a balance factor
**`(E)`** All of the above

**3)** Which of the following is true about Huffman Coding?  
**`(A)`** Prefixes are bounded by the number of occurrences of the most frequent letter.  
**`(B)`** Prefixes are always an alternating pattern of 0's and 1's and build upon each other.
**`(C)`** In Huffman coding, no code is prefix of any other code.  
**`(D)`** All of the above

**4)** Which of the following is true about Huffman Coding?  
**`(A)`** Huffman coding is a lossy compression algorithm. 
**`(B)`** Huffman coding is a lossless compression algorithm.
**`(C)`** Huffman coding can be both lossy or lossless depending on the implementation.   
**`(D)`** All of the above
**`(E)`** None of the above

**5)** Is this a viable tree for the text ‘mississippi’? 

**`(A)`**  True
**`(B)`** False

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.final.avl.answer.3.png" height="200">  

**6)** How many bits would be needed to encode ‘mississippi’?
**`(A)`** 1
**`(B)`** 2
**`(C)`** 3
**`(D)`** 4
**`(E)`** 5

**7)** The linear probe method for hash tables suffers from the phenomenon known as:

**`(A)`** fatal collisions
**`(B)`** sparse distribution
**`(C)`** clustering
**`(D)`** broken chains
**`(E)`** none of the above
  
**8)** Which of the following are true of heaps ? (choose all that apply)
  
**`(A)`** It is a binary tree
**`(B)`** In terms of its shape, it must be complete
**`(C)`** It can be either a maximal or a minimal heap
**`(D)`** The value of the root has no relationship to the value of any other nodes
**`(E)`** Is useful for implementing a stack
**F)** Is the most efficient representation for a priority queue
  
**9)** Hashing is an ______ search algorithm.

**`(A)`** O(log2n)
**`(B)`** O(n2)
**`(C)`** O(n)
**`(D)`** O(1)
  
  
**4)** What graph traversal algorithm uses a queue to keep track of vertices which need to be processed?
  
**`(A)`** Breadth-first search.
**`(B)`** Depth-first search.
  

**5)** How many spanning trees does the following graph have?
<center>
<img  src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.final.spanning_tree.1.png"  width="300"></center>

**`(A)`** 1
**`(B)`** 2
**`(C)`** 3
**`(D)`** 4
**`(E)`** More than 4

 ---
 <center>Kruskels Questions<br>
<img  src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.final.kruskels.1.png"  width="300"></center>
  
**6)** In the figure above, using Kruskal's algorithm, which edge should we choose first?
**`(A)`** AB
**`(B)`** EG
**`(C)`** BE
**`(D)`** AG
**`(E)`** None of the above
  
**7)** In the figure above, using Kruskal's algorithm, which edge should we choose third?
**`(A)`** EF
**`(B)`** AG
**`(C)`** BG
**`(D)`** EG
**`(E)`** None of the above
  
**8)** In the figure above, using Kruskal's algorithm, which edge should we choose last?
**`(A)`** None of the above
**`(B)`** AB
**`(C)`** AC
**`(D)`** CD
**`(E)`** BC
  
**9)** In the figure above, which of the following edges of the given graph are not part of Kruskel's MST?
**`(A)`** AC
**`(B)`** EF
**`(C)`** AG
**`(D)`** BG
**`(E)`** None of the above
  
**10)** In the figure above, the total weight of the MST is:
**`(A)`** 31.
**`(B)`** 42.
**`(C)`** 55.
**`(D)`** 95.
**`(E)`** None of the above
  
**11)** Which of the following statements is true about Kruskal's algorithm (choose one):

**`(A)`** It is an inefficient algorithm, and it never gives the minimum spanning tree.
**`(B)`** It is an efficient algorithm, and it always gives the minimum spanning tree.
**`(C)`** It is an efficient algorithm, but it doesn't always give the minimum spanning tree.
**`(D)`** It is an inefficient algorithm, but it always gives the minimum spanning tree.
**`(E)`** None of the above
  
**12)**  `True` or `False`: Prim’s algorithm is a greedy algorithm but Kruskal’s algorithm is not.
 
  ---
 <center>Prims Questions<br>
<img  src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.final.prims_graph_2.png"  width="300"></center>
 
 
**13)** In the figure above, using Prim's algorithm, which edge should we choose first? The starting node is A.
**`(A)`** GE
**`(B)`** GF
**`(C)`** CB
**`(D)`** AF
**`(E)`** None of the above
  
**14)** In the figure above, using Prim's algorithm, which edge should we choose third?
**`(A)`** DF
**`(B)`** AG
**`(C)`** BG
**`(D)`** EG
**`(E)`** None of the above
  
**15)** In the figure above, using Prim's algorithm, which edge should we choose last?
**`(A)`** GE
**`(B)`** AF
**`(C)`** BC
**`(D)`** DC
**`(E)`** None of the above
  
**16)** In the figure above, which of the following edges of the given graph are not part of the minimum spanning tree?
**`(A)`** CB
**`(B)`** BG
**`(C)`** CD
**`(D)`** AC
**`(E)`** All of the above
  
**17)** In the figure above, the total weight of the minimum spanning tree is
**`(A)`** 25.
**`(B)`** 21.
**`(C)`** 22.
**`(D)`** 23.
**`(E)`** None of the above
  
**18)** Which of the following data structures requires more than constant average time for insertions? (choose all that apply)
**`(A)`** hash table
**`(B)`** queue
**`(C)`** search tree
**`(D)`** stack
**`(E)`** all of the above have constant time insertion algorithms
  
**19)** What is the range of values computed by the hash function:
`Hash(X) = X mod 100`?
**`(A)`** 0 to 99
**`(B)`** 0 to 100
**`(C)`** 1 to 99
**`(D)`** 1 to 100 14
**`(E)`** none of the above
  
**20)** Which of A to D is false:
The size of a hash table:
**`(A)`** should be a power of 2 for quadratic probing
**`(B)`** should be a prime number for linear probing
**`(C)`** should be about 2<sup>n</sup> for quadratic probing
**`(D)`** should be about n for separate chaining
**`(E)`** if you mark this one, you will get it right (seriously color in E).
  
**21)** How are elements deleted in linear probing?
**`(A)`** deletion is not allowed
**`(B)`** they are remove and changed to zero
**`(C)`** they are removed and marked deleted
**`(D)`** they are removed then run unchecked deallocation
**`(E)`** none of the above
  
**22)** Suppose we are implementing quadratic probing with a hash function:
`Hash(X) = X mod 100` where the probe sequence is: ![H+1^{2},H+2^{2},H+3^{2},H+4^{2},...,H+k^{2}](https://wikimedia.org/api/rest_v1/media/math/render/svg/40ae2a97f9cdcc56936d0af6166125512db20019).
If an element with key 4594 is inserted and the first three locations attempted are already occupied, then the next cell that will be tried is:
**`(A)`** 2
**`(B)`** 3
**`(C)`** 10
**`(D)`** 97
**`(E)`** none of the above
  
**23)** In a separate chaining hash table with load factor = 0.8, what is the average length of a list?
**`(A)`** 0.8
**`(B)`** 1.0
**`(C)`** 1.25
**`(D)`** there is not enough information
**`(E)`** there is enough information, but none of the above are correct
  
**24)** Which of the following costs are equal in a probing hash table?

**`(A)`** insertion and successful search
**`(B)`** insertion and unsuccessful search
**`(C)`** successful search and unsuccessful search
**`(D)`** insertion, successful search, and unsuccessful search
**`(E)`** none of the above
  
  
**26)** Linked lists are used in:

**`(A)`** double hashing
**`(B)`** linear probing
**`(C)`** quadratic probing
**`(D)`** separate chaining
**`(E)`** all of the above
  
**27)** Primary clustering occurs in
**`(A)`** linear probing
**`(B)`** quadratic probing
**`(C)`** separate chaining
**`(D)`** all of the above
**`(E)`** none of A, B, and C
  

**29)** Every node in a (**min**) binary heap
**`(A)`** has two children
**`(B)`** is larger than its children
**`(C)`** is smaller than its children
**`(D)`** has a smaller left child than right child
**`(E)`** two or more of the above 
  
**30)** If an element in a binary heap is stored in position i and the root is at position 1, then where is the parent stored?
**`(A)`** $\lceil{i/2}\rceil$
**`(B)`** $\lfloor{i/2}\rfloor$
**`(C)`** $1 + \lfloor{i/2}\rfloor$
**`(D)`** $2*i$
**`(E)`** $2i + 1$
  
**31)** The running time of Build Heap is
**`(A)`**  `O(n)` worst case and `O(n)` average case
**`(B)`**  `O(n)` worst case and `O(log n)` average case
**`(C)`**  `O(n)` worst case and `O(n log n)` average case
**`(D)`**  `O(n log n)` worst case and `O(n)` average case
**`(E)`**  `O(n log n)` worst case and `O(n log n)` average case
  
**32)** n elements are inserted one by one into an initially empty binary heap. The total running time is
**`(A)`**  `O(n)` worst case and `O(n)` average case
**`(B)`**  `O(n)` worst case and `O(log n)` average case
**`(C)`**  `O(n)` worst case and `O(n log n)` average case
**`(D)`**  `O(n log n)` worst case and `O(n)` average case
**`(E)`**  `O(n log n)` worst case and `O(n log n)` average case
  
**33)** Which operation is not supported in constant time by a linked list with a head and tail pointer?
**`(A)`** Insertion as the front or rear item
**`(B)`** Access of the front or rear item
**`(C)`** Deletion of the front or rear item
**`(D)`** Access and deletion of the minimum item
**`(E)`** all of the above are supported
  
**34)** Which operation in a min heap cannot be done in at least $O(lg N)$ (efficient) time?
**`(A)`** Delete Min
**`(B)`** Find
**`(C)`** Find Min
**`(D)`** Insert
**`(E)`** All of the above are efficiently supported
  
**35)** Which data structure is best used to check for balanced parentheses?
**`(A)`** Binary search tree
**`(B)`** Hash table
**`(C)`** Priority queue
**`(D)`** Queue
**`(E)`** Stack
  
**36)** Jobs sent to a printer are generally placed on a:
**`(A)`** Binary search tree
**`(B)`** Hash table
**`(C)`** Priority queue
**`(D)`** Queue
**`(E)`** Stack
  
**37)** Which data structure is generally used to implement a symbol table (table that has a string that points to an address)?
**`(A)`** Binary search tree
**`(B)`** Hash table
**`(C)`** Priority queue
**`(D)`** Queue
**`(E)`** Stack
  
**38)** Which of the following could be used as an efficient priority queue?
**`(A)`** Binary search tree
**`(B)`** Hash table
**`(C)`** Linked list
**`(D)`** Array
**`(E)`** Stack
  
**39)** Which of the following does the binary heap implement?
**`(A)`** Binary search tree
**`(B)`** Hash table
**`(C)`** Priority queue
**`(D)`** Queue
**`(E)`** Stack
  
**40)** 6, 8, 4, 3, and 1 are inserted into a data structure in that order. An item is deleted using only a basic data structure operation. If the deleted item is a 1, the data structure cannot be a:
**`(A)`** Hash table
**`(B)`** Priority queue
**`(C)`** Queue
**`(D)`** Search tree
**`(E)`** Stack
  
**41)** Which data structure is used by the compiler to implement recursion?
**`(A)`** Hash table
**`(B)`** Priority queue
**`(C)`** Queue
**`(D)`** Search tree
**`(E)`** Stack
  
**42)** Which of the following data structures uses a sentinel value?
**`(A)`** Binary heap
**`(B)`** Hash table
**`(C)`** Queue
**`(D)`** Stack
**`(E)`** None of the above use sentinels
  
**43)** A node with key 8 has a left child with key 10. Which of the following objects could this node be found in?
**`(A)`** Binary search tree
**`(B)`** Max heap
**`(C)`** Min heap
**`(D)`** Two of the above
**`(E)`** None of A, B, and C
  
**44)** Bubble up and down are used for
**`(A)`** AVL trees
**`(B)`** B-trees
**`(C)`** Circular queue
**`(D)`** Binary heaps
**`(E)`** None of the above
  
**45)** Which of the following is a synonym for an edge?
**`(A)`** arc
**`(B)`** node
**`(C)`** path
**`(D)`** vertex
**`(E)`** none of the above
  
**46)** Which of the following does not use a queue?
**`(A)`** negative weighted shortest path algorithm
**`(B)`** positive weighted shortest path algorithm
**`(C)`** topological sort
**`(D)`** unweighted shortest path algorithm
**`(E)`** all of the above use a queue
  
**47)** Which of the following algorithms solves the unweighted single source shortest path problem?
**`(A)`** breadth first search
**`(B)`** depth first search
**`(C)`** Dijkstra's algorithm
**`(D)`** Kruskal's algorithm
**`(E)`** Prim's algorithm
  
**48)** Which of the following algorithms solves the positive weighted single source shortest path problem?
**`(A)`** breadth first search
**`(B)`** depth first search
**`(C)`** Dijkstra's algorithm
**`(D)`** Kruskal's algorithm
**`(E)`** Prim's algorithm
  
**49)** If the shortest path algorithm is run and a vertex is not reachable from the starting point, what happens?
  
**`(A)`** a distance of infinity is reported
**`(B)`** a distance of -1 is reported
**`(C)`** a distance of zero is reported
**`(D)`** the algorithm enters an infinite loop
**`(E)`** the algorithm's results are undefined
  
<img  src="https://www.lucidchart.com/publicSegments/view/d9366ca4-7836-49dc-83f9-406c5b356140/image.jpeg"  width="350">
  
**50)** The shortest weighted path from V4 to V5 has weight
**`(A)`** 2
**`(B)`** 4
**`(C)`** 7
**`(D)`** 8
**`(E)`** none of the above
  
**51)** If the start vertex is V4, then using the standard weighted shortest path algorithm, which is the last vertex to be declared known?
**`(A)`** V0
**`(B)`** V1
**`(C)`** V2
**`(D)`** V4
**`(E)`** none of the above
  
**52)** If the above graph were undirected, then what would be the cost of its minimum spanning tree?
**`(A)`** 1
**`(B)`** 10
**`(C)`** 11
**`(D)`** 12
**`(E)`** none of the above
  
**53)** Which algorithm is used to compute minimum spanning trees?
**`(A)`** breadth first search
**`(B)`** depth first search
**`(C)`** Dijkstra's
**`(D)`** Kruskal's
**`(E)`** Bellman Ford
  
**54)** What is the worst-case search time for finding a single item in an array?
**`(A)`** Constant time
**`(B)`** Logarithmic time
**`(C)`** Linear time
**`(D)`** Quadratic time
**`(E)`** Awesome time
  
**55)** What is the worst-case time for binary search finding a single item in an array?
**`(A)`** Constant time
**`(B)`** Logarithmic time
**`(C)`** Linear time
**`(D)`** Quadratic time
**`(E)`** Not possible in an Array

**55)** What is the worst-case time for binary search finding a single item in a doubly linked list?
**`(A)`** Constant time
**`(B)`** Logarithmic time
**`(C)`** Linear time
**`(D)`** Quadratic time 
**`(E)`** Not possible in a List
 
**56)** What additional requirement is placed on an array, so that binary search may be used to locate an entry?
**`(A)`** The array elements must form a heap.
**`(B)`** The array must have at least 2 entries.
**`(C)`** The array must be sorted.
**`(D)`** The array's size must be a power of two.
  
**57)** What is the best definition of a collision in a hash table?
**`(A)`** Two entries are identical except for their keys.
**`(B)`** Two entries with different data have the exact same key.
**`(C)`** Two entries with different keys have the same exact hash value.
**`(D)`** Two entries with the exact same key have different hash values.
  
**58)** Which guideline is NOT suggested from from empirical or theoretical studies of hash tables:
**`(A)`** Hash table size should be the product of two primes.
**`(B)`** Hash table size should be the upper of a pair of twin primes.
**`(C)`** Hash table size should be a factor of 2 , 5, or 10.
**`(D)`** Hash table size should not be too near a power of two.
**`(E)`** C and D should be avoided.
  
**59)** What kind of initialization needs to be done for an open-address hash table?
**`(A)`** None.
**`(B)`** The key at each array location must be initialized.
**`(C)`** The head pointer of each chain must be set to NULL.
**`(D)`** Both B and C must be carried out.
  
**60)** What kind of initialization needs to be done for an chained hash table?
**`(A)`** None.
**`(B)`** The key at each array location must be initialized.
**`(C)`** The head pointer of each chain must be set to NULL.
**`(D)`** Both B and C must be carried out.
  
**61)** A chained hash table has an array size of 512. What is the maximum number of entries that can be placed in the table?
**`(A)`** 256
**`(B)`** 511
**`(C)`** 512
**`(D)`** 1024
**`(E)`** There is no maximum.
  
**62)** Suppose you place m items in a hash table with an array size of s. What is the correct formula for the load factor?
**`(A)`** $s + m$
**`(B)`** $s - m$
**`(C)`** $m - s$
**`(D)`** $m * s$
**`(E)`** $m / s$

**63)** **T / F**: I can sort items in an array of numbers simply by inserting them into a binary tree and then removing the items 1 at a time from the root.

**64)** Which of the following is not a hash function that we discussed in class?
**`(A)`** Rotating hash
**`(B)`** Bernstein hash
**`(C)`** Modified Einstein hash
**`(D)`** Shift-Add-XOR hash
**`(E)`** Elf Hash

**65)** Huffman coding can be used for:
**`(A)`** Simple Text Compression
**`(B)`** Filtering
**`(C)`** Checksums / CRC Checks
**`(D)`** Error Correction
**`(E)`**  Check-hashbin Compression

**66)** Which algorithm is more greedy?
**`(A)`** Prim's
**`(B)`** Kruskel's
**`(C)`** Dijkstra's
**`(D)`** They're all greedy
**`(E)`**  None are greedy

**X)** The A-Star algorithm:
**`(A)`** Doesn't always find the shortest path
**`(B)`** Is based on Dijkstra's algorithm 
**`(C)`** Relies on a heuristics to make choices
**`(D)`** All of the above
**`(E)`** None of the above

**X)** The cost function in A-Star is calculated where cost = g() + h() where:
A) g() = distance_from_start ,  h() = distance_to_target
B) g() = total_cost ,  h() = current_cost
C) g() = current_cost ,  h() = total_cost
D) g() = a-star_cost,  h() = dijkstras_cost
E) None of the above