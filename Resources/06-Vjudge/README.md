## Uploading to UVA Online Judge

> Adapted from Zachary Kingcades tutorial.

## Overview
There is a little different angle we must take when writing code to be uploaded to https://onlinejudge.org/. Just like I have stressed in class (oh remember the days when we had class ...) having a base knowledge of the use of the command line can be beneficial. This tutorial will discuss a couple of those skills and prepare you for uploading code to UVA Online judge.

1. Compile using command Line
2. Redirect input using command line
3. Submit a solution to onlinejudge


These are the skills that are used at programming competitions, but even better ... at some interviews!


### Registration and Overview

Onlinejudge has thousands of problems to browse and solve. You can look at them without registering, but you will need to register to submit solutions so go ahead and do that [HERE](https://onlinejudge.org/index.php?option=com_comprofiler&task=registers). 

The major portion of Onlinejudge is its [uHunt](https://uhunt.onlinejudge.org/) section. This is where you browse problems, submit your solutions, see statistics about each problem, see latest submissions, and most importantly where you see the status of your own submissions. You can click on the link I provided or look for this on the main page: 

<a href="https://uhunt.onlinejudge.org/"><img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/uva_icon_sp_2020.png" width="50"></a>

### Selecting A Problem

There are many different ways and reasons to select a problem. You can use the book I provided and choose a problem that deals with a certain skill set (which is why we are doing this for class). You can select a problem based on its difficulty. Believe it or not, people actually solve these for fun! And I would recommend you find many of these in addition to your course work to pad your resume`. To choose a problem you can simple [browse](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8) them (see image below). There are a ton. We will mostly be looking at the problem set I put a box around.

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/brows_problems_sp_2020.png" width="500">

Another way to choose problems (as I previously mentioned) is difficulty. If you click on the top link (see image above) it opens into another list of folder with problems. If you drill down into any of the folders you will end up seeing something similar to below:

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/problem_difficulty_sp_2020.png" width="500">

We can see in a brief glance that lots of "red" = hard, and lots of "green" = easy (generally).  The left column shows how many total submissions vs how many solved. In other words, it takes many submissions before someone gets it correct. The right column is percentage of people that attempted the problem actually solved it. So, if you want an easy problem, find one that has a left column with 90+ solution percentage.


If you need to find a specific problem, they all have numbers (the ones we will use). So you can go to onlinejudge.org and browse problems using the number to navigate folders, or you can go to uHunt and put the number in a search form:

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/problem_search_uhunt.png" width="300">

This will bring up a link to the problem description which you can download and keep as a reference as your solving. I typically create a folder with the problem number as the folder name, and save everything in there.

In the actual assigned problems, I will get into more background and why I chose the particular problem. For now, you just need to break the ice and get a solution uploaded to uHunt. So lets start with a super easy one called `11172 - Relational Operator`

### Solving A Problem

Go get the pdf of the problem using the number "11172". But for convenience here is its contents:

-----

### 11172 - Relational Operator

Some operators checks about the relationship between two values and these operators are called relational operators. Given two numerical values your job is just to find out the relationship between them that is (i) First one is greater than the second (ii) First one is less than the second or (iii) First and second one is equal.

#### Input

First line of the input file is an integer `t (t < 15)` which denotes how many sets of inputs are there. Each of the next `t` lines contain two integers `a` and `b` `(|a|, |b| < 1000000001)`.

#### Output

For each line of input produce one line of output. This line contains any one of the relational operators `>`, `<` or `=`, which indicates the relation that is appropriate for the given two numbers.

#### Sample Input

```
3
10 20
20 10
10 10
```

#### Sample Output

```
<
>
=
```

-----

### Solving the problem

Now read over the problem and think of a solution. This one is easy, so you won't need much time. Typically we recommend that you THINK about it, and solve it on paper. Always look at the limits as described in the problem (e.g. `t < 15` and `(|a|, |b| < 1000000001)`). These could have an impact on the solution. Like does `1000000001` fit in an integer data type? 

After you come up with a proposed solution, start to code it. Normal conventions that we stress in class are a little out the window. NOT all, but some. Variable names all declared on the same line ... OK! Typically we want you to comment your code. In larger solutions where a function seems appropriate, you may want to stay inline as a function call is ever so slightly slower than inline code. Another example of a miniscule speedup is re-defining `endl`. This `endl` causes a newline AND a flush of the output buffer. If one of the problems has you writing to standard out thousands and thousands of times, it may slow you down. So redefine `endl = \n` is, again, a tiny speedup. 

Last thing: **cin** is NOT being used to prompt a user for input. It is being used to read from an input file! Jump below the code ...

#### main.cpp
```cpp
1 #include <iostream>
2
3 #define endl "\n"
4
5 using namespace std;
6
7 int  main(){
8     int c,l,r,i=0;
9     cin>>c;
10     while(i<c){
11         cin>>l>>r;
12         if(l<r){
13             cout<<'<'<<endl;
14         }else if(l>r){
15             cout<<'>'<<endl;
16         }else{
17             cout<<'='<<endl;
18         }
19         i++;
20     }
21     return 0;
22 }
```

#### infile
```
3
10 20
20 10
10 10
```

**cin** reads from [stdin](https://en.wikipedia.org/wiki/Standard_streams) which means a default connected stream for whatever platform you are on. Typically when you run a program, and you need input, you pause execution of the program with a `cin` and then it waits for input from the "keyboard". And when you write using `cout` it writes to `stdout` which is usually the terminal (or dos window). As a side note there is also `stderr` which is where errors are directed to (we don't deal with stderr, as its usually used with log files and such).

We change `stdin` to be input from a file. Why? If you upload your code to be auto run, how do you process a file? You could be given a path and a file name, but its actually easier to redirect a file into your program.

Given:

- code is in `main.cpp`
- we compile and its executable is now `main.exe`
- we have an input file called `infile`

We can read `infile` using `cin` by doing:
```
./main.exe < infile 
```

We simply changed `stdin` to be a file, instead of the keyboard. 

If you refer back to the code snippet, and infile, 
- line 9 reads in the 3, telling us how many "pairs" of values we need to read.
- line 11 then reads in two values for every iteration of the loop

### Run in Visual Studio :(

You have to edit the projects properties. So whichever side your solution explorer is: 

- Right Click on the Project and select Properties.
- Project -> Properties -> Debugging -> Command Arguments
- Add the following to your Command Arguments: `< input.txt`
- Or something like that

### Run in Terminal

A better way is to use command line and a bash console like `gitbash`.

- Change into your folder with your code and input file.
- Compile:
  - `g++ <filename> -o <executablename>`
  - `g++ main.cpp -o main`
- Run:
  - `./main < inputfile`
  
If you use any of the c++11 or later code constructs you will need to set the compiler standard when compiling:

- Compile:
  - `g++ -std=c++17 main.cpp -o main`
  - or replace c++17 with c++11 if thats what you need
  


### Repl.it 

This is similar to command line, since repl.it uses a linux based os when you run your c++ code. I have the example from above here: https://repl.it/@rugbyprof/stdinexample. Even if you don't have an account it will let you run and edit that code. I would recommend creating an account. Here is a tutorial on creating and using repl.it: https://cs.msutexas.edu/replit_tutorial/


Click run so that it "compiles" first time.

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/replit_stdin_1.png" width="600"><br>

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/replit_stdin_2.png" width="600"><br>

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/replit_stdin_3.png" width="600"><br>

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/replit_stdin_5.png" width="300"><br>
