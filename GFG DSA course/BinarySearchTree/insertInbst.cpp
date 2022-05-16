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

bstnode *insertBST_recurrsive(bstnode *root, int key)
{
    if (root == nullptr)
    {
        root = new bstnode(key);
        return root;
    }
    if (root->data < key)
    {
        // right mein jana hai
        root->right = insertBST_recurrsive(root->right, key);
    }
    else if (root->data > key)
    {
        // left mein jana hai
        root->left = insertBST_recurrsive(root->left, key);
    }
    return root;
}

bstnode *insertBST_iterative(bstnode *root, int key)
{
    if (root == nullptr)
    {
        return new bstnode(key);
    }

    bstnode *root_to_return = root;
    bstnode *prev = root;

    bool left = false;

    while (root != nullptr)
    {
        if (root->data > key)
        {
            // left mein move karo
            prev = root;
            root = root->left;
            left = true;
        }
        else if (root->data < key)
        {
            prev = root;
            root = root->right;
            left = false;
        }
    }
    if (left)
    {
        prev->left = new bstnode(key);
    }
    else
    {
        prev->right = new bstnode(key);
    }
    return root_to_return;
}

int main()
{

    return 0;
}