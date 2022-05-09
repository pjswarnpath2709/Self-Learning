#include <iostream>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

//BY SIR

double e(int x, int n)
{
    static double p = 1, f = 1;
    double result;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        result = e(x, n - 1);
        p = p * x;
        f = f * n;

        return result + (p / f);
    }
}
//BY MY METHOD

double pow(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        int result = 1;
        for (int i = 0; i < n; i++)
        {
            result = result * m;
        }
        return result;
    }
}

int fact(int n)
{
    if (n < 2)
    {
        return 1;
    }
    else
    {
        int f = 1;
        for (int i = n; i > 1; i--)
        {
            f = f * i;
        }
        return f;
    }
}

double Tay(int x, int n)
{

    if (n == 0)
    {
        return 1;
    }
    else
    {

        return Tay(x, n - 1) + (pow(x, n) / fact(n));
    }
}

int main()
{

    cout << e(3, 10)<<endl;
    cout << Tay(3, 10);

    return 0;
}