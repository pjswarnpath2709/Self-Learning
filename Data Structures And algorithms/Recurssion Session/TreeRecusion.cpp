#include <iostream>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int fun(int n)
{
    if (n >= 0)
    {
        printf("%d ", n);
        fun(n - 1);
        fun(n - 1);
        fun(n - 1);
    }
    else
    {
        return 0;
    }
}
int main()
{
    fun(10);

    return 0;
}