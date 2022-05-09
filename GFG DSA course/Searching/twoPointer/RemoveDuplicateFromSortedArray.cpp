#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define mset multiset
#define uset unordered_set
#define umap unordered_map
#define vi vector<int>
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
int removeDuplicates(vi &vec)
{
    if (vec.size() == 1 || vec.size() == 0)
    {
        return vec.size();
    }
    int prev = 0;
    for (int str = 1; str < vec.size(); str++)
    {
        if (vec[str] != vec[prev])
        {
            prev++;
            vec[prev] = vec[str];
        }
    }

    return prev + 1;
}
int main()
{
    int n;
    cin >> n;
    vi vec(n);
    in_vector(vec, n);
    cout << removeDuplicates(vec) << "\n";
    return 0;
}