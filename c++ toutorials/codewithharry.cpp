// Classes, Public and Private access modifiers in C++ | C++ Tutorials for Beginners #21
/*#include <iostream>
using namespace std;

class employee
{
private:
    int a,b,c;    
public:
int d,e;
void setData(int a1,int b1,int c1);
void getData();
};

void employee :: setData(int a1,int b1, int c1){
a=a1;
b=b1;
c=c1;
}
void employee :: getData()
{
cout<<"the value of a is "<<a<<endl;
cout<<"the value of b is "<<b<<endl;
cout<<"the value of c is "<<c<<endl;
cout<<"the value of d is "<<d<<endl;
cout<<"the value of e is "<<e<<endl;

}



int main(){

employee harry;
//harry.a  -->  this will throw error
harry.d=47;
harry.e=376;
harry.setData(1,2,3);
harry.getData();


//code here
return 0;     
}*/

//OOPs Recap & Nesting of Member Functions in C++ | C++ Tutorials for Beginners #22
/*
#include <iostream>
#include <string>
using namespace std;

class binary
{
private:
    string s;
    void chk_bin(void);

public:
    void read(void);
    void ones_compliment(void);
    void display(void);
};

void binary::read(void)
{
    cout << "Enter a binary number" << endl;
    cin >> s;
}

void binary::chk_bin(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '0' && s.at(i) != '1')
        {
            cout << "Incorrect binary format" << endl;
            exit(0);
        }
    }
}

void binary::ones_compliment(void)
{
    chk_bin();
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == '0')
        {
            s.at(i) = '1';
        }
       else
        {
            s.at(i) = '0';
        }
    }
}

void binary::display(void)
{
    cout<<"Displaying your binary number"<<endl;
    for (int i = 0; i < s.length(); i++)
    {
        cout << s.at(i);
    }
    cout<<endl;
}

int main()
{
    binary b;
    b.read();
    // b.chk_bin();
    b.display();
    b.ones_compliment();
    b.display();

    return 0;
}*/

//C++ Objects Memory Allocation & using Arrays in Classes | C++ Tutorials for Beginners #23
/*  #include <iostream>
using namespace std;

class Shop
{
private:
    int itemId[100];
    int itemPrice[100];
    int counter;

public:
    void initCounter(void) { counter = 0; }
    void setPrice(void);
    void displayPrice(void);
};
void Shop ::setPrice()
{
    cout << "enter Id of your item no. " << counter+1<< endl;
    cin >> itemId[counter];
    cout << "enter price of your item" << endl;
    cin >> itemPrice[counter];

    counter++;
}
void Shop ::displayPrice()
{
    for (int i = 0; i < counter; i++)
    {
        cout << "the price of item with id " << itemId[i] << "is " << itemPrice[i]<<endl;
       
}
}

int main()
{
    Shop dukaan;
    dukaan.initCounter();
    dukaan.setPrice();
    dukaan.setPrice();
    dukaan.setPrice();
    dukaan.displayPrice();

    //code here

    return 0;
}

*/

//Static Data Members & Methods in C++ OOPS | C++ Tutorials for Beginners #24
/* #include <iostream>
using namespace std;

class employee
{
    int id;
    static int count;

public:
    void setData(void)
    {
        cout << "enter the id " << endl;
        cin >> id;
        count++;
    }
    void getData(void)
    {

        cout << "the id of this employee is " << id << "and this is employee no. count " << count << endl;
    }
    static void getCount(void)  //static functions ONLY USE static variables and cannot be used with obejcts directly
    {
        cout << "for above the value of count is " << count << endl;
    }
};

int employee ::count; //default value is zero

int main()
{

    employee pulkit, harry, lavish;
    pulkit.setData();
    pulkit.getData();
    employee ::getCount();      //  SYNTAX TO CALL STATIC FUNCTION
    lavish.setData();
    lavish.getData();
    employee ::getCount();
    harry.setData();
    harry.getData();
    employee ::getCount();
    return 0;
} */

//Array of Objects & Passing Objects as Function Arguments in C++ | C++ Tutorials for Beginners #25

