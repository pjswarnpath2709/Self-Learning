#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
public:
    stack<int> st1; // al the elements will be present here
    stack<int> st2;
    int rear;

    // non reccursive pushIn
    void pushIn_non_recurrsive(int a)
    {
        rear = a;
        if (this->isEmpty())
        {
            st1.push(a);
            return;
        }

        // step 1 : remove all elements from the first stack and put it in second stack
        while (!st1.empty())
        {
            int ele = st1.top();
            st1.pop();
            st2.push(ele);
        }
        // step 2:  put the newly inserted element also here
        st2.push(a);

        // step 3: put all the elements back in stack 1
        while (!st2.empty())
        {
            int ele = st2.top();
            st2.pop();
            st1.push(ele);
        }
    }

    // recursive pushIn
    void pushIn_recurrsive(int a)
    {
        if (st1.empty())
        {
            st1.push(a);
            return;
        }
        int top = st1.top();
    }

    // pop the element out from the queue
    int pop_out()
    {
        if (this->isEmpty())
        {
            cout << "The queue is empty"
                 << "\n";
            return -1;
        }
        int frnt = front();
        st1.pop();
        return frnt;
    }

    // chk whether the queue is empty
    bool isEmpty()
    {
        if (st1.empty() && st2.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // return the front element of the queue
    int front()
    {
        return st1.top();
    }

    // returns the back of the queue
    int back()
    {
        return rear;
    }
};

int main()
{

    return 0;
}