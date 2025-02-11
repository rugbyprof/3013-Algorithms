## Recursion - Introduction and Overview

#### Due: N/A

## **What is Recursion?**

Recursion is a programming technique where a function calls itself to solve smaller instances of a problem. It is widely used for problems that can be broken down into similar subproblems.

### **Key Components of Recursion:**

1. **Base Case**: Defines when the recursion should stop.
2. **Recursive Case**: Defines how the problem is broken down into smaller problems.

### **Advantages of Recursion:**

- Reduces code complexity for problems that naturally fit recursion (e.g., tree traversal).
- Provides a clean and intuitive solution.

### **Disadvantages of Recursion:**

- Can lead to excessive memory usage due to function call overhead.
- Risk of stack overflow if the base case is not reached or implemented improperly.
- Often less efficient than iterative approaches for simple problems.

---

## **Recursion Examples**

### **1. Adding the Digits in an Integer**

```cpp
#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    int num = 1234;
    cout << "Sum of digits: " << sumOfDigits(num) << endl;
    return 0;
}
```

**Explanation:** This function extracts the last digit (`n % 10`) and recursively processes the remaining number (`n / 10`).

---

### **2. Print a String or Integer in Reverse**

```cpp
#include <iostream>
using namespace std;

void reverseString(string str, int index) {
    if (index < 0) return;
    cout << str[index];
    reverseString(str, index - 1);
}

int main() {
    string str = "hello";
    reverseString(str, str.length() - 1);
    return 0;
}
```

**Explanation:** This function prints the last character first and recursively processes the rest of the string.

---

### **3. Traversing an Array Recursively**

```cpp
#include <iostream>
using namespace std;

void traverseArray(int arr[], int size, int index) {
    if (index == size) return;
    cout << arr[index] << " ";
    traverseArray(arr, size, index + 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    traverseArray(arr, 5, 0);
    return 0;
}
```

**Explanation:** Processes the array element at `index` and moves forward.

---

### **4. Traversing a Linked List Recursively**

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printList(Node* head) {
    if (head == nullptr) return;
    cout << head->data << " ";
    printList(head->next);
}

int main() {
    Node* head = new Node{1, new Node{2, new Node{3, nullptr}}};
    printList(head);
    return 0;
}
```

**Explanation:** Processes the current node and moves to the next node recursively.

---

### **5. Factorial Calculation**

```cpp
#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main() {
    cout << "Factorial of 5: " << factorial(5) << endl;
    return 0;
}
```

**Explanation:** Multiplies `n` with `factorial(n-1)` until reaching `n == 0`.

---

### **6. Fibonacci Sequence**

```cpp
#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    cout << "Fibonacci of 6: " << fibonacci(6) << endl;
    return 0;
}
```

**Explanation:** Adds the previous two numbers in the sequence to compute the next number.

---

### **7. Power Function (Exponentiation)**

```cpp
#include <iostream>
using namespace std;

int power(int base, int exp) {
    if (exp == 0) return 1;
    return base * power(base, exp - 1);
}

int main() {
    cout << "2^4: " << power(2, 4) << endl;
    return 0;
}
```

**Explanation:** Multiplies `base` recursively until `exp == 0`.

---

### **8. Palindrome Detection**

```cpp
#include <iostream>
using namespace std;

bool isPalindrome(string str, int left, int right) {
    if (left >= right) return true;
    if (str[left] != str[right]) return false;
    return isPalindrome(str, left + 1, right - 1);
}

int main() {
    string str = "racecar";
    cout << (isPalindrome(str, 0, str.length() - 1) ? "Palindrome" : "Not a palindrome") << endl;
    return 0;
}
```

**Explanation:** Compares the first and last characters and moves inward recursively.

---

## **Conclusion**

Recursion is a powerful technique that simplifies problem-solving for certain types of problems. However, it must be used carefully to avoid excessive function calls and inefficiencies. Understanding when to use recursion versus iteration is key to writing optimal code.
