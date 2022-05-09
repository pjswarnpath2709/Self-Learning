#include <bits/stdc++.h>
using namespace std;

//   c = ( a * f(b) - b * f(a) )  / ( f(b) - f(a) )
double func(double a)
{
    return a * log10(a) - 1.2;
}

double calculateC(double a, double b)
{
    double ans = a * func(b) - b * func(a);
    ans /= (func(b) - func(a));
    return ans;
}
int main()
{
    cout << "enter value of eps :"
         << "\n";
    double eps;
    cin >> eps;

    double lower, upper;
    do
    {
        cout << "enter value of upper and lower "
             << "\n";
        cin >> lower >> upper;

    } while (func(lower) * func(upper) >= 0);

    int steps = 0;
    double ans = 0;

    while (abs(upper - lower) > eps)
    {
        double c = calculateC(lower, upper);
        ans = c;
        if (func(lower) * func(c) < 0)
        {
            upper = c;
        }
        else
        {
            lower = c;
        }
        steps++;
        printf("itertaion %d \t %0.7lf \n", steps, ans);
    }

    cout << "Total number of iterations : " << steps << "\n";
    cout << "The value of the root is : " << ans << "\n";

    return 0;
}