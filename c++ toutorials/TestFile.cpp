#include <iostream>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec;
    int size;
    cin >> size;
    int a = 0;

    for (int i = 0; i < size; i++)
    {
        cin >> a;
        vec.push_back(a);
    }

    int q1;
    cin >> q1;
    vec.erase(vec.begin() + (q1 - 1));
    int q2 = 0, q3 = 0;
    cin >> q2 >> q3;
    vec.erase(vec.begin() + (q2 - 1), vec.begin() + (q3 - 1));
    cout << vec.size() << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i) << ' ';
    }

    //code here
    return 0;
}