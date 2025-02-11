## Priority Queue - Binary Heap vs list and array Priority Queues

#### N/A

## **1. Binary Heap Costs**

A **binary heap** is a complete binary tree stored in an array, commonly used to implement **priority queues** efficiently.

### **Time Complexity of Binary Heap Operations**

| Operation                | Time Complexity | Explanation                                             |
| ------------------------ | --------------- | ------------------------------------------------------- |
| **Insert**               | **O(log n)**    | Uses **heapify-up** (bubble-up) to maintain heap order. |
| **Delete (Remove Root)** | **O(log n)**    | Swaps root with last element, then **heapify-down**.    |
| **Make Heap**            | **O(n)**        | Uses **Floyd’s method** (bottom-up heap construction).  |
| **Access Min/Max**       | **O(1)**        | Root contains the min (min-heap) or max (max-heap).     |

---

## **2. Implementing a Priority Queue Using an Array**

A **priority queue** allows efficient retrieval of the highest (or lowest) priority element.

### **Array-Based Implementation (Heap-Based)**

```cpp
#include <iostream>
using namespace std;

class MinHeap {
    int *heap;
    int capacity;
    int size;

public:
    MinHeap(int cap) {
        heap = new int[cap];
        capacity = cap;
        size = 0;
    }

    void insert(int value) {
        if (size == capacity) return;
        int i = size++;
        heap[i] = value;
        while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int extractMin() {
        if (size == 0) return -1;
        int root = heap[0];
        heap[0] = heap[--size];
        heapify(0);
        return root;
    }

    void heapify(int i) {
        int smallest = i, left = 2 * i + 1, right = 2 * i + 2;
        if (left < size && heap[left] < heap[smallest]) smallest = left;
        if (right < size && heap[right] < heap[smallest]) smallest = right;
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }
};

int main() {
    MinHeap pq(10);
    pq.insert(5);
    pq.insert(2);
    pq.insert(8);
    cout << "Min: " << pq.extractMin() << endl;
    return 0;
}
```

**Explanation:**

- **Insert (O(log n))**: New element is added at the end, then **heapify-up** maintains order.
- **Extract Min (O(log n))**: Root is removed, last element moved to root, and **heapify-down** restores order.

---

## **3. Implementing a Priority Queue Using a Linked List**

A priority queue can also be implemented using a **sorted linked list**.

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class PriorityQueue {
    Node* head;

public:
    PriorityQueue() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head || head->data > value) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* curr = head;
        while (curr->next && curr->next->data < value) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }

    int extractMin() {
        if (!head) return -1;
        int minVal = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        return minVal;
    }
};

int main() {
    PriorityQueue pq;
    pq.insert(5);
    pq.insert(2);
    pq.insert(8);
    cout << "Min: " << pq.extractMin() << endl;
    return 0;
}
```

### **Comparison of Implementations**

| Implementation         | Insert   | Extract Min | Memory Overhead           |
| ---------------------- | -------- | ----------- | ------------------------- |
| **Array (Heap)**       | O(log n) | O(log n)    | Uses an array (efficient) |
| **Sorted Linked List** | O(n)     | O(1)        | Extra memory for pointers |

**Conclusion:**

- **Heap-based priority queues** are **faster** for large datasets.
- **Linked-list priority queues** are **simpler** but less efficient for frequent insertions.

Both implementations have their uses depending on the constraints and requirements of a problem.
