#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
typedef TreeNode node;

class Solution
{
public:
    node *prev_app1 = nullptr;
    void flattenApproach1(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }

        // first go right then go left then treat the root : RIGHT LEFT ROOT
        flattenApproach1(root->right);
        flattenApproach1(root->left);

        // work on the root
        root->right = prev_app1;
        root->left = nullptr;
        prev_app1 = root;
    }
    void flattenApproach2(node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        stack<node *> st;
        st.push(root);
        while (!st.empty())
        {
            node *curr = st.top();
            st.pop();
            if (curr->right)
            {
                st.push(curr->right);
            }
            if (curr->left)
            {
                st.push(curr->left);
            }
            if (!st.empty())
            {
                curr->right = st.top();
            }
            curr->left = nullptr;
        }
    }

    node *prev_app3 = nullptr;
    void flattenApproach3(node *root)
    {
        node *curr = root;
        while (curr != nullptr)
        {
            if (curr->left != nullptr)
            {
                prev_app3 = curr->left;
                while (prev_app3->right)
                {
                    prev_app3 = prev_app3->right;
                }
                prev_app3->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};