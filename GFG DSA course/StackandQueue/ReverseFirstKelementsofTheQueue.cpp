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
    // step 1: make a stack and fetch k elements from the queue
    stack<int> st;
    for (int i = 0; i < k; i++)
    {
        int frontele = q.front();
        q.pop();
        st.push(frontele);
    }

    // step 2: again push all the elements in the queue
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    // step 3: get all the n-k elements from the front now and put them at back
    for (int i = 0; i < q.size() - k; i++)
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