#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &vec)
{
    for (auto it : vec)
        cout << it << " ";
    cout << "\n";
}

void nextSmallerAndPreviousSmallerInSinglePass(vector<int> arr, int n)
{
    vector<int> next(n, n);
    vector<int> prev(n, -1);

    // -1 means ki previous smaller element exists hi nahi karta
    // n means ki next smaller element exits hi nahi karta
    stack<int> st;
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() and (i == n || arr[i] <= arr[st.top()]))
        {
            int calculatingIndex = st.top();
            st.pop();
            int rightSmallerElement = i;
            int leftSmallerIndex = st.empty() ? -1 : st.top();
            // do calculations
            next[calculatingIndex] = rightSmallerElement;
            prev[calculatingIndex] = leftSmallerIndex;
        }
        st.push(i);
    }
    print(prev);
    print(next);
}

void nextGreaterAndPreviousGreaterInSinglePass(vector<int> arr, int n)
{
    vector<int> next(n, n);
    vector<int> prev(n, -1);

    // -1 means ki previous smaller element exists hi nahi karta
    // n means ki next smaller element exits hi nahi karta
    stack<int> st;
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() and (i == n || arr[i] >= arr[st.top()]))
        {
            int calculatingIndex = st.top();
            st.pop();
            int rightGreaterElement = i;
            int leftGreaterIndex = st.empty() ? -1 : st.top();
            // do calculations
            next[calculatingIndex] = rightGreaterElement;
            prev[calculatingIndex] = leftGreaterIndex;
        }
        st.push(i);
    }
    print(prev);
    print(next);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr)
        cin >> it;
    nextSmallerAndPreviousSmallerInSinglePass(arr, n);
    nextGreaterAndPreviousGreaterInSinglePass(arr ,n);
}