#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << "\n"

class Solution
{
public:
    vector<int> dp;
    int help(vector<int> &height, int n, int k)
    {
        if (n == 0)
            return 0;
        int ans = INT_MAX;
        if(dp[n]!=-1) return dp[n];
        for (int i = 1; i <= k; i++)
        {
            if (n - i < 0)
                continue;
            int diff = abs(height[n] - height[n - i]);
            int mini = help(height, n - i, k);
            ans = min(ans, diff + mini);
        }
        return dp[n] = ans;
    }
    int minimizeCost(vector<int> &height, int n, int k)
    {
        dp.resize(n,-1); 
        return help(height, n-1, k);
    }
};

int main()
{
    int n;
    int k;
    cin >> n >> k;
    vector<int> heights(n);
    for (auto &it : heights)
        cin >> it;
    Solution obj;
    cout << obj.minimizeCost(heights, n, k) << "\n";
}