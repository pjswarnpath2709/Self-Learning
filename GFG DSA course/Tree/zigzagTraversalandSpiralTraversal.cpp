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
    vector<vector<int>> _getLevelOrder(TreeNode *root)
    {
        vector<vector<int>> mat;
        if (root == nullptr)
        {
            return mat;
        }
        queue<TreeNode *> qt;
        qt.push(root);
        while (!qt.empty())
        {
            int _size = qt.size();
            vector<int> vec;
            for (int i = 0; i < _size; i++)
            {
                TreeNode *curr = qt.front();
                qt.pop();
                vec.push_back(curr->val);
                if (curr->left)
                {
                    qt.push(curr->left);
                }
                if (curr->right)
                {
                    qt.push(curr->right);
                }
            }
            mat.push_back(vec);
        }

        return mat;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> mat;
        if (root == nullptr)
        {
            return mat;
        }

        mat = _getLevelOrder(root);
        for (int i = 1; i < mat.size(); i += 2)
        {
            reverse(mat[i].begin(), mat[i].end());
        }

        return mat;
    }
};