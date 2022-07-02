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

    void minHeapify(int idx)
    {
        int smallest = idx;
        int leftIdx = leftIndex(idx);
        int rightIdx = rightIndex(idx);

        // check if left Child exits and if it does , is it has smaller value then smallest
        if (leftIdx < size && arr[leftIdx] < arr[smallest])
        {
            smallest = leftIdx;
        }
        // check if right Child exits and if it does ,  is it has smaller value then smallest
        if (rightIdx < size && arr[rightIdx] < arr[smallest])
        {
            smallest = rightIdx;
        }
        // if the smallest index is the same as the idx then no change is required , if does the change required recusively call for the smallest index after swaping it with the idx
        if (smallest != idx)
        {
            swap(arr[idx], arr[smallest]);
            minHeapify(smallest);
        }
    }

    int extractMinimum()
    {
        if (size == 0)
        {
            return INT_MAX;
        }
        if (size == 1)
        {
            size--;
            return arr[0];
        }
        // swap the last element with the root
        swap(arr[0], arr[size - 1]);
        int ans = arr[size - 1];
        size--;
        // now the smallest element is not on the top then we have to correct the whole heap
        minHeapify(0);
        return ans;
    }
    // decrease key function
    void decreaseKey(int idx, int value)
    {
        this->arr[idx] = value;
        int i = idx;
        while (i != 0 && this->arr[parentIndex(i)] < this->arr[i])
        {
            swap(this->arr[i], this->arr[parentIndex(i)]);
            i = parentIndex(i);
        }
    }
    // delete key function
    void deleteKey(int idx)
    {
        decreaseKey(idx, INT_MIN);
        extractMinimum();
    }

private:
    // the build heap fucntion
    void _buildMinHeap(int _arr[], int n)
    {
        for (int i = (n - 2) / 2; i >= 0; i--)
        {
            minHeapify(i);
        }
    }

public:
    // constructor using build heap function
    MinHeap(int _arr[], int _size, int _capacity)
    {
        this->arr = _arr;
        this->cap = _capacity;
        this->size = _size;
        _buildMinHeap(this->arr, this->size);
    }
};

int main()
{

    MinHeap h(11);
    h.insert(3);
    h.insert(2);
    h.insert(15);
    h.insert(20);
    return 0;
}