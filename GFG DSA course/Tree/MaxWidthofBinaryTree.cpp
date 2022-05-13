#include <bits/stdc++.h>
using namespace std;

struct btnode
{
    int data;
    btnode *left;
    btnode *right;

    btnode(int key)
    {
        this->data = key;
        this->left = nullptr;
        this->right = nullptr;
    }
};

int maxWidth(btnode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    queue<btnode *> qt;
    qt.push(root);
    int res = 0;
    while (!qt.empty())
    {
        int count = qt.size();
        res = max(res, count);
        for (int i = 0; i < count; i++)
        {
            btnode *curr = qt.front();
            qt.pop();
            if (curr->left)
            {
                qt.push(curr->left);
            }
            if (curr->right)
            {
                qt.push(curr->right);
            }
        }
    }

    return res;
}

int main()
{
    btnode *root = new btnode(10);
    root->left = new btnode(20);
    root->right = new btnode(30);
    root->left->left = new btnode(40);
    root->left->right = new btnode(50);
    root->right->left = new btnode(60);
    root->right->right = new btnode(70);

    cout << maxWidth(root) << "\n";

    return 0;
}