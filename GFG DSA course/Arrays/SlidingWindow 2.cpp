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
// sliding window technique is used to reduce the repetive work
// question 1 is to simply find the maximum of the sum of consequestive k elements
/*
in this the window size will be k

we have to increment j till we hit the window size i.e. j+i-1==k
after hitting the window size we simply has to slide the window but before sliding we have to remove
the calculaions of the previous element

*/
int maxSum_in_Window_of_K(vi &vec, int k)
{
    int j = 0;
    int i = 0;
    int sum = 0;
    int maxi = -1;
    int n = vec.size();
    while (j < n)
    {
        sum += vec[j];
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            maxi = max(maxi, sum);
            sum -= vec[i++];
            j++;
        }
    }
    return maxi;
}
// second question is that an number is given if the sum of any Subarray is equal to that number
// print yes other wise print no
/*
given an array of non negative integers we have to print if it consists any subarray with the sum given to
that number
*/
int sizeOfsubarraywithrequiredSum(vi &vec, int sum)
{
    int n = vec.size();
    int j = 0, i = 0;
    int count = 0;
    int current_sum = 0;
    while (j < n)
    {
        if (current_sum < sum)
        {
            current_sum += vec[j];
            j++;
        }
        else if (current_sum == sum)
        {
            count++;
            j++;
        }
        else
        {
            while (current_sum > sum && i < j)
            {
                current_sum -= vec[i++];
            }
        }
    }
    return count;
}
void solve()
{
    int n;
    cin >> n;
    vi vec(n);
    in_vector(vec, n);
    int k;
    cin >> k;
    cout << maxSum_in_Window_of_K(vec, k) << "\n";
    int kt;
    cin >> kt;
    vi vec2(kt);
    in_vector(vec2, kt);
    int sum;
    cin >> sum;
    if (sizeOfsubarraywithrequiredSum(vec, sum) > 0)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}
/*------------------------------------------------------------------------------------------------------------------------*/
int main()
{
    fastio();
    solve();
    return 0;
}