#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " " << x << "\n"

class Solution
{
public:
    int help(vector<int> &heights, int n)
    {
        if (n < 0)
            return 0;
        if (n == 0 || n == 1)
        {
            return abs(heights[n] - heights[0]);
        }

        int diff1 = abs(heights[n] - heights[n - 1]);
        int diff2 = abs(heights[n] - heights[n - 2]);
        int ans1 = help(heights, n - 1);
        int ans2 = help(heights, n - 2);
        return min(ans1 + diff1, ans2 + diff2);
    }
    int minimumEnergy(vector<int> &height, int n)
    {
        return help(height, n - 1);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> heights(n);
    for (auto &it : heights)
        cin >> it;
    Solution obj;
    cout << obj.minimumEnergy(heights, n) << "\n";
}