## Scary Big O Notation

You're a computer scientist. And when you're asked to solve a problem you want to do it correctly and efficiently. You want to pick the right algorithm for the job AND you want to run as fast as possible (some times). Speed isn't always the answer, sometimes space matters, and other times it really may just be understandability of your solution. Its all relative. What I do know is that you will have to understand (at least to some degree) how to evaluate your own code, and its cost. It's not something you will do everyday, but a working knowledge will help. SO! Evaluating your own  code and comparing different algorithms is essential for any computer scientist.

How do we compare algorithms? Well we use Big Oh (scary big oh, and some others).

> In a few words: **Big O Notation is a convenient way to express the worst-case scenario for an algorithm**

### Related Asymptotic Notations

Big O is the most commonly used asymptotic notation for comparing algorithms, but there are others as well. 

#### Big Omega Ω

- Formal Definition: `f(n) is Ω(g(n)) iff for some constants c and N₀, f(N) ≥ cg(N) for all N > N₀`
- It represents the **lower bound**. Therefore, It doesn’t help much.
- `Ω(N)` means it takes at least `N` steps.
- This is a "best case" situation.

### Big Theta Θ 

- `f(n) is Θ(g(n)) iff f(n) is O(g(n)) and f(n) is Ω(g(n))`
- It represents the **lower bound** and the **upper bound** of an algorithm. 
- It’s harder to compute (but really good).
- `Θ(N)` means it takes at least `N` and at most `N` steps.
- This is not directly the "average case" but we can figure out the average knowing the upper and lower bound.

### Big Oh O 

- `f(n) is O(g(n)) iff for some constants c and N₀, f(N) ≤ cg(N) for all N > N₀`
- It represents the **upper bound** of an algorithm. 
- Big-oh is useful because represents the worst-case behavior, which is generally what we worry about.
- So, it guarantees that the program will terminate within a certain time period, it may stop earlier, but never later.
- `O(N)` means it takes at most `N` steps.
- This is a "worst case" situation.

<!-- |       |
|:-----:|
| <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/complexity_compared_2020.png" width="400"> |
| Relationships between Big O, Little O, Omega & Theta |  -->

