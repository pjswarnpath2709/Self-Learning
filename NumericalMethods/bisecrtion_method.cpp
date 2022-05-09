#include <bits/stdc++.h>
using namespace std;

// f(x) is given already f(x)= x^3 - x -1
double func(double a)
{
    double ans = a * a * a - a - 1;
    return ans;
}

int main()
{
    cout << "enter the esp :"
         << "\n";
    double eps; // kitni digit tak answer nikalna hai
    // enter the value of eps
    cin >> eps;

    // enter two numbers
    double a, b;

    // do
    // {
    //     cout << "enter a and b: "
    //          << "\n";
    //     cin >> a >> b;

    // } while (func(a) * func(b) >= 0.0);
    cin >> a >> b;

    int step = 0;
    double ans = 0;

    while (abs(a - b) > eps)
    {
        double mid = (a + b) / 2; // calculate the mid point
        ans = mid;

        if (func(a) * func(mid) < 0)
        {
            b = mid;
        }
        else
        {
            a = mid;
        }
        step++;
        cout << "value of mid in iteration " << step << " is: " << mid << "\n";
    }
    cout << "\n";
    cout << "the root is " << ans << "\n";
    cout << "number of iterations " << step << "\n";

    return 0;
}