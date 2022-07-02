

#include <bits/stdc++.h>
using namespace std;

int getTheMaximumProducts(vector<int> &vec, int &sum)
{
    priority_queue<int> pq(vec.begin(), vec.end());
    int res = 0;
    while (pq.top() <= sum)
    {
        res++;
        sum -= pq.top();
        pq.pop();
    }
}

int main()
{

    return 0;
}