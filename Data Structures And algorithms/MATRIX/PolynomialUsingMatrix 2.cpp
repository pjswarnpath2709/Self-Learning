
#include <bits/stdc++.h>
using namespace std;

class Term
{
    int coeff;
    int exp;

public:
    Term(int coeff = 0, int exp = 0)
    {
        this->coeff = coeff;
        this->exp = exp;
    }
    void setValue(int coeff, int exp)
    {
        this->coeff = coeff;
        this->exp = exp;
    }
    int getCoeff()
    {
        return coeff;
    }
    int getExp()
    {
        return exp;
    }
};
class Poly
{
    int size;
    Term *t;

public:
    Poly(int size = 0)
    {
        this->size = size;
        t = new Term[size];
    }
    void setValues(int index, int coeff, int exp)
    {
        t[index].setValue(coeff, exp);
    }
    friend ostream &operator<<(ostream &out, Poly &p);
    friend long double Compute(Poly &p, int x);
};

int main()
{
    int size;
    int x;

    cin >> size >> x;
    Poly p(size);
    for (int i = 0; i < size; i++)
    {
        int coeff, exp;
        cin >> coeff >> exp;
        p.setValues(i, coeff, exp);
    }
    cout << p;
    cout << Compute(p, x);

    return 0;
}
ostream &operator<<(ostream &out, Poly &p)
{
    for (int i = 0; i < p.size;)
    {
        out << "(" << (p.t[i]).getCoeff() << "*x^" << (p.t[i]).getExp() << ")";
        i++;
        out << " + ";
    }
    out << " 0 ";
    out << " = ";
    return out;
}
long double Compute(Poly &p, int x)
{
    long double sum = 0;
    for (int i = 0; i < p.size; i++)
    {
        sum = sum + (pow(x, (p.t[i]).getExp()) * ((p.t[i]).getCoeff()));
    }
    return sum;
}