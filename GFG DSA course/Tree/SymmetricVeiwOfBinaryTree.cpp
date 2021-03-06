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

class Solution
{
public:
    bool isSymmetricHelp(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr || right == nullptr)
        {
            return left == right;
        }
        return left->val == right->val && isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
    }
    bool isSymmetric(TreeNode *root)
    {

        return root == nullptr || isSymmetricHelp(root->left, root->right);
    }
};

int main()
{

    return 0;
}