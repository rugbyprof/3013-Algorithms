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
#pragma once

#include "graph.h"

using namespace std;

/**
 * edge - represents the edge of a graph.
 */
struct edge
{
    int fromID;
    int toID;      // id of vertex edge is going to
    double weight; // weight of edge if any
    bool used;     // was edge used in some traversal
    edge(int id, double w)
    {
        fromID = -1;
        toID = id;
        weight = w;
        used = false;
    }
    edge(int fid,int tid, double w)
    {
        fromID = fid;
        toID = tid;
        weight = w;
        used = false;
    }
    /**
     * operator<< - overload cout for edge
     * Params:
     *     const edge e     - edge to print
     * Returns 
     *     formatted output for an edge
     */
    friend ostream &operator<<(ostream &output, const edge &e)
    {
        if(e.fromID < 0)
          output << "(To: " << e.toID << " W: " << e.weight << " U: " << e.used << ")";
        else
          output << "(From: "<<e.fromID<<" To: " << e.toID << " W: " << e.weight << " U: " << e.used << ")";
        return output;
    }
};

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
class edgeHeap
{
  private:
    vector<edge *> H;

    /**
     * Function IncreaseKey:
     *      Bubbles element up from given index.
     * 
     * Params:
     *     [int] index  - index of item to be increased
     * Returns
     *      void
     */
    void BubbleUp(int i)
    {
      int p = Parent(i);
      while(p > 0 && H[i]->weight < H[p]->weight){
        Swap(i,p);
        i = p;
        p = Parent(i);
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
    void BubbleDown(int i)
    {
      int c = PickChild(i);
      
      while(c > 0){
        if(H[i]->weight > H[c]->weight){
          Swap(i,c);
          i = c;
          c = PickChild(i);
        }else{
          c = -1;
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
    void Swap(int p, int i)
    {
        edge *temp = H[p];
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
    int RightChild(int i)
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
      if(RightChild(i) >= H.size()){//No right child
        if(LeftChild(i) >= H.size()){//No left child
          return -1;
        }else{//you have a left no right
          return LeftChild(i);
        }
      }else{
        //right child exists
        if(H[RightChild(i)] > H[LeftChild(i)]){
          return RightChild(i);
        }else{
          return LeftChild(i);
        }
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
    edgeHeap()
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
    void Insert(edge* x)
    {
      H.push_back(x);
      BubbleUp(H.size()-1);
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
    edge* Extract()
    {

      if(Empty()){
        return NULL;
      }
      
      edge* retval = H[1];
      H[1] = H.back();
      H.pop_back();

      
      if(H.size() > 1){
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
    void PrintHeap()
    {
        for (int i = 1; i < H.size(); i++)
        {
            cout << *H[i] << endl;
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
        return H.size();
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
        return H.size() == 0;
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
    void Heapify(vector<edge *>A, int size)
    {
      H = A;
      for(int j=H.size()/2;j>=1;j--){
        BubbleDown(j);
      }
    }
};