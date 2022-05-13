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

void printlist(btnode *head)
{
    btnode *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}

class ConverterClass
{
private:
    btnode *prev = nullptr;

public:
    /*
    we will do in order traversal and keep a prev pointor which can tell our previous node

    dll structure will be like
    left --> prev
    right -->next

    now the crucial part is that if the node's left is null then the node will be the head node
    the leftmost node will be the head
    hence we will traverse in the inorder
    */
    btnode *convertBTtoDLL(btnode *root)
    {
        if (root == nullptr)
            return root;

        // here we call for the left subtree to get the head
        btnode *head = convertBTtoDLL(root->left);

        // here we process the current element;
        if (prev == nullptr)
        {
            head = root;
        }
        else
        {
            root->left = prev;  // root ka previous toh prev ho jayega
            prev->right = root; // prev ka next apna root ho jayega
        }
        prev = root; // aur yeh apan prev ko update kardenge next root ke liye

        // here we call for the right subtree of the root
        convertBTtoDLL(root->right);
        return head;
    }
};

int main()
{
    btnode *root = new btnode(10);
    root->left = new btnode(5);
    root->right = new btnode(20);
    root->right->left = new btnode(30);
    root->right->right = new btnode(35);

    ConverterClass *cnvrtobj = new ConverterClass();
    btnode *head = cnvrtobj->convertBTtoDLL(root);
    printlist(head);
}