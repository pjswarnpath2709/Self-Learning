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
//brute force approach
/*
it will be the powerSet approach that we will use to generate all possible combinations
*/
// optimised recursive  approach
void subSetSum(int idx, int sumTillyet, vi &vec, int n, vi &ans)
{
    if (idx == n)
    {
        // cout << sumTillyet << "\n";
        ans.pb(sumTillyet);
        return;
    }
    // lets pick that element
    subSetSum(idx + 1, sumTillyet + vec[idx], vec, n, ans);
    // lets not pick that element
    subSetSum(idx + 1, sumTillyet, vec, n, ans);
}
int main()
{
    int n;
    cin >> n;
    vi vec(n);
    in_vector(vec, n);
    vi ans;
    subSetSum(0, 0, vec, n, ans);
    sort(ans.begin(), ans.end());
    printVec(ans);
    return 0;
}