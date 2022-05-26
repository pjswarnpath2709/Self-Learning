#include <bits/stdc++.h>
using namespace std;

struct bstnode
{
    int data;
    bstnode *left;
    bstnode *right;
    bstnode(int key)
    {
        this->data = key;
        this->right = nullptr;
        this->left = nullptr;
    }
};

bool chkBST(bstnode *root, int mini, int maxi)
{
    if (root == nullptr)
    {
        return true;
    }
    return (root->data <= maxi && root->data >= mini) &&
           chkBST(root->left, mini, root->data) &&
           (root->right, root->data, maxi);
}

int main()
{
    bstnode *root = new bstnode(4);
    root->left = new bstnode(2);
    root->right = new bstnode(5);
    root->left->left = new bstnode(1);
    root->left->right = new bstnode(3);

    if (chkBST(root, INT_MIN, INT_MAX))
        cout << "Is BST\n";
    else
        cout << "Not a BST\n";

    return 0;
}