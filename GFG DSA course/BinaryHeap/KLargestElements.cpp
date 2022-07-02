

#include <bits/stdc++.h>
using namespace std;

vector<int> getKLargestElements(vector<int> &vec, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push(vec[i]);
    }

    for (int i = k; i < vec.size(); i++)
    {
        if (vec[i] > pq.top())
        {
            pq.pop();
            pq.push(vec[i]);
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
int main()
{

    return 0;
}