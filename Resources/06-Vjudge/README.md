## Uploading to UVA Online Judge

> Adapted from Zachary Kingcades tutorial.

## Overview
There is a little different angle we must take when writing code to be uploaded to https://onlinejudge.org/. Just like I have stressed in class (oh remember the days when we had class ...) having a base knowledge of the use of the command line can be beneficial. This tutorial will discuss a couple of those skills and prepare you for uploading code to UVA Online judge.

Keep in mind that solving these types of problems isn't just for competition, its relevant for school and especially as a prep for interviewing.

### Registration and Overview

Onlinejudge has thousands of problems to browse and solve. You can look at them without registering, but you will need to register to submit solutions so go ahead and do that [HERE](https://onlinejudge.org/index.php?option=com_comprofiler&task=registers). 

The major portion of Onlinejudge is its [uHunt](https://uhunt.onlinejudge.org/) section. This is where you browse problems, submit your solutions, see statistics about each problem, see latest submissions, and most importantly where you see the status of your own submissions. You can click on the link I provided, **or** look for this icon on the main page: 

<a href="https://uhunt.onlinejudge.org/"><img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/uva_icon_sp_2020.png" width="50"></a>

### Selecting A Problem

You're registered, and ready to solve problems! How do you pick a problem? There are many different ways and reasons to select a problem. 

We are solving problems that require the understanding of specific data structures as well as problem solving paradigms. Data structures include: lists, arrays, stacks, queues, trees, graphs along with variants or combos of each. Problem Solving Paradigms include: brute force, divide and conquer, greedy, and dynamic programming.

We will use Competitive Programming 3 to help us choose problems that will best be solved by choosing the proper data structure accompanied with the correct problem solving paradigm. 

>**Note 1:** I hate stealing from any author, especially one who created such a great resource. I'm sure he would understand our dilemma this semester. I bought my own copy, and would encourage all of you to [purchase a copy](https://cpbook.net/#CP3details). Its a great programming resource since it really concentrates on problem solving in general, not just competitive programming. 

>**Note 2:** The only reason I haven't used this from the beginning is ... cheating :( You can find most of the solutions online. Even though I have a defense for this, its just exhausting. More later ... 

You don't only have to choose problems based on data structures and problem solving paradigms, 
believe it or not, people actually solve these for fun! I would recommend you solve as many of these as you have time for in addition to your course work. Lots of solutions will pad your resume` AND prepare you for interviews. So how do you choose problems to solve if its not for specific data structures? You can choose based on difficulty and how cool the name is. To do this, you have to [browse](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8) the problem sets. Below is the first menu of problems to choose from. We will concentrate on the two sets I placed a box around:

<a href="https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8"><img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/brows_problems_sp_2020.png" width="500"></a>

As you click folders, they drill down into other folders and finally lists of problems. If you drill down into any of the folders you will end up seeing something similar to below:

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/problem_difficulty_sp_2020.png" width="500">

We can see in a brief glance that lots of "red" = hard, and lots of "green" = easy (generally).  The left column shows how many total submissions vs how many solved. In other words, lots of red means it takes many submissions before someone gets it correct. The right column is percentage of people that attempted the problem actually solved it. So, if you want an easy problem, find one that has a left column with 90+ solution percentage.

If you need to find a specific problem, they all have numbers (the ones we will use). So you can go [browse](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8) and find problems using the number to navigate folders, or you can go to [uHunt](https://uhunt.onlinejudge.org/) and put the number in a search form (see #1 on image).

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/uhunt_browse_problems.png" width="500">

This will bring up a link to the problem description (see #2 on image) which you can download and keep as a reference as your solving. It also give you basic stats and current "whats going on" with the problem (see #3 on image).

To stay organized I typically create a folder with the problem number as the folder name, and save everything from that associated problem in there. There will always be the pdf for the problem, multiple data sets to test your problem, and the actual source code. So, organizing with folders and problem numbers is recommended.

Aside from being organized and trying to decide what problems to solve, you really just need to break the ice and get a solution uploaded to uHunt. So lets start with a super easy one called `11172 - Relational Operator`

### Solving A Problem

You can refer to the previous section and go get the pdf of the problem we will solve. Its number is "11172". But for this tutorial, here are the contents:

-----

### 11172 - Relational Operator
>Time limit: 3.000 seconds

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

### Coding The Problem

#### Start
You should read over the problem and start to formulate a solution by breaking it down into manageable components (more later). This problem is easy. I will say, however, that initially none of the problems **read** easy. They use mathematical notation to remove ambiguity from the problem definition, and it is a bit confounding at first. However it simply requires a little practice or a nice **slow** approach to absorb its meaning. 

#### Think
For each problem we recommend that you THINK about it, re-read it, then start your solution on paper. Also, when solving these problems, always look at the limits as described in the problem (e.g. `t < 15` and `(|a|, |b| < 1000000001)`). These could have an impact on the solution. For example, does `1000000001` fit in an integer data type? Or should it be long? Int works when uploaded for this solution, but on a tougher problem this could bite you in the butt.

#### Code
After you come up with a proposed solution, start to code it. Normal coding conventions that we stress in class are a little out the window. **Not all**, but some.  Rules like self documenting variable names, comments for each variable, organized procedural solution (lots of functions) are all relaxed for these solutions.

#### Nuances
Also, we want all the little speedups we can manage. **Example 1)** in larger solutions where a function seems appropriate, you may want to keep your code in main (inline), a function call is ever so slightly slower than inline code. **Example 2)** Another miniscule speedup is something as simple as re-defining `endl` to `\n`. The first one is interpreted as a newline **AND** a flush of the output buffer. If one of the problems you are solving has you writing to standard out thousands and thousands of times, the extra flush may slow you down. Both of these are tiny little speedups, but put a lot of those tiny speedups together, and it could make a difference. Difference in what you ask? The first line after the title in our problem statement states: `Time limit: 3.000 seconds`. That's the problem. Each solution has a time limit to complete. 

#### Stdin

Lastly **cin** is NOT being used to prompt a user for input. It is being used to read from an input file! Jump below the code and input file ...

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

Repl.it is kinda awesome. Yes I said it. They give us a pretty nice virtual linux environment to run our programs in. Basically, they give us a virtual machine / command line solution ... in the browser.  I have the example from above here: https://repl.it/@rugbyprof/stdinexample. Even if you don't have an account it will let you run and edit that code. I would recommend creating an account. Here is a tutorial on creating and using repl.it: https://cs.msutexas.edu/replit_tutorial/

#### Start
- Click run so that it "compiles" first time.
- You will have to stop it (see next pic)
  
<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/replit_stdin_1.png" width="600"><br>

#### Stop
- It will not finish, since its waiting for input:) 
- `cin` is still defined to read keyboard input, so hit the stop button. 
- You should see `exited, terminated` in the terminal.
  
<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/replit_stdin_2.png" width="600"><br>

#### Test Run

- When we hit "run" the first time , Replit compiled our code and made an executable with the same name as our file (minus the extension). 
- Since Replit is a linux virtual machine, we can run our program from the provided command line! 
- So, you can type `./main < input` in the terminal and get a correct run (notice we have output in the green box).
  
<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/replit_stdin_3.png" width="600"><br>

#### Compile

- We don't want to have to hit "run" to get a new executable every time we make a change to our source code. And we don't have to.
- Again, Replit gives us a linux terminal, so let us compile our own code using the terminal they so nicely gave us.
- So as you are testing your code, you can use the `up arrow` to cycle through the necessary commands (after you have typed them at least once).
  - Make a change, then using the terminal: 
  - Compile: `g++ main.cpp -o main`
  - Run: `./main < input`
  
<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/replit_stdin_5.png" width="300"><br>

### Testing Your Solution

You can now run your code using an input file as stdin. But how do we know if the solution is correct? You know its correct if:

- You thought of every edge case possible.
- You incorporated all nuances of the problem description into your solution.
- Your output is formatted perfectly.
- You are smarter than anyone you know.

The problem is, you really do not know if your solution is correct. You can upload it to uHunt and roll the dice to see if your solution will be accepted. Or, you can try to ensure your solution is correct by running multiple test data sets. 

If you go to the problems page where you got the pdf from, you will see a lady bug at the top right above the problem statement. Click on it. It will take you from [uHunt](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2113) to [uDebug](https://www.udebug.com/UVa/11172) where you have some options for testing your solution more thoroughly using data sets uploaded by other users. They go way beyond the example data given in the problem, and will help you determine if you really did thing about all the "edge cases" that might appear in the data.

#### Go Debug

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/replit_debug_sp_2020.png" width="600"><br>

#### Getting Data

- When you go to the debug site for your problem, you will see multiple data sets to choose from as I enclosed in a box.
- Above the blue box, you will see a link to the most popular input data. But all of them should help you debug. 
- If your code can process all of the data sets, you should be good (but not always :) I have one solution that passed ALL data sets but fails online. )
  
<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/uhunt_debug_get_data.png" width="600"><br>

#### Pick a Set

1. Pick a data set
2. Copy it to your clipboard
    
<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/uhunt_debug_copy_data.png" width="600"><br>

#### Use New Data

1. Create a new file
2. Paste new data in file
3. Run your code with new data file
   
> Your new output will be in the terminal, you need to copy it to bring back to uDebug.

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/uhunt_rerun_newdata.png" width="600"><br>

#### Check New Output

1. Click to get accepted output.
2. This window shows whats expected.
3. This is where you paste your output to be compared with accepted output.
4. Click to see if it matches!

> Note: uDebug gives better feedback than simply uploading your solution. In fact lots of times solutions are rejected for an extra "newline". This can be fixed here at uDebug.

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/uhunt_results_newdata.png" width="600"><br>

### Uploading Solution

#### Start Submission

- Go back to the problem page and click on submit.
  
<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/uhunt_choose_submit.png" width="600"><br> 

#### Do Submission

- On the next page:
  - Choose your version of c++ 
  - Paste your code into the submission text field or Upload a file. 
  - Press "submit"
  
<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/uhunt_paste_code_submit.png" width="600"><br> 

#### Confirm Submission

- You Get redirected back to the problem page with a confirmation.
  
<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/uhunt_confirm_submit.png" width="600"><br> 

#### Submission Results

- You will get an email telling you what happened, but I like to view the stats on the website.
- On the main onlinejudge site.
- Click on last 50 submissions (under site statistics).
- You should see your results (if you don't wait too long).
  
<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/uhunt_see_results.png" width="600"><br> 
