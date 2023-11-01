#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
	Description: Clears the terminal
	Precondition: none
	@ param none
	@return none
*/
void clearTerminal() 
{
    system("cls"); 
}


/*
	Description: Picks the number of players
	Precondition: none
	@ param none
	@return the integer version of the chosen char
*/
int getPlayers() {
    char strPlayerCount[2];

    while (1) {
        printf("How many players (1 - 3)? \n");

        printf("Select Option: ");
        scanf("%1s", strPlayerCount);

        switch (strPlayerCount[0]) {
            case '1': {
                clearTerminal();
                return 1;
            }
            case '2': {
                return 2;
                clearTerminal();
            }
            case '3': {
                clearTerminal();
                return 3;
            }
            default: {
                printf("Invalid player count. Please type 1, 2, or 3.\n");
            }
        }
    }

    return 0;
}

/*
	Description: Triggers the start menu on startup and when a game is quit
	Precondition: none
	@ param none
	@return the chosen start status whether start game, instructions, or exit game
*/
char startMenu()
{
	char strStartStatus[2]; // char with [n] means the length of the input which becomes a string, 2 is put because I only want 1 digit for item [0] and the other 2 extra is for the \0 which ends the string
	
	printJeopardy();
	
	printf("Welcome to Jeopardy!\n");

    while (1) // while (1) makes an infinite loop until you do something to make it exit
	{
        printf("[1] Start Game \n");
        printf("[2] How to Play \n");
        printf("[3] Exit Game \n");

        printf("Select Option: ");
        scanf("%1s", strStartStatus); // %1s makes it so that it will make the scanf only get the first digit

        switch (strStartStatus[0]) // [0] is there since the \0 is still caught so it stops being a single digit '' char
		 {		 	
            case '1': {
                clearTerminal();
                return strStartStatus[0];
                break;
            }
            case '2': {
                clearTerminal();
                return strStartStatus[0];
                break;
            }
            case '3': {
                clearTerminal();
                return strStartStatus[0];
                break;
            }
            default: {
                printf("Invalid Option. Please type 1, 2, or 3.\n");
            }
            // no break to make the while (1) work 
        }
    }
    
    return strStartStatus[0];
}

