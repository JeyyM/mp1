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
	@return the integer version of the chosen char, keeps checking for valid inputs
*/
int getPlayers() {
    char strPlayerCount[2];

    while (1) {
        printf("How many players (1 - 3)? \n");

        printf("Select Option: ");
        scanf(" %1s", strPlayerCount);

        // Clears the buffer meaning if you type for example, 333, it will stop the input from affecting the next ones
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);

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
    // picks a random number seed based on current time
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

/*
	Description: Checks to see if a question choice is available
	Precondition: A valid category was chosen
	@ param p# - the prizes for each item
	@return number of the question
*/
int ValidateQuestion(int* P1, int* P2, int* P3, int* P4, int* P5){
                    char cQChoice;
                    int nChoiceLoop2 = 1;

                    printf("Which question would you like to answer?\n [A]$%d\n [B]$%d\n [C]$%d\n [D]$%d\n [E]$%d\n", *P1, *P2, *P3, *P4, *P5);

while (nChoiceLoop2) {
    printf("Please choose a question [A, B, C, D, E]: ");
    scanf(" %1c", &cQChoice);
    while (getchar() != '\n');

    if (cQChoice == 'A') {
        if (*P1 > 0) {
            nChoiceLoop2 = 0;
            return 1;
        } else {
            printf("That question has already been answered.\n");
        }
    } else if (cQChoice == 'B') {
        if (*P2 > 0) {
            nChoiceLoop2 = 0;
            return 2;
        } else {
            printf("That question has already been answered.\n");
        }
    } else if (cQChoice == 'C') {
        if (*P3 > 0) {
            nChoiceLoop2 = 0;
            return 3;
        } else {
            printf("That question has already been answered.\n");
        }
    } else if (cQChoice == 'D') {
        if (*P4 > 0) {
            nChoiceLoop2 = 0;
            return 4;
        } else {
            printf("That question has already been answered.\n");
        }
    } else if (cQChoice == 'E') {
        if (*P5 > 0) {
            nChoiceLoop2 = 0;
            return 5;
        } else {
            printf("That question has already been answered.\n");
        }
    } else {
        printf("Invalid choice. Please pick from: [A, B, C, D, E]\n");
    }
}
}

/*
	Description: Changes the active player when a wrong answer is chosen
	Precondition: None
	@ param 
    nTurnTracker - Tracks which player is active 
    strTh - the names of the players
    nThScore - the scores of the players
    strActivePlayer and nActiveScore - active player name and score
	@return none
*/
void changePlayers(int *nTurnTracker, int nPlayers,
                   char* strFirst, char* strSecond, char* strThird,
                   int* nFirstScore, int* nSecondScore, int* nThirdScore,
                   char* strActivePlayer, int* nActiveScore){

                    switch (*nTurnTracker){
                        case 1:{
                            *nFirstScore = *nActiveScore;
                            break;
                        }
                        case 2:{
                            *nSecondScore = *nActiveScore;
                            break;
                        }
                        case 3:{
                            *nThirdScore = *nActiveScore;
                            break;
                        }
                    }

                    if (*nTurnTracker == nPlayers){
                        *nTurnTracker = 1;
                    } else {
                        *nTurnTracker += 1;
                    }

                    switch (*nTurnTracker){
                        case 1:{
                            strcpy(strActivePlayer, strFirst);
                            *nActiveScore = *nFirstScore;
                            break;
                        }
                        case 2:{
                            strcpy(strActivePlayer, strSecond);
                            *nActiveScore = *nSecondScore;     
                            break;        
                            }
                        case 3:{
                            strcpy(strActivePlayer, strThird);
                            *nActiveScore = *nThirdScore;        
                            break;      
                            }
                    }

                    printf("It is now %s's turn\n Your current score is: %d\n", strActivePlayer, *nActiveScore);        
}

/*
	Description: 
	Precondition: A valid category was chosen
	@ param p# - the prizes for each item
	@return number of the question
*/
int CheckAnswer(char* CatQ, char* CatCh, char CatAns, int* nActiveScore, int* CatP, char* strActivePlayer){

    char cAnswerChoice;

    printf("Your question is: %s\n", CatQ);
    printf("Your choices are (%c):\n %s\n", CatAns, CatCh);

    printf("What is your choice: ");
    scanf(" %1c", &cAnswerChoice);
    while (getchar() != '\n');

    if (cAnswerChoice == CatAns){
        printf("Congrats, %s! You won $%d \n", strActivePlayer, *CatP);
        *nActiveScore += *CatP;
        *CatP = 0;

        printf("Press Any Key to Continue\n");  
        getch();

        clearTerminal();

        return 0;
    } else {
        printf("Sorry, %s, that is the wrong answer.\n You lost $%d\n", strActivePlayer, *CatP);
        *nActiveScore -= *CatP;
        return *CatP;
    }
}

/*
	Description: Picks the player's final answer
	Precondition: The category hasn't been completed yet
	@ param 
    CatQ Ch Ans P - the category item's details
    nTurnTracker - Tracks which player is currently playing
    nPlayers - the number of players
    nFailCounter - number of times a question is answered wrong
    nThScore - the players' scores
    nActivePlayer and Score - the active player's name and score
	@return none
*/

void PickAnswer (char* CatQ, char* CatCh, char CatAns, int* CatP,

                int* nTurnTracker, int nPlayers, int nFailCounter,

                char* strFirst, char* strSecond, char* strThird,
                int* nFirstScore, int* nSecondScore, int* nThirdScore,
                char* strActivePlayer, int* nActiveScore){

        int nAnswerStatus = CheckAnswer(CatQ, CatCh, CatAns, nActiveScore, CatP, strActivePlayer);
        int nFailedQ;
        char cRebound;

    if (nAnswerStatus > 0 && nPlayers > 1){
        nFailCounter++;
        nFailedQ = 1;

        do {
            changePlayers(nTurnTracker, nPlayers, strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore, strActivePlayer, nActiveScore);
            printf("What is your answer to the question? ");
            scanf(" %1c", &cRebound);
            while (getchar() != '\n');

            if (cRebound == CatAns){
                printf("Correct! You won $%d\n", *CatP);
                *nActiveScore += *CatP;
                nFailedQ = 0;

                printf("Press Any Key to Continue\n");  
                    getch();

                    clearTerminal();
            } else {
                printf("Sorry but that answer is incorrect. \nYou lost $%d\n\n", *CatP);
                *nActiveScore -= *CatP;
            }

            nFailCounter += 1;

            if (nFailCounter == nPlayers && cRebound != CatAns){
                printf("Nobody got the correct answer.\n");
                nFailedQ = 0;

                changePlayers(nTurnTracker, nPlayers, strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore, strActivePlayer, nActiveScore);

                printf("Press Any Key to Continue\n");  
                    getch();

                    clearTerminal();
            }
            
        } while (nFailedQ);
    }

    *CatP = 0;

    if (nPlayers == 1 && nAnswerStatus > 0){
                printf("Press Any Key to Continue\n");  
                    getch();

                    clearTerminal();
    }

}