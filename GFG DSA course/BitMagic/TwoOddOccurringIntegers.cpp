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
struct DUO
{
    ll first;
    ll second;
};
ll rightMostSetBit(ll n)
{
    return n & ~(n - 1);
}
DUO TwoOddOcurringElements(vll &vec)
{
    DUO ans;
    ll res = 0;
    // first find the XOR of the odd Occuring elements
    for (auto i : vec)
    {
        res = res ^ i;
    }
    // find right most set bit in the res
    ll sgn = rightMostSetBit(res);
    //segregate according to the segregator
    res = 0;
    int res2 = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] & sgn == 0) //if the rightmst bit is set on 
        {
            res = res ^ vec[i];
        }
        else
        {
            res2 = res2 ^ vec[i];
        }
    }
    ans.first = res;
    ans.second = res2;
    return ans;
}
int main()
{
    ll n;
    cin >> n;
    vll vec(n);
    in_vector(vec, n);
    DUO ans = TwoOddOcurringElements(vec);
    cout << ans.first << ans.second << "\n";

    return 0;
}