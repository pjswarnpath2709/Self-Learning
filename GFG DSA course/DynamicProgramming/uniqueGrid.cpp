#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int help(int row, int col)
    {
        if (row == 0 || col == 0)
        {
            return 1;
        }
        int right = help(row, col - 1);
        int down = help(row - 1, col);
        return right + down;
    }
    int helpMemo(int row, int col, vector<vector<int>> &dp)
    {
        if (row == 0 || col == 0)
        {
            return 1;
        }
        if (dp[row][col] != -1)
            return dp[row][col];
        int down = helpMemo(row - 1, col, dp);
        int right = helpMemo(row, col - 1, dp);
        return dp[row][col] = right + down;
    }
    int memoisation(int row, int col)
    {
        vector<vector<int>> dp(row, vector<int>(col, -1));
        return helpMemo(row - 1, col - 1, dp);
    }
    int tabulation(int row, int col)
    {
        vector<vector<int>> dp(row, vector<int>(col, -1));
        for (int i = 0; i < col; i++)
        {
            dp[0][i] = 1;
        }
        for (int i = 0; i < row; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < col; j++)
            {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[row - 1][col - 1];
    }
    int spaceOptimization(int m, int n)
    {
        vector<int> prev(n, 0);
        for (int row = 0; row < m; row++)
        {
            vector<int> temp(n, 0);

            for (int col = 0; col < n; col++)
            {
                if (row == 0 && col == 0)
                    temp[col] = 1;
                else
                {
                    if (col >= 1)
                    {
                        temp[col] = prev[col] + temp[col - 1];
                    }
                    temp[col] = 0;
                    if (row >= 1)
                        temp[col] += prev[col];
                    if (col >= 1)
                        temp[col] += temp[col - 1];
                }
            }
            prev = temp;
        }
        return prev[n - 1];
    }
    int NumberOfPath(int a, int b)
    {
        return spaceOptimization(a, b);
        // return tabulation(a, b);
        // return memoisation(a, b);
        // return help(a - 1, b - 1);
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    Solution obj;
    cout << obj.NumberOfPath(m, n) << "\n";
}