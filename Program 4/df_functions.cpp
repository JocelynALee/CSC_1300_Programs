/**********************************************************
	Title: 		df_functions.cpp
	Author:  	Jocelyn Lee
	Date:  		04/12/2024
	Purpose:    Every Other Function
**********************************************************/

#include "dinofight.h"


//****************************************************************************
//                                 getValidateInput()
//
// task:          Validates the User's Inputs.
//
//****************************************************************************
int getValidateInput(int low, int high, string question)
{
    int validInput;
    do{
        cout << question;
        cin >> validInput;
        /*INPUT IS ABOVE RANGE*/
        if(validInput > high)
        {
            cout << "Oops. You didn't enter a number in the valid range.\n";
        }
        /*INPUT IS BELOW RANGE*/
        else if(validInput < low)
        {
            cout << "Oops! You didn't enter a positive number greater than zero.\n";
        }
        /*INPUT IS ENTERED AS A CHAR/STRING */
        while(!(cin.good()))
        {
            cout << "Oops! You must have entered something other than a number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            cout << question;
            cin >> validInput;
            if(validInput > high)
            {
                cout << "Oops. You didn't enter a number in the valid range.\n";
            }
            else if(validInput < low)
            {
                cout << "Oops! You didn't enter a positive number greater than zero.\n";
            }
        }
    }while((validInput < low) || (validInput > high) || (!(cin.good())));
    return validInput;
}

//****************************************************************************
//                                 printArt()
//
// task:          This function prints "DINO FIGHT!".
//
//****************************************************************************
void printArt()
{
	cout << endl << endl;
	cout << "########  #### ##    ##  #######     ######## ####  ######   ##     ## ######## ####\n"; 
	cout << "##     ##  ##  ###   ## ##     ##    ##        ##  ##    ##  ##     ##    ##    ####\n"; 
	cout << "##     ##  ##  ####  ## ##     ##    ##        ##  ##        ##     ##    ##    ####\n"; 
	cout << "##     ##  ##  ## ## ## ##     ##    ######    ##  ##   #### #########    ##     ##\n";  
	cout << "##     ##  ##  ##  #### ##     ##    ##        ##  ##    ##  ##     ##    ##\n";         
	cout << "##     ##  ##  ##   ### ##     ##    ##        ##  ##    ##  ##     ##    ##    ####\n"; 
	cout << "########  #### ##    ##  #######     ##       ####  ######   ##     ##    ##    ####\n";
	cout << endl;
}


//****************************************************************************
//                                 preloadDinos()
//
// task:          This function takes all of the data from 'dinosaurs.txt'
//                and puts it into the Dino array before printing out that
//                the dinosaurs have been added to the fight arena. If the
//                text file cannot be opened, it will print an error message.
//
//****************************************************************************
int preloadDinos(int& max, Dino maxCap[])
{
    /*VARIABLES*/
    int numDino = 0;
    fstream inFile;
    string hitPoints;
    string healthPoints;

    /*OPENS FILE*/
    inFile.open("dinosaurs.txt");
    if(inFile.is_open())
    {
        /*GETS DATA AND PRINTS DINOSAURS*/
        for(int i = 0; i < max; i++)
        {
            if(getline(inFile, maxCap[i].dinoType, '#'))
            {
                getline(inFile, maxCap[i].dinoName, '#');
                getline(inFile, hitPoints, '#');
                maxCap[i].dinoStats.hitPoints = stoi(hitPoints);
                getline(inFile, healthPoints, '#');
                maxCap[i].dinoStats.healthPoints = stoi(healthPoints);
                cout << maxCap[i].dinoName << " the " << maxCap[i].dinoType << " has been added to the fight arena!" << endl;
                numDino++;
            }
        }
    }
    /*ERROR MESSAGE*/
    else
    {
        cout << "Sorry. Can't load dinosaurs because dinosaurs.txt does not exist or is corrupt.\n";
    
    }
    /*CLOSES FILE*/
    inFile.close();
    return numDino;
}

