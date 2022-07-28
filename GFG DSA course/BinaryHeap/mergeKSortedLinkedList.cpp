#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};
class MyComp
{
public:
    bool operator()(Node<int> *n1, Node<int> *n2)
    {
        return n1->data > n2->data;
    }
};

//////+++++++++++++++++++++++++++++++++++++++++//////

Node<int> *mergeKLists(vector<Node<int> *> &listArray)
{

    // making the head and tail to combine all the linked lists
    Node<int> *head = nullptr;
    // tail is made beacuse all the insertion will be at the tail
    Node<int> *tail = nullptr;

    priority_queue<Node<int> *, vector<Node<int> *>, MyComp> min_heap; // minHeap<Node<int>*>

    // step1:  building heap of the first element of all the linked list
    for (int i = 0; i < listArray.size(); i++)
    {
        if (listArray[i] != nullptr)
        {
            min_heap.push(listArray[i]);
        }
    }

    while (!min_heap.empty())
    {
        // take the minimum element out
        Node<int> *curr = min_heap.top();
        min_heap.pop();

        // if the head is still null , then we will set the head and tail first
        if (head == nullptr)
        {
            head = curr;
            tail = curr;
        }
        else
        {
            // the head is not null hence we have to update the tail
            tail->next = curr;
            tail = tail->next;
        }
        // now push the next node of the same list as of curr into the heap
        if (curr->next)
        {
            min_heap.push(curr->next);
        }
    }
    // return the head
    return head;
}
int main()
{
}
