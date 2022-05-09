#include <bits/stdc++.h>
using namespace std;
bool isgood(stack<char> &st, char c)
{
    if (st.empty())
    {
        return false;
    }
    if ((st.top() == '(' && c == ')') || (st.top() == '{' && c == '}') || (st.top() == '[' && c == ']'))
    {
        return true;
    }

    return false;
}
bool regularBracket(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (isgood(st, s[i]))
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    if (st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int n;
    cin >> n;
    while (n)
    {
        string s;
        cin >> s;
        if (regularBracket(s))
        {
            cout << "YES"
                 << "\n";
        }
        else
        {
            cout << "NO"
                 << "\n";
        }
        n--;
    }

    return 0;
}