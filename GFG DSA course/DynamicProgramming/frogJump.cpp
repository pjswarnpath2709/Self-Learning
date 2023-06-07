#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int help(vector<int> &heights, int n)
    {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return heights[1] - heights[0];
        }
        int jump1 = abs(heights[n] - heights[n - 1]) + help(heights, n - 1);
        int jump2 = abs(heights[n] - heights[n - 2]) + help(heights, n - 2);
        return min(jump1, jump2);
    }
    int minimumEnergy(vector<int> &height, int n)
    {
        return help(height, n);
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
    cout << obj.minimumEnergy(heights, n);
}