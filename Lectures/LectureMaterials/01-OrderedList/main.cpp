// Created on January 14th @ 1230
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Person{
    string Name;    // full name
    int Age;        // age of person
    // default constructor
    Person(){
        Name = "";
        Age = 0;
    }
    // overloaded constructor
    Person(string n,int a){
        Name = n;
        Age = a;
    }
};


struct Node{
    Person Data;    // Person struct
    Node* Next;     // Link to next node
    // should have default constructor
    // constructor
    Node(Person p){
        Data = p;
        Next = NULL;
    }
};

// operations
// insert 
// delete
// find
// size
// update a person


/**
 * Class Name
 * 
 * Description:
 *      Maintains an ordered linked list of people
 * 
 * Public Methods:
 *      - void Insert(Person)
 *      - void Print()
 * 
 * Private Methods:
 *      - void FrontSert(Node* x)
 *      - void EndSert(Node* x)
 *      - void OrderedSert(Node* x)
 */
class OrderedList{
private:
    Node* Head;
    Node* Tail;
    int Size;

    //Value less than head of list
    void FrontSert(Node* x){
        x->Next = Head;
        Head = x;
    }

    // value greater than head of list
    void EndSert(Node* x){
        Tail->Next = x;
        Tail = x;
    }

    // value somewhere in the middle
    void OrderedSert(Node* x){
        Node* Current = Head;
        Node* Previous = Head;

        while(Current && Current->Data.Name < x->Data.Name ){
            Previous = Current;
            Current = Current->Next;
        }

        Previous->Next = x;
        x->Next = Current;
    }
public:
    // constructor inits everything
    OrderedList(){
        Size = 0;
        Head = NULL;
    }

    ~OrderedList(){
        // needs implementing. Good practice of deleting a list via a traversal.
    }

    void Insert(Person P){
        Node* Temp = new Node(P);   // allocate new memory
        // is person less than head?
        // is person greater than tail?
        // or middle /

        // List is empty
        if(!Head){
            Head = Temp;        // Point head and tail to 
            Tail = Temp;        // new node
        // Not Empty
        }else{
            // O(1)
            // If Name is less than Name in head
            if(Temp->Data.Name < Head->Data.Name){
                FrontSert(Temp);
            // O(1)
            // If Name is greater than Name in tail
            }else if(Temp->Data.Name > Tail->Data.Name){
                EndSert(Temp);
            // O(N)
            // Go find where to insert it. 
            }else{
                OrderedSert(Temp);
            }
        }
    }

    void Print(){
        // Always copy head so you don't destroy the list
        Node* Current = Head;

        // Standard traversal
        // Start at head and then goto next node.
        while(Current){
            // loop fails when Current == NULL (which is 0)
            cout<<Current->Data.Name;   // print name in node
            cout<<"->";                 // awesome graphics
            Current = Current->Next;    // goto next node
        }
        // End of list points to NULL
        cout<<"NULL"<<endl;
    }

};

int main() {
    ifstream fin;           // fin is our file reference
    fin.open("data.txt");   // open file using reference
    int person_count = 0;   // set up int counter
    OrderedList L1;         // declare instance of our list
    fin>>person_count;      // read in top number from file

    // Create an array of "Person's" to hold info from file
    Person *PArray = new Person[person_count];

    int i = 0;                  // init counter
    while(!fin.eof()){          // while more stuff to read
        fin>>PArray[i].Name;    // read the Name into the Person
                                //    at array location i
        fin>>PArray[i].Age;     // read the Age into the Person
                                //    at array location i
        ++i;                    // increment our counter
    }

    // standard for loop to loop over 
    // our newly loaded array and insert
    // into the list 
    // (seems like we could have just inserted 
    // right into the list right?!?!)
    for(int i=0;i<person_count;i++){
        L1.Insert(PArray[i]);
    }

    // Print the list
    L1.Print();
  
}