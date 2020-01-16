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
        // need to check for end of array!!!
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

    int getSmallestChild(int i){
        int smallest = 0;
        
        // no children
        if(2*i > last){
            return -1;  
        }

        // checking both children
        if(heap[2*i] < heap[2*i+1]){
            if(heap[i] > heap[2*i]){
                return 2*i;
            }else{
                return -1;
            }
        }else{
            if(heap[i] > heap[2*i+1]){
                return 2*i+1;
            }else{
                return -1;
            }
        }
    }

    void swap(int i,int j){
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    void bubbleDown(int i){

        int j = getSmallestChild(i);

        if(j < 0){
            return;
        }

        if(j != -1){
            swap(i,j);
            bubbleDown(j);
        }


    }

    void Heapify(){

    }

    bool Empty(){
        return last == 0;
    }

    int extractMin(){
        int retVal = heap[1];
        heap[1] = heap[last--];
    
        // bubble down

        return retVal;
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

    while(!H.Empty()){
        cout<<H.extractMin()<<endl;
        H.bubbleDown(1);
    }

    H.Print();

    return 0;
}