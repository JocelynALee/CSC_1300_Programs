/*
    Title: jalee45_prog3.h
    Author: Jocelyn Lee
    Date: March 20, 2024
    Purpose: Header File
*/

#ifndef JALEE45_PROG3_H
#define JALEE45_PROG3_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

const int SIZE = 200;
int getData(string[], string[], double[], int);
void selectionSort(string[], string[], double[], int);
void printArray(string[], string[], double[], int);
double getAverage(double[], int);
double getMedian(double[], int);
double getMode(double[], int);
int main();

#endif
