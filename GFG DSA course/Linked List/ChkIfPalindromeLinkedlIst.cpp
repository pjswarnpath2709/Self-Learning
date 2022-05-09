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
ListNode *getMid(ListNode *head)
{
    ListNode *fast = head->next;
    ListNode *slow = head;
    while (fast->next != nullptr && fast != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
ListNode *reverseLinkList(ListNode *head)
{
    // three pointer approach
    ListNode *curr = head;
    ListNode *prev = nullptr;
    ListNode *nextptr = nullptr;

    while (curr != nullptr)
    {
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
    }
    return prev;
}

bool isPalindrome(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return true;
    }
    // step 1 get the mid
    ListNode *middle = getMid(head);
    // step 2 reverse List after MIDDLE
    ListNode *temp = middle->next;
    middle->next = reverseLinkList(temp);
    // step 3 compare both halfs
    ListNode *head1 = head;
    ListNode *head2 = middle->next;
    while (head2 != nullptr)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    // step 4 repeat step 2
    temp = middle->next;
    middle->next = reverseLinkList(temp);
    return true;
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
    cout << isPalindrome(l1->head) << "\n";
    return 0;
}