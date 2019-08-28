/**
 * Review of topics from 1063 Data Structures
 * 
 */

#include <iostream>     // write to stdout read from stdin
#include <ctime>        // to use system clock

using namespace std;

/**
 * Node: A structure that represents a node in a linked list.
 */
struct Node
{
    int key;      // simple data element
    Node *next; // single link to next node

    // Constructor to add x when a new Node is created
    Node(int val)
    {
        key = val;
        next = NULL;
    }
};

/**
 * List 
 * Description:
 *     represents a linked list and basic functions to manipulate the list
 * Methods:
 *     list methods here
 */
class List
{
    Node *Head; // Everylist needs a head node to access it
public:
    List()
    {
        Head = NULL; // Null means list is empty
    }

    /**
     * public frontSert: add item to front of list
     * Params:
     *     int x : data item to store in node
     * Returns:
     *     void
     */
    void frontSert(int key)
    {
        // Allocate new memory to hold our new value
        Node *temp = new Node(key);

        // if list is empty just point head to new Node
        // if(Head == NULL) // Same as line below
        if (!Head)
        {
            Head = temp;
        }
        else
        {
            // push onto front of list
            temp->next = Head;
            Head = temp;
        }
        
    }

    /**
     * public endSert: add item to end of list
     * Params:
     *     int x : data item to store in node
     * Returns:
     *     void
     */
    void endSert(int key)
    {

        
    }

    /**
     * public orderedSert: add item to proper location maintaining ascending order.
     *                     
     * Params:
     *     int x : data item to store in node
     * Returns:
     *     void
     */
    void orderedSert(int key)
    {

        
    }

    /**
     * public randSert: add item to a random location in the list
     * Params:
     *     int x : data item to store in node
     * Returns:
     *     void
     */
    void randSert(int key){
        for(int i=0;i<rand();i++){
            //do somethiing
        }
    }

    /**
     * public remove: remove a node (delete) from the list
     * Params:
     *     int val : the value to find and then remove
     *               if it exists.
     * Returns:
     *     void
     */
    void remove(int key)
    {

        if(!Head){
            return;
        }

        // Handle deleting first node
        if(Head->key == key){
            Node* Temp = Head;
            Head = Head->next;
            delete Temp;
        }

        Node *prev = delSearch(key);

        if(prev->next){
            Node *target = prev->next;
            prev->next = target->next;
            delete target;
        }else{
            // delete last node
        }

        return;
    }

    /**
     * public print: print the list (for debugging really)
     * Params:
     *     void
     * Returns:
     *     void
     */
    void print()
    {
        // start at head of list
        // always make a copy, never alter head
        Node *Temp = Head;

         // While not at end of list
        // Same as: while(Temp != NULL)
        while (Temp)
        {
            cout << Temp->key;

            // only print if not at end of list
            if(Temp->next){
                cout<< "->";
            }
            Temp = Temp->next;
        }
        cout << endl;
    }

private:
    /**
     * private delSearch: finds a node to be deleted based on a search value
     * 
     * Params:
     *     int key
     * 
     * Returns:
     *     Node*
     */
    Node *delSearch(int key)
    {
        // point at start of list
        Node *Temp = Head;

        if (Temp->key == key)
        {
            return Temp;
        }

        // while temp != null && Temp isn't the value
        while (Temp->next && Temp->next->key != key)
        {
            Temp = Temp->next;
        }

        // if Temp == NULL then the key was not in the list
        return Temp;
    }
};

/**
 * main driver
 * 
 */
int main(int argc, char** argv)
{
    srand(time(0));    // seed random number generator
    List L;         // declare instance of a list

    // loop i times: 0 <= i < 10000
    for (int i = 0; i < rand() % 100; i++)
    {
        // load list with random # of nodes between 0 and 10000
        L.frontSert(rand() % 1000);
    }

    L.frontSert(33);

    L.randSert(55);

    // Print the list
    //L.print();

    // find node with value 216 and remove it
    //L.remove(216);

    // find node with value 967 and remove it
    //L.remove(967);

    // print the list again
    L.print();

    return 0;
}