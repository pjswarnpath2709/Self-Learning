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

void verticalSum(bstnode *root, int dist, map<int, int> &mp)
{
    if (root == nullptr)
    {
        return;
    }
    // left ke liye call karo
    verticalSum(root->left, dist - 1, mp);
    mp[dist] += root->data;
    verticalSum(root->right, dist + 1, mp);
}

void printVSum(bstnode *root)
{
    map<int, int> mp;
    verticalSum(root, 0, mp);
    for (auto sum : mp)
    {
        cout << sum.second << " ";
    }
}

int main()
{

    bstnode *root = new bstnode(10);
    root->left = new bstnode(20);
    root->right = new bstnode(50);
    root->left->left = new bstnode(30);
    root->left->right = new bstnode(40);

    printVSum(root);
    cout << "\n";
    return 0;
}