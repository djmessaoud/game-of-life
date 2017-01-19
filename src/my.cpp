
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include "my.h"
using namespace std;

void printField(field& f) {
	system("cls");
	for (int i = 0; i<FSIZE; i++) {
		for (int j =0 ; j<FSIZE; j++) {
			cout << f.f[i][j];
		}
		cout << "\n";
	}
}
void csField(field& f) {
	for (int i = 0; i<FSIZE; i++) {
		for (int j = 0; j<FSIZE; j++) {
			if (i == 0) f.f[i][j] = '_';
			if ((j == 0 && i > 0)) f.f[i][j] = '|';
			if ((j>0) && (i>0)) f.f[i][j] = ' ';
			if (j == 0 && i == 0) f.f[i][j] = '.';
            if ((j == FSIZE-1 && i > 0)) f.f[i][j] = '|';
            if (i == FSIZE-1) f.f[i][j] = '-';
		}
	}
}
void play(field& f,field& f2) { // Play Function
char s;
for (int m=1;m<=5000;m++) {
//do {
    printField(f);
for (int i=2;i<=FSIZE-2;i++) {
    for (int j=2;j<=FSIZE-2;j++) {
        s=f.f[i][j];
        if (s==ALIVE) {
            if (rule1(j,i,f)) s=DEAD;
            else if (rule2(j,i,f)) s=ALIVE;
            else if (rule3(j,i,f)) s=DEAD;
        }
        else if (s==DEAD) if (rule4(j,i,f)) s=ALIVE;
        f2.f[i][j]=s;

    }
}
f=f2;
printField(f);
//}while (f.f[FSIZE-1][FSIZE-1]=!ALIVE);
if (f.f[FSIZE-2][FSIZE-2]==ALIVE) { break; break; break; }
// getchar(); // It's to check :D}
}
}
void fillCell(int y,int x,field& f) { // Function which create a block ( cell with 8 neighbours )
    for (int i=x-1;i<=x+1;i++) {
        for (int j=y-1;j<=y+1;j++) f.f[i][j]=ALIVE;
}
}
int neighbours(int x,int y,field& f) { // Calculate number of alive neighbours
    int k=0;
    for (int i=x-1;i<=x+1;i++) {
        for (int j=y-1;j<=y+1;j++) {
            if ((i==x) && (j==y));
            else {
                if (f.f[j][i]==ALIVE) k++;
                }

        }
    }
    return k;
     /*   for (int i=1;i<=8;i++) {
        if (f.f[x][y+1]==ALIVE) k++;
        if (f.f[x-1][y+1]==ALIVE) k++;
        if (f.f[x-1][y]==ALIVE) k++;
        if (f.f[x-1][y-1]==ALIVE) k++;
        if (f.f[x][y-1]==ALIVE) k++;
        if (f.f[x+1][y-1]==ALIVE) k++;
        if (f.f[x+1][y]==ALIVE) k++;
        if (f.f[x+1][y+1]==ALIVE) k++;
    }*/
}
bool rule1(int y,int x,field& f) { // Check Rules
return (neighbours(y,x,f)<2);
}

bool rule2(int y,int x,field& f) {
return ((neighbours(y,x,f)==2) || (neighbours(y,x,f)==3));
}

bool rule3(int y,int x,field& f) {
return (neighbours(y,x,f)>3);
}

bool rule4(int y,int x,field& f) {
    bool l;
    l= ((neighbours(y,x,f)==3) && (f.f[x][y]==DEAD));
return l;
}

void createPlaner(int x, int y, field& f)
{
	f.f[y][x - 1] = f.f[y][x] = f.f[y][x + 1] = ALIVE;
	f.f[y - 1][x + 1] = ALIVE;
	f.f[y - 2][x] = ALIVE;
}

