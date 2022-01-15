## Recursion Practice 2

```
int Mystery(int a, int b) {
    int result;
    if (b == 0)
        result = 0;
    else if (b > 0)
        result = a + Mystery(a, b - 1);
    else
        result = Mystery(-a, -b);
    return result;
}
```

### Show the output for the following function calls.

1. `cout << Mystery(4, 3);`
```






```
2. `cout << Mystery(3, 4);`
```






```
3. `cout << Mystery(5, 0);`
```






```
4. `cout << Mystery(-3, -2);`
```






```
5. `cout << Mystery(-8, 1);`
```






```

6. What is this recursive function calculating when called with `Mystery(x, y)`???
```






```

### Show the output for the following function calls.

```cpp
int Mystery2(int x) {
    if (x <= 1)
        return x;
    else
        return Mystery2(x - 1) + Mystery2(x / 2);
}
```

1. `cout << Mystery2(6); ` 
><sub>Hint:  Follow the left side of the addition all the way down first</sub>
```






```
2. `cout << Mystery2(5); ` 
><sub>Hint:  Don’t redo work you have already done.  Look back at work for 1.</sub>
```






```
3.	`cout << Mystery2(-4);`
```






```
4. Are there any values that would cause infinite recursion if passed to Mystery2?
```






```

