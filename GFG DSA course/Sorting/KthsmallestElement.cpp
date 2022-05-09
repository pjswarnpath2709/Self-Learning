#define vi vector<int>
#define vll vector<long long>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
int lomutoPartition(vi &vec, int low, int high)
{
    int key = vec[high];
    int i = low - 1; // from 0 to i all the elements are smaller then the pivot
    for (int j = low; j <= high; j++)
    {
        if (vec[j] < key)
        {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[high], vec[i + 1]);
    return i + 1;
}

int kthSmallestElement(vi &vec, int k)
{
    int n = vec.size();
    int low = 0;
    int high = n - 1;
    // sort of binary search technique
    while (low <= high)
    {
        int p = lomutoPartition(vec, low, high);
        if (p == k - 1)
        {
            return vec[p];
        }
        else if (p > k - 1)
        {
            high = p - 1;
        }
        else
        {
            low = p + 1;
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vi vec(n);
        in_vector(vec, n);
        cout << kthSmallestElement(vec, k) << "\n";
    }
    return 0;
}