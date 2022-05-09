/*
Main memory is divided into three sections:-
1.)Code  -this can be directly access by program
2.)Stack -this is also directly access by program
3.)Heap  -this cannot be accsesed directly by program hence required pointers for it

1>>
Pointer is used to access memory in Heap
2>>
Anything which is external to programrequires a pointer of same file type to be access
3>>
Pointers are used for passing parameters


Every Variables:- occupy memory in stack framework of main memory 

*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int a = 10;
    int *p; //declaration of pointer
    p = &a;

    // cout << p << endl; //printing address od a
    // cout << *p;        //derefrencing a pointer

    //GIVING MEMORY IN HEAP *IMPORTANT
    //Dynamic memory location in Heap
    int *pt1;
    pt1 = (int *)malloc(5 * sizeof(int)); //THIS IS FOR C
    //FOR C++ ITS
    int *ptr;
    ptr = new int[5]; //ptr is pointing at the arr[0] of the array in heap

    //POINTER TO AN ARRAY
    int A[5] = {2, 3, 4, 5, 6};
    int *p_arr;
    p_arr = A;
    //Here pointer is acting as name of array
    for (int i = 0; i < 5; i++)
    {
        cout << p_arr[i] << endl;
    }

    //Assining value to Heap array
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter in Heap Array" << i << endl;
        cin >> *(ptr + i);
    }

    for (int i = 0; i < 5; i++)
    {
        cout << *(ptr + i) << endl;
    }

    delete [] ptr;
    delete [] p_arr;

    return 0;
}