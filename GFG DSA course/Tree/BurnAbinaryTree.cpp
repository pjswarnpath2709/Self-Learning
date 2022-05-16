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

int res = 0;
int burnTime(btnode *root, int leaf, int &dist)
{

    if (root == nullptr)
    {
        return 0;
    }

    if (root->data == leaf)
    {
        dist = 0;
        return 1;
    }
    int leftdist = -1;
    int rightdist = -1;
    int leftheight = burnTime(root->left, leaf, leftdist);
    int rightheight = burnTime(root->right, leaf, rightdist);

    if (leftdist != -1)
    {
        dist = leftdist + 1;
        res = max(res, dist + rightheight);
    }
    else if (rightdist != -1)
    {
        dist = rightdist + 1;
        res = max(res, dist + leftheight);
    }
    return max(leftheight, rightheight) + 1;
}
int main()
{

    btnode *root = new btnode(10);
    root->left = new btnode(20);
    root->right = new btnode(30);
    root->left->left = new btnode(40);
    root->left->right = new btnode(50);
    root->left->left->left = new btnode(60);
    root->left->left->left->left = new btnode(70);
    int dist = -1;
    int leaf = 50;
    burnTime(root, leaf, dist);
    cout << res;
    return 0;
}