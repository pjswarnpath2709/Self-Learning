#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define pll pair<long long, long long>
#define all_vec vec.begin(), vec.end()
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
long long fact(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
        return n * fact(n - 1);
}
int printRank(string &s)
{
    int n = s.size();
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = 0;
    }
    int mul = fact(n);
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i + 1; j < s.length(); j++)
        {
            if (s[j] < s[i])
            {
                temp[i]++;
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        mul /= (n - i);
        ans += temp[i] * mul;
    }
    return ans + 1;
}
int printLexiographicalRank(string &str)
{
    int rank = 1;
    int n = str.size();
    int mul = fact(n);
    int count[256];
    for (int i = 0; i < 256; i++)
    {
        count[i] = 0;
    }
    for (int i = 1; i < 256; i++)
    {
        count[i] = count[i] + count[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        mul = mul / (n - i);
        rank = rank + count[str[i] - 1] * mul;

        for (int j = str[i]; j < 256; j++)
        {
            count[j]--;
        }
    }
    return rank;
}
int main()
{
    string s;
    cin >> s;
    cout << printLexiographicalRank(s) << "\n";

    return 0;
}