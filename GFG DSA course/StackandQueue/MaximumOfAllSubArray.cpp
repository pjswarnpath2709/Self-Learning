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

int main()
{
    int n, k;
    cin >> n >> k;
    vi vec(n);
    in_vector(vec, n);

    printVec(vec);

    int j = 0;
    int i = 0;
    deque<int> dq;

    while (j < n)
    {
        // operations to be done on deque
        int _number = vec[j];
        if (dq.empty())
        {
            dq.push_back(_number);
        }
        else
        {
            while (dq.back() < _number && !dq.empty()) // this condition is important
            {
                dq.pop_back();
            }
            dq.push_back(_number);
        }

        if (j - i + 1 < k)
        {
            j++;
        }
        else
        {
            // now the desired size is acchied so get the answer , move the window and update the deque
            int ans = dq.front();
            cout << ans << " ";

            // remove the first element if it is the first element of the window
            int ithElement = vec[i];
            if (dq.front() == ithElement)
            {
                dq.pop_front();
            }
            i++;
            j++;
        }
    }

    return 0;
}