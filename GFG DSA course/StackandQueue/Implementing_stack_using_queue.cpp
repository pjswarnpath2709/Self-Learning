

#include <bits/stdc++.h>
using namespace std;

class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;

    void pushIn(int a)
    {
        if (q1.empty())
        {
            // step 1 : add in empty q
            q1.push(a);
            // step 2 : remove from q2 and push to q1 till q2 is empty
            while (!q2.empty())
            {
                int r = q2.front();
                q2.pop();
                q1.push(r);
            }
        }
        else if (q2.empty())
        {
            q2.push(a);
            while (!q1.empty())
            {
                int r = q1.front();
                q1.pop();
                q2.push(r);
            }
        }
        else
        {
            q1.push(a);
        }
    }
    int popOut()
    {
        if (this->isEmpty())
        {
            cout << "stack underflow"
                 << "\n";
            return -1;
        }
        if (q1.empty())
        {
            int top = q2.front();
            q2.pop();
            return top;
        }
        else
        {
            int top = q1.front();
            q1.pop();
            return top;
        }
    }
    int top()
    {
        if (this->isEmpty())
        {
            return -1;
        }
        if (q1.empty())
        {
            //
            return q2.front();
        }
        else
        {
            return q2.front();
        }
    }
    bool isEmpty()
    {
        if (q1.empty() && q2.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{

    return 0;
}