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
ll n, k;
bool good(double x, vll &vec)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += floor(vec[i] / x);
    }
    return s >= k;
}
int main()
{
    cin >> n >> k;
    vll vec(n);
    in_vector(vec, n);

    double l = 0;   // good(l) =true
    double r = 1e8; // good(r)=bad
    for (int i = 0; i < 100; i++)
    {
        double m = (l + r) / 2;
        if (good(m, vec))
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    cout << setprecision(20) << l << "\n";
    return 0;
}