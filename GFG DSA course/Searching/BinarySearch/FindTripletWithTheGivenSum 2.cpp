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
void tripletwithGivenSum(vll &vec, int n, int sum)
{
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++)
    {
        // checking for the duplicates of i
        if (i == 0 || (i > 0 && vec[i] != vec[i - 1]))
        {
            int target = sum - vec[i];
            int low = i + 1;
            int high = n - 1;
            while (low < high)
            {
                while (vec[high] == vec[high - 1])
                {
                    high--;
                }
                while (vec[low] == vec[low + 1])
                {
                    low++;
                }
                if (vec[low] + vec[high] == target)
                {
                    cout << vec[i] << " " << vec[low] << " " << vec[high] << "\n";
                }
                if (vec[low] + vec[high] > target)
                {

                    high--;
                }
                else
                {

                    low++;
                }
            }
        }
    }
}
int main()
{
    ll n, sum;
    cin >> n >> sum;
    vll vec(n);
    in_vector(vec, n);
    tripletwithGivenSum(vec, n, sum);
    return 0;
}