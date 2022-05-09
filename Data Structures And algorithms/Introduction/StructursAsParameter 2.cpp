#include <iostream>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

struct Rectangle
{
    int ll;
    int bb;
};
//Setting Dimensions
void setDimensions(Rectangle &r1, int l, int b)
{
    r1.ll = l;
    r1.bb = b;
}
//Printing DImensions
void display(Rectangle r1)
{
    cout << " Length : " << r1.ll << endl;
    cout << "breadth : " << r1.bb << endl;
}

//Printing DImensions using Pointers
void display(Rectangle *ptr)
{
    cout << " Length : " << ptr->ll << endl;
    cout << "breadth : " << ptr->bb << endl;
}

//Area Function using pointer
int Area(Rectangle *ptr)
{
    return ptr->ll * ptr->bb;
}

//Parameter function using Refrences
int Parameter(Rectangle &r1)
{
    return 2 * (r1.ll + r1.bb);
}

//RECTANGLE TYPE FUNCTION
Rectangle *fun()
{
    Rectangle *p;
    p = new Rectangle;
    p->ll = 29;
    p->bb = 23;
    return p;
}

int main()
{
    Rectangle r1;
    Rectangle *ptr_rec;
    ptr_rec = &r1;
    setDimensions(r1, 30, 40);
    display(r1);
    cout << "the area is: " << Area(ptr_rec) << endl;
    cout << "The Parameter is: " << Parameter(r1) << endl;
    setDimensions(r1, 40, 50);
    display(r1);

    Rectangle *ptr2 = fun();
    display(ptr2);
    delete ptr2;

    return 0;
}