//PART A:-ARRAY OF OBJECTS
/*#include <iostream>
using namespace std;

class employee
{
    int id;
    int salary;

public:
    void setId(void)
    {
        cout << "enter id of employee" << endl;
        cin >> id;
    }
    void getId(void)
    {
        cout << "the id of this employee is" << id << endl;
    }
};

int main()
{
  
    
    employee fb[4];
    for (int i = 0; i < 4; i++)
    {
        fb[i].setId();
        fb[i].getId();
    }

    return 0;
}
*/
//PART B
/*#include <iostream>
using namespace std;

class complex
{
    int a, b;

public:
    void setData(int v1, int v2)
    {
        a = v1;
        b = v2;
    }
    void setDatabySum(complex o1, complex o2)
    {
        a = o1.a + o2.a;
        b = o1.b + o2.b;
    }
    void display(void)
    {
        cout << "the complex no. is " << endl;
        cout << a << "+ i" << b<<endl;
    }
};

int main()
{
    complex c1, c2, c3;
    c1.setData(1, 2);
    c1.display();
    c2.setData(5, 8);
    c2.display();
    c3.setDatabySum(c1, c2);
    c3.display();

    //code here

    return 0;
}
*/

//Friend Functions in C++ | C++ Tutorials for Beginners #26
/*#include <iostream>
using namespace std;

class Complex
{
    int a, b;
    friend Complex sumComplex(Complex o1, Complex o2); 

public:
    void setNumber(int n1, int n2)
    {
        a = n1;
        b = n2;
    }

    // Below line means that non member - sumComplex funtion is allowed to do anything with my private parts (members)
    void printNumber()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};

Complex sumComplex(Complex o1, Complex o2)
{
    Complex o3;
    o3.setNumber((o1.a + o2.a), (o1.b + o2.b));
    return o3;
}

int main()
{
    Complex c1, c2, sum;
    c1.setNumber(1, 4);
    c1.printNumber();

    c2.setNumber(5, 8);
    c2.printNumber();

    sum = sumComplex(c1, c2);
    sum.printNumber();

    return 0;
}
*/

/* Properties of friend functions
1. Not in the scope of class
2. since it is not in the scope of the class, it cannot be called from the object of that class. c1.sumComplex() == Invalid
3. Can be invoked without the help of any object
4. Usually contans the objects as arguments
5. Can be declared inside public or private section of the class
6. It cannot access the members directly by their names and need object_name.member_name to access any member.

*/

//Friend Classes & Member Friend Functions in C++ | C++ Tutorials for Beginners #27

/* #include <iostream>
using namespace std;

// Forward declaration
class Complex;

class Calculator
{
public:
    int add(int a, int b)
    {
        return (a + b);
    }

    int sumRealComplex(Complex, Complex);
    int sumCompComplex(Complex, Complex);
};

class Complex
{
    int a, b;
    // Individually declaring functions as friends
    // friend int Calculator ::sumRealComplex(Complex, Complex);
    // friend int Calculator ::sumCompComplex(Complex, Complex);

    // Aliter: Declaring the entire calculator class as friend
    friend class Calculator;

public:
    void setNumber(int n1, int n2)
    {
        a = n1;
        b = n2;
    }

    void printNumber()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};

int Calculator ::sumRealComplex(Complex o1, Complex o2)
{
    return (o1.a + o2.a);
}

int Calculator ::sumCompComplex(Complex o1, Complex o2)
{
    return (o1.b + o2.b);
}

int main()
{
    Complex o1, o2;
    o1.setNumber(1, 4);
    o2.setNumber(5, 7);
    Calculator calc;
    int res = calc.sumRealComplex(o1, o2);
    cout << "The sum of real part of o1 and o2 is " << res << endl;
    int resc = calc.sumCompComplex(o1, o2);
    cout << "The sum of complex part of o1 and o2 is " << resc << endl;
    return 0;
}
*/

//More on C++ Friend Functions (Examples & Explanation) | C++ Tutorials for Beginners #28
//EXAMPLE 1
/*#include <iostream>
using namespace std;

class Y;
class X
{
    int data;
    friend void add(X a1, Y b1);

public:
    void setValue(int value)
    {
        data = value;
    }
};
class Y
{
    int num;
    friend void add(X a1, Y b1);

public:
    void setValue(int value)
    {
        num = value;
    }
};
void add(X o1, Y o2)
{
    cout << "summing data of X and Y objects gives me " << o1.data + o2.num;
}

int main()
{
    X a;
    a.setValue(3);

    Y b;
    b.setValue(6);

    add(a, b);

    return 0;
}*/
//EXAMPLE 2
/*#include <iostream>
using namespace std;
class c2;
class c1
{
    int val1;
    friend void exchange(c1 &x, c2 &y);

public:
    void indata(int a)
    {
        val1 = a;
    }
    void display(void)
    {
        cout << val1 << endl;
    }
};
class c2
{
    int val2;
    friend void exchange(c1 &x, c2 &y);

public:
    void indata(int b)
    {
        val2 = b;
    }
    void display(void)
    {
        cout << val2 << endl;
    }
};

void exchange(c1 &x, c2 &y)
{
    int temp = x.val1;
    x.val1 = y.val2;
    y.val2 = temp;
}

int main()
{
    c1 a;
    c2 b;
    cout << "the old values of the obnjects are" << endl;
    a.indata(45);
    a.display();
    b.indata(56);
    b.display();

    exchange(a, b);

    cout << "the new values of the obnjects are" << endl;
    a.display();
    b.display();

    //code here

    return 0;
}*/

