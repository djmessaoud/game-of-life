#pragma once

#include <stdio.h>
#include <iostream>
#include <Windows.h>
#define FSIZE 60
#define DEAD ' '
#define ALIVE '°'
using namespace std;
struct field { char f[FSIZE][FSIZE]; };
void printField(field& f);
void csField(field& f);
void play(field& f,field& f2);
int neighbours(int y,int x,field& f);
bool rule1(int y,int x,field& f);
bool rule2(int y,int x,field& f);
bool rule3(int y,int x,field& f);
bool rule4(int y,int x,field& f);
void fillCell(int y,int x,field& f);
void createPlaner(int x, int y, field& f);
void createSmallExploder(int x,int y,field& f);
void createExploder (int x,int y,field& f);
void createTenCellRow (int x,int y,field& f);
void createSpaceship (int x,int y,field& f);
void createTumbler (int x,int y,field& f);
void gShape1 (int x,int y,field& f);
void gShape2 (int x,int y,field& f);
void gShape3 (int x,int y,field& f);
void gShape4 (int x,int y,field& f);
void createGosperGliperGun (int x,int y,field& f);
