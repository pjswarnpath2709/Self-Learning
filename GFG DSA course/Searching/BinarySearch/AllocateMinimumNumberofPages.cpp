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
bool isPossible(vi &vec, int barrier, int student)
{
    int StuCnt = 0;
    int allocatedPages = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] > barrier)
            return false;
        if (vec[i] + allocatedPages > barrier)
        {
            StuCnt++;
            allocatedPages = vec[i];
        }
        else
        {
            allocatedPages += vec[i];
        }
    }

    if (StuCnt < student)
    {
        return true;
    }
    return false;
}
int books(vi &vec, int student)
{
    if(student>vec.size()) return -1;
    int low = vec[0];
    int high = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        high += vec[i];
        low = min(low, vec[i]);
    }
    int res = -1;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (isPossible(vec, mid, student))
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low; // can also return res
}
int main()
{
    int n;
    cin>>n;
    vi vec(n);
    in_vector(vec,n);
    int students;
    cin>>students;
    cout<<books(vec,students)<<"\n";

    return 0;
}