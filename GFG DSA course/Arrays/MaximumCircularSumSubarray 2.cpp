#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define mset multiset
#define uset unordered_set
#define umap unordered_map
#define nline "\n"
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

/*---------------------------------------------------------------------------------------------------------------*/
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
/*------------------------------------------------------------------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }
void _print(bool t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{

    cerr
        << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
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

/*------------------------------------------------------------------------------------------------------------------------*/
// naive approach-->O(n*n)
/*
in this we consider every element as the begining of subarray and find maximum possible sum till
returning to the same location of the subarray circularly, to do this we have used the concept of
moduluar arithmatic
*/
int circularSubarray(vi &vec)
{
    int res = vec[0];
    for (int i = 0; i < vec.size(); i++)
    {
        int curr_max = vec[i];
        int curr_sum = vec[i];
        for (int j = 1; j < vec.size(); j++)
        {
            int index = (i + j) % vec.size();
            curr_sum += vec[index];
            curr_max = max(curr_max, curr_sum);
        }
        res = max(res, curr_max);
    }
    return res;
}
// efficent method-->O(N)
/*
Idea->
take the maximum of these two ->
1.)Normal Maximum sum Subarray(Using kadane's Algo)
2.)Finding the maximum Circular Subarray sum(this can be done by the following manner)

to find the maximum circular sum subtract the minimum possible subarray sum and subtract it from the
sum of whole array e.g.
{5,-2,3,4}  the minimum subarray sum is -2({-2}) ,so we will remove that subarray to form -> {5,3,4}
{8,-4,3,-5,4} the minimum subarray sum is -6({-4,3,-5}) ,so we will remove that subarray to form->{4,8}
{3,-4,5,6,-8,7} the minimum subarray sum is -8({-8}) ,so we will remove that subarray to form->{7,3,-4,5,6}


we are simply finding the minimum subarray sum and than subtracting it from the total sum

MaxCircularSubarraySum = MinCircularSubarraySum + totalSumofArray

*/
int kadaneMaximumSum(vi &vec)
{
    int res = vec[0];
    int previous_maximum_sum = vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        previous_maximum_sum = max(previous_maximum_sum + vec[i], vec[i]);
        res = max(previous_maximum_sum, res);
    }
    return res;
}
// first method to find the minimum subbaray sum
int kadaneMinimumSum(vi &vec)
{
    int res = vec[0];
    int previous_minimum_sum = vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        previous_minimum_sum = min(previous_minimum_sum + vec[i], vec[i]);
        res = min(previous_minimum_sum, res);
    }
    return res;
}
// second method is to simply invert the whole array then find kadaneMax and returning negative of kadaneMax
int kadaneMinEasyMethod(vi vec)
{
    // inverting the array
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i] = -vec[i];
    }
    // finding kadaneMax on this
    int kadaneMax = kadaneMaximumSum(vec);
    return -1 * kadaneMax;
}
int circularSubarrayefficient(vi &vec)
{
    int kadaneMaxSum = kadaneMaximumSum(vec); // check if kadaneMax is negetive or possitve
    // cout << kadaneMaxSum << "\n";
    // if negative simply return it
    if (kadaneMaxSum < 0)
        return kadaneMaxSum;
    // lets find the sum of all the element in the array
    int totalSum = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        totalSum += vec[i];
    }
    // now we will find minimum Sum possible Subarray
    // int kadaneMiniSum = kadaneMinimumSum(vec);
    int kadaneMinSum = kadaneMinEasyMethod(vec);
    // cout << "kadaneMiniSum: " << kadaneMiniSum << "\n";
    // cout << "kadaneMinSum: " << kadaneMinSum << "\n";
    return max(kadaneMaxSum, totalSum - kadaneMinSum);
}
void solve()
{
    int n;
    cin >> n;
    vi vec(n);
    in_vector(vec, n);
    cout << circularSubarray(vec) << "\n";
    cout << circularSubarrayefficient(vec) << "\n";
}

/*------------------------------------------------------------------------------------------------------------------------*/
int main()
{
    fastio();
    solve();
    return 0;
}