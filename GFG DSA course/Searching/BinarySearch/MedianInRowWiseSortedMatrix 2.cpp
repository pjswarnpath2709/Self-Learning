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
int countSmallerThanMid(vi &row, int mid)
{
    int lo = 0, hi = row.size() - 1;
    while (lo <= hi)
    {
        int md = (lo + hi) >> 1;
        if (row[md] <= mid)
        {
            lo = md + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return lo;
}
int FindMedian(vector<vi> &matrix)
{
    int low = 1;
    int high = 1e9;
    int n = matrix.size();
    int m = matrix[0].size();
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += countSmallerThanMid(matrix[i], mid);
        }
        if (cnt <= (n * m) / 2)
            low = mid + 1;
        else
            high = mid + 1;
    }
}
int main()
{
    ll m,n;
    cin>>n>>m;
    vector<vi>matrix;
    for(int i=0;i<m;i++){
        in_vector(matrix[i],n);
    }
    return 0;
}