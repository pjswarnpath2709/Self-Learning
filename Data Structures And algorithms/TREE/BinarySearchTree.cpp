#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *lchild;
    int data;
    Node *rchild;
};

class BST
{
public:
    Node *root;
    void InsertBST(Node *t, int key);
    Node *RinsertBST(Node *p, int key);
    BST()
    {
        root = NULL;
    }
    BST(int value)
    {
        Node *t = new Node;
        t->data = value;
        t->lchild = t->rchild = NULL;
        root = t;
        t = NULL;
    }
    void CreateBST(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            InsertBST(root, arr[i]);
        }
    }
    void RcreateBST(int *arr, int n)
    {
        for (int i = 0; i < n; i++)
        {
            root = RinsertBST(root, arr[i]);
        }
    }
    Node *SearchBST(Node *t, int key);
    Node *RsearchBST(Node *t, int key);
    Node *Delete(Node *t, int key);
    int Height(Node *p);
    void inOrder(Node *p);
    Node *InPre(Node *P);
    Node *InSuc(Node *p);
};

int main()
{
    BST bst(34);
    BST bst2(45);
    int arr[] = {9, 15, 5, 20, 16, 8, 12, 3, 6};
    bst.CreateBST(arr, 9);
    bst2.RcreateBST(arr, 9);

    bst.inOrder(bst.root);
    cout << "\n";
    bst2.inOrder(bst2.root);
    cout << "\n";
    Node *t = bst.RsearchBST(bst.root, 20);
    if (t)
    {
        cout << t->data << " Yes its found\n";
    }
    else
    {
        cout << "NO not found\n";
    }
    t = bst2.SearchBST(bst2.root, 16);
    if (t)
    {
        cout << t->data << " Yes its found \n";
    }
    else
    {
        cout << "NO not found\n";
    }
    bst.Delete(bst.root, 20);
    bst.inOrder(bst.root);
    cout << "\n";
    bst2.Delete(bst2.root, 45);
    bst2.inOrder(bst2.root);
    cout << "\n";
    return 0;
}
Node *BST::RinsertBST(Node *p, int key)
{
    Node *t;
    if (p == NULL)
    {
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    else
    {
        if (key < p->data)
        {
            p->lchild = RinsertBST(p->lchild, key);
        }
        else
        {
            p->rchild = RinsertBST(p->rchild, key);
        }
    }
}
void BST::InsertBST(Node *t, int key)
{
    Node *r = NULL, *p;
    while (t != NULL)
    {
        r = t;
        if (key == t->data)
        {
            return;
        }
        else if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    p = new Node;
    p->data = key;
    p->lchild = p->rchild = NULL;
    if (p->data < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}
void BST::inOrder(Node *p)
{
    if (p)
    {
        inOrder(p->lchild);
        cout << p->data << " ";
        inOrder(p->rchild);
    }
}
Node *BST::SearchBST(Node *t, int key)
{
    while (t != NULL)
    {
        if (t->data == key)
        {
            return t;
        }
        else if (t->data < key)
        {
            t = t->rchild;
        }
        else
        {
            t = t->lchild;
        }
    }
    return NULL;
}
Node *BST::RsearchBST(Node *t, int key)
{
    if (t)
    {
        if (t->data == key)
        {
            return t;
        }
        else if (t->data > key)
        {
            return RsearchBST(t->lchild, key);
        }
        else
            return RsearchBST(t->rchild, key);
    }
    return NULL;
}

Node *BST::Delete(Node *p, int key)
{

    if (p == NULL)
        return NULL;
    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
            root = NULL;
        free(p);
        return NULL;
    }

    if (key < p->data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else
    {
        if (Height(p->lchild) > Height(p->rchild))
        {
            Node *q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            Node *q = InSuc(p->rchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
    }
}
int BST::Height(Node *p)
{
    int x = 0, y = 0;
    if (p == 0)
    {
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    if (x > y)
    {
        return x + 1;
    }
    else
        return y + 1;
}
Node *BST::InPre(Node *p)
{
    while (p && p->rchild != NULL) 
    {
        p = p->rchild;
    }
    return p;
}
Node *BST::InSuc(Node *p)
{
    while (p && p->lchild != NULL)
    {
        p = p->lchild;
    }
    return p;
}
