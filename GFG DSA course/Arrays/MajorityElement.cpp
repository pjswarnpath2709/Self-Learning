#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define mset multiset
#define uset unordered_set
#define umap unordered_map
#define nline "\n"
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

/*---------------------------------------------------------------------------------------------------------------*/
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
/*------------------------------------------------------------------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }
void _print(bool t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{

    cerr
        << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
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
template <class T>
void print_matrix(T **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j];
        }
        cout << "\n";
    }
}
template <class T>
void in_vector(vector<T> &vec, ll n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
}
void shift(vi &vec, int l, int r)
{
    reverse(vec.begin() + l, vec.begin() + r + 1);
    reverse(vec.begin() + l, vec.begin() + r);
}
bool is_sorted(vll &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] > vec[i + 1])
        {
            return false;
        }
    }
    return true;
}

/*------------------------------------------------------------------------------------------------------------------------*/
// naive approach-->O(n*n)
// traverse through thge whole array and take the count of every element if there is a element whose
// if there is an element whose count is greater than floor(n/2) then simply return or else print -1
int MajorityElementNaive(vi &vec)
{
    int n = vec.size();
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (vec[i] == vec[j])
                count++;
        }
        if (count > n / 2)
            return vec[i];
    }
    return -1;
}
// efficient solution
// Maore's voting algorithm
/*
ajeeb sa algorithm hai kuch jyada samjh nahi aya
but still it has two phase,the first phase is to find index of majority element and
second is to find that is the majority element is really the majority element or not
if not thgen simply return -1 else return the index
*/

int MoareMajorityElement(vi &vec)
{
    int n = vec.size();
    int res_indx = 0;
    int count = 1;
    // phase one of the maore algorithm
    for (int i = 1; i < n; i++)
    {
        if (vec[i] == vec[res_indx])
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count == 0)
        {
            count = 1;
            res_indx = i;
        }
    }
    // phase two of the moare algorithm
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (vec[res_indx] == vec[i])
        {
            count++;
        }
    }
    if (count > n / 2)
        return res_indx;
    return -1;
}
void solve()
{
    int n;
    cin >> n;
    vi vec(n);
    in_vector(vec, n);
    cout << MajorityElementNaive(vec) << "\n";
    cout << MoareMajorityElement(vec) << "\n";
}
/*
An Element  is called majority if it appear strictly more than N/2 times in the array
*/
/*------------------------------------------------------------------------------------------------------------------------*/
int main()
{
    fastio();
    solve();
    return 0;
}
