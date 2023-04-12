///////////////////////////////////////////////////////////////////////////////
// Title:            Heap.hpp
// Semester:         Fall 2019
// Course:           CMPS 3013
//
// Author:           Terry Griffin
// Email:            terry.griffin@msutexas.edu
// Description:
//       Min or Max Heap implementation
/////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <iostream>
#include <math.h>

using namespace std;

/**
 * Class Heap:
 * 
 * Public Methods:
 *    Heap(int)
 *    void Insert(int)
 *    int Remove()
 *    void PrintHeap()
 *    int Size()
 *    bool Empty()
 *    void Heapify(int*,int)
 */
template <typename T>
class Heap {
private:
    T **Array;     // Pointer to allocate dynamic array
    T **SwapSpace; //
    int Next;      // Next available location
    int MaxSize;   // Max size since were using array
    int HeapSize;  // Actual number of items in the array.
    bool isMax;    // true = max heap false = min

    /**
     * Function IncreaseKey:
     *      Bubbles element up from given index.
     * 
     * Params:
     *     [int] index  - index of item to be increased
     * Returns
     *      void
     */
    void BubbleUp(int i) {
        int p = Parent(i);
        if (isMax) {
            while (p > 0 && Array[i]->priority > Array[p]->priority) {
                Swap(i, p);
                i = p;
                p = Parent(i);
            }
        } else {
            while (p > 0 && Array[i]->priority < Array[p]->priority) {
                Swap(i, p);
                i = p;
                p = Parent(i);
            }
        }
    }

    /**
     * Function DecreaseKey:
     *      Bubbles element down from given index.
     * 
     * Params:
     *      [int] index - index of item to be decreased
     * Returns
     *      void
     */
    void BubbleDown(int i) {
        int c = PickChild(i);

        while (c > 0) {
            if (isMax) {
                if (Array[i]->priority < Array[c]->priority) {
                    Swap(i, c);
                    i = c;
                    c = PickChild(i);
                } else {
                    c = -1;
                }
            } else {
                if (Array[i]->priority > Array[c]->priority) {
                    Swap(i, c);
                    i = c;
                    c = PickChild(i);
                } else {
                    c = -1;
                }
            }
        }
    }

    /**
     * Function Swap:
     *      Swaps two elements in an array
     * 
     * Params:
     *      [int] index1 - index of item to swap with
     *      [int] index2 - same
     * Returns
     *      void
     */
    void Swap(int p, int i) {
        T *temp = Array[p];
        Array[p] = Array[i];
        Array[i] = temp;
    }

    /**
     * Function Parent:
     *      Returns parent index of a given index
     * 
     * Params:
     *      [int]index - index to calculate parent from
     * Returns
     *      index [int]
     */
    int Parent(int i) {
        return int(i / 2);
    }

    /**
     * Function LeftChild:
     *      Returns left index of a given index
     * 
     * Params:
     *      [int] index - index to calculate child from
     * Returns
     *      [int] index - left child index
     */
    int LeftChild(int i) {
        return i * 2;
    }

    /**
     * Function RightChild:
     *      Returns right index of a given index
     * 
     * Params:
     *      [int] index - index to calculate child from
     * Returns
     *      [int] index - right child index
     */
    int RightChild(int i) {
        return i * 2 + 1;
    }

    /**
     * Function PickChild:
     *      Return index of child to swap with or -1 to not swap.
     * 
     * Params:
     *      [int] index - index of parent element
     * Returns
     *      [int] index - index to swap with or -1 to not swap
     */
    int PickChild(int i) {
        if (RightChild(i) >= Next) {    //No right child
            if (LeftChild(i) >= Next) { //No left child
                return -1;
            } else { //you have a left no right
                return LeftChild(i);
            }
        } else {
            //right child exists
            if (isMax) {
                if (Array[RightChild(i)]->priority > Array[LeftChild(i)]->priority) {
                    return RightChild(i);
                } else {
                    return LeftChild(i);
                }
            } else {
                if (Array[RightChild(i)]->priority < Array[LeftChild(i)]->priority) {
                    return RightChild(i);
                } else {
                    return LeftChild(i);
                }
            }
        }
    }

    /**
     * ResizeHeap
     * 
     * Description:
     *     If heap gets full, we need to resize and not throw memory error
     * Params:
     *     bool grow: if true we grow the heap, else we shrink the heap 
     * 
     * Note:
     * 
     *     Shrink is not implemented!
     */
    void ResizeHeap(bool grow = true) {
        if (grow) {
            int newSize = MaxSize * 2;
            SwapSpace = new T *[newSize];
            for (int i = 1; i <= Next; i++) {
                SwapSpace[i] = Array[i];
            }
            MaxSize = newSize;
            delete[] Array;
            Array = SwapSpace;
        } else {
            // not implemented!
        }
    }

public:
    /**
     * Function Heap:
     *      Constructor that allocates memory for array and
     *      inits vars.
     * 
     * Params:
     *      void
     * Returns
     *      void
     */
    Heap(int size, bool max = true) {
        Array = new T *[size];
        Next = 1;
        MaxSize = size;
        HeapSize = 0;
        isMax = max;
    }

    Heap(bool max = true) {
        Array = new T *[100];
        Next = 1;
        MaxSize = 100;
        HeapSize = 0;
        isMax = max;
    }

    /**
     * Function Insert:
     *      Insert value into heap.
     * 
     * Params:
     *      [int] x - value to be inserted
     * Returns
     *      void
     */
    void Insert(T *x) {
        if (Next + 1 == MaxSize) {
            ResizeHeap();
        }
        Array[Next] = x;
        BubbleUp(Next);
        Next++;
        HeapSize++;
    }

    /**
     * Function Extract:
     *      Removes top element from heap (whether min or max).
     * 
     * Params:
     *      void
     * Returns
     *      [T] top_value - top value in the heap (min or max)
     */
    T *Extract() {

        if (Empty()) {
            return NULL;
        }

        T *retval = Array[1];
        Array[1] = Array[--Next];
        HeapSize--;

        if (HeapSize > 1) {
            BubbleDown(1);
        }

        return retval;
    }

    /**
     * Function PrintHeap:
     *      Prints the values currently in the heap array
     *      based on array location, not heap order
     * 
     * Params:
     *      void
     * Returns
     *      void
     */
    void PrintHeap() {
        for (int i = 1; i < Next; i++) {
            cout << Array[i]->letter << ":" << Array[i]->priority << " ";
        }
        cout << endl;
    }

    /**
     * Function Size:
     *      Returns the number of items in the heap
     * 
     * Params:
     *      void
     * Returns
     *      [int] heapSize - size of heap
     */
    int Size() {
        return Next - 1;
    }

    /**
     * Function Empty:
     *      Returns boolean true of array is empty
     * 
     * Params:
     *      void
     * Returns
     *      [bool] empty - is array empty
     */
    bool Empty() {
        return Next == 1;
    }

    void Clear() {
        delete[] Array;
        Array = new T *[MaxSize];
        HeapSize = 0;
        Next = 1;
    }

    /**
     * Function Heapify:
     *      Creates a heap out of a given array of nums in no specific order.
     * 
     * Params:
     *      [int*] array - array of values to heapify
     *      [int] size - size of array
     * Returns
     *      void
     */
    void Heapify(T **&A, int size) {
        int i = size / 2;
        Array = A;
        Next = size;
        HeapSize = size - 1;

        for (int j = i; j >= 1; j--) {
            BubbleDown(j);
        }
    }
};
