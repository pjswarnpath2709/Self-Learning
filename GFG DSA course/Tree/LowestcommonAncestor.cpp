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

bool findPath(btnode *root, int n, vector<btnode *> &path)
{
    if (root == nullptr)
    {
        return false;
    }
    path.push_back(root);
    if (root->data == n)
    {
        return true;
    }

    bool t1 = findPath(root->left, n, path);
    bool t2 = findPath(root->right, n, path);

    if (t1 || t2)
    {
        return true;
    }

    path.pop_back();
    return false;
}

btnode *lca(btnode *root, int n1, int n2)
{
    vector<btnode *> path1, path2;

    if (!findPath(root, n1, path1) || !findPath(root, n2, path2))
    {
        return nullptr;
    }

    for (int i = 0; i < path1.size() - 1 && i < path2.size() - 1; i++)
    {
        if (path1[i + 1] != path2[i + 1])
        {
            return path1[i];
        }
    }

    return nullptr;
}

/*

this assumes that both the node is definitely present in the binary tree ,
if any of the one is missing then it will return a wrong answer


4 cases need to be considered in this efficient method

case a) when the current node  is null simply return *NULL*

case b) when the current node is the node of n1 or n2 , then simply returns the
*ADDRESS OF CURRENT NODE* only

case c) when the current node has lca present on either of its subtree
then simply returns that *LCA* only

case d) when both the subtree contains a lca then current node is the real lca
hence we got the answer and return the *CURRENT NODE* as the answer

*/

btnode *lcaEfficient(btnode *root, int n1, int n2)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    btnode *lca1 = lcaEfficient(root->left, n1, n2);
    btnode *lca2 = lcaEfficient(root->right, n1, n2);

    if (lca1 != nullptr && lca2 != nullptr)
    {
        return root;
    }
    if (lca1 != nullptr)
    {
        return lca1;
    }
    else
    {
        return lca2;
    }
}

int main()
{
    btnode *root = new btnode(10);
    root->left = new btnode(20);
    root->right = new btnode(30);
    root->right->left = new btnode(40);
    root->right->right = new btnode(50);
    int n1 = 20, n2 = 50;

    btnode *ans = lca(root, n1, n2);
    cout << "LCA: " << ans->data;

    ans = lcaEfficient(root, n1, n2);
    cout << "\n";
    cout << "LCA efficient : " << ans->data;
}