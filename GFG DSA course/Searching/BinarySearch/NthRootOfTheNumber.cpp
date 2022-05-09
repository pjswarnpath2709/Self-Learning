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
lld multiply(lld number, int multiply_times)
{
    lld ans = 1.0;
    for (int i = 1; i <= multiply_times; i++)
    {
        ans *= number;
    }
    return ans;
}
void solve(int number, int root_number)
{
    lld low = 1.0;
    lld high = (double)number;
    lld eps = 1e-10; // always equal to ...... eps=1e-(asked_precision -1);
    while ((high - low) > eps)
    {
        lld mid = (low + high) / 2;
        if (multiply(mid, root_number) < number)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    cout << setprecision(11) << max(low, high) << "\n";
}
int main()
{
    int number, root_number;
    cin >> number >> root_number;
    solve(number, root_number);
    return 0;
}