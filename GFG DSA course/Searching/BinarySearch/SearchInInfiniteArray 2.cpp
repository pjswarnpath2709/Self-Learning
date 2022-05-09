#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<long long>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
int SimpleBinSearch(vll vec, ll low, ll high, ll value)
{
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (vec[mid] == value)
        {
            return mid;
            if (vec[mid] > value)
            {
                // move left
                high = mid - 1;
            }
            if (vec[mid] < value)
            {
                // move right
                low = mid + 1;
            }
        }
    }
    return -1;
}
int searchInInfiniteArray(vll vec, ll key)
{
    if (vec[0] == key)
    {
        return 0;
    }
    else
    {
        int i = 1;
        while (vec[i] < key)
        {
            i *= 2;
        }
        if (vec[i] == key)
        {
            return i;
        }
        else
        {
            return SimpleBinSearch(vec, i / 2, i, key);
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