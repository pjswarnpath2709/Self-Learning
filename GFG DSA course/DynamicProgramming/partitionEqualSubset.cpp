#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution
{
public:
    bool subsetSum(int n, vector<int> &arr, int k)
    {
        vector<bool> prev(k + 1, false), cur(k + 1, false);
        prev[0] = cur[0] = true;
        if (arr[0] <= k)
            prev[arr[0]] = true;
        for (int ind = 1; ind < n; ind++)
        {
            cur[0] = true;
            for (int target = 0; target <= k; target++)
            {
                bool noTake = prev[target];
                bool take = false;
                if (arr[ind] <= target)
                    take = prev[target - arr[ind]];
                cur[target] = (take | noTake);
            }
            prev = cur;
        }
        return prev[k];
    }
    int equalPartition(vector<int> &vec)
    {
        int totalSum = accumulate(vec.begin(), vec.end(), 0);
        if (totalSum & 1 == 1)
            return false;
        int target = totalSum >> 1;
        return subsetSum(vec.size(), vec, target);
    }
};

int main()
{
    int n;
    cin >> n;
    vi vec(n, 0);
    for (auto &it : vec)
        cin >> it;
    Solution obj;
    string ans = obj.equalPartition(vec) ? "yes" : "no";
    cout << ans << "\n";
}