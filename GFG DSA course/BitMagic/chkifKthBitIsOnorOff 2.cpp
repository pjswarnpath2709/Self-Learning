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
bool Kth_bit_on(ll n, int k)
{
    // using left shift
    // form a mask using 1 and left shifting it by k and did AND operation 
    return ((n & 1 << k - 1) == 0) ? false : true;

    // method 2
    /*
    using right shift operator
    shifted the k'th bit to first position and then simply did and with 1

    */
    return ((n >> (k - 1) & 1) == 1) ? true : false;
}
int main()
{
    ll n, k;
    cin >> n >> k;
    cout << ((Kth_bit_on(n, k)) ? "YES" : "NO") << "\n";
    return 0;
}