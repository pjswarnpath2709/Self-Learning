
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
    //Setting Size of Array:-->
    void setSize(int size)
    {
        this->size = size;
    }
    void setLength(int len)
    {
        length = len;
    }
    //INSERTING THE N ELEMENTS:-->
    void insertElements(int n);
    //Display
    void show();
    //Merging two Sorted Element
    friend Array Merge(Array A1, Array A2);
    ~Array()
    {
        delete[] A;
    }
    
};
Array Merge(Array A1, Array A2)
{
    {
        Array A3(40);
        int i, j, k;
        i = j = k = 0;

        while (i < A1.length && j < A2.length)
        {
            if (A1.A[i] < A2.A[j])
            {
                A3.A[k++] = A1.A[i++];
            }
            else
            {
                A3.A[k++] = A2.A[j++];
            }
            for (; i < A1.length; i++)
            {
                A3.A[k++] = A1.A[i];
            }
            for (; j < A2.length; j++)
            {
                A3.A[k++] = A2.A[j];
            }
        }
        A3.setLength(A1.length + A2.length);

        return A3;
    }
}
int main()
{
    Array A1(20);
    int input;
    cout << "Size of sorted Arrays: ";
    cin >> input;
    cout << "For Array  1" << endl;
    A1.insertElements(input);

    Array A2(20);
    cout << "For Array  2" << endl;
    A2.insertElements(input);
    Array A3(40);

    A3 = Merge(A1, A2);
    A3.show();

    return 0;
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
    show();
}

void Array::show()
{
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << endl;
}