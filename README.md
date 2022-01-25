# 3013-Algorithms

### Roster

![](https://d3vv6lp55qjaqc.cloudfront.net/items/220B0V0H3c041K2p251Z/google-sheets-16.png?X-CloudApp-Visitor-Id=1094421) [Class Roster](https://docs.google.com/spreadsheets/d/1SvxY7V82s1o-MfIch2vWafe0FpAWLEObwlbyb2lK7yk/edit?usp=sharing)


### General Course Info
- __Days:__ TTh 12:30 p.m. - 1:50 p.m. 
- __Location:__ BO 320
- [__Semester:__](https://msutexas.edu/registrar/_assets/files/pdfs/acadcal2022.pdf) Monday January 10<sup>th</sup> - Friday April 29<sup>rd</sup>
- [__Holidays:__](https://msutexas.edu/registrar/_assets/files/pdfs/acadcal2022.pdf)
  - __Martin Luther King Jr. Day__ Monday January 17<sup>th</sup>
  - __Spring Break :__ Monday March 14<sup>st</sup> - Friday March 19<sup>th</sup> 
- [__Last Day for “W”:__](https://msutexas.edu/registrar/_assets/files/pdfs/acadcal2022.pdf)  Friday March 21<sup>st</sup>
- [__Last Day of Class:__](https://msutexas.edu/registrar/_assets/files/pdfs/acadcal2022.pdf) Friday April 29<sup>th</sup>
- [__Final Exam:__](https://msutexas.edu/registrar/_assets/files/pdfs/spring22finals.pdf) Thursday May 5<sup>th</sup> @ 10:30am in BO 320

### Resources

Here are some open source books for the course. I hope you guys appreciate the amount of effort it takes to put material together and then put it on the internet for free.

- [Discrete Structures for Computer Science: Counting, Recursion, and Probability](http://cglab.ca/~michiel/DiscreteStructures/)
  - Thanks To: [Michiel Smid](http://people.scs.carleton.ca/~michiel/)
- [Open Data Structures](https://opendatastructures.org/ods-cpp.pdf)
  - Code available [HERE](https://github.com/patmorin/ods)
  - Thanks To: [Pat Morin](http://cglab.ca/~morin/)
- [Algorithms](http://jeffe.cs.illinois.edu/teaching/algorithms/)
  - Thanks To: [Jeff Erickson](http://jeffe.cs.illinois.edu/)
- [Wikipedia Collection of Data Structures](https://en.wikipedia.org/wiki/Book:Data_structures)

### Assumed

- This course assumes you know what `array based data structures` and `list based data structures` are.
- For example you should be able to write (from scratch) an `array based stack` and `queue` along with a `list based stack` and `queue`. If you cannot, go study.
- You should have a general understanding of recursive functions.
- You should have a general understanding on graph structures more specifically be able to write and traverse a basic Binary Search Tree (BST).
- Basic OOP skills. Mainly encapsulation and implementation hiding, in other words packaging a data structure with the methods to manipulate that data structure.  

### Note About This Courses

 I will try to go over the list of topics (see below) in the order they are listed, and I have a path that I like to follow when introducing these topics.  However, I approach each course with the hopes that student interaction and feedback will steer the course in a direction that may not be what was previously planned. This is stressful for some of my more "organized" students, and I can appreciate their angst. So I always provide a study guide before each exam to ensure everyone is on the same page with the topics I expect you to study. The study guide could have actual test type questions, small programs to implement, or vocabulary and topics. 


#### Algorithm Categories

- Backtracking
- Brute Force 
- Dynamic Programming
- Greedy Algorithms
- Recursion

#### Topics List

As I stated above, we will try to stay on task, but let me give you an example of why things can't always be taught sequentially. 
There are always multiple ways to implement every data structure. For example there is a data structure called a **priority queue**. It can be implemented in many ways, some better than others. Some of these won't make sense right now, but you will get the idea. Here are a few:

1. Use an **array**, and order the items in the array using the "priority" value.
2. Use a **singly linked list**, and order the nodes using the "priority" value.
3. Use an **array based binary tree**, called a **binary heap** and using the "priority" value to order the heap.
4. Use a **doubly circular linked list**, and follow the algorithm known as a **Fibonacci Heap** to keep the items in order.
   
So ultimately based on class input and questions that come up in discussion, I may jump around a bit so an explanation will make sense. Remember though ... *I make study guides for each test*!!


- [x] Array Based vs List Based Structures
- [x] [Array Based Implementations](https://opendatastructures.org/ods-cpp/2_Array_Based_Lists.html)
- [ ] Complexity 
  - [ ] Introduction 
  - [ ] Will be discussed with each data structure
- [ ] Linked List Types
  - [ ] [Singly Linked List](https://opendatastructures.org/ods-cpp/3_1_Singly_Linked_List.html)
  - [ ] [Doubly Linked List](https://opendatastructures.org/ods-cpp/3_2_Doubly_Linked_List.html)
  - [ ] [Circular List](https://www.geeksforgeeks.org/circular-linked-list/)
- [x] Stack, Queue, Priority Queue, Deque
- [x] Array Based Binary Search
- [x] Binary Tree's
  - [x] Components
  - [x] Array Based
- [x] Binary Heap (Array Based)
- [ ] Fibonacci Heap (**Possibly**)
- [ ] Binary Tree Implementation (List Based)
- [ ] Trie
- [ ] Balanced Tree's
  - [ ] AVL
  - [ ] Red Black (**Possibly**)
- [ ] [Hash Tables](https://opendatastructures.org/ods-cpp/5_Hash_Tables.html)
- [ ] Graphs 
  - [ ] Array Based and List Based Implementations
  - [ ] [Basic Graph Algorithms](http://jeffe.cs.illinois.edu/teaching/algorithms/book/05-graphs.pdf)
  - [ ] [DFS (Depth-First Search)](http://jeffe.cs.illinois.edu/teaching/algorithms/book/06-dfs.pdf)
  - [ ] [BFS (Breadth-First Search)](https://opendatastructures.org/ods-cpp/12_3_Graph_Traversal.html)
  - [ ] [Minimum Spanning Trees](http://jeffe.cs.illinois.edu/teaching/algorithms/book/07-mst.pdf) 
    - [ ] Prim's Algorithm (Minimum Spanning Tree)
    - [ ] Kruskal's Algorithm (Minimum Spanning Tree)
  - [ ] [Shortest Path](http://jeffe.cs.illinois.edu/teaching/algorithms/book/08-sssp.pdf)
    - [ ] Dijkstra's Algorithm (One Way Shortest Path)
    - [ ] A-Star Algorithm (**Possibly**)
- [ ] Sorting:
  - [ ] O(n^2)
    - [ ] Bubble Sort
    - [ ] Selection Sort
    - [ ] Insertion Sort
  - [ ] O(n lg n)
    - [ ] Merge Sort
    - [ ] Quick Sort
  - [ ] Other
    - [ ] Counting Sort
    - [ ] Radix Sort


### Resources

- http://opendatastructures.org/ods-cpp/
- https://github.com/ippeb/ACM-ICPC

## Grading

| Categories                                              |       | Grade |          |
| :------------------------------------------------------ | :---: | :---: | :------: |
| Exams (3)                               |  40%  |   A   |  89-100  |
| Programs (3-5)<sup>**1**</sup> & Assignments            |  30%  |   B   |  79-88   |
| Final<sup>**2**</sup>                                   |  20%  |   C   |  69-78   |
| Github Portfolio                                        |  10%  |   D   |  59-68   |
| Project Presentations (time permitting)<sup>**3**</sup> |  10%  |   F   | below 59 |
|                                                         |       |       |          |

>**1**. Despite the low overall value of the programming portion of the course, ALL programs must be turned in running to pass the course.  They don't have to be necessarily correct, but they must run and they need to at least approach the solution (a "Hello World" program will not work). 
>
>**2**. Plane ticket prices, events like weddings, or trips out of the country are not valid excuses for missing the final exam at its scheduled time. I will not make accommodations for anything other than an issue vetted by the dean of students. 
>
>**3**. The 10% for project presentations will be taken from Programs & Assignments if we have time to do presentations. 

## Academic Misconduct Policy & Procedures

Cheating, collusion, and plagiarism (the act of using source material of other persons, either published or unpublished, without following the accepted techniques of crediting, or the submission for credit of work not the individual’s to whom credit is given . The Department of Computer Science has adopted the following policy related to cheating (academic misconduct).  The policy will be applied to all instances of cheating on assignments and exams as determined by the instructor of the course.  (See below for link to MSU definitions.)

- 1st instance of cheating in a course: The student will be assigned a non-replaceable grade of zero for the assignment, project or exam.  If the resulting grade does not result in a letter grade reduction, the student will receive a one letter grade reduction in course.
- 2nd instance of cheating in a course: The student will receive a grade of F in course & immediately be removed from course.
- All instances of cheating will be reported to the Department Chair and, in the case of graduate students, to the Department Graduate Coordinator.
  
Note: Letting a student look at your work is collusion and is academic misconduct!
 
See Also:   MSU Student Handbook: Appendix E: Academic Misconduct Policy & Procedures
https://msutexas.edu/student-life/_assets/files/handbook.pdf.

