#include <iostream>
#include <ctime>

using namespace std;
struct node{
  int data;
  node* next;
};

class intLinkedList{
  private:
  node* Head;
  public:
  intLinkedList(){
    Head = NULL;
  }
  void insert(int x){
    //empty list case
    if(!Head){
      Head = new node;
      Head->data = x;
      Head->next = NULL;
    }else{//not empty list
      node* T = new node;
      T->data = x;
      T->next = Head;
      Head = T;
    }
  }
  
  node* Find(int key){
    node* temp = Head;
    while(temp){
      if(temp->data == key){
        return temp;
      }
      temp = temp->next;
    }
    return NULL;
  }
  
  node* Remove(int key){
    node* result = Find(key);
    if(result){
      node* temp = Head;
      while(temp->next != result){
        temp = temp->next;
      }
      temp->next = result->next;
      delete result;
    }
  }
  
  void print(){
    node* p = Head;
    while(p){
      cout<<p->data<<endl;
      p = p->next;
    }
  }
};

int main() {
  srand(8734587);
  cout << "Hello World!\n";
  intLinkedList mylist;
  for(int i=0;i<10;i++){
    mylist.insert(rand()%100);
  }
  mylist.print();
  cout<<mylist.Find(99)<<endl;
  mylist.Remove(58);
  mylist.print();

  
}
