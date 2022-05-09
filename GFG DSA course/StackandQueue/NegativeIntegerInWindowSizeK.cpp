// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k);

// Driver program to test above functions
int main()
{
    long long int t, i;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    deque<long long int> dq;
    vector<long long> ans;
    int negative = -1;

    long long i = 0;
    long long j = 0;

    while (j < N)
    {
        long long _number = A[j];
        if (_number < 0)
        {
            dq.push_back(_number);
        }
        if (j - i + 1 < K)
        {
            j++;
        }
        else
        {
            long long _ans = (!dq.empty()) ? dq.front() : 0;
            ans.push_back(_ans);

            if (dq.front() == A[i])
            {
                dq.pop_front();
            }
            i++;
            j++;
        }
    }
    return ans;
}