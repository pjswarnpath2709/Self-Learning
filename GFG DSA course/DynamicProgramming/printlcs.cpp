#include <bits/stdc++.h>
using namespace std;

class Solution
{
    string s1;
    string s2;
    int n;
    int m;

public:
    vector<vector<int>> tabulation()
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
        return dp;
    }
    void lcsHelp(vector<vector<int>> &dp, int i, int j, string str, set<string> &st)
    {
        if (i == 0 || j == 0)
        {
            if (str.length() == dp[n][m])
            {
                reverse(str.begin(), str.end());
                st.insert(str);
            }
            return;
        }
        if (s1[i - 1] == s2[j - 1])
        {
            str += s1[i - 1];
            lcsHelp(dp, i - 1, j - 1, str, st);
            str.pop_back();
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            lcsHelp(dp, i - 1, j, str, st);
        }
        else if (dp[i - 1][j] < dp[i][j - 1])
        {
            lcsHelp(dp, i, j - 1, str, st);
        }
        else
        {
            lcsHelp(dp, i - 1, j, str, st);
            lcsHelp(dp, i, j - 1, str, st);
        }
    }
    string lcs(string s1, string s2)
    {
        this->s1 = s1;
        this->s2 = s2;
        this->n = s1.size();
        this->m = s2.size();
        vector<vector<int>> dp = tabulation();
        cout << dp[n][m];
        int i = n, j = m;
        string ans;
        while (i > 0 && j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                ans += s1[i - 1];
                i = i - 1;
                j = j - 1;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                i = i - 1;
            }
            else
            {
                j = j - 1;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    vector<string> allLcs(string s1, string s2)
    {
        this->s1 = s1;
        this->s2 = s2;
        this->n = s1.size();
        this->m = s2.size();
        vector<vector<int>> dp = tabulation();
        set<string> st;
        lcsHelp(dp, n, m, "", st);
        vector<string> ans;
        for (auto it : st)
        {
            ans.push_back(it);
        }
        return ans;
    }
};
// s = abaaa, t = baabaca
int main()
{
    string a, b;
    cin >> a >> b;
    Solution obj;
    // cout << obj.lcs(a, b) << "\n";
    for (auto it : obj.allLcs(a, b))
        cout << it << "\n";
}
