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
// naive approach will be for each element finding perfect match
vector<vi> threeMethod3(vi &vec, int target)
{
    vector<vi> ansVec;
    for (int i = 0; i < vec.size() - 2; i++)
    {
        if (i == 0 || (i > 0 && vec[i] != vec[i - 1]))
        {
            for (int j = i + 1; j < vec.size() - 1; j++)
            {
                if (vec[j] != vec[j + 1])
                {
                    for (int k = j + 1; k < vec.size(); k++)
                    {
                        if (k == vec.size() - 1 || (k < vec.size() - 1 && vec[k] != vec[k + 1]))
                            if (vec[i] + vec[j] + vec[k] == target) // we got the asswer
                            {
                                vi ans;
                                ans.pb(vec[i]);
                                ans.pb(vec[j]);
                                ans.pb(vec[k]);
                            }
                    }
                }
            }
        }
    }
}
// another efficent approach will be using hash table
vector<vi> threeMethod2(vi &vec, int target)
{
    vector<vi> ansVec;
    //this code will use the method of hashing we will use a set
    set<int> s;
    for(int i=0;i<vec.size()-2;i++){
        
    }

}
// another approach will be using two sum approach
vector<vi> threeSumMethod1(vi &vec, int target) // method one uses two pinter approach
{
    sort(vec.begin(), vec.end()); // sort the whole array first
    vector<vi> ansVec;
    if (vec.size() < 3) // if size is lesser than 3 just return
    {
        return ansVec;
    }
    for (int i = 0; i < vec.size() - 2; i++) // at last we need atleast two elements so the loop runs till n-2 only
    {
        if (i == 0 || (i > 0 && vec[i] != vec[i + 1])) // this condition is important
        {
            int low = i + 1;
            int high = vec.size() - 1;
            while (low < high)
            {
                if (vec[low] + vec[high] == target - vec[i])
                {
                    vi ans;
                    ans.pb(vec[low]);
                    ans.pb(vec[high]);
                    ans.pb(vec[i]);
                    ansVec.pb(ans);
                    while (low < high && vec[low] == vec[low + 1]) // to remove all duplicates
                        low++;
                    while (low < high && vec[high] == vec[high - 1]) // to remove all duplicates
                        high--;
                    low++;
                    high--;
                }
                else if (vec[low] + vec[high] > target - vec[i]) // if greater than ,we have to reduce the of high
                {
                    high--;
                }
                else // if lesser we have to increase the value of low
                {
                    low++;
                }
            }
        }
    }
    return ansVec;
}
vector<vi> threeSum(vi &nums)
{
    return threeSumMethod1(nums, 0);
}
int main()
{
    int n;
    cin >> n;
    vi vec(n);
    in_vector(vec, n);
    vector<vi> ansVec = threeSum(vec);
    for (int i = 0; i < ansVec.size(); i++)
    {
        printVec(ansVec[i]);
    }
    return 0;
}