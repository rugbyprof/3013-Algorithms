## Recursion

Recursion is a powerful concept in computer science, and starting with simple examples is a great way to help students grasp it without getting overwhelmed. Here are a few ideas for recursive functions that are straightforward and involve single recursive calls, much like your integer reversal example:

### 1. **Countdown Timer**
A simple function that takes an integer `n` and prints a countdown from `n` to 1. It's a nice way to illustrate how a problem can be broken down into smaller instances of itself.

```python
def countdown(n):
    if n <= 0:
        print("Blast off!")
    else:
        print(n)
        countdown(n-1)
```

### 2. **String Reversal**
Implement a function that takes a string as input and returns its reverse. This example helps students see recursion's utility beyond numeric computations.

```python
def reverse_string(s):
    if len(s) == 0:
        return s
    else:
        return s[-1] + reverse_string(s[:-1])
```

### 3. **Sum of an Array**
A function that calculates the sum of an array of numbers. This example can introduce the concept of recursion on collections.

```python
def sum_array(arr):
    if len(arr) == 0:
        return 0
    else:
        return arr[0] + sum_array(arr[1:])
```

### 4. **Fibonacci Numbers**
Although it might be a bit cliché, calculating a Fibonacci number is a classic example to show the simplicity and elegance of recursion. To keep it simple and avoid multiple recursive calls in one instance, you might choose to demonstrate this up to a small `n`.

```python
def fibonacci(n):
    if n <= 1:
        return n
    else:
        return fibonacci(n-1) + fibonacci(n-2)
```

### 5. **Factorial Calculation**
Calculating the factorial of a number is another classic example that's both simple and effectively demonstrates recursion.

```python
def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)
```

### 6. **Checking Palindromes**
A function that checks if a given string is a palindrome. This can be an interesting way to apply recursion to string manipulation and comparison.

```python
def is_palindrome(s):
    if len(s) <= 1:
        return True
    elif s[0] != s[-1]:
        return False
    else:
        return is_palindrome(s[1:-1])
```