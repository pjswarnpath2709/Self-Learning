#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define mset multiset
#define uset unordered_set
#define umap unordered_map
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
int naivePartition(vll &vec, int low, int high, int idx)
{
    ll key = vec[idx];
    vll temp(high - low + 1);
    int k = 0;
    // for the smaller one
    for (int i = low; i <= high; i++)
    {
        if (vec[i] < key)
        {
            temp[k++] = vec[i];
        }
    }
    // for the equal one
    for (int i = low; i <= high; i++)
    {
        if (vec[i] == key)
        {
            temp[k++] = vec[i];
        }
    }
    int res = low + k - 1; // formatting the index
    // for the greater one
    for (int i = low; i <= high; i++)
    {
        if (vec[i] > key)
        {
            temp[k++] = vec[i];
        }
    }
    for (int i = 0; i < temp.size(); i++)
    {
        vec[i] = temp[i + low];
    }
    temp.clear();
    return res;
}
int main()
{
    ll n;
    cin >> n;
    vll vec(n);
    in_vector(vec, n);
    int idx;
    cin >> idx;
    int ans = naivePartition(vec, 0, n - 1, idx);
    cout << ans << "\n";
    printVec(vec);

    return 0;
}