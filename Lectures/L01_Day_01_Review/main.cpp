#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Pnode: Simple struct to help with in class lecture so we 
 *     show that we can store more than just int's or string's 
 * 
 */
struct Pnode {
    string value{""};
    int priority{1};

    Pnode(string v = "", int p = 1) {
        value = v;
        priority = p;
    }
};

/**
 * @brief ArrayStack: Array based implementation of a stack.
 * 
 * Stack = LIFO data structure
 * 
 * NO Error checking, bare bones array stack used for as a code review
 * for lecture.
 * 
 */
class ArrayStack {
private:
    Pnode *stack;  // Array pointer
    int stackSize; // allocated stack size
    int top;       // index to top of stack
public:
    /**
     * @brief Construct a new Array Stack object
     * 
     */
    ArrayStack() {
        top = -1;                       // init at -1 so when we increment before we add to the stack
                                        // top always is even with the top most element

        stackSize = 10;                 // 10 default elements in the array
        stack = new Pnode[stackSize];   // dynamic array of Pnode's 
    }

    /**
     * @brief Construct a new Array Stack object
     * 
     * @param size 
     */
    ArrayStack(int size) {
        top = -1;                       // init at -1 so when we increment before we add to the stack
                                        // top always is even with the top most element

        stackSize = size;               // size elements in the array
        stack = new Pnode[stackSize];   // dynamic array of Pnode's 
    }

    /**
     * @brief Add an item to the stack
     * 
     * @param string v  : 
     * @param int p 
     */
    void Push(string v, int p) {
        if (!Full()) {                      // arrays must check if stack is full 
            top++;                          // move top to next element
            stack[top].value = v;           // Add value and priority to stack
            stack[top].priority = p;        // (remember priority doesn't effect this stack at all)
        } else {
            cout << "Stack Full!!" << endl; // Array's fill up. Lists don't:) We could resize the array
        }                                   // but we won't for now.
    }

    Pnode Pop() {
        if (!Empty()) {
            Pnode Temp = stack[top];
            top--;
            return Temp;
        }
        cout << "Error: Popping from empty stack!!" << endl;
        return Pnode("what?", -1);
    }

    // bool Pop(Pnode &p){
    //   if(!Empty()){
    //     p = stack[top];
    //     top--;
    //     return true;
    //   }
    //   return false;
    // }

    void Print() {
        for (int i = 0; i <= top; i++) {
            cout << stack[i].value << ":" << stack[i].priority << endl;
        }
    }

    bool Empty() {
        return top == -1;
    }

    bool Full() {
        return top == stackSize - 1;
    }
};

int main() {
    ArrayStack S;

    S.Push("hello", 7);
    S.Push("whateger", 8);
    S.Print();
}