/**********************************************************
	Title: 		prog4.cpp
	Author:  	Jocelyn Lee
	Date:  		04/12/2024
	Purpose:    Main Function
**********************************************************/

#include "dinofight.h"

int main()
{
    /*VARIABLES*/
    int max;
    int choice;
    int numDino;
    Dino *maxCap;
    int endProgram = 0;
    int low = 0;

    /*PRINTS DINO FIGHT!*/
    printArt();

    /*ASKS MAX CAPACITY AND VALIDATES*/
    string maxCapacity = "What is the maximum capacity of the dinosaur fight arena?\n";
    max = getValidateInput(low, numeric_limits<int>::max(), maxCapacity);
    cout << endl;

    /*DYNAMIC ALLOCATION*/
    maxCap = new Dino[max];
    numDino = preloadDinos(max, maxCap);

    /*MAIN MENU OPTIONS*/
    do{
        cout << "\n\nWhat would you like to do?\n";
        cout << "\t1.  Enter dionsaurs\n";
        cout << "\t2.  Print dinosaurs\n";
        cout << "\t3.  FIGHT!\n";
        cout << "\t4.  End Program\n";
        cout << "\tEnter 1, 2, 3, or 4.\n";

        /*ASKS USER CHOICE AND VALIDATES*/ 
        int high = 4;
        string choiceQuestion = "CHOICE: ";
        choice = getValidateInput(low, high, choiceQuestion);

        switch(choice)
        {
            /*ENTERS NEW DINOSAURS*/
            case 1:
                numDino = enterDinos(max, numDino, maxCap);
                break;

            /*PRINTS OUT THE DINOSAURS*/
            case 2:
                printDinos(numDino, maxCap);
                break;
            
            /*DINOSAURS FIGHT*/
            case 3:
                fight(numDino, maxCap);
                break;
            
            /*SAVES DINOSAURS* 
             *DELETES ARRAY  *
             *ENDS PROGRAM   */
            case 4:
                saveToFile(numDino, maxCap);
                cout << "\nGood Fight!\n";
                delete [] maxCap;
                endProgram = 1;
                break;
        }
    }while(endProgram != 1);    
    return 0;
    /*The program is done running :)*/
}
