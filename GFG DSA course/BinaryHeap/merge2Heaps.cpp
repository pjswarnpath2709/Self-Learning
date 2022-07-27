#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void maxHeapify(vector<int> &vec, int index, int size)
    {
        int leftidx = 2 * index + 1;
        int rightidx = 2 * index + 2;
        int greatest = index;

        if (leftidx < size && vec[leftidx] > vec[greatest])
        {
            greatest = leftidx;
        }
        if (rightidx < size && vec[rightidx] > vec[greatest])
        {
            greatest = rightidx;
        }
        if (greatest != index)
        {
            swap(vec[greatest], vec[index]);
            maxHeapify(vec, greatest, size);
        }
    }

    void buildheap(vector<int> &vec, int size)
    {
        for (int i = (size - 2) / 2; i >= 0; i--)
        {
            maxHeapify(vec, i, size);
        }
    }

public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {
        for (int i = 0; i < b.size(); i++)
        {
            a.push_back(b[i]);
        }
        buildheap(a, n + m);
        return a;
    }
};

int main()
{

    return 0;
}