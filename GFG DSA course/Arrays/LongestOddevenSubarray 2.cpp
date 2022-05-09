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

/*---------------------------------------------------------------------------------------------------------------*/
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
/*------------------------------------------------------------------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }
void _print(bool t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{

    cerr
        << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
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

/*------------------------------------------------------------------------------------------------------------------------*/
// naive approach-->O(n*n)
/*
in this we are starting a subarray from every index and incrementing the length of it till
there is breakage of the law in the array
*/
int maxEvenOdd(vi &vec)
{
    int n = vec.size();
    int res = 1;
    for (int i = 0; i < n; i++)
    {
        int curr = 1;
        for (int j = i; j < n; j++)
        {
            if ((vec[i] % 2 == 0 && vec[i - 1] % 2 != 0) || (vec[i] % 2 == 1 && vec[i - 1] % 2 != 1))
            {
                curr++;
            }
            else
            {
                break;
            }
        }
        res = max(res, curr);
    }
    return res;
}
// efficient approach-->O(n)
// based on the kadane's algorithm
/*
in this approach we are starting from the second element,i.e,index=1
the i'th index tells us that here the subarray is ending,

in kadane's algorithm we have to approaches either start a new
subarray from that index for either extend the previous subarray

->in this approach we are extending the pevious subarray

*/
int kadane_maxEvenOdd(vi &vec)
{
    int res = 1;
    int curr = 1;
    for (int i = 0; i < vec.size(); i++)
    {
        if ((vec[i] % 2 == 0 && vec[i - 1] % 2 != 0) || (vec[i] % 2 == 1 && vec[i - 1] % 2 == 0))
        {
            curr++;
            res = max(res, curr); // continue the previous trail
        }
        else
        {
            curr = 1; // or start the new trail
        }
    }
    return res;
}
void solve()
{
    int n;
    cin >> n;
    vi vec(n);
    in_vector(vec, n);
    cout << maxEvenOdd(vec) << "\n";
    cout << kadane_maxEvenOdd(vec) << "\n";
}

/*------------------------------------------------------------------------------------------------------------------------*/
int main()
{
    fastio();
    solve();
    return 0;
}