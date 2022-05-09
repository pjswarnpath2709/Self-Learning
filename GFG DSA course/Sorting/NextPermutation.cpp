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
void nextPermutation(vi &vec)
{
    int k = -1;
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        if (vec[i + 1] > vec[i])
        {
            i = k;
            break;
        }
    }
    if (k < 0)
    {
        reverse(vec.begin(), vec.end());
    }
    else
    {
        int l = vec.size() - 1;
        for (; l > k; l--)
        {
            if (vec[l] > vec[k])
            {
                break;
            }
        }
        swap(vec[l], vec[k]);
        reverse(vec.begin() + k + 1, vec.end());
    }
}
int main()
{
    ll n;
    cin >> n;
    vll vec(n);
    in_vector(vec, n);

    return 0;
}