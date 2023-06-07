#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << ":" \
                      << " " << x << "\n";

class Solution
{
    vector<long long> dp;

public:
    Solution()
    {
    }
    long long minOperationOptimal(long long n)
    {
        long long res = 0;
        while (n != 1)
        {
            if ((n & 1) == 0)
                n >>= 1;
            else if (n == 3)
            {
                res += 2;
                break;
            }
            else if ((n & 3) == 1)
                n -= 1;
            else if ((n & 3) == 3)
                n += 1;
            res++;
        }
        return res;
    }
    long long minOperationToOneDp(long long n)
    {
        if (n == 0)
            return dp[0] = 0;
        if (n == 1)
            return dp[1] = 0;

        if (dp[n] != -1)
            return dp[n];
        if ((n & 1) == 0)
        {
            long long dummy = n;
            long long steps = 0;
            while ((dummy > 1) && ((dummy & 1) == 0))
            {
                steps++;
                dummy >>= 1;
            }
            dp[n] = steps + minOperationToOneDp(dummy);
            return dp[n];
        }
        else
        {
            long long ans1 = 1 + minOperationToOneDp(n + 1);
            long long ans2 = 1 + minOperationToOneDp(n - 1);
            dp[n] = min(ans1, ans2);
            return dp[n];
        }
    }
    long long minOperationToOne(long long n)
    {
        dp.resize(n + 1, -1);
        return minOperationToOneDp(n);
    }
};

int main()
{
    int test;
    cin >> test;
    Solution obj;
    for (int i = 0; i < test; i++)
    {
        long long n;
        cin >> n;
        cout << obj.minOperationOptimal(n) << "\n";
    }
}