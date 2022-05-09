#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define mset multiset
#define uset unordered_set
#define umap unordered_map
#define vi vector<int>
#define vll vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define pll pair<long long, long long>
#define all_vec vec.begin(), vec.end()
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define MOD 1000000007
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

/*
we compare the hash value of the pattern with the hashvalue of text and if the hashvalue of the character
matches with the text's hashvalue then we will compare the indiviaual character of the pattern and the text
hashvalue->it is the sum of every ascii value in the pat

these hash value are calculated by the diffrent hashing functions
*/

bool isGood(string substr, string &pat)
{
    for (int i = 0; i < pat.size(); i++)
    {
        if (pat[i] != substr[i])
        {
            return false;
        }
    }
    return true;
}
// simple hashfunctioning by adding the characters
void printIndexSimpleHash(string txt, string pat)
{
    int j = 0;
    int i = 0;
    int hash = 0;
    for (int i = 0; i < pat.size(); i++)
    {
        hash += pat[i];
    }
    // cout << hash << "\n";
    int currhash = 0;
    while (j < txt.size())
    {
        currhash += txt[j];
        if (j - i + 1 < pat.size())
        {
            j++;
        }
        // now maintain the window size
        else if (j - i + 1 == pat.size())
        {
            // chk for the ans
            if (isGood(txt.substr(i, j - i + 1), pat) && hash == currhash)
            {
                cout << i << " ";
            }

            // remove the calcultaion of the i
            currhash -= txt[i];
            // move the window
            j++;
            i++;
        }
    }
}
#define d 256 // because there are 256 characters in the english letters
void RBSearch(string txt, string pat, int N, int M)
{
    // Compute (d^(M-1))%q
    ll h = 1;
    for (int i = 1; i <= M - 1; i++)
        h = (h * d) % MOD;
    // Compute p and to
    ll p = 0, t = 0;
    for (int i = 0; i < M; i++)
    {
        p = (p * d + pat[i]) % MOD;
        t = (t * d + txt[i]) % MOD;
    }
    for (int i = 0; i <= (N - M); i++)
    {
        // Check for hit
        if (p == t)
        {
            bool flag = true;
            for (int j = 0; j < M; j++)
                if (txt[i + j] != pat[j])
                {
                    flag = false;
                    break;
                }
            if (flag == true)
                cout << i << " ";
        }
        // Compute ti+1 using ti
        if (i < N - M)
        {
            t = ((d * (t - txt[i] * h)) + txt[i + M]) % MOD;
            if (t < 0)
                t = t + MOD;
        }
    }
}
int main()
{
    string txt, pat;
    cin >> txt >> pat;
    RBSearch(txt, pat, txt.size(), pat.size());
    return 0;
}