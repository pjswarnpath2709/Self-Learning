

#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
public:
    int size;
    int cap;
    int *arr;

public:
    MinHeap(int capacity)
    {
        size = 0;
        cap = capacity;
        arr = new int[cap];
    }

    int leftIndex(int i)
    {
        return 2 * i + 1;
    }
    int rightIndex(int i)
    {
        return 2 * i + 2;
    }
    int parentIndex(int i)
    {
        return (i - 1) / 2;
    }

    void insert(int x)
    {
        if (size == cap)
        {
            return;
        }
        size++;
        arr[size - 1] = x;
        for (int i = size - 1; i != 0 && arr[parentIndex(i)] > arr[i];)
        {
            swap(arr[i], arr[parentIndex(i)]);
            i = parentIndex(i);
        }
    }
};

void minHeapify(MinHeap *minheap, int idx)
{
    int smallest = idx;
    int leftIdx = minheap->leftIndex(idx);
    int rightIdx = minheap->rightIndex(idx);

    int _size = minheap->size;
    int *_arr = minheap->arr;
    // check if left Child exits and if it does , is it has smaller value then smallest
    if (leftIdx < _size && _arr[leftIdx] < _arr[smallest])
    {
        cout << "left: " << leftIdx << "\n";
        smallest = leftIdx;
    }
    // check if right Child exits and if it does ,  is it has smaller value then smallest
    if (rightIdx < _size && _arr[rightIdx] < _arr[smallest])
    {
        cout << "right: " << rightIdx << "\n";
        smallest = rightIdx;
    }
    // if the smallest index is the same as the idx then no change is required , if does the change required recusively call for the smallest index after swaping it with the idx
    if (smallest != idx)
    {
        swap(_arr[idx], _arr[smallest]);
        minHeapify(minheap, smallest);
    }
}

int main()
{

    MinHeap h(15);
    h.insert(40);
    h.insert(20);
    h.insert(30);
    h.insert(35);
    h.insert(25);
    h.insert(80);
    h.insert(32);
    h.insert(100);
    h.insert(70);
    h.insert(60);

        // minHeapify(&h, 0);

    for (int i = 0; i < 10; i++)
    {
        cout << h.arr[i] << " ";
    }

    return 0;
}