//Constructors In C++ | C++ Tutorials for Beginners #29
/* #include <iostream>
using namespace std;

class Complex
{
    int a, b;

public:
    //creating a constructor
    //Constructer is a special member of function with same name as of the class.
    //whenever an object is created it is automatically invoked
    //it is used to intialiose the obejcts of its class
    Complex(void); //constructor declaration
    void printNumber(void)
    {
        cout << "the complex no. is " << a << "+ i" << b;
    }
};
Complex ::Complex(void) //Constructer declaration -->THIS A DEFAULT CONSTRUCTOR
{
    cout << "put the value of a" << endl;
    cin >> a;
    cout << "put the value of b" << endl;
    cin >> b;
}
int main()
{
    Complex c;
    c.printNumber();

    return 0;
} */
//PROPERTIES OF CONSTRUCTOR
/*
1.SHOULD BE DECLARE IN PUBLIC SECTION OF CLASS
2.THEY ARE INVOKED AUTOMATICALLY
3. THEY CANNOT RETURN VALUES AND DO NOT HAVE RETURN TYPES
4. IT CAN HAVE DEFAULT ARGUMENTS
5.WE CANNOT REFER TO THEIR ADDRESS
*/

//Parameterized and Default Constructors In C++ | C++ Tutorials for Beginners #30
//  PART NO. 1
/*#include <iostream>
using namespace std;

class Complex
{
    int a, b;
    friend void addComplex(Complex, Complex);

public:
    Complex(int, int);

    void printNumber()
    {
        cout << "your number is " << a << "+ i" << b << endl;
    }
};
//PARAMITARISED CONSTRUCTOR
Complex ::Complex(int x, int y)
{
    a = x;
    b = y;
}
void addComplex(Complex c1, Complex c2)
{
    cout << "your number is " << c1.a + c2.a << "+ i" << c1.b + c2.b << endl;
}

int main()
{
    //Implicit call
    Complex c1(4, 6);
    c1.printNumber();
    //explicit call
    Complex c2 = Complex(5, 7);
    c2.printNumber();

    addComplex(c1, c2);
    return 0;
}*/
//PART NO. 2
/*#include <iostream>
#include <cmath>
using namespace std;
class point
{
    int x, y;
    friend float Dis(point, point);

public:
    point()
    {
        cout << "enter the point" << endl;
        cout << "the value of x ";
        cin >> x;
        cout << "the value of y ";
        cin >> y;
        cout << endl;
    }
    void displayPoint()
    {
        cout << "The point is(" << x << "," << y << ")" << endl;
    }
};

float Dis(point p1, point p2)
{
    int a = p1.x - p2.x;
    int b = p1.y - p2.y;
    float c = sqrt(a * a + b * b);
    return c;
}

int main()
{

    point p1;
    p1.displayPoint();
    point p2;
    p2.displayPoint();
    cout << "the value of the distance between two points entered by you is " << Dis(p1, p2);

    return 0;
}
*/

//Constructor Overloading In C++ | C++ Tutorials for Beginners #31
/*#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
    int a, b;

public:
    Complex(int x, int y)
    {
        a = x;
        b = y;
    }
    Complex(int x)
    {
        a = x;
        b = 0;
    }
    void printData(void)
    {
        cout << "your no. is " << a << "+ i" << b << endl;
    }
};

int main()
{
    Complex c1(4, 6);
    c1.printData();
    Complex c2(5);
    c2.printData();
    return 0;
}
*/

//Constructors With Default Arguments In C++ | C++ Tutorials for Beginners #32
/*#include <iostream>
using namespace std;

class Simple
{
    int data1;
    int data2;
    int data3;

public:
    Simple(int a = 7, int b = 9, int c = 8)
    {
        data1 = a;
        data2 = b;
        data3 = c;
    }
    void printData();
};
void Simple::printData()
{
    cout << "the value of the data1 is " << data1 << " and data2 is " << data2 << " and data3 is " << data3 << endl;
}

int main()
{
    Simple s(1);
    s.printData();
    Simple s2(1, 2, 4);
    s2.printData();
    return 0;
}*/

