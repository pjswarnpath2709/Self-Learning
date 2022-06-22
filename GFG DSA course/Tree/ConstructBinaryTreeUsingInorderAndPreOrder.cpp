

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

int preIndex = 0;
btnode *createTree(int inorderArr[], int preorderArr[], int is, int ie)
{
    if (is > ie)
    {
        return nullptr;
    }
    btnode *root = new btnode(preorderArr[preIndex++]);

    // select the index of the same node in the inorder sequence
    int inIndex = is;
    for (int i = is; i <= ie; i++)
    {
        if (root->data == inorderArr[i])
        {
            inIndex = i;
            break;
        }
    }
    // we got the index now set theleft swubtree and right subtree of the root recursively
    // and return the root

    root->left = createTree(inorderArr, preorderArr, is, inIndex - 1);
    root->right = createTree(inorderArr, preorderArr, inIndex + 1, ie);

    return root;
}
void inorder(btnode *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
int main()
{
    int n;
    cin >> n;
    int in[n];
    int pre[n];

    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }

    // int in[]={20,10,40,30,50};
    //  int pre[]={10,20,30,40,50};
    //  int n=sizeof(in)/sizeof(in[0]);

    btnode *root = createTree(in, pre, 0, n - 1);
    inorder(root);

    return 0;
}