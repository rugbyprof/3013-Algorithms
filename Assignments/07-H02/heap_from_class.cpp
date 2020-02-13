#include <iostream>

using namespace std;

class Heap{
private:
  int size;
  int *H;
  int end;
public:
  Heap(){
    size = 100;
    H = new int[size];
    end = 1;
  }
  Heap(int s){
    size = s;
    H = new int[s];
    end = 1;
  }

  void Insert(int x){
    H[end] = x;
    BubbleUp(end);
    end++;
  }

  void BubbleUp(int index){
    //check parent 
    if(Parent(index) >= 1){
      while(index > 1 && H[index] < H[Parent(index)]){
        Swap(index,Parent(index));
        index = Parent(index);
      }
    }
  }

  void Swap(int i, int j){
    int temp = H[i];
    H[i] = H[j];
    H[j] = temp;
  }

  int Remove(){
    int temp = H[1];
    H[1] = H[end];
    --end;

    return temp;
  }

  void SinkDown(int index){

      while(OnHeap(index)){
        
      }
  }

  // Picks larger or (smaller) of the two
  // children and returns the index
  int PickChild(int index){
    // if(Left(index) >= end){
    //   return -1;
    // }
      
    if(end % 2 == 1){
      // no right child
      return Left(index);
    }else{
      // got two children
        if(Right(index) < end){
          if(H[Right(index)] > H[Left(index)]){
            return Left(index);
          }else{
            return Right(index);
          }
        }
    }
  }

  int Left(int index){
    return 2*index;
  }

  int Right(int index){
    return 2*index+1;
  }

  bool OnHeap(int index){
    return index < end;
  }

  int Parent(int index){
    return index/2;
  }

  void Print(){
    for(int i=1;i<=end-1;i++){
      cout<<H[i]<<"->";
    }
  }

};

int main() {
  Heap H;

  H.Insert(17);
  H.Insert(11);

  for(int i = 1;i<=10;i++){
    H.Insert(i);
  }

  H.Print();
 
}