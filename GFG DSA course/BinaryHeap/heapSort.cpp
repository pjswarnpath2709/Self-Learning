#include <bits/stdc++.h>
using namespace std;

void maxHeapify(int arr[], int size, int idx)
{
    int largest = idx;
    int leftIdx = 2 * idx + 1;
    int rightIdx = 2 * idx + 2;
    if (leftIdx < size && arr[leftIdx] > arr[largest])
    {
        largest = leftIdx;
    }
    if (rightIdx < size && arr[rightIdx] > arr[largest])
    {
        largest = rightIdx;
    }
    if (largest != idx)
    {
        swap(arr[idx], arr[largest]);
        maxHeapify(arr, size, largest);
    }
}

void buildMaxHeap(int arr[], int size)
{
    for (int i = (size - 2) / 2; i >= 0; i--)
    {
        maxHeapify(arr, size, i);
    }
}

void heapSort(int arr[], int n)
{
    buildMaxHeap(arr, n);
    for (int i = n - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

int main()
{

    return 0;
}