#include <bits/stdc++.h>
using namespace std;

class Solution
{
    string s1;
    string s2;
    int n;
    int m;

public:
    int help(int ind1, int ind2)
    {
        if (ind1 < 0 || ind2 < 0)
            return 0;
        if (s1[ind1] == s2[ind2])
            return 1 + help(ind1 - 1, ind2 - 1);
        return 0 + max(help(ind1 - 1, ind2), help(ind1, ind2 - 1));
    }
    int recHelp()
    {
        return help(n - 1, m - 1);
    }
    int helpMemo(int ind1, int ind2, vector<vector<int>> &dp)
    {
        if (ind1 < 0 || ind2 < 0)
            return 0;
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        if (s1[ind1] == s2[ind2])
            return dp[ind1][ind2] = 1 + helpMemo(ind1 - 1, ind2 - 1, dp);
        return dp[ind1][ind2] = 0 + max(helpMemo(ind1 - 1, ind2, dp), helpMemo(ind1, ind2 - 1, dp));
    }
    int memoisation()
    {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helpMemo(n - 1, m - 1, dp);
    }
    int tabulation()
    {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int ind1 = 1; ind1 <= n; ind1++)
        {
            for (int ind2 = 1; ind2 <= m; ind2++)
            {
                if (s1[ind1 - 1] == s2[ind2 - 1])
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                else
                    dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
            }
        }
        return dp[n][m];
    }
    int spaceOptimisation()
    {
        vector<int> prev(m + 1, 0), cur(m + 1, 0);
        for (int ind1 = 1; ind1 <= n; ind1++)
        {
            for (int ind2 = 1; ind2 <= m; ind2++)
            {
                if (s1[ind1 - 1] == s2[ind2 - 1])
                    cur[ind2] = 1 + prev[ind2 - 1];
                else
                    cur[ind2] = 0 + max(prev[ind2], cur[ind2 - 1]);
            }
            prev = cur;
        }
        return prev[m];
    }
    int lcs(string s1, string s2)
    {
        this->s1 = s1;
        this->s2 = s2;
        this->n = s1.size();
        this->m = s2.size();
        return spaceOptimisation();
    }
};
int main()
{
    string a, b;
    cin >> a >> b;
    Solution obj;
    cout << obj.lcs(a, b) << "\n";
}
