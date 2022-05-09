#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<long long>
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
ll getPeakElement(vi vec, int low, int high)
{
    int mid = (low + high) >> 1;
    if ((vec[mid] > vec[mid + 1] && vec[mid] > vec[mid - 1]) || (mid == 0 && vec[mid] > vec[mid + 1]) || (mid == vec.size() && vec[mid] > vec[mid - 1]))
    {
        return mid;
    }
    else if (vec[mid + 1] > vec[mid])
    {
        return getPeakElement(vec, mid + 1, high);
    }
    else
    {
        return getPeakElement(vec, low, mid - 1);
    }
}
int findPeakElement(vector<int> &vec)
{
    int low = 0;
    int high = vec.size() - 1;
    while (low < high)
    {
        int mid = (high + low) >> 1;
        if (vec[mid] > vec[mid + 1])
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
int main()
{
    int n;
    cin >> n;
    vi vec(n);
    in_vector(vec, n);
    cout << findPeakElement(vec) << "\n";

    return 0;
}