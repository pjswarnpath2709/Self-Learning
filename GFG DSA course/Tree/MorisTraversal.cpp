
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
    vector<int> inorderMorrisTraversal(node *root)
    {
        vector<int> inorder;

        node *cur = root;
        while (cur != NULL)
        {
            if (cur->left == NULL)
            {
                inorder.push_back(cur->val);
                cur = cur->right;
            }
            else
            {
                node *prev = cur->left;
                while (prev->right != NULL && prev->right != cur)
                {
                    prev = prev->right; // go to the rightmost guy
                }
                if (prev->right == NULL)
                {
                    prev->right = cur; // do the threading
                    cur = cur->left;   // move curr to the left
                }
                else
                {
                    prev->right = NULL;          // unthread the connections
                    inorder.push_back(cur->val); // store the root now
                    cur = cur->right;            // move to the right
                }
            }
        }
        return inorder;
    }
    vector<int> preorderMorrisTraversal(node *root)
    {
        vector<int> preorder;

        node *cur = root;
        while (cur != NULL)
        {
            if (cur->left == NULL)
            {
                preorder.push_back(cur->val);
                cur = cur->right;
            }
            else
            {
                node *prev = cur->left;
                while (prev->right != NULL && prev->right != cur)
                {
                    prev = prev->right; // go to the rightmost guy
                }
                if (prev->right == NULL)
                {
                    prev->right = cur;            // do the threading
                    preorder.push_back(cur->val); // push to the preorder as at this time we are on the root
                    cur = cur->left;              // move curr to the left
                }
                else
                {
                    prev->right = NULL; // unthread the connections
                    cur = cur->right;   // move to the right
                }
            }
        }
        return preorder;
    }
};