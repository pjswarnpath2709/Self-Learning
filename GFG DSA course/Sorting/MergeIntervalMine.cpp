#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<long long>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <class T>
void in_vector(vector<T> &vec, ll n)
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
vector<vi> merge(vector<vi> &intervals)
{
    vector<vi> mergedIntervals;
    if (intervals.size() == 0)
    {
        return mergedIntervals;
    }
    sort(intervals.begin(), intervals.end());
    vi tempInterval = intervals[0];

    for (auto it : intervals)
    {
        if (it[0] <= tempInterval[1])
        {
            tempInterval[1] = max(it[1], tempInterval[1]);
        }
        else
        {
            mergedIntervals.push_back(tempInterval);
            tempInterval = it;
        }
    }
    mergedIntervals.push_back(tempInterval);
    return mergedIntervals;
}
int main()
{
    int n;
    cin >> n;
    vector<vi> vec;
    vi input(2, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> input[0] >> input[1];
        vec.pb(input);
    }
    vector<vi> ans=merge(vec);
    for(auto i:ans){
        cout<<i[0]<<" "<<i[1]<<"\n";
    }
    return 0;
}