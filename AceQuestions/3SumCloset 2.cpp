#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define mset multiset
#define uset unordered_set
#define umap unordered_map
#define vi vector<int>
#define vll vector<long long>
#define all_vec vec.begin(), vec.end()
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
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
void in_vector(vector<T> &vec, ll n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
}

int threeSumClosest(vll &vec, int target)
{
    int n = vec.size();
    sort(all_vec);
    int ans = INT32_MAX;
    for (int i = 0; i < n - 2; i++)
    {
        if (i == 0 || (i > 0 && vec[i] != vec[i + 1]))
        {
            int k = i + 1;
            int j = n - 1;
            while (k < j)
            {
                while (vec[k] == vec[k + 1])
                {
                    k++;
                }
                while (vec[j] == vec[j - 1])
                {
                    j--;
                }
                int sum = vec[i] + vec[k] + vec[j];
                if (sum > target)
                {
                    if (abs(sum - target) < abs(target - ans))
                    {
                        ans = sum;
                    }
                    j--;
                }
                else if (sum < target)
                {

                    if (abs(sum - target) < abs(ans - target))
                    {
                        ans = sum;
                    }
                    k++;
                }
                else
                {
                    return target;
                }
            }
        }
    }
    return ans;
}
int main()
{
    ll n;
    cin >> n;
    vll vec(n);
    in_vector(vec, n);
    int target;
    cin >> target;
    cout << threeSumClosest(vec, target) << "\n";

    return 0;
}