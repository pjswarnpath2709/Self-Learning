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
#define pi pair<int, int>
#define pll pair<long long, long long>
#define all_vec vec.begin(), vec.end()
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define MOD 1000000007
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
ll w, h, n;
bool good(ll x)
{
    return (x / w) * (x / h) >= n;
}
int main()
{
    cin >> w >> h >> n;

    ll l = 0; // good(l)=0
    ll r = 1; // good(r)=1
    while (!good(r))
    {
        r *= 2;
    }

    while (r > l + 1)
    {
        ll m = (l + r) / 2;
        if (good(m))
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }
    // answer will be in r
    cout << r << "\n";
    return 0;
}