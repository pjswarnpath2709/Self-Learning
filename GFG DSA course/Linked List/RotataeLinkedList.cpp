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
ListNode *rotateRight(ListNode *head, int k)
{
    if (!head || !head->next || k == 0)
    {
        return head;
    }
    // compute the length
    ListNode *curr = head;
    int len = 1;
    while (curr->next && ++len)
    {
        curr = curr->next;
    }
    // go till taht node
    curr->next = head;
    k = k % len;
    k = len - k;
    while (k--)
        curr = curr->next;
    head = curr->next;
    curr->next = nullptr;
    return head;
}
int main()
{
    LinkedListMine *l1 = new LinkedListMine();

    int n1 = getInt();
    for (int i = 0; i < n1; i++)
    {
        l1->insertNodeAtend(getInt());
    }
    l1->printList();
    return 0;
}