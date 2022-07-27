

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k)
    {
        priority_queue<int> max_heap;
        // first build the max heap of the first k elements
        for (int i = l; i < l + k; i++)
        {
            max_heap.push(arr[i]);
        }

        // second for loop
        for (int i = l + k; i <= r; i++)
        {
            if (arr[i] < max_heap.top())
            {
                max_heap.pop();
                max_heap.push(arr[i]);
            }
        }

        return max_heap.top();
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (auto &ele : arr)
        {
            cin >> ele;
        }
        int k;
        cin >> k;
        Solution obj;
        cout << obj.kthSmallest(arr, 0, n - 1, k) << "\n";
    }

    return 0;
}