//****************************************************************************
//                                 enterDinos()
//
// task:          This function allows the user to enter their own dinosaurs 
//                into the fight arena. It also validates if the user is
//                trying to add more dinosaurs than the arena can handle.
//
//****************************************************************************
int enterDinos(int max, int numDino, Dino maxCap[])
{
    /*VARIABLES*/
    int newDino = numDino;
    char answer;
    int low = 0;

    if(numDino < max)
    {   
        /*GETS USER DATA TO CREATE DINOSAUR*/
        do
        {
            int hitPoints;
            int healthPoints;
            cin.ignore();
            cout << "\nDinosaur Type: ";
            getline(cin, maxCap[newDino].dinoType);  
            
            cout << "Dinosaur Name: ";
            getline(cin, maxCap[newDino].dinoName);

            string hitPointsQuestion = "Hit Points: ";
            hitPoints = getValidateInput(low, numeric_limits<int>::max(), hitPointsQuestion);
            maxCap[newDino].dinoStats.hitPoints = hitPoints;

            string healthPointsQuestion = "Health Points: ";
            healthPoints = getValidateInput(low, numeric_limits<int>::max(), healthPointsQuestion);
            maxCap[newDino].dinoStats.healthPoints = healthPoints;

            cout << maxCap[newDino].dinoName << " the " << maxCap[newDino].dinoType << " has been added to the fight arena!\n";
            numDino++;

            /*ADDS MORE IF YES UNLESS ARENA IS FULL*/
            cout << "\n\nWant to add more dinosaurs? (y or n) ";
            cin >> answer;
    
            /* USER INPUT VALIDATION*/
            while(answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N')
            {
                cout << "\nOops. You didn't enter y or n.";
                cout << "\n\nWant to add more dinosaurs? (y or n) ";
                cin >> answer;
            }
        }while((answer == 'y' && numDino < max) || (answer == 'Y' && numDino < max));
        
        /*TOO MANY DINOSAURS*/
        if(numDino >= max)
            {
                cout << "Sorry! Your fight arena can only hold " << max << " dinosaurs.\n";
                cout << "You cannot add more.\n";
            }
    }
    else
    {
        /*ERROR MESSAGE IF ARENA IS FULL*/
        cout << "\nSorry! Your fight arena can only hold " << max << " dinosaurs.\n";
        cout << "You cannot add more.\n";
    }
    return numDino;
}

//****************************************************************************
//                                 printDinos()
//
// task:          This function prints out all of the dinosaurs in the fight  
//                arean and their stats.
//
//****************************************************************************
void printDinos(int& numDino, Dino maxCap[])
{
    if(numDino != 0)
    {
        for(int i = 0; i < numDino; i++)
        {
        cout << "\n-----------------------------------------------------------------------------\n";
        cout << "----------------------------------DINOSAUR FIGHTER " << i+1 << endl;
        cout << setw(16) << left << "NAME:" << maxCap[i].dinoName << endl;
        cout << setw(16) << left << "TYPE:" << maxCap[i].dinoType << endl;
        cout << setw(16) << left << "HIT POINTS:"<< maxCap[i].dinoStats.hitPoints;
        cout << setw(17) << left << "\nHEALTH POINTS:" << maxCap[i].dinoStats.healthPoints;
        }
    }
    else
    {
        "\nThere are no dinosaurs in your fight arena!\n";
    }
}

//****************************************************************************
//                                 fight()
//
// task:          This function will battle two dinosaurs of the user's choice 
//                in turn-based combat. Sends dead dinosaurs to deleteDino().
//                Prints error message if there are less than 2 dinosaurs in
//                the fight arena.
//
//****************************************************************************
int fight(int& numDino, Dino maxCap[])
{
    /*VARIABLES*/
    srand(time(0));
    int rounds = 3;
    int num = 0;
    string dinoFighter1;
    string dinoFighter2;
    int dinoChoice1;
    int dinoChoice2;
    int dino1Hits;
    int dino2Hits;
    int firstTurn;
    int hitRate;
    int lostDino;

    if(numDino > 2)
    {
        /*USER CHOOSES TWO DINOSAURS TO BATTLE*/
        cout << "\nWhich two dinosaurs do you want to fight?\n";
            for(int i = 0; i < numDino; i++)
            {
            cout << i+1 << ": " << maxCap[i].dinoName << " the " << maxCap[i].dinoType << endl;
            num++;
            }
        cout << "Enter the first dinosaur (enter 1 - " << num << "): ";
            cin >> dinoChoice1;
            while(dinoChoice1 < 1 || dinoChoice1 > num)
            {
                cout << "Oops. You didn't enter a number in the valid range.";
                cout << "Enter the first dinosaur (enter 1 - " << num << "): ";
                    cin >> dinoChoice1;
            }
        cout << "Enter the second dinosaur (enter 1 - " << num << "): ";
            cin >> dinoChoice2;
            while(dinoChoice2 < 1 || dinoChoice2 > num)
            {
                cout << "Oops. You didn't enter a number in the valid range.";
                cout << "Enter the first dinosaur (enter 1 - " << num << "): ";
                    cin >> dinoChoice2;
            }
        
        /*SETS DINOFIGHTERS TO ARRAY*/
        dinoFighter1 = maxCap[dinoChoice1-1].dinoName;
        dinoFighter2 = maxCap[dinoChoice2-1].dinoName;

        cout << "\n\nYES! " << dinoFighter1 << " is fighting " << dinoFighter2 << "!!\n\n\n";

        firstTurn = rand()%(2-1+1)+1;

        /*3 BATTLE ROUNDS*/
        /*UNLESS A DINOSAUR DIES :(*/
        for(int i = 0; i < rounds; i++)
        {
            cout << "\n*************** ROUND " << i+1 << "***************\n";
            switch(firstTurn)
            {
                /*DINOSAUR 1 HITS DURING THIS ROUND*/
                case 1:
                {
                    hitRate = rand()%(10-1+1)+1;
                    dino1Hits = maxCap[dinoChoice1-1].dinoStats.hitPoints / hitRate;
                    maxCap[dinoChoice2-1].dinoStats.healthPoints -= dino1Hits;
                    cout << dinoFighter1 << " hit " << dinoFighter2 << " with " << dino1Hits;

                    if(maxCap[dinoChoice2-1].dinoStats.healthPoints <= 0)
                    {
                        /*DINOSAUR 2 DIES AND DINOSAUR 1 WINS*/
                        cout << endl << dinoFighter2 << " has died.";
                        numDino = deleteDino(numDino, dinoChoice2, maxCap);
                        cout << "\n\n!!!!!!! " << dinoFighter1 << " the " << maxCap[dinoChoice1-1].dinoType << " WON !!!!!!!";
                        return numDino;
                    }
                    else
                    {
                    /*THE NEXT ROUND BEGINS*/
                    cout << endl << dinoFighter2 << " is left with " << maxCap[dinoChoice2-1].dinoStats.healthPoints << endl;
                    firstTurn = firstTurn + 1;
                    }
                    break;
                }
                /*DINOSAUR 2 HITS DURING THIS ROUND*/
                case 2:
                {
                    hitRate = rand()%(10-1+1)+1;
                    dino2Hits = maxCap[dinoChoice2-1].dinoStats.hitPoints / hitRate;
                    maxCap[dinoChoice1-1].dinoStats.healthPoints -= dino2Hits;
                    cout << dinoFighter2 << " hit " << dinoFighter1 << " with " << dino2Hits;
                    
                    if(maxCap[dinoChoice1-1].dinoStats.healthPoints <= 0)
                    {
                        /*DINOSAUR 1 DIES AND DINOSAUR 2 WINS*/
                        cout << endl << dinoFighter1 << " has died.";
                        numDino = deleteDino(numDino, dinoChoice1, maxCap);
                        cout << "\n\n!!!!!!! " << dinoFighter2 << " the " << maxCap[dinoChoice2-1].dinoType << " WON !!!!!!!";
                        return numDino;
                    }
                    else
                    {
                    /*THE NEXT ROUND BEGINS*/
                    cout << endl << dinoFighter1 << " is left with " << maxCap[dinoChoice1-1].dinoStats.healthPoints << endl;
                    firstTurn = firstTurn - 1;
                    }
                    break;
                }
            }
        
        }
        /*IF DINOSAURS MAKE IT THROUGH ALL 3 ROUNDS*/
        if(maxCap[dinoChoice1-1].dinoStats.healthPoints > maxCap[dinoChoice2-1].dinoStats.healthPoints)
            {
                /*DINOSAUR 1 WINS!*/
                cout << "\n!!!!!!! " << dinoFighter1 << " the " << maxCap[dinoChoice1-1].dinoType << " WON !!!!!!!";
            }
            else
            {
                /*DINOSAUR 2 WINS!*/
                cout << "\n!!!!!!! " << dinoFighter2 << " the " << maxCap[dinoChoice2-1].dinoType << " WON !!!!!!!";
            }
    }
    /*ERROR MESSAGE*/
    /*NOT ENOUGH DINOSAURS*/
    else
    {
        cout << "\nOh no! You do not have at least two dinosaurs to fight!\n";
    }
    return numDino;
}

//****************************************************************************
//                                 deleteDino()
//
// task:          This function deletes a dinosaur if it dies in battle and 
//                cremates it. Returns new number of dinosaurs after shifting
//                the array.
//
//****************************************************************************
int deleteDino(int numDino, int lostDino, Dino maxCap[])
{
    /*VARIABLES*/
    lostDino = lostDino - 1;
    int shift = 0;
    
    /*DINOSAUR DEATH*/
    cout << endl << maxCap[lostDino].dinoName << " has been cremated.";
    
    /*ARRAY IS SHIFTED*/
    for(int i = 1; i < (numDino - lostDino); i++)
    {
        maxCap[lostDino+shift].dinoName = maxCap[lostDino+i].dinoName;
        maxCap[lostDino+shift].dinoType = maxCap[lostDino+i].dinoType;
        maxCap[lostDino+shift].dinoStats.hitPoints = maxCap[lostDino+i].dinoStats.hitPoints;
        maxCap[lostDino+shift].dinoStats.healthPoints = maxCap[lostDino+i].dinoStats.healthPoints;
        shift++;
    }
    numDino = numDino - 1;
    return numDino;
}

//****************************************************************************
//                                 saveToFile()
//
// task:          This function prints all of the remaining dinosaurs to the  
//                text file "dinosaur.txt". Also ends the program.
//
//****************************************************************************
void saveToFile(int numDino, Dino maxCap[])
{
    /*VARIABLES*/
    ofstream outFile;
    outFile.open("dinosaurs.txt");

    /*ADDS DINOSAURS TO FILE*/
    for(int i = 0; i < numDino; i++)
    {
        outFile << maxCap[i].dinoType << '#';
        outFile << maxCap[i].dinoName << '#';
        outFile << maxCap[i].dinoStats.hitPoints << '#';
        outFile << maxCap[i].dinoStats.healthPoints << '#';
    }
    cout << "\nThe dinosaurs were successfully saved to dinosaurs.txt.\n";
    outFile.close();
}
