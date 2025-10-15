/**********************************************************
	Title: 		dinoFight.h
	Author:  	Jocelyn Lee
	Date:  		04/12/2024
	Purpose:    Header File
**********************************************************/

#ifndef DINOFIGHT_H
#define DINOFIGHT_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>
#include <limits>
#include <cctype>
using namespace std;

struct Stats
{
    int hitPoints;
    int healthPoints;
};
struct Dino
{
    string dinoType;
    string dinoName;
    Stats dinoStats;
};

int getValidateInput(int, int, string);
void printArt();
int preloadDinos(int&, Dino []);
int enterDinos(int, int, Dino []);
void printDinos(int&, Dino []);
int fight(int&, Dino []);
int deleteDino(int, int, Dino []);
void saveToFile(int, Dino []);
int  main();

#endif
