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

bool isTwoSum(vll vec, int sum, int n)
{
    sort(vec.begin(), vec.end());
    int low = 0;
    int high = n - 1;
    while (high > low)
    {
        if (vec[low] + vec[high] > sum)
        {
            while (vec[high] == vec[high - 1])
            {
                high--;
            }
        }
        if (vec[low] + vec[high] == sum)
        {
            return true;
        }
        else
        {
            while (vec[low] == vec[low + 1])
            {
                low++;
            }
        }
    }
    return false;
}
int main()
{
    ll n;
    cin >> n;
    vll vec(n);
    in_vector(vec, n);

    return 0;
}