#include <iostream>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

void fun(int A[])
{
    for (int i = 0; i < 5; i++)
    {
        cout << A[i] << endl;
    }
}
int *fun(int size)
{
    int *p;
    p = new int[size];
    for (int i = 0; i < size; i++)
    {
        p[i] = i + 1;
    }
    return p;
}
int main()
{
    int A[] = {2, 4, 6, 8, 10};
    int n = 5;

    for (int x : A)
    {
        cout << x << " ";
    }
    cout << " \n"
         << sizeof(A) / sizeof(int) << endl;

    fun(A);

    int *ptr;
    int size = 5;
    ptr = fun(size);
    for (int i = 0; i < size; i++)
        cout << ptr[i] << " ";
    cout << "\n";

    return 0;
}