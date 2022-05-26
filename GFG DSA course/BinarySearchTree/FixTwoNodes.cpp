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

void printFirstAndSecond(int arr[], int n)
{
    int prev = INT_MIN;
    int first = INT_MIN;
    int second = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < prev)
        {
            if (first == INT_MIN)
            {
                first = prev;
            }
            second = arr[i];
        }
        prev = arr[i];
    }
}

void inorder(bstnode *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void fixbst(bstnode *root, bstnode *&first, bstnode *&second, bstnode *&prev)
{
    if (root != nullptr)
    {
        fixbst(root->left, first, second, prev);
        if (prev != nullptr && root->data < prev->data)
        {
            if (first == nullptr)
            {
                first = prev;
            }
            second = root;
        }
        prev = root;
        fixbst(root->right, first, second, prev);
    }
}
void fixBST(bstnode *root, bstnode *&first, bstnode *&second)
{
    bstnode *prev = nullptr;
    fixbst(root, first, second, prev);
}
int main()
{
    bstnode *root = new bstnode(18);
    root->left = new bstnode(60);
    root->right = new bstnode(70);
    root->left->left = new bstnode(4);
    root->right->left = new bstnode(8);
    root->right->right = new bstnode(80);

    bstnode *first = nullptr;
    bstnode *second = nullptr;
    inorder(root);
    cout << endl;
    fixBST(root, first, second);
    int temp = first->data;
    first->data = second->data;
    second->data = temp;
    inorder(root);
    cout << "\n";

    return 0;
}