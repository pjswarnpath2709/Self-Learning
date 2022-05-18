

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
bstnode *ceil_rec(bstnode *root, int key)
{
    if (root == nullptr)
    {
        return root;
    }
    bstnode *left = nullptr, *right = nullptr;
    if (root->data == key)
    {
        return root;
    }
    if (root->data > key)
    {
        left = ceil_rec(root->left, key);
    }
    else
    {
        right = ceil_rec(root->right, key);
    }
    // now we either get the left or right key back baki mein kisi mein null ayega
    if (left != nullptr && right == nullptr && left->data > key)
    {
        return left;
    }
    else if (right != nullptr && left == nullptr && right->data > key)
    {
        return right;
    }
    // agar dono mein se koi bhi null nahi aya yani woh returnj hoga na jiski value jyada rahegi
    else if (right != nullptr && left != nullptr && right->data > key && left->data > key)
    {
        return (right->data < left->data) ? right : left;
    }
    // dono hi null agaye yani tree ke end mein khade ho ji app

    return root;
}
bstnode *floorBst(bstnode *root, int key)
{
    bstnode *res = nullptr;
    while (root != nullptr)
    {
        if (root->data == key)
        {
            return root;
        }
        else
        {
            // use choti value definetly left mein exist karegi
            if (root->data < key)
            {
                root = root->right;
            }

            // yeh toh mil gaya but kya pata koi candidate iske right mein betha ho
            else
            {
                res = root;
                root = root->left;
            }
        }
    }
    return res;
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
    int x = 17;

    cout << "Floor_rec : " << (ceil_rec(root, 17)->data) << "\n";
    cout << "Floor_iter : " << (floorBst(root, 17)->data) << "\n";
    return 0;
}