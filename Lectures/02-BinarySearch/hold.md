
In class on the 22<sup>nd</sup> of January I introduced a variety of concepts which included:

- Big Oh (one of the ways we analyze algorithms)
- Binary Search (the algorithm we discussed to speed up finding an item)
- A Simple Sort (a binary search requires the items to be sorted)

Before I describe each of these items, let me throw at you a brief overview of `asymptotic notation` which are mathematical definitions of how algorithms perform. There are 5 listed below, but remember that we are mostly interested in `big oh` (worst case performance). 

## Asymptotic Notations

Asymptotic notations are mathematical tools used in algorithm analysis to describe the behavior of algorithms, especially their runtime or space requirements, as the size of the input grows. The main asymptotic notations used are:

### On Exam
  - **Big O Notation** `O(n)`
     - **Description**: Describes the upper bound of an algorithm's runtime. It provides a worst-case scenario.
     - **Example**: If an algorithm's runtime is ***O(n<sup>2</sup>)***, then its execution time will not grow faster than ***n<sup>2</sup>*** for large values of ***n***.
     - **Use**: Commonly used to describe the worst-case complexity of an algorithm.
    
-----

### Not On Exam

  - **Omega Notation** `Ω(n)`
     - **Description**: Describes the lower bound of an algorithm's runtime. It gives the best-case scenario.
     - **Example**: If an algorithm's runtime is ***Ω(n)***, it means that the algorithm takes at least linear time in the best case.
     - **Use**: Useful when we want to show that an algorithm cannot do better than a certain time complexity in the best case.

  - **Theta Notation** `Θ(n)`
     - **Description**: Tight bound of an algorithm's runtime. It represents both the upper and lower bounds.
     - **Example**: If an algorithm's runtime is ***Θ(n log n)***, it means that the algorithm's time complexity is bounded both above and below by ***n log n***. So, for large values of n, the algorithm's runtime is proportional to ***n log n***.
     - **Use**: Used when an algorithm’s upper and lower bound complexity are the same.

  - **Little o Notation** `o(n)`
       - **Description**: Describes an upper bound that is not tight. In other words, it gives an upper limit, but the actual complexity might be lower.
       - **Example**: If an algorithm's runtime is ***o(n<sup>2</sup>)***, then for large values of ***n***, the algorithm's runtime grows slower than ***n<sup>2</sup>***.
       - **Use**: Useful for showing that an algorithm is definitely faster than a certain complexity, but it does not specify the exact complexity.

  - **Little omega Notation**  `ω(n)`
       - **Description**: Describes a lower bound that is not tight. The actual complexity might be higher.
       - **Example**: If an algorithm's runtime is ***ω(n)***, then the algorithm grows faster than linear time for large values of ***n***, but it doesn't specify how much faster.
       - **Use**: Less common in practical algorithm analysis, but useful for theoretical comparisons.

-----

Each of these notations serves a specific purpose in algorithm analysis, helping to describe how an algorithm performs in different scenarios (worst-case, best-case, and average-case) as the size of the input grows (where input = `N`). Understanding these notations is crucial for analyzing and comparing the efficiency of different algorithms.
