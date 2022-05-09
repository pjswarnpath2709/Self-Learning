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
double findMedianSortedArray(vi &vec1, vi &vec2)
{
    if (vec2.size() < vec1.size())
    {
        return findMedianSortedArray(vec2, vec1);
    }
    int n1 = vec1.size();
    int n2 = vec2.size();
    int low = 0;   // minimum number of elements in left side
    int high = n1; // maximum number of elements in right side
    while (low <= high)
    {
        int cut1 = (low + high) >> 1;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int left1 = (cut1 == 0) ? INT_MIN : vec1[cut1 - 1]; // left element of the vector 1
        int left2 = (cut2 == 0) ? INT_MIN : vec2[cut2 - 1]; // left element of the vector 2

        int right1 = (cut1 == n1) ? INT_MAX : vec1[cut1]; // right element of the vector 1
        int right2 = (cut2 == n2) ? INT_MAX : vec2[cut2]; // right element of the vector 2

        if (left1 <= right2 && left2 <= right1)
        {
            if ((n1 + n2) % 2 == 0)
            {
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }
            else
            {
                return max(left1, left2);
            }
        }
        else if (left1 > right2)
        { // move more left
            high = cut1 - 1;
        }
        if (left2 > right1)
        {
            // move right
            low = cut1 + 1;
        }
    }
    return 0.0;
}
int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    vi vec1(n1), vec2(n2);
    in_vector(vec1, n1);
    in_vector(vec2, n2);
    cout << findMedianSortedArray(vec1, vec2) << "\n";

    return 0;
}