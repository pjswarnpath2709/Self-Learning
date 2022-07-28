#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    int row;
    int col;
    Node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class MyComp
{
public:
    bool operator()(Node *t1, Node *t2)
    {
        return t1->data > t2->data;
    }
};

int kSorted(vector<vector<int>> &arr, int k, int n)
{
    int mini = INT_MAX;
    int maxi = INT_MIN;

    priority_queue<Node *, vector<Node *>, MyComp> min_Heap;

    for (int i = 0; i < k; i++)
    {
        maxi = max(maxi, arr[i][0]);
        mini = min(mini, arr[i][0]);
        min_Heap.push(new Node(arr[i][0], i, 0));
    }
    int start = mini, end = maxi;

    while (!min_Heap.empty())
    {
        Node *top = min_Heap.top();
        min_Heap.pop();

        mini = top->data;

        if (maxi - mini < end - start)
        {
            start = mini;
            end = maxi;
        }

        if (top->col + 1 < n)
        {
            int data = arr[top->row][top->col + 1];
            int row = top->row;
            int col = top->col + 1;
            maxi = max(maxi, data);
            min_Heap.push(new Node(data, row, col));
        }
        else
        {
            break;
        }
    }

    return end - start + 1;
}

int main()
{

    return 0;
}