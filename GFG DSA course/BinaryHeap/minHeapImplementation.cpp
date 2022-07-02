

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
};

int main()
{
    minHeap h(4);
    return 0;
}