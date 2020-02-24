## Binary Heap Implementation

In this Heap overview, we assume **MIN** heap.

In order to make our heap work efficiently, we will take advantage of the logarithmic nature of the
binary tree to represent our heap. In order to guarantee logarithmic performance, we must keep our
tree balanced. A balanced binary tree has roughly the same number of nodes in the left and right
subtrees of the root. In our heap implementation we keep the tree balanced by creating a **complete
binary tree**. A complete binary tree is a tree in which each level has all of its nodes. The
exception to this is the bottom level of the tree, which we fill in from left to right. **Figure 1**
shows an example of a complete binary tree.

<center>

|                             **Figure 1**: A Complete Binary Tree                              |
| :-------------------------------------------------------------------------------------------: |
| <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/compTree_3013_2020.png"> |

</center>

Another interesting property of a complete tree is that we can represent it using a single list. We
do not need to use nodes and references or even lists of lists. - Because the tree is complete, the
left child of a parent (at position *P*) is the node that is found in position ***2P*** in the list.
- Similarly, the right child of the parent is at position ***2P + 1*** in the list. - To find the
parent of any node in the tree, we can simply use C++’s integer division. - Given that a node is at
position ***n*** in the list, the parent is at position ***n/2***. - Figure 2 shows a complete
binary tree and also gives the list representation of the tree. - Note the ***2P*** and ***2P + 1***
relationship between parent and children. - The list representation of the tree, along with the full
structure property, allows us to efficiently traverse a complete binary tree using only a few simple
mathematical operations. We will see that this also leads to an efficient implementation of our
binary heap.

## The Heap Order Property

The method that we will use to store items in a heap relies on maintaining the heap order property.
The **heap order property** is as follows: In a heap, for every node ***x*** with parent ***p***,
the key in ***p*** is smaller than or equal to the key in ***x***.

|                    Figure 2: A Complete Binary Tree w/ List Representation                     |
| :--------------------------------------------------------------------------------------------: |
| <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/heapOrder_3013_2020.png"> |

## Heap Operations

### Getting Setup

Since the entire binary heap can be represented by a single array (efficiently), we don’t need to
keep track of much. Remember that since a heap is ALWAYS a complete tree, we never have empty slots
between stored values in our array. We really only need to keep track of the ***next available
slot*** (or ***currentSize***).

Also, we start filling our array at ***index 1*** since using ***index 0*** would have bad results
when calculating *left, right, and parent.* The figure below shows the relationship between each binary tree entity when stored in an array. 

|                    Heap Container                   |
| :--------------------------------------------------------------------------------------------: |
| Empty Container - We don't use slot zero.
| <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.heap_array_2020.png"> |
| Looking at Left / Right / and Parent |
| <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.heap_array_2_2020.png"> |
| <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.heap_array_3_2020.png"> |

### Insert

The easiest, and most efficient, way to add an item to a heap is to simply append the item to the
next available slot in the array. The good news about this is that we will ALWAYS have a complete
tree! The bad news about appending is that we will very likely violate the heap structure property
(meaning we will have to re-arrange values).

Fixing any violations of the heap structure property can be done by comparing the newly added item
with its parent. If the newly added item is less than its parent, then we can swap the item with its
parent. The figure below shows the series of swaps needed to percolate the newly added item up to its proper position in the tree.

|                    Percolate the New Node up to Its Proper Position                    |
| :--------------------------------------------------------------------------------------------: |
| <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/percUp_3013_2020.png"> |
| <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.heap_array_5_2020.png"> |
| <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.heap_array_6_2020.png"> |


