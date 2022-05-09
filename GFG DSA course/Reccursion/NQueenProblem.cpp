/*-------------------------------------------------------------------------------------------------------------*/
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
/*-------------------------------------------------------------------------------------------------------------*/
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
/*-------------------------------------------------------------------------------------------------------------*/
void solve(int col, vs &board, vector<vs> &ans, vi &leftRow, vi &upperDaig, vi &lowerDaig, int n)
{
    if (col == n)
    {
        ans.pb(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (leftRow[row] == 0 && upperDaig[n - 1 + (col - row)] == 0 && lowerDaig[col + row] == 0)
        {
            // setting the queen
            board[row][col] = 'Q';
            lowerDaig[row + col] = 1;
            upperDaig[n - 1 + (col - row)] = 1;
            leftRow[row] = 1;

            // recurrsion call
            solve(col + 1, board, ans, leftRow, upperDaig, lowerDaig, n);

            // unsetting the queen
            board[row][col] = '.';
            lowerDaig[row + col] = 0;
            upperDaig[n - 1 + (col - row)] = 0;
            leftRow[row] = 0;
        }
    }
}
vector<vs> solveNQueenOuter(int n)
{
    vector<vs> ans;
    string str(n, '.');
    vs board(n);
    for (int i = 0; i < n; i++)
    {
        board[i] = str;
    }
    vi leftRow(n, 0);
    vi upperDaig(2 * n - 1, 0);
    vi lowerDaig(2 * n - 1, 0);
    solve(0, board, ans, leftRow, upperDaig, lowerDaig, n);
    return ans;
}
/*-------------------------------------------------------------------------------------------------------------*/
int main()
{
    ll n;
    cin >> n;
    vll vec(n);
    in_vector(vec, n);

    return 0;
}
/*-------------------------------------------------------------------------------------------------------------*/