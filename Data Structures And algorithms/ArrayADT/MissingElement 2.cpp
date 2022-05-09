#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19};
    int diff = 6 - 0;
    for (int i = 0; i < 11; i++)
    {
        if (v[i] - i != diff)
        {
            while (v[i] - i > diff)
            {
                cout << i + diff << " ";
                diff++;
            }
        }
    }
    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        if (v[i + 1] - v[i] != 1)
        {
            for (int x = 1; x < v[i + 1] - v[i]; x++)
            {
                cout << v[i] + x<<" ";
            }
        }
    }

    return 0;
}