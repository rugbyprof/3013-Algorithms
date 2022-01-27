#include <iostream>

using namespace std;

class Heap {
    int *heap;
    int rear;
    int size;

    int Parent(int i) {
        return i / 2;
    }

    int Left(int i) {
        return 2 * i;
    }

    int Right(int i) {
        return (2 * i) + 1;
    }

    void BubbleUp(int i) {
        int p = Parent(i);
        while (i > 1 && heap[i] < heap[p]) {
            Swap(i, p);
            i = p;
            p = Parent(i);
        }
    }

    void Swap(int i, int j) {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    bool OnHeap(int i) {
        return i < rear;
    }

    void BubbleDown(int i) {
        int left = Left(i);
        int right = Right(i);
    }

public:
    Heap() {
        size = 10;
        heap = new int[size];
        rear = 1;
    }

    void Insert(int x) {
        heap[rear] = x;
        BubbleUp(rear);
        rear++;
    }

    // STOPPED HERE NEED TO IMPLEMENT BUBBLEDOWN
    int Remove() {
        int temp = heap[1];
        rear--;
        heap[1] = heap[rear];
        BubbleDown(1);
        return temp;
    }

    void Print() {
        for (int i = 1; i < rear; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap H;
    H.Insert(8);
    H.Insert(2);
    H.Insert(3);
    H.Insert(1);
    H.Print();
}