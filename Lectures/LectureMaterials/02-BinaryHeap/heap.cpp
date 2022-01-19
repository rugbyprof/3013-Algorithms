#include <iostream>

using namespace std;

/**
 * Not a complete implementation of a min heap yet!
 * We still need to implement BubbleDown and Heapify!
 */

/**
 * MinHeap
 * 
 * Private Methods:
 *      BubbleDown  - after removing item and a swap
 *      BubbleUp    - after inserting new item to back
 *      Left        - left child
 *      Parent      - parent
 *      Right       - right child
 *      Swap        - swap two elements
 * Public Methods:
 *      MinHeap()   - constructor
 *      Extract     - remove top of heap
 *      Push        - add to heap
 *      Print       - print to std out
 */
class MinHeap {
private:
    int *h;           // data container
    int current_size; //
    int heap_size;    // size of array
    int back;         // end of heap

    /**
     * Left - calculates left child index
     */
    int Left(int i) {
        return 2 * i;
    }

    /**
     * Right - calculates right child index
     */
    int Right(int i) {
        return 2 * i + 1;
    }

    /**
     * Parent - calculates parent index
     */
    int Parent(int i) {
        return i / 2;
    }

    /**
     * BubbleUp - bubbles a value up to fullfill heap property
     *            after item was added to rear of array.
     */
    void BubbleUp(int i) {
        int p = 0;
        while (i > 1) {
            p = Parent(i);
            if (h[i] < h[p]) {
                Swap(i, p);
                i = p;
            } else {
                return;
            }
        }
    }

    /**
     * BubbleDown - bubbles a value down to fullfill heap property
     *              after item was removed and last item swapped to front.
     */
    void BubbleDown(int i) {
        int p = 0;
        while (i < back) {
            p = Parent(i);
            if (h[i] < h[p]) {
                Swap(i, p);
                i = p;
            } else {
                return;
            }
        }
    }

    /**
     * Swap - standard three line swap.
     */
    void Swap(int i, int j) {
        int temp = h[i];
        h[i] = h[j];
        h[j] = temp;
    }

public:
    /**
     * Default Constructor
     * 
     */
    MinHeap() {
        h = new int[100];
        back = 1;
        heap_size = 100;
        current_size = 0;
    }

    /**
     * Push - Add item to rear of heap.
     */
    void Push(int x) {
        h[back] = x;                    // put item in array
        back++;                         // move back of heap
        current_size++;                 // increment size
        BubbleUp(back - 1);             // move new item to proper spot
    }

    /**
     * Print - dump heap to stdout.
     */
    void Print() {
        for (int i = 1; i <= current_size; i++) {
            cout << h[i] << " ";
        }
        cout << endl;
    }

    /**
     * Extract - remove item from heap.
     */
    int Extract() {
        int temp = h[1];        // copy top of heap
        back--;                 // move back to point at 
                                //       actual last item
        h[1] = h[back];         // swap back item to top of heap
        BubbleDown(1);          // bubble top down to proper
                                //     location
    }
};

int main() {
    MinHeap H;

    H.Push(47);
    H.Push(45);
    H.Push(50);
    H.Push(20);
    H.Push(30);
    H.Push(15);
    H.Push(10);
    H.Print();
    H.Push(5);

    H.Print();
}