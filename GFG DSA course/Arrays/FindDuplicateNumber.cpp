// problem link::--> leetcode.com/problems/find-the-duplicate-number/
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
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
int findDuplcate(vi &vec, int n)
{
    int slow = vec[0];
    int fast = vec[0];
    do
    {
        slow = vec[slow];      // move one step
        fast = vec[vec[fast]]; // move two steps
    } while (slow != fast);
    fast = vec[0]; // move fast to start
    while (slow != fast)
    {
        slow = vec[slow]; // move one step
        fast = vec[fast]; // move one step
    }

    return slow;
}
int main()
{
    int n;
    cin >> n;
    vi vec(n);
    in_vector(vec, n);

    return 0;
}