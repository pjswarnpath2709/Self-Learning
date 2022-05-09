#include <bits/stdc++.h>
using namespace std;

double func(double a)
{

    double ans = a * a - 12; // function in this

    return ans;
}

double newFunc(double a, double b)
{
    double ans = (a * func(b) - b * func(a)) / (func(b) - func(a));
    return ans;
}

int main()
{

    // enter the value of eps
    cout << "enter the value of eps"
         << "\n";
    double eps;
    cin >> eps;
    // enter the value of x0,x1
    cout << "Enter the value of x0,x1 \n";
    double x0, x1;
    cin >> x0 >> x1;

    int steps = 1; // initial step of the algorithm
    double x2 = newFunc(x0, x1);

    do
    {
        x0 = x1;
        x1 = x2;
        cout << steps << " " << x2 << "\n";
        x2 = newFunc(x0, x1);

        if (func(x2) == 0)
        {
            cout << "the root of the eqaution is " << x2 << "\n";
            break;
        }
        steps++;

    } while (abs(x2 - x1) > eps);

    return 0;
}