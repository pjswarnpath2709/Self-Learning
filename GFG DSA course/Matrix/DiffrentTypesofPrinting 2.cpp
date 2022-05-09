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
/*------------------------------------------------------------------------------------------------------------------------*/

const int N = 10;
int n;
int arr[1000];

void printSnake(int **matrix, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        if (m % 2 == 0)
        {
            for (int j = 0; i < n; j++)
            {
                cout << matrix[i][j] << " ";
            }
        }
        else
        {
            for (int j = n - 1; j >= 0; j--)
            {
                cout << matrix[i][j] << " ";
            }
        }
        cout << "\n";
    }
}
void printBoundary(int **matrix, int m, int n)
{

    if (m == 1)
    {
        for (int i = 0; i < n; i++)
            cout << matrix[0][i] << " ";
    }
    else if (n == 1)
    {
        for (int i = 0; i < m; i++)
            cout << matrix[i][0] << " ";
    }
    else
    {
        for (int i = 0; i < n; i++)
            cout << matrix[0][i] << " ";
        for (int i = 1; i < m; i++)
            cout << matrix[i][n - 1] << " ";
        for (int i = n - 2; i >= 0; i--)
            cout << matrix[m - 1][i] << " ";
        for (int i = m - 2; i >= 1; i--)
            cout << matrix[i][0] << " ";
    }
}
void MatrixTranspose(int **matrix, int m, int n, int mode)
{
    if (mode <= 0)
    {
        // naive approach
        int temp[m][n];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                temp[i][j] = matrix[j][i];
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; i < n; j++)
            {
                temp[i][j] = matrix[i][j];
            }
            cout << "\n";
        }
    }
    else
    {
        // better approach
        for (int i = 0; i < m; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    out_matrix_fun(matrix, m, n);
    cout << "\n";
}
void solve()
{
}

int32_t main()
{
#ifdef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    solve();

#ifdef ONLINE_JUDGE
    cerr << "Time: " << duration.count() / 1000 << endl;
#endif
}