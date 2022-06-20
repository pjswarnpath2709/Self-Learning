#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *left, *right;

    node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

bool getPath(node *root, vector<int> &arr, int x)
{
    if (!root)
        return false;

    arr.push_back(root->data);
    if (root->data == x)
    {
        return true;
    }

    if (getPath(root->right, arr, x) || getPath(root->left, arr, x))
    {
        return true;
    }
    arr.pop_back();
    return false;
}

int main()
{

    struct node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(6);
    root->left->right->right = new node(7);
    root->right = new node(3);

    vector<int> arr;

    bool res;
    res = getPath(root, arr, 7);

    cout << "The path is ";
    for (auto it : arr)
    {
        cout << it << " ";
    }

    return 0;
}
