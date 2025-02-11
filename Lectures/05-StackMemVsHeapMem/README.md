## Stack Memory vs Heap Memory - A comparison

Typically when we declare variables, whatever type they are, they end up on the **Stack**, because
most of the variables we declare are **statically declared** (meaning they do NOT use the `new`
operator). When variables are declared during run time, they end up on the **Heap**. These variables
are **dynamically declared** and are treated differently. So, lets look at **Stack VS Heap**.

### The Run Time Stack

What is the *stack*? It’s a special region of your computer’s memory that stores temporary variables
created by each function (including the `main()` function). The *stack* is a **LIFO** (last in,
first out) data structure, that is managed and optimized by the CPU quite closely. Every time a
function declares a new variable, it is "pushed" onto the *stack*. Then every time a function exits,
**all** of the variables pushed onto the *stack* by that function, are freed (that is to say, they
are deleted). Once a *stack* variable is freed, that region of memory becomes available for other
*stack* variables.

The advantage of using the *stack* to store variables, is that memory is managed for you. You don’t
have to allocate memory by hand, or free it once you don’t need it any more. What’s more, because
the CPU organizes *stack* memory so efficiently, **reading from and writing to *stack* variables is very fast**.

A key to understanding the *stack* is the notion that **when a function exits**, all of its
variables are popped off of the *stack* (and hence lost forever). Thus *stack* variables are
**local** in nature. This is related to a concept we saw earlier known as `variable scope`, or
`local vs global variables`. One possible issue when dealing with *stack* variables is attempting to
access a variable created in a function from a place in your program outside of that function
(i.e. after that function has exited).

Another feature of the *stack* to keep in mind, is that there is a limit (varies with the OS) on the
size of variables that can be stored on the *stack*. This is not the case for variables allocated on
the **heap**.

**To summarize the stack:**

  - the *stack* grows and shrinks as functions push and pop local variables
  - there is no need to manage the memory yourself, variables are allocated and freed automatically
  - the *stack* has size limits
  - *stack* variables only exist while the function that created them is running

### The Heap

The *heap* is a region of your computer’s memory that is not managed automatically for you, and is
not as tightly managed by the CPU. It is a more free-floating region of memory (and is larger). To
allocate memory on the *heap* you must use:

  - In old C
      - To allocate memory: `malloc()` or `calloc()`
      - To deallocate memory: `free()`
  - In C++
      - To allocate memory: `new`
      - To deallocate memory: `delete`

Once you have allocated memory on the *heap*, **you are responsible for deallocating** that memory
once you don’t need it any more. If you fail to do this, your program will have what is known as a
**memory leak**. That is, memory on the *heap* will still be set aside (and won’t be available to
other processes).

Unlike the *stack*, the *heap* does not have size restrictions on variable size (apart from the
obvious physical limitations of your computer). *Heap* memory is slightly slower to be read from and
written to, because one has to use **pointers** to access memory on the *heap*.

Unlike the *stack*, **variables created on the *heap* are accessible by any function, anywhere in
your program**. Heap variables are essentially global in scope.

## Stack vs Heap Pros and Cons

### Stack

  - very fast access
  - don’t have to explicitly de-allocate variables
  - space is managed efficiently by CPU, memory will not become fragmented
  - local variables only
  - limit on *stack* size (OS-dependent)
  - variables cannot be resized

### Heap

  - variables can be accessed globally
  - no limit on memory size
  - (relatively) slower access
  - no guaranteed efficient use of space, memory may become fragmented over time as blocks of memory
    are allocated, then freed
  - you must manage memory (you’re in charge of allocating (`new`) and freeing (`delete`) variables)
  - ~~variables can be resized using `realloc()`~~ Only in C (not C++) when using `malloc()`. C++
    has things like `vectors` that grow and shrink for us.

## Examples

Here is a typical program that uses `stack` variables:

``` cpp
#include <iostream>

using namespace std;

double multiplyByTwo (double input) {
  double twice = input * 2.0;
  return twice;
}

int main (int argc, char *argv[])
{
  int age = 30;
  double salary = 12345.67;
  double myList[3] = {1.2, 2.3, 3.4};

  cout<<"double your salary is "<<multiplyByTwo(salary)<<"\n";


  return 0;
}
```

``` cpp
double your salary is 24691.340
```

In the main function: an `int`, a `double`, and an array of three doubles are declared. These three
variables are pushed onto the *stack* as soon as the `main()` function allocates them. When the
`main()` function exits (and the program stops) these variables are popped off of the *stack*.
Similarly, in the function `multiplyByTwo()`, the `twice` variable, which is a `double`, is pushed
onto the *stack* as soon as the `multiplyByTwo()` function allocates it. As soon as the
`multiplyByTwo()` function exits, the `twice` variable is popped off of the *stack*, and is gone
forever.

As a side note, there is a way to tell C++ to keep a *stack* variable around, even after its creator
function exits, and that is to use the `static` keyword when declaring the variable. A variable
declared with the `static` keyword thus becomes something like a global variable, but one that is
only visible inside the function that created it. It’s a strange construction, one that you probably
won’t need except under very specific circumstances.

Here is another version of this program that allocates all of its variables on the **heap** instead
of the *stack*:

