#include "mygetch.hpp"
#include <iostream>

using namespace std;

int main() {
    char k;

    while ((k = getch()) != 'Z') {
        cout << "Key: " << k << " = " << (int)k << endl;
    }
    return 0;
}