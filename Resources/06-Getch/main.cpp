#include "mygetch.hpp"
#include <iostream>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#define OS "WINDOWS"
#else
#define OS "LINUX"
#endif

using namespace std;

int main() {
    char k;

    while ((k = getch()) != 'Z') {
        cout << "Key: " << k << " = " << (int)k << endl;
    }
    return 0;
}