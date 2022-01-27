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

class PriorityQueue {
    Pnode *Front;
    Pnode *Rear;

public:
    PriorityQueue() {
        Front = Rear = nullptr;
    }

    void Push(string value, int priority) {
        Pnode *newNode = new Pnode(value, priority);
        //cout<<*newNode<<endl;

        // Handle insert for empty list
        if (!Front) {
            Front = Rear = newNode;
            // check front of list
        } else if (newNode->priority < Front->priority) {
            PushFront(newNode);
        } else if (newNode->priority >= Rear->priority) {
            PushRear(newNode);
        } else {
            PushMiddle(newNode);
        }
    }

    void PushFront(Pnode *&p) {
        p->next = Front;
        Front = p;
    }

    void PushRear(Pnode *&p) {
        Rear->next = p;
        Rear = p;
    }

    void PushMiddle(Pnode *&p) {
        Pnode *temp = Front;
        Pnode *prev = Front;

        while (temp && p->priority >= temp->priority) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = p;
        p->next = temp;
    }

    Pnode *Pop() {
        if (!Empty()) {
            Pnode *P = new Pnode(Front->value, Front->priority);

            Pnode *temp = Front;
            Front = Front->next;

            if (Front == nullptr) {
                Rear = Front;
            }
            delete temp;
            return P;
        }
        return nullptr;
    }

    bool Empty() {
        return Front == nullptr && Rear == nullptr;
    }

    void Print() {
        Pnode *temp = Front;
        while (temp) {
            cout << *temp << endl;
            temp = temp->next;
        }
    }
};

int main() {

    ifstream fin;
    fin.open("printJobs.txt");
    string animal;
    int priority;

    PriorityQueue PQ;

    while (!fin.eof()) {
        fin >> animal >> priority;
        //cout<<animal<<priority<<endl;
        PQ.Push(animal, priority);
    }
    cout << "==================" << endl
         << endl;
    while (!PQ.Empty()) {
        Pnode *p = PQ.Pop();
        cout << *p << endl;
    }

    cout << PQ.Pop() << endl;
}