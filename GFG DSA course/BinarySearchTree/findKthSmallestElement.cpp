#include <bits/stdc++.h>
using namespace std;

struct agmnode
{
    int data;
    agmnode *left;
    agmnode *right;
    int leftCount;
    agmnode(int key)
    {
        this->data = key;
        this->left = nullptr;
        this->right = nullptr;
        this->leftCount = 0;
    }
};

class AugmentedBST
{
private:
    agmnode *root = nullptr;

    agmnode *insertAgmNode(int key)
    {
        if (root == nullptr)
        {
            root = new agmnode(key);
            return root;
        }
        agmnode *parent = nullptr;
        agmnode *curr = root;
        while (curr != nullptr)
        {
            parent = curr;
            if (curr->data < key)
            {
                curr = curr->right;
            }
            else if (curr->data > key)
            {
                curr->leftCount++;
                curr = curr->left;
            }
            else
            {
                return root;
            }
        }
        if (parent->data > key)
        {
            parent->left = new agmnode(key);
        }
        else
        {
            parent->right = new agmnode(key);
        }
        return root;
    }

    // leftmost node of right child subtree
    agmnode *getSuccesor(agmnode *node)
    {
        agmnode *curr = node->right;
        while (curr != nullptr && curr->left != nullptr)
        {
            curr = curr->left;
        }
        return curr;
    }

    agmnode *deleteAgmNode(agmnode *droot, int key)
    {
        if (droot == nullptr)
        {
            return nullptr;
        }
        else if (droot->data < key)
        {
            droot->right = deleteAgmNode(droot->right, key);
        }
        else if (droot->data > key)
        {
            droot->leftCount--;
            droot->left = deleteAgmNode(droot->left, key);
        }
        else
        {
            // here arises there cases
            // case 1 if the left node is null
            if (droot->left == nullptr)
            {
                agmnode *temp = droot->right;
                delete droot;
                return temp;
            }
            // case2 if the right node is null
            else if (droot->right == nullptr)
            {
                agmnode *temp = droot->left;
                delete droot;
                return temp;
            }
            // case3 if nothing is null
            else
            {
                // get the succesor
                agmnode *succ = getSuccesor(droot);
                droot->data = succ->data;
                // update the right subtree as we are now deleting the
                // succesor
                droot->right = deleteAgmNode(droot->right, succ->data);
            }
        }
        return droot;
    }

    agmnode *getKthSmallestAgmNode(agmnode *droot, int k)
    {
        if (droot == nullptr)
        {
            return nullptr;
        }
        if (droot->leftCount + 1 == k)
        {
            return droot;
        }
        else if (droot->leftCount + 1 > k)
        {
            return getKthSmallestAgmNode(droot->left, k);
        }
        else
        {
            return getKthSmallestAgmNode(droot->right, k - droot->leftCount - 1);
        }
    }
    void inorderTraversel(agmnode *droot)
    {
        if (droot != nullptr)
        {
            inorderTraversel(droot->left);
            cout << droot->data << " ";
            inorderTraversel(droot->right);
        }
    }

public:
    void insertNode(int key)
    {
        root = insertAgmNode(key);
    }

    void deleteNode(int key)
    {
        root = deleteAgmNode(root, key);
    }

    int getKthSmallest(int k)
    {
        agmnode *node = getKthSmallestAgmNode(root, k);
        return (node != nullptr) ? node->data : -1;
    }
    void printTree()
    {
        if (root == nullptr)
        {
            cout << "empty tree";
        }
        inorderTraversel(root);
    }
};

int main()
{

    AugmentedBST *bst = new AugmentedBST();
    bst->insertNode(50);
    bst->insertNode(20);
    bst->insertNode(10);
    bst->insertNode(40);
    bst->insertNode(4);
    bst->insertNode(100);
    bst->insertNode(70);
    bst->insertNode(120);
    bst->insertNode(60);
    bst->insertNode(80);
    bst->printTree();
    int ans = bst->getKthSmallest(7);
    cout << "\n";
    cout << ans << "\n";
    bst->deleteNode(70);
    bst->printTree();
    ans = bst->getKthSmallest(7);
    cout << "\n";
    cout << ans << "\n";

    return 0;
}