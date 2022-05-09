#include <bits/stdc++.h>
using namespace std;

// x(n+1)=x(n)-(f(x(n))/f'(x(n))

// function
double func(double x)
{
    double ans = x * x * x - x * x + 2;
    return ans;
}

// diffrention of function
double diff_func(double x)
{
    double ans = 3 * x * x - 2 * x;
    return ans;
}

int main()
{
    cout << "enter the value of eps :"
         << "\n";
    double eps;
    cin >> eps;

    cout << "enter the value of x"
         << "\n";
    double x;
    cin >> x;
    // count is initialised 1
    int count = 1;

    double h = func(x) / diff_func(x);
    while (abs(h) > eps)
    {
        cout << count << " " << x << "\n";

        h = func(x) / diff_func(x);

        x = x - h;

        count++;
    }
    cout << "the value of the root is :" << x << endl;

    return 0;
}