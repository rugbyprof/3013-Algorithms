### Recursive Print expression

Not really an expression, but this function will print (for example) if you call `sumDigitsExpression(12345, total)`
it will print: `1 + 2 + 3 + 4 + 5 = 15`.

```c++
#include <iostream>
#include <string>

/**
 * A single recursive function that returns the digit-expression string
 * (e.g., "1 + 2 + 3 + 4 + 5") and updates 'sum' by reference.
 *
 * We then append " = 15" after the recursion finishes in 'main' (or a wrapper).
 */
std::string sumDigitsExpression(int n, int &sum) {
    if (n < 10) {
        sum = n;  // base case: sum is just that one digit
        // return the single digit as the entire string so far
        return std::to_string(n);
    } else {
        // recursive call on leading part (n / 10)
        std::string partial = sumDigitsExpression(n / 10, sum);

        // now sum contains the sum of all leading digits
        int digit = n % 10;
        sum += digit;  // add the last digit

        // build out the partial expression by adding " + digit"
        return partial + " + " + std::to_string(digit);
    }
}

int main() {
    int number = 12345;
    int total = 0;

    // single function call to build the expression AND compute sum
    std::string expression = sumDigitsExpression(number, total);

    // Now 'total' holds the sum of the digits
    expression += " = " + std::to_string(total);

    std::cout << expression << std::endl;
    // Output: 1 + 2 + 3 + 4 + 5 = 15

    return 0;
}
```

### How It Works

1. Base Case (n < 10)
   - Directly set sum = n.
   - Return just the digit as the string (e.g., "7").
2. Recursive Case (for multi-digit n)
   - Recursively call on n / 10, which returns something like "1 + 2 + 3" and updates sum to (1+2+3=6).
   - Add the last digit digit = n % 10 to sum.
   - Return partial + " + " + std::to_string(digit).
3. Final Step
   - In main, you just append " = " + std::to_string(total) to the returned expression.
