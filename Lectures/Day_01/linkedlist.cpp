#include <iostream>
#include <ctime>

using namespace std;

struct Node{
  int x;
  Node *next;
  Node(int n){
    x = n;
  }
};

class List{
  Node *Head;
  // collection of data and methods
  // that work on the data
public:
  List(){
    Head = NULL;
  }

  bool frontSert(int x){
    Node* temp = new Node(x);

    // if list is empty just point head to new Node
    //if(Head == NULL)
    if(!Head){
      Head = temp;
    }else{
      temp->next = Head;
      Head = temp;
    }
    // if list is not empty push it on the front
    return true;
  }

  bool remove(int val){
    Node* Patriot = delSearch(val);
    Node* Terrorist = Patriot->next;

    Patriot->next = Patriot->next->next;
    delete Terrorist;

    return true;
  }

  int get(){
    return true;
  }


  void print(){
    Node *Temp = Head;

    while(Temp){
      cout<<Temp->x<<"->";
      Temp = Temp->next;
    }
    cout<<endl;
  }

private:
  Node* delSearch(int s){
    // point at start of list
    Node *Temp = Head;

    if(Temp->x == s){
      return Temp;
    }

    // while temp != null && Temp isn't the value
    while(Temp->next && Temp->next->x != s){
      Temp = Temp->next;
    }

    return Temp;
  }
};

int main() {
  srand(1234);
  List L;
  for(int i=0;i<rand()%10000;i++){
    L.frontSert(rand()%1000);
  }

  L.print();
  
  L.remove(216);
  L.remove(967);
  
  L.print();
}
