#define pb push_back
#define ppb pop_back
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
template <class T>
void printVec(vector<T> &vec)
{
    for (T i : vec)
    {
        cout << i << " ";
    }
    cout << "\n";
}
int lomutoPartition(vll &vec, int low, int high, int idx)
{
    // consider the last element as the pivot
    swap(vec[idx], vec[high]);
    ll pivot = vec[high];
    int cut = low-1; // the small window
    for (int j = low; j <= high; j++)
    {
        if (vec[j] < pivot)
        {
            cut++;
            swap(vec[cut], vec[j]);
        }
    }
    swap(vec[cut+1], vec[high]);
    return cut+1;
}
int main()
{
    ll n;
    cin >> n;
    vll vec(n);
    in_vector(vec, n);
    cout << lomutoPartition(vec, 0, 6, 6) << "\n";
    printVec(vec);

    return 0;
}