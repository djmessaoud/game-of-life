#pragma once

#define FSIZE 50
#define DEAD ' '
#define ALIVE 'o'

struct field { char f[FSIZE][FSIZE]; };

/*Drawing functions*/
void printField(field& f);
void csField(field& f);
void drectangle(int h, int w, int x, int y, field& f);
void dline(field& f);
void dtriangle(int x, int y, int w, field& f);
void dcircle(int x, int y, int r, field& f);
void fillCell(int y,int x,field& f);
void createPlaner(int x, int y, field& f);
void dp(int x, int y, field& f);

/*Geme of life functions*/
void play(field& f, int maxIterations = 100);
int neighbours(int y,int x,field& f);
bool rule1(int y,int x,field& f);
bool rule2(int y,int x,field& f);
bool rule3(int y,int x,field& f);
bool rule4(int y,int x,field& f);
