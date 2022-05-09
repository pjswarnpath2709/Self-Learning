#include <bits/stdc++.h>
using namespace std;

int findMinimumCost(string str)
{
    // odd condition
    if (str.length() % 2 == 1)
    {
        return -1;
    }
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '{')
        {
            st.push(ch);
        }
        else
        {
            // ch is closed brace
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
    }
    // stack contains invalid expresion now
    int a = 0, b = 0;
    while (!st.empty())
    {
        if (st.top() == '{')
        {
            a++;
        }
        else
        {
            b++;
        }
        st.pop();
    }
    int ans = (a + 1) / 2;
    ans += (b + 1) / 2;
    return ans;
}

int main()
{

    return 0;
}