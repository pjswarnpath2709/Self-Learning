

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;

    unordered_map<char, int> mp;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
    }

    int maxi = 0;
    for (auto ele : mp)
    {
        maxi = max(ele.second, maxi);
    }
    cout << maxi << "\n";
    return 0;
}