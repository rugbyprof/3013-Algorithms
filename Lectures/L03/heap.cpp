///////////////////////////////////////////////////////////////////////////////
//                   YOU MUST COMPLETE AND COMMENT YOUR CODE!
// Title:            (program's title)
// Files:            (list of source files)
// Semester:         (course) Spring 2018
//
// Author:           (your name)
// Email:            (your email address)
// Description:
//       describe program here thoroughly
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>

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
class Heap
{
  private:
    int *H;       // Pointer to allocate dynamic array
    int Next;     // Next available location
    int MaxSize;  // Max size since were using array
    int HeapSize; // Actual number of items in the array.

    /**
     * Function IncreaseKey:
     *      Bubbles element up from given index.
     * 
     * Params:
     *     [int] index  - index of item to be increased
     * Returns
     *      void
     */
    void IncreaseKey(int i)
    {
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
    void DecreaseKey(int i)
    {
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
    void Swap(int p, int i)
    {
        int temp = H[p];
        H[p] = H[i];
        H[i] = temp;
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
    int Parent(int i)
    {
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
    int LeftChild(int i)
    {
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
    int Right(int i)
    {
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
    int PickChild(int i){

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
    Heap(int size)
    {
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
    void Insert(int x)
    {
    }

    /**
     * Function Extract:
     *      Removes top element from heap (whether min or max).
     * 
     * Params:
     *      void
     * Returns
     *      [int] top_value - top value in the heap (min or max)
     */
    int Extract()
    {
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
    void PrintHeap()
    {
        for (int i = 1; i < Next; i++)
        {
            cout << H[i] << " ";
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
    int Size()
    {
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
    bool Empty()
    {
        return Next == 1;
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
    void Heapify(int *A, int size)
    {
    }
};
