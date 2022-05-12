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
int maxlevel = 0;
void printleft(btnode *root, int level)
{
    if (root == nullptr)
    {
        return;
    }
    if (maxlevel < level)
    {
        cout << root->data << "  ";
        maxlevel = level;
    }
    printleft(root->left, level + 1);
    printleft(root->right, level + 1);
}

void printleftView(btnode *root)
{
    printleft(root, 1);
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

    printleftView(root);

    return 0;
}