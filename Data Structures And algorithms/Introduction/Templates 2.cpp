#include <iostream>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

template <class T>
class Calculator
{
    T a;
    T b;

public:
    Calculator(T a, T b)
    {
        this->a = a;
        this->b = b;
    }
    T add()
    {
        T c = a + b;

        return c;
    }
    T subtract()
    {
        T c = a - b;
        return c;
    }
    double divide()
    {
        double c = a / b;
        return c;
    }
    T multiply()
    {
        T c = a * b;
        return c;
    }
    T moduluds();
    ~Calculator()
    {
    }
};
template <class T>
T Calculator<T>::moduluds()
{

    T c;
    c = (T)a % b;
    return c;
}

int main()
{
    Calculator<int> calc(23, 67);
    cout << calc.add() << endl;
    cout << sizeof(calc.add()) << endl;

    Calculator<long> calc1(23677, 354467);
    cout << calc1.add() << endl;
    cout << sizeof(calc1.add()) << endl;

    Calculator<float> calc2(23.88, 67.55);
    cout << calc2.add() << endl;
    cout << sizeof(calc2.add()) << endl;

    Calculator<double> calc3(23.86534, 67.90876);
    cout << calc3.add() << endl;
    cout << sizeof(calc3.add()) << endl;

    Calculator<int> calc4(23, 67);
    cout << calc4.moduluds() << endl;
    cout << sizeof(calc4.moduluds()) << endl;

    return 0;
}