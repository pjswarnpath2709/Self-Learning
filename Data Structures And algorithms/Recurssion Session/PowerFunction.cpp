#include <iostream>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int power(int m, int n)
{
    if (n == 0)
        return 1;
    else
    {
        return power(m, n - 1) * m;
    }
}
int power1(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        if (n % 2 == 0)
        {
            return power(m * m, n / 2);
        }
        else
        {
            return m * power(m * m, (n - 1) / 2);
        }
    }
}

int main()
{
    int r = 3;
    cout << power(r, 4) << endl;
    cout << power1(r, 4);
    return 0;
}