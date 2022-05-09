#include <iostream>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
void fun1(int n)
{
    cout << " this is for Func1(" << n << ") : " << endl;
    if (n > 0)
    {
        cout << " " << n << endl;
        fun1(n - 1);
    }
    else
    {
        cout << "0";
    }
}
void fun2(int n)
{

    if (n > 0)
    {
        fun2(n - 1);
        cout << " this is for Func2(" << n << ") : " << endl;
        cout << " " << n << endl;
    }
    else
    {
        cout << "0";
    }
}

int main()
{
    int x = 3;
    fun1(x);
    cout << "\n ";
    fun2(x);
    cout << "\n ";

    return 0;
}