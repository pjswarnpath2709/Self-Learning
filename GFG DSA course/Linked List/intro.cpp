#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    Node *next;
    Node(int x)
    {
        key = x;
        next = nullptr;
    }
};
Node *insertBegin(Node *head, int key)
{
    Node *temp = new Node(key);
    temp->next = head;
    return temp;
}
Node *insertEnd(Node *head, int key)
{
    if (head == nullptr)
    {
        return new Node(key);
    }
    Node *curr = head;
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }
    curr->next = new Node(key);
    return head;
}
void PrintList(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->key << " ";
        curr = curr->next;
    }
}
int main()
{
    return 0;
}