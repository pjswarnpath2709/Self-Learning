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
#define pi pair<int, int>
#define pll pair<long long, long long>
#define all_vec vec.begin(), vec.end()
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())

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
    cerr << "[ ";
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
int countSetBitOn(ll n)
{
    ll count = 0;
    while (n > 0)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}
int power_function(int n, int j)
{
    if (n == 0)
    {
        return 0;
    }
    if (j == 1)
    {
        return n;
    }
    else
    {
        if (j % 2 == 0)
            return power_function(n * n, j / 2);
        else
        {
            return n * power_function(n * n, (j - 1) / 2);
        }
    }
}

/*------------------------------------------------------------------------------------------------------------------------*/
bool is_prime(ll n)
{
    if (n == 0 || n == 1)
    {
        return false;
    }
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int gcd_Int(int a, int b)
{
    int result = min(a, b);
    while (result > 0)
    {
        if (a % result == 0 && b % result == 0)
        {
            break;
        }
        result;
    }
    return result;
}

ll gcd_Long(ll a, ll b)
{
    ll result = min(a, b);
    while (result > 0)
    {
        if (a % result == 0 && b % result == 0)
        {
            break;
        }
        result--;
    }
    return result;
}
/*------------------------------------------------------------------------------------------------------------------------*/
void printGood(vector<vc> &good)
{
    for (int i = 1; i < good.size(); i++)
    {
        for (int j = 1; j < good[i].size(); j++)
        {
            cout << good[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}
bool inGrid(int row, int col, int n)
{
    if (row >= 1 && row <= n && col >= 1 && col <= n)
    {
        return true;
    }
    return false;
}
bool horizontalContainsX(vector<vc> good, int ri, int ci, int k)
{

    for (int col = ci + 1; col < ci + k; col++)
    {
        if (inGrid(ri, col, good.size() - 1))
        {
            if (good[ri][col] == 'X')
            {
                return true;
            }
        }
    }
    for (int col = ci - 1; col > ci - k; col--)
    {
        if (inGrid(ri, col, good.size() - 1))
        {
            if (good[ri][col] == 'X')
            {
                return true;
            }
        }
    }

    return false;
}
bool verticalContainsX(vector<vc> &good, int r, int c, int k)
{

    for (int row = r + 1; row < r + k; row++)
    {
        if (inGrid(row, c, good.size() - 1))
        {
            if (good[row][c] == 'X')
            {
                return true;
            }
        }
    }
    for (int row = r - 1; row > r - k; row--)
    {
        if (inGrid(row, c, good.size() - 1))
        {
            if (good[row][c] == 'X')
            {
                return true;
            }
        }
    }

    return false;
}
void solve()
{
    ll n, k, r, c;
    cin >> n >> k >> r >> c;
    vector<vc> good(n + 1);
    for (int i = 1; i <= n; i++)
    {
        vector<char> vec(n + 1, '.');
        good[i] = vec;
    }
    good[r][c] = 'X';

    for (int row = r; row <= n; row++)
    {
        for (int col = c; col <= n; col++)
        {
            if (good[row][col] == '.' && !horizontalContainsX(good, row, col, k) && !verticalContainsX(good, row, col, k))
            {
                good[row][col] = 'X';
            }
        }
    }
    for (int row = r; row >= 1; row--)
    {
        for (int col = c; col >= 1; col--)
        {
            if (good[row][col] == '.' && !horizontalContainsX(good, row, col, k) && !verticalContainsX(good, row, col, k))
            {
                good[row][col] = 'X';
            }
        }
    }
    printGood(good);
}

/*----------------------------------------------------------------------------------------------------------------------------*/
int32_t main()
{
#ifdef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    int t = 0;
    cin >> t;
    for (int test_count = 0; test_count < t; test_count++)
    {
        solve();
    }
}

//////-------------------------------------------------------------------------------------------------------------------------------//////

// int32_t main()
// {
// #ifdef ONLINE_JUDGE
//     freopen("Error.txt", "w", stderr);
// #endif
//     fastio();
//     solve();
//}