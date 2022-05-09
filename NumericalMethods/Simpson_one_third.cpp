#include <bits/stdc++.h>
using namespace std;

double func(double a)
{
    return 1 / (1 + a * a);
}

double simpson1_3(double lower, double upper, double n)
{

    double h = (upper - lower) / n;

    double sum = func(upper) + func(lower);

    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 0)
        {
            sum += 2 * func(lower + i * h);
        }
        else
        {
            sum += 4 * func(lower + i * h);
        }
    }

    return sum * h / 3;
}

int main()
{
    double lower, upper, n;
    cin >> lower >> upper >> n;

    cout << simpson1_3(lower, upper, n) << "\n";

    return 0;
}