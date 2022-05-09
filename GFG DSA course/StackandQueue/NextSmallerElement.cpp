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

vll nextSmallerElement(vll &vec, ll n)
{
    stack<ll> st;
    st.push(-1);
    vll ans(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        // agar current element se chota element stack mein
        // present hai then that is answer else remove till answer is not found
        while (st.top() >= vec[i])
        {
            st.pop();
        }
        ans[i] = st.top();
        // store the current element int he stack
        st.push(vec[i]);
    }
    return ans;
}
vll previousSmallerElement(vll &vec, ll n)
{
    stack<ll> st;
    st.push(-1);
    vll ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        // agar current element se chota element stack mein
        // present hai then that is answer else remove till answer is not found
        while (st.top() >= vec[i])
        {
            st.pop();
        }
        ans[i] = st.top();
        // store the current element int he stack
        st.push(vec[i]);
    }
    return ans;
}
int main()
{
    ll n;
    cin >> n;
    vll vec(n);
    in_vector(vec, n);
    vll ans = nextSmallerElement(vec, n);
    printVec(ans);
    return 0;
}