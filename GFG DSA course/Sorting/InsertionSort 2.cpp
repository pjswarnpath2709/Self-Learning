
#include <bits/stdc++.h>
using namespace std;
void InsertionSort(int *arr, int n)
{
    // we consider first element as always sorted
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main()
{

    return 0;
}