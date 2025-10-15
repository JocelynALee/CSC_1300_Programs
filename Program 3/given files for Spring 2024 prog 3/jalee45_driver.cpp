/*
    Title: jalee45_driver.cpp
    Author: Jocelyn Lee
    Date: March 20, 2024
    Purpose: Main Function
*/


#include "jalee45_prog3.h"

int main()
{
    char runAgain;
    do
    {
            string firstName[SIZE];
            string lastName[SIZE];
            double hoursSM[SIZE];
            double averageHours;
            double medianHours;
            double modeHours;
            int totalStudents;

        cout << "\n\n*****SOCIAL MEDIA STATISTICAL DATA PROGRAM*****\n\n";
        totalStudents = getData(firstName, lastName, hoursSM, SIZE);
            if(totalStudents == -1)
            {
                cout << "\n\nRun again? (y/n) ";
                    cin >> runAgain;
            }
                else
                {
                    cout << "\nSuccessfully entered the data on " << totalStudents << " students.\n";

                    averageHours = getAverage(hoursSM, totalStudents);
                    selectionSort(lastName, firstName, hoursSM, SIZE);
                    medianHours = getMedian(hoursSM, totalStudents);
                    modeHours = getMode(hoursSM, totalStudents);
                    printArray(firstName, lastName, hoursSM, SIZE);

                    cout << setprecision(4) << fixed;
                    cout << "\n*****STATISTICS FOR TIME SPENT ON SOCIAL MEDIA*****";
                    cout << "\nAverage: " << averageHours << " hours\n";
                    cout << "Median: " << medianHours << " hours\n";
                    
                    if(modeHours == -1)
                    {
                        cout << "Mode:  The set has no mode.";
                    }
                        else
                        {
                            cout << "Mode: " << modeHours << " hours\n";
                        }
                    cout << "\n\nRun again? (y/n) ";
                        cin >> runAgain;
                }
    }while((runAgain == 'y') || (runAgain == 'Y'));
    cout << "Bye!";
    return 0;
}