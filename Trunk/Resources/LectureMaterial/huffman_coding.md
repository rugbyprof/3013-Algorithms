## Huffman Coding

### Introduction
Huffman coding algorithm is a lossless data compression algorithm. It is a method of storing strings of data as binary code in an efficient manner. Huffman coding uses variable length codes to input characters, which means that characters in the data are converted to a binary symbols based on how often that character is used. The most frequently used character gets the smallest binary code and the least frequently used character gets the longest binary code.

The  variable-length codes that are assigned to the input characters are prefix codes. A binary code is called a **prefix code** if no code is a prefix of any other binary code. This is how Huffman coding avoids ambiguity while decoding.

For example, let us consider four characters **a**, **b**, **c** and **d**. Let their binary codes be **00**, **0**, **1** and **01**. We can observe that the binary code of character **b** is a prefix to binary code of characters **a** and **d**. So, if the encoded code is 00001 then the decoded code could be **"aac"**, **"abc"**, **"bbbbc"**, and so on.

### Problem Definition

***Input:***

A Set of characters usually an array with each character and the frequency of its repetition in it.

Let the set of characters be **A**= {a1, a2, a3, ..., an}  and

Set of their frequencies be **F**= {*f*1, *f*2, *f*3, ..., *f*n}.


***Output:***

Generating binary code for each character, finding the length of each character.
The length of each character is variable.

Let **BC**(**A**,**F**)= { c1, c2, c3, ..., cn} where c1, c2, c3, ..., cn are the binary codes.

### Structure and Algorithm
Huffman coding can be achieved by following steps:

1. To construct a tree from the input characters.
2. To assign the binary codes to the input characters.
3. And to decode the binary code of the strings.

***Constructing a tree from the given input characters:***

To construct a tree we need an input of characters along with their frequencies.

1. Imagine each character as a separate leaf node of a binary tree. 
2. Combine two smallest trees in order to form either a min heap or max heap.
3. Adding the frequencies of the two trees forms a new node. Make the least or first chosen node as left child and then the next one as right child.
4. Repeat this process until the min heap or max heap has one node left which will be the root node.

**Pseudo code for constructing a tree:**

```
Input: An array I[] of frequencies

Output: Binary tree with binary codes with n leaves

Huffman(I[1 to n])

(1) T= Empty binary tree
(2) Q= Priority Queues with pairs(i,I[i])
(3) foreach k= 1 to n-1
(4) i= extractMin(Q)
(5) j= extractMin(Q)
(6) I[n+k]= I[i] + I[j]
(7) insertNode(T, n+k) child i, j
(8) insertRear(Q,(n+k, I[n+k]))
(9) return T

```

Code in C++

```cpp
//Node comparision
if (b->frequency < a->frequency)
    return 1;
if (a->frequency < b->frequency)
    return 0;

// Node comparision if two symbols have same frequency
if (!a->leftChild && a->leftChild)
    return 1;
if (a->leftChild && !b->LeftChild)

    //Inserting Leaf nodes into priority queue
    while (start != end)
        Node *dNode = new Node(start->second, startnode->firstnode);
pqueue.push(dNode);
++start;

//Constructing the tree
while (!pqueue.empty())
{
    Node *top = pqueue.top();
    pqueue.pop();
    if (pqueue.empty())
    {
        tree = top;
    }
    else
    {
        Node *topnew = pqueue.top();
        pqueue.pop();
        pqueue.push(new Node(top, topnew));
    }
}
```

Let us consider an example:

