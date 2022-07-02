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

bool isTwoSumPresentInBST(TreeNode *root, int k)
{
    BSTIterator *bst_itr_Obj = new BSTIterator(root);

    auto itrStart = bst_itr_Obj->next();
    auto itrEnd = bst_itr_Obj->before();

    while (itrStart <= itrEnd)
    {
        if (itrStart + itrEnd < k)
        {
            itrStart = bst_itr_Obj->next();
        }
        else if (itrStart + itrEnd > k)
        {
            itrEnd = bst_itr_Obj->before();
        }
        else
        {
            return true;
        }
    }
    return false;
}
/*

// STRIVER'S CODE :- IT'S PASSED ON THE LEETCODE

class BSTIterator {
    stack<TreeNode *> myStack;
    bool reverse = true;
public:
    BSTIterator(TreeNode *root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }


    bool hasNext() {
        return !myStack.empty();
    }


    int next() {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        if(!reverse) pushAll(tmpNode->right);
        else pushAll(tmpNode->left);
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node) {
        for(;node != NULL; ) {
             myStack.push(node);
             if(reverse == true) {
                 node = node->right;
             } else {
                 node = node->left;
             }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();
        while(i<j) {
            if(i + j == k) return true;
            else if(i + j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};

*/
int main()
{
}