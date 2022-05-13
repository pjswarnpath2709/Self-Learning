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

// method 1 to do so

void printSpiralLinebyLine(btnode *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<btnode *> qt;
    stack<int> st;
    bool reverse = false; // to get idea if it is time to reverse or not
    qt.push(root);
    while (!qt.empty())
    {
        int size = qt.size();
        for (int i = 0; i < size; i++)
        {
            btnode *curr = qt.front();
            qt.pop();
            if (reverse)
            {
                st.push(curr->data);
            }
            else
            {
                cout << curr->data << " ";
            }
            if (curr->left != nullptr)
            {
                qt.push(curr->left);
            }
            if (curr->right != nullptr)
            {
                qt.push(curr->right);
            }
        }
        // for loop ke bahar likhna hai ise
        if (reverse)
        {
            while (!st.empty())
            {
                cout << st.top() << " ";
                st.pop();
            }
        }
        reverse = (!reverse);
    }
}

// method 2 to do so using two stacks

/*

   1.> Push root to the stack
   2.> while any of the stack is not empty :
        a.> while s1 is not empty:
             1.)take ot the node print it
             2.)push it's children in the stack 2
        b.> while s2 is not empty:
             1.)take out the node print it
             2.) push it's children in stack 1 but in reverse order

    3.>algorithm ends here

*/
void printSpiralUsingStacks(btnode *root)
{
    if (root == nullptr)
        return;

    stack<btnode *> st1;
    stack<btnode *> st2;
    st1.push(root);
    while (!st1.empty() || !st2.empty())
    {
        while (!st1.empty())
        {
            btnode *curr = st1.top();
            st1.pop();
            cout << curr->data << " ";

            if (curr->left != nullptr)
            {
                st2.push(curr->left);
            }
            if (curr->right != nullptr)
            {
                st2.push(curr->right);
            }
        }
        while (!st2.empty())
        {
            btnode *curr = st2.top();
            st2.pop();
            cout << curr->data << " ";
            if (curr->right != nullptr)
            {
                st1.push(curr->right);
            }

            if (curr->left != nullptr)
            {
                st1.push(curr->left);
            }
        }
    }
}

int main()
{

    btnode *root = new btnode(1);
    root->left = new btnode(2);
    root->right = new btnode(3);
    root->left->left = new btnode(4);
    root->left->right = new btnode(5);
    root->right->left = new btnode(6);
    root->right->right = new btnode(7);

    printSpiralLinebyLine(root);
    cout << "\n";
    printSpiralUsingStacks(root);
    return 0;
}