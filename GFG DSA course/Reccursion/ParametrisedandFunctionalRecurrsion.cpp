#include <bits/stdc++.h>
using namespace std;
// sumation of first N natural numbers
int sumation(int i, int n)
{
    if (i == n)
    {
        return n;
    }
    return i + sumation(i + 1, n);
}
int fact(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * fact(n - 1);
}
int main()
{
    int n;
    cin >> n;
    cout << sumation(1, n) << "\n";
    cout << fact(5) << "\n";
    return 0;
}