#define pb push_back
#define ppb pop_back
#define vi vector<int>
#include <bits/stdc++.h>
using namespace std;
template <class T>
void in_vector(vector<T> &vec, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
}
template <class T>
void printVec(vector<T> &vec)
{
    for (T i : vec)
    {
        cout << i << " ";
    }
    cout << "\n";
}
void printSubSet2(int idx, vi &vec, vi &ds, vector<vi> &ans)
{
    ans.pb(ds);
    // ans.pb(ds);
    for (int i = idx; i < vec.size(); i++)
    {
        if (i != idx && vec[i] == vec[i - 1])
        {
            continue;
        }
        ds.pb(vec[i]);
        printSubSet2(i + 1, vec, ds, ans);
        ds.ppb();
    }
}
int main()
{
    int n;
    cin >> n;
    vi vec(n);
    in_vector(vec, n);
    sort(vec.begin(), vec.end());
    // printVec(vec);
    vi ds;
    vector<vi> ans;
    printSubSet2(0, vec, ds, ans);
    for (auto i : ans)
    {
        printVec(i);
    }

    return 0;
}