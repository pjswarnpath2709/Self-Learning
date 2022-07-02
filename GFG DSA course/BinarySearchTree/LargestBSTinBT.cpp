#include <bits/stdc++.h>
using namespace std;

class NodeValue
{
public:
    int minNode;
    int maxNode;
    int maxSize;

    NodeValue(int minNode, int maxNode, int maxSize) : minNode(minNode), maxNode(maxNode), maxSize(maxSize)
    {
    }
};

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
    NodeValue _largestBstHelper(TreeNode *root)
    {
        // the nullpointer is a bst with size 0
        if (root == nullptr)
        {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        // calculating for the left side and the right side
        auto left = _largestBstHelper(root->left);
        auto right = _largestBstHelper(root->right);

        // checking if the current node is a bst or not
        //  if the current node's value is greater than the largest of left and smaller then the smallest in right then it followes the property of the bst
        if (left.maxNode < root->val && right.minNode > root->val)
        {
            // then it follows the rules of bst hence return the new NodeValue
            return NodeValue(
                min(left.minNode, root->val),  // the minimum should be from the left side only
                max(right.maxNode, root->val), // the maximum should be fromn the right side only
                1 + left.maxSize + right.maxSize);
        }
        else
        {
            // other wise return the range [-Inf, Inf] so that parent's cant be a valid bst
            return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
        }
    }

public:
    int largestBSTSubTree(TreeNode *root)
    {
        return _largestBstHelper(root).maxSize;
    }
};