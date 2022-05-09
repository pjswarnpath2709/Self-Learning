
#include <bits/stdc++.h>
using namespace std;
// appraoch for merge function is
void mergeArray(int *arr, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int size = high - low + 1;
    int *temp = new int[size];
    int k = 0;
    // merging array by comparijg elements
    while (i < mid + 1 && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    // for remaining elements
    for (; j <= high;)
    {
        temp[k++] = arr[j++];
    }
    for (; i < mid + 1; i++)
    {
        temp[k++] = arr[i++];
    }
    // copy temp array into original array
    for (int m = 0; m < size; m++)
    {
        arr[low + m] = temp[m];
    }
    // delete t he array temp
    delete[] temp;
}
// anothe appraoch for merge function is

void mergeArrays(int *arr, int low, int mid, int high)
{
    // creating two new arrays of respected size
    int size1 = mid - low + 1;
    int size2 = high - mid;
    int *left = new int[size1];
    int *right = new int[size2];
    // filling the arrays
    for (int i = 0; i < size1; i++)
    {
        left[i] = arr[low + i];
    }
    for (int i = 0; i < size2; i++)
    {
        right[i] = arr[mid + i + 1];
    }
    // mergig these arrays into the original array
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < size1 && j < size2)
    {
        if (left[i] <= right[i])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }
    // copying remaining elemts
    for (; j < size2;)
    {
        arr[k++] = right[j++];
    }
    for (; i < size1;)
    {
        arr[k++] = left[i++];
    }
    delete[] left;
    delete[] right;
}

void MergeSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2; // same as (low+high)/2
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        mergeArray(arr, low, mid, high);
    }
}
int main()
{

    return 0;
}