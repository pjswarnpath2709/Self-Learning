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
void in_array(T *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
template <class T>
void print_array(T *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
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
void in_matrix(T **matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }
}
template <class T>
void out_matrix_fun(T **matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << matrix[i][j] << " ";
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
ll power_function(int n,int power){
    if(n==0){
        return 0;
    }if(power==0){
        return 1;
    }if(power==1){
        return n;
    }if(power%2==0){
        return power_function(n*n,power/2);
    }else{
        return n * power_function(n*n,(power-1)/2);
    }

}
int nextGreaterElement(int m)
{
    string s = to_string(m);
    int n = s.length();
    int indx = 0; // first dip
    for (int i = n - 2; i >= 0; i--)
    {
        if (!(s[i]-'0' > s[i + 1] - '0'))
        {
            // here we find the first dip
            indx = i;
            break;
        }
    }
    if (indx < 0)
    {
        return -1;
    }
    // after finding the first dip we will find the potential swap
    int alter_indx;
    for (int j = indx + 1; j < n; j++)
    {
        if ((s[j] - '0') > s[indx] - '0')
        {
            alter_indx = j;
        }
    }
    // now swap the potential index with alter index
    swap(s[indx], s[alter_indx]);
    // cout<<s<<"\n";
    reverse(s.begin() + indx + 1, s.end());
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int multiply=s[i]-'0';
        // cout<<multiply<<"\n";
        ans += (multiply) * power_function(10, n -1 - i);
        // cout<<ans<<"\n";
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << nextGreaterElement(n) << "\n";

    return 0;
}