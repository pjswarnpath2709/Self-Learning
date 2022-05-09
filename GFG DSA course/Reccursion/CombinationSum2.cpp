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
// brute force approach
// set<vi> ans;
// void printCombSum(int idx, int sumToform, int arr[], int n, vi vec)
// {
//     if (idx == n)
//     {
//         if (sumToform == 0)
//         {
//             sort(vec.begin(), vec.end());
//             ans.insert(vec);
//         }
//         return;
//     }
//     if (sumToform < 0)
//     {
//         return;
//     }
//     // lets consider the element
//     vec.pb(arr[idx]);
//     printCombSum(idx + 1, sumToform - arr[idx], arr, n, vec);
//     // lets not consider the element
//     vec.ppb();
//     printCombSum(idx + 1, sumToform, arr, n, vec);
// }
// optimised approach

void findCombination(int ind, int target, vi &arr, vector<vi> &ans, vi &ds)
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }
    for (int i = ind; i < arr.size(); i++)
    {
        if (i > ind && arr[i] == arr[i - 1])
            continue;
        if (arr[i] > target)
            break;
        ds.push_back(arr[i]);
        findCombination(i + 1, target - arr[i], arr, ans, ds);
        ds.pop_back();
    }
}
vector<vi> combinationSum2(vi &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vi> ans;
    vi ds;
    findCombination(0, target, candidates, ans, ds);
    return ans;
}

int main()
{
    int n, target;
    cin >> n >> target;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vi vecTo(n);
    for (int i = 0; i < n; i++)
    {
        vecTo[i] = arr[i];
    }
    // printVec(vecTo);
    // vi vec;
    // printCombSum(0, target, arr, n, vec);
    // for (auto i : ans)
    // {
    //     for (int j = 0; j < i.size(); j++)
    //     {
    //         cout << i[j] << " ";
    //     }
    //     cout << "\n";
    // }

    // optimised approach
    vector<vi> ans = combinationSum2(vecTo, target);
    // printVec(vecTo);
    for (int i = 0; i < ans.size(); i++)
    {
        printVec(ans[i]);
    }
    return 0;
}