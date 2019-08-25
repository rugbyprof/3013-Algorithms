## Day 2 - Trees and Intro to Heaps

### Overview

This lecture was all about going over the parts and complexity of a `binary tree`, and then
how we can store a `binary tree` in an array efficiently if we follow a set of rules (notice
I did not say `binary search tree`):

### Quick Notes

- Always make the sure the tree is complete (filled in from left to right).
- Ummm. Thats really it. 
- How do we make it stay in heap order?
    - Insertion
        - Add to next available location in array, and bubble up comparing value to parent and swapping if the child is smaller (min heap) or larger (max heap).
        - O(lg N)
    - ExtractMin, ExtractMax
        - Remove item from front of array (location 1).
        - Replace with last item in array, and bubble that item down using heap order rules mentioned above.
        - The actual removal is O(1), but to place swapped item into proper location is O(lg N).



- https://en.wikipedia.org/wiki/Tree_(data_structure)
- https://en.wikipedia.org/wiki/Heap_(data_structure)