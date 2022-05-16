

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
        this->left = nullptr;
        this->right = nullptr;
    }
};
bool searchBST(bstnode *root, int key)
{
    if (root == nullptr)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }
    if (root->data < key)
    {
        return searchBST(root->right, key);
    }
    else
    {
        return searchBST(root->left, key);
    }
}

bool searchBSTiterative(bstnode *root, int key)
{
    while (root != nullptr)
    {
        if (root->data == key)
        {
            return true;
        }
        else if (root->data > key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return false;
}
int main()
{
    bstnode *root = new bstnode(15);
    root->left = new bstnode(5);
    root->left->left = new bstnode(3);
    root->right = new bstnode(20);
    root->right->left = new bstnode(18);
    root->right->left->left = new bstnode(16);
    root->right->right = new bstnode(80);
    int x = 16;

    if (searchBST(root, x))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    if (searchBSTiterative(root, x))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    return 0;
}