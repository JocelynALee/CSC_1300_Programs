/*
Title: jalee45_prog2.cpp
Author: Jocelyn Lee
Date: March 1, 2024
Purpose: 
*/

#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;
//Global Variables
const double TAX_RATE = .0975;

//Function Definitions
void printArt();
void enterSales();
void totalSales();

//Function: main()
//Purpose: runs the whole program :)
int main()
{ 
//Variables
    string lineofDashes(53, '-');
    int choice;
    char deleteResponse;
    fstream DailySales;
    
    printArt();
    do
    {
//Main Menu
    cout << lineofDashes << endl;
    cout<< "Marvel Superhero Store Program\n\n";
    cout << "Please select from the following menu items:\n";
    cout << "\t1. Enter Sales\n";
    cout << "\t2. Total the Daily Sales\n";
    cout << "\t3. Delete Today's Sales\n";
    cout << "\t4. End Program\n";
    cout << "\tCHOOSE 1-4: ";
        cin >> choice;
//Validating choice
        while((choice < 1)||(choice > 4))
        {
            cout << "You did not enter a valid choice.\n";
            cout << "\tCHOOSE 1-4: ";
                cin >> choice;
        }
        
            switch (choice)
            {
                case 1: 
                    enterSales();
                    break;
                case 2: 
                    totalSales();
                    break;
                case 3: 
                    cout << "\nYou wish to delete the sales.txt file? (y or n): ";
                        cin >> deleteResponse;
                            if ((deleteResponse == 'y') || (deleteResponse == 'Y'))
                            {
                                if(remove("sales.txt") != 0)
                                    cout << "\nUnable to delete sales.txt because it does not exist.\n\n";
                                else
                                    cout << "\nThe sales.txt file was successfully deleted.\n\n";
                            }
                            else //selected 'n' or 'N'
                                cout << "\nYou chose not to delete the file.\n\n";
                    break;
            }
    }while(choice != 4);
    cout << "\nThank You and Have a Marvel-ous Day!!\n";                                                 
return 0;
}

//Function: printArt()
//Purpose: Print the MARVEL Logo
    void printArt()
    {
        cout << "*****************************************************************************************************" << endl;
        cout << "*****************************************************************************************************" << endl;
        cout << "***.      .*****:      .****=       .****:         .-***.    .#****.                 :+     :********" << endl;                                                                                             
        cout << "***.      .+****.      .****.       .+***:           .:*.     +****.      .          :+     :********" << endl;
        cout << "***.       -***=       .****.        -***:              :     :****.     .:          :+     :********" << endl;
        cout << "***.       .***.       .****.        .***:     =*+.           .***=      =:     ******+     :********" << endl;
        cout << "***.        +**.       .***=    ..    +**:     =***.          .***:      *:     ******+     :********" << endl;
        cout << "***.        =*+.       .***.    :.    =**:     =***-          .+**.      *:     ******+     :********" << endl;
        cout << "***.        :*-        .***     =     :**:     =***-     .     -*+      .*:     ******+     :********" << endl;
        cout << "***.         *         .**+    .*-    .**:     =***.     :     .*=      +*:     .....:+     :********" << endl;
        cout << "***.         -         .**-    .*+     +*:     =*+.     .*.     *-     .#*:          :+     :********" << endl;
        cout << "***.     .   .   .     .**.    :**.    -*:              =*-     +.     :**:          :+     :********" << endl;
        cout << "***.     -       :     .*+     :**.    :*:             +***.    :      -**:     .....:+     :********" << endl;
        cout << "***.     =       =     .*-     =**-    .#:           .*****.           +**:     ******+     :********" << endl;
        cout << "***.     +.     .*     .*:     -==:     =:     =*.    .****:          .#**:     ******+     :********" << endl;
        cout << "***.     +=     :*     .*.              ::     =*=     +***+          -***:     ******+     :********" << endl;
        cout << "***.     +*.    +*     .+               .:     =**.    :***#.         =***:     ******+     :********" << endl;
        cout << "***.     +*.    **     .:     -++++.    .:     =**-     =***:         ****:          :+          .***" << endl;
        cout << "***.     +*:   .**     ..     +****-           =**#.    :***=        :****:          :+          .***" << endl;
        cout << "***.     +*+   =**           .*****+           =***-     =***        =****:          :+          .***" << endl;
        cout << "*****************************************************************************************************" << endl;
        cout << "*****************************************************************************************************" << endl;
    }

