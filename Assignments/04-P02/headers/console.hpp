/**
 *    Description: This header file contains console functions and determines which libraries to use based on your OS (windows or linux).
 *    Data Types:
 *        - struct console_size - width and height of the console
 *    Functions:
 *        - getConsoleSize() - which gets the rows and columns of the console
 *        - clearConsole() - this function clears the console
 *        - getch() - and this function gets a character from the console without printing it (unless you want to print it)
 */

#ifndef CONSOLE_UTILS_HPP
#define CONSOLE_UTILS_HPP

#include <cstdio>   // For getchar()
#include <iostream> // For std::cout

#ifdef _WIN32 // Windows specific includes
#include <windows.h>
#else // Linux specific includes
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#endif

struct consoleSize {
    int width;
    int height;
};

// Function to get console size
consoleSize getConsoleSize() {
    consoleSize console_size;
#ifdef _WIN32 // Windows implementation
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    console_size.width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    console_size.height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
#else // Linux implementation
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    console_size.width = size.ws_col;
    console_size.height = size.ws_row;
#endif
    return console_size;
}

// Function to clear console
void clearConsole() {
#ifdef _WIN32 // Windows implementation
    system("cls");
#else // Linux implementation
    std::cout << "\033[2J\033[1;1H";
#endif
}

// Function to get a single character from console input
char getch;
#ifdef _WIN32 // Windows implementation
#include <conio.h>
#include <windows.h>
_getch();

#else // Linux implementation
getch = linuxGetch();
#endif

#endif // CONSOLE_UTILS_HPP

void (*funcPtr)() = myFunction;

char windowsGetch() {

    char linuxGetch() {
        struct termios oldt, newt;
        char ch;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return ch;
    }
