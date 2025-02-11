# **Floyd’s Makeheap Algorithm**

## **Introduction**

Floyd’s **Makeheap algorithm** (also known as **Floyd’s heap construction**) is an efficient method for converting an **unsorted array into a binary heap**. It follows a **bottom-up heapification** approach, ensuring that all parent nodes satisfy the heap property.

### **Key Concepts**

1. **Heap Property**: In a **min-heap**, each parent node is smaller than its children; in a **max-heap**, each parent node is larger than its children.
2. **Bottom-up Heap Construction**: Instead of inserting elements one by one (which takes **O(n log n)** time), Floyd’s algorithm starts from the last **non-leaf node** and applies **heapify-down (sift-down)** operations to restore the heap property.
3. **Efficiency**: The algorithm runs in **O(n)** time, which is optimal for heap construction.

---

## **Floyd’s Makeheap Algorithm Steps**

1. **Start from the last parent node** (i.e., the last node that has children).

- The last parent node is at index **_(n/2) - 1_** (zero-based indexing).

2. **Heapify down** (sift down) each parent node to maintain the heap property.

- Compare the node with its children.
- Swap with the largest child (for a max heap) or the smallest child (for a min heap).
- Repeat the process until the subtree satisfies the heap property.

3. **Continue moving up** towards the root, ensuring each subtree is a valid heap.
4. **When reaching the root**, the entire array is now a valid **max heap** (or **min heap**, if adjusted).

---

## **C++ Implementation of Floyd’s Makeheap**

```cpp
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i; // Root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check if left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check if right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void floydMakeHeap(int arr[], int n) {
    // Start from the last non-leaf node and heapify down
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    floydMakeHeap(arr, n);
    cout << "Heapified array: ";
    printArray(arr, n);
    return 0;
}
```

### **Explanation of C++ Code**

1. **heapify()**: Recursively maintains the heap property for a given subtree.
2. **floydMakeHeap()**:
   - Starts from the last non-leaf node (`n/2 - 1`).
   - Calls `heapify()` on each node **bottom-up**, ensuring the entire array becomes a heap.
3. **printArray()**: Displays the heapified array.
4. **Main function**:
   - Defines an unsorted array.
   - Calls `floydMakeHeap()` to construct the heap in **O(n) time**.
   - Prints the transformed heap.

---

## **Time Complexity Analysis**

| Operation            | Complexity |
| -------------------- | ---------- |
| **Heapify a node**   | O(log n)   |
| **Floyd’s Makeheap** | O(n)       |

- Unlike **naïve heap construction** (inserting elements one by one, O(n log n)), Floyd’s algorithm runs in **O(n)** time.
- The **heapify-down** operation is efficient because it processes **fewer nodes at deeper levels**.

---

## **Conclusion**

- **Floyd’s Makeheap algorithm** efficiently converts an unsorted array into a **binary heap** in **O(n) time**.
- It is widely used in **heap sort** and **priority queue construction**.
- The **bottom-up approach** minimizes unnecessary swaps, making it superior to naive insertion-based heap construction.

This method is a fundamental component in efficient heap operations and is widely used in algorithmic implementations.
