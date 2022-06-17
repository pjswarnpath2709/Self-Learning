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

void postorder(btnode *root)
{
    if (root != nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

void iterativePostorder2Stacks(btnode *root)
{
    btnode *node = root;
    stack<btnode *> st1;
    stack<int> st2;
    st1.push(node);
    while (!st1.empty())
    {
        node = st1.top();
        st1.pop();
        st2.push(node->data);
        if (node->left != nullptr)
        {
            st1.push(node->left);
        }
        if (node->right != nullptr)
        {
            st1.push(node->right);
        }
    }
    while (!st2.empty())
    {
        cout << st2.top() << " ";
        st2.pop();
    }
}

void iterativePostOrder1Stack(btnode *root)
{
    if (root == nullptr)
    {
        return;
    }
    stack<btnode *> st;
    btnode *curr = root;
    // st.push(curr);
    while (curr != nullptr || !st.empty())
    {
        if (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            btnode *temp = st.top()->right;
            if (temp == nullptr)
            {
                temp = st.top();
                st.pop();
                cout << temp->data << " ";
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    cout << temp->data << " ";
                }
            }
            else
            {
                curr = temp;
            }
        }
    }
    return;
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
    cout << "reccursive postorder: ";
    postorder(root);
    cout << "\n";
    cout << "iterativePostOrder2stack: ";
    iterativePostorder2Stacks(root);
    cout << "\n";
    cout << "iterativePostOrder1stack: ";
    iterativePostOrder1Stack(root);
    cout << "\n";
    return 0;
}