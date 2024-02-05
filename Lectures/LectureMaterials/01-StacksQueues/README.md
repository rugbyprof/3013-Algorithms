## Review - Stacks & Queues
#### Due: N/A 

Stacks and queues are fundamental data structures used in computer science to store and manage data. Both are linear structures with their unique way of handling elements, primarily differing in the order in which elements are removed.

### Stacks (LIFO: Last In, First Out)

A stack is a collection of elements that supports two principal operations: push, which adds an element to the collection, and pop, which removes the most recently added element. The last element added is the first one to be removed, making it a Last In, First Out (LIFO) structure. Think of a stack of plates; you can only take the top plate off and add a new plate on top.

#### C++ Example using Array
```cpp
const int SIZE = 100;
int stack[SIZE];
int top = -1;

void push(int value) {
    if (top >= SIZE - 1) {
        cout << "Stack Overflow" << endl;
    } else {
        stack[++top] = value;
    }
}

int pop() {
    if (top < 0) {
        cout << "Stack Underflow" << endl;
        return 0;
    } else {
        return stack[top--];
    }
}
```

### Queues (FIFO: First In, First Out)

A queue, on the other hand, allows the removal of the element that was added first, making it a First In, First Out (FIFO) structure. This is akin to a line of people waiting in a queue where the first person in line is the first to be served and leave the queue.

#### C++ Example using Array (Bounded Queue)
```cpp
const int SIZE = 100;
int queue[SIZE];
int front = 0;
int rear = -1;

void enqueue(int value) {
    if (rear >= SIZE - 1) {
        cout << "Queue Overflow" << endl;
    } else {
        queue[++rear] = value;
    }
}

int dequeue() {
    if (front > rear) {
        cout << "Queue Underflow" << endl;
        return 0;
    } else {
        return queue[front++];
    }
}
```

### Circular Array BasedQueue 

A circular queue is a linear data structure that uses a single, fixed-size buffer as if it were connected end-to-end. This structure allows it to efficiently use space by wrapping around to the beginning of the buffer when it reaches the end. This approach solves some of the problems of implementing a queue with a bounded array, specifically the inefficient use of space that occurs in a linear queue once elements are dequeued from the front.

Here's a basic C++ implementation of a circular queue, followed by some operations that demonstrate pushing and popping of elements, which will lead to the front and rear indices moving around the buffer:

```cpp
#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int front, rear, size;

public:
    CircularQueue(int size) {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        arr[rear] = value;
        cout << "Enqueued: " << value << "\n";
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int temp = arr[front];
        if (front == rear) {
            front = rear = -1; // Queue becomes empty
        } else {
            front = (front + 1) % size;
        }
        cout << "Dequeued: " << temp << "\n";
        return temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        int i = front;
        cout << "Queue elements: ";
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << "\n";
    }
};

int main() {
    CircularQueue q(5); // Create a circular queue of size 5

    // Enqueue elements
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    q.display(); // Display queue contents

    // Dequeue elements
    q.dequeue();
    q.dequeue();

    q.display(); // Display queue after two dequeues

    // Enqueue more elements to show circular nature
    q.enqueue(5);
    q.enqueue(6);

    q.display(); // Should wrap around and display properly

    return 0;
}
```

In this example, the circular queue is initialized with a size of 5. We enqueue some elements, then dequeue a couple, and enqueue more to show how the front and rear indices move. When the rear index reaches the end of the array (index 4 in a 0-indexed array with size 5), the next element enqueued wraps around to the beginning of the array, utilizing the spaces freed up by dequeues.

### Problems with Implementing a Queue in a Bounded Array

The main challenge is the inefficient use of space. In a simple array-based implementation, once an element is dequeued from the front, that space cannot be reused for new elements being enqueued, leading to wasted space. A circular queue addresses this by allowing the rear of the queue to wrap back to the beginning of the array once it reaches the end, thus reusing the space from which elements have been dequeued.

### Contemporary Uses

- **Stacks**: Often used for managing function calls (call stack), parsing expressions (like in compilers), undo mechanisms in editors, and backtracking algorithms (like maze solving).
- **Queues**: Used in scheduling tasks (like CPU and IO scheduling), handling asynchronous data (like in web server request management), and in breadth-first search algorithms.

### Contemporary Uses
- **Stacks** are used in situations like:
  -  function call management in programming languages (call stack), 
  -  expression evaluation and syntax parsing, 
  -  undo mechanisms in editors
  -  backtracking algorithms.
  
- **Queues** are used in:
  -  scheduling tasks (like print job management), 
  -  handling asynchronous data (like IO Buffers), 
  -  in algorithms like breadth-first search (BFS) for graph traversal, 
  -  in scenarios requiring fairness where the first come should be the first served (like customer service systems).


### Complex Data Structures

- Both stacks and queues are foundational in more complex data structures:

  - **Stacks** 
    - graph algorithms (DFS)
    - recursive algorithms, 
    - parsing and evaluating expressions (e.g., infix to postfix conversion)
    - memory management schemes

  - **Queues** 
    - graph algorithms (like BFS)
    - implementing 
    - various synchronization problems in concurrent programming (e.g., producer-consumer problem)
    - caches
    - buffers (like IO buffers)

Despite their simple concepts, stacks and queues are incredibly powerful and versatile, making them indispensable in computer science.
