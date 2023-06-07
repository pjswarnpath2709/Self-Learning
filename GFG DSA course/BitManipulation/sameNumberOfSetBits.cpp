#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << ":" << " " << x << "\n";

class Solution
{
public:
    long long nCr(long long n, long long r)
    {
        if(r==0) return 1;
        long long ans = 1;
        for (int i = 1; i <= r; i++)
        {
            ans *= n - i + 1;
            ans /= i;
        }
        return ans;
    }
    long long sameNumberOfBitsReC(long long n)
    {
        if(n==0) return 0;
        long long length = log2(n) + 1;
        long long setBits = __builtin_popcountll(n);
        if (length == setBits)
            return 0;
        long long mask = 1 << (length-1);
        long long remainder = (n ^ mask);
        long long ans = nCr(length-1, setBits);
        ans += sameNumberOfBitsReC(remainder);
        return ans;
    }
    long long sameNumberOfBits(long long n)
    {
        long long ans = 0;
        // basic approach
        for (int i = 1; i < n; i++)
        {
            if (__builtin_popcountll(i) == __builtin_popcountll(n))
            {
                ans++;
            }
        }
        return ans;
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
        cout << obj.sameNumberOfBitsReC(n) << "\n";
    }
}