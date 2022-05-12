#include <bits/stdc++.h>
using namespace std;

struct btnode
{
    int data;
    btnode *left;
    btnode *right;

    btnode(int key)
    {
        this->data = key;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void levelOrder(btnode *root)
{
    if (root == nullptr)
        return;

    queue<btnode *> qt;
    qt.push(root);
    while (!qt.empty())
    {
        // get the first element of the queue
        btnode *curr = qt.front();
        qt.pop();
        // print its data
        cout << curr->data << " ";
        // now enqueue it's children in the queue if any are there
        if (curr->left != nullptr)
        {
            qt.push(curr->left);
        }
        if (curr->right != nullptr)
        {
            qt.push(curr->right);
        }
    }
}

void levelOrderLine(btnode *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<btnode *> qt;
    qt.push(root);
    qt.push(nullptr);
    while (qt.size() > 1)
    {
        btnode *curr = qt.front();
        qt.pop();

        // if the front node is null then we have to again insert the null
        // and print the next line
        if (curr == nullptr)
        {
            // current level done and next level is completely inside the queue
            cout << "\n";
            qt.push(nullptr);
        }
        else
        {
            cout << curr->data << " ";
            if (curr->left != nullptr)
            {
                qt.push(curr->left);
            }
            if (curr->right != nullptr)
            {
                qt.push(curr->right);
            }
        }
    }
}

int main()
{
    btnode *root = new btnode(10);
    root->left = new btnode(20);
    root->right = new btnode(30);
    root->left->left = new btnode(40);
    root->left->right = new btnode(50);
    root->right->left = new btnode(60);
    root->right->right = new btnode(70);

    levelOrder(root);
    cout << "\n"
         << "lien by line : "
         << "\n";

    levelOrderLine(root);

    return 0;
}