![Table](https://github.com/rugbyprof/DataStructuresRepo/raw/master/HuffmanCoding/Images/Table.jpeg "Table")

Now represent each character as a leaf node as follows,

![Step 1](https://github.com/rugbyprof/DataStructuresRepo/raw/master/HuffmanCoding/Images/1.jpeg "Step 1")

Choose two least frequencies and combine them to form a new node. Here **a** and **d** have the least frequencies of 1 and 2 respectively. Combine them to form new node **3**. 

![Step 2](https://github.com/rugbyprof/DataStructuresRepo/raw/master/HuffmanCoding/Images/2.jpeg "Step 2")

Now the least nodes are node 3 and node **b**. Combine these two nodes. A new node **9** is formed.

![Step 3](https://github.com/rugbyprof/DataStructuresRepo/raw/master/HuffmanCoding/Images/3.jpeg "Step 3")

Now the least nodes are node **c** and node **e**. Adding them together  forms a new node, node **15**

![Step 4](https://github.com/rugbyprof/DataStructuresRepo/raw/master/HuffmanCoding/Images/4.jpeg "Step 4")

Combine the last two nodes to form the final node or the root node. Combining node **9** and node **15** forms a node **24**. The final tree is 

![Step 5](https://github.com/rugbyprof/DataStructuresRepo/raw/master/HuffmanCoding/Images/5.jpeg "Step 5")

As we have only one node left the algorithm stops here.

### Assigning binary codes to the input characters

There is way to decide what binary code to give each character using trees.

Now we can assign binary code to each symbol by going down the tree. The left branch of the tree receives a '**0**' and the right branch of the tree receives a '**1**'.

We use an array to store the binary codes of each character. On each movement insert the correct value in to the array.

The tree with binary codes assigned looks as below,

![Step 6](https://github.com/rugbyprof/DataStructuresRepo/raw/master/HuffmanCoding/Images/6.jpeg "Tree with binary codes assigned to each character")

Now the binary codes of the characters are

![Table for binary codes](https://github.com/rugbyprof/DataStructuresRepo/raw/master/HuffmanCoding/Images/7.jpeg "Table of binary codes")

Now the string "**abcde**" has the encoded value "**000011000111**"

```
	
//Assigning binary code to symbols
if (leftChild)
{
    prefix.push_back(0);
    leftChild->CodeFill(encoding, prefix);
    prefix.push() = 1;
    rightChild->codeFill(encoding, prefix);
    prefix.pop_back();
}
else
    encoding[*data] = prefix;

```


###Decoding the string with binary code:###

Considering the above binary code of string **abcde**, we decode this binary value.

The encoded binary code is "**000011000111**"

We assign the binary code to its character from the above table of binary codes.

**a** = 000

**b** = 01

**c** = 10

**d** = 001

**e** = 11

![](https://github.com/rugbyprof/DataStructuresRepo/raw/master/HuffmanCoding/Images/8.jpeg)

Thus the decode value is a string "**abcde**". The decoding is lossless.

Considering the same characters and their binary codes we decode another binary encoded value.

Let the encoded string be "**1011001000011101**"

![](https://github.com/rugbyprof/DataStructuresRepo/raw/master/HuffmanCoding/Images/Diagram7.jpeg)

The decoded string is "**cedabeb**".


```

//Decoding
void Decode(const &v, OutputIterator itr)
{
    Node *node = tree;
    for (const i = v.begin(); i != v.end(); i++)
    {
        node = *i ? node->rightChild : node->leftChild;
        if (!node->leftChild)
        {
            *itr++ = *(node->data);
            node = tree;
        }
    }
}

```

**Average Length of code word**

Average code word length is given by a mathematical representation

	Average code word length = (1/f(T)) * (sum of d(i)*f(i)) , for i = 0 to n.

where n= number of characters
*f*(T)= total frequency

*f*(i)= frequency of that character

d(i)= length of that symbol(character)

Average length of the example considered above:

=(1/(1+2+6+7+8))*((3*1)+(2*6)+(2*7)+(3*2)+(2*8))

=(1/24)*(3+12+1+6+16)

=(1/24)*(51)

=2.125 digits long (Average length in the code is encoded to 2.125 binary digits)

**Time Complexity**

The time complexity of huffman coding takes O(nlogn), where n is the number of characters. The extractMin and the insertRear require O(logn) time as if there are n characters then extractMin will be called 2^(n-1) times. This is exactly same as when extractMin calls the Heap.

**Advantages**

1. The algorithm is easy to implement.
2. Produces lossless compression of data.

**Disadvantages**

1. If the frequencies and probabilities change, optimal coding changes.
2. It does not consider blocks of symbols.

**References**

[http://en.wikipedia.org/wiki/Huffman_coding](http://en.wikipedia.org/wiki/Huffman_coding)
