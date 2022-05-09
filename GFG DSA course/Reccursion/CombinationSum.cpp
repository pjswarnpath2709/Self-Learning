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
void in_array(T *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
template <class T>
void print_array(T *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
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
template <class T>
void printVec(vector<T> &vec)
{
    for (T i : vec)
    {
        cout << i << " ";
    }
    cout << "\n";
}

void printCombSum(int idx, int sumToform, int arr[], vi &vec, int n)
{
    if (sumToform == 0 && idx==n)
    {
        printVec(vec);
    }
    if (idx >= n || sumToform < 0)
    {
        return;
    }

    // pick the element
    vec.pb(arr[idx]);
    printCombSum(idx, sumToform - arr[idx], arr, vec, n);
    // not pick the element
    vec.ppb();
    printCombSum(idx + 1, sumToform, arr, vec, n);
}

int main()
{
    int n, target;
    cin >> n >> target;
    int arr[n];
    in_array(arr, n);
    vi vec;
    printCombSum(0, target, arr, vec, n);
    return 0;
}