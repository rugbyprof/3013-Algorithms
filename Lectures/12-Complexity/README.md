## Scary Big O Notation

You're a computer scientist. And when you're asked to solve a problem you want to do it correctly
and efficiently. You want to pick the right algorithm for the job AND you want to run as fast as
possible (some times). Speed isn't always the answer, sometimes space matters, and other times
it really may just be understandability of your solution. Its all relative. What I do know is that
you will have to understand (at least to some degree) how to evaluate your own code, and its cost.
It's not something you will do everyday, but a working knowledge will help. SO! Evaluating your own 
code and comparing different algorithms is essential for any computer scientist.

How do we compare algorithms? Well we use Big Oh (scary big oh, and some others).

> In a few words: **Big O Notation is a convenient way to express the worst-case scenario for an algorithm**

### Related Asymptotic Notations

Big O is the most commonly used asymptotic notation for comparing algorithms, but there are the two
most often used notations aside from the big *O* notation.

#### Big Omega Ω

- Formal Definition: `f(n) is Ω(g(n)) iff for some constants c and N₀, f(N) ≥ cg(N) for all N > N₀`
- It represents the **lower bound**. Therefore, It doesn’t help much.
- `Ω(N)` means it takes at least `N` steps.

### Big Theta Θ 

- `f(n) is Θ(g(n)) iff f(n) is O(g(n)) and f(n) is Ω(g(n))`
- It represents the **lower bound** and the **upper bound** of an algorithm. 
- It’s hard to compute.
- `Θ(N)` means it takes at least `N` and at most `N` steps.

### Big Oh O 

- `f(n) is O(g(n)) iff for some constants c and N₀, f(N) ≤ cg(N) for all N > N₀`
- It represents the **upper bound** of an algorithm. 
- Big-oh is the most useful because represents the worst-case behavior.
- So, it guarantees that the program will terminate within a certain time period, it may stop earlier, but never later.
- `O(N)` means it takes at most `N` steps.

## What is the relationship between Big O, Θ, Ω and best, worst, and average case of an algorithm? 

|       |
|:-----:|
| <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/complexity_compared_2020.png" width="400"> |
| Relationships between Big O, Little O, Omega & Theta | 

