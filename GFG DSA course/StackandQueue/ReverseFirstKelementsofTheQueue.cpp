#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
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
queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int> st;
    int n = q.size();
    for (int i = 0; i < k; i++)
    {
        int frontele = q.front();
        q.pop();
        st.push(frontele);
    }
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        q.push(top);
    }

    for (int i = 0; i < n - k; i++)
    {
        int frontele = q.front();
        q.pop();
        q.push(frontele);
    }
    return q;
}

int main()
{
    int n;
    cin >> n;

    return 0;
}