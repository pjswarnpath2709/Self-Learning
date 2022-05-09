#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<long long>
#define vc vector<char>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <class T>
void in_vector(vector<T> &vec, ll n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
}
// we consider the greatest element as the opivot
int getThePivotaIndex(vi &vec, int low, int high)
{
    if (low > high)
    {
        return -1;
    }
    int left_mostElement = vec[0];
    int mid = (high + low) >> 1;
    if (vec[mid] > vec[mid + 1])
    {
        return mid;
    }
    else
    {
        // search in the right array
        if (left_mostElement > vec[mid])
        {
            // search in the left part
            return getThePivotaIndex(vec, low, mid - 1);
        }
        // search in the left array
        else
        {
            return getThePivotaIndex(vec, mid + 1, high);
        }
    }
}
// then simply do the Binarysearch in the array from either low to pivot or pivot to high
int SimpleBinarySearch(vi &vec, int low, int high, int value)
{
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (vec[mid] == value)
        {
            return mid;
        }
        if (vec[mid] > value)
        {
            // move to left
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
int search(vector<int> &nums, int target)
{
    int pivot = getThePivotaIndex(nums, 0, nums.size() - 1);
    int targetIndex = SimpleBinarySearch(nums, 0, pivot, target);
    int taregtIndex2 = SimpleBinarySearch(nums, pivot, nums.size() - 1, target);
    int ans = max(targetIndex, taregtIndex2);
    return ans;
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