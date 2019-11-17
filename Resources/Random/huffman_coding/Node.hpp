#pragma once

using namespace std; 

struct Node{
  char *letter;
  int freq;
  int priority;
  bool innerNode;
  
  Node* Left;
  Node* Right;

  Node(){
    letter = new char;
    letter = NULL;
    freq = 0;
    priority=0;
    innerNode = true;
    Left = Right = NULL;
  }

  Node(char ch){
    letter = new char(ch);
    freq = 0;
    priority=0;
    innerNode = true;
    Left = Right = NULL;
  }

  void SetPriority(int p){
    freq = p;
    priority = p;
  }

};

ostream& operator<<(ostream& os, const Node* node)
{
    os << node->letter << ':' << node->priority <<endl;
    return os;
}