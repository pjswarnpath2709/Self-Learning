#include <bits/stdc++.h>
using namespace std;

vector<int> sortKsortedArray(vector<int> &vec, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq; // syntax to make min heap
    // step 1: insert all the k elemets into the priority_queue
    for (int i = 0; i < k; i++)
    {
        pq.push(vec[i]);
    }
    // now traverse the k+1 to n-1 array and start processing the array
    int index = 0;
    for (int i = k; i < vec.size(); i++)
    {

        vec[index] = pq.top();
        index++;
        pq.pop();
        pq.push(vec[i]);
    }

    // now the k+1 to n-1 elements will be in the priority queue so
    while (pq.empty() == false)
    {
        vec[index++] = pq.top();
        pq.pop();
    }
    return vec;
}

int main()
{
    return 0;
}