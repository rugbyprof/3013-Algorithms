#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Pnode{
  string value{""};
  int priority{1};
  Pnode* next;
  Pnode(string v="",int p=1){
    value = v;
    priority = p;
    next = nullptr;
  }
  Pnode(const Pnode &p){
    value = p.value;
    priority = p.priority;
    next = nullptr;
  }

  friend ostream& operator<<(ostream &os,const Pnode &p){
    return os <<"["<< p.value<<" "<<p.priority<<" "<<p.next<<"]";
  } 

};


class ListQueue{
  Pnode *front;
  Pnode *rear;
  int size;
public:
  ListQueue(){
    front = rear = nullptr;
    size = 0;
  }

  void Push(const Pnode &p){
    Pnode *temp = new Pnode(p);
    if(!front){  
      front = rear = temp;
    }else{
      rear->next = temp;
      rear = temp;
    }
    size++;
  }

  void Pop(Pnode &p){
    if(!front){
      return;
    }else if(front ==  rear){
      rear = nullptr;
    }
    p.value = front->value;
    p.priority = front->priority;
    Pnode *temp = front;
    front = front->next;
    delete temp;
    size--;
  }

  void Print(){
    Pnode *temp = front;

    while(temp){
      cout<<*temp;
      if(temp->next){
        cout<<"->";
      }
      temp = temp->next;
    }
  }

  bool Empty(){
    return size == 0;
  }
};


int main() {
  ListQueue Q;
  ifstream fin;
  // string animal;
  // int priority;

  Pnode P;

  fin.open("printjobs.txt");

  while(!fin.eof()){
    fin>>P.value>>P.priority;
    Q.Push(P);
  }
  Q.Print();
  cout<<endl<<endl;

  // Q.Pop(P);
  // Q.Print();
  // cout<<endl<<"P="<<P<<endl<<endl;

  while(!Q.Empty()){
    Q.Pop(P);
    cout<<endl<<"P="<<P<<endl;
  }
} 