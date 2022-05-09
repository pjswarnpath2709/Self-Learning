#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int size, int count, int n)
{
    // base case
    if (count == size)
    {
        st.push(n);
        return;
    }
    int top = st.top();
    st.pop();
    insertAtBottom(st, size, count + 1, n);
    st.push(top);
}
int main()
{

    int n, k;
    cin >> n >> k;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }
    insertAtBottom(st, n, 0, k);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}