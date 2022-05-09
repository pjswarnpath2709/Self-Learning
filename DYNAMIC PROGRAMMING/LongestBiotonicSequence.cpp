#include <iostream>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
int *lis(int *input, int n)
{
    int *output = new int[n];
    for (int i = 0; i < n; i++)
        output[i] = 1;
    /* Compute LIS values from left to right */
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (input[i] > input[j] && output[i] < output[j] + 1)
                output[i] = output[j] + 1;
    return output;
}
int *lds(int *input, int n)
{

    /* Allocate memory for lds and initialize LDS values for
      all indexes */
    int *output = new int[n];
    for (int i = 0; i < n; i++)
        output[i] = 1;

    /* Compute LDS values from right to left */
    for (int i = n - 2; i >= 0; i--)
        for (int j = n - 1; j > i; j--)
            if (input[i] > input[j] && output[i] < output[j] + 1)
                output[i] = output[j] + 1;

    return output;
}
int lbs(int *input, int n)
{
    int *output_lis = lis(input, n);
    int *output_lds = lds(input, n);
    int maximum = 1;
    for (int i = 0; i < n; i++)
    {
        maximum = max(output_lis[i] + output_lds[i] - 1, maximum);
    }
    return maximum;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        int *input = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> input[i];
        }
        cout << lbs(input, n) << "\n";
    }

    return 0;
}