//File I/O in C++: Reading and Writing Files | C++ Tutorials for Beginners #60
/*
The useful classes for working with files in C++ are:
1.fstreambase
2.ifstream --> derived from fstreambase
3.ofstream --> derived from fstreambase

// in order to work with files in C++,you will have to open it.Primariliy ,there are 2 ways to open a file:
//1.using the constructor
//2.using the member function open() of the class 


*/
/*
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string st = "Harry bhai";
    string st2 = "";
    string st3;
    //opening  files using constructor
    ofstream out("samplefile.txt"); //write operation
    out << st;

    //opening file to the constructor and reading from it
    ifstream ino("samplefile2.txt");
    ino >> st2;
    getline(ino, st3);
    cout << st2;
    cout << st3;
    return 0;
}
*/

//File I/O in C++: Read/Write in the Same Program & Closing Files | C++ Tutorials for Beginners #61
/*
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    //connecting our file
    ofstream hout("samplefile.txt");

    //Creating a name string and fililng it with the string entered by user
    cout << " ENTER YOUR NAME";
    string name;
    cin >> name;

    //writing a string to the file
    hout << " My name is --> " + name;

    hout.close();
    ifstream hin("samplefile.txt");
    string content;
    getline(hin, content);

    cout << "The content of this file is :- \n"
         << content;

    return 0;
    hin.close();

}
*/

//File I/O in C++: open() and eof() functions | C++ Tutorials for Beginners #62
/*
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // ofstream out;
    // out.open("samplefile2.txt");
    // out << "This is me \n";
    // out << "This is also  me \n";
    // out << "This is  alsi me \n";

    // out.close();
    ifstream in;
    string st, st2;
    in.open("samplefile2.txt");
    //in >> st;
    // cout << st;
    // getline(in, st2); //the cursor jumps on next line 
    // cout << st2;
    // getline(in, st2); //the cursor jumps onn next line hence read the next line
    // cout << st2;
    // getline(in, st2);//the cursor jumps again to next line after taking input
    // cout << st2;


    //WHILE LOOP TO PRINT 
    while(in.eof()==0){
        getline(in,st);
        cout<<st<<endl;
    }

    in.close();

    return 0;
}
*/

//C++ Templates: Must for Competitive Programming | C++ Tutorials for Beginners #63
/*
template <class T>
class Vector{
    T * arr;
    public:
    Vector(T *arr){
        cout<<arr;
    }

}

#include <iostream>
using namespace std;


int main(){
//code here
int *ptr;
Vector <int> myVec(ptr);

return 0;
}
*/

//Writing our First C++ Template in VS Code | C++ Tutorials for Beginners #64
/*
#include <iostream>
using namespace std;
template <class T>
class Vector
{
public:
    T *arr;
    int size;
    Vector(int m)
    {
        size = m;
        arr = new T[size];
    }
    T dotProduct(Vector v)
    {
        T d = 0;
        for (int i = 0; i < size; i++)
        {
            d = d + v.arr[i] * this->arr[i];
        }
        return d;
    }
};

int main()
{
    Vector<float> v1(3);
    v1.arr[0] = 1;
    v1.arr[1] = 2;
    v1.arr[2] = 3;
    Vector<float> v2(3);
    v2.arr[0] = 2.1;
    v2.arr[1] = 3.1;
    v2.arr[2] = 4.5;
    float a = v1.dotProduct(v2);
    cout << a;

    return 0;
}
*/

//C++ Templates: Templates with Multiple Parameters | C++ Tutorials for Beginners #65
/*
CLASS TEMPLATES WITH MULTIPLE PARAMETERS
template<class T1,class T2>..........(comma separated)
class nameOfClass{};

*/
/*
#include <iostream>
using namespace std;

template <class T1, class T2>
class myClass
{
public:
    T1 data1;
    T2 data2;


    myClass(T1 a, T2 b)
    {
        data1 = a;
        data2 = b;
    }

    void display()
    {
        cout << this->data1<<"  "<<endl<< this->data2<<endl;
    }
};

int main()
{
    myClass<int, char> obj(3,'b');
    obj.display();

    myClass<int,float> obj3(45,89.007);
    obj3.display();


    //code here
    return 0;
}
*/

//C++ Templates: Class Templates with Default Parameters | C++ Tutorials for Beginners #66
/*
#include <iostream>
using namespace std;
template <class t1 = int, class t2 = float>

class Pulkit
{

public:
    t1 a;
    t2 b;

    Pulkit(t1 x, t2 y)
    {
        a = x;
        b = y;
    }
    void display()
    {
        cout << "the value of a is " << a << endl;
        cout << "the value of b is " << b << endl;
    }
};

int main()
{
    //code here
    Pulkit<> h(3, 4.97);
    h.display();

    Pulkit<char,double> h2('B',249.098);
    h2.display();


    return 0;
}
*/

//C++ Templates: Class Templates with Default Parameters | C++ Tutorials for Beginners #66
/*
#include <iostream>
using namespace std;

template <class T1, class T2>

float funcAverage(T1 a, T2 b)
{
    float avg = (a + b) / 2.0;
    return avg;
}

template <class T3, class T4>
void swapp(T3 &a, T4 &b)
{
    T3 temp = a;
    a = b;
    b = temp;
}

int main()
{
    //code here
    float a;
    a = funcAverage(34, 78.009);
    cout << a << endl;
    int x = 5;
    int y = 7;
    swapp(x, y);
    cout << x << "\t" << y;

    return 0;
}
*/

//Member Function Templates & Overloading Template Functions in C++ | C++ Tutorials for Beginners #68
/*
#include <iostream>
using namespace std;

template <class T>
class Pulkit
{

public:
    T data;
    Pulkit(T a)
    {
        data = a;
    }
    void display();
};
template <class T>
void Pulkit<T>::display()
{
    cout << "The data present is :--> " << data << endl;
}

void func(int a)  //EXACT MATCH TAKE HIGHEST PRIORITY
{
    cout << "I am first func()" << a << endl;
}
template <class T>
void func(T a)
{
    cout << "I am Templatised func()" << a << endl;
}

int main()
{

    Pulkit<float> p(5.7);
    Pulkit<char> ch('c');
    p.display();
    ch.display();
    //cout << p.data << endl;
    func(4);

    //code here
    return 0;
}
*/

//Vector In C++ STL | C++ Tutorials for Beginners #71
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
template <class T>
void display(vector<T> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        // cout << v[i] << " ";
        cout << v.at(i) << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vec1(5);
    int element, size;
    cout << vec1.size()<<endl;
    //vec1.pop_back(); //delete element from the end of vector
    //display(vec1);
    // vector<int>::iterator iter = vec1.begin();
    //  vec1.insert(iter, 566);
    //  display(vec1);
    // vec1.insert(iter + 1, 20, 56);
    // display(vec1);
    // vec1.insert(iter + 2, 560);
    // display(vec1);
    // vec1.insert(iter + 3, 5, 36); //here the seconfd argument symbolises no. of copiees to be inserted
    // display(vec1);

    vector<int> vec2(4);     //4 element int vector
    vector<char> vec3(4);    //4 element char  vector
    vector<char> vec4(vec3); // 4-element character vector with the help of vec3
    vector<int> vec(6, 3);   //6-element vector of 3's
    display(vec);
    vec2.push_back(5);
    cout << vec2.size();

    return 0;

    //code here
    return 0;
}
