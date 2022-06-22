

#include <bits/stdc++.h>
using namespace std;

template <class T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
typedef BinaryTreeNode<int> Node;

void _markParents(Node *root, unordered_map<Node *, Node *> &parents)
{
    queue<Node *> qt;
    qt.push(root);
    while (!qt.empty())
    {
        int size = qt.size();
        for (int i = 0; i < size; i++)
        {
            Node *curr = qt.front();
            qt.pop();
            if (curr->left)
            {
                parents[curr->left] = curr;
                qt.push(curr->left);
            }
            if (curr->right)
            {
                parents[curr->right] = curr;
                qt.push(curr->right);
            }
        }
    }
}

Node *_findStart(Node *root, int start)
{
    Node *ans = nullptr;
    queue<Node *> qt;
    qt.push(root);
    while (!qt.empty())
    {
        int size = qt.size();
        for (int i = 0; i < size; i++)
        {
            Node *curr = qt.front();
            qt.pop();
            if (curr->data == start)
            {
                ans = curr;
                return ans;
            }
            if (curr->left)
            {

                qt.push(curr->left);
            }
            if (curr->right)
            {
                qt.push(curr->right);
            }
        }
    }
    return ans;
}

int timeToBurnTree(Node *root, int start)
{
    unordered_map<Node *, Node *> parents;
    _markParents(root, parents);
    unordered_map<Node *, bool> visited;
    queue<Node *> qt;
    Node *target = _findStart(root, start);
    qt.push(target);
    visited[target] = true;
    int time = 0;

    while (!qt.empty())
    {
        int size = qt.size();
        int isDeletedSomething = false;
        for (int i = 0; i < size; i++)
        {
            Node *curr = qt.front();
            qt.pop();

            if (curr->left && visited[curr->left] == false)
            {
                isDeletedSomething = true;
                visited[curr->left] = true;
                qt.push(curr->left);
            }
            if (curr->right && visited[curr->right] == false)
            {
                isDeletedSomething = true;
                visited[curr->right] = true;
                qt.push(curr->right);
            }
            if (parents.find(curr) != parents.end() && visited[parents[curr]] == false)
            {
                isDeletedSomething = true;
                visited[parents[curr]] = true;
                qt.push(parents[curr]);
            }
        }
        if (isDeletedSomething)
        {
            time++;
        }
    }
    // cout << time << "\n";
    return time;
}

int main()
{
    return 0;
}