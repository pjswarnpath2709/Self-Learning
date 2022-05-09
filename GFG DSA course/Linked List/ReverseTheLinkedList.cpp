#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        this->data = x;
        this->next = nullptr;
    }
};
class LinkedListMine
{
public:
    Node *head;
    LinkedListMine()
    {
        this->head = nullptr;
    }
    void insertNodeATBegin(int x)
    {
        Node *temp = new Node(x);
        if (head == nullptr)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }
    void insertNodeAtend(int x)
    {
        Node *temp = new Node(x);
        if (head == nullptr)
        {
            head = temp;
        }
        else
        {
            Node *curr = head;
            while (curr->next != nullptr)
            {
                curr = curr->next;
            }
            curr->next = temp;
        }
    }
    void printList()
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
};

Node *reverseLinkList(Node *head)
{
    // three pointer approach
    Node *prev = nullptr;
    Node *curr = head;
    Node *nextptr = head->next;

    while (curr->next != nullptr)
    {
        curr->next = prev;
        prev = curr;
        curr = nextptr;
        nextptr = curr->next;
    }
    curr->next = prev;
    prev = curr;
    return prev;
}
int main()
{
    LinkedListMine *l = new LinkedListMine();
    l->insertNodeATBegin(10);
    l->insertNodeATBegin(20);
    l->insertNodeATBegin(30);
    l->insertNodeATBegin(40);
    l->insertNodeATBegin(50);
    l->insertNodeAtend(100);
    l->printList();
    cout << "\n";
    l->head = reverseLinkList(l->head);
    l->printList();
}