#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    int value;
    Node *next;
    Node *prev;
    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};
class DLL
{
private:
public:
    Node *head;
    Node *tail;
    DLL()
    {
        head = nullptr;
        tail = nullptr;
    }
    void insertAtBegin(int key, int value)
    {
        Node *temp = new Node(key, value);
        if (head == nullptr)
        {
            head = tail = temp;
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }
    void insertAtEnd(int key, int value)
    {
        Node *temp = new Node(key, value);
        if (head == nullptr)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }
    void deleteNode(Node *temp)
    {
        if (temp == tail)
        {
            tail = temp->prev;
            temp->prev = nullptr;
            tail->next = nullptr;
            delete temp;
        }
        Node *prev = temp->prev;
        Node *next = temp->next;
        prev->next = next;
        next->prev = prev;
        delete temp;
    }
};
class LRUCache
{
private:
    int capacity;
    unordered_map<int, Node *> *mp;
    DLL *lst;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        this->lst = new DLL();
        this->mp = new unordered_map<int, Node *>();
    }

    int get(int key)
    {
        if (!mp->count(key)) // if it does not exits
        {
            return -1;
        }
        else
        {
            // put the most recently used at the front always
            int value = mp->at(key)->value;
            lst->deleteNode(mp->at(key));
            mp->erase(key);
            lst->insertAtBegin(key, value);
            Node *add = lst->head;
            mp->insert({key, add}); // inserted as pair
            return value;
        }
    }

    void put(int key, int value)
    {
        // if it already exits
        if (mp->count(key))
        {
            // update it with new Value and Move it to the front
            lst->deleteNode(mp->at(key));
            mp->erase(key);
            lst->insertAtBegin(key, value);
            Node *add = lst->head;
            mp->insert({key, add});
        }
        // if it does not exits then we chk if the capacity was full or we can still insert the new Node
        else
        {
            // if the capacity is full
            if (mp->size() == this->capacity)
            {
                // delete the least used Node from the the DLL
                int lastKey = lst->tail->key;
                lst->deleteNode(lst->tail);
                // remove it from the map also
                mp->erase(lastKey);
                // insert the new node at head in the DLL
                lst->insertAtBegin(key, value);
                // insert it in the map also
                Node *add = lst->head;
                mp->insert({key, add});
            }
            // if neither the capacity was full nor it previously existed
            else
            {
                lst->insertAtBegin(key, value);
                Node *add = lst->head;
                mp->insert({key, add});
            }
        }
    }
};
