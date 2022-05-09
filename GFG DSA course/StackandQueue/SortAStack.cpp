#include <bits/stdc++.h>
using namespace std;
void insertSorted(stack<int> &st, int top)
{
    if (st.empty() || (!st.empty() && st.top() < top))
    {
        st.push(top);
        return;
    }
    int newTop = st.top();
    st.pop();
    insertSorted(st, top);
    st.push(newTop);
}
void sortStack(stack<int> &st)
{
    // base case
    if (st.empty())
    {
        return;
    }
    int top = st.top();
    st.pop();
    sortStack(st);
    insertSorted(st, top);
}
int main()
{

    return 0;
}