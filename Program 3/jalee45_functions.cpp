/*
    Title: jalee45_functions.cpp
    Author: Jocelyn Lee
    Date: March 20, 2024
    Purpose: Contains the rest of the functions used
*/

#include "jalee45_prog3.h"


//****************************************************************************
//                                 getData
//
// task:          All arrays pass to this function and return the number of 
//                students from the text file. Asks user for information.
//
//****************************************************************************
int getData(string firstName[], string lastName[], double hoursSM[], int SIZE)
{   
    int totalStudents;
    char answer;
    string studentFile;
    fstream inFile;

    cout << "Enter the filename with student data (student_data.txt): ";
    cin >> studentFile;

    if(studentFile == "student_data.txt")
    {
        inFile.open("student_data.txt");
	        while(getline(inFile, firstName[totalStudents], ','))
            {
                getline(inFile, lastName[totalStudents], ',');
                inFile >> hoursSM[totalStudents];
                inFile.ignore();
                totalStudents++;
            }
            inFile.close();
            return totalStudents;
    }

        else if(studentFile == "student_data_nm.txt")
        {
            inFile.open("student_data_nm.txt");
                while(getline(inFile, firstName[totalStudents], ','))
                {
                    getline(inFile, lastName[totalStudents], ',');
                    inFile >> hoursSM[totalStudents];
                    inFile.ignore();
                    totalStudents++;
                }
                inFile.close();
                return totalStudents;
        }
            else //file is not found
            {
                cout << "\nUnable to open student_data.txt!";
                return -1;
            }
}

//****************************************************************************
//                                 selectionSort
//
// task:          This function performs the selection sort algorithm on 
//                array, sorting the hours in ascending order and making sure
//                to also sort the name arrays at the same time.
//
//****************************************************************************
void selectionSort(string lastName[],string firstName[], double hoursSM[], int SIZE)
{
    int start, minIndex;
    double minValue;
    string nameTemp;
    
    for (start = 0; start < (SIZE - 1); start++)
    {
        minIndex = start;
        minValue = hoursSM[start];

        for(int index = start + 1; index < SIZE; index++)
        {
            if (hoursSM[index] < minValue)
            {
                minValue = hoursSM[index];
                minIndex = index;
            }
        }

        hoursSM[minIndex] = hoursSM[start];
        hoursSM[start] = minValue;
        nameTemp = firstName[minIndex];
        firstName[minIndex] = firstName[start];
        firstName[start] = nameTemp;
        nameTemp = lastName[minIndex];
        lastName[minIndex] = lastName[start];
        lastName[start] = nameTemp;
    }
}

//****************************************************************************
//                                 printArray
//
// task:          To print out the values in the arrays.
//
//****************************************************************************
void printArray(string firstName[], string lastName[], double hoursSM[], int SIZE)
{
    cout << "\nData entered from the file in ascending\n";
    cout << "order of hours spent on social media:\n\n";
    cout << setprecision(2) << fixed;
    cout << "Avg. Hours Per Day" << setw(12) << "First Name" << setw(14) << "Last Name" << endl;
    cout << "*******************" << setw(15) << "**************" << setw(14) << "*************" << endl;
    for(int i = 0; i < SIZE; i++)
    {
        if(hoursSM[i] != 0)
        {
        cout << left << setw(20) << hoursSM[i] << left << setw(15) << firstName[i] << lastName[i] << endl;
        }   
    }
}

//****************************************************************************
//                                 getAverage
//
// task:          Calculates and returns the average of the student's hours 
//                spent on social media.
//
//****************************************************************************
double getAverage(double hoursSM[], int SIZE)
{
    double averageHours;
    double tHours = 0;

    for(int i = 0; i < SIZE; i++)
    {
        if(hoursSM[i] != 0)
        {
        tHours += hoursSM[i];
        }
    }
    averageHours = tHours / SIZE;
    return averageHours;
}

//****************************************************************************
//                                 getMedian
//
// task:          Calculates and returns the median of the student's hours 
//                spent on social media.
//
//****************************************************************************
double getMedian(double hoursSM[], int SIZE)
{
    double medianHours = 0;
    int median = SIZE / 2;
    int remainder = SIZE % 2;
    int i = 0;
    int count = -1;
    double num;

    while(hoursSM[i] == 0)
    {
        i++;
        count++;
    }
    if(remainder != 1)
    {
        num = (hoursSM[median + count] + hoursSM[median + count + 1]);
        medianHours = num / 2;
    }
        else
        {
            medianHours = hoursSM[median + count];
        }
    return medianHours;
}

//****************************************************************************
//                                 getMode
//
// task:          Calculates and returns the mode of the student's hours 
//                spent on social media.
//
//****************************************************************************
double getMode(double hoursSM[], int SIZE)
{
    double modeHours = 0;
    int i = 0;
    int modefrequency = 0;
    int runlength;
    double runvalue;

    while (i <= (SIZE - 1))
    {
        runlength = 1;
        runvalue = hoursSM[i];
        if(hoursSM[i] != 0)
        {
            while (((i + runlength) <= (SIZE - 1)) && (hoursSM[i + runlength] == runvalue))
            {
                runlength += 1;
            }
                if (runlength > modefrequency)
                {
                    modefrequency = runlength;
                    modeHours = runvalue;
                }
        }
        i = i + runlength;
        
    }
    if(modefrequency > 1)
    {
        return modeHours;
    }
        else
        {
            return -1;
        }
}