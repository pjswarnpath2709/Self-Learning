

#include <bits/stdc++.h>
using namespace std;
long long backbenchersAndBugs(int N, vector<int> C)
{
    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += C[i];
    }

    return sum;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> choices(N);
        for (int i = 0; i < N; i++)
        {
            cin >> choices[i];
        }

        cout << backbenchersAndBugs(N, choices) << "\n";
    }

    return 0;
}