## Recursion

Recursion is a programming technique where a function calls itself directly or indirectly to solve a problem by breaking it down into smaller, more manageable sub-problems. Each recursive call processes a subset of the overall problem, and the recursion continues until it reaches a base case, which is a condition that can be solved without further recursion. Recursion is commonly used in tasks involving hierarchical structures, such as tree traversals, or in algorithms that naturally fit the divide-and-conquer approach, like sorting and searching algorithms.

When writing a recursive function, it's preferential to include the following components to ensure that the function works correctly and terminates as expected:

### Extended Components

1. **Base Case(s)**: The base case is a condition that stops the recursion by not making any further recursive calls. It typically handles the simplest or smallest possible input for which the result can be determined directly. Properly defined base cases prevent infinite recursion and ensure that the function eventually terminates.

2. **Recursive Case(s)**: The recursive case is the part of the function that includes a call to the function itself with a different argument. It gradually moves the problem towards the base case. The recursive case must alter the input (e.g., reduce the problem size) in such a way that each recursive call progresses towards meeting the base case condition.

3. **Correctness**: The function should correctly implement the logic for the problem it's intended to solve, ensuring that each recursive step correctly moves towards a solution and that the base cases correctly handle the smallest instances of the problem.

4. **Termination Condition**: Ensured by the base case(s), the termination condition is what prevents the function from recursing indefinitely. It's crucial that each recursive step moves the problem closer to a base case to guarantee termination.

5. **Return Value**: Recursive functions should return a value at each step. In the base case, this is often a direct answer, while in the recursive case, the return value is typically derived from the recursive call(s). The way these values are combined or manipulated is specific to the problem the function is solving.

If we Boil recursion down to its bare bones, then the following components are essential.

### Essential Components

1. The recursive function calls itself.
2. The recursive call should gradually move the problem toward the base case.
3. A base case that terminates or ends the series of recursive calls. 

### Recursion Example: Computing Factorials

Here's a simple example of a recursive function to compute the factorial of a non-negative integer, illustrating these components:

```c++
int factorial(int n) {
    // Base case: factorial of 0 or 1 is 1
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive case: n! = n * (n-1)!
    else {
        return n * factorial(n - 1);
    }
}
```

- **Base Case**: `if (n == 0 || n == 1)`, where the factorial of 0 or 1 is directly returned as 1.
- **Recursive Case**: `return n * factorial(n - 1);`, which multiplies `n` by the factorial of `n - 1`, moving towards the base case.

### Best Practices

- **Avoiding Stack Overflow**: (Not the website :laughing:) Since each recursive call uses some amount of stack memory, it's important to ensure that recursion depth won't exceed the system's stack size, which could lead to a stack overflow error.
- **Memoization**: In some cases, to improve efficiency, it's beneficial to store (memoize) the results of recursive calls, so they don't need to be recomputed if needed again.
- **Alternative to Recursion**: For functions that could lead to deep recursion levels, consider using an iterative approach if possible, to avoid the risk of stack overflow.