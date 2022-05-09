#include <iostream>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

/*typedef struct Rec
{
    int length;
    int breadth;
} Rectangle;

int area(Rectangle &ptr)
{
    int area = ptr.length * ptr.breadth;
    return area;
}
int parameter(Rectangle &rec)
{
    int parameter = 2 * (rec.length + rec.breadth);
    return parameter;
}
int area(Rectangle *ptr)
{
    int area = ptr->length * ptr->breadth;
    return area;
}
int parameter(Rectangle *ptrec)
{
    int parameter = 2 * (ptrec->length + ptrec->breadth);
    return parameter;
}

int main()
{
    Rectangle rec1;
    rec1.length = 20;
    rec1.breadth = 10;
    Rectangle rec2 = {10, 5}; //Declaration + Initialisation

    Rectangle *ptrec = &rec2;

    cout << "The area of rectangle is " << area(rec1) << endl;
    cout << "the parameter of rectangle is " << parameter(rec1) << endl;

    cout << "The area of rectangle 2 is " << area(ptrec) << endl;
    cout << "the parameter of rectangle 2 is " << parameter(ptrec) << endl;
    cout << sizeof(Rectangle);

    //code here

    return 0;
}*/
typedef struct Card
{

    int face;
    int shape;
    int color;
    char x; //PADING OF MEMORY

} card;

int main()
{
    cout << sizeof(card) << endl;
    int arr[20];
    int *ptr;
    ptr = arr; //Here the arr denotes the adrres of arr[0]

    card deck[3];
    card *deckptr;
    deckptr = &deck[0]; //  Here the same thing cant be done

    for (int i = 0; i < 3; i++)
    {
        cout << "enter the color for"
             << "deck[" << i << "] :-";
        cin >> deckptr->color;
        cout << "enter the face for"
             << "deck[" << i << "] :-";
        cin >> deckptr->face;
        cout << "enter the shape for"
             << "deck[" << i << "] :-";
        cin >> deckptr->shape;
        deckptr++;
    }
    deckptr = &deck[0];
    for (int i = 0; i < 3; i++)
    {
        printf("the color of deck[%d] is :- %d\n", i, deckptr->color);
        printf("the face of deck[%d] is :- %d\n", i, deckptr->face);
        printf("the shape of deck[%d] is :- %d\n", i, deckptr->shape);
        deckptr++;
    }

    return 0;
}
