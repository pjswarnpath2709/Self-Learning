#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> triangle;
    int n;

public:
    int help(int row, int col)
    {
        if (row == n - 1)
        {
            return triangle[row][col];
        }
        int down = triangle[row][col] + help(row + 1, col);
        int diag = triangle[row][col] + help(row + 1, col + 1);
        return min(down, diag);
    }
    int helpMemo(int row, int col, vector<vector<int>> &dp)
    {
        if (row == n - 1)
        {
            return triangle[row][col];
        }
        if (dp[row][col] != -1)
            return dp[row][col];
        int down = triangle[row][col] + helpMemo(row + 1, col, dp);
        int diag = triangle[row][col] + helpMemo(row + 1, col + 1, dp);
        return dp[row][col] = min(down, diag);
    }
    int memoisation()
    {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helpMemo(0, 0, dp);
    }
    int tabulation()
    {
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // fill up all the base cases
        for (int col = 0; col < n; col++)
        {
            dp[n - 1][col] = triangle[n - 1][col];
        }

        for (int row = n - 2; row >= 0; row--)
        {
            for (int col = row; col >= 0; col--)
            {
                int down = dp[row + 1][col];
                int diag = dp[row + 1][col + 1];
                dp[row][col] = triangle[row][col] + min(down, diag);
            }
        }

        return dp[0][0];
    }
    int spaceOptimisation()
    {
        vector<int> front(n, -1);
        // fill up all the base cases
        for (int col = 0; col < n; col++)
        {
            front[col] = triangle[n - 1][col];
        }

        for (int row = n - 2; row >= 0; row--)
        {
            vector<int> curr(n, -1);
            for (int col = row; col >= 0; col--)
            {
                int down = front[col];
                int diag = front[col + 1];
                curr[col] = triangle[row][col] + min(down, diag);
            }
            front = curr;
        }

        return front[0];
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        this->triangle = triangle;
        this->n = triangle.size();
        // return help(0, 0);
        // return memoisation();
        // return tabulation();
        return spaceOptimisation();
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> triangle;
    for (int i = 0; i < n; i++)
    {
        vector<int> vec(i + 1);
        triangle.push_back(vec);
    }
    for (auto &li : triangle)
        for (auto &it : li)
            cin >> it;
    Solution obj;
    cout << obj.minimumTotal(triangle) << "\n";
}