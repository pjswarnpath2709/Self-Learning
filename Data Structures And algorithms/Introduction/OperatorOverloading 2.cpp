#include <iostream>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

class Complex
{
    int real;
    int img;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        img = i;
    }
    Complex operator+(Complex c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        return temp;
    }
    void setValues(int x, int y)            //Nessesary to use in istream operator overloading 
    {
        real = x;
        img = y;
    }

    // friend Complex operator+(Complex c1, Complex c2);
    friend ostream &operator<<(ostream &out, Complex c1);
    friend istream &operator>>(istream &in, Complex &c1);
};

// Complex operator+(Complex c1, Complex c2)
// {
//     Complex temp;
//     temp.real = c1.real + c2.real;
//     temp.img = c1.img + c2.img;
//     return temp;
// }
ostream &operator<<(ostream &out, Complex c1)
{
    out << c1.real << " +i" << c1.img << endl;
    return out;
}

istream &operator>>(istream &in, Complex &c1) //yaha pe refrence pass karna pada kyuki actuall wale mein change karna tha
{
    int x, y;
    in >> x >> y;
    c1.setValues(x, y);
    return in;
}

int main()
{
    Complex c1;
    Complex c2;
    Complex c3;

    cin >> c1;
    cout << c1;
    cin >> c2;
    cout << c2;
    c3 = c1 + c2;
    cout << c3;

    return 0;
}