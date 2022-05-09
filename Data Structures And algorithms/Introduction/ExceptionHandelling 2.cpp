#include <iostream>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

class Pulkit
{

public:
};

int main()
{
    bool z = true;
    int x = 23, y;

    do
    {
        cin >> y;
        try
        {
            if (y == 0)
            {
                throw 1;
            }
            else
            {
                cout << (double)x / y;
                z = false;
                break;
            }
        }
        catch (int e)
        {
            cout << "Error:Division by zero" << endl;
        }

    } while (z = true);
}
