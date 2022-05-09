#define vi vector<int>
#define vll vector<long long>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
void DutchFlagAlgo(vi &vec, int n)
{
    int low = 0;      // from zero to low-1 there will be zero
    int mid = 0;      // from low+1 to mid there will be 1
    int high = n - 1; // from high+1 to n-1 there will be two
    while (mid <= high)
    {
        if (vec[mid] == 0)
        {
            swap(vec[low], vec[mid]);
            low++;
            mid++;
        }
        else if (vec[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(vec[mid], vec[high]);
            high--;
        }
    }
    printVec(vec);
}
int main()
{
    int n;
    cin >> n;
    vi vec(n);
    in_vector(vec, n);
    DutchFlagAlgo(vec,n);

    return 0;
}