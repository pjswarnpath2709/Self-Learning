#include <bits/stdc++.h>
using namespace std;
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
    ListNode *head;
    LinkedListMine()
    {
        this->head = nullptr;
    }
    void insertNodeATBegin(int x)
    {
        ListNode *temp = new ListNode(x);
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
        ListNode *temp = new ListNode(x);
        if (head == nullptr)
        {
            head = temp;
        }
        else
        {
            ListNode *curr = head;
            while (curr->next != nullptr)
            {
                curr = curr->next;
            }
            curr->next = temp;
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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *start = new ListNode(-1);
    start->next = head;
    ListNode *fast = start;
    ListNode *slow = start;
    for (int i = 1; i <= n; i++)
    {
        fast = fast->next;
    }
    while (fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return start->next;
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
    int n = 0;
    cin >> n;
    l->head = removeNthFromEnd(l->head, n);
    l->printList();
}