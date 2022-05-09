#include <iostream>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

class Rectangle
{
    int ll;
    int bb;

public:
    //TO SET DIMENSIONS
    Rectangle()
    {
    }
    Rectangle(int a, int b)
    {
        ll = a;
        bb = b;
    }
    void setDimensions(int a, int b)
    {
        ll = a;
        bb = b;
    }
    //TO CALCULATE AREA
    int area()
    {
        return ll * bb;
    }
    //TO CALCULATE PARAMETER
    int parameter()
    {
        return 2 * (ll + bb);
    }
    //TO DISPLAY ALL CHANGES
    int display()
    {
        cout << "length :" << ll << " "
             << "breadth :" << bb << endl;

        cout << "AREA: " << area() << " "
             << "Parameter: " << parameter() << endl;
    }

    ~Rectangle()
    {
    }
};

int main()
{
    Rectangle Rec;
    Rec.setDimensions(10, 20);
    Rec.display();
    return 0;
}