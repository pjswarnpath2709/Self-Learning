#include <bits/stdc++.h>
using namespace std;

// memoisation
long long fibbo(int number, vector<long long> &vec)
{
    if (vec[number] != -1)
    {
        return vec[number];
    }
    else if (number == 1 || number == 0)
    {
        vec[number] = number;
        return number;
    }
    vec[number] = fibbo(number - 1, vec) + fibbo(number - 2, vec);
    return vec[number];
}

// tabulation
long long fibboTable(int number)
{
    long long prev = 1;
    long long prev2 = 0;
    for (int i = 2; i <= number; i++)
    {
        long long curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main()
{
    long long number;
    cin >> number;

    vector<long long> vec(number + 1, -1);

    cout << fibbo(number, vec) << "\n";
    cout << fibboTable(number) << "\n";

    for (auto it : vec)
    {
        cout << it << " ";
    }
    return 0;
}