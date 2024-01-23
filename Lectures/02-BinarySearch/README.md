## Binary Search - Plus Other Stuff
#### Due: Never 

In class on the 22<sup>nd</sup> of January I introduced a variety of concepts which included:

- Big Oh (one of the ways we analyze algorithms)
- Binary Search (the algorithm we discussed to speed up finding an item)
- A Simple Sort (a binary search requires the items to be sorted)

Before I describe each of these items, let me throw at you a brief overview of `asymptotic notation` which are mathematical definitions of how algorithms perform. There are 5 listed below, but remember that we are mostly interested in `big oh` (worst case performance). 

## Asymptotic Notations

Asymptotic notations are mathematical tools used in algorithm analysis to describe the behavior of algorithms, especially their runtime or space requirements, as the size of the input grows. The main asymptotic notations used are:

1. **Big O Notation (O-notation)**
   - **Description**: Describes the upper bound of an algorithm's runtime. It provides a worst-case scenario.
   - **Example**: If an algorithm's runtime is ***O(n<sup>2</sup>)***, then its execution time will not grow faster than ***n<sup>2</sup>*** for large values of ***n***.
   - **Use**: Commonly used to describe the worst-case complexity of an algorithm.

2. **Omega Notation (Ω-notation)**
   - **Description**: Describes the lower bound of an algorithm's runtime. It gives the best-case scenario.
   - **Example**: If an algorithm's runtime is ***Ω(n)***, it means that the algorithm takes at least linear time in the best case.
   - **Use**: Useful when we want to show that an algorithm cannot do better than a certain time complexity in the best case.

3. **Theta Notation (Θ-notation)**
   - **Description**: Tight bound of an algorithm's runtime. It represents both the upper and lower bounds.
   - **Example**: If an algorithm's runtime is ***Θ(n log n)***, it means that the algorithm's time complexity is bounded both above and below by ***n log n***. So, for large values of n, the algorithm's runtime is proportional to ***n log n***.
   - **Use**: Used when an algorithm’s upper and lower bound complexity are the same.

4. **Little o Notation (o-notation)**
   - **Description**: Describes an upper bound that is not tight. In other words, it gives an upper limit, but the actual complexity might be lower.
   - **Example**: If an algorithm's runtime is ***o(n<sup>2</sup>)***, then for large values of ***n***, the algorithm's runtime grows slower than ***n<sup>2</sup>***.
   - **Use**: Useful for showing that an algorithm is definitely faster than a certain complexity, but it does not specify the exact complexity.

5. **Little omega Notation (ω-notation)**
   - **Description**: Describes a lower bound that is not tight. The actual complexity might be higher.
   - **Example**: If an algorithm's runtime is ***ω(n)***, then the algorithm grows faster than linear time for large values of ***n***, but it doesn't specify how much faster.
   - **Use**: Less common in practical algorithm analysis, but useful for theoretical comparisons.

Each of these notations serves a specific purpose in algorithm analysis, helping to describe how an algorithm performs in different scenarios (worst-case, best-case, and average-case) as the size of the input grows (where input = `N`). Understanding these notations is crucial for analyzing and comparing the efficiency of different algorithms.


Again, `Big Oh` is the `worst case scenario` for an algorithm, but it doesn't mean that the worst case will always happen, it simply defines the cost when it does happen. For example, if I had an unordered array of integers, and I had to look for a value in said array, what is the worst case? 
   1. Item is not in the array.
   2. Item is in the last position in the array.

This means that I have to process (look at or loop over) every single item in said array. 

However, if the item I'm looking for is: 
   1. The first item in the array.
   2. Somewhere in the middle of the array.

Then I don't have to process every item! However, `big oh` doesn't change for this algorithm since the `worst case scenario` is still the same. 

## Unordered Search

Before I describe `Binary Search` let's discuss an unordered (or linear) search on an array of items. In an unordered search, you sequentially check each element of the array until you find the target item or reach the end of the array.

