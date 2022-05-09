#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define pll pair<long long, long long>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
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
void reverseQueue(queue<int> &qt)
{
    if (qt.empty())
    {
        return;
    }
    // get the front and do pop
    int front = qt.front();
    qt.pop();

    // get the reversed queue back
    reverseQueue(qt);

    // put back the front to the back
    qt.push(front);
}
int main()
{
    int n;
    cin >> n;
    queue<int> qt;
    for (int i = 0; i < n; i++)
    {
        int y;
        cin >> y;
        qt.push(y);
    }
    reverseQueue(qt);
    while (!qt.empty())
    {
        cout << qt.front() << " ";
        qt.pop();
    }

    return 0;
}