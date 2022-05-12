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

int getMax(btnode *root)
{
    if (root == nullptr)
    {
        return INT_MIN;
    }
    else
    {
        return max(root->data, max(getMax(root->left), getMax(root->right)));
    }
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

    cout << getMax(root);

    return 0;
}