We need asymptotic notations to describe the **best**, **average**, or **worst case** (types of analysis) of an algorithm. So we use our little greek friends to do just that. In summary:
- `big Ω` or the lower bound is used to analyze the **best** an algorithm performs.  
- `big O` or the upper bound is used to analyze the **worst** an algorithm will perform.
  - `little o` actually a nice overview of little o [here](https://stackoverflow.com/questions/1364444/difference-between-big-o-and-little-o-notation). 
- `big Θ` is an upper AND lower bound and actually gives us the best overall analysis, but its harder (and not always necessary) to calculate.

As an example, worst case analysis gives the maximum number of operations assuming that the input is in the worst possible state, while the `big O` notation express the max number of operations done in the worst case.

Although `big O` notation has nothing to do with the worst case analysis, we usually represent the worst case by `big O` notation. So, you can analyse just fine without `big O` notation.

> For example, the time complexity of `Mergesort` in the worst case is `Θ(n log n)`. This means in the worst case analysis, `Mergesort` will make roughly `n log n` operations.

> Another example, In the average case analysis, we can use the big o notation to express the number of operations in the worst case. So, In binary search, the best case is `O(1)`, average and worst case is `O(log n)`.

In short, there is no kind of relationship of the type *“big O is used for worst case, Theta for average case”*. All types of notation can be (and sometimes are) used when talking about best, average, or worst case of an algorithm.

### Running Time Calculations 

There are several algorithms we could use, and probably the best way to decide which is faster is to code them and run!. But, we would like to eliminate the bad ones early. So, analysis is usually required. - 

Analysis also helps us to design efficient algorithms.

#### A Simple Example 

```cpp
  int sum (int n) {
1     int totalSum = 0;
2     for( int i = 0; i < n; i++)
3        totalSum+= i;
4     return totalSum;
  }
```
- The analysis for this piece of code is simple. 
  - **Lines 1 and 4** count for one unit of time each.
  - **Line 2** counts for one unit for initializing, `N + 1` for the tests, and `N` for the increments. 
    - The test is executed `N + 1` times, where the last time is when the condition is false.
    - The increment is executed `N` times. So, the total cost is `2N + 2`.
  - **Line 3** counts for 2 units; one addition and one assignment, and it’s executed `N` times, for a total of `2N` units.
  - Therefore, we have **2 + 2N + 2 + 2N = 4N + 4** (which is really `O(N)` see below).

### Simplify The Analysis

- To simplify the analysis, fortunately, since we are going to use the `Big O` notation, there are a lot of shortcuts we can make. We are going to throw away any constants, and also low-order terms.
- The [terms](http://en.wikipedia.org/wiki/Term_%28mathematics%29#Elementary_mathematics) are basically the things separated by plus / minus symbols.
- We are going to drop the **+4** , because it’s obviously lower than **4N** (that’s the low-order term), and also throw any constants. So, we will end up having a complexity of **O(N)** , instead of
**O(4N + 4)** .

> If the constant is large, (like `10⁵`) it is good practice to give this constant a name and to include it in the asymptotic notation. 
> So, a program counts for `10⁵ * N` units would have complexity of `O(K * N)`.
> In the above example `4N` is not something big enough to earn its own constant.

This was a simple example to get up and running. But, there are some other general rules to follow when analyzing our code.

## General Rules

### 1. Loops

The running time of the loop is at most the running time of the statements inside the loop (including the tests) multiplied by the number of iterations.

As an example, the following program has complexity of O(N).

```cpp
for( int i = 0; i < n; i++)
   k++;                      // This statement will run N times.
```

### 2. Nested Loops

The total running time of the nested loops is the running time of the outer loop multiplied by the inner loop(s).

Let’s try the other way; Analyze Inside out.

The total running time of a statement inside a group of nested loops is the running time of that
statement multiplied by the product of the sizes of all the loops.

As an example, the following program has complexity of O(N²).

```cpp
for( int i = 0; i < n; i++)
    for( int j = 0; j < n; j++)
        k++;                   // This statement will run N^2 times.
```

**3. Consecutive Statements**

When there are consecutive statements, we count the statement with maximum complexity.

As an example, the following program which has O(N), followed by O(N²), has complexity of O(N²).

```cpp
for( int i = 0; i < n; i++)       // O(N)
   k++;for( int i = 0; i < n; i++)       // O(N^2)
    for( int j = 0; j < n; j++)
        k++;                   
```

**4. If-Else**

The running time is never more than the running time of the test(s) plus the running time of the
block with maximum complexity.

```cpp
if (condition)
   block 1
else if (condition)
   block 2
else
   block 3
```

**5. Simple Statements**

Return statements, initialize a variable, increment , assigning, …etc. All of these operations
counted in O(1).

## Big O Pitfalls

Since Big O Notation tells us about the upper bound of an algorithm ignoring constants and low-order
terms. An algorithm may have exact number of steps in the worst case more or less than the Big O
notation.

### Exact Steps > Big O

An algorithm takes 5 * N steps has complexity of O(N) in the worst case, which is smaller than the
exact number of steps.

```cpp
for(i = 0; i < 5*n; i++ )
    k++;
```

### Exact Steps < Big O

As an example, if we have a loop with `N = 10⁹` iterations, therefore it has complexity of `O(N)`, but, according to the nature of the data, the goal will always be found before `N` hits `10⁷`. 

```cpp
for(i = 0; i < n; i++ )
    if(arr[i] == goal) break;
```

Another example is, when the number of loops are decreasing by the time. So, first time it will loop `N, N-1, N-2, … , till 1`. The Big O notation for the following code is `O(N³)`, while the exact number of steps is much less than that.

```cpp
for (int i = 0; i < n; ++i)
    for (int j = i; j < n; ++j)
        for (int k = j; k < n; ++k)
            cunt++;
```

## Common Time Complexities

When speaking about the time/memory complexity of an algorithm, instead of using the formal
notation, we may simply state the class of an algorithm.

Here are some classes of the common time complexities.

|       |
|:-----:|
| <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/comparison_between_complexities_2020.png" width="500"> |
| Common Complexities | 

## Constant — O(1)

The algorithm does a [constant](https://en.wikipedia.org/wiki/Time_complexity#Constant_time) number of operations independent on the input.

```cpp
int start = 6;
int end = 100;int mid = (end — start) / 2;if(mid%2 == 0) mid--;
```

## Linear— O(N)

The running time of the algorithm increases linearly with the size of the input.

```cpp
for(i = 0; i < n; i++ )
    k++;
```

## Logarithmic— O(LogN)

The running time of the algorithm is decreased by some factor with each step. A very simple example of this type is an algorithm that keeps dividing the input by two. A [binary search](https://en.wikipedia.org/wiki/Binary_search_algorithm) algorithm follows the same rule.

```cpp
while(n > 0){
   n /= 2;
}
```

> The logarithm is base 2, that is, Log2 N.

## Linearithmic— O(N Log N)

The running time of the algorithm is as a result of performing a logarithmic operation N times.

For example, inserting N number of nodes inside a binary search tree. Each insertion takes O(LogN)
time, while the entire algorithm takes linearithmic time.

Also, the average case of [quick sort](https://en.wikipedia.org/wiki/Quicksort) ,[heap sort](https://en.wikipedia.org/wiki/Heapsort) , and [merge sort](https://en.wikipedia.org/wiki/Merge_sort) takes O(NLogN) time.

```cpp
int arr[n] = [1,6,3];for (int i = 0; i < n; ++i)
    binarySearchTree.insert(arr[i]);
```

### Square Root — O(sqrt(N))

The running time of the algorithm is decreased by the square root of the size of the input. As an example, you could check if a number is a prime or not by just looping till it’s square root.

```cpp
bool isPrime(int n) {
    if (n == 2)  
        return true;  
    if (n < 2)  
        return false;
    for (int i = 2; i <= sqrt(n); i ++)  
        if (n%i == 0) return false;  
    return true;
}
```

### Quadratic — O(N²)

The running time of the algorithm is as a result of performing a linear operation N times; So, it’s N multiplied by N. A common sorting algorithms like [bubblesort](https://en.wikipedia.org/wiki/Bubble_sort) , [selectionsort](https://en.wikipedia.org/wiki/Selection_sort) and [insertionsort](https://en.wikipedia.org/wiki/Insertion_sort) takes `O(N²)`.

```cpp
for( int i = 0; i < n; i++)
    for( int j = 0; j < n; j++)
        k++;
```

## Cubic— O(N³)

The running time of the algorithm is as a result of performing a linear operation N² times; So, it’s
N multiplied by N, multiplied by N.

```cpp
for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
        for (int k = 0; k < n; ++k)
            cunt++;
```

### Polynomial — O(N<sup>c</sup>)

The running time of the algorithm is as a result of performing a linear operation N<sup>(c-1)</sup> times, for some constant c, where `c > 1`.

In other words, The running time of the algorithm is a simple
[polynomial](https://translate.google.com/#en/ar/polynomial%20time) function of the size of the
input.

> Since polynomial has complexity of O(N^c), where c \> 1. Therefore, O(N²) is also a polynomial
> time.

```cpp
for( int i = 0; i < n; i++)
    for( int j = 0; j < n; j++)
        k++;
```

### Exponential— O(c^N)

The running time of the algorithm is a constant to the N power, where c \> 1. It’s common in
situations when you traverse all the nodes in a [binary
tree](https://en.wikipedia.org/wiki/Binary_tree) . The complexity would be exponential in depth;
O(2^(d+1)), which is O(2^d).

```cpp
void traverse(Node node){
    if (node == NULL){
        return;
    }
    
    print(node.value);    traverse(node.left);
    traverse(node.right);
}
```

### Factorial— O(N!)

The running time of the algorithm is factorial of N. It’s common in generating permutations. The
complexity would be the summation of N\!/K\!, where k = 0…N; O(N\!/0\! + N\!/1\! + …. + 1), which is
O(N\!).

```cpp
const int n = 3;
int arr[n] = [1, 2, 5], cur[n];
bool vis[n];void permutation(int i) {
    if (i == n){
        print(cur);
        return;
    }
    
    for (int j = 0; j < n; ++j){
        if (!vis[j]){
            vis[j] = 1;
            cur[i] = num[j];
        
            permutation(i + 1);
            vis[j] = 0;
        }
    }
}// This will print
// {1,2,5}, {1,5,2}, {2,1,5}, {2,5,1}, {5,1,2}, {5,2,1}
```

http://www.columbia.edu/~jxz2101/#1