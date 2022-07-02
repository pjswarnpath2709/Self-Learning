#include <bits/stdc++.h>
using namespace std;

struct bstnode
{
    int data;
    bstnode *left;
    bstnode *right;
    bstnode(int key)
    {
        this->data = key;
        this->right = nullptr;
        this->left = nullptr;
    }
};

void printFirstAndSecond(int arr[], int n)
{
    int prev = INT_MIN;
    int first = INT_MIN;
    int second = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < prev)
        {
            if (first == INT_MIN)
            {
                first = prev;
            }
            second = arr[i];
        }
        prev = arr[i];
    }
}

void inorder(bstnode *root)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void fixbst(bstnode *root, bstnode *&first, bstnode *&second, bstnode *&prev)
{
    if (root != nullptr)
    {
        fixbst(root->left, first, second, prev);
        if (prev != nullptr && root->data < prev->data)
        {
            if (first == nullptr)
            {
                first = prev;
            }
            second = root;
        }
        prev = root;
        fixbst(root->right, first, second, prev);
    }
}
void fixBST(bstnode *root, bstnode *&first, bstnode *&second)
{
    bstnode *prev = nullptr;
    fixbst(root, first, second, prev);
}
int main()
{
    bstnode *root = new bstnode(18);
    root->left = new bstnode(60);
    root->right = new bstnode(70);
    root->left->left = new bstnode(4);
    root->right->left = new bstnode(8);
    root->right->right = new bstnode(80);

    bstnode *first = nullptr;
    bstnode *second = nullptr;
    inorder(root);
    cout << endl;
    fixBST(root, first, second);
    int temp = first->data;
    first->data = second->data;
    second->data = temp;
    inorder(root);
    cout << "\n";

    return 0;
}

/*

//Striver's Solution

class Solution {
private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;
private:
    void inorder(TreeNode* root) {
        if(root == NULL) return;

        inorder(root->left);

        if (prev != NULL && (root->val < prev->val))
        {

            // If this is first violation, mark these two nodes as
            // 'first' and 'middle'
            if ( first == NULL )
            {
                first = prev;
                middle = root;
            }

            // If this is second violation, mark this node as last
            else
                last = root;
        }

        // Mark this node as previous
        prev = root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
    }
};

*/