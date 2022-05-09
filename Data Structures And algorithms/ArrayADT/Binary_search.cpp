#include <iostream>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

class Array
{
private:
    int size;

    int length;

public:
    int *A = new int[size];
    Array()
    {
        this->size = 0;
        length = 0;
    }
    Array(int size)
    {
        this->size = size;
    }
    int getLength()
    {
        return length;
    }

    //INSERTING THE N ELEMENTS:-->
    void insertElements(int n);
    //showing Elements:-->
    void show();
    //Inserting in an sorted array
    void InsertSort(int value);
    //checking if array is sorted or not
    bool IsSorted();
    //Reaarange
};
void Rearrange(Array &Arr)
{
    int i, j;
    i = 0;
    j = Arr.getLength() - 1;
    while (i < j)
    {
        while (Arr.A[i] < 0)
            i++;
        while (Arr.A[i] > 0)
            j--;
        if (i < j)
        {
            swap(Arr.A[i], Arr.A[j]);
        }
        Arr.show();
    }
}

int Bin_Search(Array Arr, int Key)
{
    if (Arr.IsSorted())
    {
        int l = 0;
        int h = Arr.getLength() - 1;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (Key == Arr.A[mid])
            {
                return mid;
            }
            else if (Key < Arr.A[mid])
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return -1;
    }
    return -1;
}

void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main()
{
    Array Arr(20), Arr2(20);
    int length;
    cin >> length;

    Arr.insertElements(length);
    cout << Arr.IsSorted() << endl;
    Arr.InsertSort(23);

    int key;
    cin >> key;
    cout << Bin_Search(Arr, key) << endl;
}

void Array::InsertSort(int value)
{
    if (IsSorted())
    {
        int i = length - 1;
        while (i >= 0 && A[i] > value)
        {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = value;
        length++;
        show();
    }
    else
    {
        cout << "You inserting in an unsorted Array,Sorry!" << endl;
    }
}

void Array::insertElements(int n)
{
    try
    {
        if (n > size)
            throw -1;
        length = n;
        cout << "Enter " << n << " elements" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
    }
    catch (int r)
    {
        cout << "insertion greater than size";
    }
}
void Array::show()
{
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << endl;
}

bool Array::IsSorted()
{
    int i;
    for (i = 0; i < length; i++)
    {
        if (A[i] > A[i + 1])
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}
