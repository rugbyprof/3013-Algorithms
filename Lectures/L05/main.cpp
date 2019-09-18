#include <iostream>

using namespace std;

class MinHeap{
private:
    int *heap;
    int size;
    int last;

int parent(int i){
    return i / 2;
}

int left(int i){
    return i * 2;
}

int right(int i){
    return i * 2 + 1;
}

public:
    MinHeap(){
        size = 100;
        heap = new int[size];
        last = 0;
        heap[0] = INT32_MIN;
    }

    void Insert(int val){
        heap[++last] = val; 
        bubbleUp();
    }

    void bubbleUp(){
        int i = last;
        int temp = 0;

        while(heap[parent(i)] > heap[i]){
            // classic swap
            temp = heap[parent(i)];
            heap[parent(i)] = heap[i];
            heap[i] = temp;
            i = parent(i);
        }
    }

    void Heapify(){

    }

    void Print(){
        for(int i=1;i<=last;i++){
            cout<<heap[i]<<" ";
        }
        cout<<endl;
    }
};

int main(int argc, char** argv){

    MinHeap H;

    //for(int i=0;i<20;i++)

    H.Insert(3);
    H.Insert(8);
    H.Insert(4);
    H.Insert(2);
    H.Insert(11);
    H.Insert(9);
    H.Insert(1);
    H.Insert(5);

    H.Print();

    return 0;
}