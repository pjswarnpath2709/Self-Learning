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
    TreeNode *buildTreeHelp(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd, unordered_map<int, int> &inIndexes)
    {
        if (inStart > inEnd || postStart > postEnd)
        {
            return nullptr;
        }

        TreeNode *root = new TreeNode(postorder[postEnd]);

        // get the index of the root
        int indx_root = inIndexes[root->val];
        int numsLeft = indx_root - inStart;

        root->left = buildTreeHelp(inorder, inStart, indx_root - 1, postorder, postStart, postStart + numsLeft - 1, inIndexes);
        root->right = buildTreeHelp(inorder, indx_root + 1, inEnd, postorder, postStart + numsLeft, postEnd - 1, inIndexes);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> inIndexes;
        for (int i = 0; i < inorder.size(); i++)
        {
            inIndexes[inorder[i]] = i;
        }

        TreeNode *root = buildTreeHelp(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inIndexes);

        return root;
    }
};
int main()
{

    return 0;
}