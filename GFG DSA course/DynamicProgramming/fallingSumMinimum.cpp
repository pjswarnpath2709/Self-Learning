#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> grid;
    int n;

public:
    int help(int row, int col, vector<vector<int>> &dp)
    {
        if (col >= n || col < 0)
            return 1e6;
        if (row == 0)
            return grid[row][col];
        if (dp[row][col] != -1)
            return dp[row][col];
        int up = grid[row][col] + help(row - 1, col, dp);
        int ld = grid[row][col] + help(row - 1, col - 1, dp);
        int rd = grid[row][col] + help(row - 1, col + 1, dp);
        return dp[row][col] = min(up, min(ld, rd));
    }
    int memoisation()
    {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = 1e6;
        for (int i = 0; i < n; i++)
        {
            ans = min(help(n - 1, i, dp), ans);
        }
        return ans;
    }
    int tabulation()
    {
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            dp[0][i] = grid[0][i];
        }
        for (int row = 1; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                int up = grid[row][col], ld = grid[row][col], rd = grid[row][col];
                up += dp[row - 1][col];
                if (col >= 1)
                    ld += dp[row - 1][col - 1];
                else
                    ld += 1e6;
                if (col+1 < n)
                    rd += dp[row - 1][col + 1];
                else
                    rd += 1e6;
                dp[row][col] = min(up, min(ld, rd));
            }
        }
        int ans = 1e6;
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, dp[n - 1][i]);
        }
        return ans;
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        this->grid = matrix;
        this->n = matrix.size();
        return tabulation();
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
    cout << obj.minFallingPathSum(grid) << "\n";
}