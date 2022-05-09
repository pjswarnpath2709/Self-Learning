#include <bits/stdc++.h>
using namespace std;

class Matrix
{
private:
    int si=0;
    int * matrix;

public:
    Matrix()
    {
        si = 0;
    }
    Matrix(int size)
    {
        this->si = size;
        matrix=new int[si];
    }
    void matrixInsert(int i, int j, int value)
    {
        if (i == j)
            matrix[i] = value;
    }

    int matrixGet(int i, int j)
    {
        return matrix[i];
    }
    void display()
    {
        for (int i = 0; i < si; i++)
        {
            for (int j = 0; j < si; j++)
            {
                if (i == j)
                    cout << matrix[i] << " ";
                else
                    cout << 0 << " ";
            }
            printf("\n");
        }
    }
    ~Matrix()
    {
    }
};
int main()
{
    int size = 0;
    cin >> size;
    //just take element at the diagonal and print them size will be given by user only
    Matrix m(size);
    cout << "you need to enter " << size << " values";
    for (int i = 0; i < size; i++)
    {
        int x;
        cin >> x;
        m.matrixInsert(i, i, x);
    }
    //displaying diagonal matrix
    m.display();
    return 0;
}
