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

struct pack
{
    TreeNode *node;
    int horizontalDist;
    int level;
    pack(TreeNode *node, int horizontalDist, int level)
    {
        this->node = node;
        this->horizontalDist = horizontalDist;
        this->level = level;
    }
};

void _getVecFromMultiSet(multiset<int> ms, vector<int> &vec)
{
    for (auto ele : ms)
    {
        vec.push_back(ele);
    }
}
void _converter(map<int, map<int, multiset<int>>> &mp, vector<vector<int>> &mat)
{

    for (auto ele : mp)
    {
        vector<int> vec;
        for (auto eleIn : ele.second)
        {
            _getVecFromMultiSet(eleIn.second, vec);
        }
        mat.push_back(vec);
    }
}

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
    {
        return ans;
    }
    queue<pack *> qt;
    map<int, map<int, multiset<int>>> mp;
    qt.push(new pack(root, 0, 0));
    while (!qt.empty())
    {
        int size = qt.size();
        for (int i = 0; i < size; i++)
        {
            pack *p = qt.front();
            qt.pop();
            TreeNode *curr = p->node;
            // inserting into the big data structure
            mp[p->horizontalDist][p->level].insert(curr->val);

            if (curr->left)
            {
                qt.push(new pack(curr->left, p->horizontalDist - 1, p->level + 1));
            }
            if (curr->right)
            {
                qt.push(new pack(curr->right, p->horizontalDist + 1, p->level + 1));
            }
            delete p;
        }
    }
    _converter(mp, ans);
    return ans;
}
int main()
{
    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(10);
    root->left->left->right = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(10);

    vector<vector<int>> vTraversal;
    vTraversal = verticalTraversal(root);

    cout << "The Vertical Traversal is : " << endl;
    for (auto vertical : vTraversal)
    {
        for (auto nodeVal : vertical)
        {
            cout << nodeVal << " ";
        }
        cout << endl;
    }
}