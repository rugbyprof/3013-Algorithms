## Data Structures and ADTs

### What Are Data Structures

There are many definitions available.

  - A data structure is **an aggregation of data** components that together constitute a meaningful whole.  
  - A data structure is **a way of arranging data** in a computer’s memory or other disk storage.  
  - A data structure is **a collection of data** , organized so that items can be stored and retrieved by some fixed techniques.

There are several common data structures: arrays, linked lists, queues, stacks, binary trees, hash tables, graphs, etc.  These data structures can be classified as either *linear* or *nonlinear* data structures, based on how the data is conceptually organized or aggregated.

**Linear structures** .  The array, list, queue, and stack belong to this category.  Each of them is a collection that stores its entries in a linear sequence, and in which entries may be added or removed at will.  They differ in the restrictions they place on how these entries may be added, removed, or accessed.  The common restrictions include FIFO and LIFO.

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/linearvsnonlinear.png" width="400">

**Non-linear structures** .  Trees and graphs are classical non-linear structures. Data entries are not arranged in a sequence, but with different rules.



### What are abstract data types (ADT)?

Remember the goal of software development? `Robustness,  adaptability, and reusability` .  Out of this effort to write better code arose a new metaphor for  
using and building data structures: *abstract data type* , which   highlights the notion of *`abstractness `* .

When we say "data type", we often refer to the primitive data types built into a language, such as integer, real, character, and boolean. An integer, is most likely implemented or represented in four
bytes in the computer.  However, when we use integers, we do not worry at all about its internal representation, or how these operations are  
implemented by the compiler in machine code.  Additionally, we know that, even when we run our program on a different machine, the behavior of an integer does not change, even though its internal  
representation may change. What we know is that we can use primitive data types via their operational interface -- '+', '-', '*' and '/' for integers. The primitive data types were abstract  
entries.

A stack or a queue is an example of an ADT.  Both stacks and queues can be implemented using an array.  It is also possible to implement stacks and queues using linked lists.  This demonstrates the  
"abstract" nature of stacks and queues: how they can be considered separately from their implementation.

Applying the idea of abstraction to data structures, we have ADT for data structures. On the one hand, an ADT makes `a clean separation  between interface and implementation` , the user only sees the  
interface and therefore does not need to tamper with the  implementation.  On the other hand, if the implementation of an ADT  changes, the code that uses the ADT does not break, since the interface remains the same.  Thus, the abstraction makes the code `more robust and easier to maintain` .  Moreover, once an ADT is  built, it `may be used multiple times` in various contexts.  For example, the list ADT may be used directly in application code, or  may be used to build another ADT, such as a stack.

### How do I choose the right data structures?

- When writing a program, one of the first steps is determining or choosing the data structures.  
- What are the "right" data structures for the program?  
- The **interface of operations** supported by a data structure is one factor to consider when choosing between several available data structures.  
- Another important factor is the  **efficiency** of the data structure: how much *`space`* does the data structure occupy, and what are the *`running times`* of the operations in its  interface?

## Introduction to Algorithms

### What is an algorithm?

There are many definitions of algorithms. An algorithm is a procedure, *a finite set of well-defined instructions, for solving a  problem which, given an initial state, will terminate in a defined end-state*. The computational complexity and efficient implementation of the algorithm are important in computing, and this depends on suitable data structures.

#### Classification of Design Techniques:
  - Recursive  
  - Brute-Force  
  - Divide-and-Conquer  
  - Depth First  
  - Breadth First  
  - Backtracking  
  - Greedy -- local optimal  
  - Branch and Bound

**Algorithm Expression** : There are many different ways to express  
an algorithm, including natural language, pseudocode, flowcharts, and programming languages. **Natural language** expressions of algorithms  
tend to be verbose and ambiguous, and are rarely used for complex or  technical algorithms. **Pseudocode** and **flowcharts** are structured  
ways to express algorithms that avoid many of the ambiguities common in natural language statements, while remaining independent of a  
particular implementation language. *Programming languages* are  primarily intended for expressing algorithms in a form that can be executed by a computer, but are often used as a way to define or  
document algorithms.

### Program efficiency: time vs. space

It is interesting to know how much of a particular resource (such as time or storage) is required for a given algorithm.  Methods have been developed for the  
**analysis of algorithms** to obtain such quantitative answers, such as the `big O notation` . For example, the time needed for traversing an array of `n` slots is  
proportional to `n` , and we say the time is in the order of `O(n)`.  However, accessing the `i` th element in an array takes only constant time, which is independent of the size of the array, thus is in the order of `O(1)`.

### Running Time Notation Definitions:

Common functions used in analysis:

  - Constant function `f(n) = C` -- Constant algorithm does not depend on the input size. 
  - Logarithm function `f(n) = log n` -- Logarithm function gets slightly slower as `n` grows. 
  - Linear function `f(n) = n` -- Whenever `n` doubles, so does the running time. 
  - N-Log-N function `f(n) = n log n` -- It grows a little faster than the linear function.  
  - Quadratic function `f (n) = n`<sup>2</sup> -- Whenever `n` doubles, the running time increases fourfold.
  - Cubic Function and Other Polynomials  
  - Exponential Function `f(n) = b`<sup>n</sup>  
  - Factorial Function `f(n) = n!`

**The Development Process (not necessarily in order):**

  - Specification of the task  
  - Design of a solution  
  - Implementation (coding) of the solution  
  - Analysis of the solution  
  - Testing and debugging  
  - Maintenance

### Analysis

Time analysis vs. space analysis.
Worst-case, average-case and best-case analyses.

### Testing

To serve as good test data, your test inputs need two properties:

1. You must know `what output a correct program should produce` for each test input.  
2. The test inputs should include those `inputs that are most likely to cause errors` .

How to find test data that are most likely to cause errors? Try to  **test boundary values** , which are particularly apt to cause errors, and extreme values. A boundary value of a problem is an input that is one step away from a different kind of behavior.

**Fully exercising code** : make sure that each line of your code is executed at least once by some of your test data. If there is part of your code that is sometimes skipped altogether, make sure there is at least one test input that actually does skip this part of your code.

<sup>source: https://www.cpp.edu/~ftang/courses/CS241/notes/intro.htm</sup>
