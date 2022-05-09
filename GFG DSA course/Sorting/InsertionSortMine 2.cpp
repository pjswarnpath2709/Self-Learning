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
void insertionSort(vll &vec, int n)
{
    int cut = 1;
    while (cut <= n)
    {
        int j = cut;
        while (j - 1 >= 0 && vec[j] < vec[j - 1])
        {
            swap(vec[j - 1], vec[j]); //just swap till it's not equal or greater
            j--;
        }
        cut++; //increae the cut size as j is also added
    }
}
int main()
{
    ll n;
    cin >> n;
    vll vec(n);
    in_vector(vec, n);
    insertionSort(vec, n);
    printVec(vec);
    return 0;
}