#include <bits/stdc++.h>
using namespace std;

void printCeilingLeft(vector<int> arr)
{
    cout << (-1 + " ");
    for (int i = 1; i < arr.size(); i++)
    {
        int diff = INFINITY;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] >= arr[i])
            {
                diff = min(diff, arr[j] - arr[i]);
            }
        }
        if (diff == INFINITY)
        {
            cout << -1 << " ";
        }
        else
        {
            cout << arr[i] + diff << " ";
        }
    }
    cout << "\n";
}
void printleftCeiling(vector<int> vec)
{
    set<int> st;
    for (int i = 0; i < vec.size(); i++)
    {
        if (st.lower_bound(vec[i]) != st.end())
            cout << *(st.lower_bound(vec[i])) << " ";
        else
            cout << "-1"
                 << " ";
        st.insert(vec[i]);
    }
}

int main()
{

    return 0;
}