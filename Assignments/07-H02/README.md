## Assignment 7 - Heapify Debacle
#### Due: 02-17-2020 (Monday @ 3:30 p.m.)

### Overview

#### Scene 1 - Griffin Crying Like a Baby

- Fun times in class. 
- It's a little daunting trying to incorporate everyone's ideas, listen to comments , type code, not make mistakes, evaluate recommendations, laugh at jokes, filter good and / or bad ideas ... And not F*** up. (F*** = Mess).
- It's always easy to blame the professor when your sitting quietly in the audience where it is easy to gather your thoughts.
- Having said that, **I'm stoked that so many individuals are contributing to lecture!**
- Why are some of you NOT on the programming team (or in my research group)??
- However, on the counter point, anyone want to take over coding ... please volunteer :) 

#### End Scene 1

#### Scene 2 - Griffin Threatens Class With Technology

- I will gladly break out the powerpoints (dust them off) and simply click through slide after slide of code.
- That is the easy way out on my end. 
- Go ahead ... dare me. I have HUNDREDS OF SLIDES :grimacing:


#### End Scene 2

#### Scene 3 - Griffin Pleads w/ the Masses
- Try to respect the fact that I put myself out there every class to give you guys the best I can offer. 
- Personally, I like the group solutions. I can only ask that everyone understand it is not easy behind the keyboard.
- Messing up on the whiteboard :) THATS ALL ON ME ... DAMMIT.
- ![Oops](https://media0.giphy.com/media/3ohs7Ys9J8XyFVheg0/giphy-downsized.gif?cid=6104955ef8d85af10ce744af57761567d8710d68becc9ffe&rid=giphy-downsized.gif)

#### End Scene 3

### Heap Operations

- https://en.wikipedia.org/wiki/Binary_heap which talks about methods in exactly the same terms as we did in class. 
- For example looking at extracting a value:

>The procedure for deleting the root from the heap (effectively extracting the maximum element in a max-heap or the minimum element in a min-heap) and restoring the properties is called down-heap (also known as *bubble-down, percolate-down, sift-down, sink-down, trickle down, heapify-down, cascade-down, and extract-min/max*).
- Sound familiar? Even Wikipedia can't give a single operation a definitive name! Basically, all of you should be focusing on not what "we call a method" but more so "what needs to happen". 
- For example: if I insert a value into a "heap", what operations must I perform to keep this structure in "heap" order.
- [Wikipedia](https://en.wikipedia.org/wiki/Binary_heap) and [NIST-Heap](https://xlinux.nist.gov/dads/HTML/heap.html) and [NIST-Heapify](https://xlinux.nist.gov/dads/HTML/heapify.html) do a good job in describing our problem.
- One caveat is that [wikipedias](https://en.wikipedia.org/wiki/Binary_heap) solution to a `Max-Heapify` solution is **recursive**! We discussed it as an iterative solution. Both are viable. Recursion is always cool, but not always efficient. 


### What 2 Fix:

- A working set of code is here: [heap_working.cpp](heap_working.cpp).
- The code we stopped with is here : [heap_from_class.cpp](heap_from_class.cpp)
- I commented the code from [heap_working.cpp](heap_working.cpp).
- The methods you need to fix are below in the code snippet:
- 


```cpp
    /**
     * 
     * @param  {int*} A   :  array pointer with unsorted values to make into a heap
     * @param  {int} size :  size of new heap
     */
    void Heapify(int A *, int size) {
        // do it!
    }

    /**
     * SinkDown
     * @description:
     *      Places one heap item into its proper place in the heap
     *      by bubbling it down to it proper location.
     * 
     * @param  {int} index  : index to start from in the array
     * @return              : void 
     */
    void SinkDown(int index) {
        //do stuff!
    }

    /**
     * PickChild
     * @description:
     *      If one child exists, return it.
     *      Otherwise, return the smaller of the two.
     * 
     * @param  {int} index  : index of parent in the array
     * @return              : index to child 
     */
    int PickChild(int index) {
        return 0; // temporary suppress of warning
    }
```



### Deliverables

- Create a folder called `H02` in your assignments folder.
- Put your code files in the folder.
- Upload to github sometime close to the due date.
- Print out your banner ON ITS OWN PAGE

```
H02
3013
LASTNAME
```
- Print out your version of the entire heap class and bring it to class.
- Make sure you put comments in the code, especially the main program comment block with your name etc.
