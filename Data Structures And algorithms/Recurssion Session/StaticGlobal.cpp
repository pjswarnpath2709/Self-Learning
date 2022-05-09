#include <iostream>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int x = 0;  //Made it global
int fun1(int a)
{

    if (a > 0)
    {
        x++;
        return fun1(a - 1) + x;
    }
}

int main()
{
    int w = 5;
    cout << fun1(w);

    return 0;
}