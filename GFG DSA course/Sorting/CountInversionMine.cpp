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
int mergeit(vll &vec, int low, int mid, int high)
{
    // phase size
    int n1 = mid - low + 1;
    int n2 = high - mid;
    // phase copy
    vll left(n1), right(n2);
    for (int i = 0; i < n1; i++)
        left[i] = vec[i + low];
    for (int j = 0; j < n2; j++)
        right[j] = vec[mid + 1 + j];
    // phase decision
    int i = 0, j = 0, k = low; //yaha dhyan rakhna hain
    int res = 0;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            vec[k++] = left[i++];
        }
        else
        {
            // if inversion occurs for i then offcourse it will occur for evry i,i+1,i+2....n1-1
            vec[k++] = right[j++];
            res += (n1 - i);
        }
    }
    while (i < n1)
        vec[k++] = left[i++];
    while (j < n2)
        vec[k++] = right[j++];

    // memory free phase
    left.clear();
    right.clear();
    // return phase
    return res;
}
int mergeSort(vll &vec, int low, int high)
{
    int ans = 0;
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        ans += mergeSort(vec, low, mid);
        ans += mergeSort(vec, mid + 1, high);
        ans += mergeit(vec, low, mid, high);
    }
    return ans;
}
int main()
{
    ll n;
    cin >> n;
    vll vec(n);
    in_vector(vec, n);
    cout << mergeSort(vec, 0, n - 1);

    return 0;
}