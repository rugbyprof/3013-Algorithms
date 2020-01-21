## Comments

Comments are important! You think they are not, but they really are. In the real world, your comments will allow another programmer to read and understand your code much faster. Un-commented code could (and does) take much much longer to digest. I read my own programs from just a few months ago and wonder ... what was I thinking?!? 

In the case of academia, they are still important. Your comments help me (or the grader) figure out if your program works as expected, or what you were trying to do if things aren't working properly.

- RULE 1: Every program will have comments. 
- RULE 2: If I didn't mention it in class or write it on the assignment, refer to RULE 1. 
- RULE 3: I'm allowed to make cheesy, but effective jokes. 

### Example Program Comment Block 

Every program will have a comment block nearly IDENTICAL in structure to the one below. Do NOT remove the slashes. It makes a very distinct BOX like effect. Keep it as is and only replace the pertinant information.
This is the comment that will go into your main driver program. It is also the top page when turning in a 
printed program (unless we create a banner page).

#### Program Comment Template:

```cpp

///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           (your name)
// Email:            (your email address)
// Label:            (program's label from assignment list)
// Title:            (short title from assignment, if any)
// Course:           (course number and prefix)
// Semester:         (semester and year)
//
// Description:
//       describe program here thoroughly 
//
// Usage:
//       how to use program if necessary
//
// Files:            (list of all source files used in this program)
/////////////////////////////////////////////////////////////////////////////////
```

#### Program Comment Example:

```cpp
///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Terry Griffin
// Email:            terry.griffin@msutexas.edu
// Label:            A04
// Title:            Linked List Class
// Course:           CMPS 3013
// Semester:         Spring 2020
//
// Description:
//       This program implements a class that allows a linked list to be used just like 
//       an array. It overloads the "[]" (square brackets) to simulate accessing seperate 
//       array elements, but really it traverses the list to find the specified node using
//       an index value. It also overloads the "+" and "-" signs allowing a user to "add"
//       or "push" items onto the end of the list, as well as "pop" items off the end of our 
//       array. This class is not meant to replace the STL vector library, its simply a project
//       to introduce the beginnings of creating complex / abstract data types. 
//       
// Usage: 
//      - $ ./main filename
//      - This will read in a file containing whatever values to be read into our list/array. 
//      
// Files:            
//      main.cpp    : driver program 
//      list.h      : header file with list defintion
//      list.cpp    : list implementation
/////////////////////////////////////////////////////////////////////////////////
```


