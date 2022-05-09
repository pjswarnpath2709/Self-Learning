#include <iostream>
using namespace std;
#define MOD 1000000007
// naive appraoch
long long coin_change_naive(long long n, long long *d, long long numD)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    if (numD == 0)
    {
        return 0;
    }
    long long first = (coin_change_naive(n - d[0], d, numD)) % MOD;
    long long second = (coin_change_naive(n, d + 1, numD - 1)) % MOD;
    return (first % MOD + second % MOD) % MOD;
}
//efficent approach usin 2d array to do memoisation
long long coin_change(long long n, long long *d, long long numD, long long **output)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    if (numD == 0)
    {
        return 0;
    }
    if (output[n][numD] > -1)
    {
        return (output[n][numD]) % MOD;
    }
    long long first = (coin_change(n - d[0], d, numD, output)) % MOD;
    long long second = (coin_change(n, d + 1, numD - 1, output)) % MOD;
    output[n][numD] = (first % MOD + second % MOD) % MOD;
    return (first % MOD + second % MOD) % MOD;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long numD;
        cin >> numD;
        long long *d = new long long[numD];
        for (long long i = 0; i < numD; i++)
        {
            cin >> d[i];
        }
        long long n;
        cin >> n;
        // allocate 2d array here, n + 1 * numD + 1
        // put all -1
        long long **output = new long long *[n + 1];
        for (long long i = 0; i < n + 1; i++)
        {
            output[i] = new long long[numD + 1];
        }
        for (long long i = 0; i < n + 1; i++)
        {
            for (long long j = 0; j < numD + 1; j++)
            {
                output[i][j] = -1;
            }
        }
        cout << coin_change(n, d, numD, output) << endl;
    }
}