void createSmallExploder(int x,int y,field& f)
{
    f.f[y][x - 1] = f.f[y][x] = f.f[y][x + 1] = ALIVE;
    f.f[y-1][x]=ALIVE;
    f.f[y+1][x-1]=ALIVE;
    f.f[y+1][x+1]=ALIVE;
    f.f[y+2][x]=ALIVE;
}
void createExploder (int x,int y,field& f)
{
    f.f[y][x-2]=f.f[y][x+2]=f.f[y][x]=ALIVE;
    f.f[y+1][x-2]=f.f[y+1][x+2]=ALIVE;
    f.f[y+2][x-2]=f.f[y+2][x+2]=ALIVE;
    f.f[y+3][x-2]=f.f[y+3][x+2]=ALIVE;
    f.f[y+4][x-2]=f.f[y+4][x+2]=f.f[y+4][x]=ALIVE;

}

void createTenCellRow (int x,int y,field& f)
{
    for (int i=x-5;i<x+5;i++) f.f[y][i]=ALIVE;
}
void createSpaceship (int x,int y,field& f)
{
f.f[y][x]=f.f[y-1][x+1]=f.f[y-1][x+2]=f.f[y-1][x+3]=f.f[y-1][x+4]=ALIVE;
f.f[y][x+4]=f.f[y+1][x+4]=ALIVE;
f.f[y+2][y+3]=ALIVE;
f.f[y+2][x]=ALIVE;
}
void createTumbler (int x,int y,field& f)
{
    for (int i=y;i>=y-4;i--) {
        f.f[i][x]=f.f[i][x+2]=ALIVE;
    }
    f.f[y-4][x-1]=f.f[y-3][x-1]=ALIVE;
    f.f[y-4][x+3]=f.f[y-3][x+3]=ALIVE;
    f.f[y+1][x-1]=f.f[y+1][x-2]=f.f[y][x-2]=f.f[y-1][x-2]=ALIVE;
    f.f[y+1][x+3]=f.f[y+1][x+4]=f.f[y][x+4]=f.f[y-1][x+4]=ALIVE;
}
void gShape1 (int x,int y,field& f)
{
    f.f[y][x]=f.f[y][x-1]=f.f[y+1][x]=f.f[y+1][x-1]=ALIVE;
}
void gShape2 (int x,int y,field& f)
{
    f.f[y][x+1]=f.f[y-1][x+1]=f.f[y-1][x]=ALIVE;
    f.f[y+1][x]=f.f[y+1][x-1]=f.f[y][x-1]=ALIVE;
}
void gShape3 (int x,int y,field& f)
{
f.f[y][x]=f.f[y-1][x]=f.f[y-2][x]=f.f[y-2][x+1]=f.f[y-1][x+2]=ALIVE;
}
void gShape4 (int x,int y,field& f)
{
    f.f[y][x]=f.f[y][x+1]=f.f[y][x+2]=f.f[y+1][x]=f.f[y+2][x+1]=ALIVE;
}

void createGosperGliperGun (int x,int y,field& f)
{
    gShape1(x,y,f);
    gShape2(x+8,y+1,f);
    gShape3(x+15,y+4,f);
    gShape2(x+22,y-1,f);
    gShape4(x+23,y+10,f);
    gShape1(x+34,y-2,f);
    gShape3(x+34,y+7,f);
/*gShape1(x,y,f);
f.f[y][x+8]=f.f[y][x+9]=f.f[y+1][x+9]=f.f[y+1][x+7]=f.f[y+1][x+7]=f.f[y+1][x+8]=ALIVE;
f.f[y][x+11]=f.f[y][x+12]=f.f[y-1][x+12]=f.f[y+1][x+13]=f.f[y-1][x+13]=ALIVE;
f.f[y+6][x+21]=f.f[y+7][x+20]=f.f[y+8][x+20]=f.f[y+7][x+21]=f.f[y+8][x+22]=ALIVE;
f.f[y][x+21]=f.f[y][x+22]=f.f[y-1][x+21]=f.f[y-2][x+22]=f.f[y-2][x+23]=f.f[y-1][x+23]=ALIVE;
f.f[y+3][x+30]=f.f[y+2][x+31]=f.f[y+3][x+31]=f.f[y+2][x+32]=f.f[y+4][x+32]=ALIVE;
f.f[y-2][x+33]=f.f[y-1][x+33]=f.f[y-2][x+34]=f.f[y-1][x+34]=ALIVE;*/
}
