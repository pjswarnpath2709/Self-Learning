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
ListNode *getCycleStart(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *entry = head;
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }
    while(fast->next&&fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            while(slow!=entry){
                slow=slow->next;
                entry=entry->next;
            }
            return entry;
        }
    }
    return nullptr;
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
    cout << "\n";
    return 0;
}