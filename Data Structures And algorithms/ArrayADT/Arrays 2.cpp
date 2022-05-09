#include <iostream>

using namespace std;
class Array
{
private:
    int size;
    int *A = new int[size];
    int length;

public:
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
    //INSERTING THE N ELEMENTS:-->
    void insertElements(int n);
    //Display
    void show();
    //Adding or Appending:-->
    void Add(int n);
    //Inserting an Element at given Index:-->
    void insert(int index, int element);
    //Dleting an array from an given Index:-->
    void remove(int index);
    //Reversing An Array:-->
    void reverse();
    //Rotating an array:-->
    void rotate(char str);
    //REVERSING AN ARRAY:-->
    void rev();
    //Finding Maximum in array:-->
    int max();
    //Inserting in an sorted array
    void InsertSort(int value);
};

//MAIN METHOD:-->

int main()
{
    int length = 0;
    Array arr(10);
    cout << "Max size is 20";
    cin >> length;
    arr.insertElements(length);

    arr.Add(106);
    arr.insert(5, 999);
    arr.remove(5);
    arr.rotate('l');
    arr.rotate('r');
    arr.rev();
    cout << arr.max();


    return 0;
}

//OTHER FUNCTION DEFINATION:-->

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

void Array::Add(int n)
{
    A[length] = n;
    length++;

    show();
}

void Array::insert(int index, int element)
{
    length++;

    for (int i = length; i > index; i--)
    {
        A[i] = A[i - 1];
    }
    A[index] = element;

    show();
}

void Array::remove(int index)
{
    for (int i = index; i < length; i++)
    {
        A[i] = A[i + 1];
    }
    length--;

    show();
}

void Array::rotate(char str)
{
    if (str == 'l')
    {
        int temp = A[0];

        for (int i = 0; i < length; i++)
        {
            A[i] = A[i + 1];
        }
        A[length - 1] = temp;
    }

    if (str == 'r')
    {
        int temp = A[length - 1];

        for (int i = length - 2; i >= 0; i--)
        {
            A[i + 1] = A[i];
        }
        A[0] = temp;
    }

    show();
}

void Array::rev()
{
    int *Ar;
    Ar = new int[length];
    for (int i = 0; i < length; i++)
    {
        Ar[length - 1 - i] = A[i];
    }
    int *temp;
    temp = A;
    A = Ar;
    Ar = temp;
    delete[] Ar;
    show();
    cout << "\n";
}
int Array::max()
{
    int max = A[0];
    for (int i = 0; i < length; i++)
    {
        if (A[i] > max)
            max = A[i];
    }

    return max;
}

void Array::InsertSort(int value)
{
    if (length == size)
    {
        cout << "the array is fulled no value can be inserted";
    }

    else
    {
        int i = length - 1;
        while (value > A[i])
        {
            A[i + 1] = A[i];
        }
        A[i] = value;
        length++;
        show();
    }
}