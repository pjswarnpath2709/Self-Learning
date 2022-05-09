#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define mset multiset
#define uset unordered_set
#define umap unordered_map
#define vi vector<int>
#define vll vector<long long>
#define vc vector<char>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
template <class T>
void in_array(T *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
template <class T>
void print_array(T *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
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
template <class T>
void printVec(vector<T> &vec)
{
    for (T i : vec)
    {
        cout << i << " ";
    }
    cout << "\n";
}
void printPermuations(int idx, int n, vi &vec, vi &ds, vector<vi> &ans)
{
    if (idx == n)
    {
        ans.pb(ds);
        return;
    }
    for (int i = idx; i < n; i++)
    {
        swap(vec[idx], vec[i]);
        printPermuations(idx + 1, n, vec, ds, ans);
        swap(vec[idx], vec[i]);
    }
}
vector<vi> permute(int n, vi &vec)
{
    vector<vi> ans;
    vi ds;
    printPermuations(0, n, vec, ds, ans);
    return ans;
}
int main()
{
    ll n;
    cin >> n;
    vll vec(n);
    in_vector(vec, n);

    return 0;
}