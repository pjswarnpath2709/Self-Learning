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
#define vs vector<string>
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
void recurPermute(vi &vec, vi &ds, vector<vi> &ans, int freq[])
{
    if (ds.size() == vec.size())
    {
        ans.pb(ds);
        return;
    }
    for (int i = 0; i < vec.size(); i++)
    {
        if (!freq[i])
        {
            ds.pb(vec[i]);
            freq[i] = 1;
            recurPermute(vec, ds, ans, freq);
            freq[i] = 0;
            ds.ppb();
        }
    }
}
vector<vi> permute(vi &vec)
{
    vector<vi> ans;
    vi ds;

    int n = vec.size();
    int freq[n];
    for (int i = 0; i < n; i++)
    {
        freq[i] = 0;
    }
    recurPermute(vec, ds, ans, freq);
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