#include <iostream>
#include "my.h"
using namespace std;

int main()
{
    field plan;
    csField(plan);
 /* plan.f[5][5]=ALIVE;
  plan.f[5][6]=ALIVE;
    plan.f[4][4]=ALIVE;
    plan.f[4][6]=ALIVE;
   plan.f[4][5]=ALIVE;
    plan.f[6][6]=ALIVE;
    plan.f[6][5]=ALIVE;
    plan.f[6][4]=ALIVE;
    plan.f[5][4]=ALIVE;
    //fillField(plan);*/
    fillCell(5,5,plan);
    //fillCell(9,5,plan);
    //plan.f[5][7]=ALIVE;
    createPlaner(20, 20, plan);
    printField(plan);
    //cout << rule4(7,5,plan);
  /*  cout << neighbours(5,5,plan);
    cout << rule1(5,5,plan) << endl;
    cout << rule2(5,5,plan) << endl;
    cout << rule3(5,5,plan) << endl;
    cout << rule4(5,5,plan) << endl;*/
    play(plan);
    return 0;
}
