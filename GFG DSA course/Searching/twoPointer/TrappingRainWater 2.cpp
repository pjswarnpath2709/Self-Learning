#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define mset multiset
#define uset unordered_set
#define umap unordered_map
#define vi vector<int>
#define vll vector<long long>
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
int trappingRainWater2pointer(vll &vec)
{
    int n = vec.size();
    int low = 0;
    int high = n - 1;
    int leftMax = 0;
    int rightMax = 0;
    int res = 0;
    while (low <= high)
    {
        if (vec[low] <= vec[high])
        {
            if (vec[low] >= leftMax)
            {
                leftMax = vec[low];
            }
            else
            {
                res += leftMax - vec[low];
            }
            low++;
        }
        else
        {
            if (vec[high] >= rightMax)
            {
                rightMax = vec[high];
            }
            else
            {
                res += rightMax - vec[high];
            }
            high--;
        }
    }
    return res;
}
int main()
{
    ll n;
    cin >> n;
    vll vec(n);
    in_vector(vec, n);
    cout<<trappingRainWater2pointer(vec)<<"\n";

    return 0;
}