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
void printVec(vector<T> &vec)
{
    for (T i : vec)
    {
        cout << i << " ";
    }
    cout << "\n";
}
template <class T>
void print_matrix(T **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j];
        }
        cout << "\n";
    }
}
template <class T>
void in_matrix(T **matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }
}
template <class T>
void out_matrix_fun(T **matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
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
bool is_sorted(vll &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] > vec[i + 1])
        {
            return false;
        }
    }
    return true;
}
int numSubarrayBoundedMax(vll &vec, int left, int right)
{
    int i = 0;
    int j = 0;
    int ans = 0;
    int n = vec.size();
    int subarrayCount = 0; // count of total subarrays ending  with that number
    int prevCount = 0;     // previous subarray count ending with previous number
    while (j < n)
    {
        if (vec[j] >= left && vec[j] <= right)
        {
            subarrayCount = j - i + 1; // count of  subbarrays ending at that number
            prevCount = subarrayCount;
            ans += prevCount; // count of total subarrays which satisfies the answer
        }
        else if (vec[j] < left)
        {
            // the answer will be added with previous count becuase one subaaray will not be counted
            ans += prevCount;
        }
        else
        {
            // we got hit by a break point
            // do reset
            i = j + 1;
            prevCount = 0; // reset the prevCount to find new subarrays before another breakpoint
        }
        j++;
    }
    return ans;
}
int main()
{
    ll n;
    cin >> n;
    vll vec(n);
    in_vector(vec, n);
    ll left, right;
    cin >> left >> right;
    cout << numSubarrayBoundedMax(vec, left, right) << "\n";

    return 0;
}