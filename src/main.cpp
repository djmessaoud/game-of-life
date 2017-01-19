#include <iostream>
#include "my.h"
#include <windows.h>
using namespace std;

int main()
{
    int x,y,b=0;
    field plan,plan2;
    csField(plan);
    plan2=plan;
    char k;
    cout << " ******** WELCOME TO GAME OF LIFE PROGRAM ! ******** ";
        cout << "\n\n First let's start with coordinates of your shape and how many steps you want to to live (evaluate)";
    cout << "\nX = "; cin>>x;
    cout <<"\nY = ";cin >>y;
    //cout <<"\nSteps = "; cin >> steps;
   do {
            cout << "\nPlease Enter What shape you want to use in evaluation : ";
            cout << "\n1 : Planer";
            cout << "\n2 : Small Exploder";
            cout << "\n3 : Exploder";
            cout << "\n4 : Ten Cell Row";
            cout << "\n5 : Spaceship";
            cout << "\n6 : Tumbler";
            cout << "\n7 : Gosper Glider Gun ( X should be less than 10 )";
            cout << "\ne : No Thanks, i don't want to play or i finished :)";
            cout << "\nYour Choice : ";
            cin >>k;
    switch (k) {
    case('1') : {  do { csField(plan); createPlaner(x, y, plan); play(plan,plan2);}while(b==0); break;}
    case('2') : { csField(plan); createSmallExploder(x, y, plan); play(plan,plan2); break;}
    case('3') : { csField(plan); createExploder(x, y, plan); play(plan,plan2); break;}
    case('4') : { csField(plan); createTenCellRow(x, y, plan); play(plan,plan2); break;}
    case('5') : { csField(plan); createSpaceship(x, y, plan); play(plan,plan2); break;}
    case('6') : { csField(plan); createTumbler(x, y, plan); play(plan,plan2); break;}
    case('7') : { csField(plan); createGosperGliperGun(x, y, plan); play(plan,plan2); break;}

    }
   }while (k!='e');
    return 0;
}
