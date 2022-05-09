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
    for (auto &i : vec)
    {
        cout << i << " ";
    }
    cout << "\n";
}
/*--------------------------------------------------------------------------------------------------------------------------------*/
bool KsubsequencesOneAnswer(int idx, int arr[], vi &vec, int sum, int n, int k)
{
    if (idx >= n)
    {
        // condition satisfied
        if (sum == k)
        {
            printVec(vec);
            return true;
        }
        // condition not satisfied
        return false;
    }
    // take the idx element
    vec.pb(arr[idx]);
    sum = sum + arr[idx];
    // chk if this answer is satisfiing the condition
    if (KsubsequencesOneAnswer(idx + 1, arr, vec, sum, n, k))
    {
        // simply return na why to go further
        return true;
    }
    // not take  the elemeny
    sum = sum - arr[idx];
    vec.ppb();
    if (KsubsequencesOneAnswer(idx + 1, arr, vec, sum, n, k))
    {
        return true;
    }
    return false;
}
/*-------------------------------------------------------------------------------------------------------------------------------*/

int main()
{
    int k = 2;
    int sum = 0;
    int n = 3;
    int arr[] = {1, 2, 1};
    vi vec;
    bool ans = KsubsequencesOneAnswer(0, arr, vec, sum, n, k);
    return 0;
}