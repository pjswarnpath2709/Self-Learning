#define umap unordered_map
#define vi vector<int>
#define vll vector<long long>
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
template <class T>
void printVec(vector<T> &vec)
{
    for (T i : vec)
    {
        cout << i << " ";
    }
    cout << "\n";
}
string FirstNonRepeating(string A)
{
    umap<char, int> count;
    queue<int> qt;
    string ans = "";

    for (int i = 0; i < A.length(); i++)
    {
        char ch = A[i];

        // increase the count of ch
        count[ch]++;

        // queue mein push karo
        qt.push(ch);

        while (!qt.empty())
        {
            if (count[qt.front()] > 1)
            {
                // repeating character hai nahi chaiye
                qt.pop();
            }
            else
            {
                // non repeating character mil gaya
                ans.push_back(qt.front());
                break;
            }
        }

        // if the queue is empty
        if (qt.empty())
        {
            ans += '#';
        }
    }
}

int main()
{
    ll n;
    cin >> n;
    vll vec(n);
    in_vector(vec, n);

    return 0;
}