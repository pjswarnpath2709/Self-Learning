#include <stack>
#include <bits/stdc++.h>
using namespace std;
class SpecialStack
{
    // Define the data members.
    stack<int> st;
    int mini = INT_MAX;
    /*----------------- Public Functions of SpecialStack -----------------*/
public:
    void push(int data)
    {
        // for the first element normal push
        if (st.empty())
        {
            mini = min(mini, data);
            st.push(data);
            return;
        }
        if (data > mini)
        {
            st.push(data);
        }
        else
        {
            int val = 2 * data - mini;
            st.push(val);
            mini = data;
        }
    }

    int pop()
    {
        if (st.empty())
        {
            return -1;
        }
        int curr = st.top();
        if (curr > mini)
        {
            // normal pop
            st.pop();
            return curr;
        }
        else
        {
            int prevMini = mini;
            int val = 2 * mini - curr;
            mini = val;
            return prevMini;
        }
    }

    int top()
    {
        if (st.empty())
        {
            return -1;
        }
        int curr = st.top();
        if (curr < mini)
        {
            return mini;
        }
        else
        {
            return curr;
        }
    }

    bool isEmpty()
    {
        return st.empty();
    }

    int getMin()
    {
        if (st.empty())
        {
            return -1;
        }
        return mini;
    }
};