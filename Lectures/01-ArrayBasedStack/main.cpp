///////////////////////////////////////////////////////////////////////////////
//
// Author:           Terry Griffin
// Email:            terry.griffin@msutexas.edu
// Label:            L01
// Title:            Lecture 01 - Array Based Stack
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//       Overview of a class implementing an array based stack
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

/**
 * ArrayStack
 * 
 * Description:
 *      Array based stack
 * 
 * Public Methods:
 *      - See class below
 * 
 * Usage: 
 *      - See main program
 *      
 */
class ArrayStack{
private:
  int *A;           // pointer to array of int's
  int size;         // current max stack size
  int top;          // top of stack 

public:
 /**
  * ArrayStack
  * 
  * Description:
  *      Constructor no params
  * 
  * Params:
  *     - None
  * 
  * Returns:
  *     - NULL
  */
  ArrayStack(){
    size = 10;
    A = new int[size];
    top = -1;
  }

 /**
  * ArrayStack
  * 
  * Description:
  *      Constructor size param
  * 
  * Params:
  *     - int size
  * 
  * Returns:
  *     - NULL
  */
  ArrayStack(int s){
    size = s;
    A = new int[s];
    top = -1;
  }

 /**
  * Public bool: Empty
  * 
  * Description:
  *      Stack empty?
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [bool] true = empty
  */
  bool Empty(){
    return (top <= -1);
  }
  
 /**
  * Public bool: Full
  * 
  * Description:
  *      Stack full?
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [bool] true = full
  */
  bool Full(){
    return (top >= size-1);
  }

 /**
  * Public int: Peek
  * 
  * Description:
  *      Returns top value without altering the stack
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [int] top value if any
  */
  int Peek(){
    if(!Empty()){
      return A[top];
    }
    
    return -99;
  }

 /**
  * Public int: Pop
  * 
  * Description:
  *      Returns top value and removes it from stack
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      [int] top value if any
  */
  int Pop(){
    if(!Empty()){
      return A[top--];
    }

    return -99;
  }

 /**
  * Public void: Print
  * 
  * Description:
  *      Prints stack to standard out
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
  void Print(){
    for(int i=0;i<=top;i++){
      cout<<A[i]<<" ";
    }
    cout<<endl;
  } 

 /**
  * Public bool: Push
  * 
  * Description:
  *      Adds an item to top of stack
  * 
  * Params:
  *      [int] : item to be added
  * 
  * Returns:
  *      [bool] ; success = true
  */
  bool Push(int x){
    if(Full()){
      Resize();
    }
    if(!Full()){
      A[++top] = x;
      return true;
    }
    
    return false;
    
  }

 /**
  * Public void: Resize
  * 
  * Description:
  *      Resizes the container for the stack by doubling
  *      its capacity
  * 
  * Params:
  *      NULL
  * 
  * Returns:
  *      NULL
  */
  void Resize(){
    int newSize = size*2;
    int *B = new int[newSize];

    for(int i=0;i<size;i++){
      B[i] = A[i];
    }

    delete [] A;

    size = newSize;

    A = B;

  }

};

// MAIN DRIVER
// Simple Array Based Stack Usage:
int main() {
  ArrayStack stack;
  int r = 0;

  for(int i=0;i<20;i++){
    r = rand() % 100;
    r = i+1;
    if(!stack.Push(r)){
      cout<<"Push failed"<<endl;
    }
  }

  for(int i=0;i<7;i++){
    stack.Pop();
  }

  stack.Print();
}