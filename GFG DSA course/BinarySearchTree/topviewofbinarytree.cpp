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

void topView(bstnode *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<pair<bstnode *, int>> qt;
    map<int, int> mp;
    qt.push({root, 0});
    while (!qt.empty())
    {
        auto p = qt.front();
        bstnode *curr = p.first;
        int hd = p.second;
        if (mp.find(hd) == mp.end())
            mp[hd] = (curr->data);
        qt.pop();
        if (curr->left != NULL)
            qt.push({curr->left, hd - 1});
        if (curr->right != NULL)
            qt.push({curr->right, hd + 1});
    }
    for (auto x : mp)
    {
        cout << x.second << " ";
    }
    cout << "\n";
}
int main()
{
    bstnode *root = new bstnode(10);
    root->left = new bstnode(20);
    root->right = new bstnode(30);
    root->left->left = new bstnode(40);
    root->left->right = new bstnode(50);

    topView(root);

    return 0;

    return 0;
}