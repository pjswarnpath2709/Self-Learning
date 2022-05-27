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

void vTraversal(bstnode *root)
{
    map<int, vector<int>> mp;
    queue<pair<bstnode *, int>> q;
    q.push({root, 0});
    while (q.empty() == false)
    {
        auto p = q.front();
        bstnode *curr = p.first;
        int hd = p.second;
        mp[hd].push_back(curr->data);
        q.pop();
        if (curr->left != NULL)
            q.push({curr->left, hd - 1});
        if (curr->right != NULL)
            q.push({curr->right, hd + 1});
    }
    for (auto x : mp)
    {
        for (int y : x.second)
            cout << y << " ";
        cout << endl;
    }
}

int main()
{
    bstnode *root = new bstnode(10);
    root->left = new bstnode(20);
    root->right = new bstnode(30);
    root->left->left = new bstnode(40);
    root->left->right = new bstnode(50);
    vTraversal(root);
    return 0;
}