``` cpp
#include <iostream>

using namespace std;

double *multiplyByTwo (double *input) {
  double *twice = new double;
  *twice = *input * 2.0;
  return twice;
}

int main (int argc, char *argv[])
{
  int *age = new int;
  *age = 30;
  double *salary = new double;
  *salary = 12345.67;
  double *myList = new double[3];
  myList[0] = 1.2;
  myList[1] = 2.3;
  myList[2] = 3.4;


  cout<<"double your salary is "<<multiplyByTwo(salary)<<"\n";

  delete age;
  delete salary;
  delete myList;

  return 0;
}
```

As you can see, using `new` to allocate memory on the *heap* and then using `delete` to deallocate
it, is no big deal, but is a bit cumbersome. The other thing to notice is that there is a bunch of
dereferencing going on `*`s everywhere.  
As we should know, `new` and `delete` deal with **pointers** not actual values.

## When to use the Heap?

When should you use the *heap*, and when should you use the *stack*? If you need to allocate a large
block of memory (e.g. a large array, or a big struct), and you need to keep that variable around a
long time (like a global), then you should allocate it on the *heap*. If you are dealing with
relatively small variables that only need to persist as long as the function using them is alive,
then you should use the *stack*, it’s easier and faster. If you need variables like arrays and
structs that can change size dynamically (e.g. arrays that can grow or shrink as needed) then you
will likely need to allocate them on the *heap*, and use dynamic memory allocation `new` along with
`delete` to manage that memory “by hand”.


## Chat GPT's Explanation 

### Stack vs. Heap

Imagine your program's memory as a vast warehouse. Within this warehouse, there are two main sections: the Stack and the Heap.

#### The Stack
- **Visual**: Think of the Stack as a stack of trays in a cafeteria. Each tray represents a function call in your program. When a new function is called, a new tray is placed on top with all the utensils (local variables) needed for your meal (function). Once you're done eating (the function returns), the tray is removed, and everything on it is gone.
- **Characteristics**:
  - **Fast Access**: Placing and removing trays is quick, much like how accessing local variables is faster.
  - **Automatic Management**: Just like how cafeteria staff manage trays, the Stack is automatically managed by the system. When a function exits, its stack frame (tray) is popped off, and all its variables are gone.
  - **Limited Size**: There's only so much space for trays. The Stack has a limited size, and overloading it leads to a stack overflow.

#### The Heap
- **Visual**: Now, picture the Heap as a vast storage room in the warehouse with lots of shelves. You can rent a shelf (allocate memory) for your stuff (dynamic variables) for as long as you need it.
- **Characteristics**:
  - **Flexible Size**: You can rent as much space as you need, unlike the fixed stack of trays. This is like dynamic memory allocation in the Heap.
  - **Manual Management**: Unlike the trays, you're responsible for returning the shelf space (deallocating memory). If you forget, your stuff piles up, leading to clutter (memory leaks).
  - **Slower Access**: It takes longer to find and access your stuff among the shelves compared to grabbing the top tray from the Stack.

### Memory Leaks and Management

In C++, when you allocate memory on the Heap using `new`, it's like renting shelf space. If you forget to `delete` it, you're not giving the space back, leading to a memory leak. It's like renting a storage unit and never returning the key. Over time, the warehouse (Heap) gets filled with unused stuff, affecting the program.

### Garbage Collection

In languages like Java or Python, there's an employee in the warehouse (garbage collector) who checks for unneeded items (unreferenced objects) and cleans them up. C++, however, expects you to clean up after yourself.

### Why "Heap"?

The term "Heap" in memory context isn't directly related to the Heap data structure (like in a priority queue). The name "Heap" historically refers to a "pile" or "mass" of memory where things can be dynamically allocated, without the structured order of a stack. It's like a heap of things piled up randomly, not a neatly arranged stack.

The Heap data structure, used in priority queues, is called a "heap" because it can be visualized as a "heap" or "tree" where parents dominate the values of their children, maintaining a specific order. The naming overlap is coincidental and can indeed be confusing.

### ASCII Art Visualization

```c++
[ The Program's Memory Warehouse ]

+-----------------------------------+---------------------+
|               Stack               |        Heap         |
+-----------------------------------+---------------------+
| Function Call 3 (tray)            |                     |
| - Local Var 3.1 (fork)            |     [Shelf 1]       |
| - Local Var 3.2 (knife)           | - Dynamic Var A     |
+-----------------------------------+---------------------+
| Function Call 2 (tray)            |     [Shelf 2]       |
| - Local Var 2.1 (spoon)           | - Dynamic Var B     |
+-----------------------------------+---------------------+
| Function Call 1 (tray)            |     ...             |
| - Local Var 1.1 (napkin)          |                     |
+-----------------------------------+---------------------+
| Main Function (bottom tray)       |                     |
| - Local Var 1 (plate)             |     [Shelf N]       |
+-----------------------------------+---------------------+  (Entrance)
|                                   | - Dynamic Var Z     |
+-----------------------------------+---------------------+
```

In this warehouse, trays (function calls) are stacked neatly on the left (Stack), while shelves (dynamic memory) on the right (Heap) can be rented as needed. Remember to return your trays and clean up your shelf space to keep the warehouse running smoothly!


## Links

  - [The Stack and the Heap](http://www.learncpp.com/cpp-tutorial/79-the-stack-and-the-heap/)
  - [What and Where are the stack and
    heap](http://stackoverflow.com/questions/79923/what-and-where-are-the-stack-and-heap)

-----

<sub>source: Paul Gribble https://gribblelab.org/CBootCamp/7\_Memory\_Stack\_vs\_Heap.html</sub>
