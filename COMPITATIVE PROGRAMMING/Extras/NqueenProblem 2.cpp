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
int Subsequences(string input, string output[])
{
    if (input == "")
    {
        output[0] = "";
        return 1;
    }
    string substring = input.substr(1);
    int smallOutputSize = Subsequences(substring, output);
    for (int i = 0; i < smallOutputSize; i++)
    {
        output[i + smallOutputSize] = input[0] + output[i];
    }

    return 2 * smallOutputSize;
}
void getSubsequences(string input, string output)
{
    if (input.length() == 0)
    {
        cout << output << " ";
        return;
    }
    getSubsequences(input.substr(1), output);
    getSubsequences(input.substr(1), output + input[0]);
}
/*---------------------------------------------------------------------------------------------------------------*/
int boards[100][100];
bool isPossible(int n, int row, int col)
{
    // vertical coloumn
    for (int i = row - 1; i >= 0; i--)
    {
        if (boards[i][col] == 1)
        {
            return false;
        }
    }
    // upper left daigonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (boards[i][j] == 1)
        {
            return false;
        }
    }
    // upper right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (boards[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}
void QueenHelper(int n, int row)
{
    if (row == n)
    {
        // simply we have to print answer otherwise we have to chk for the next row
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << boards[i][j] << " ";
            }
        }
        cout << endl;
        return;
    }
    // place at allpossible positions and move to smaller problem
    for (int j = 0; j < n; j++)
    {
        if (isPossible(n, row, j))
        {
            boards[row][j] = 1;
            QueenHelper(n, row + 1);
            boards[row][j] = 0;
        }
    }
    return;
}
void placeNqueens(int n)
{
    memset(boards, 0, 100 * 100 * sizeof(int)); // this function initialise all vaalues with a single value in ciontigoius space
    QueenHelper(n, 0);
}
void solve()
{
    int n;
    cin >> n;
    placeNqueens(n);
}

/*------------------------------------------------------------------------------------------------------------------------*/
int main()
{

#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    ll t = 0;
    cin >> t;
    for (int test_count = 0; test_count < t; test_count++)
    {
        solve();
    }
#ifndef ONLINE_JUDGE
#endif
    return 0;
}