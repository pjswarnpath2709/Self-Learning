#include <bits/stdc++.h>
using namespace std;

int getMax(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] >= arr[i])
            {
                curr += arr[i];
            }
            else
                break;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] >= arr[i])
            {
                curr += arr[i];
            }
            else
            {
                break;
            }
        }
        res = max(res, curr);
    }
    return res;
}
// efficent approach
int getMaxEfficent(int arr[], int n)
{
    stack<int> st;
    int res = 0;
    int tp;
    int curr;
    for (int i = 0; i < n; i++)
    {
        while (st.empty() == false && arr[st.top()] >= arr[i])
        {
            tp = st.top();
            st.pop();
            curr = arr[tp] * (st.empty() ? i : i - st.top() - 1);
            res = max(res, curr);
        }
        st.push(i);
    }
    while (st.empty() == false)
    {
        tp = st.top();
        st.pop();
        curr = arr[tp] * (st.empty() ? n : n - st.top() - 1);
        res = max(res, curr);
    }

    return res;
}
int main()
{
}