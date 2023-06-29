#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution
{
    vector<int> arr;
    int n;
    int sum;

public:
    bool help(int ind, int target)
    {
        if (target == 0)
            return true;
        if (ind == 0)
            return (arr[0] == target);
        bool noTake = help(ind - 1, target);
        bool take = false;
        if (target >= arr[ind])
            take = help(ind - 1, target - arr[ind]);
        return (take || noTake);
    }
    bool recHelp()
    {
        return help(n - 1, sum);
    }
    bool helpMemo(int ind, int target, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;
        if (ind == 0)
            return (arr[0] == target);
        if (dp[ind][target] != -1)
            return (dp[ind][target] == 1);
        bool noTake = helpMemo(ind - 1, target, dp);
        bool take = false;
        if (target >= arr[ind])
            take = helpMemo(ind - 1, target - arr[ind], dp);
        dp[ind][target] = (take || noTake) ? 1 : 0;
        return (take || noTake);
    }
    int memoisation()
    {
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return helpMemo(n - 1, sum, dp);
    }
    int tabulation()
    {
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        // base cases
        for (int i = 0; i < n; i++)
            dp[i][0] = true;
        if (arr[0] <= sum)
            dp[0][arr[0]] = true;
        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 0; target <= sum; target++)
            {
                bool noTake = dp[ind - 1][target];
                bool take = false;
                if (target >= arr[ind])
                    take = dp[ind - 1][target - arr[ind]];
                dp[ind][target] = (take | noTake);
            }
        }
        return dp[n - 1][sum];
    }
    int spaceOptimisation()
    {
        vector<bool> prev(sum + 1, false), cur(sum + 1, false);
        prev[0] = true;
        if (arr[0] <= sum)
            prev[arr[0]] = true;
        for (int ind = 1; ind < n; ind++)
        {
            cur[0] = true;
            for (int target = 0; target <= sum; target++)
            {
                bool noTake = prev[target];
                bool take = false;
                if (target >= arr[ind])
                    take = prev[target - arr[ind]];
                cur[target] = (take | noTake);
            }
            prev = cur;
        }
        return prev[sum];
    }
    bool isSubsetSum(vector<int> vec, int sum)
    {
        this->arr = vec;
        this->n = vec.size();
        this->sum = sum;
        // return recHelp();
        // return memoisation();
        // return tabulation();
        return spaceOptimisation();
    }
};

int main()
{
    int n, target;
    cin >> n;
    vi vec(n, 0);
    for (auto &it : vec)
        cin >> it;
    cin >> target;
    Solution obj;
    string ans = obj.isSubsetSum(vec, target) ? "yes" : "no";
    cout << ans << "\n";
}