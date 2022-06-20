

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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int ans = 0;
        queue<pair<TreeNode *, int>> qt;
        qt.push({root, 0});
        while (!qt.empty())
        {
            int size = qt.size();
            int mmin = qt.front().second;
            int first, last;
            for (int i = 0; i < size; i++)
            {
                int cur_id = qt.front().second - mmin;
                TreeNode *cur = qt.front().first;
                qt.pop();
                if (i == 0)
                    first = cur_id;
                if (i == size - 1)
                    last = cur_id;

                if (cur->left)
                {
                    qt.push({cur->left, cur_id * 2 + 1});
                }
                if (cur->right)
                {
                    qt.push({cur->right, cur_id * 2 + 2});
                }
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};

int main()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(5);
    root->left->left->left = new TreeNode(7);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(6);

    int maxWidth = Solution().widthOfBinaryTree(root);
    cout << "The maximum width of the Binary Tree is " << maxWidth;

    return 0;

    return 0;
}