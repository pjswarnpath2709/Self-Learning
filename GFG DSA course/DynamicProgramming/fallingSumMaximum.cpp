#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> grid;
    int n;

public:
    int help(int row, int col)
    {
        if (col < 0 || col >= n)
            return -1e9;
        if (row == 0)
        {
            return grid[row][col];
        }
        int up = help(row - 1, col);
        int ld = help(row - 1, col - 1);
        int rd = help(row - 1, col + 1);
        return grid[row][col] + max(up, max(ld, rd));
    }
    int recHelp()
    {
        int ans = -1e9;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, help(n - 1, i));
        }
        return ans;
    }
    int helpMemo(int row, int col, vector<vector<int>> &dp)
    {
        if (col < 0 || col >= n)
            return -1e9;
        if (row == 0)
        {
            return grid[row][col];
        }
        if (dp[row][col] != -1)
            return dp[row][col];
        int up = helpMemo(row - 1, col, dp);
        int ld = helpMemo(row - 1, col - 1, dp);
        int rd = helpMemo(row - 1, col + 1, dp);
        return dp[row][col] = grid[row][col] + max(up, max(ld, rd));
    }
    int memoisation()
    {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = -1e9;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, helpMemo(n - 1, i, dp));
        }
        return ans;
    }
    int tabulation()
    {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            dp[0][i] = grid[0][i];
        }
        for (int row = 1; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                int up = dp[row - 1][col];
                int ld = (col < 0) ? -1e9 : dp[row - 1][col - 1];
                int rd = (col >= n) ? -1e9 : dp[row - 1][col + 1];
                dp[row][col] = grid[row][col] + max(up, max(ld, rd));
            }
        }
        int ans = -1e9;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, dp[n - 1][i]);
        }
        return ans;
    }
    int spaceOptimisation()
    {
        vector<int> prev(n, -1);
        for (int i = 0; i < n; i++)
        {
            prev[i] = grid[0][i];
        }
        for (int row = 1; row < n; row++)
        {
            vector<int> cur(n, 0);
            for (int col = 0; col < n; col++)
            {
                int up = prev[col];
                int ld = (col < 0) ? -1e9 : prev[col - 1];
                int rd = (col >= n) ? -1e9 : prev[col + 1];
                cur[col] = grid[row][col] + max(up, max(ld, rd));
            }
            prev = cur;
        }
        int ans = -1e9;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, prev[i]);
        }
        return ans;
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        grid = Matrix;
        n = N;
        // return recHelp();
        // return memoisation();
        // return tabulation();
        return spaceOptimisation();
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, -1));
    for (auto &li : grid)
        for (auto &it : li)
            cin >> it;
    Solution obj;
    cout << obj.maximumPath(n, grid) << "\n";
}