In summary:
- `big Ω` or the lower bound is used to analyze the **best** an algorithm performs.  
  <!-- - `little o` actually a nice overview of little o [here](https://stackoverflow.com/questions/1364444/difference-between-big-o-and-little-o-notation).  -->
- `big Θ` is an upper AND lower bound and actually gives us the best overall analysis, but its harder (and not always necessary) to calculate.
- `big O` or the upper bound is used to analyze the **worst** an algorithm will perform.

### Run Time Calculations 

The best most accurate way of calculating run times (or number of comparisons, or number of instructions run, etc.) is to actually write the program and run the code. This is not always feasible. So we need to have a rudimentary understanding of how to analyze an algorithm. Analysis also helps us to design more efficient algorithms.

#### Starter Example

```cpp
  int sum (int n) {
1     int totalSum = 0;
2     for( int i = 0; i < n; i++)
3        totalSum+= i;
4     return totalSum;
  }
```
- The analysis for this piece of code is pretty straight forward:
  - **Lines 1 and 4** count for one unit of time each (or a constant 2).
  - **Line 2** 
    - `i=0`  is a cost of `1`
    - The test is executed `N + 1` times, where the last time is when the condition is false.
    - The increment is executed `N` times. 
    - So, the total cost for line 2 is `2N + 2`.
  - **Line 3** counts for 2 units; one addition and one assignment, and it’s executed `N` times, for a total of `2N` units.
  - So currently we have **2 + 2N * 2N + 2** 
  - We can rewrite this as **4N + 4** or **O(4N + 4)** (for now).
- Since we are looking for big oh / worst case / upper bound we can start throwing terms out of our equation that have little impact on the cost. These are things like constants and low order terms.
- We are going to drop the **+4** , because it’s a constant. 
- We can also drop the **4** from the **4N** because even though its a multiplier, it has little impact on the resulting cost as N gets very large. 
- So we now have a cost of **O(N)** 

>Note:<br>
> I know we said that we can throw out constants. Because if "its not based on the data set size its trivial". This is true most of the time. 
> However, if the constant is large, (like `10⁵`) it is good practice to give this constant a name and to include it in the asymptotic notation. 
> So, a program counts for `10⁵ * N` units would have complexity of `O(K * N)`.
> In the above example `4N` is not something big enough to earn its own constant.

This was a simple example to get up and running. But, there are some other general rules to follow when analyzing our code.

## General Rules

### 1. Loops

The running time of the loop is at most the running time of the statements inside the loop (including the tests) multiplied by the number of iterations.

The following program has complexity of O(10). (Does not depend on a data set, so its trivial).

```cpp
for( int i = 0; i < 10; i++)
   k++;                      // This statement will run 10 times.
```

As an example, the following program has complexity of O(N).

```cpp
for( int i = 0; i < n; i++)
   k++;                      // This statement will run N times.
```


### 2. Nested Loops

The total running time of the nested loops is the running time of each loop multiplied together. 

The total running time of a statement inside a group of nested loops is the running time of that statement multiplied by the product of the sizes of all the loops.

As an example, the following program has complexity of O(N²).

```cpp
for( int i = 0; i < n; i++)
    for( int j = 0; j < n; j++)
        k++;                   // This statement will run N^2 times.
```

### 3. Consecutive Statements

When there are consecutive statements, we count the statement with maximum complexity.

As an example, the following program which has O(N), followed by O(N²), has complexity of O(N²).

```cpp
for( int i = 0; i < n; i++){        // O(N)
   k++;
}
for( int i = 0; i < n; i++){        // O(N^2)
    for( int j = 0; j < n; j++){
        k++;                  
    }
} 
```

Also:

```cpp
for( int i = 0; i < n; i++){        // O(N)
    k++;
}
for( int i = 0; i < n; i++){        // O(N)
    k++;
} 
for( int j = 0; j < n; j++){        // O(N)
    k++;                  
}

// All together = O(3N) or simply O(N)
```

### 4. If-Else

The running time is never more than the running time of the test(s) plus the running time of the
block with maximum complexity.

```cpp
if (condition)
    //block 1
    for( int j = 0; j < n; j++){        // O(N)
        k++;                  
    }
else if (condition)
    //block 2
    for( int i = 0; i < n; i++){        // O(N^2)
        for( int j = 0; j < n; j++){
            k++;                  
        }
    } 
else
    //block 3
    for( int i = 0; i < n; i++){        // O(N^3)
        for( int j = 0; j < n; j++){
            for( int j = 0; j < n; j++){
                k++;                  
            }                  
        }
    } 

    // OR: O(N^3) worst case
```

### 5. Simple Statements

Return statements, initialize a variable, increment , assigning, …etc. All of these operations counted in **O(1)**.

## Big O Pitfalls

Since Big O Notation tells us about the upper bound of an algorithm ignoring constants and low-order terms. An algorithm may have exact number of steps in the worst case more or less than the Big O notation.

### Exact Cost > Big O

This algorithm has a *O(N)* upper bound. However we loop 5*N number of times, beyond the supposed upper bound.

```cpp
for(i = 0; i < 5*n; i++ )
    k++;
```

### Exact Cost < Big O

If we have a loop that executes `N = 10⁹` iterations, it gets a complexity of `O(N)`. However we KNOW that it almost never goes beyond `10⁷` number of iterations! Doesn't matter, its still `O(N)`.

```cpp
for(i = 0; i < n; i++ )
    if(arr[i] == goal) break;
```

A more common example, when the number of loops are decreasing by the time. So, first time it will loop `N, N-1, N-2, … , till 1`. The Big O notation for the following code is still `O(N³)`, while the exact number of steps is much less than that.

```cpp
for (int i = 0; i < n; ++i)    
    for (int j = i; j < n; ++j) 
        for (int k = j; k < n; ++k)
            count++;
```

## Common Time Complexities

When speaking about the time/memory complexity of an algorithm, instead of using the formal notation, we may simply state the class of an algorithm.

Here are some classes of the common time complexities.

|       |
|:-----:|
| <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/comparison_between_complexities_2020.png" width="500"> |
| Common Complexities | 

### Constant — O(1)

The algorithm does a [constant](https://en.wikipedia.org/wiki/Time_complexity#Constant_time) number of operations independent on the input.

```cpp
int start = 6;
int end = 100;
int mid = (end — start) / 2;
if(mid%2 == 0) 
    mid--;
```

### Linear— O(N)

The running time of the algorithm increases linearly with the size of the input.

```cpp
for(i = 0; i < n; i++ )
    k++;
```

### Logarithmic— O(Log N)

The running time of the algorithm is decreased by some factor with each step. A very simple example of this type is an algorithm that keeps dividing the input by two. A [binary search](https://en.wikipedia.org/wiki/Binary_search_algorithm) algorithm follows the same rule.

```cpp
while(n > 0){
   n /= 2;
}
```

> The logarithm is base 2, that is, Log<sub>2</sub> N.

### Linearithmic— O(N Log N)

The running time of the algorithm is as a result of performing a logarithmic operation *N* times.

For example, inserting *N* number of nodes inside a binary search tree. Each insertion takes O(Log N) time, while the entire algorithm takes linearithmic time.

Also, the average case of [quick sort](https://en.wikipedia.org/wiki/Quicksort) ,[heap sort](https://en.wikipedia.org/wiki/Heapsort) , and [merge sort](https://en.wikipedia.org/wiki/Merge_sort) takes O(N Log N) time.

```cpp
int arr[n] = [1,6,3];
for (int i = 0; i < n; ++i){
    binarySearchTree.insert(arr[i]);
}
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
        if (n % i == 0) return false;  
    return true;
}
```

### Quadratic — O(N²)

The running time of the algorithm is as a result of performing a linear operation *N* times; So, it’s *N* multiplied by *N*. A common sorting algorithms like [bubblesort](https://en.wikipedia.org/wiki/Bubble_sort) , [selectionsort](https://en.wikipedia.org/wiki/Selection_sort) and [insertionsort](https://en.wikipedia.org/wiki/Insertion_sort) takes `O(N²)`.

```cpp
for( int i = 0; i < n; i++)
    for( int j = 0; j < n; j++)
        k++;
```

### Cubic— O(N³)

The running time of the algorithm is as a result of performing a linear operation N² times; So, it’s N multiplied by N, multiplied by N.

```cpp
for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
        for (int k = 0; k < n; ++k)
            cunt++;
```

### Polynomial — O(N<sup>c</sup>)

The running time of the algorithm is as a result of performing a linear operation N<sup>(c-1)</sup> times, for some constant `c`, where `c > 1`.

In other words, The running time of the algorithm is a simple [polynomial](https://en.wikipedia.org/wiki/Polynomial) function of the size of the input.

> Since polynomial has complexity of O(N<sup>c</sup>), where c > 1. Therefore, O(N²) is also a polynomial time.

```cpp
for( int i = 0; i < n; i++)
    for( int j = 0; j < n; j++)
        k++;
```

### Exponential — O(c<sup>N</sup>)

Printing every possible combination of a numerical password of size N = O(10<sup>N</sup>). The key here is "numerical" (0-9) or 10 digits. Thats where the 10 in 10<sup>N</sup> comes from. That why passwords want you to mix digits , uppercase , lowercase, and special characters. 

Here is a decent article about the 8 queens problem which has a brute force O(N<sup>N</sup>) solution. There are other much faster solutions, but this is a decent example: [8 queens](https://medium.com/@jmohon1986/timeout-the-story-of-n-queens-time-complexity-c80636d92f8b). NOT mandatory reading.

### Factorial— O(N!)

The running time of the algorithm is factorial of N. It’s common in generating permutations. The complexity would be the summation of N\!/K\!, where k = 0…N; O(N\!/0\! + N\!/1\! + …. + 1), which is O(N\!).

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
Or take a look at the [traveling salesman](https://en.wikipedia.org/wiki/Travelling_salesman_problem). That wikipedia article shows just how studied some of these algorithms can get. The brute force solution is O(N!), with LOTS of other approches with improvements. Not mandatory, but check it out.

## P and NP

So, prove P == NP and become famous and win money. What is P vs NP? The P = "Polynomial" and the NP = "Non Polynomial" which are two broad classification of algorithms. Most all of the algorithms we discuss in class are of the "P" or polynomial class of algorithm (N N<sup>2</sup>, even N<sup>3</sup>, ...). This means they can be solved in plynomial time. Non Polynomial or NP are algorithms that cannot be solved in polynomial time (N! or C<sup>N</sup>). This [article](https://en.wikipedia.org/wiki/P_versus_NP_problem) on wikipedia discusses P vs NP in detail. 

Some food for thought: Contempary public key encryption is safe assuming that prime number factorization cannot be solved in polynomial time. If someone can show that a Non Polynomial time algorithm can be solved in Polynomial time (the factorization of large primes for example) ... then all of our encryption keys have just become worthless. So ... sometimes its ok for algorithms to be hard! 

<sub>(Then comes quantum computers  ... and then the singularity ... were all doomed)</sub>