Notice that when we percolate an item up, we are restoring the heap property between the newly added
item and the parent. We are also preserving the heap property for any siblings. Of course, if the
newly added item is very small, we may still need to swap it up another level. In fact, we may need
to keep swapping until we get to the top of the tree. [<span class="std std-ref">Listing
2</span>](#lst-heap2) shows the `percUp` method, which percolates a new item as far up in the tree
as it needs to go to maintain the heap property. Here is where our wasted element in `heapList` is
important. Notice that we can compute the parent of any node by using simple integer division. The
parent of the current node can be computed by dividing the index of the current node by 2.

We are now ready to write the `insert` method (see [<span class="std std-ref">Listing
3</span>](#lst-heap3)). Most of the work in the `insert` method is really done by `percUp`. Once a
new item is appended to the tree, `percUp` takes over and positions the new item properly.

**Listing 2**

    def percUp(self,i):
        while i // 2 > 0:
          if self.heapList[i] < self.heapList[i // 2]:
             tmp = self.heapList[i // 2]
             self.heapList[i // 2] = self.heapList[i]
             self.heapList[i] = tmp
          i = i // 2

**Listing 3**

    def insert(self,k):
        self.heapList.append(k)
        self.currentSize = self.currentSize + 1
        self.percUp(self.currentSize)

With the `insert` method properly defined, we can now look at the `delMin` method. Since the heap
property requires that the root of the tree be the smallest item in the tree, finding the minimum
item is easy. The hard part of `delMin` is restoring full compliance with the heap structure and
heap order properties after the root has been removed. We can restore our heap in two steps. First,
we will restore the root item by taking the last item in the list and moving it to the root
position. Moving the last item maintains our heap structure property. However, we have probably
destroyed the heap order property of our binary heap. Second, we will restore the heap order
property by pushing the new root node down the tree to its proper position.
[<span class="std std-ref">Figure 3</span>](#fig-percdown) shows the series of swaps needed to move
the new root node to its proper position in the heap.

<span id="fig-percdown"></span>![image](https://runestone.academy/runestone/books/published/pythonds/_images/percDown.png)

<span class="caption-text">Figure 3: Percolating the Root Node down the
Tree</span>[¶](#id4 "Permalink to this image")

In order to maintain the heap order property, all we need to do is swap the root with its smallest
child less than the root. After the initial swap, we may repeat the swapping process with a node and
its children until the node is swapped into a position on the tree where it is already less than
both children. The code for percolating a node down the tree is found in the `percDown` and
`minChild` methods in [<span class="std std-ref">Listing 4</span>](#lst-heap4).

**Listing 4**

    def percDown(self,i):
        while (i * 2) <= self.currentSize:
            mc = self.minChild(i)
            if self.heapList[i] > self.heapList[mc]:
                tmp = self.heapList[i]
                self.heapList[i] = self.heapList[mc]
                self.heapList[mc] = tmp
            i = mc
    
    def minChild(self,i):
        if i * 2 + 1 > self.currentSize:
            return i * 2
        else:
            if self.heapList[i*2] < self.heapList[i*2+1]:
                return i * 2
            else:
                return i * 2 + 1

The code for the `delmin` operation is in [<span class="std std-ref">Listing 5</span>](#lst-heap5).
Note that once again the hard work is handled by a helper function, in this case `percDown`.

**Listing 5**

    def delMin(self):
        retval = self.heapList[1]
        self.heapList[1] = self.heapList[self.currentSize]
        self.currentSize = self.currentSize - 1
        self.heapList.pop()
        self.percDown(1)
        return retval

To finish our discussion of binary heaps, we will look at a method to build an entire heap from a
list of keys. The first method you might think of may be like the following. Given a list of keys,
you could easily build a heap by inserting each key one at a time. Since you are starting with a
list of one item, the list is sorted and you could use binary search to find the right position to
insert the next key at a cost of approximately
<span class="math notranslate nohighlight">\\(O(\\log{n})\\)</span> operations. However, remember
that inserting an item in the middle of the list may require
<span class="math notranslate nohighlight">\\(O(n)\\)</span> operations to shift the rest of the
list over to make room for the new key. Therefore, to insert
<span class="math notranslate nohighlight">\\(n\\)</span> keys into the heap would require a total
of <span class="math notranslate nohighlight">\\(O(n \\log{n})\\)</span> operations. However, if we
start with an entire list then we can build the whole heap in
<span class="math notranslate nohighlight">\\(O(n)\\)</span> operations.
[<span class="std std-ref">Listing 6</span>](#lst-heap6) shows the code to build the entire heap.

**Listing 6**

    def buildHeap(self,alist):
        i = len(alist) // 2
        self.currentSize = len(alist)
        self.heapList = [0] + alist[:]
        while (i > 0):
            self.percDown(i)
            i = i - 1

<span id="fig-buildheap"></span>![image](https://runestone.academy/runestone/books/published/pythonds/_images/buildheap.png)

<span class="caption-text">Figure 4: Building a Heap from the List \[9, 6, 5, 2,
3\]</span>[¶](#id5 "Permalink to this image")

[<span class="std std-ref">Figure 4</span>](#fig-buildheap) shows the swaps that the `buildHeap`
method makes as it moves the nodes in an initial tree of \[9, 6, 5, 2, 3\] into their proper
positions. Although we start out in the middle of the tree and work our way back toward the root,
the `percDown` method ensures that the largest child is always moved down the tree. Because the heap
is a complete binary tree, any nodes past the halfway point will be leaves and therefore have no
children. Notice that when `i=1`, we are percolating down from the root of the tree, so this may
require multiple swaps. As you can see in the rightmost two trees of
[<span class="std std-ref">Figure 4</span>](#fig-buildheap), first the 9 is moved out of the root
position, but after 9 is moved down one level in the tree, `percDown` ensures that we check the next
set of children farther down in the tree to ensure that it is pushed as low as it can go. In this
case it results in a second swap with 3. Now that 9 has been moved to the lowest level of the tree,
no further swapping can be done. It is useful to compare the list representation of this series of
swaps as shown in [<span class="std std-ref">Figure 4</span>](#fig-buildheap) with the tree
representation.

    i = 2  [0, 9, 5, 6, 2, 3]
    i = 1  [0, 9, 2, 6, 5, 3]
    i = 0  [0, 2, 3, 6, 5, 9]

The complete binary heap implementation can be seen in ActiveCode 1.

The assertion that we can build the heap in
<span class="math notranslate nohighlight">\\(O(n)\\)</span> may seem a bit mysterious at first, and
a proof is beyond the scope of this book. However, the key to understanding that you can build the
heap in <span class="math notranslate nohighlight">\\(O(n)\\)</span> is to remember that the
<span class="math notranslate nohighlight">\\(\\log{n}\\)</span> factor is derived from the height
of the tree. For most of the work in `buildHeap`, the tree is shorter than
<span class="math notranslate nohighlight">\\(\\log{n}\\)</span>.

Using the fact that you can build a heap from a list in
<span class="math notranslate nohighlight">\\(O(n)\\)</span> time, you will construct a sorting
algorithm that uses a heap and sorts a list in
<span class="math notranslate nohighlight">\\(O(n\\log{n}))\\)</span> as an exercise at the end of
this chapter.

You have attempted <span id="scprogresstotal"></span> of <span id="scprogressposs"></span>
activities on this page

  - <span id="relations-prev">[](BinaryHeapOperations.html)</span> ::: {style=“background-color:
    white; border-style:solid; border-color:lightgrey; border-width:2px; width:100px; height:50px”}
    :::

[](BinaryHeapOperations.html)

  - <span id="relations-next">[](BinarySearchTrees.html)</span> ::: {style=“background-color: white;
    border-style:solid; border-color:lightgrey; border-width:2px; width:100px; height:50px”} :::

[Next Section - 7.11. Binary Search Trees](BinarySearchTrees.html)

<span id="numuserspan"></span><span class="loggedinuser"></span> | [Back to top](#)

© Copyright 2014 Brad Miller, David Ranum. Created using
[Runestone](http://runestoneinteractive.org/) 4.2.1.
