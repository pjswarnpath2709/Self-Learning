#include <bits/stdc++.h>
using namespace std;
long long fact(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * fact(n - 1);
}

float calc_u_multiply(float u, int i)
{
    float ans = u;
    for (; i > 0; i--)
    {
        ans *= (u - i);
    }
    return ans;
}

int main()
{
    int n = 4;
    int x[] = {45, 50, 55, 60};
    double y[n][n];
    cout << setprecision(7) << "\n";

    y[0][0] = 0.7071;
    y[1][0] = 0.7660;
    y[2][0] = 0.8192;
    y[3][0] = 0.8660;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << y[j][i] << " ";
        }
        cout << "\n";
    }

    int value = 52;

    double u = (value - x[0]) / (x[1] - x[0]);

    double sum = y[0][0];
    for (int i = 1; i < n; i++)
    {
        sum += calc_u_multiply(u, i - 1) * y[0][i] / fact(i);
    }
    cout << "the value at " << value << " is : " << sum << "\n";

    return 0;
}


//   