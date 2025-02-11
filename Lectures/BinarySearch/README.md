## Binary Search - Overview

#### Due: N/A

<img src="https://images2.imgbox.com/e1/44/KxfIEB9m_o.gif">

Again, `Big Oh` is the `worst case scenario` for an algorithm, but it doesn't mean that the worst case will always happen, it simply defines the cost when it does happen. For example, if I had an unordered array of integers, and I had to look for a value in said array, what is the worst case?

1.  Item is not in the array.
2.  Item is in the last position in the array.

This means that I have to process (look at or loop over) every single item in said array.

However, if the item I'm looking for is:

1.  The first item in the array.
2.  Somewhere in the middle of the array.

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

- The time complexity of binary search is **_O(log n)_**, where **_n_** is the number of elements in the array.

#### Example

Let's consider a sorted array of numbers:

- `[1, 3, 5, 7, 9, 11, 13, 17, 23, 37]`
- Key = `23`.

---

- **Step 1**
  `l = 0`
  `r = 9`
  `m = 0+9//2 = 4`

```
Starting m
[1, 3, 5, 7, 9, 11, 13, 17, 23, 37]
[0, 1, 2, 3, 4,  5 , 6 , 7,  8,  9]
 l           m                   r
```

Key is not `l`, `r`, or `m`

- **Step 2**
  `Key` > `m` so ...
  `l = m + 1 = 5`
  `r = 9`
  `m = (5 + 9 )// 2 = 7`

```
[1, 3, 5, 7, 9, 11, 13, 17, 23, 37]
[0, 1, 2, 3, 4,  5 , 6 , 7,  8,  9]
                 l       m       r
```

Key is not `l`, `r`, or `m`

- **Step 3**
  `Key` > `m` so ...
  `l = m + 1 = 8`
  `r = 9`
  `m = (8 + 9 )// 2 = 7`

```
[1, 3, 5, 7, 9, 11, 13, 17, 23, 37]
[0, 1, 2, 3, 4,  5 , 6 , 7,  8,  9]
                             l   r
                             m
```

Key is at `l` and `m` both at index `8` so return true or the location within the array (8).

---

In this example, the binary search found `23` in three steps, which is much more efficient than linear search for larger arrays.

Binary search is an efficient algorithm for finding an item from a sorted list of items. It works by repeatedly dividing in half the portion of the list that could contain the item until you've narrowed the possible locations to just one. Here's an overview, along with considerations for its implementation, the overhead involved, its complexity, and why it's not suitable for list-based structures.

### Conditions Justifying Binary Search

1. **Sorted Data**: Binary search only works on a sorted array. The array must be sorted beforehand, which incurs an additional cost if the data is not already sorted.
2. **Large Datasets**: The efficiency of binary search becomes significant with large datasets. For small datasets, the overhead of ensuring the data is sorted might not be worth the speedup in search time.

3. **Frequent Searches**: If you're performing many searches, the cost of sorting the data (if it's not already sorted) can be amortized over these searches, making binary search more appealing.

### Overhead in Binary Search Implementation

1. **Sorting Overhead**: If the data isn't already sorted, you need to sort it first, which adds overhead. The efficiency of binary search must be weighed against this sorting cost.

2. **Random Access**: Binary search requires random access to the elements, as it needs to jump to the middle element at each step. This is not a significant issue in arrays but is a critical limitation in list-based structures.

### Complexity

- **Worst-Case Complexity**: O(log n), where n is the number of elements in the array. This is because the algorithm splits the array in half with each iteration.
- **Average-Case Complexity**: Also O(log n) for the same reasons as the worst case.

### Binary Search in List-Based Structures

Binary search doesn't work efficiently in list-based structures (like linked lists) primarily due to the lack of random access. In arrays, jumping to the middle element is an O(1) operation, which is crucial for the efficiency of binary search. In a linked list, however, accessing the middle element requires traversing half the list from the beginning, which is an O(n) operation. This traversal would need to be done at each step of the binary search, negating its logarithmic nature and making it no more efficient than a linear search in such structures.

Certainly! Below is a class stub for an array-based binary search in C++. This class includes the necessary data elements and method declarations. The actual implementations of the methods are left as stubs for you or your students to fill in.

```cpp
#include <vector>

class BinarySearch {
private:
    std::vector<int> data; // The sorted array for binary search

public:
    // Constructor to initialize the binary search with a sorted array
    BinarySearch(const std::vector<int>& sortedArray) : data(sortedArray) {}

    // Method to perform binary search
    // Returns the index of the element if found, -1 otherwise
    int search(int target) const;

    // Optional: Method to add an element to the array while maintaining sorted order
    // This might be useful if you frequently need to add elements and still perform binary search
    void insert(int value);

    // Optional: Method to remove an element from the array
    // This might be useful if you need to dynamically update the array contents
    bool remove(int value);

    // Optional: Utility method to display the contents of the array
    // This can be useful for debugging purposes
    void display() const;
};
```

In this class stub:

- The `data` member variable is a `std::vector<int>` that stores the sorted array on which binary search is performed. While this example uses `int`, you can template the class to allow for other data types.
- The `search` method is the core of the binary search functionality, taking a `target` value to find in the array and returning its index if found, or `-1` if not found.
- The `insert` and `remove` methods are optional and would require additional logic to maintain the sorted order of the array. These methods would be useful if the array needs to be dynamic, with elements added or removed over time.
- The `display` method is a utility to print the contents of the array, helpful for debugging or demonstration purposes.

This class provides a basic framework for implementing binary search on an array-based data structure, with optional features to manage dynamic data.

You're right that when implementing a binary search algorithm, you typically need to keep track of the left, right, and middle indices to determine the current search boundaries within the array. These variables are crucial for narrowing down the search space in each iteration of the algorithm.

### Declaring Left, Right, and Middle Indices

In a typical binary search implementation, the `left`, `right`, and `middle` variables are declared and used within the scope of the `search` method itself. This is because their values are specific to each individual search operation and don't need to be retained or accessed outside of a single execution of the search method.

### Example Revised Method Signature with Local Variables:

```cpp
int search(int target) const {
    int left = 0;
    int right = data.size() - 1;
    int middle;

    while (left <= right) {
        middle = left + (right - left) / 2;

        if (data[middle] == target) {
            return middle; // Target found
        } else if (data[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1; // Target not found
}
```

### Instance Variables Consideration

Generally, there's no need to make `left`, `right`, and `middle` instance variables for a standard binary search implementation, as each search is independent, and these variables only have meaning within the context of a single search operation.

However, there could be specific scenarios or advanced implementations where you might consider keeping such variables at the instance level, for example:

1. **Stateful Search Operations**: If your application involves pausing and resuming search operations, maintaining state between operations could necessitate keeping these variables at the instance level.

2. **Iterative Interface**: If you're designing an iterative interface where the user or another part of the program can manually control the progression of the search step by step, maintaining state across method calls could be useful.

3. **Complex Algorithms**: In more complex algorithms that extend basic binary search, such as certain types of search trees or algorithms that require backtracking, maintaining broader state information might be beneficial.

For most use cases, especially educational and straightforward binary search implementations, keeping `left`, `right`, and `middle` within the local scope of the `search` method is sufficient and keeps the class design clean and focused.

### Conclusion

Binary search is a highly efficient algorithm for searching in sorted arrays. It significantly reduces the number of comparisons needed to find an element, compared to linear search. `However, its effectiveness is contingent on the array being sorted.` This makes binary search a great example of the trade-off between sorting cost and search efficiency.
