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
int FindLeftMostPosition(vll vec, ll target)
{

    int ans = -1;
    int low = 0, high = vec.size() - 1;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (vec[mid] == target && (vec[mid] != vec[mid - 1] || mid == 0))
        {
            ans = mid;
            // return mid;
        }
        // if the target is smaller or equal to the target move left
        if (vec[mid] >= target)
        {
            // move left
            high = mid - 1;
        }
        else
        {
            // move rigth
            low = mid + 1;
        }
    }
    return ans;
}
int FindRightMostPosition(vll vec, ll target)
{
    ll ans = -1;
    ll low = 0, high = vec.size() - 1;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (vec[mid] == target && (vec[mid] != vec[mid + 1] || mid == vec.size() - 1))
        {
            ans = mid;
        }
        if (target >= vec[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
int main()
{
    ll n, target;
    cin >> n >> target;
    vll vec(n);
    in_vector(vec, n);
    cout << FindLeftMostPosition(vec, target) << " " << FindRightMostPosition(vec, target) << "\n";

    return 0;
}