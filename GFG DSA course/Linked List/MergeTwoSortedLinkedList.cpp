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

ListNode *MergeLinkedList(ListNode *head1, ListNode *head2)
{
    ListNode *temp = nullptr;
    ListNode *newHead = temp;
    if (head1 == nullptr)
    {
        return head2;
    }
    else if (head2 == nullptr)
    {
        return head1;
    }
    while (head1 != nullptr && head2 != nullptr)
    {
        if (head1->data < head2->data)
        {
            if (temp == nullptr)
            {
                temp = head1;
                head1 = head1->next;
                temp->next = nullptr;
                newHead = temp;
            }
            else
            {
                temp->next = head1;
                temp = temp->next;
                head1 = head1->next;
                temp->next = nullptr;
            }
        }
        else
        {
            if (temp == nullptr)
            {
                temp = head2;
                head2 = head2->next;
                temp->next = nullptr;
                newHead = temp;
            }
            else
            {
                temp->next = head2;
                temp = temp->next;
                head2 = head2->next;
                temp->next = nullptr;
            }
        }
    }
    if (head1 == nullptr)
    {
        temp->next = head2;
    }
    if (head2 == nullptr)
    {
        temp->next = head1;
    }

    return newHead;
}

int main()
{
    LinkedListMine *l1 = new LinkedListMine();
    LinkedListMine *l2 = new LinkedListMine();
    int n1 = 0;
    int n2 = 0;
    cin >> n1 >> n2;
    for (int i = 0; i < n1; i++)
    {

        l1->insertNodeAtend(getInt());
    }
    for (int i = 0; i < n2; i++)
    {
        l2->insertNodeAtend(getInt());
    }

    l1->head = MergeLinkedList(l1->head, l2->head);
    l1->printList();
    return 0;
}