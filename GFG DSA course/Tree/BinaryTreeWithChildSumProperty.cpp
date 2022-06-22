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

void changeTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    int childSum = 0;
    if (root->left)
    {
        childSum += root->left->val;
    }
    if (root->right)
    {
        childSum += root->right->val;
    }

    if (childSum >= root->val)
        root->val = childSum;
    else
    {
        if (root->left)
        {
            root->left->val = root->val;
        }
        else if (root->right)
        {
            root->right->val = root->val;
        }
    }

    changeTree(root->left);
    changeTree(root->right);

    int totalSum = 0;
    if (root->left)
    {
        totalSum += root->left->val;
    }
    if (root->right)
    {
        totalSum += root->right->val;
    }
    if (root->left || root->right)
    {
        // if it is a leaf node dont update it , only uopdate normal nodes
        root->val = totalSum;
    }
}

void inorder(TreeNode *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(35);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(10);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(2);

    inorder(root);
    cout << "\n";
    changeTree(root);
    cout << "\n";
    inorder(root);

    return 0;
}
