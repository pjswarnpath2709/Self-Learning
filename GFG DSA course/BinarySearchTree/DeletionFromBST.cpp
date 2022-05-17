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
        this->left = nullptr;
        this->right = nullptr;
    }
};
// inorder traversal gives the succesor
//  the next succesor is the left most leaf of the right child of the current node
bstnode *getSuccesor(bstnode *root)
{
    bstnode *curr = root->right; // got the right child's root
    while (curr != nullptr && curr->left != nullptr)
    {
        curr = curr->left;
    }
    return curr;
}
bstnode *deleteNode(bstnode *root, int key)
{
    // the upper function ius very similiar to the insert function
    if (root == nullptr)
    {
        return root;
    }
    else if (root->data > key)
    {
        // update the left subtree after deletion of the key
        root->left = deleteNode(root->left, key);
    }
    else if (root->data < key)
    {
        // update the right subtree after deletion of the key
        root->right = deleteNode(root->right, key);
    }
    else
    {
        /*
        ab yaha pe baari aati hai jab key find kar lete hai apan
        so ab kaam hai use delete karne ka so there are several cases

        case 1.) if the left child of the tree is empty then we will simply resend the right child of the tree
        case 2.) if the right child of the tree is empty then we will simply resend the left child of the tree
        case 3.) if there exits both child of the tree
           if this is the case then we will find the lowest uppar succesor for the
           given key copy it's value to the node and will call delete node function for the
           same key on the right child of it
           and hence will simply return  the root

        */

        // case 1 -> when the left child is empty
        if (root->left == nullptr)
        {
            bstnode *temp = root->right;
            delete root;
            return temp;
        }
        // case 2 -> when the right child is empty
        else if (root->right == nullptr)
        {
            bstnode *temp = root->left;
            delete root;
            return temp;
        }

        // both of the upper cases will also handle the case when the leaf is delted as it eill simply
        //  return a nullptr

        // here we fall in the third case where we have to find the succesor of the root
        else
        {
            // step 1: get the succesor
            bstnode *succ = getSuccesor(root);

            // step 2: copy the value of the succesor to the root
            root->data = succ->data;

            // now call delete function recuursively to delte the succesor node on right child
            // hence update the right child of the root after delting the succesor's node
            root->right = deleteNode(root->right, succ->data);
        }
    }
    return root;
}
void inorder(bstnode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    bstnode *root = new bstnode(10);
    root->left = new bstnode(5);
    root->right = new bstnode(15);
    root->right->left = new bstnode(12);
    root->right->right = new bstnode(18);
    int x = 15;

    root = deleteNode(root, x);
    inorder(root);
    return 0;
}
