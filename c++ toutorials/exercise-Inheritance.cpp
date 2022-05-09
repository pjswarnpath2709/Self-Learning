
/*
Create 2 classes:
    1. SimpleCalculator - Takes input of 2 numbers using a utility function and perfoms +, -, *, / and displays the results using another function.
    2. ScientificCalculator - Takes input of 2 numbers using a utility function and perfoms any four scientific operation of your chioice and displays the results using another function.

    Create another class HybridCalculator and inherit it using these 2 classes:
    Q1. What type of Inheritance are you using?
    Q2. Which mode of Inheritance are you using?
    Q3. Create an object of HybridCalculator and display results of simple and scientific calculator.
    Q4. How is code reusability implemented?
*/
#include <iostream>
#include <cmath>

using namespace std;

class Calc
{
    int a, b;

public:
    void getDataSimple()
    {
        cout << "enetr the value of a" << endl;
        cin >> a;
        cout << "Enter the value of b " << endl;
        cin >> b;
    }
    void performOpertaions()
    {
        cout << "the value of a+b is " << a + b << endl;
        cout << "the value of a-b is " << a - b << endl;
        cout << "the value of a/b is " << a / b << endl;
        cout << "the value of a*b is " << a * b << endl;
    }
};
class ScCalc
{
    int a, b;

public:
    void getDataSc()
    {
        cout << "enetr the value of a" << endl;
        cin >> a;
        cout << "Enter the value of b " << endl;
        cin >> b;
    }
    void performOpertaionsSc()
    {
        int x;
        cout << "the value of cos(a) is " << cos(a) << endl;
        cout << "the value of cos(b) is " << cos(b) << endl;
        cout << "the value of sin(b) is " << sin(b) << endl;
        cout << "the value of sin(a) is " << sin(a) << endl;
        cout << "the value of a^b is " << pow(a, b) << endl;
        cout << "the value of log(a)is " << log(a) << endl;
        cout << "the value of log(b)is " << log(b) << endl;
        cout << "the value of exp(a)is " << exp(a) << endl;
        cout << "the value of exp(b)is " << exp(b) << endl;
    }
};
class HybridCalc : public Calc, public ScCalc
{
    public:


};

int main()
{
HybridCalc clac;

    //code here

    return 0;
}