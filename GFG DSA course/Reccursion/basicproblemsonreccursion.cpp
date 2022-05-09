#include <bits/stdc++.h>
using namespace std;
// print name 5 times
// void printnames(int cnt)
// {
//     if (cnt == 5)
//         return;
//     cout << "Pulkit\n";
//     printnames(++cnt);
// }

// print linearly from 1 to N
void printLinearly(int current, int n)
{
    if (current == n + 1)
    {
        return;
    }
    cout << current++ << "\n";
    printLinearly(current, n);
}

// print backward from 1 to N
void printBack(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n-- << "\n";
    printBack(n);
}

// print N to 1 but by using backtracking
void printLinBacktrak(int i, int n)
{
    if (i == 0)
        return;
    printLinBacktrak(i - 1, n);
    cout << n - (i - 1) << "\n";
}

// print 1 to N but by Backtracking
void printBackBacktrack(int i, int n)
{
    if (i == 0)
        return;
    printBackBacktrack(i - 1, n);
    cout << i << "\n";
}
int main()
{
    int n;
    cin >> n;
    printLinBacktrak(n, n);
    printBackBacktrack(n, n);
    return 0;
}