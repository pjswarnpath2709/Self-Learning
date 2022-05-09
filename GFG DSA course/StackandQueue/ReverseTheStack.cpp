#include <bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int> &st, int num)
{
    // if the stack is empty then insert the number
    if (st.empty())
    {
        st.push(num);
        return;
    }
    int x = st.top();
    st.pop();
    insertAtBottom(st, num);
    st.push(x);
}
void reverseStack(stack<int> &st)
{
    // base case
    if (st.empty())
    {
        return;
    }
    int num = st.top();
    st.pop();
    // reccursive call
    reverseStack(st);
    // insert at the bottom
    insertAtBottom(st, num);
}
int main()
{

    return 0;
}