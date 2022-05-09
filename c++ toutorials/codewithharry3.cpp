//Ambiguity Resolution in Inheritance in C++ | C++ Tutorials for Beginners #43
/*#include <iostream>
using namespace std;
class Base1
{

public:
    void greet()
    {
        cout << "how are you " << endl;
    }
};

class Base2
{
public:
    void greet()
    {
        cout << "Hello hey there " << endl;
    }
};
class Base3
{
public:
    void greet()
    {
        cout << "Kaise ho bhia " << endl;
    }
};
class Derived : public Base1, public Base2, public Base3
{
public:
    void greet()
    {
        Base1 ::greet();
    }
};
class B
{
public:
    void say()
    {
        cout << "hello world  " << endl;
    }
};
class D : public B
{
    int a;

public:
    void say()
    {
        cout << "hello world by beautiful people " << endl;
    }
};

int main()
{
    // Base1 base1obj;
    //Base2 base2obj;
    //Base3 base3obj;

    //base1obj.greet();
    //base2obj.greet();
    B b;
    D d;
    b.say();
    d.say();
    //code here
    return 0;
}*/

//Virtual Base Class in C++ | C++ Tutorials for Beginners #44
/*#include <iostream>
using namespace std;
//Student-->Test
//Student-->sports
//{test,sports}-->results
//
//
//

class Student
{
protected:
    int roll_no;

public:
    void set_Number(int a)
    {
        roll_no = a;
    }
    void print_Number(void)
    {
        cout << "your roll no is " << roll_no << endl;
    }
};
class Test : virtual public Student
{
protected:
    float maths, physics;

public:
    void set_marks(float m1, float m2)
    {
        maths = m1;
        physics = m2;
    }
    void print_marks(void)
    {
        cout << "You result is here:" << endl
             << "Maths:  " << maths << endl
             << "Physics: " << physics << endl;
    }
};
class Sports : virtual public Student
{
protected:
    float score;

public:
    void set_score(float sc)
    {
        score = sc;
    }
    void print_score(void)
    {
        cout << "Your PT score is " << score << endl;
    }
};
class Result : public Test, public Sports
{
private:
    float total;

public:
    void display(void)
    {
        total = maths + physics + score;
        print_Number();
        print_marks();
        print_score();
        cout << " your total score is : " << total << endl;
    }
};

int main()
{
    Result harry;
    harry.set_Number(4200);
    harry.set_marks(78.9, 94.5);
    harry.set_score(5);
    harry.display();
    return 0;
}*/

//Constructors in Derived Class in C++ | C++ Tutorials for Beginners #46
/*#include <iostream>
using namespace std;
class Base1
{
private:
    int a, b;

public:
    Base1();
    Base1(int fx, int ex)
    {
        a = fx;
        b = ex;
    }
};

class Derived
{
};

int main()
{
    //code here
    return 0;
}
*/

//Code Example: Constructors in Derived Class in Cpp | C++ Tutorials for Beginners #48
/*#include <iostream>
using namespace std;

class Base1
{
    int data1;

public:
    Base1(int i)
    {
        data1 = i;
        cout << "base1 class constructor called" << endl;
    }
    void printData1(void)
    {
        cout << " the value of data1 is " << data1 << endl;
    }
};
class Base2
{
    int data2;

public:
    Base2(int i)
    {
        data2 = i;
        cout << "base2 class constructor called" << endl;
    }
    void printData2(void)
    {
        cout << " the value of data2 is " << data2 << endl;
    }
};

class Derived : public Base1, public Base2
{
int der1,der2;
public:
    Derived(int a,int b, int c,int d):Base2(b),Base1(a){
        der1=c;
        der2=d;
        cout<<"Derived class constructor called "<<endl;

    }
     void printData3(void)
    {
        cout << " the value of derived 1 is " << der1 << endl;
        cout << " the value of derived 2 is  " << der2 << endl;
    }
};

int main()
{
    Derived der(2,3,4,5);
    der.printData1();
    der.printData2();
    der.printData3();
    //code here
    return 0;
}
*/

//Initialization list in Constructors in Cpp | C++ Tutorials for Beginners #49
/*
constructor (argument-list):initilisation-section
{
    assignment + other code;
}
ex-->>
class Test{
    int a,b;
    public:
    Test(int i ,int j):a(i),b(j){       //value of i goes to a and value of j goes to b
cout<<"hey there ius constructor of test";
}
};
*/

/*#include <iostream>
using namespace std;

class Pulkit
{
    int a, b;

public:
    //Pulkit(int i, int j) : a(i), b(j)
    //Pulkit(int i, int j) : a(i), b(i*j)
    //Pulkit(int i, int j) : a(i), b(a+j)
    //Pulkit(int i, int j) : b(i), a(b+j)-->>>this will throw illogical error becuse a is declared first but not intialise first
    Pulkit(int i, int j) : a(i), b(a+j)
    {
        cout << "constructor executed " << endl;
        cout << a << " " << b;
    }
};

int main()
{
    Pulkit pel(3, 4);
    //code here
    return 0;
}*/

//Revisiting Pointers: new and delete Keywords in CPP | C++ Tutorials for Beginners #50
/*#include <iostream>
using namespace std;


class Pulkit{

public:

};


int main(){
//basic example
int a=4;
int* ptr =&a;

cout<<"the value of a is "<<*(ptr);
// new keyword
int *p=new int(40);
cout<<"the value at p is "<<*(p);

int *arr= new int[3]; //dynamically made a block of array
arr[0]=10;
arr[1]=20;
arr[2]=30;

cout<<"The value of arr[0] is "<<arr[0];
cout<<"The value of arr[1] is "<<arr[1];
cout<<"The value of arr[2] is "<<arr[2];

//delete operator
delete arr;   //to free araay 
delete [] arr; // to free all blocks

//code here
return 0;
}

*/

