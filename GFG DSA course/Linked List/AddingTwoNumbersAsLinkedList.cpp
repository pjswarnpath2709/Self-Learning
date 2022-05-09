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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *temp = dummy;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr || carry != 0)
    {
        int sum = 0;
        if (l1 != nullptr)
        {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != nullptr)
        {
            sum += l2->data;
            l2 = l2->next;
        }
        sum += carry;
        carry = sum / 10;
        ListNode *node = new ListNode(sum % 10);
        temp->next = node;
        temp = temp->next;
    }

    return dummy->next;
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