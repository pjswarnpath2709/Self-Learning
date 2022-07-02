

#include <bits/stdc++.h>
using namespace std;

void printMedianOfStream(vector<int> &vec)
{
    priority_queue<int> smallers;
    priority_queue<int, vector<int>, greater<int>> greaters;

    smallers.push(vec[0]);
    cout << smallers.top() << "\n";

    for (int i = 1; i < vec.size(); i++)
    {
        int value_to_pushed = vec[i];
        // first case if smallers container has the greater size
        if (smallers.size() > greaters.size())
        {
            if (value_to_pushed < smallers.top())
            {
                greaters.push(smallers.top());
                smallers.pop();
                smallers.push(value_to_pushed);
            }
            else
            {
                greaters.push(value_to_pushed);
            }
            cout << (smallers.top() + greaters.top()) / 2.0 << "\n";
        }
        // else both their sizes are equal
        else
        {
            if (value_to_pushed <= smallers.top())
            {
                smallers.push(value_to_pushed);
            }
            else
            {
                greaters.push(value_to_pushed);
                smallers.push(greaters.top());
                greaters.pop();
            }
            cout << smallers.top() << "\n";
        }
    }
}

int main()
{

    vector<int> vec = {12, 15, 10, 5, 8, 7, 16};
    printMedianOfStream(vec);

    return 0;
}