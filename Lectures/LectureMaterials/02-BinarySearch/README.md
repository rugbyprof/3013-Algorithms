## Binary Search
#### Due: N/A 


<img src="https://images2.imgbox.com/e1/44/KxfIEB9m_o.gif">

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
- `[1, 3, 5, 7, 9, 11, 13, 17, 23, 37]`
- Key =  `23`.

----
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

-----

In this example, the binary search found `23` in three steps, which is much more efficient than linear search for larger arrays.

### Conclusion

Binary search is a highly efficient algorithm for searching in sorted arrays. It significantly reduces the number of comparisons needed to find an element, compared to linear search. `However, its effectiveness is contingent on the array being sorted.` This makes binary search a great example of the trade-off between sorting cost and search efficiency.
