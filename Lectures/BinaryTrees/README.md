## Binary Trees - Example Code

#### N/A

# Warning

This sample has some issues that I need to fix. I will get them fixed soon.

To create a Makefile for your C++ project with the files `main.cpp`, `graphviz.h`, `graphviz.cpp`, and `bst.hpp`, you need to define a set of rules that tell `make` how to compile and link your program. Here's a basic example of what your Makefile might look like:

```makefile
# Compiler settings - Can be customized.
CC = g++
CFLAGS = -Wall -g -std=c++17

# Define the executable file
TARGET = myprogram

all: $(TARGET)

$(TARGET): main.o graphviz.o
    $(CC) $(CFLAGS) main.o graphviz.o -o $(TARGET)

main.o: main.cpp graphviz.h bst.hpp
    $(CC) $(CFLAGS) -c main.cpp

graphviz.o: graphviz.cpp graphviz.h
    $(CC) $(CFLAGS) -c graphviz.cpp

clean:
    rm -f *.o $(TARGET)
```

Here's a breakdown of this Makefile:

- **CC**: This is the compiler to use. In this case, we're using `g++`.
- **CFLAGS**: These are the flags passed to the compiler. `-Wall` enables all compiler's warning messages and `-g` adds debugging information to the executable file.
- **TARGET**: This is the name of the final executable file to be created.
- **all**: This is the default target. It depends on `$(TARGET)` and will build the `myprogram` executable.
- **$(TARGET)**: This target compiles `main.o` and `graphviz.o` into an executable. The dependencies are listed after the colon, and the command to create the target is on the next line, indented by a tab.
- **main.o**: This rule says how to create `main.o` from `main.cpp`. It also specifies that `main.o` depends on `graphviz.h` and `bst.hpp`, so if either of those header files changes, `main.cpp` will be recompiled.
- **graphviz.o**: Similarly, this is the rule for creating `graphviz.o` from `graphviz.cpp`.
- **clean**: This is a conventional target that cleans up the directory. It deletes all object files and the `myprogram` executable.

You can use this Makefile by running `make` to build your program, and `make clean` to clean up the build artifacts.

Note that if your project becomes more complex, you might need to modify your Makefile accordingly, such as adding more source files or adjusting compiler flags.
