#define vi vector<int>
#define vll vector<long long>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
template <class T>
void in_vector(vector<T> &vec, ll n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
}
template <class T>
void printVec(vector<T> &vec)
{
    for (T i : vec)
    {
        cout << i << " ";
    }
    cout << "\n";
}
int lomutoPartion(vi &vec, int low, int high, int idx)
{
    swap(vec[high], vec[idx]);
    int key = vec[high];
    int cut = low-1;
    for (int j = low; j <= high; j++)
    {
        if (vec[j] < key)
        {
            cut++;
            swap(vec[j], vec[cut]);
        }
    }
    swap(vec[high], vec[cut+1]);
    return cut+1;
}
void quickSort(vi &vec, int low, int high)
{
    if (low < high)
    {
        int pivot = lomutoPartion(vec, low, high, high);
        quickSort(vec, low, pivot - 1);
        quickSort(vec, pivot + 1, high);
    }
}
int main()
{
    int n;
    cin >> n;
    vi vec(n);
    in_vector(vec, n);
    quickSort(vec, 0, n - 1);
    printVec(vec);

    return 0;
}