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
unordered_map<btnode *, int> mp;
int getHeight(btnode *root)
{
    if (root == nullptr)
    {
        mp[root] = 0;
        return 0;
    }
    int lh = mp.find(root->left) != mp.end() ? mp[root->left] : getHeight(root->left);
    int rh = mp.find(root->right) != mp.end() ? mp[root->right] : getHeight(root->right);
    mp[root] = 1 + max(lh, rh);
    return 1 + max(lh, rh);
}

int getDaimeter(btnode *root)
{
    if (root == nullptr)
    {
        mp[root] = 0;
        return 0;
    }

    int d1 = 1 + getHeight(root->left) + getHeight(root->right);
    int d2 = getDaimeter(root->left);
    int d3 = getDaimeter(root->right);

    return max(d1, max(d2, d3));
}

// better solution this will use thr preprocessed map which contains the data of heigt
int getDaimeterMap(btnode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int d1 = 1 + mp[root->left] + mp[root->right];
    int d2 = getDaimeterMap(root->left);
    int d3 = getDaimeterMap(root->right);

    return max(d1, max(d2, d3));
}

// most efficient approach will be modifing the getHiegth function
int res = 0;
int getDaimeterModifiedHeigth(btnode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int lh = getDaimeterModifiedHeigth(root->left);
    int rh = getDaimeterModifiedHeigth(root->right);

    res = max(res, 1 + lh + rh);

    return 1 + max(lh, rh);
}

int main()
{
    btnode *root = new btnode(10);
    root->left = new btnode(20);
    root->right = new btnode(30);
    root->right->left = new btnode(40);
    root->right->right = new btnode(60);
    root->right->left->left = new btnode(50);
    root->right->right->right = new btnode(70);

    cout << "Height: " << getHeight(root) << endl;
    int height = getDaimeterModifiedHeigth(root);
    cout << "Diameter with modified height : " << res << "\n";
    cout << "Diameter with Mapped height : " << getDaimeterMap(root) << "\n";
    cout << "Diameter with Normal height :" << getDaimeter(root) << "\n";
    return 0;
}