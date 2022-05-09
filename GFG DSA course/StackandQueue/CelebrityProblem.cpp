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

bool knows(int a, int b, vector<vector<int>> &M)
{
    if (M[a][b] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> st;
    // step 1: push all the elements inside the stack
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }
    // step 2: chk for every two elements till stack size is not equal to 1
    while (st.size() > 1)
    {
        int num1 = st.top();
        st.pop();
        int num2 = st.top();
        st.pop();

        if (knows(num1, num2, M))
        {
            st.push(num2);
        }
        else
        {
            st.push(num1);
        }
    }
    // step 3: jab stack mein single element bacha hoga tab fir se rechk karo

    // row check
    bool rowChk = false;
    int zeroCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[st.top()][i] == 0)
        {
            zeroCount++;
        }
    }
    if (zeroCount == n)
    {
        rowChk = true;
    }
    // column check
    bool colChk = false;
    int oneCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[i][st.top()] == 1)
        {
            oneCount++;
        }
    }
    if (oneCount == n - 1)
    {
        colChk = true;
    }
    if (rowChk && colChk)
    {
        return st.top();
    }
    else
    {
        return -1;
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