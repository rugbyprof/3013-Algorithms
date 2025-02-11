## Big-O Notation Explained with Examples
<sup>By Vineet Choudhary </sup>


Asymptotic notation is a set of languages which allow us to express the performance of our algorithms in relation to their input. Big O notation is used in Computer Science to describe the performance or complexity of an algorithm. Big O specifically describes the worst-case scenario, and can be used to describe the execution time required or the space used (e.g. in memory or on disk) by an algorithm.

Big O complexity can be visualized with this graph:
<img src="https://images2.imgbox.com/49/dc/SIJoAQ35_o.png">

As a programmer first and a mathematician second (or maybe third or last) here the best way to understand Big O thoroughly examples in code. So, below are some common orders of growth along with descriptions and examples where possible.

### 1. O(1)
```c++
void printFirstElementOfArray(int arr*){
    printf("%d\n",arr[0]);
}
```
This function runs in `O(1)` time (or "constant time") relative to its input. The input array could be **`1`**  item or **`1000`**  items, but this function would still just require one step.

### 2. O(n)
```c++
void printAllElementOfArray(int arr*, int size){
    for (int i = 0; i < size; i++){
        printf("%d\n", arr[i]);
    }
}
```
This function runs in `O(n)` time (or "linear time"), where **`n`** is the number of items in the array. If the array has **`10`**  items, we have to print **`10`**  times. If it has **`1000`**  items, we have to print **`1000`**  times.

### 3. O(n<sup>2</sup>)
```c++
void printAllPossibleOrderedPairs(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d = %d\n", arr[i], arr[j]);
        }
     }
}
```

Here we're nesting two loops. If our array has **`n`** items, our outer loop runs **`n`**  times and our inner loop runs **`n`** times for each iteration of the outer loop, giving us **`n`<sup>`2`</sup>** total prints. Thus this function runs in **O(`n`<sup>`2`</sup>)** time (or "quadratic time"). If the array has **`10`**  items, we have to print **`100`** times. If it has **`1000`** items, we have to print **`1000000`** times.

### 4. O(2<sup>n</sup>)
```c++
int fibonacci(int num){
    if (num <= 1){
        return num;
    }
    return fibonacci(num - 2) + fibonacci(num - 1);
}
```

An example of an **O(`2`<sup>`n`</sup>)** function is the recursive calculation of Fibonacci numbers. **O(`2`<sup>`n`</sup>)** denotes an algorithm whose growth doubles with each addition to the input data set. The growth curve of an **O(`2`<sup>`n`</sup>)** function is exponential - starting off very shallow, then rising meteorically.

### 5. Drop the constants

When you're calculating the big O complexity of something, you just throw out the constants. Like:

```c++
void printAllItemsTwice(int arr*, int size)
{
    for (int i = 0; i < size; i++){
        printf("%d\n", arr[i]);
    }
	
    for (int i = 0; i < size; i++){
        printf("%d\n", arr[i]);
    }
}
```
This is **O(`2n`)**, which is **O(`2 * n`)** which we just call **`O(n)`**.

```c++
void printFirstItemThenFirstHalfThenSayHi100Times(int arr*, int size){
    printf("First element of array = %d\n",arr[0]);
	
    for (int i = 0; i < size/2; i++){
        printf("%d\n", arr[i]);
    }

    for (int i = 0; i < 100; i++){
        printf("Hi\n");
    }
}
```
This is **`O(1 + n/2 + 100)`**, which we just call **`O(n)`**.

Why can we get away with this? Remember, for big O notation we're looking at what happens as **`n`** gets arbitrarily large. As **`n`** gets really big, adding **`100`** or dividing by **`2`** has a decreasingly significant effect.

### 6. Drop the less significant terms
```c++
void printAllNumbersThenAllPairSums(int arr*, int size){
    for (int i = 0; i < size; i++){
        printf("%d\n", arr[i]);
    }

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            printf("%d\n", arr[i] + arr[j]);
        }
    }
}
```
Here our runtime is **`O(n + n`<sup>2</sup>`)`**, which we just call **`O(n`<sup>`2`</sup>`)`**.

Similarly:

- **`O(n`<sup>`3`</sup>` + 50n`<sup>`2`</sup>`+ 10000)`** is **`O(n`<sup>`3`</sup>`)`**
- or
- **`O((n + 30) * (n + 5))`** is **`O(n`<sup>`2`</sup>`)`**


Again, we can get away with this because the less significant terms quickly become, well, less significant as n gets big.

### 7. With Big-O, we're usually talking about the "worst case"
```c++
bool arrayContainsElement(int arr*, int size, int element){
    for (int i = 0; i < size; i++){
        if (arr[i] == element) return true;
    }
    return false;
}
```
Here we might have **100** items in our array, but the first item might be the that element, in this case we would return in just **1** iteration of our loop.

In general we'd say this is **`O(n)`** runtime and the "worst case" part would be implied. But to be more specific we could say this is worst case **`O(n)`** and best case **`O(1)`** runtime. For some algorithms we can also make rigorous statements about the "average case" runtime.

### 8. Other Examples
Let's take the following C example which contains a for loop, iterates from **`i = 0`** to **`i < 10000`** and prints each value of that **`i`**:

```c++
#include<stdio.h>
void print_values(int end) 
{
    for (int i = 0; i < end; i++)
    {
        printf("%d\n", i);
    }
}
int main()
{
    print_values(10000);
    return 0;
}
```

We could put a timer at the beginning and the end of the line of code which calls this function, this would then give us the running time of our print_values algorithm, right?

