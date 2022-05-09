#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

// naive approach
int num_codes(int *arr, int size)
{
    if (size == 1)
    {
        return 1;
    }
    if (size == 0)
    {
        return 1;
    }
    int output = (num_codes(arr, size - 1)) % MOD;
    if (arr[size - 2] * 10 + arr[size - 1] <= 26)
    {
        output += (num_codes(arr, size - 2)) % MOD;
    }
    return (output) % MOD;
}
// efficient approach
ll num_codes_efficent(ll *arr, ll size, ll *helper)
{
    if (size == 1)
    {
        return 1;
    }
    if (size == 0)
    {
        return 1;
    }
    if (helper[size] > 0)
    {
        ll ans = helper[size];
        return ans;
    }
    ll output = 0;
    if(arr[size-1] != 0) //added this
    	output = (num_codes_efficent(arr, size - 1, helper)) % MOD;
    if (arr[size - 2] * 10 + arr[size - 1] <= 26 && arr[size-2] != 0) //added new condition
    {
        output += (num_codes_efficent(arr, size - 2, helper)) % MOD;
    }
    helper[size] = output % MOD;
    return (output) % MOD;
}
// best efficent approach
ll num_code_iterative(ll *input, ll size)
{
    ll *output = new ll[size + 1];
    output[0] = 1;
    output[1] = 1;
    for (ll i = 2; i <= size; i++)
    {
        output[i] = 0; //added this
        if(input[i-1] != 0) //added this
        	output[i] += output[i - 1];
        if(input[i - 2] * 10 + input[i - 1] <= 26 && input[i-2] != 0 ) //added a new condition
        {
            output[i] += output[i - 2] % MOD;
        }
        output[i] %= MOD;
    }
    ll ans = output[size];
    delete[] output;
    
    return ans%MOD;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        ll *arr = new ll[s.size()];
        ll *helper = new ll[s.size() + 1];
        // memset(helper, -1, (s.size() + 1) * sizeof(int));
        for (ll i = 0; i < s.size(); i++)
        {
            arr[i] = s[i] - '0';
            helper[i] = 0;
        }
        helper[s.size()] = 0;
        cout << num_codes_efficent(arr, s.size(), helper) << "\n";
        delete [] helper;
        // cout<<num_code_iterative(arr,s.size())<<"\n";
    }
    return 0;
}