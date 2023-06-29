#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> points;
    int n;
    int helpRec(int day, int last)
    {
        if (day == 0)
        {
            int maxi = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task == last)
                    continue;
                maxi = max(maxi, points[0][task]);
            }
            return maxi;
        }
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task == last)
                continue;
            int ans = points[day][task] + helpRec(day - 1, task);
            maxi = max(ans, maxi);
        }
        return maxi;
    }
    int helpMemo(int day, int last, vector<vector<int>> &dp)
    {
        if (day == 0)
        {
            int maxi = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task == last)
                    continue;
                maxi = max(maxi, points[0][task]);
            }
            return maxi;
        }
        if (dp[day][last] != -1)
            return dp[day][last];
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task == last)
                continue;
            int ans = points[day][task] + helpMemo(day - 1, task, dp);
            maxi = max(ans, maxi);
        }
        return dp[day][last] = maxi;
    }
    int memoisation()
    {
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return helpMemo(n - 1, 3, dp);
    }
    int tabulation()
    {
        vector<vector<int>> dp(n, vector<int>(4, -1));
        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][0], points[0][1]);
        dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
        for (int day = 1; day < n; day++)
        {
            for (int last = 0; last < 4; last++)
            {
                dp[day][last] = 0;
                for (int task = 0; task < 3; task++)
                {
                    if (task == last)
                        continue;
                    int ans = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], ans);
                }
            }
        }

        return dp[n - 1][3];
    }
    int spaceOptimisation()
    {
        vector<int> prev(4, 0);
        prev[0] = max(points[0][1], points[0][2]);
        prev[1] = max(points[0][0], points[0][2]);
        prev[2] = max(points[0][0], points[0][1]);
        prev[3] = max(points[0][0], max(points[0][1], points[0][2]));
        for (int day = 0; day < n; day++)
        {
            vector<int> temp(4, 0);
            for (int last = 0; last < 4; last++)
            {
                temp[last] = 0;
                for (int task = 0; task < 3; task++)
                {
                    if(task==last) continue;
                    temp[last] = max(temp[last], points[day][task] + prev[task]);
                }
            }
            temp = prev;
        }
        return prev[3];
    }
    int ninjaTraining(int n, vector<vector<int>> &pwd)
    {
        points = pwd;
        this->n = n;
        // return helpRec(n - 1, 3);
        // return memoisation();
        return tabulation();
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        for (auto &it : points[i])
            cin >> it;
    }
    Solution obj;
    cout << obj.ninjaTraining(n, points);
}