#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

class Solution
{
    vector<vector<int>> grid;
    int r;
    int c;
    vector<int> del;

public:
    Solution()
    {
        del = {-1, 0, +1};
    }
    int help(int row, int colA, int colB)
    {
        if (colA < 0 || colB < 0 || colA >= c || colB >= c)
        {
            return -1e8;
        }
        if (row == r - 1)
        {
            if (colA == colB)
                return grid[row][colA];
            else
                return grid[row][colA] + grid[row][colB];
        }
        // explore all the paths
        int maxi = -1e8;
        for (auto dA : del)
        {
            for (auto dB : del)
            {
                int newColA = colA + dA;
                int newColB = colB + dB;
                int nextAns = help(row + 1, newColA, newColB);
                if (colA == colB)
                    maxi = max(grid[row][colA] + nextAns, maxi);
                else
                    maxi = max(grid[row][colA] + grid[row][colB] + nextAns, maxi);
            }
        }
        return maxi;
    }
    int helpMemo(int row, int colA, int colB, vvvi &dp)
    {
        if (colA < 0 || colB < 0 || colA >= c || colB >= c)
            return -1e8;
        if (row == r - 1)
        {
            if (colA == colB)
                return grid[row][colA];
            return grid[row][colA] + grid[row][colB];
        }
        // explore all the paths
        if (dp[row][colA][colB] != -1)
            return dp[row][colA][colB];
        int maxi = -1e8;
        for (int delA = -1; delA <= +1; delA++)
        {
            for (int delB = -1; delB <= +1; delB++)
            {
                int newColA = colA + delA;
                int newColB = colB + delB;
                int nextAns = helpMemo(row + 1, newColA, newColB, dp);
                if (colA == colB)
                    maxi = max(maxi, grid[row][colA] + nextAns);
                else
                    maxi = max(maxi, grid[row][colA] + grid[row][colB] + nextAns);
            }
        }
        return maxi;
    }
    int memoisation()
    {
        vvvi dp(r, vvi(c, vi(c, -1)));
        return helpMemo(0, 0, c - 1, dp);
    }
    int tabulation()
    {
        vvvi dp(r, vvi(c, vi(c, 0)));
        for (int colA = 0; colA < c; colA++)
        {
            for (int colB = 0; colB < c; colB++)
            {
                if (colA == colB)
                {
                    dp[r - 1][colA][colB] = grid[r - 1][colA];
                }
                else
                {
                    dp[r - 1][colA][colB] = grid[r - 1][colA] + grid[r - 1][colB];
                }
            }
        }
        for (int row = r - 2; row >= 0; row--)
        {
            for (int colA = c - 1; colA >= 0; colA--)
            {
                for (int colB = c - 1; colB >= 0; colB--)
                {
                    int maxi = -1e8;
                    for (int delA = -1; delA <= +1; delA++)
                    {
                        for (int delB = -1; delB <= +1; delB++)
                        {
                            int newColA = colA + delA;
                            int newColB = colB + delB;
                            int nextAns = -1e8;
                            if (newColA >= 0 && newColB >= 0 && newColA < c && newColB < c)
                                nextAns = dp[row + 1][newColA][newColB];
                            if (colA == colB)
                                maxi = max(maxi, grid[row][colA] + nextAns);
                            else
                                maxi = max(maxi, grid[row][colA] + grid[row][colB] + nextAns);
                        }
                    }
                    dp[row][colA][colB] = maxi;
                }
            }
        }
        return dp[0][0][c - 1];
    }
    int spaceOptimisation()
    {
        vvi prev(c, vi(c, 0));
        for (int colA = 0; colA < c; colA++)
        {
            for (int colB = 0; colB < c; colB++)
            {
                if (colA == colB)
                {
                    prev[colA][colB] = grid[r - 1][colA];
                }
                else
                {
                    prev[colA][colB] = grid[r - 1][colA] + grid[r - 1][colB];
                }
            }
        }

        for (int row = r - 2; row >= 0; row--)
        {

            vvi cur(c, vi(c, 0));
            for (int colA = c - 1; colA >= 0; colA--)
            {
                for (int colB = c - 1; colB >= 0; colB--)
                {
                    int maxi = -1e8;
                    for (int delA = -1; delA <= +1; delA++)
                    {
                        for (int delB = -1; delB <= +1; delB++)
                        {
                            int newColA = colA + delA;
                            int newColB = colB + delB;
                            int nextAns = -1e8;
                            if (newColA >= 0 && newColB >= 0 && newColA < c && newColB < c)
                                nextAns = prev[newColA][newColB];
                            if (colA == colB)
                                maxi = max(maxi, grid[row][colA] + nextAns);
                            else
                                maxi = max(maxi, grid[row][colA] + grid[row][colB] + nextAns);
                        }
                    }
                    cur[colA][colB] = maxi;
                }
            }
            prev = cur;
        }
        return prev[0][c - 1];
    }
    int solve(int m, int n, vector<vector<int>> &mat)
    {
        this->grid = mat;
        this->r = m;
        this->c = n;
        // return help(0, 0, c - 1);
        // return memoisation();
        // return tabulation();
        return spaceOptimisation();
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n, -1));
    for (auto &li : grid)
        for (auto &it : li)
            cin >> it;
    Solution obj;
    cout << obj.solve(m, n, grid) << "\n";
}