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
// there are solutions to this problem the first is with higher complexity O(N*N)
int stockBuyAndSellRecursive(int arr[], int startidx, int endidx)
{
    int profit = 0;
    if (startidx < endidx)
    {
        for (int i = startidx; i < endidx; i++)
        {
            for (int j = i + 1; j <= endidx; j++)
            {
                int curr_profit = arr[j] - arr[i];
                curr_profit += stockBuyAndSellRecursive(arr, startidx, i - 1); // usse phele ka profit kyta raha hoga
                curr_profit += stockBuyAndSellRecursive(arr, j + 1, endidx);   // uuse baad ka profit kya raha hoga
                profit = max(profit, curr_profit);                             // return the maximum profit
            }
        }
    }
    return profit;
}
// second is with lower complexity O(N)
int stockBuyAndSell(int arr[], int n)
{
    //imagine the values of the arrays as a graph, and then think of an O(N) solution
    //dip aate hi stock buy karna hain then peek aate hi sell karna hain
    int profit=0;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1]){
            profit+=arr[i]-arr[i-1];
        }
    }
    return profit;
}
int main()
{
    ll n;
    cin >> n;
    vll vec(n);
    in_vector(vec, n);

    return 0;
}