## Bubble Sort vs Selection Sort - A comparison

#### N/A

## **1. Overview**

Sorting algorithms play a crucial role in computer science. Two simple comparison-based sorting algorithms are **Bubble Sort** and **Selection Sort**. This document provides an in-depth comparison, including implementations in C++ and insights into performance, optimizations, and pitfalls.

---

## **2. Bubble Sort**

### **How It Works**

Bubble Sort repeatedly steps through the array, compares adjacent elements, and swaps them if they are in the wrong order. This process continues until the array is fully sorted.

### **C++ Implementation**

```cpp
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) // If no swaps occurred, array is sorted
            break;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
```

### **Complexity Analysis**

- **Best Case (Already Sorted):** O(n)
- **Worst Case (Reverse Sorted):** O(n²)
- **Average Case:** O(n²)

### **Optimizations & Pitfalls**

- Adding a `swapped` flag can improve performance if the array is nearly sorted.
- Inefficient for large datasets due to O(n²) complexity.
- Stable sort (preserves relative order of equal elements).

---

## **3. Selection Sort**

### **How It Works**

Selection Sort divides the array into a sorted and an unsorted region. It repeatedly finds the minimum element from the unsorted part and swaps it with the leftmost unsorted element.

### **C++ Implementation**

```cpp
#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
```

### **Complexity Analysis**

- **Best Case:** O(n²)
- **Worst Case:** O(n²)
- **Average Case:** O(n²)

### **Optimizations & Pitfalls**

- Unlike Bubble Sort, Selection Sort always performs O(n²) comparisons, regardless of the input.
- Generally performs fewer swaps than Bubble Sort (O(n) swaps compared to O(n²) swaps in Bubble Sort).
- Not a stable sort (may change relative order of equal elements).
- Slightly better performance than Bubble Sort in practice but still inefficient for large datasets.

---

## **4. Comparison Table**

| Feature                       | Bubble Sort                          | Selection Sort |
| ----------------------------- | ------------------------------------ | -------------- |
| Time Complexity (Best)        | O(n) (optimized)                     | O(n²)          |
| Time Complexity (Worst)       | O(n²)                                | O(n²)          |
| Time Complexity (Average)     | O(n²)                                | O(n²)          |
| Number of Swaps               | High (O(n²))                         | Low (O(n))     |
| Stable Sorting                | Yes                                  | No             |
| Works Well For                | Small datasets or nearly sorted data | Small datasets |
| Performance on Large Datasets | Poor                                 | Poor           |

---

## **5. Conclusion**

- **Bubble Sort** can be optimized with a swap flag but is still slow for large datasets.
- **Selection Sort** performs fewer swaps but always takes O(n²) comparisons.
- Both are **inefficient for large datasets** and should be replaced by **Merge Sort, Quick Sort, or Heap Sort** for better performance.

### **Recommendation**

- If stability is required, use **Bubble Sort**.
- If minimizing swaps is important, use **Selection Sort**.
- For real-world applications, prefer **Merge Sort** or **Quick Sort** for significantly better performance.
