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

void printvector(vector<int> vec)
{
    for (auto ele : vec)
    {
        cout << ele << " ";
    }
    cout << "\n";
}

void allTraversals(btnode *root,
                   vector<int> &pre,
                   vector<int> &in,
                   vector<int> &post)
{
    if (root == nullptr)
    {
        return;
    }
    stack<pair<btnode *, int>> st;
    st.push({root, 1});
    while (!st.empty())
    {
        if (st.top().second == 1)
        {
            pre.push_back(st.top().first->data);
            ++st.top().second;
            if (st.top().first->left != nullptr)
            {
                st.push({st.top().first->left, 1});
            }
            // cout << "pre"
            //      << "\n";
        }
        else if (st.top().second == 2)
        {
            in.push_back(st.top().first->data);
            ++st.top().second;
            if (st.top().first->right != nullptr)
            {
                st.push({st.top().first->right, 1});
            }
            // cout << "in"
            //      << "\n";
        }
        else
        {
            post.push_back(st.top().first->data);
            st.pop();
            // cout << "post"
            //      << "\n";
        }
    }
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

    vector<int> pre, in, post;
    allTraversals(root, pre, in, post);

    printvector(pre);
    printvector(in);
    printvector(post);

    return 0;
}
