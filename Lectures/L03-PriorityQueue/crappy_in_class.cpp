#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Pnode {
    string value{""};
    int priority;
    Pnode *next;
    Pnode(string v = "", int p = 1) {
        value = v;
        priority = p;
        next = nullptr;
    }
    Pnode(const Pnode &p) {
        value = p.value;
        priority = p.priority;
        next = nullptr;
    }

    friend ostream &operator<<(ostream &os, const Pnode &p) {
        return os << "[" << p.value << " " << p.priority << "]";
    }
};

class PriorityListQueue {
    Pnode *front;
    Pnode *rear;
    int size;

public:
    PriorityListQueue() {
        front = rear = nullptr;
        size = 0;
    }

    void Push(const Pnode &p) {
        Pnode *temp = new Pnode(p);
        Pnode *tempFront = front;
        Pnode *prev = front;

        // empty list
        if (!front) {
            front = rear = temp;
        } else {
            // front of list with one node only
            if (front->next == nullptr) {
                if (temp->priority > front->priority) {
                    temp->next = front;
                    front = temp;
                } else {
                    front->next = temp;
                    rear = temp;
                }
            } else {

                if (temp->priority > front->priority) {
                    temp->next = front;
                    front = temp;
                } else {

                    // find proper location
                    while (tempFront && temp->priority <= tempFront->priority) {
                        prev = tempFront;
                        tempFront = tempFront->next;
                    }

                    // this is end of list logic
                    if (!tempFront) {
                        rear->next = temp;
                        rear = temp;
                        // use rear
                    } else {
                        prev->next = temp;
                        temp->next = tempFront;
                    }
                }
            }
        }
        size++;
    }

    void Pop(Pnode &p) {
        if (!front) {
            return;
        } else if (front == rear) {
            rear = nullptr;
        }
        p.value = front->value;
        p.priority = front->priority;
        Pnode *temp = front;
        front = front->next;
        delete temp;
        size--;
    }

    void Print() {
        Pnode *temp = front;

        while (temp) {
            cout << *temp;
            if (temp->next) {
                cout << "->";
            }
            temp = temp->next;
        }
    }

    bool Empty() {
        return size == 0;
    }
};

int main() {
    PriorityListQueue Q;
    ifstream fin;
    // string animal;
    // int priority;

    Pnode P;

    fin.open("printjobs.txt");

    while (!fin.eof()) {
        fin >> P.value >> P.priority;
        Q.Push(P);
    }

    // fin>>P.value>>P.priority;
    // Q.Push(P);
    // fin>>P.value>>P.priority;
    // Q.Push(P);
    // fin>>P.value>>P.priority;
    // Q.Push(P);

    Q.Print();
    cout << endl
         << endl;

    P.value = "Platypus";
    P.priority = 99;

    Q.Push(P);
    Q.Print();

    // Q.Pop(P);
    // Q.Print();
    // cout<<endl<<"P="<<P<<endl<<endl;

    // while(!Q.Empty()){
    //   Q.Pop(P);
    //   cout<<"P="<<P<<endl;
    // }
}