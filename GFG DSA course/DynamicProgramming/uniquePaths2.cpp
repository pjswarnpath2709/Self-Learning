#include <bits/stdc++.h>
using namespace std;
class Solution
{
    vector<vector<int>> grid;

public:
    int help(int row, int col)
    {
        if (row == 0 && col == 0)
            return 1;
        // if i can move upward
        if (row < 0 || col < 0)
            return 0;
        if (grid[row][col] == 1)
            return 0;
        int up = help(row - 1, col);
        int left = help(row, col - 1);
        return up + left;
    }
    int helpMemo(int row, int col, vector<vector<int>> &dp)
    {
        if (row == 0 && col == 0)
            return 1;
        // if i can move upward
        if (dp[row][col] != -1)
            return dp[row][col];
        if (row < 0 || col < 0)
            return 0;
        if (grid[row][col] == 1)
            return 0;
        int up = helpMemo(row - 1, col, dp);
        int left = helpMemo(row, col - 1, dp);
        return dp[row][col] = up + left;
    }
    int memoisation(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helpMemo(m - 1, n - 1, dp);
    }
    int tabulation(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[0][0] = 1;
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (row == 0 && col == 0)
                    continue;
                dp[row][col] = 0;
                if (grid[row][col] == 1)
                    continue;
                if (row - 1 >= 0)
                    dp[row][col] += dp[row - 1][col];
                if (col - 1 >= 0)
                    dp[row][col] += dp[row][col - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
    int spaceOptimisation(int m , int n){
        vector<int> prev(n,0);
        for(int row=0;row<m;row++){
            vector<int> temp(n,0);
            for(int col=0;col<n;col++){
                if(row==0 && col==0) temp[col] = 1;
                else{
                    temp[col] = 0;
                    if(grid[row][col]==1) continue;
                    if(row>=1) temp[col]+=prev[col];
                    if(col>=1) temp[col] += temp[col-1];
                }
            }
            prev = temp;
        }
        return prev[n-1];
    }
    int totalWays(int n, int m, vector<vector<int>> &grid)
    {
        if (grid[0][0] == 1)
            return 0;
        this->grid = grid;
        // return help(n - 1, m - 1);
        // return memoisation(n, m);
        return spaceOptimisation(m,n);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, -1));
    for (auto &li : grid)
        for (auto &it : li)
            cin >> it;
    Solution obj;
    cout << obj.totalWays(n, m, grid) << "\n";
}