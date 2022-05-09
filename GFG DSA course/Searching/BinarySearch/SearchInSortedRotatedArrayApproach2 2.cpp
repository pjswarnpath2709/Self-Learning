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
int search(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size()-1;
    while (low <= high)
    {
        int mid = (low+high)>>1;
        if (nums[mid] == target)
        {
            return mid;
        }
        // chk which part is sorted
        else if (nums[low] <= nums[mid])
        {
            // if this is sorted chk if target lie in this range
            if (nums[low] <= target &&  nums[mid] > target)
            {
                high = mid - 1;
            }
            // the target will definetly lie  in the next side
            else
            {
                low = mid + 1;
            }
        }
        // second array must be sorted
        else if (nums[mid] <= nums[high])
        {
            // if this is sorted chk if target lie in this range
            if (target > nums[mid] && target <= nums[high])
            {
                low = mid + 1;
            }
            // the target will definetly lie in the next side
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}
int main()
{
    int n, target;
    cin >> n >> target;
    vi vec(n);
    in_vector(vec, n);
    cout << search(vec, target) << "\n";

    return 0;
}