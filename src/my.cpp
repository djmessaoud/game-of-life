#include <cstdlib>
#include <iostream>
#include "my.h"

using namespace std;

void printField(field& f) {

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	system("cls");
#else
	system("clear");
#endif

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

void dp(int x, int y, field& f) {
	f.f[y][x] = ALIVE;
	printField(f);
}

void dline(field& f) {
	for (int i = 0; i<FSIZE; i++) {
		dp(i, i, f);
		printField(f);
	}
}

void play(field& f, int maxIterations) { // Play Function
	char s;
	for (int k = 0; k < maxIterations; k++) {
		for (int i=2;i<=FSIZE-2;i++) {
	    for (int j=2;j<=FSIZE-2;j++) {
	        s=f.f[i][j];
	        if (s==ALIVE) {
	            if (rule1(j,i,f)) s=DEAD;
	            else if (rule2(j,i,f)) s=ALIVE;
	            else if (rule3(j,i,f)) s=DEAD;
	        }
	        else if (s==DEAD) if (rule4(j,i,f)) s=ALIVE;
	        f.f[i][j]=s;
	    }
		}
		printField(f);
	}
}

void fillCell(int y, int x, field& f) { // Function which create a block ( cell with 4 neighbours )
    for (int i = x - 1; i <= x; i++)
        for (int j = y - 1; j <= y; j++)
					f.f[i][j] = ALIVE;
}

void createPlaner(int x, int y, field& f)
{
	f.f[y][x - 1] = f.f[y][x] = f.f[y][x + 1] = ALIVE;
	f.f[y - 1][x + 1] = ALIVE;
	f.f[y - 2][x] = ALIVE;
}

int neighbours(int y,int x,field& f) { // Calculate number of alive neighbours
    int k=0;
    for (int i=x-1;i<=x+1;i++) {
        for (int j=y-1;j<=y+1;j++) {
            if ((i==x) && (j==y));
            else {
                if (f.f[i][j]==ALIVE) k++;
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
    l = ((neighbours(y,x,f)==3) && (f.f[y][x]==DEAD));
		return l;
}









/*for (;;){
    for (int i=2;i<=FSIZE-2;i++) {
       plan.f[i][i]=ALIVE;
       plan.f[i][i+1]=ALIVE;
       plan.f[i+1][i]=ALIVE;
       plan.f[i-1][i+1]=ALIVE;
       system("cls");
       printField(plan);
       csField(plan);
       plan.f[i][i]=ALIVE;
       plan.f[i][i+1]=ALIVE;
       plan.f[i+1][i+1]=ALIVE;
       plan.f[i+2][i+1]=ALIVE;
       plan.f[i][i-1]=DEAD;
       plan.f[i+1][i-1]=DEAD;
       plan.f[i-1][i]=DEAD;
       system("cls");
       printField(plan);
       csField(plan);
    }
    }*/
