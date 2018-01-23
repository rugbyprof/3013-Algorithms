#include <iostream>

using namespace std;

class Heap{
private:
    int *H;
    int Next;
    int MaxSize;
    int HeapSize;
    void BubbleUp(int);
    void BubbleDown(int);
    int Parent(int);
    int Left(int);
    int Right(int);
    void Swap(int,int);
    int PickChild(int i);
public:
    Heap(int);
    void Insert(int);
    int Remove();
    void PrintHeap();
    int Size();
    bool Empty();
    void Heapify(int*,int);
};

Heap::Heap(int size){
    H = new int [size];
    Next = 1;
    MaxSize = size;
    HeapSize = 0;
}

void Heap::Insert(int x){
    H[Next] = x;
    BubbleUp(Next);
    Next++;
    HeapSize++;
}

void Heap::BubbleUp(int i){
    int p = Parent(i);
    while(H[i] < H[p]){
        Swap(i,p);
        i = p;
        p = Parent(i);
    }
}

void Heap::Heapify(int *A,int size){
  int i = size / 2;
  H = A;
  Next = size;
  HeapSize = size;

  for (int j=i;j>=1;j--){
    
    BubbleDown(j);
  }
}

//    int A[] = {0,10,4,7,5,9,2,11,14,3};

void Heap::BubbleDown(int i){
    int temp = 0;
    int swap = PickChild(i);
    
    while(swap > 0){
        if(H[i] > H[swap]){
          Swap(i,swap);
          i = swap;
          swap = PickChild(i);
        }else{
          swap = -1;
        }
    }
}

//returns index to swap with or -1 for no Swap
int Heap::PickChild(int i){
    
    if(Right(i) >= Next){    //No right child
        if(Left(i) >= Next){   //No left child either
            return -1;
        }else{                 //Only left child, so return it
            return Left(i);
        }
    }else{                  //There is a right child (there must be a left)
        if(H[Right(i)] < H[Left(i)]){
            return Right(i);
        }else{
            return Left(i);
        }
    }
}

void Heap::Swap(int p, int i){
    int temp = H[p];
    H[p] = H[i];
    H[i] = temp;
}

int Heap::Parent(int i){
    return int(i / 2);
}

int Heap::Left(int i){
    return i * 2;
}

int Heap::Right(int i){
    return i * 2 + 1;
}

int Heap::Remove(){
    if(Empty()){
        return -1;
    }
    char ch;
    int temp = H[1];
    H[1] = H[--Next];
    HeapSize--;
    
    if(HeapSize > 1){
        BubbleDown(1);
    }
    return temp;
}

void Heap::PrintHeap(){
    for(int i=1;i<Next;i++){
        cout<<H[i]<<" ";
    }
    cout<<endl;
}

int Heap::Size(){
    return Next-1;
}

bool Heap::Empty(){
    return Next == 1;
}

int main(){
    srand(2987364);
    int val = 0;
    
    int A[] = {0,10,4,7,5,9,2,11,14,3};
    int size = 9;
    
    Heap myHeap(100);
    
    myHeap.Heapify(A,size);
    // for(int i=0;i<size;i++){
    //     myHeap.Insert(A[i]);
    //   //myHeap.Insert(rand()%900+100);
    // }
   // myHeap.PrintHeap();
    cout<<endl;

    while(!myHeap.Empty() > 0){
        val = myHeap.Remove();
        cout<<val<<" ";
    }
    return 0;
}