//Dynamic Initialization of Objects Using Constructors | C++ Tutorials for Beginners #33
/* #include <iostream>
using namespace std;

class BankDeposit
{
    int pricipal;
    int years;
    float interestRate;
    float returnValue;

public:
    BankDeposit() {} //AGAR p,y,r ki value nahi bhi de paye toh bhi object ban paye
    BankDeposit(int p, int y, float r);
    BankDeposit(int p, int y, int r);
    void show();
};
BankDeposit ::BankDeposit(int p, int y, float r)
{
    pricipal = p;
    years = y;
    interestRate = r;

    returnValue = pricipal;
    for (int i = 0; i < y; i++)
    {
        returnValue = returnValue * (1 + interestRate);
    }
}
BankDeposit ::BankDeposit(int p, int y, int r)
{
    pricipal = p;
    years = y;
    interestRate = float(r) / 100;

    returnValue = pricipal;
    for (int i = 0; i < y; i++)
    {
        returnValue = returnValue * (1 + interestRate);
    }
}
void BankDeposit::show()
{
    cout << endl
         << "Principal amount was " << pricipal
         << " return value after " << years << "  years is " << returnValue;
}

int main()
{
    BankDeposit bd1, bd2, bd3;
    int p, y;
    float r;
    int R;

    cout << "enter the value of p y and r" << endl;
    cin >> p >> y >> r;
    bd1 = BankDeposit(p, y, r);
    bd1.show();

    return 0;
}*/

//Copy Constructor in C++ | C++ Tutorials for Beginners #34
/* #include <iostream>
using namespace std;

class Number
{
    int a = 0;

public:
    Number() {}
    Number(int num)
    {
        a = num;
    }
    Number(Number &obj) //-->copy constructor called
    {
        cout << "Copy constructor called -->" << endl;
        a = obj.a;
    }
    void display()
    {
        cout << "the number fot this object is " << a << endl;
    }
};

//--> when no copy constructor is found compiler supplies its own copy constructor

int main()
{
    Number x, y, z(45), z2; // --> ek sath itne object banane ke liye default constructer must hain

    x.display();
    y.display();
    z.display();
    Number z1(z); //copy constructor invoked
    z1.display();

    z2 = z;        //copy constructor not invoked -->yaha object z2 bana banaya hua rakha hain
    Number z3 = z; //copy instructorn invoked -->yaha object z3 just bana hi hain

    return 0;
}*/

//Destructor in C++ in Hindi | C++ Tutorials for Beginners #35
/* #include <iostream>
using namespace std;
int count = 0;
//Destructor never takes an argument nor does it return any value

class Num
{

public:
    Num()
    {
        count++;
        cout << "this the time when constructor is called for object no. " << count << endl;
    }
    ~Num()
    {
        cout << "this the time when my distructor is called for object no. " << count << endl;
        count--;
    }
};

int main()
{
    cout << "we are inside our main function " << endl;
    cout << "Creating first object n1" << endl;

    Num n1;
    {
        cout << " entering this block " << endl;
        cout << " creating two more objects " << endl;
        Num n2, n3;
        cout << " Exiting this block " << endl;
    }
    cout << "Back to main" << endl;

    //code here

    return 0;
}*/

//Inheritance Syntax & Visibility Mode in C++ | C++ Tutorials for Beginners #37
/* #include <iostream>
using namespace std;

// Base Class
class Employee
{
public:
    int id;
    float salary;
    Employee(int inpId)
    {
        id = inpId;
        salary = 34.0;
    }
    Employee() {}
};*/
// Derived Class syntax
/*
class {{derived-class-name}} : {{visibility-mode}} {{base-class-name}}
{
    class members/methods/etc...
}*/ 
//Note:
//1. Default visibility mode is private
//2. Public Visibility Mode: Public members of the base class becomes Public members of the derived class
//3. Private Visibility Mode: Public members of the base class becomes Private members of the derived class
//4. Private members are never inherited
// Creating a Programmer class derived from Employee Base class
/* class Programmer : public Employee
{
public:
    int languageCode;
    Programmer(int inpId)
    {
        id = inpId;
        languageCode = 9;
    }
    void getData(){
        cout<<id<<endl;
    }
};

int main()
{
    Employee harry(1), rohan(2);
    cout << harry.salary << endl;
    cout << rohan.salary << endl;
    Programmer skillF(10);
    cout << skillF.languageCode<<endl;
    cout << skillF.id<<endl;
    skillF.getData();
    return 0;
}
*/




