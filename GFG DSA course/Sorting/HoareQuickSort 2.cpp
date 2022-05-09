#define vi vector<int>
#define vll vector<long long>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <class T>
void in_vector(vector<T> &vec, ll n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
}
int hoarePartition(vi &vec, int low, int high)
{
    int key = vec[low];
    int i = low - 1;
    int j = high + 1;
    while (true)
    {
        do
        {
            i++;
        } while (vec[i] < key);
        do
        {
            j--;
        } while (vec[j] > key);
        if (i >= j)
        {
            return j;
        }
        swap(vec[j], vec[i]);
    }
}
void quickSort(vi &vec, int low, int high)
{
    if (low < high)
    {
        int pivot = hoarePartition(vec, low, high);
        quickSort(vec, low, pivot);
        quickSort(vec, pivot + 1, high);
    }
}
int main()
{
    ll n;
    cin >> n;
    vi vec(n);
    in_vector(vec, n);
    quickSort(vec, 0, n - 1);
    for (auto i : vec)
    {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}