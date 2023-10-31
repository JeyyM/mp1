#include <stdio.h>
#include <stdlib.h> // gets functions like randomization, etc.
#include <string.h> // allows for operations with strings like strcpy()
#include "ascii.c"
#include "functions.c"
#include "questions1.c"

/*
	Description:
	Precondition:
	@ param <name> <purpose>
	@return <returned item>
*/

/*
	Description: Starts the game if the user picks 1
	Precondition: none
	@ param none
	@return none
*/
void PlayGame(){
    int nPlayers;
    int nJeopardyMultiplier;
    int nCateg1, nCateg2, nCateg3, nCateg4;

    char strPlayer1Name[16];
    char strPlayer2Name[16];
    char strPlayer3Name[16];
    char strActivePlayer[16];

    char strFirst[16];
    char strSecond[16];
    char strThird[16];

    char strTitle1[30] = "", strTitle2[30] = "", strTitle3[30] = "", strTitle4[30] = "";
    
    char Cat1Ans1, Cat1Ans2, Cat1Ans3, Cat1Ans4, Cat1Ans5; 
    char Cat2Ans1, Cat2Ans2, Cat2Ans3, Cat2Ans4, Cat2Ans5;
    char Cat3Ans1, Cat3Ans2, Cat3Ans3, Cat3Ans4, Cat3Ans5;
    char Cat4Ans1, Cat4Ans2, Cat4Ans3, Cat4Ans4, Cat4Ans5;
    char Cat5Ans1, Cat5Ans2, Cat5Ans3, Cat5Ans4, Cat5Ans5;

    char Cat1P1, Cat1P2, Cat1P3, Cat1P4, Cat1P5;
    char Cat2P1, Cat2P2, Cat2P3, Cat2P4, Cat2P5;
    char Cat3P1, Cat3P2, Cat3P3, Cat3P4, Cat3P5;
    char Cat4P1, Cat4P2, Cat4P3, Cat4P4, Cat4P5;
    char Cat5P1, Cat5P2, Cat5P3, Cat5P4, Cat5P5;

    float fFirstScore;
    float fSecondScore;
    float fThirdScore;
    float fActiveScore;

    nJeopardyMultiplier = 1;
    nPlayers = GetPlayers();
    printf("What are the Player/s' names? \n");

    if (nPlayers >= 1){
        printf("What is Player 1's name (Max of 15 characters long and no spaces): ");
        scanf("%15s", &strPlayer1Name);
    }

    if (nPlayers >= 2){
        printf("What is Player 2's name (Max of 15 characters long and no spaces): ");
        scanf("%15s", &strPlayer2Name);
    } 
    
    if (nPlayers >= 3){
        printf("What is Player 3's name (Max of 15 characters long and no spaces): ");
        scanf("%15s", &strPlayer3Name);
    }

    OrderPlayers(&nPlayers, strPlayer1Name, strPlayer2Name, strPlayer3Name, strFirst, strSecond, strThird);

    printf("Press Any Key to Continue\n");  
    getch();  // waits for a char on key press

    clearTerminal();

    nCateg1 = RandMinMax(1, 7);

    nCateg2 = RandMinMax(1, 7);
    if (nCateg2 == nCateg1) {
        do {
            nCateg2 = RandMinMax(1, 7);
        } while (nCateg2 == nCateg1);
    }

    nCateg3 = RandMinMax(1, 7);
    if (nCateg3 == nCateg1 || nCateg3 == nCateg2) {
        do {
            nCateg3 = RandMinMax(1, 7);
        } while (nCateg3 == nCateg1 || nCateg3 == nCateg2);
    }

    nCateg4 = RandMinMax(1, 7);
    if (nCateg4 == nCateg1 || nCateg4 == nCateg2 || nCateg4 == nCateg3) {
        do {
            nCateg4 = RandMinMax(1, 7);
        } while (nCateg4 == nCateg1 || nCateg4 == nCateg2 || nCateg4 == nCateg3);
    }
    
}

int main ()
{
	char cMode;

    cMode = StartMenu();

    // printf("%s", strTitle1);

    switch (cMode) {
        case '1':
        {
            PlayGame();
        } break;

        case '2': 
        { 
            GetTitle(1);
        } break;
    }

	
	return 0;
}