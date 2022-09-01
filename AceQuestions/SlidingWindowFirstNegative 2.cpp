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
    for (T &i : vec)
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
vll FirstNegativeElement(vll &vec, int window_size)
{
    vll ansVec;

    int i = 0;
    int k = window_size;
    int j = 0;
    queue<ll> ls; // the list's front will always store the first negative number
    while (j < vec.size())
    {
        if (vec[j] < 0)
        {
            // if negative add to the list
            ls.push(vec[j]);
        }
        if (j - i + 1 < k)
        {
            j++;
        }
        if (j - i + 1 == k)
        {
            // move window by removing the calculations for i
            if (ls.size() == 0) // the list has no elemnts means the window has no negative element in  it
            {
                ansVec.pb(0);
            }
            else
            {
                // store the first neagtive numver in the list
                ansVec.push_back(ls.front());
                if (ls.front() == vec[i])
                {
                    ls.pop();
                }
            }
            // move th1e window
            i++;
            j++;
        }
    }

    return ansVec;
}
int main()
{
    int n;
    cin >> n;
    vll vec(n);
    in_vector(vec, n);
    int k;
    cin >> k;
    vll ansVec = FirstNegativeElement(vec, k);
    printVec(ansVec);

    return 0;
}