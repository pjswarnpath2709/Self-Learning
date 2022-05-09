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

ListNode *IntersectionPoint(ListNode *head1, ListNode *head2)
{
    if (head1 == nullptr || head2 == nullptr)
    {
        return nullptr;
    }
    ListNode *a = head1;
    ListNode *b = head2;
    while (a != b)
    {
        a = a == nullptr ? head1 : a->next;
        b = b == nullptr ? head2 : b->next;
    }
    return a;
}

int main()
{
    LinkedListMine *l1 = new LinkedListMine();

    int n1 = getInt();
    int k = getInt();
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

    l1->printList();
    return 0;
}