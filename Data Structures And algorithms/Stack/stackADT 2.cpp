#include <iostream>
using namespace std;

template <class T>
struct stack
{
    int size;
    T *arr;
    int top;
};
template <class T>
class Stack
{
    stack<T> stc;

public:
    Stack(int size)
    {
        stc.top = -1;
        stc.size = size;
        stc.arr = new T[size];
    }
    bool isFull()
    {
        if (stc.top == stc.size - 1)
            return true;

        return false;
    }
    bool isEmpty()
    {
        if (stc.top == -1)
            return true;

        return false;
    }
    void push(T value)
    {
        if (isFull())
        {
            cout << "Overflow"
                 << "\n";
            return;
        }

        stc.top++;
        stc.arr[stc.top] = value;
        return;
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Underflow"
                 << "\n";
            return;
        }
        T value = stc.arr[stc.top];
        stc.top--;
        cout << value << "\n";
        return;
    }
    T peek(int posn)
    {
        int temp_pos = stc.top - posn + 1;
        if (temp_pos >= 0)
            return stc.arr[temp_pos];

        return stc.arr[-1];
    }
    T Top()
    {
        return stc.arr[stc.top];
    }
};
int main()
{
    Stack<int> st(10);
    for (int i = 0; i < 5; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }
    cout << st.Top() << " ";
    cout << st.peek(3) << "\n";
    for (int i = 0; i < 2; i++)
    {
        st.pop();
    }
    cout << st.Top() << " ";
    cout << st.peek(4) << "\n";

    return 0;
}
