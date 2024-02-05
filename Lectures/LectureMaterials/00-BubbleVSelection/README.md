## Simple Sorts

Both `Bubble Sort` and `Selection Sort` are simple sorting algorithms with a time complexity of **`O(n^2)`**, making them less efficient for large datasets. However, they are easy to understand and implement, which is why they're often taught in introductory computer science courses.

### Bubble Sort

#### Basics:

- Bubble Sort is a comparison-based swapping algorithm that:
  - Steps through the list up to **`O(n^2)`** times.
  - It compares adjacent elements, and swaps them if they are in the wrong order.
  - Using an inner and outer loop guarantees we traverse the list enough times to ensure total order.
  - Notice only the `j` values is used to do swaps, since it must start from the beginning every time.
  - There are speedups that can be added, but we will discuss those at a later date.

#### C++ Example:
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

#### Basics:
- Selection Sort places on item into its proper location on every pass.
  - Assuming ascending order, on the first pass, the smallest value in the array will get placed at location `0`
  - On the next pass, since `i` starts at the next location, the next smallest item gets placed in its proper location.
  - So on 2 iterations of the outer loop, 2 items will be in proper location, on 5 passes, 5 items. 
  - Selection sort maintains two parts: a sorted part, and an unsorted part.
  - It will terminate when there are no more values to move. 

#### C++ Example:
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
   - In Bubble Sort, neighbors continuously swap until no more swaps get made.
   - In Selection Sort, places one item into its proper spot every iteration.

2. **Number of Swaps**:
   - Bubble Sort can have a higher number of swaps in each pass through the array since it swaps neighbors
   - Selection Sort only swaps 1 item per iteration leading to n-1 swaps

3. **Adaptive Nature**:
   - Bubble Sort has a few tricks to add that allows it to terminate early.
   - Selection Sort makes the same number of comparisons regardless of the initial order of the elements.

4. **Performance**:
   - Bubble Sort generally performs worse than Selection Sort in terms of the number of comparisons and swaps, especially in the worst-case scenario.
   - Selection Sort has better performance than Bubble Sort due to fewer swaps but is still not suitable for large lists.

Both algorithms have limited practical applications due to their quadratic time complexity. They are inefficient for large datasets but are useful for educational purposes to illustrate the basics of sorting algorithms.