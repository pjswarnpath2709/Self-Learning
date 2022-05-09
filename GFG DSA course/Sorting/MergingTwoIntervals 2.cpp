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
bool isMerging(pi &p1, pi &p2)
{
    if (p1.first >= p1.second)
    {
        if (p1.first <= p2.second)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (p2.first <= p1.second)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
void merge_the_pair(pi &p1, pi &p2)
{
    p1.first = min(p1.first, p2.first);
    p1.second = max(p1.second, p2.second);
}
// Naive approach
void mergeIntervals(vector<pi> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (isMerging(vec[i], vec[j]))
            {
                merge_the_pair(vec[i], vec[j]);
                vec.erase(vec.begin() + i + j);
                j--;
            }
        }
    }
    for (auto &i : vec)
    {
        cout << i.first << " " << i.second << "\n";
    }
}
void mergeIntervalSEfficient(vector<pi> vec)
{
    sort(vec.begin(), vec.end());
    int res = 0;
    for (int i = 1; i < vec.size(); i++)
    {
        if (isMerging(vec[res], vec[i]))
        {
            merge_the_pair(vec[res], vec[i]);
        }
        else
        {
            res++;
            vec[res] = vec[i];
        }
    }
    for (int i = 0; i <= res; i++)
    {
        cout << vec[i].first << " " << vec[i].second << "\n";
    }
}
// efficient approach
int main()
{
    ll n;
    cin >> n;
    vector<pi> vec(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        pi p;
        p = make_pair(x, y);
        vec[i] = p;
    }
    mergeIntervals(vec);
    mergeIntervalSEfficient(vec);
    return 0;
}