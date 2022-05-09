
#include <bits/stdc++.h>
using namespace std;

// naive approach
void MergeTwoSortedArrays(int *arr, int n, int *brr, int m)
{
    int *crr = new int[n + m];
    for (int i = 0; i < n; i++)
    {
        crr[i] = arr[i];
    }
    for (int i = 0; i < m; i++)
    {
        crr[n + i] = brr[i];
    }
    sort(crr, crr + m + n);
    for (int i = 0; i < m + n; i++)
    {
        cout << crr[i] << " ";
    }
    cout << "\n";
    delete[] crr;
}
// efficent approach
void MergeTwoSortedArrays_efficiently(int *arr, int n, int *brr, int m)
{
    // we compare every element and print whichever is smaller
    int i = 0;
    int j = 0;
    while (i < n && j < m)
    {
        if (arr[i] <= brr[j])
        {
            cout << arr[i++] << " ";
        }
        else
        {
            cout << brr[j++] << " ";
        }
    }
    // for remaining elements
    for (; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    for (; j < m; j++)
    {
        cout << brr[j] << " ";
    }
    cout << "\n";
}
// making a smaller named function which will internally call the above two function

void getMerge(int *arr, int n, int *brr, int m, bool mode)
{

    // call efficient approach
    if (mode)
    {
        MergeTwoSortedArrays_efficiently(arr, n, brr, m);
    }
    // cal naive approach
    else
    {
        MergeTwoSortedArrays(arr, n, brr, m);
    }
}
int main()
{

    int *arr = new int[5];
    arr[0] = 4;
    arr[1] = 7;
    arr[2] = 10;
    arr[3] = 17;
    arr[4] = 22;
    int *brr = new int[6];
    brr[0] = 2;
    brr[1] = 8;
    brr[2] = 9;
    brr[3] = 15;
    brr[4] = 23;
    brr[5] = 40;

    getMerge(arr, 5, brr, 6, true);
    getMerge(arr, 5, brr, 6, false);

    return 0;
}