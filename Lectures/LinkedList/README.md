## Linked Lists - Overview

#### Due: N/A

## **Introduction**

A **linked list** is a linear data structure where elements, known as **nodes**, are linked together using pointers. Unlike arrays, linked lists do not store elements in contiguous memory locations, which allows for **efficient insertions and deletions** but comes with additional memory overhead due to pointer storage.

---

## **Benefits of Linked Lists**

1. **Dynamic Size**: Unlike arrays, linked lists do not require pre-allocation of memory and can grow or shrink dynamically.
2. **Efficient Insertions/Deletions**: Inserting or deleting elements in a linked list is generally O(1) when modifying only pointers, whereas arrays require shifting elements (O(n)).
3. **Memory Utilization**: Since they are dynamically allocated, linked lists utilize only as much memory as needed.

---

## **Pitfalls of Linked Lists**

1. **Increased Memory Overhead**: Each node requires extra memory for storing pointers, making it less space-efficient than arrays.
2. **Slower Random Access**: Unlike arrays, which offer O(1) access by index, linked lists require O(n) time to access an element.
3. **Complex Implementation**: Handling pointers requires careful management to avoid issues such as memory leaks and segmentation faults.

---

## **Types of Linked Lists**

### **1. Singly Linked List**

<img src="https://images2.imgbox.com/18/ee/yLMoMRGV_o.png">

A **singly linked list** consists of nodes where each node has:

- A **data field**
- A **pointer to the next node**

#### **Example Implementation in C++**

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node{1, new Node{2, new Node{3, nullptr}}};
    printList(head);
    return 0;
}
```

#### **Justification for Singly Linked Lists**

- Simple and efficient for **insertion/deletion at the beginning**.
- Uses **less memory** than doubly linked lists due to single pointer.
- Good for **stack implementations** and simple sequential traversals.

---

### **2. Doubly Linked List**

<img src="https://images2.imgbox.com/e2/81/RUjLLtRT_o.png">

A **doubly linked list** extends the singly linked list by adding a **previous pointer** to each node, allowing traversal in both directions.

#### **Example Implementation in C++**

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node{1, nullptr, new Node{2, nullptr, nullptr}};
    head->next->prev = head;
    printList(head);
    return 0;
}
```

#### **Justification for Doubly Linked Lists**

- Allows **bi-directional traversal**.
- Efficient **deletion from both ends**.
- Used in **LRU caches**, **deque implementations**, and complex list operations.

---

### **3. Circular Linked List**

<img src="https://images2.imgbox.com/e1/4c/V695cORd_o.png">

A **circular linked list** is where the last node links back to the first node instead of pointing to NULL.

#### **Example Implementation in C++**

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printList(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(Back to head)" << endl;
}

int main() {
    Node* head = new Node{1, new Node{2, new Node{3, nullptr}}};
    head->next->next->next = head; // Circular link
    printList(head);
    return 0;
}
```

#### **Justification for Circular Linked Lists**

- Used in **round-robin scheduling** and **buffered memory management**.
- Eliminates need for NULL checks when traversing.
- Good for **queue-based applications**.

### Sorting a Linked List

- Linked lists are generally poor for sorting because they lack direct indexing, making efficient divide-and-conquer sorting algorithms like quicksort less effective.
- Unlike arrays, which allow O(1) random access, linked lists require O(n) time to traverse to a specific position. As a result, common sorting algorithms such as quicksort and mergesort have higher overhead when applied to linked lists.
- While mergesort is commonly used for linked lists due to its stability and ability to work well with sequential access, it still requires O(n log n) time complexity and extra memory for recursion.
- Insertion sort, which performs well on nearly sorted data, can work efficiently on linked lists with O(n²) complexity but is generally inefficient for large datasets.

---

## **Conclusion**

Linked lists are powerful and flexible data structures that provide **dynamic memory allocation** and **efficient insertions/deletions**. However, they come at the cost of additional memory overhead and slower access times compared to arrays. Choosing between **singly linked lists**, **doubly linked lists**, and **circular linked lists** depends on the specific use case and required operations. Also, sorting linked lists is usually not the best choice unless no other options are available.
