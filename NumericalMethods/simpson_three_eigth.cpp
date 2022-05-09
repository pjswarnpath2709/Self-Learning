#include <bits/stdc++.h>
using namespace std;

double func(double a)
{
    return 1 / (1 + a * a);
}

double simpson3_8(double lower, double upper, double n)
{

    double h = (upper - lower) / n;

    double sum = func(upper) + func(lower);

    for (int i = 1; i < n; i++)
    {
        if (i % 3 == 0)
        {
            sum += 2 * func(lower + i * h);
        }
        else
        {
            sum += 3 * func(lower + i * h);
        }
    }

    return sum * h * 3 / 8;
}

int main()
{
    double lower, upper, n;
    cin >> lower >> upper >> n;

    cout << simpson3_8(lower, upper, n) << "\n";

    return 0;
}