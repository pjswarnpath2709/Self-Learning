#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
private:
    int countNode(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        return 1 + countNode(root->left) + countNode(root->right);
    }
    bool isCBT(Node *root, int index, int nodeCount)
    {
        if (root == nullptr)
        {
            return true;
        }
        if (index >= nodeCount)
        {
            return false;
        }
        else
        {
            bool leftans = isCBT(root->left, 2 * index + 1, nodeCount);
            bool rightans = isCBT(root->right, 2 * index + 2, nodeCount);
            return (leftans && rightans);
        }
    }

    bool isMaxHeap(Node *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return true;
        }
        if (root->right == nullptr)
        {
            return root->data > root->left->data;
        }
        else
        {
            bool left = isMaxHeap(root->left);
            bool right = isMaxHeap(root->right);
            return ((root->data > root->left->data) && (root->data > root->right->data)) && left && right;
        }
    }

public:
    bool isHeap(struct Node *tree)
    {
        int nodeCount = countNode(tree);
        int index = 0;
        return isCBT(tree, index, nodeCount) && isMaxHeap(tree);
    }
};
int main()
{

    return 0;
}