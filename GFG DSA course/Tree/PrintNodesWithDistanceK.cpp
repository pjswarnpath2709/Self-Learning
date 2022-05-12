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

void printKNode(btnode *root, int k, int height)
{
    if (k >= 0 && k <= height)
    {
        if (root == nullptr)
        {
            return;
        }
        else if (k == 0)
        {
            cout << root->data << " ";
        }
        else
        {
            printKNode(root->left, k - 1, height);
            printKNode(root->right, k - 1, height);
        }
    }
}

int getheight(btnode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + max(getheight(root->left), getheight(root->right));
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

    int height = getheight(root);
    printKNode(root, height - 1, height);
    return 0;
}