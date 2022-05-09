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
template <class T>
void printVec(vector<T> &vec)
{
    for (T i : vec)
    {
        cout << i << " ";
    }
    cout << "\n";
}
ll findClosestFromLeftToTarget(vll vec, ll target)
{
    int low = -1;          // vec[low]<=target
    int high = vec.size(); // vec[high]>target
    while (high > low + 1)
    {
        int mid = (low + high) >> 1;
        if (vec[mid] <= target)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    return low+1; // at the end low will point at the maximum index which is smaller than the target
}
void solve()
{
    ll n, target;
    cin >> n >> target;
    vll vec(n);
    in_vector(vec, n);
    cout << findClosestFromLeftToTarget(vec, target) << "\n";
}
int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        solve();
    }
    return 0;
}