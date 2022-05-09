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

bool DetectCycleInLinkedList(ListNode *head1)
{
    unordered_set<ListNode *> hs;
    ListNode *curr = head1;
    for (; curr != nullptr; curr = curr->next)
    {
        if (hs.find(curr) == hs.end())
        {
            hs.insert(curr);
        }
        else
        {
            return true;
        }
    }
    return false;
}
bool detectCycle(ListNode *head)
{
    // slow poinbter and fast pointer approach
    if (head == nullptr || head->next == nullptr)
    {
        return false;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
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