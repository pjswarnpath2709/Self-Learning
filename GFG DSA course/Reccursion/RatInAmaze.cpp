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
void solve(int i, int j, vector<vi> &a, int n, vs &ans, string move, vector<vi> &vis, int di[], int dj[])
{
    if (i == n - 1 && j == n - 1)
    {
        ans.pb(move);
        return;
    }
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(move);
        return;
    }
    string dir = "DLRU";
    for (int ind = 0; ind < 4; ind++)
    {
        int nexti = i + di[ind];
        int nextj = j + dj[ind];
        if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1)
        {
            vis[i][j] = 1;
            solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);
            vis[i][j] = 0;
        }
    }
    // // move down
    // if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1)
    // {
    //     vis[i][j] = 1;
    //     solve(i + 1, j, n, move + "D", ans, vis, a);
    //     vis[i][j] = 0;
    // }
    // // move left
    // if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1)
    // {
    //     vis[i][j] = 1;
    //     solve(i, j - 1, n, move + "L", ans, vis, a);
    //     vis[i][j] = 0;
    // }
    // // move right
    // if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1)
    // {
    //     vis[i][j] = 1;
    //     solve(i, j + 1, n, move + "L", ans, vis, a);
    //     vis[i][j] = 0;
    // }
    // // move up
    // if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1)
    // {
    //     vis[i][j] = 1;
    //     solve(i - 1, j, n, move + "L", ans, vis, a);
    //     vis[i][j] = 0;
    // }
}
vs findPath(vector<vi> &m, int n)
{
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    int di[] = {+1, 0, 0, -1};
    int dj[] = {0, -1, 1, 0};
    if (m[0][0] == 1)
        solve(0, 0, m, n, ans, "", vis, di, dj);
    return ans;
}
int main()
{
    ll n;
    cin >> n;
    vll vec(n);
    in_vector(vec, n);

    return 0;
}