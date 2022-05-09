#include <bits/stdc++.h>
using namespace std;

string reverseString(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);
    }
    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}
int main()
{
    string s;
    cin >> s;
    cout << reverseString(s) << "\n";
    return 0;
}