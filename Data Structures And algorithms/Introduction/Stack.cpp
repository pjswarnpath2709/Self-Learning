#include <iostream>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
template <class T>
class Stack
{
private:
    T *stk;
    int top;
    int size;

public:
    Stack(int sz)
    {
        size = sz;
        top = -1;
        stk = new T[size];
    }
    void push(int x);
    int pop();
};
template <class T>
void Stack<T>::push(int x)
{

    if (top == size - 1)
        cout << "Stack is full ";

    else
    {
        top++;
        stk[top] = x;
    }
}
template <class T>
int Stack<T>::pop()
{
    int x = 0;
    if (top == -1)
        cout << "Stack is Empty";

    else
    {
        x = stk[top];
        top--;
    }
}

int main()
{
    Stack<int> s(10);
    s.push(10);
    s.push(20);
    s.push(30);
    return 0;
}