//Function: enterSales()
//Purpose: Takes in user data and puts it in sales.txt
    void enterSales()
    {
    int subChoice, numItems;
    double gprice, sprice, dprice;
    double gCost, sCost, dCost;
    double tax;
    ofstream DailySales;

//Department Menu
        do
        {
        cout << "\nChoose the department from the following menu:\n";
        cout << "\t1. Guardians of the Galaxy\n";
        cout << "\t2. Spider-Man\n";
        cout << "\t3. Doctor Strange\n";
        cout << "\t4. Return to Main Menu\n";
        cout << "\tCHOOSE 1-4: ";
            cin >> subChoice;
            while (subChoice < 1 || subChoice > 4)
            {
                cout << "\nYou did not enter a valid choice.\n";
                cout << "\tCHOOSE 1-4: ";
                    cin >> subChoice;
            }
                
        DailySales.open("sales.txt", ios::app);
            switch (subChoice)
            {
//Guardians of the Galaxy
                case 1: 
                    DailySales << "Guardians of the Galaxy" << endl;
                    cout << "\nWhat is the price of the item? $";
                        cin >> gprice;
                    cout << "How many did they buy? ";
                        cin >> numItems;
                    tax = TAX_RATE * gprice * numItems;
                    gCost = gprice * numItems + tax;
                    DailySales << setprecision(2) << fixed << gCost << endl;
                    break;

//Spider-Man     
                case 2:
                    DailySales << "Spider-Man" << endl;
                    cout << "\nWhat is the price of the item? $";
                        cin >> sprice;
                    cout << "How many did they buy? ";
                        cin >> numItems;
                    tax = TAX_RATE * sprice * numItems;
                    sCost = sprice * numItems + tax;
                    DailySales << setprecision(2) << fixed << sCost << endl;
                    break;

//Doctor Strange
                case 3:
                    DailySales << "Doctor Strange" << endl;
                    cout << "\nWhat is the price of the item? $";
                        cin >> dprice;
                    cout << "How many did they buy? ";     
                        cin >> numItems;
                    tax = TAX_RATE * dprice * numItems;
                    dCost = dprice * numItems + tax;
                    DailySales << setprecision(2) << fixed << dCost << endl;
                    break;
            }
        DailySales.close();
        } while (subChoice != 4);
    }

//Function: totalSales()
//Purpose: Takes info from sales.txt and outputs as a reciept
    void totalSales()
    {
//Variables
        ifstream DailySales;
        string lineofDashes(53, '-');
        time_t rawtime;
        time(&rawtime);
        string department;
        float cost;
        double gtotalCost = 0, stotalCost = 0, dtotalCost = 0;
        
    DailySales.open("sales.txt");

        if(DailySales.is_open())
        {
            while(getline(DailySales, department))
            {
                if(department == "Guardians of the Galaxy")
                {
                    DailySales >> cost;
                    gtotalCost = gtotalCost + cost;
                }
                    else if(department == "Spider-Man")
                    {
                    DailySales >> cost;
                    stotalCost = stotalCost + cost;
                    }
                        else if(department == "Doctor Strange")
                        {
                            DailySales >> cost;
                            dtotalCost = dtotalCost + cost;
                        }
            }
//Total Sales
            cout << "\nTOTAL SALES ON " << ctime(&rawtime) << "\n";
            cout << lineofDashes << endl;
            cout << setw(13) << "Guardians of the Galaxy:" << setw(13) << "$" << setw(13) << setprecision(2) << fixed << gtotalCost << endl;
            cout << setw(24) << "Spider-Man:" << setw(13) << "$" << setw(13) << setprecision(2) << fixed << stotalCost << endl;
            cout << setw(24) << "Doctor Strange:" << setw(13) << "$" << setw(13) << setprecision(2) << fixed << dtotalCost << endl;
            cout << lineofDashes << endl << endl;
            DailySales.close();
        }
        else
        cout << "\nUnable to total the daily sales because there is no input file named sales.txt\n\n";
    }