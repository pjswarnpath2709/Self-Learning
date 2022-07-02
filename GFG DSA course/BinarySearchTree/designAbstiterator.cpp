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
class BSTIterator
{
private:
    stack<TreeNode *> myStackNext;
    stack<TreeNode *> myStackBefore;
    void _pushAllNext(TreeNode *node)
    {
        for (; node != nullptr; node = node->left)
        {
            myStackNext.push(node);
        }
    }
    void _pushAllBefore(TreeNode *node)
    {
        for (; node != nullptr; node = node->right)
        {
            myStackBefore.push(node);
        }
    }

public:
    BSTIterator(TreeNode *root)
    {
        _pushAllNext(root);
        _pushAllBefore(root);
    }

    int next()
    {
        TreeNode *temp = myStackNext.top();
        myStackNext.pop();
        _pushAllNext(temp->right);
        return temp->val;
    }
    int before()
    {
        TreeNode *temp = myStackBefore.top();
        myStackBefore.pop();
        _pushAllBefore(temp->left);
        return temp->val;
    }

    bool hasBefore()
    {
        return !myStackBefore.empty();
    }

    bool hasNext()
    {
        return !myStackNext.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */