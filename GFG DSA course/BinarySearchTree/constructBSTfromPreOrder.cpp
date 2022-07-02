#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
private:
    TreeNode *_build(vector<int> &preorder, int indx, int upperBound)
    {
        if (indx == preorder.size() || preorder[indx] > upperBound)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[indx++]);
        root->left = _build(preorder, indx, root->val);
        root->right = _build(preorder, indx, upperBound);
        return root;
    }

public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        return _build(preorder, 0, INT_MAX);
    }
};