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
vector<vi> fourSum(vi &vec, int target)
{
    vector<vi> res;
    if (vec.empty())
    {
        return res;
    }
    // sort the vector
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size() - 3; i++)
    {
        for (int j = i + 1; j < vec.size() - 2; j++)
        {
            int l = j + 1;
            int find_sum = target - vec[i] - vec[j];
            int r = vec.size() - 1;
            // two sum -- twopointer approach
            while (l < r)
            {
                int sum = vec[l] + vec[r];
                if (sum > find_sum)
                {
                    r--;
                }
                else if (sum < find_sum)
                {
                    l++;
                }
                else
                {
                    vi quad(4, 0);
                    quad[0] = vec[i];
                    quad[1] = vec[j];
                    quad[2] = vec[l];
                    quad[3] = vec[r];
                    res.push_back(quad);
                    // processing the duplicates of quad[2]
                    while (l < r && vec[l] == quad[2])
                        ++l;
                    //  processing the duplicates of quad[3]
                    while (l < r && vec[r] == quad[3])
                        --r;
                }
            }
            // processing the duplicates of j
            while (j < vec.size() - 2 && vec[j] == vec[j + 1])
                ++j;
        }
        // processing the duplicates of i
        while (i < vec.size() - 3 && vec[i] == vec[i + 1])
            ++i;
    }
    return res;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi vec(n);
        in_vector(vec, n);
        int target;
        cin >> target;
        vector<vi> ans = fourSum(vec, target);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}