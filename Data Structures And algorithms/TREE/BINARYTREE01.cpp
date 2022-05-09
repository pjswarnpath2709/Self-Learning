#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *Lchild;
    int data;
    Node *Rchild;
};

class BT
{
public:
    Node *root;
    BT()
    {
        root = NULL;
    }
    void createBT();
    void preOrder(Node *p);
    void postOrder(Node *p);
    void inOrder(Node *p);
    void levelOrder(Node *p);
    int Height(Node *p);
};
int main(int argc, char const *argv[])
{
    BT bt;
    bt.createBT();
    cout << "\n";
    bt.preOrder(bt.root);
    cout << "\n";
    bt.postOrder(bt.root);
    cout << "\n";
    bt.inOrder(bt.root);
    cout << "\n";
    bt.levelOrder(bt.root);
    cout << "\n";
    cout << bt.Height(bt.root) << "\n";
    return 0;
}

void BT::createBT()
{
    queue<Node *> q;
    Node *p, *t;
    cout << "Enter root Value:-\n";
    int x;
    cin >> x;
    root = new Node;
    root->data = x;
    root->Lchild = NULL;
    root->Rchild = NULL;
    q.push(root);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        cout << "Enter Left child of:--" << p->data << "\n";
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1)
        {
            t = new Node;
            t->data = leftdata;
            t->Lchild = t->Rchild = NULL;
            p->Lchild = t;
            q.push(t);
        }
        cout << "Enter Right child of:--" << p->data << "\n";
        int rightdata;
        cin >> rightdata;
        if (rightdata != -1)
        {
            t = new Node;
            t->data = rightdata;
            t->Lchild = t->Rchild = NULL;
            p->Rchild = t;
            q.push(t);
        }
    }
}
void BT::preOrder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preOrder(p->Lchild);
        preOrder(p->Rchild);
    }
}
void BT::postOrder(Node *p)
{
    if (p)
    {
        postOrder(p->Lchild);
        postOrder(p->Rchild);
        cout << p->data << " ";
    }
}
void BT::inOrder(Node *p)
{
    if (p)
    {
        inOrder(p->Lchild);
        cout << p->data << " ";
        inOrder(p->Rchild);
    }
}
void BT::levelOrder(Node *p)
{
    queue<Node *> qt;
    cout << (p->data) << " ";
    qt.push(p);
    while (!qt.empty())
    {
        p = qt.front();
        qt.pop();
        if (p->Lchild)
        {
            cout << p->Lchild->data << " ";
            qt.push(p->Lchild);
        }
        if (p->Rchild)
        {
            cout << p->Rchild->data << " ";
            qt.push(p->Rchild);
        }
    }
}
int BT::Height(Node *p)
{
    int x = 0, y = 0;
    if (p == 0)
    {
        return 0;
    }
    x = Height(p->Lchild);
    y = Height(p->Rchild);
    if (x > y)
    {
        return x + 1;
    }
    else
        return y + 1;
}