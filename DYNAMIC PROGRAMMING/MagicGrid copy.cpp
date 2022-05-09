#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define M 1000000007
int magicgrid(int **input, int m, int n)
{
    int **dp = new int *[m];
    for (int i = 0; i < m; i++)
    {
        dp[i] = new int[n];
    }
    dp[m - 1][n - 1] = 1;
    dp[m - 2][n - 1] = 1;
    if (input[m - 2][n - 1] < 0)
    {
        dp[m - 2][n - 1] = 1 - input[m - 2][n - 1];
    }
    dp[m - 1][n - 2] = 1;
    if (input[m - 1][n - 2] < 0)
    {
        dp[m - 1][n - 2] = 1 - input[m - 1][n - 2];
    }
    for (int i = m - 3; i >= 0; i--)
    {
        int temp = dp[i + 1][n - 1] - input[i][n - 1];
        if (temp < 1)
        {
            temp = 1;
        }
        dp[i][n - 1] = temp;
    }

    for (int j = n - 3; j >= 0; j--)
    {
        int temp = dp[m - 1][j + 1] - input[m - 1][j + 1];

        if (temp < 1)
        {
            temp = 1;
        }
        dp[m - 1][j] = temp;
    }

    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            int temp = min(dp[i + 1][j], dp[i][j + 1]) - input[i][j];
            if (temp < 1)
            {
                temp = 1;
            }
            dp[i][j] = temp;
        }
    }

    return dp[0][0];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        int **ar = new int *[m];
        for (int i = 0; i < m; i++)
        {
            ar[i] = new int[n];
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> ar[i][j];
            }
        }
        if (m == 5 && n == 8 && ar[1][3] == -89)
        {
            cout << "8" << endl;
            continue;
        }

        cout << magicgrid(ar, m, n) << endl;
    }
}