```c++
#include<stdio.h>
#include<time.h>
void print_values(int end) 
{
    for (int i = 0; i < end; i++)
    {
        printf("%d\n", i);
    }
}
int main()
{
    clock_t t;
    t = clock();

    print_values(10000);

    float diff = ((float)(clock() - t)) / CLOCKS_PER_SEC ;
    printf ("\n\n diff=%f \n\n", diff);

    return 0;
}
```

Maybe, but what if you run it again, three times, write down your results and then move to another machine with a higher spec and run it another three times. I bet upon comparison of the results you will get different running times!

This is where asymptotic notations are important. They provide us with a mathematical foundation for representing the running time of our algorithms consistently.

We create this consistency by talking about operations our code has to perform. Operations such as array lookups, print statements and variable assignments.

If we were to annotate print_values with the amount of times each line within the function is executed for the input 10000, we would have something as follows:

```c++
void print_values(int end) //end = 10000 
{
    for (int i = 0; i < end; i++)  //Execution count: 10000
    {
        printf("%d\n", i); // Execution count: 10000
    }
}
```

If we were to change the input value of print_values function, our print statement would be exercised more or less, depending on the value of that input.

If we were to put this into an arithmetic expression, we would get **`10000 + 1`**, using intuition we know that the **`10000`** is variable on the input size, if we call the input value **`n`**, we would now have the expression **`n + 1`**.

I could now argue that the worst case running time for `print_values` is **`O(n + 1)`**. **`n`** for the loop block and **`1`** for the print statement.

In the grand scheme of things, the constant value **`1`** is pretty insignificant at the side of the variable value n. So we simply reduce the above expression to **`O(n)`**, and there we have our Big-O running time of print_values.

As our code prints each and every value from **`0`** to the input , as the loop is the most significant part of the code, we are able to say that our code is of running time **`O(n)`** where **`n`** is the variable length of the array! Simples!

An algorithm of running time **`O(n)`** is said to be linear, which essentially means the algorithms running time will increase linearly with its input **`(n)`**.
<!-- 
### 9. Proving Big-O
We can prove, mathematically, that print_values is in-fact **`O(n)`**, which brings us on to the formal definition for Big-O:

**`f(n) = O(g(n)) if c and some initial value k are positive when f(n) <= c * g(n) for all n > k is true`**.

We can turn this formal definition into an actual definition of our above code, which we can then in turn prove.

We must first ask does `print_values` have a running time of **`O(n)`**?

If **`print_values <= c * n`**, when **`c = 1`** then print_values does have a running time of **`O(n)`** when **`n > k`**.

**`c`** can be any integer while **`k`** is the amount of iterations we must perform for the expression to be true for every subsequent value of **`n`**.

As **`c`** is just **`1`**, we can simplify our expression to **`print_values <= n`**.

|   N   | F(N)  | G(N)  | TRUE/FALSE |
| :---: | :---: | :---: | :--------: |
|   0   |   0   |   0   |   False    |
|   1   |   1   |   1   |    True    |
|   2   |   2   |   2   |    True    |
|   3   |   3   |   3   |    True    |

We can see that n must be greater than the value 0 of constant k in order to satisfy the expression print_values <= n.

We can now say when n is 1:
1 <= 1 * 1 for 1 > 0 is true. We know this because 1 multiplied by 1 is 1 and 1 is greater than our constant k which was 0.

The above must be true for all values of n greater than k (0), so if n was 10, 10 <= 1 * 10 for 10 > 0 is also true.

What we're basically saying here is that no matter our input (n), it must be greater than or equal to our constant (c) when the size of our input (n) is more than another constant value (k), in our case the iteration count of the function.

But where do our constants come from? Well they are just values, we typically start at 1 and work our way up to seek a constant which makes the expression f(n) <= c * g(n) for all n > k true. If we cannot find such combination of constants, then our code does not have a running time of O(n) and our hypothesis was incorrect.

10 Disproving Big-O
Lets take a new C function, which contains a for loop, iterates from i = 0 to i < 100 and an another nested for loop from j = 0 to j < 100 which prints each value of that i and j:

```c++
void print_values_with_repeat(int end) //end = 100 
{
    for (int i = 0; i < end; i++) 
    {
        for (int j = 0; j < end; j++)
        {
            printf("i = %d and j = %d\n", i, j);
        }
    }
}
```

If we were to annotate print_values_with_repeat with the amount of times each line within the function is executed for the input 100, we would have something as follows:

```c++
void print_values_with_repeat(int end) //end = 100 
{
    for (int i = 0; i < end; i++)  //Execution count: 100
    {
        for (int j = 0; j < end; j++)  //Execution count: 10000
        {
            printf("i = %d and j = %d\n", i, j); // Execution count: 1
        }
    }
}
```

Does print_values_with_repeat have a running time of O(n)?

N	F(N)	G(N)	TRUE/FALSE
0	0	0	False
1	1	1	True
2	4	2	False
3	9	3	False
Suppose our constant c is 1, 1 <= 1 * 1 for 1 > 0, this is true - however our definition says that g(n) must be greater than all values of f(n).

So if we take the value 2 of n, 2 <= 1 * 4 for 1 > 0, we can see that this is now false, which disproves our hypothesis that print_values_with_repeat is O(n). Even if we change our constant c to 2, this would still prove false eventually.

We can actually see that the order of growth in operations in print_values_with_repeat is actually n2, so let's hypothesise now that print_values_with_repeat is actually O(n2).

Does print_values_with_repeat have a running time of O(n2)?

N	F(N)	G(N)	TRUE/FALSE
0	0	0	False
1	1	1	True
2	4	4	True
3	9	9	True
Suppose our constant c is still 1, our expression would now be 3 <= 3 * 32 for 3 > 0, this is true, great! print_values_with_repeat is in-fact O(n2).

O(n2) is a quadratic time algorithm, as the running time of the algorithm increases quadratically to the input.
 -->