- **Scenario**: You have an unordered array of items. This means the items are not sorted in any particular order.
- **Goal**: To find a specific item (let's call it `target`) in the array.
- **Process**:
  **1.** Start from the first element of the array.
  **2.** Compare the current element with `target`.
  **3.** If it matches, you've found the item, and the search ends.
  **4.** If it doesn't match, move to the next element.
  **5.** Repeat steps 2-4 until you either find `target` or reach the end of the array.
  **6.** If you reach the end of the array without finding `target`, the item is not in the array.

#### Time Complexity
- The time complexity of an unordered search is O(n), where n is the number of elements in the array. In the worst case, you may have to check every element.

#### Simple Example

Let's say we have an array of numbers and we're searching for the number `5`.

`Array`: `[8, 3, 5, 1, 9, 6]`

Here's the search process:

```
Searching for the value 5 by looking at each item in sequence until you find said item, or reach the end of your container. 

[8, 3, 5, 1, 9, 6]  
 ^

[8, 3, 5, 1, 9, 6]
    ^

[8, 3, 5, 1, 9, 6]   <- Target found (5)
       ^
```

In this case, we found our target, `5`, at the third position in the array.

An `Unordered Search` is straightforward but not the most efficient way to find items, especially for large arrays. It's best suited for small arrays or situations where the array elements are not sorted and cannot be sorted. For searching in large or frequently accessed datasets, other search methods or data structures might be more efficient, like a `Binary Search`.

## Binary Search

A binary search is an efficient algorithm for finding an item from a sorted list of items. It works by repeatedly dividing in half the portion of the list that could contain the item, until you've narrowed down the possible locations to just one.

#### Description of Binary Search

- **Prerequisite**: The array must be sorted!
- **Goal**: To find a specific item (let's call it `target`) in the array.
- **Process**:
  **1.** Start with the entire array.
  **2.** Find the middle element of the array.
  **3.** If the middle element is equal to `target`, the search is complete.
  **4.** If the middle element is less than `target`, narrow the search to the upper half of the array.
  **5.** If the middle element is greater than `target`, narrow the search to the lower half of the array.
  **6.** Repeat steps 2-5 on the new half-array until the target is found or the array cannot be split further.

#### Time Complexity
- The time complexity of binary search is ***O(log n)***, where ***n*** is the number of elements in the array.

#### Example

Let's consider a sorted array of numbers:
- `[1, 3, 5, 7, 9, 11, 13, 15]` 
- and we're searching for the number `9`.

```
Initial Array:
[1, 3, 5, 7, 9, 11, 13, 15]
[0, 1, 2, 3, 4, 5 , 6 , 7]
          
Step 1: Calculate Front Middle & Rear: (F + R // 2)

[1, 3, 5, 7, 9, 11, 13, 15]
[0, 1, 2, 3, 4, 5 , 6 , 7]
 F        M             R

(0 + 7) / 2 = 3.5 or 3

Step 2:  Middle is index 3 (value 7), target is greater, take the upper half.
Calculate the middle: 4 + 7 = 11 / 2 = 5.5 or 5

[9, 11, 13, 15]
[4, 5 , 6 , 7]
 F  M       R

Step 3: Middle is index 5 (value 11), target is smaller, take the lower half of the array (which in this case is the value we are looking for).
[9]
[4]

Found target (9) at position: 4 (0-based index)
```

In this example, the binary search found `9` in three steps, which is much more efficient than linear search for larger arrays.

### Conclusion
Binary search is a highly efficient algorithm for searching in sorted arrays. It significantly reduces the number of comparisons needed to find an element, compared to linear search. `However, its effectiveness is contingent on the array being sorted.` This makes binary search a great example of the trade-off between sorting cost and search efficiency.

## Simple Sorts

Both Bubble Sort and Selection Sort are simple sorting algorithms with a time complexity of O(n^2), making them less efficient for large datasets. However, they are easy to understand and implement, which is why they're often taught in introductory computer science courses.

### Bubble Sort

**Description**:
Bubble Sort is a comparison-based algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.

**C++ Example**:
```cpp
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}
```

### Selection Sort

**Description**:
Selection Sort divides the input list into two parts: a sorted sublist of items which is built up from left to right at the front of the list, and a sublist of the remaining unsorted items. On each iteration, the smallest (or largest, depending on sorting order) element from the unsorted sublist is picked and moved to the sorted sublist.

**C++ Example**:
```cpp
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}
```

### Differences between Bubble Sort and Selection Sort

1. **Sorting Process**:
   - In Bubble Sort, the largest (or smallest) element "bubbles up" to the end of the array in each iteration.
   - In Selection Sort, the algorithm selects the smallest (or largest) element from the unsorted part and moves it to the end of the sorted part.

2. **Number of Swaps**:
   - Bubble Sort can have a higher number of swaps in each pass through the array.
   - Selection Sort makes fewer swaps in comparison, at most n-1 swaps.

3. **Adaptive Nature**:
   - Bubble Sort can be easily modified to be adaptive (to stop early if the list is sorted).
   - Selection Sort makes the same number of comparisons regardless of the initial order of the elements.

4. **Performance**:
   - Bubble Sort generally performs worse than Selection Sort in terms of the number of comparisons and swaps, especially in the worst-case scenario.
   - Selection Sort has better performance than Bubble Sort due to fewer swaps but is still not suitable for large lists.

Both algorithms have limited practical applications due to their quadratic time complexity. They are inefficient for large datasets but are useful for educational purposes to illustrate the basics of sorting algorithms.