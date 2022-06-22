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
private:
    TreeNode *buildTreeHelp(vector<int> &preorder, int pre_start, int pre_end, vector<int> &inorder, int in_start, int in_end, unordered_map<int, int> &inIndexes)
    {
        if (in_start > in_end || pre_start > pre_end)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[pre_start]);
        int in_Root = inIndexes[root->val]; // get index of root in the inorder
        int numsLeft = in_Root - in_start;
        root->left = buildTreeHelp(preorder, pre_start + 1, pre_start + numsLeft, inorder, in_start, in_Root - 1, inIndexes);
        root->right = buildTreeHelp(preorder, pre_start + numsLeft + 1, pre_end, inorder, in_Root + 1, in_end, inIndexes);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> inIndexes; // because all elements of the inorder is unique
        for (int i = 0; i < inorder.size(); i++)
        {
            inIndexes[inorder[i]] = i;
        }
        TreeNode *root = buildTreeHelp(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inIndexes);

        return root;
    }
};

int main()
{

    return 0;
}
