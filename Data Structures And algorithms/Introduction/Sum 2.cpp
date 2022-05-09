
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 0;
    cin >> a;
    int sum = 0;
    for (int i = 0; i < a; i++)
    {
        int input;
        cin >> input;
        sum = sum + input;
    }
    cout << sum;
    return 0;
}