#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int *wt;
    int *val;
    int capacity;
    int n;

public:
    int help(int ind, int W)
    {
        if (ind == 0)
        {
            if (wt[0] <= W)
                return val[0];
            else
                return 0;
        }
        int noTake = 0 + help(ind - 1, W);
        int take = -1e9;
        if (wt[ind] <= W)
        {
            take = val[ind] + help(ind - 1, W - wt[ind]);
        }
        return max(noTake, take);
    }
    int recHelp()
    {
        return help(n - 1, capacity);
    }
    int helpMemo(int ind, int W, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (wt[0] <= W)
                return val[0];
            else
                return 0;
        }
        if (dp[ind][W] != -1)
            return dp[ind][W];
        int noTake = 0 + helpMemo(ind - 1, W, dp);
        int take = -1e9;
        if (wt[ind] <= W)
        {
            take = val[ind] + helpMemo(ind - 1, W - wt[ind], dp);
        }
        return dp[ind][W] = max(noTake, take);
    }
    int memoisation()
    {
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
        return helpMemo(n - 1, capacity, dp);
    }
    int tabulation()
    {
        vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
        // base cases
        for (int W = wt[0]; W <= capacity; W++)
        {
            dp[0][W] = val[0];
        }
        for (int ind = 1; ind < n; ind++)
        {
            for (int W = 0; W <= capacity; W++)
            {
                int noTake = 0 + dp[ind - 1][W];
                int take = -1e9;
                if (wt[ind] <= W)
                {
                    take = val[ind] + dp[ind - 1][W - wt[ind]];
                }
                dp[ind][W] = max(noTake, take);
            }
        }
        return dp[n - 1][capacity];
    }
    int spaceOptimisation()
    {
        vector<int> prev(capacity + 1, 0), cur(capacity + 1, 0);
        for (int W = wt[0]; W <= capacity; W++)
        {
            prev[W] = val[0];
        }
        for (int ind = 1; ind < n; ind++)
        {
            for (int W = 0; W <= capacity; W++)
            {
                int noTake = 0 + prev[W];
                int take = -1e9;
                if (wt[ind] <= W)
                {
                    take = val[ind] + prev[W - wt[ind]];
                }
                cur[W] = max(noTake, take);
            }
            prev = cur;
        }
        return prev[capacity];
    }
    int spaceOptimisationOneArray()
    {
        vector<int> prev(capacity + 1, 0);
        for (int W = wt[0]; W <= capacity; W++)
        {
            prev[W] = val[0];
        }
        for (int ind = 1; ind < n; ind++)
        {
            for (int W = capacity; W >= 0; W--)
            {
                int noTake = 0 + prev[W];
                int take = -1e9;
                if (wt[ind] <= W)
                {
                    take = val[ind] + prev[W - wt[ind]];
                }
                prev[W] = max(noTake, take);
            }
        }
        return prev[capacity];
    }
    int knapSack(int W, int wt[], int val[], int n)
    {
        this->wt = wt;
        this->val = val;
        this->capacity = W;
        this->n = n;
        // return recHelp();
        // return memoisation();
        // return tabulation();
        return spaceOptimisationOneArray();
    }
};

int main()
{
    int n;
    vector<int> wt(n, 0);
    vector<int> val(n, 0);
}
