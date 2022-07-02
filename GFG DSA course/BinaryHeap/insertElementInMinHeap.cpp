

#include <bits/stdc++.h>
using namespace std;

class minHeap
{
public:
    int size;
    int cap;
    int *arr;

public:
    minHeap(int capacity)
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

int main()
{

    minHeap h(11);

    h.insert(3);
    h.insert(2);
    h.insert(15);
    h.insert(20);

    return 0;
}