
#include <bits/stdc++.h>
using namespace std;
/*------------------------------------------------------------------------------------------------------------*/
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
/*------------------------------------------------------------------------------------------------------------*/
template <class T>
void printVec(vector<T> &vec)
{
    for (T i : vec)
    {
        cout << i << " ";
    }
    cout << "\n";
}
template <class T>
void in_vector(vector<T> &vec, ll n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
}
void swaping(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}
/*------------------------------------------------------------------------------------------------------------*/
// Sorting Algoritms
// A)---->Bubble Sort
void BubbleSort(vector<int> &arr, int n)
{
    bool flag;
    for (int i = 0; i < arr.size(); i++)
    {
        flag = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swaping(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if (!flag)
            break;
    }
}
// B)---->Insertion Sort
void InsertionSort(vector<int> &arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int x = arr[i];
        while (j > -1 && arr[j] > x)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}
// C)---->Selection Sort
void SelectionSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int j, k;
        j = k = i;
        for (; j < n; j++)
        {
            if (arr[j] < arr[k])
            {
                k = j;
            }
        }
        swaping(arr[i], arr[k]);
    }
}
/*------------------------------------------------------------------------------------------------------------*/
int main()
{
    ll n;
    cin >> n;
    vector<int> vec(n);
    in_vector(vec, n);
    vector<int> vec2(vec);
    BubbleSort(vec2, n);
    printVec(vec2);
    vector<int> vec3(vec);
    InsertionSort(vec3, n);
    printVec(vec3);
    vector<int> vec4(vec);
    SelectionSort(vec4, n);
    printVec(vec4);
    return 0;
}