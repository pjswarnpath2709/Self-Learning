

#define vi vector<int>
#define vll vector<long long>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

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
ll kadaneMax(vll vec, int n)
{
    ll maxEnding = vec[0];
    ll res = vec[0];
    for (int i = 1; i < n; i++)
    {
        maxEnding = max(vec[i], maxEnding + vec[i]);
        res = max(res, maxEnding);
    }
    return res;
}
int Kconcat(vll &vec, int n, int k)
{

    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += vec[i];
    }
    // creating new array
    vll vec2 = vec;
    for (auto i : vec)
    {
        vec2.push_back(i);
    }
    ll kadaneforTwo = kadaneMax(vec2, vec2.size());
    ll kadaneforOne = kadaneMax(vec, vec.size());
    if (k == 1)
    {
        return kadaneforOne;
    }
    else
    {
        return max(kadaneforOne, max(kadaneforTwo, kadaneforTwo + sum * (k - 2)));
    }
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    vll vec(n);
    in_vector(vec, n);
    cout << Kconcat(vec, n, k) << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}