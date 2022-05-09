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
bool isPossible(vi &vec, int distance, int &cows)
{
    int prevCord = vec[0];
    int cowCnt = 1;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] - prevCord >= distance)
        {
            cowCnt++;
            prevCord = vec[i];
        }
        if (cowCnt == cows)
            return true;
    }
    return false;
}
int aggresiveCows(vi &vec, int cows)
{
    sort(vec.begin(), vec.end());
    int low = vec[0];
    int high = vec[vec.size() - 1] - vec[0];
    int res = vec[0];
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (isPossible(vec, mid, cows))
        {
            res = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return res;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, cows;
        cin >> n >> cows;
        vi vec(n);
        in_vector(vec, n);
        cout << aggresiveCows(vec, cows) << "\n";
    }

    return 0;
}