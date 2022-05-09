

#include <iostream>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

//USING Factorial Function
int fact(int n)
{
    int f = 1;
    if (n == 0)
    {
        return 1;
    }

    else
    {
        for (int i = 1; i <= n; i++)
        {
            f = f * (i);
        }
        return f;
    }
}

auto nCr(int n, int r)
{
    try
    {
        int t1, t2, t3;
        if (n < r)
        {
            throw -1;
        }
        else
        {
            return fact(n) / (fact(r) * fact(n - r));
        }
    }
    catch (int i)
    {
        if (i == -1)
            cout << "N could not be lesser than R" << endl;
    }
}

//Using reccursion:-->
auto recNCR(int n, int r)
{
    try
    {
        if (r == 0 || n == r)
        {
            return 1;
        }
        else
        {
            return recNCR(n - 1, r - 1) + recNCR(n - 1, r);
        }
        if ((r == 0 && n == 0) || (n < r))
        {
            throw 1;
        }
    }

    catch (int i)
    {
        if (i = -1)
            cout << "Error encountered";
    }
}

int main()
{

    cout << fact(5) << endl;
    cout << nCr(4, 2)<<endl;
    cout<< recNCR(4,2)<<endl;

    return 0;
}