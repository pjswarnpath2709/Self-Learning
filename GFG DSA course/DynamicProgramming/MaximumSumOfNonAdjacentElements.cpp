#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << "\n";

class Solution
{
public:
    vector<int> arr;
    int n;
    int help(int ind, vector<int> &dp)
    {
        if (ind == 0)
            return arr[ind];
        if (ind < 0)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int pick = arr[ind] + help(ind - 2, dp);
        int notPick = help(ind - 1, dp);
        return dp[ind] = max(pick, notPick);
    }
    int findMaxSum(vector<int> &arr, int n)
    {
        this->arr = arr;
        this->n = n;
        vector<int> dp(n, -1);
        // help(ind) represent sum of subsequence from 0 to ind not including adjacent elements
        // now if we pick the element ans = arr[ind] + help(ind-2)
        // if we don't pick the element ans = 0 + help(ind-1)
        return help(n - 1, dp);
    }
    int tabulation(vector<int> &arr, int n)
    {
        vector<int> dp(n, 0);
        dp[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            int take = arr[i];
            if (i > 1)
                take += dp[i - 2];
            int noTake = 0 + dp[i - 1];
            dp[i] = max(take, noTake);
        }
        return dp[n - 1];
    }
    int spaceOptimization(vector<int> &arr, int n)
    {
        int prev = arr[0];
        int prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int take = arr[i];
            if (i > 1)
                take += prev2;
            int notTake = 0 + prev;
            int curi = max(take, notTake);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n, -1);
    for (auto &it : vec)
        cin >> it;
    Solution obj;
    cout << obj.findMaxSum(vec, n) << "\n";
}