/*
	Description: Assigns the order of each player name on the strPlacements
	Precondition: The number of players are set and 1-3 player names
	@ param nPlayers - number of players. strPlayer#Names - the names of the players, strPlacement - the ordering names
	@return none
*/
void orderPlayers(int* nPlayers, char* strPlayer1Name, char* strPlayer2Name, char* strPlayer3Name, char* strFirst, char* strSecond, char* strThird) {
    srand(time(NULL));

    float fRand1 = rand();
    float fRand2 = rand();
    float fRand3 = rand();

    //* aren't put behind the chars because they are arrays. Arrays are treated like pointers

    if (*nPlayers == 3) {
        if (fRand1 > fRand2 && fRand1 > fRand3) {
            strcpy(strFirst, strPlayer1Name);
            
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
    } else if (*nPlayers == 2) {
        if (fRand1 > fRand2) {
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

    if (*nPlayers >= 1) {
        printf("The Play Order Will Be: \n");
        printf("%s \n", strFirst);
        if (*nPlayers >= 2) {
            printf("%s \n", strSecond);
        }
        if (*nPlayers >= 3) {
            printf("%s \n", strThird);
        }
    }
}

/*
	Description: Gets a random number between a minimum and maximum
	Precondition: none
	@ param min - lowest floor, max - the highest possible
	@return randomized number
*/
int randMinMax(int min, int max) 
{
    return min + rand() % (max - min + 1);
}

/*
	Description: Sets up the current player
	Precondition: All of the player names have been set
	@ param nTurnTracker - keeps track of which player's turn it is, Player#Name - the names of the 1-3 players, Player#Score - the player scores, 
                           strActivePlayer and nActiveScore are the containers that hold the current player's data
	@return none
*/
void setPlayer(int nTurnTracker, char* Player1Name, char* Player2Name, char* Player3Name, 
               int Player1Score, int Player2Score, int Player3Score, 
               char* strActivePlayer, int* nActiveScore){

    switch (nTurnTracker){
        case 1: {
            strcpy(strActivePlayer, Player1Name);
            *nActiveScore = Player1Score;
        } break;

        case 2: {
            strcpy(strActivePlayer, Player2Name);
            *nActiveScore = Player2Score;
        } break;

        case 3: {
            strcpy(strActivePlayer, Player3Name);
            *nActiveScore = Player3Score;
        } break;
    }
}

void PickAnswer(
                char* Title1, char* Title2, char* Title3, char* Title4, 

                char* Cat1Q1, char* Cat2Q1, char* Cat3Q1, char* Cat4Q1,
                char* Cat1Q2, char* Cat2Q2, char* Cat3Q2, char* Cat4Q2,
                char* Cat1Q3, char* Cat2Q3, char* Cat3Q3, char* Cat4Q3,
                char* Cat1Q4, char* Cat2Q4, char* Cat3Q4, char* Cat4Q4, 
                char* Cat1Q5, char* Cat2Q5, char* Cat3Q5, char* Cat4Q5, 
                
                char* Cat1Ch1, char* Cat2Ch1, char* Cat3Ch1, char* Cat4Ch1,
                char* Cat1Ch2, char* Cat2Ch2, char* Cat3Ch2, char* Cat4Ch2,
                char* Cat1Ch3, char* Cat2Ch3, char* Cat3Ch3, char* Cat4Ch3,
                char* Cat1Ch4, char* Cat2Ch4, char* Cat3Ch4, char* Cat4Ch4, 
                char* Cat1Ch5, char* Cat2Ch5, char* Cat3Ch5, char* Cat4Ch5,

                char Cat1Ans1, char Cat2Ans1, char Cat3Ans1, char Cat4Ans1,
                char Cat1Ans2, char Cat2Ans2, char Cat3Ans2, char Cat4Ans2,
                char Cat1Ans3, char Cat2Ans3, char Cat3Ans3, char Cat4Ans3,
                char Cat1Ans4, char Cat2Ans4, char Cat3Ans4, char Cat4Ans4, 
                char Cat1Ans5, char Cat2Ans5, char Cat3Ans5, char Cat4Ans5,
                
                int* Cat1P1, int* Cat2P1, int* Cat3P1, int* Cat4P1,
                int* Cat1P2, int* Cat2P2, int* Cat3P2, int* Cat4P2,
                int* Cat1P3, int* Cat2P3, int* Cat3P3, int* Cat4P3,
                int* Cat1P4, int* Cat2P4, int* Cat3P4, int* Cat4P4,
                int* Cat1P5, int* Cat2P5, int* Cat3P5, int* Cat4P5,

                int* nJeopardyProgress, int* nTurnTracker, int nPlayers
                )
    {

    int CatAProgress = 5;
    int CatBProgress = 5;
    int CatCProgress = 5;
    int CatDProgress = 5;
    int CatEProgress = 5;

    char ActiveCateg[100];
    int ActiveProgress;

    char ActiveQ1[100];
    char ActiveQ2[100];
    char ActiveQ3[100];
    char ActiveQ4[100];
    char ActiveQ5[100];

    char ActiveC1[100];
    char ActiveC2[100];
    char ActiveC3[100];
    char ActiveC4[100];
    char ActiveC5[100];

    int ActiveP1;
    int ActiveP2;
    int ActiveP3;
    int ActiveP4;
    int ActiveP5;

    char cCategChoice;
    
        printf("It is currently %s's turn\n Your score is: %d\n", strActivePlayer, nActiveScore);

        printf("Select which category you want to answer: \n [A] %s\n [B] %s\n [C]%s\n [D]%s\n [E] Exit Game\n", strTitle1, strTitle2, strTitle3, strTitle4);

        scanf(" %c", &cCategChoice);

    //     while (1) {
    //     printf("How many players (1 - 3)? \n");

    //     printf("Select Option: ");
    //     scanf("%1s", strPlayerCount);

    //     switch (strPlayerCount[0]) {
    //         case '1': {
    //             clearTerminal();
    //             return 1;
    //         }
    //         case '2': {
    //             return 2;
    //             clearTerminal();
    //         }
    //         case '3': {
    //             clearTerminal();
    //             return 3;
    //         }
    //         default: {
    //             printf("Invalid player count. Please type 1, 2, or 3.\n");
    //         }
    //     }
    // }

    }