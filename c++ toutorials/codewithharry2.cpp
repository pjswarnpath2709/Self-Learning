//Single Inheritance Deep Dive: Examples + Code | C++ Tutorials for Beginners #38
/* #include <iostream>
using namespace std;

class Base
{
    int data1; //private by defualt and is not inheritable
public:
    int data2;
    Base() {}
    void setData();
    int getData1();
    int getData2();
};

void Base ::setData(void)
{
    data1 = 10;
    data2 = 20;
}

int Base ::getData1(void)
{
    return data1;
}

int Base ::getData2(void)
{
    return data2;
}

class Derived : public Base //--->>>suppose it is called privately
{

    int data3;

public:
    Derived() {}
    void process();
    void display();
};

void Derived ::process()
{
    //setData(); --->>> use ser data here when the class derived is called privately
    data3 = data2 * getData1();
}
void Derived ::display()
{
    cout << " Value of data 1 is " << getData1() << endl;
    cout << " Value of data 2 is " << data2 << endl;
    cout << " Value of data 3 is " << data3 << endl;
}

int main()
{
    Derived der;
    der.setData();
    der.process();
    der.display();

    //code here

    return 0;
}
*/

//Protected Access Modifier in C++ | C++ Tutorials for Beginners #39
/*#include <iostream>
using namespace std;

class Base
{
protected:
    int a;

private:
    int b;
};*/
/*
For a protected member:
                        Public derivation   Private Derivation   Protected Derivation
    1. Private members      Not Inherited   Not Inherited       Not Inherited
    2. Protected members    Protected       Private             Protected
    3. Public members       Public          Private             Protected
*/
/*class Derived : protected Base
{
};

int main()
{
    Base b;
    Derived d;
    // cout<<d.a; // Will not work since a is protected in both base as well as derived class
    return 0;
}*/

//Multi-level Inheritance Deep Dive with Code Example in C++ | C++ Tutorials for Beginners #40
/*
#include <iostream>
using namespace std;
class Student
{
protected:
    int roll_number;

public:
    void set_roll_number(int);
    void get_roll_number(void);
};
void Student ::set_roll_number(int r)
{
    roll_number = r;
}
void Student ::get_roll_number()
{
    cout << " The roll number a is " << roll_number << endl;
}

class Exam : public Student
{
protected:
    float maths;
    float physics;

public:
    void set_marks(float, float);
    void get_marks(void);
};

void Exam ::set_marks(float m1, float m2)
{
    maths = m2;
    physics = m1;
}
void Exam ::get_marks()
{
    cout << " The marks obtained  in physics are:  " << physics << endl;
    cout << " The marks obtained  in maths are:  " << maths << endl;
}

class Results : public Exam
{
    float percentage;

public:
    void display()
    {
        get_roll_number();
        get_marks();
        cout << "your percentage is " << (maths + physics) / 2 << endl;
    }
};

int main()
{

    Results harry;
    harry.set_roll_number(420);
    harry.set_marks(99.9, 100.0);
    harry.display();

    //code here

    return 0;
}
*/
/*
Notes:
    If we are inherting B from A and C from B:[A-->B-->C]
1. A is the base class for B and B is the base class for C
2. A-->B-->C is called as inheritance Path
*/

//Multiple Inheritance Deep Dive with Code Example in C++ | C++ Tutorials for Beginners #41
/*#include <iostream>
using namespace std;

// Syntax for inheriting in multiple inheritance
// class DerivedC: visibility-mode base1, visibility-mode base2
// {
//      Class body of class "DerivedC"
// };

class Base1{
protected:
    int base1int;

public:
    void set_base1int(int a)
    {
        base1int = a;
    }
};

class Base2{
protected:
    int base2int;

public:
    void set_base2int(int a)
    {
        base2int = a;
    }
};

class Base3{
protected:
    int base3int;

public:
    void set_base3int(int a)
    {
        base3int = a;
    }
};

class Derived : public Base1, public Base2, public Base3
{
    public: 
        void show(){
            cout << "The value of Base1 is " << base1int<<endl;
            cout << "The value of Base2 is " << base2int<<endl;
            cout << "The value of Base3 is " << base3int<<endl;
            cout << "The sum of these values is " << base1int + base2int + base3int << endl;
        }
};*/
/*
The inherited derived class will look something like this:
Data members:
    base1int --> protected
    base2int --> protected

Member functions:
    set_base1int() --> public
    set_base2int() --> public
    set_show() --> public
*/
/* int main()
{
    Derived harry;
    harry.set_base1int(25);
    harry.set_base2int(5);
    harry.set_base3int(15);
    harry.show();
    
    return 0;
}*/

