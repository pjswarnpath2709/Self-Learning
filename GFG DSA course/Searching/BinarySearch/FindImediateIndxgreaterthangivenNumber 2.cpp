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
int FindImediateGreater(vll &vec, int n, int number)
{
    int low = 0;      // vec[l]<=number
    int high = n - 1; // vec[h]>number
    while (high > low + 1)
    {
        int mid = (low + high) >> 1;
        if (vec[mid] > number)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    return high;
}
int main()
{
    ll n, number;
    cin >> n >> number;
    vll vec(n);
    in_vector(vec, n);
    int ans = FindImediateGreater(vec, n, number);
    cout<<ans<<"\n";
    cout << vec[ans] << "\n";
    return 0;
}