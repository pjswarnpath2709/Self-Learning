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
public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node *inOrderSuccessor(Node *root, Node *x)
    {
        Node *succ = nullptr;
        while (root != nullptr)
        {
            if (x->data >= root->data)
            {
                root = root->right;
            }
            else
            {
                succ = root;
                root = root->left;
            }
        }
        return succ;
    }
    Node *inOrderPredecessor(Node *root, Node *x)
    {
        Node *pred = nullptr;
        while (root != nullptr)
        {
            if (x->data <= root->data)
            {
                root = root->left;
            }
            else
            {
                pred = root;
                root = root->right;
            }
        }
        return pred;
    }
};

int main()
{
}