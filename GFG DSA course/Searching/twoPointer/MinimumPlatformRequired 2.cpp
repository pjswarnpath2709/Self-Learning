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
int MinimumPlatformRequired(vi &arr, vi &dep)
{
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int plat_needed = 1;
    int results = 1;
    int i = 1;
    int j = 0;
    while (i < arr.size() || j < arr.size())
    {
        if (arr[i] <= dep[j])
        {
            plat_needed++;
            i++;
        }
        if(arr[i]>dep[j]){
            plat_needed--;
            j++;
        }
        results=max(results,plat_needed);
    }
    return results;
}
int main()
{
    int n;
    cin >> n;
    vi arr(n);
    vi dep(n);
    in_vector(arr, n);
    in_vector(dep, n);
    cout << MinimumPlatformRequired(arr, dep) << "\n";

    return 0;
}