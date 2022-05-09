#include <bits/stdc++.h>
using namespace std;
// reverse the array
void reverseArray(int vec[], int low, int high)
{
    if (low < high)
    {
        swap(vec[low++], vec[high--]);
        reverseArray(vec, low, high);
    }
}
// chk for the palndrome
bool isPalindrome(string &s, int low, int high)
{
    if (low >= high)
    {
        return true;
    }
    if (s[low] != s[high])
    {
        return false;
    }
    else
    {
        return isPalindrome(s, low + 1, high - 1);
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    reverseArray(arr, 0, n - 1);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << "\n";
    string s;
    cin >> s;
    cout << isPalindrome(s, 0, s.length()-1) << "\n";
    return 0;
}