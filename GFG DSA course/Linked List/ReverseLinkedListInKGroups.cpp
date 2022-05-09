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
ListNode *Kreverse(ListNode *head, int k)
{
    // base case
    if (head == nullptr)
    {
        return nullptr;
    }
    // step 1 -> reverse first K nodes
    ListNode *next = nullptr;
    ListNode *curr = head;
    ListNode *prev = nullptr;
    int count = 0;
    while (curr != nullptr && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // step 2 -> Recurrsion dekh lega aage ka
    if (next != nullptr)
    {
        head->next = Kreverse(next, k);
    }
    // step 3->return head of the NEW Linked list that would be the prev
    return prev;
}
//the leetcode wala question
class Solution
{

private:
    int getLength(ListNode *head)
    {
        int counter = 0;
        while (head != nullptr)
        {
            counter++;
            head = head->next;
        }
        return counter;
    }

private:
    ListNode *reverseKgroup(ListNode *head, int k, int len)
    {
        // base case
        if (head == nullptr)
        {
            return nullptr;
        }
        // step 1 -> reverse first K nodes
        ListNode *next = nullptr;
        ListNode *curr = head;
        ListNode *prev = nullptr;
        int count = 0;
        while (curr != nullptr && count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        len = len - k;
        // step 2 -> Recurrsion dekh lega aage ka
        if (next != nullptr && len >= k)
        {
            head->next = reverseKgroup(next, k, len);
        }
        else
        {
            head->next = next;
        }
        // step 3->return head of the NEW Linked list that would be the prev
        return prev;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int len = getLength(head);
        return reverseKgroup(head, k, len);
    }
};
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