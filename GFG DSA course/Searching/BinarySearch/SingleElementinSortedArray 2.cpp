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

int singleNonDuplicate(vll &nums)
{
    int n = nums.size();
    int lo = 0, hi = n - 1;
    while (lo < hi)
    {
        int mid = (lo + hi) >> 1;
        if (nums[mid] == nums[mid ^ 1])
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }
    return nums[lo];
}

int main()
{
    ll n;
    cin >> n;
    vll vec(n);
    in_vector(vec, n);
    cout << singleNonDuplicate(vec) << "\n";

    return 0;
}