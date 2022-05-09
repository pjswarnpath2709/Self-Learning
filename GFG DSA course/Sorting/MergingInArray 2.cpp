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

void merge(vll &vec, int low, int mid, int high)
{
    //size phase
    int n1 = mid - low + 1;
    int n2 = high - mid;
    // cpy phase
    vll left(n1);
    vll right(n2);
    for (int i = 0; i < n1; i++)
        left[i] = vec[low + i];
    for (int i = 0; i < n2; i++)
        right[i] = vec[mid + 1 + i];
    // decision phase
    int i = 0, j = 0, k = low; //yaha dhyan rakhna hain
    while (i < n1 && j < n2)
    {
        if (left[i] < right[j])
            vec[k++] = left[i++];
        else
            vec[k++] = right[j++]++;
    }
    while (i < n1)
        vec[k++] = left[i++];
    while (j < n2)
        vec[k++] = right[j++];
    // memory free phase
    left.clear();
    right.clear();
    // return phase
    return;
}
int main()
{
    ll n;
    cin >> n;
    vll vec(n);
    in_vector(vec, n);
    merge(vec, 0, 2, n - 1);
    printVec(vec);

    return 0;
}