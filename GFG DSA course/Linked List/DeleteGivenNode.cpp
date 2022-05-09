#include <bits/stdc++.h>
using namespace std;
int getInt()
{
    int n;
    cin >> n;
    return n;
}
struct ListNode
{
    int data;
    ListNode *next;
    ListNode(int x)
    {
        this->data = x;
        this->next = nullptr;
    }
};
class LinkedListMine
{
public:
    ListNode *head, *tail;
    LinkedListMine()
    {
        this->head = nullptr;
        this->tail;
    }
    void insertNodeATBegin(int x)
    {
        ListNode *temp = new ListNode(x);
        if (head == nullptr)
        {
            head = tail = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }
    void insertNodeAtend(int x)
    {
        ListNode *temp = new ListNode(x);
        if (head == nullptr)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    void printList()
    {
        ListNode *curr = head;
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
};

void deleteNode(ListNode *node)
{
    ListNode *temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    temp->next = nullptr;
    delete temp;
}

int main()
{
    LinkedListMine *l1 = new LinkedListMine();

    int n1 = 0;
    int k = 0;
    cin >> n1 >> k;
    for (int i = 0; i < n1; i++)
    {
        l1->insertNodeAtend(getInt());
    }
    l1->printList();
    ListNode *curr = l1->head;
    for (int i = 0; i < k; i++)
    {
        curr = curr->next;
    }
    deleteNode(curr);
    l1->printList();
    return 0;
}