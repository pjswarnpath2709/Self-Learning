
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define mset multiset
#define uset unordered_set
#define umap unordered_map
#define nline "\n"
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
/*---------------------------------------------------------------------------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;

/*---------------------------------------------------------------------------------------------------------------------------*/
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
/*---------------------------------------------------------------------------------------------------------------------------*/
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
void shift(vi &vec, int l, int r)
{
    reverse(vec.begin() + l, vec.begin() + r + 1);
    reverse(vec.begin() + l, vec.begin() + r);
}
int BS(vi vec, int low, int high, int x)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (vec[mid] == x)
        {
            return mid;
        }
        else if (vec[mid] > x)
        {
            return BS(vec, low, mid - 1, x);
        }
        else
        {
            return BS(vec, mid + 1, high, x);
        }
    }
    return -1;
}
/*---------------------------------------------------------------------------------------------------------------------------*/
// To find leftmost index of a repeted number in a sorted array
int BSL(vi vec, int low, int high, int x)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (vec[mid] == x && (mid == low || vec[mid - 1] != x)) // this condition is important
        return mid;
    if (vec[mid] >= x) // this condition is important
    {
        return BSL(vec, low, mid - 1, x);
    }
    else
    {
        return BSL(vec, mid + 1, high, x);
    }
}
// To find rightmost index of a repated number in a sorted array
int BSR(vi vec, int low, int high, int x)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (vec[mid] == x && (mid == vec.size() - 1 || vec[mid + 1] != x)) // this condition is important
        return mid;
    if (vec[mid] > x) // this condition is important
    {
        return BSR(vec, low, mid - 1, x);
    }
    else
    {
        return BSR(vec, mid + 1, high, x);
    }
}
/*---------------------------------------------------------------------------------------------------------------------------*/
/*
given a sorted and rotated array of distinct elements and an element x,find if x is present in the array or not
{10,20,40,5,6,7,8} -->pivot point is the maximum or minimum element always
so we need a function tio find the pivot point and then we will simply apply binary search in both arrays after pivation
*/
int pivation(vi vec, int low, int high)
{
    if (low == high)
    {
        return low;
    }
    if (low < high)
    {
        int mid = (low + high) / 2;
        if (mid < high && vec[mid] > vec[mid + 1] && vec[mid] > vec[mid - 1])
        {
            int pivot = mid;
            return pivot;
        }
        if (vec[mid] < vec[0])
        {
            return pivation(vec, low, mid - 1);
        }
        else
        {
            return pivation(vec, mid + 1, high);
        }
    }
}
int search(vi vec, int x)
{
    int pivot = pivation(vec, 0, vec.size() - 1);
    cout << pivot << "\n";
    int val = BS(vec, 0, pivot, x);
    int val2 = BS(vec, pivot + 1, vec.size() - 1, x);
    return max(val, val2);
}
/*---------------------------------------------------------------------------------------------------------------------------*/
int PeakElement(vi vec, int low, int high)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if ((mid == 0 || vec[mid - 1] <= vec[mid]) && (mid == vec.size() - 1 || vec[mid + 1] <= vec[mid]))
        {
            return mid;
        }
        if (vec[mid - 1] > vec[mid])
        {
            return PeakElement(vec, low, mid);
        }
        else
        {
            return PeakElement(vec, mid, high);
        }
    }
    else
    {
        return -1;
    }
}
/*---------------------------------------------------------------------------------------------------------------------------*/
void solve()
{
    ll n;
    cin >> n;
    vi vec(n);
    in_vector(vec, n);
    cout << vec[PeakElement(vec,0,n-1)] << "\n";
}
/*---------------------------------------------------------------------------------------------------------------------------*/
int main()
{
    fastio();
    ll t = 0;
    cin >> t;
    for (int test_count = 0; test_count < t; test_count++)
    {
        solve();
    }
    return 0;
}
/*---------------------------------------------------------------------------------------------------------------*/
