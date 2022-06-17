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

void preorder(btnode *root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void iterativePreOrder(btnode *root)
{
    if (root == nullptr)
    {
        return;
    }
    stack<btnode *> st;
    st.push(root);
    while (!st.empty())
    {
        btnode *curr = st.top();
        st.pop();

        // step1: print the root
        cout << curr->data << " ";

        // step2 :first we will push the right first as it is a stack
        if (curr->right)
        {
            st.push(curr->right);
        }
        // step3 : secondly we will push the left first as it will be at top of the stack
        if (curr->left)
        {
            st.push(curr->left);
        }
    }
    cout << "\n";
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

    preorder(root);
    cout << "\n";
    iterativePreOrder(root);
    return 0;
}