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
int countAnagramofString(string big, string small)
{
    int n = big.length();
    // we will use mapping , we will prepare the map of the string small
    umap<char, int> mp;
    for (int i = 0; i < small.length(); i++)
    {
        mp[small[i]]++;
    }
    int j = 0;
    int i = 0;
    int counter = 0;
    int map_size = mp.size();
    /*
    now we will use a pattern to note if there exists a anagram.
    first we will decrease the count of element if present in map, if any element decreases it's count to
    zero than it's requirement is fullfilled and we will decrease the size of map,
    the point where the size of map hit zero
    we got our answer.
    Now when we want to remove the calcultaions of i we will chk if big[i] was wheter present in the map, if was then increase it's count
    and if it's count is alreadyzero then increment  it map_size also
    */
    while (j < n)
    {
        char ch = big[j];
        if (mp.find(ch) != mp.end())
        {
            mp[ch]--;
            if (mp[ch] == 0)
            {
                map_size--;
            }
        }
        if (j - i + 1 < small.size())
        {
            j++;
        }
        if (j - i + 1 == small.size())
        {
            //find the answer
            if(map_size==0){
                counter++;
            }
            // remove the calcultions of i
            if (mp.find(big[i]) != mp.end())
            {
                if (mp[big[i]] == 0)
                {
                    map_size++;
                }
                mp[big[i]]++;
            }
            // move the window ahead
            i++;
            j++;
        }
    }
}
int main()
{
    string str1;
    string str2;
    cin >> str1;
    cin >> str2;
    cout << countAnagramofString(str1, str2);

    return 0;
}