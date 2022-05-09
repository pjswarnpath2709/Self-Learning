#include <iostream>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
template <class T>
void initialise_matrix_with(T **matrix, int row, int col, T value)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = value;
        }
    }
}
template <class T>
void in_matrix(T **matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }
}
template <class T>
void out_matrix_fun(T **matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}
int minimumStregth(int **grid, int m, int n)
{
    int **dp = new int *[m];
    for (int i = 0; i < m; i++)
    {
        dp[i] = new int[n];
    }
    dp[m - 1][n - 1] = 0;
    for (int i = m - 2; i >= 0; i--)
    {
        if (dp[i + 1][n - 1] - grid[i][n - 1] == 1 && grid[i + 1][n - 1] < 0)
        {
            dp[i][n - 1] = 2; // if any where the minimum health becoming one ,i check for the following condition
        }
        else
        {
            dp[i][n - 1] = dp[i + 1][n - 1] - grid[i][n - 1];
            if (dp[i][n - 1] < 0)
                dp[i][n - 1] = 1; // if any where health minimum health become -ve i made it 1
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (dp[m - 1][i + 1] - grid[m - 1][i] == 1 && grid[m - 1][i + 1] < 0)
        {
            dp[m - 1][i] = 2; // if any where the minimum healtgh becoming one ,i check for the following condition
        }
        else
        {
            dp[m - 1][i] = dp[m - 1][i + 1] - grid[m - 1][i];
            if (dp[m - 1][i] < 0)
                dp[m - 1][i] = 1; // if any where health minimum health become -ve i made it 1
        }
    }
    // out_matrix_fun(dp, m, n);
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            if (min(dp[i][j + 1], dp[i + 1][j]) - grid[i][j] == 1 && grid[i + 1][j] < 0 && grid[i][j + 1] < 0)
            {
                dp[i][j] = 2;
            }
            else
            {
                dp[i][j] = min(dp[i][j + 1], dp[i + 1][j]) - grid[i][j];
            }
            if (dp[i][j] < 0)
                dp[i][j] = 1; // if any where health minimum health become -ve i made it 1
        }
    }
    int ans = dp[0][0];
    for (int i = 0; i < m; i++)
    {
        delete[] dp[i];
    }
    delete[] dp;
    return ans;
}
void solve()
{
    int m, n;
    cin >> m >> n;
    int **grid = new int *[m];
    for (int i = 0; i < m; i++)
    {
        grid[i] = new int[n];
    }
    in_matrix(grid, m, n);
    // out_matrix_fun(grid, m, n);
    int ans = minimumStregth(grid, m, n);
    cout << ans << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}