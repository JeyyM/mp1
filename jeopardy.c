#include <stdio.h>
#include <stdlib.h>
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

    float fFirstScore;
    float fSecondScore;
    float fThirdScore;
    float fActiveScore;

    char Ask1;
    int Ask2;

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

    printf("%s %s %s", strPlayer1Name, strPlayer2Name, strPlayer3Name);
    // clearTerminal();
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