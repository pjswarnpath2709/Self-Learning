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
// this function returns height if balanced else it returns -1
int chkBBT(btnode *root)
{

    if (root == nullptr)
    {
        return 0;
    }
    int lh = chkBBT(root->left);
    if (lh == -1)
        return -1;
    int rh = chkBBT(root->right);
    if (rh == -1)
        return -1;

    if (abs(lh - rh) > 1)
        return -1;

    return 1 + max(lh, rh);
}

// this function returns true or false and use the function geth height
bool isBalanced(btnode *root)
{
    if (root == nullptr)
        return true;

    int lh = getheight(root->left);
    int rh = getheight(root->right);

    return (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right));
}