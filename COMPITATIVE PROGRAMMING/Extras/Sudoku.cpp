
#include <bits/stdc++.h>
using namespace std;
#define N 9

bool isSafeinRow(int grid[N][N], int row, int x)
{
    for (int i = 0; i < N; i++)
    {
        if (grid[row][i] == x)
        {
            return false;
        }
    }
    return true;
}
bool isSafeinCol(int grid[N][N], int col, int x)
{
    for (int i = 0; i < N; i++)
    {
        if (grid[i][col] == x)
        {
            return false;
        }
    }
    return true;
}
bool isSafeinBox(int grid[N][N], int row, int col, int x)
{
    int rowfactor = row - (row % 3);
    int colfactor = col - (col % 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i+rowfactor][j+colfactor] == x)
            {
                return false;
            }
        }
    }
    return true;
}
bool isSafe(int grid[N][N], int row, int col, int x)
{
    if (isSafeinBox(grid, row, col, x) && isSafeinRow(grid, row, x) && isSafeinCol(grid, col, x))
    {
        return true;
    }
    return false;
}
bool findNextEmptyloaction(int grid[N][N], int &row, int &col)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
            {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}
bool solveSudoku(int grid[N][N])
{
    int row=-1, col=-1;
    if (!findNextEmptyloaction(grid, row, col))
    {
        return true;
    }
    for (int i = 1; i <=N; i++)
    {
        if (isSafe(grid, row, col, i))
        {
            grid[row][col] = i;
            if (solveSudoku(grid))
            {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}
int main()
{
    int grid[N][N];
    for (int i = 0; i < N; i++)
    {
        // string s;
        // cin >> s;
        for (int j = 0; j < N; j++)
        {
            cin>>grid[i][j];
        }
    }
    if(solveSudoku(grid)){
        cout<<"true\n";
    }
    else{
        cout<<"false\n";
    }
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout << grid[i][j];
    //     }
    //     cout << "\n";
    // }
    return 0;
}