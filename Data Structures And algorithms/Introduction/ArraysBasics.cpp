#include <iostream>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //code here

    //FOR EACH LOOP
    int arr[10] = {1, 2, 3, 4, 5, 5, 8}; //The value at rest of indexces will be stored zero
    cout << " the size of array using sizeof():- " << sizeof(arr) << endl;

    for (int element : arr) //Just Can be used to traverse the array
    {
        cout << element << endl;
    }

    return 0;
}