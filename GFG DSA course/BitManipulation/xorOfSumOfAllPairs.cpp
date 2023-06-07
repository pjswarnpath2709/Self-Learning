#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << ":" \
                      << " " << x << "\n";

class Solution
{
public:
    long long calXor(vector<long long> &vec){
        long long ans = 0;
        for(auto it : vec) ans^=(it<<1);
        return ans;
    }
    void solve()
    {
        long long n;
        cin >> n;
        vector<long long> vec(n);
        for (auto &it : vec)
            cin >> it;
        cout << calXor(vec) << "\n";
    }
    
};

int main()
{
    int test;
    cin >> test;
    Solution obj;
    for (int i = 0; i < test; i++)
    {
        obj.solve();
    }
}