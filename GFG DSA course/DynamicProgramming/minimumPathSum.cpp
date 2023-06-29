#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;
class Solution
{
    vvi grid;
    int m;
    int n;

public:
    int help(int row, int col)
    {
        if (row == 0 && col == 0)
            return grid[0][0];
        if (row < 0 || col < 0)
            return 1e9;
        int up = grid[row][col] + help(row - 1, col);
        int left = grid[row][col] + help(row, col - 1);
        return min(up, left);
    }
    int minPathSum(vvi &grid)
    {
        this->grid = grid;
        this->m = grid.size();
        this->n = grid[0].size();
        return help(m - 1, n - 1);
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    vvi grid(m, vi(n, -1));
    for (auto &li : grid)
        for (auto &it : li)
            cin >> it;
    Solution obj;
    cout << obj.minPathSum(grid) << "\n";
}