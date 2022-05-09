

#include <bits/stdc++.h>
using namespace std;

double func(double a)
{
    return 1 / (1 + a * a);
}

// int = h*([y0+yn]/2 + sum(y)->(1 to n-1) )

double trapezoidal(double lower, double upper, int n)
{
    double h = (upper - lower) / n;

    double sum = (func(lower) + func(upper)) / 2;

    for (int i = 1; i < n; i++)
    {
        double x_i = lower + i * h;
        sum += func(x_i);
    }
    return sum * h;
}

int main()
{
    cout << "enter lower upper and number of partitions: \n";
    int a, b, n;
    cin >> a >> b >> n;

    cout << trapezoidal(a, b, n) << "\n";
    return 0;
}