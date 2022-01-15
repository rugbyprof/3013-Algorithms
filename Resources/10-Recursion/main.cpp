#include <iostream>

using namespace std;

void message(int x) {
    if (x == 0)
        cout << "Base case \n";
    else {
        cout << "x = " << x << endl;
        message(x - 1);
    }
}

void F(char ch) {
    if ('A' <= ch && ch <= 'H') {
        F(ch - 1);
        cout << ch << endl;
    } else {
        cout << "** \n";
    }
}

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

int Mystery2(int x) {
    if (x <= 1)
        return x;
    else
        return Mystery2(x - 1) + Mystery2(x / 2);
}

int main() {
    return 0;
}