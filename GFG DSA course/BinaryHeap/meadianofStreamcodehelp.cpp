#include <bits/stdc++.h>
using namespace std;

int signum(int a, int b)
{
    if (a == b)
    {
        return 0;
    }
    else if (a > b)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void callMedian(int element, priority_queue<int> &max_heap, priority_queue<int, vector<int>, greater<int>> &min_heap, int &median)
{
    switch (signum(max_heap.size(), min_heap.size()))
    {
    case 0:
        if (element > median)
        {
            min_heap.push(element);
            median = min_heap.top();
        }
        else
        {
            max_heap.push(element);
            median = max_heap.top();
        }
        break;

    case 1:
        if (element > median)
        {
            min_heap.push(element);
            median = (min_heap.top() + max_heap.top()) / 2;
        }
        else
        {
            min_heap.push(max_heap.top());
            max_heap.pop();
            max_heap.push(element);
            median = (min_heap.top() + max_heap.top()) / 2;
        }

        break;

    case -1:
        if (element > median)
        {
            max_heap.push(min_heap.top());
            ;
            min_heap.pop();
            min_heap.push(element);
            median = (min_heap.top() + max_heap.top()) / 2;
        }
        else
        {
            max_heap.push(element);
            median = (min_heap.top() + max_heap.top()) / 2;
        }

        break;

    default:
        break;
    }
}

vector<int> findMedian(vector<int> &arr, int n)
{
    vector<int> ans;
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int median = 0;
    for (int i = 0; i < n; i++)
    {
        int element = arr[i];
        callMedian(element, max_heap, min_heap, median);
        ans.push_back(median);
    }
    return ans;
}

int main()
{

    return 0;
}