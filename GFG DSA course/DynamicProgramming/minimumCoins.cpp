#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> coins;
    int n;
    int amount;

public:
    int help(int ind, int target)
    {
        if (ind == 0)
        {
            if (target % coins[0] != 0)
                return 1e9;
            else
                return target / coins[0];
        }
        int notTake = 0 + help(ind - 1, target);
        int take = 1e9;
        if (coins[ind] <= target)
        {
            take = 1 + help(ind, target - coins[ind]);
        }
        return min(take, notTake);
    }
    int recHelp()
    {
        return help(n - 1, amount);
    }
    int helpMemo(int ind, int target, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (target % coins[0] != 0)
                return 1e9;
            else
                return target / coins[0];
        }
        if (dp[ind][target] != -1)
            return dp[ind][target];
        int notTake = 0 + help(ind - 1, target);
        int take = 1e9;
        if (coins[ind] <= target)
        {
            take = 1 + help(ind, target - coins[ind]);
        }

        return dp[ind][target] = min(take, notTake);
    }
    int memoisation()
    {
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return helpMemo(n - 1, amount, dp);
    }
    int tabulation()
    {
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        // base case
        for (int target = 0; target <= amount; target++)
        {
            if (target % coins[0] == 0)
                dp[0][target] = target / coins[0];
            else
                dp[0][target] = 1e9;
        }
        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 0; target <= amount; target++)
            {
                int notTake = 0 + dp[ind - 1][target];
                int take = 1e9;
                if (coins[ind] <= target)
                {
                    take = 1 + dp[ind][target - coins[ind]];
                }
                dp[ind][target] = min(take, notTake);
            }
        }
        return dp[n - 1][amount];
    }
    int coinChange(vector<int> &coins, int amount)
    {
        this->coins = coins;
        this->amount = amount;
        this->n = coins.size();
        return tabulation();
        // return memoisation();
        // return recHelp();
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> coins(n, 0);
    for (auto &it : coins)
        cin >> it;
    int amount;
    cin >> amount;

    Solution obj;
    cout << obj.coinChange(coins, amount) << "\n";
}

/*
12
411 412 413 414 415 416 417 418 419 420 421 422
9864
*/