#include <stdio.h>
#include <stdlib.h>
#include <string.h> // allows for operations with strings
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

    char strPlayer1Name[16];
    char strPlayer2Name[16];
    char strPlayer3Name[16];
    char strActivePlayer[16];

    char strFirst[16];
    char strSecond[16];
    char strThird[16];

    srand(time(NULL));

    float fRand1 = rand();
    float fRand2 = rand();
    float fRand3 = rand();

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

    if (nPlayers == 3){
    if (fRand1 > fRand2 && fRand1 > fRand3) {
        strcpy(strFirst, strPlayer1Name); //strcpy means string copy, because in c, you can't just apply arrays.                                                                       because it sucks
        
        if (fRand2 > fRand3) {
            strcpy(strSecond, strPlayer2Name);
            strcpy(strThird, strPlayer3Name);
        } else {
            strcpy(strSecond, strPlayer3Name);
            strcpy(strThird, strPlayer2Name);
        }	
    }
    else if (fRand2 > fRand3) {
        strcpy(strFirst, strPlayer2Name);
        
        if (fRand1 > fRand3) {
            strcpy(strSecond, strPlayer1Name);
            strcpy(strThird, strPlayer3Name);
        } else {
            strcpy(strSecond, strPlayer3Name);
            strcpy(strThird, strPlayer1Name);
        }	
    }
    else {
        strcpy(strFirst, strPlayer3Name);
        
        if (fRand1 > fRand2) {
            strcpy(strSecond, strPlayer1Name);
            strcpy(strThird, strPlayer2Name);
        } else {
            strcpy(strSecond, strPlayer2Name);
            strcpy(strThird, strPlayer1Name);
        }	
    }
    } else if (nPlayers == 2){
        if (fRand1 > fRand2){
            strcpy(strFirst, strPlayer1Name);
            strcpy(strSecond, strPlayer2Name);
        } else {
            strcpy(strFirst, strPlayer2Name);
            strcpy(strSecond, strPlayer1Name);
        }
    } else {
        strcpy(strFirst, strPlayer1Name);
    }

    clearTerminal();

    if (nPlayers >= 1){
    printf("The Play Order Will Be: \n");
    printf("%s \n", strFirst);
    if (nPlayers >=2){
        printf("%s \n", strSecond);
    }
    if (nPlayers >=3){
        printf("%s \n", strThird);
    }
    }
}

int main ()
{
	char cMode;

	
    cMode = StartMenu();

    switch (cMode) {
        case '1':
        {
            PlayGame();
        }
    }

	
	return 0;
}