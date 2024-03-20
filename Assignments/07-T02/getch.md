## Getch

The `getch` function is a commonly used input function in C and C++ programming, especially in console applications. It is part of the conio.h (console input/output) header file, which is a non-standard header used primarily in MS-DOS compilers to provide console input/output capabilities. The name `getch` stands for "get character".

### Functionality

- **Reading a Character**: `getch` reads a single character from the keyboard without echoing it to the console. This means that when you press a key, it won't be displayed on the screen, which is different from standard input functions like `scanf` or `cin` that display the typed characters.
- **No Buffering**: It does not wait for the Enter key to be pressed; the program continues as soon as any key is pressed. This contrasts with standard input methods, which typically wait for the user to press Enter and submit the input.

- **Portability**: Because `conio.h` and consequently `getch` are not part of the standard C/C++ libraries, their use is generally limited to platforms where `conio.h` is available, such as **Windows**. This limits the portability of code that relies on `getch`. This is normally NOT the case where windows has a better implementation for something like getch, but they do!
- **Alternatives in Unix/Linux**: For Unix-like systems, similar functionality can be achieved using different libraries. Here is a linux function that mimics the getch behavior. it turns off **canonical mode** and **echo**. 

### Linux Getch

This implementation uses the `termios` library to change terminal settings, disabling canonical mode (`ICANON`) and echoing of input characters (`ECHO`), to allow for reading a single character from the keyboard without waiting for the Enter key and without echoing the character to the screen.

```c++
#include <termios.h>
#include <thread>
#include <unistd.h>

char getch(void) {
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    return buf;
}
```
  
- **Canonical Mode**: input is `buffered`.
- **Buffered**: The terminal driver collects input characters until a newline character (\n) or carriage return (\r) is encountered before making the input available to a reading process. This allows the user to edit the line of input (using backspace or delete) before submitting it.

- **Non Canonical Mode**: input is not `buffered` or `raw`.
- **Non Buffered**: Each keystroke is made available to applications immediately without the user needing to press Enter. This allows for more interactive and immediate responses to user input, which is useful in applications like text editors, games, and real-time command interfaces.

- **Echo**: input is printed to the terminal. Turning echo off, stops that behavior. 

### Windows Getch Example

Very simple to use since windows includes getch in `conio.h`

```c++
#include <conio.h>

char ch;
ch = getch();
```

### Use Cases 

These apply to Windows and Linux, since getch() really just means to pass input to the terminal without buffering characters. Each OS just implements this differently.

- **Password Input**: One of the most common uses of `getch` is for entering passwords or other sensitive information. Since `getch` does not echo the characters to the screen, it can be used to conceal the input.
- **Interactive Menus**: For creating interactive command-line menus where an action is performed immediately when a key is pressed, without needing to press Enter.
- **Game Development**: In simple console-based games, `getch` can be used to read player inputs for movements or actions without the clutter of echoed characters or the need to press Enter.
- **Real-time Input Handling**: Any scenario where immediate reaction to key presses is required without the overhead of buffering and line editing.


### Windows Password Input

Here's a simple example of using `getch` to read a password:

```c++
#include <conio.h>
#include <stdio.h>

int main() {
    char ch;
    char password[50];
    int i = 0;
    printf("Enter password: ");

    while(1) {
        ch = getch(); // Get character without echoing
        if(ch == '\r' || ch == '\n') { // Enter key is pressed
            break;
        } else {
            password[i++] = ch;
            printf("*"); // Echoing '*' for each character entered
        }
    }
    password[i] = '\0'; // Null terminate the password string

    printf("\nYour entered password is: %s\n", password);
    return 0;
}
```

### Linux Example Password Input

This uses the linux `getch()` function defined above.

```c++
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

// Your getch() function as defined above...

int main() {
    char ch, password[100];
    int i = 0;
    printf("Enter password: ");

    while ((ch = getch()) != '\n' && i < sizeof(password) - 1) {
        if (ch == 127) { // Handle backspace
            if (i > 0) {
                printf("\b \b"); // Move cursor back, print space, move cursor back again
                i--;
            }
        } else {
            password[i++] = ch;
            printf("*");
        }
    }
    password[i] = '\0';

    printf("\nYour entered password is: %s\n", password);
    return 0;
}
```
### Arrow Keys

Capturing arrow keys on windows or linux, ends up being a two character event. The first character is an escape sequence or special character followed by the specific character that represent a specific arrow key.

- **First Character**
  - Windows
    - The first character is a special key usually `0xE0` or `0x00`.
  - Linux
    -  The first character is an escape sequences. `ESC[A`.
- **Second Character**
  - Windows
    - H (Up)
    - P (Down)
    - M (Right)
    - K (Left)
  - Linux
    - `\033[A` (Up)
    - `\033[B` (Down)
    - `\033[C` (Right)
    - `\033[D` (Left)

### Windows Detecting Arrow Keys

This example will continue looping until the escape key is pressed. It will only print something if an arrow key is pressed, however.

```c++
#include <conio.h>
#include <stdio.h>

int main() {
    int ch, ch2;
    printf("Press an arrow key...\n");

    while(1) {
        ch = getch(); // Get the first character
        if (ch == 0xE0 || ch == 0x00) { // Check for arrow keys (0xE0 for extended keys, 0x00 for function keys)
            ch2 = getch(); // Get the next character in the sequence

            switch(ch2) {
                case 72: // Up arrow key (H)
                    printf("Up\n");
                    break;
                case 80: // Down arrow key (P)
                    printf("Down\n");
                    break;
                case 75: // Left arrow key (K)
                    printf("Left\n");
                    break;
                case 77: // Right arrow key (M)
                    printf("Right\n");
                    break;
                default:
                    printf("Other key\n");
                    break;
            }
        } else if (ch == 27) { // ESC key to exit
            break;
        }
    }

    return 0;
}
```

### Capturing Arrow Keys on Linux

Capturing arrow keys in a terminal environment is slightly more complex because arrow keys are sent as escape sequences. For example, the up arrow key sends the sequence `ESC[A` (`\033[A`). 

This code runs just like the windows example. It stops when the escape key is pressed, and will only echo output if an arrow key is pressed. 

```c
#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

// Linux getch() function as defined above...

int main() {

    printf("Press an arrow key (ESC to exit)...\n");
    char ch;
    while ((ch = getch()) != 27) { // ESC key to exit
        if (ch == '\033') { // Start of escape sequence
            getch(); // Skip the '[' character
            switch(getch()) { // The third character determines the arrow key
                case 'A':
                    printf("Up arrow\n");
                    break;
                case 'B':
                    printf("Down arrow\n");
                    break;
                case 'C':
                    printf("Right arrow\n");
                    break;
                case 'D':
                    printf("Left arrow\n");
                    break;
            }
        }
    }
    return 0;
}
```