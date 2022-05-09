//Pointers to Objects and Arrow Operator in CPP | C++ Tutorials for Beginners #51
/*#include <iostream>
using namespace std;

class Complex
{
    int real, imaginary;

public:
    void getData()
    {
        cout << "The real part is " << real << endl;
        cout << "The imaginary part is " << imaginary << endl;
    }
    void setData(int a, int b)
    {
        real = a;
        imaginary = b;
    }
};

int main()
{
    Complex c1;
    //Complex *ptr = &c1;
    Complex *ptr =new Complex;
    //(*ptr).setData(1, 49);
    //(*ptr).getData();
ptr->setData(1,54);//while we use arrow operator we not really need to create an object we directly persuie using a pointer
ptr->getData();// (*ptr)=(ptr->)

    //code here
//Array of objects
Complex *ptr2=new Complex[4];
ptr2->setData(10,40);
(ptr2+1)->setData(20,30);
(ptr2+2)->setData(20,44);
(ptr2+3)->setData(10,84);

ptr2->getData();
(ptr2+1)->getData();
(ptr2+2)->getData();
(ptr2+3)->getData();
    return 0;
}
*/

//Array of Objects Using Pointers in C++ | C++ Tutorials for Beginners #52
/*#include <iostream>
using namespace std;

class ShopItem
{
    int id;
    float price;

public:
    void setData(int a, float b)
    {
        id = a;
        price = b;
    }
    void getData(void)
    {
        cout << "Code of this item is " << id << endl;
        cout << "Price of this item is " << price << endl;
    }
};

int main()
{
    int size=3;
    int id, price;
    ShopItem *ptr = new ShopItem[size];
    for (int i = 0; i < size; i++)
    {
        cout << "value of id,price of item " << i + 1 << endl;
        cin >> id >> price;
        (ptr + i)->setData(id, price);
    }

    for (int i = 0; i < size; i++)
    {
        cout << "item Number: " << i + 1 << endl;
        (ptr + i)->getData();
    }

        //code here
    return 0;
}
*/

//this Pointer in C++ | C++ Tutorials for Beginners #53
/*#include <iostream>
using namespace std;

class A
{
    int a;

public:
    A & setData(int a)
    {
      this->a=a;
      return *this;
    }
    void getData()
    {
        cout << "the value of a is " << a << endl;
    }
};

//THIS is a keyword which point to the object which invokes the member function
int main()
{
    A ab;
    ab.setData(4).getData();
    //a.getData();
    //code here
    return 0;
}
*/

//Pointers to Derived Classes in C++ | C++ Tutorials for Beginners #55
/*
#include <iostream>
using namespace std;
class BaseClass
{

public:
    int base;
    int var_base;
    void display()
    {
        cout << "Displaying Base Class Variable var_base " << var_base << endl;
    }
};
class DerivedClass : public BaseClass
{
public:
    int var_derived;
    void display()
    {

        cout << "diaplaying base class variable var_base " << var_derived << endl;
        cout << "diaplaying derived class variable var_derived " << var_derived << endl;
    }
};

int main()
{
    //Polymorphism
    BaseClass *base_class_pointer;

    BaseClass obj1;

    DerivedClass obj_derived;

    base_class_pointer = &obj_derived; //pointing to base class

    base_class_pointer->var_base = 3400;
    //base_class_pointer->var_derived=134; --->>> not allowed will throw an error
    base_class_pointer->display();

    DerivedClass *derived_class_pointer;
    derived_class_pointer = &obj_derived;

    derived_class_pointer->var_base = 123;
    derived_class_pointer->var_derived = 123;
    derived_class_pointer->display();

    return 0;
}
*/

//Virtual Functions in C++ | C++ Tutorials for Beginners #56
/*
#include <iostream>
using namespace std;
class BaseClass
{

public:
    int var_base = 1234;
    virtual void display()
    {
        cout << "enter the var_base -->> " << endl;
        cin >> var_base;
        cout << "Displaying Base Class Variable var_base -->> " << var_base << endl;
    }
};
class DerivedClass : public BaseClass
{
public:
    int var_derived;
    void display()
    {
        cout << "enter the var_base -->> " << endl;
        cin >> var_base;
        cout << "enter the var_derived -->> " << endl;
        cin >> var_derived;

        cout << "diaplaying base class variable var_base -->> " << var_base << endl;
        cout << "diaplaying derived class variable var_derived -- >> " << var_derived << endl;
    }
};

int main()
{
    //Polymorphism

    BaseClass *bptr;
    DerivedClass dobj;
    DerivedClass *dptr;
    bptr = &dobj;
    bptr->display();

    // dptr->display();
}
*/

//Virtual Functions Example + Creation Rules in C++ | C++ Tutorials for Beginners #5
/*
#include <iostream>
#include <string.h>
using namespace std;

class CWH
{
protected:
    string title;

    float rating;

public:
    CWH(string s, float r)
    {
        title = s;
        rating = r;
    }
    virtual void display()
    {
        cout<< " -->>base class display function<<-- "<<endl;
    }
};

class CWHVideo : public CWH
{
    int videolength;

public:
    CWHVideo(string s, float r, int vl) : CWH(s, r)
    {
        videolength = vl;
    }
    void display()
    {
        cout<< " -->> Derived class1 class display function<<-- "<<endl;
        cout << "this is an amazing video with the title:--> " << title << endl;
        cout << "Ratings:--> " << rating << " out of 5 starts " << endl;
        cout << "Length of this video is --> " << videolength << " minutes " << endl;
    }
};
class CWHText : public CWH
{
    int words;

public:
    CWHText(string s, float r, int w) : CWH(s, r)
    {
        words = w;
    }
    void display()
    {
        cout<< " -->> Derived class2class display function <<-- "<<endl;
        cout << "this is an amazing Text tutorial  with the title:--> " << title << endl;
        cout << "Ratings:--> " << rating << " out of 5 starts " << endl;
        cout << "Length of this Text article  is --> " << words << " words " << endl;
    }
};

int main()
{

    string title;
    float rating, vlen;
    int words;
    //for code with harry vedioes
    title = "Django tutorials Vedioes";
    vlen = 4.56;
    rating = 4.89;
    CWHVideo djvideo(title, rating, vlen);
    //djvideo.display();

    //for code with harry text tutorials
    title = "Django tutorials Text ";
    words = 433;
    rating = 4.89;
    CWHText djText(title, rating, words);
   // djText.display();

    CWH *tuts[2];
    tuts[0] = &djvideo;
    tuts[1] = &djText;

    tuts[0]->display();
    tuts[1]->display();

    //code here
    return 0;
}
*/

//Abstract Base Class & Pure Virtual Functions in C++ | C++ Tutorials for Beginners #58
/*
class CWH{
    protected:
        string title;
        float rating;
    public:
        CWH(string s, float r){
            title =  s;
            rating = r;
        }
        virtual void display()=0;   //pure virtual function 
};
*/





