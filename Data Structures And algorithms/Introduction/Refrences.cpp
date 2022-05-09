#include <iostream>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

typedef struct rectangle
{
    int ll;
    int bb;

} rec;

int main()
{

    int a = 10;
    int &r = a;
    int *ptr = &a;
    int *ptr2 = &r;
    cout << "a : " << ptr << endl;
    cout << "r : " << ptr2 << endl;

    rec r1 = {20, 23};
    rec *pt3 = &r1; // declaratrion
    //acssesing the values via Arrow operator
    cout << pt3->ll << endl
         << pt3->bb<<endl;

    //now creating a object in Heap
    rec *po;
    po = new rec;
    po->ll = 200;
    po->bb = 300;
    cout << po->ll << endl
         << po->bb;

    delete po;

    return 0;
}