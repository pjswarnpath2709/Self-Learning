#include <bits/stdc++.h>
using namespace std;

void deleteMiddle(stack<int> &st, int count, int size)
{
    // base case
    if (count == size / 2)
    {
        st.pop();
        return;
    }
    int top = st.top();
    st.pop();
    deleteMiddle(st, count + 1, size);
    st.push(top);
}
int main()
{
    stack<int> st;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }
    deleteMiddle(st, 0, n);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}