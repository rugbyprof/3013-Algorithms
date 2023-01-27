#include <iostream>
#include <vector>

using namespace std;

/**
 * This implementation uses a vector to store the elements of the heap, and provides
 * functions for adding an element (push), removing the maximum element (pop), and
 * accessing the maximum element (top). The heap is maintained by repeatedly swapping
 * elements up and down the heap until the heap property is satisfied.
 *
 * You can test the implementation by creating an instance of MaxHeap, and calling
 * the push() method to insert elements into the heap.
 *
 */

class MaxHeap {
private:
    std::vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i) + 1; }
    int rightChild(int i) { return (2 * i) + 2; }

    void swap(int i, int j) {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            std::swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int maxIndex = i;
        int l = leftChild(i);
        int r = rightChild(i);

        if (l < heap.size() && heap[l] > heap[maxIndex]) {
            maxIndex = l;
        }

        if (r < heap.size() && heap[r] > heap[maxIndex]) {
            maxIndex = r;
        }

        if (i != maxIndex) {
            std::swap(heap[i], heap[maxIndex]);
            heapifyDown(maxIndex);
        }
    }

    /**
     * This method takes in three parameters:
     * Params:
     *      n is the size of the list
     *      i is the index of the current element in the list
     * The method starts by setting the largest value to be the current element (i.e., i) and
     * then compares the left and right children of the current element to see if they are larger.
     * If either child is larger, the largest value is updated to be the value of the larger child.
     * If the root is no longer the largest value, then the root and the largest value are swapped
     * and the method is called recursively on the largest value to ensure that the sub-tree rooted
     * at that value is also a valid heap.
     *
     * It should be noted that this is a example of max heap, if you want to implement a min heap you
     * should change the signs of comparison in if conditions.
     *
     */
    void heapify(int i = 0) {
        int n = heap.size();
        int largest = i;   // Initialize largest as root
        int l = 2 * i;     // left = 2*i + 1
        int r = 2 * i + 1; // right = 2*i + 2

        // See if left child of root exists and is greater than root
        if (l < n && heap[l] > heap[largest])
            largest = l;

        // See if right child of root exists and is greater than root
        if (r < n && heap[r] > heap[largest])
            largest = r;

        // Change root, if needed
        if (largest != i) {
            swap(heap[i], heap[largest]);

            // Heapify the root.
            heapify(largest);
        }
    }

public:
    MaxHeap() {}

    MaxHeap(vector<int> array) {
        heapify(array);
    }

    void print() {
        for (int i = 0; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
    }

    void push(int x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    int pop() {
        int max = heap.front();
        std::swap(heap[0], heap.back());
        heap.pop_back();
        heapifyDown(0);
        return max;
    }

    int top() {
        return heap.front();
    }

    void heapify(vector<int> array) {
        heap = array;
        heapify(0);
    }
};

int main() {

    MaxHeap heap1;
    heap1.push(3);
    heap1.push(5);
    heap1.push(1);
    heap1.print();

    vector<int> vals{3, 4, 23, 22, 45, 67, 5, 4, 2, 99, 88, 77, 66, 55};

    MaxHeap heap2(vals);
    heap2.print();

    return 0;
}