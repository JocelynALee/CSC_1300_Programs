/*
Title: jalee45_prog1.cpp
Author: Jocelyn Lee
Date: January 29, 2024
Purpose: This program will take information about one credit card
from the user and calculate how long it will take to pay
the card off.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

// Variable Definitions
    cout << setprecision(2) << fixed;
    string CreditCard;
    double APR, minPay, PeriodicRate, MonthlyInterestFee, Principal, MonthlyBalance, NewminPay;
    double AverageDaysinMonth = 30.42, TotalInterest = 0;
    int Month = 0;

// Intro Statement
    cout << "\nThis program will take your credit card information and \n";
    cout << "compute how long it will take you to pay it off, as well \n";
    cout << "as compute the total interest that you will be paying. \n\n";

// User Data
    cout << "Name of your credit card: ";
        cin >> CreditCard;

    cout << "\nCurrent balance on your " << CreditCard << " card: $";
        cin >> MonthlyBalance;
            while (MonthlyBalance < 0 || MonthlyBalance > 99999.99)
                {
                    cout << "\nThe amount you have entered is not valid. Please try again.";
                    cout << "\nCurrent balance on your " << CreditCard << " card: $";
                        cin >> MonthlyBalance;
                }

    cout << "\nAnnual Percentage Rate (APR) on your " << CreditCard << " card: ";
        cin >> APR;
            while (APR < 0 || APR > 100)
                {
                    cout << "\nThe percentage you have entered is not valid. Please try again.";
                    cout << "\nAnnual Percentage Rate (APR) on your " << CreditCard << " card: ";
                        cin >> APR;
                }

    cout << "\nMonthly minimum payment on your " << CreditCard << " card: $";
        cin >> minPay;
            while (minPay < 0 || minPay > 99999.99)
                {
                    cout << "\nThe number you have entered is not valid. Please try again.\n";
                    cout << "\nMonthly minimum payment on your " << CreditCard << " card: $";
                        cin >> minPay;
                }

// Analysis
    cout << "\nCredit Card Debt Analysis for your " << CreditCard << " card: \n\n";
    cout << setw(22) << "Payment" << setw(16) << "Interest" << setw(16) << "Principal" << setw(16) << "Balance\n\n";
    cout << setw(62) << "$" << setw(8) << MonthlyBalance << endl;


//Calculations
    PeriodicRate = APR / 365 * 0.01;
    AverageDaysinMonth = 30.42;
    MonthlyInterestFee = MonthlyBalance * PeriodicRate * AverageDaysinMonth;
    Principal = minPay - MonthlyInterestFee;

//If you can't afford payments
    if (Principal < 0)
        {          
//Calculations
        PeriodicRate = APR / 365 * 0.01;
        AverageDaysinMonth = 30.42;
        MonthlyInterestFee = MonthlyBalance * PeriodicRate * AverageDaysinMonth;
        Principal = minPay - MonthlyInterestFee;
        MonthlyBalance = MonthlyBalance + MonthlyInterestFee - minPay;
        Month = Month + 1;

            cout << "Month" << setw(6) << Month ++ << ":" << setw(4) << "$" << setw(8) << minPay << setw(7) << "$" << setw(8) << MonthlyInterestFee << setw(7) << "$" << setw(8) << Principal << endl;
            cout << "\n\nCredit card balance will continually get larger and never be paid off.\n";
            cout << "You will need to make a payment higher than your minimum payment\n";
            cout << "of $" << minPay << " to pay off your credit card.\n";
        }

//Monthly Analysis
        else
            {
                while (MonthlyBalance > minPay)
                    {
//Calculations
                    PeriodicRate = APR / 365 * 0.01;
                    AverageDaysinMonth = 30.42;
                    MonthlyInterestFee = MonthlyBalance * PeriodicRate * AverageDaysinMonth;
                    MonthlyBalance = MonthlyBalance + MonthlyInterestFee - minPay;
                    Principal = minPay - MonthlyInterestFee;
                    Month = Month + 1;
                    TotalInterest = TotalInterest + MonthlyInterestFee;

                        cout << "Month" << setw(6) << Month << ":" << setw(4) << "$" << setw(8) << minPay << setw(7) << "$" << setw(8) << MonthlyInterestFee << setw(7) << "$" << setw(8) << Principal << setw(8) << "$" << setw(8) << MonthlyBalance << endl; 
                
    
//Final Month
                    if (MonthlyBalance < minPay)
                        {
//calculations
                        Month = Month + 1;
                        MonthlyInterestFee = MonthlyBalance * PeriodicRate * AverageDaysinMonth;
                        NewminPay = MonthlyBalance + MonthlyInterestFee; 
                        Principal = NewminPay - MonthlyInterestFee;
                        TotalInterest = TotalInterest + MonthlyInterestFee;
                        MonthlyBalance = MonthlyBalance + MonthlyInterestFee - NewminPay;
                        
                            cout << "Month" << setw(6) << Month << ":" << setw(4) << "$" << setw(8) << NewminPay << setw(7) << "$" << setw(8) << MonthlyInterestFee << setw(7) << "$" << setw(8) << Principal << setw(8) << "$" << setw(8) << MonthlyBalance << endl; 
                        }
                    }
                
                cout << "\nWith your current monthly payment of $" << minPay << " for your " << CreditCard << " card, \n";
                cout << "you will pay it off in " << Month << " months.\n\n";
                cout << "You also will have paid $" << TotalInterest << " in interest payments.\n";
            }

    return 0;
}