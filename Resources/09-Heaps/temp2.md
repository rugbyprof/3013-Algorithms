::: {#navbar .navbar .navbar-default .navbar-fixed-top role="navigation"}
::: {.container}
::: {.navbar-header}
[toggle navbar]{.icon-bar aria-label="navbar toggle"} []{.icon-bar}
[]{.icon-bar}

<div>

[ ](/runestone/default/user/login){.brand-logo}
[pythonds](../index.html){.navbar-brand}

</div>
:::

::: {.navbar-collapse .collapse .navbar-ex1-collapse}
-   
-   [*[Social]{.visuallyhidden
    aria-label="Social"}*](#){.dropdown-toggle}
    -   <div>

        **Runestone in social media:**

        </div>

        [Follow
        \@iRunestone](https://twitter.com/iRunestone){.twitter-follow-button}
        ::: {.fb-like data-href="https://www.facebook.com/RunestoneInteractive" send="false" layout="button_count" data-width="300" show-faces="false" font="arial"}
        :::

    -   

    -   <div>

        **Help support us:**

        </div>

        <div>

        ![](https://www.paypalobjects.com/en_US/i/scr/pixel.gif){width="1"
        height="1"}

        </div>
-   
-   [*[Search]{.visuallyhidden
    aria-label="Search"}*](#){.dropdown-toggle}
    -   [Table of Contents](../index.html)

    -   [Book Index](../genindex.html)

    -   

    -   ::: {.input-group}
        :::
-   
-   [*[User]{.visuallyhidden aria-label="User"}*](#){.dropdown-toggle}
    -   []{.loggedinuser}

    -   

    -   [Assignments](/runestone/assignments/chooseAssignment.html)

    -   [Practice](/runestone/assignments/practice)

    -   

    -   [Change Course](/runestone/default/courses)

    -   

    -   [[Instructor\'s
        Page](/runestone/admin/index)]{#ip_dropdown_link}

    -   [Progress Page](/runestone/dashboard/studentreport)

    -   

    -   [Edit Profile](/runestone/default/user/profile){#profilelink}

    -   [Change
        Password](/runestone/default/user/change_password){#passwordlink}

    -   [Register](/runestone/default/user/register){#registerlink}

    -   [Login](#)

    -   ::: {.slider .round}
        :::

        Dark Mode
-   
-   [[*[Scratch Activecode]{.visuallyhidden
    aria-label="Scratch Activecode"}*](javascript:ACFactory.toggleScratchActivecode())]{#scratch_ac_link}
-   
-   [*[Help]{.visuallyhidden aria-label="Help"}*](#){.dropdown-toggle}
    -   [FAQ](http://runestoneinteractive.org/pages/faq.html)
    -   [Instructors
        Guide](https://runestone.academy/runestone/static/instructorguide/index.html)
    -   
    -   [About Runestone](http://runestoneinteractive.org)
    -   [Report A
        Problem](/runestone/default/reportabug?course=pythonds&page=BinaryHeapImplementation)
-   

```{=html}
<!-- -->
```
-   
-   [This Chapter](../index.html){.dropdown-toggle}
    -   [7.1 Objectives](Objectives.html){.reference .internal}
    -   [7.2 Examples of Trees](ExamplesofTrees.html){.reference
        .internal}
    -   [7.3 Vocabulary and
        Definitions](VocabularyandDefinitions.html){.reference
        .internal}
    -   [7.4 List of Lists
        Representation](ListofListsRepresentation.html){.reference
        .internal}
    -   [7.5 Nodes and References](NodesandReferences.html){.reference
        .internal}
    -   [7.6 Parse Tree](ParseTree.html){.reference .internal}
    -   [7.7 Tree Traversals](TreeTraversals.html){.reference .internal}
    -   [7.8 Priority Queues with Binary
        Heaps](PriorityQueueswithBinaryHeaps.html){.reference .internal}
    -   [7.9 Binary Heap
        Operations](BinaryHeapOperations.html){.reference .internal}
    -   [7.10 Binary Heap
        Implementation](BinaryHeapImplementation.html){.reference
        .internal}
    -   [7.11 Binary Search Trees](BinarySearchTrees.html){.reference
        .internal}
    -   [7.12 Search Tree
        Operations](SearchTreeOperations.html){.reference .internal}
    -   [7.13 Search Tree
        Implementation](SearchTreeImplementation.html){.reference
        .internal}
    -   [7.14 Search Tree Analysis](SearchTreeAnalysis.html){.reference
        .internal}
    -   [7.15 Balanced Binary Search
        Trees](BalancedBinarySearchTrees.html){.reference .internal}
    -   [7.16 AVL Tree Performance](AVLTreePerformance.html){.reference
        .internal}
    -   [7.17 AVL Tree
        Implementation](AVLTreeImplementation.html){.reference
        .internal}
    -   [7.18 Summary of Map ADT
        Implementations](SummaryofMapADTImplementations.html){.reference
        .internal}
    -   [7.19 Summary](Summary.html){.reference .internal}
    -   [7.20 Key Terms](KeyTerms.html){.reference .internal}
    -   [7.21 Discussion Questions](DiscussionQuestions.html){.reference
        .internal}
    -   [7.22 Programming Exercises](Exercises.html){.reference
        .internal}
-   
-   
:::
:::
:::

::: {#continue-reading .container}
:::

::: {#main-content .container role="main"}
::: {#binary-heap-implementation .section}
7.10. Binary Heap Implementation[¶](#binary-heap-implementation "Permalink to this headline"){.headerlink}
==========================================================================================================

::: {#the-structure-property .section}
7.10.1. The Structure Property[¶](#the-structure-property "Permalink to this headline"){.headerlink}
----------------------------------------------------------------------------------------------------

In order to make our heap work efficiently, we will take advantage of
the logarithmic nature of the binary tree to represent our heap. In
order to guarantee logarithmic performance, we must keep our tree
balanced. A balanced binary tree has roughly the same number of nodes in
the left and right subtrees of the root. In our heap implementation we
keep the tree balanced by creating a **complete binary tree**. A
complete binary tree is a tree in which each level has all of its nodes.
The exception to this is the bottom level of the tree, which we fill in
from left to right. [[Figure 1]{.std
.std-ref}](#fig-comptree){.reference .internal} shows an example of a
complete binary tree.

::: {#id1 .figure .align-center}
[]{#fig-comptree}![image](../_images/compTree.png)

[Figure 1: A Complete Binary
Tree]{.caption-text}[¶](#id1 "Permalink to this image"){.headerlink}
:::

Another interesting property of a complete tree is that we can represent
it using a single list. We do not need to use nodes and references or
even lists of lists. Because the tree is complete, the left child of a
parent (at position [\\(p\\)]{.math .notranslate .nohighlight}) is the
node that is found in position [\\(2p\\)]{.math .notranslate
.nohighlight} in the list. Similarly, the right child of the parent is
at position [\\(2p + 1\\)]{.math .notranslate .nohighlight} in the list.
To find the parent of any node in the tree, we can simply use Python's
integer division. Given that a node is at position [\\(n\\)]{.math
.notranslate .nohighlight} in the list, the parent is at position
[\\(n/2\\)]{.math .notranslate .nohighlight}. [[Figure 2]{.std
.std-ref}](#fig-heaporder){.reference .internal} shows a complete binary
tree and also gives the list representation of the tree. Note the
[\\(2p\\)]{.math .notranslate .nohighlight} and [\\(2p+1\\)]{.math
.notranslate .nohighlight} relationship between parent and children. The
list representation of the tree, along with the full structure property,
allows us to efficiently traverse a complete binary tree using only a
few simple mathematical operations. We will see that this also leads to
an efficient implementation of our binary heap.
:::

::: {#the-heap-order-property .section}
7.10.2. The Heap Order Property[¶](#the-heap-order-property "Permalink to this headline"){.headerlink}
------------------------------------------------------------------------------------------------------

The method that we will use to store items in a heap relies on
maintaining the heap order property. The **heap order property** is as
follows: In a heap, for every node [\\(x\\)]{.math .notranslate
.nohighlight} with parent [\\(p\\)]{.math .notranslate .nohighlight},
the key in [\\(p\\)]{.math .notranslate .nohighlight} is smaller than or
equal to the key in [\\(x\\)]{.math .notranslate .nohighlight}. [[Figure
2]{.std .std-ref}](#fig-heaporder){.reference .internal} also
illustrates a complete binary tree that has the heap order property.

::: {#id2 .figure .align-center}
[]{#fig-heaporder}![image](../_images/heapOrder.png)

[Figure 2: A Complete Binary Tree, along with its List
Representation]{.caption-text}[¶](#id2 "Permalink to this image"){.headerlink}
:::
:::

::: {#heap-operations .section}
7.10.3. Heap Operations[¶](#heap-operations "Permalink to this headline"){.headerlink}
--------------------------------------------------------------------------------------

We will begin our implementation of a binary heap with the constructor.
Since the entire binary heap can be represented by a single list, all
the constructor will do is initialize the list and an attribute
`currentSize`{.docutils .literal .notranslate} to keep track of the
current size of the heap. [[Listing 1]{.std
.std-ref}](#lst-heap1a){.reference .internal} shows the Python code for
the constructor. You will notice that an empty binary heap has a single
zero as the first element of `heapList`{.docutils .literal .notranslate}
and that this zero is not used, but is there so that simple integer
division can be used in later methods.

**Listing 1**

::: {.highlight-default .notranslate}
::: {.highlight}
    class BinHeap:
        def __init__(self):
            self.heapList = [0]
            self.currentSize = 0
:::
:::

The next method we will implement is `insert`{.docutils .literal
.notranslate}. The easiest, and most efficient, way to add an item to a
list is to simply append the item to the end of the list. The good news
about appending is that it guarantees that we will maintain the complete
tree property. The bad news about appending is that we will very likely
violate the heap structure property. However, it is possible to write a
method that will allow us to regain the heap structure property by
comparing the newly added item with its parent. If the newly added item
is less than its parent, then we can swap the item with its parent.
[[Figure 2]{.std .std-ref}](#fig-percup){.reference .internal} shows the
series of swaps needed to percolate the newly added item up to its
proper position in the tree.

::: {#id3 .figure .align-center}
[]{#fig-percup}![image](../_images/percUp.png)

[Figure 2: Percolate the New Node up to Its Proper
Position]{.caption-text}[¶](#id3 "Permalink to this image"){.headerlink}
:::

Notice that when we percolate an item up, we are restoring the heap
property between the newly added item and the parent. We are also
preserving the heap property for any siblings. Of course, if the newly
added item is very small, we may still need to swap it up another level.
In fact, we may need to keep swapping until we get to the top of the
tree. [[Listing 2]{.std .std-ref}](#lst-heap2){.reference .internal}
shows the `percUp`{.docutils .literal .notranslate} method, which
percolates a new item as far up in the tree as it needs to go to
maintain the heap property. Here is where our wasted element in
`heapList`{.docutils .literal .notranslate} is important. Notice that we
can compute the parent of any node by using simple integer division. The
parent of the current node can be computed by dividing the index of the
current node by 2.

We are now ready to write the `insert`{.docutils .literal .notranslate}
method (see [[Listing 3]{.std .std-ref}](#lst-heap3){.reference
.internal}). Most of the work in the `insert`{.docutils .literal
.notranslate} method is really done by `percUp`{.docutils .literal
.notranslate}. Once a new item is appended to the tree,
`percUp`{.docutils .literal .notranslate} takes over and positions the
new item properly.

**Listing 2**

::: {.highlight-default .notranslate}
::: {.highlight}
    def percUp(self,i):
        while i // 2 > 0:
          if self.heapList[i] < self.heapList[i // 2]:
             tmp = self.heapList[i // 2]
             self.heapList[i // 2] = self.heapList[i]
             self.heapList[i] = tmp
          i = i // 2
:::
:::

**Listing 3**

::: {.highlight-default .notranslate}
::: {.highlight}
    def insert(self,k):
        self.heapList.append(k)
        self.currentSize = self.currentSize + 1
        self.percUp(self.currentSize)
:::
:::

With the `insert`{.docutils .literal .notranslate} method properly
defined, we can now look at the `delMin`{.docutils .literal
.notranslate} method. Since the heap property requires that the root of
the tree be the smallest item in the tree, finding the minimum item is
easy. The hard part of `delMin`{.docutils .literal .notranslate} is
restoring full compliance with the heap structure and heap order
properties after the root has been removed. We can restore our heap in
two steps. First, we will restore the root item by taking the last item
in the list and moving it to the root position. Moving the last item
maintains our heap structure property. However, we have probably
destroyed the heap order property of our binary heap. Second, we will
restore the heap order property by pushing the new root node down the
tree to its proper position. [[Figure 3]{.std
.std-ref}](#fig-percdown){.reference .internal} shows the series of
swaps needed to move the new root node to its proper position in the
heap.

::: {#id4 .figure .align-center}
[]{#fig-percdown}![image](../_images/percDown.png)

[Figure 3: Percolating the Root Node down the
Tree]{.caption-text}[¶](#id4 "Permalink to this image"){.headerlink}
:::

In order to maintain the heap order property, all we need to do is swap
the root with its smallest child less than the root. After the initial
swap, we may repeat the swapping process with a node and its children
until the node is swapped into a position on the tree where it is
already less than both children. The code for percolating a node down
the tree is found in the `percDown`{.docutils .literal .notranslate} and
`minChild`{.docutils .literal .notranslate} methods in [[Listing 4]{.std
.std-ref}](#lst-heap4){.reference .internal}.

**Listing 4**

::: {.highlight-default .notranslate}
::: {.highlight}
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
:::
:::

The code for the `delmin`{.docutils .literal .notranslate} operation is
in [[Listing 5]{.std .std-ref}](#lst-heap5){.reference .internal}. Note
that once again the hard work is handled by a helper function, in this
case `percDown`{.docutils .literal .notranslate}.

**Listing 5**

::: {.highlight-default .notranslate}
::: {.highlight}
    def delMin(self):
        retval = self.heapList[1]
        self.heapList[1] = self.heapList[self.currentSize]
        self.currentSize = self.currentSize - 1
        self.heapList.pop()
        self.percDown(1)
        return retval
:::
:::

To finish our discussion of binary heaps, we will look at a method to
build an entire heap from a list of keys. The first method you might
think of may be like the following. Given a list of keys, you could
easily build a heap by inserting each key one at a time. Since you are
starting with a list of one item, the list is sorted and you could use
binary search to find the right position to insert the next key at a
cost of approximately [\\(O(\\log{n})\\)]{.math .notranslate
.nohighlight} operations. However, remember that inserting an item in
the middle of the list may require [\\(O(n)\\)]{.math .notranslate
.nohighlight} operations to shift the rest of the list over to make room
for the new key. Therefore, to insert [\\(n\\)]{.math .notranslate
.nohighlight} keys into the heap would require a total of [\\(O(n
\\log{n})\\)]{.math .notranslate .nohighlight} operations. However, if
we start with an entire list then we can build the whole heap in
[\\(O(n)\\)]{.math .notranslate .nohighlight} operations. [[Listing
6]{.std .std-ref}](#lst-heap6){.reference .internal} shows the code to
build the entire heap.

**Listing 6**

::: {.highlight-default .notranslate}
::: {.highlight}
    def buildHeap(self,alist):
        i = len(alist) // 2
        self.currentSize = len(alist)
        self.heapList = [0] + alist[:]
        while (i > 0):
            self.percDown(i)
            i = i - 1
:::
:::

::: {#id5 .figure .align-center}
[]{#fig-buildheap}![image](../_images/buildheap.png)

[Figure 4: Building a Heap from the List \[9, 6, 5, 2,
3\]]{.caption-text}[¶](#id5 "Permalink to this image"){.headerlink}
:::

[[Figure 4]{.std .std-ref}](#fig-buildheap){.reference .internal} shows
the swaps that the `buildHeap`{.docutils .literal .notranslate} method
makes as it moves the nodes in an initial tree of \[9, 6, 5, 2, 3\] into
their proper positions. Although we start out in the middle of the tree
and work our way back toward the root, the `percDown`{.docutils .literal
.notranslate} method ensures that the largest child is always moved down
the tree. Because the heap is a complete binary tree, any nodes past the
halfway point will be leaves and therefore have no children. Notice that
when `i=1`{.docutils .literal .notranslate}, we are percolating down
from the root of the tree, so this may require multiple swaps. As you
can see in the rightmost two trees of [[Figure 4]{.std
.std-ref}](#fig-buildheap){.reference .internal}, first the 9 is moved
out of the root position, but after 9 is moved down one level in the
tree, `percDown`{.docutils .literal .notranslate} ensures that we check
the next set of children farther down in the tree to ensure that it is
pushed as low as it can go. In this case it results in a second swap
with 3. Now that 9 has been moved to the lowest level of the tree, no
further swapping can be done. It is useful to compare the list
representation of this series of swaps as shown in [[Figure 4]{.std
.std-ref}](#fig-buildheap){.reference .internal} with the tree
representation.

::: {.highlight-default .notranslate}
::: {.highlight}
    i = 2  [0, 9, 5, 6, 2, 3]
    i = 1  [0, 9, 2, 6, 5, 3]
    i = 0  [0, 2, 3, 6, 5, 9]
:::
:::

The complete binary heap implementation can be seen in ActiveCode 1.

::: {.runestone .explainer .ac_section .alert .alert-warning childcomponent="completeheap"}
:::

The assertion that we can build the heap in [\\(O(n)\\)]{.math
.notranslate .nohighlight} may seem a bit mysterious at first, and a
proof is beyond the scope of this book. However, the key to
understanding that you can build the heap in [\\(O(n)\\)]{.math
.notranslate .nohighlight} is to remember that the
[\\(\\log{n}\\)]{.math .notranslate .nohighlight} factor is derived from
the height of the tree. For most of the work in `buildHeap`{.docutils
.literal .notranslate}, the tree is shorter than [\\(\\log{n}\\)]{.math
.notranslate .nohighlight}.

Using the fact that you can build a heap from a list in
[\\(O(n)\\)]{.math .notranslate .nohighlight} time, you will construct a
sorting algorithm that uses a heap and sorts a list in
[\\(O(n\\log{n}))\\)]{.math .notranslate .nohighlight} as an exercise at
the end of this chapter.
:::
:::

::: {#scprogresscontainer}
You have attempted []{#scprogresstotal} of []{#scprogressposs}
activities on this page

::: {#subchapterprogress}
:::
:::

-   [[](BinaryHeapOperations.html)]{#relations-prev}
    ::: {style="background-color: white; border-style:solid; border-color:lightgrey; border-width:2px; width:100px; height:50px"}
    :::

[](BinaryHeapOperations.html){#navLinkBgLeft .navLinkBg}

-   [[](BinarySearchTrees.html)]{#relations-next}
    ::: {style="background-color: white; border-style:solid; border-color:lightgrey; border-width:2px; width:100px; height:50px"}
    :::

[Next Section - 7.11. Binary Search
Trees](BinarySearchTrees.html){#navLinkBgRight .navLinkBg .navLink}
:::

::: {.container}
[]{#numuserspan}[]{.loggedinuser} \| [Back to top](#)

© Copyright 2014 Brad Miller, David Ranum. Created using
[Runestone](http://runestoneinteractive.org/) 4.2.1.
:::
