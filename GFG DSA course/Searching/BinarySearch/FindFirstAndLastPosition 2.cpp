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
int getLeftMostOccurance(vi vec, int target, int low, int high)
{
    if (low > high)
    {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (vec[mid] == target && (mid == 0 || vec[mid - 1] != target))
    {
        return mid;
    }
    // move left if the target is smaller or equal to the current mid
    if (vec[mid] >= target)
    {
        return getLeftMostOccurance(vec, target, low, mid - 1);
    }
    else
    {
        return getLeftMostOccurance(vec, target, mid + 1, high);
    }
}
int getRightMostOccurance(vi vec, int target, int low, int high)
{
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (vec[mid] == target && (mid == vec.size() - 1 || vec[mid + 1] != target))
    {
        return mid;
    }
    // move right if target is greater than value at mid
    if (vec[mid] <= target)
    {
        return getRightMostOccurance(vec, target, mid + 1, high);
    }
    else
    {
        return getRightMostOccurance(vec, target, low, mid - 1);
    }
}

vi searchRange(vi &vec, int target)
{
    vi veci(2);
    veci[0] = getLeftMostOccurance(vec, target, 0, vec.size() - 1);
    veci[1] = getRightMostOccurance(vec, target, 0, vec.size() - 1);
    return veci;
}
int main()
{
    int n, value;
    cin >> n >> value;
    // cout << n << value << "\n";
    vi vec(n);
    in_vector(vec, n);
    vi veci = searchRange(vec, value);
    cout << veci[0] << " " << veci[1] << "\n";

    return 0;
}