## Recursion Practice 1
 

### Given the following:
```cpp
void message(int x) {
    if (x == 0)
        cout << "Base case \n";
    else {
        cout << "x = " << x << endl;
        message(x - 1);
    }
}
```
 
 
### Show the output for the following function calls (1-3). 
 
1. `message(3);`
```






```
2. `message(0);` 
```






```
3. `message(-5);` 
```






```
4. How could you change the code so that the following output is produced from the call message(3)? 
 
```
Base case
x = 1
x = 2
x = 3
```
```






```

-----

### Given the following:
```cpp
void F(char ch) {
    if ('A' <= ch && ch <= 'H') {
        F(ch - 1);
        cout << ch << endl;
    } else {
        cout << "** \n";
    }
}
```
 
 
 
### Show the output for the following function calls. 
 
1.	`F('D')` 
```






```
2.	`F('E')` 
```






```
3.	`F('2') `
```






```
4.	`F('D')` if `ch - 1` is replaced by `ch + 1` 
```






```
5.	`F('D') `if `ch - 1` is replaced by `ch + 1` and the output statement and the recursive call to `F()` are interchanged. 
```






```




 
 
