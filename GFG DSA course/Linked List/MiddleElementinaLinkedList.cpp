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

ListNode *middleNode(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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
    ListNode *ans = middleNode(l->head);
    cout << ans->data << "\n";
}