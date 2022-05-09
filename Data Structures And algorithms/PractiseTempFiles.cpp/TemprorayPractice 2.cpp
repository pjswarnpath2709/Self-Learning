//
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define pb push_back
#define ppb pop_back
#define nline "\n"
/*------------------------------------------------------------------------------------------------------------------------*/
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
/*------------------------------------------------------------------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------------------------------------------------------------------------*/
template <class T>
void printVec(vector<T> &vec)
{
    for (T i : vec)
    {
        cout << i;
    }
    cout << "\n";
}
ll min_of_three(ll a, ll b, ll c)
{
    return min(a, min(b, c));
}
/*------------------------------------------------------------------------------------------------------------------------*/

int main()
{
    fastio();

    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        if ((2 * k + 1) > n)
        {
            cout << "NO\n";
        }
        else
        {
            string a;
            string b;
            for (int i = 0; i < k; i++)
            {
                a = a + s[i];
            }
            for (int i = n - 1; i >= n - k; i--)
            {
                b = b + s[i];
            }
            if (a == b)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }

    return 0;
}