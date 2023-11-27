/*
Description: Machine Project for Term 1 2023-2024, Jeopardy Game
Programmed By: Miranda, Juan Miguel, S22A
Last Modified: 11/26/2023
Version: 1.0
Acknowledgements: Some libraries such <string.h> <time.h> were used to gain certain functionalities.
                  Some Googling was done when problems occured.
                  https://ascii-generator.site/ was used to generate ascii images.
*/

#include <stdio.h>
#include <stdlib.h> // gets functions like randomization, exit, etc.
#include <string.h> // allows for operations with strings like strcpy()
#include "ascii.c"
#include "functions.c"
#include "questions1.c"
#include "questions2.c"
#include "main_functions.c"

/*
	Description:
	Precondition:
	@ param <name> <purpose>
	@return <returned item>
*/

/*
	Description: Starts the Jeopardy round
	Precondition: none
	@ param 
    nLength1 and nLength2 - Set the number of rounds for normal and double round
    nPlayersHold - Will be modified to get the number of players after Jeopardy round
    nTurnTrackerHold - Will be modified to get the current player after Jeopardy round
    strThHold and strActivePlayerHold - Will be modified to get the player names after Jeopardy round
    nThScoreHold and nActiveScoreHold - Will be modified to get the player scores after Jeopardy round
    nDoubleMode - Sets the Double round penalty

	@return none
*/
void PlayGame(int nLength1, int* nLength2, int* nPlayersHold, int* nTurnTrackerHold, 
              char* strFirstHold, char* strSecondHold, char* strThirdHold, char* strActivePlayerHold, 
              int* nFirstScoreHold, int* nSecondScoreHold, int* nThirdScoreHold, int* nActiveScoreHold, int nDoubleMode){

    // since this is the jeopardy round, setting nDoubleMode to 1 makes it so scores are never reset to 0 here
    nDoubleMode = 1;

    // the number of players
    int nPlayers;

    // the tracker to see which player is currently active (1 to 3)
    int nTurnTracker;

    // random numbers will be set to see which questions it will choose
    int nCateg1, nCateg2, nCateg3, nCateg4;

    // variables to hold player name strings
    char strPlayer1Name[16];
    char strPlayer2Name[16];
    char strPlayer3Name[16];
    char strActivePlayer[16];

    // variables to hold player names after randomization
    char strFirst[16];
    char strSecond[16];
    char strThird[16];

    // titles of categories chosen
    char strTitle1[30] = "", strTitle2[30] = "", strTitle3[30] = "", strTitle4[30] = "";

    // questions of categories chosen
    char Cat1Q1[100], Cat1Q2[100], Cat1Q3[100], Cat1Q4[100], Cat1Q5[100];
    char Cat2Q1[100], Cat2Q2[100], Cat2Q3[100], Cat2Q4[100], Cat2Q5[100];
    char Cat3Q1[100], Cat3Q2[100], Cat3Q3[100], Cat3Q4[100], Cat3Q5[100];
    char Cat4Q1[100], Cat4Q2[100], Cat4Q3[100], Cat4Q4[100], Cat4Q5[100];

    // choices of categories chosen
    char Cat1Ch1[100], Cat1Ch2[100], Cat1Ch3[100], Cat1Ch4[100], Cat1Ch5[100];
    char Cat2Ch1[100], Cat2Ch2[100], Cat2Ch3[100], Cat2Ch4[100], Cat2Ch5[100];
    char Cat3Ch1[100], Cat3Ch2[100], Cat3Ch3[100], Cat3Ch4[100], Cat3Ch5[100];
    char Cat4Ch1[100], Cat4Ch2[100], Cat4Ch3[100], Cat4Ch4[100], Cat4Ch5[100];

    // answers of categories chosen
    char Cat1Ans1, Cat1Ans2, Cat1Ans3, Cat1Ans4, Cat1Ans5; 
    char Cat2Ans1, Cat2Ans2, Cat2Ans3, Cat2Ans4, Cat2Ans5;
    char Cat3Ans1, Cat3Ans2, Cat3Ans3, Cat3Ans4, Cat3Ans5;
    char Cat4Ans1, Cat4Ans2, Cat4Ans3, Cat4Ans4, Cat4Ans5;

    // prizes of categories chosen
    int Cat1P1, Cat1P2, Cat1P3, Cat1P4, Cat1P5;
    int Cat2P1, Cat2P2, Cat2P3, Cat2P4, Cat2P5;
    int Cat3P1, Cat3P2, Cat3P3, Cat3P4, Cat3P5;
    int Cat4P1, Cat4P2, Cat4P3, Cat4P4, Cat4P5;

    // variables that hold players scores
    int nFirstScore;
    int nSecondScore;
    int nThirdScore;
    int nActiveScore;

    // how many turns are left for the round
    int nJeopardyProgress;

    // tracks to see if a category can still be answered or not
    int CatAProgress = 5;
    int CatBProgress = 5;
    int CatCProgress = 5;
    int CatDProgress = 5;
    int CatEProgress = 5;

    // initially sets it to player 1
    nTurnTracker = 1;

    //Sets the number of questions that will be answered per round
    nJeopardyProgress = nLength1;

    nPlayers = GetPlayers();
    printf("What are the Player/s' names? \n");

    if (nPlayers >= 1){
        printf("What is Player 1's name (Max of 15 characters long and no spaces): ");
        scanf("%15s", strPlayer1Name);
        while (getchar() != '\n');
        nFirstScore = 0;
    }

    if (nPlayers >= 2){
        printf("What is Player 2's name (Max of 15 characters long and no spaces): ");
        scanf("%15s", strPlayer2Name);
        while (getchar() != '\n');
        nSecondScore = 0;
    } 
    
    if (nPlayers >= 3){
        printf("What is Player 3's name (Max of 15 characters long and no spaces): ");
        scanf("%15s", strPlayer3Name);
        while (getchar() != '\n');
        nThirdScore = 0;
    }

    OrderPlayers(&nPlayers, strPlayer1Name, strPlayer2Name, strPlayer3Name, strFirst, strSecond, strThird);

    printf("Press Any Key to Continue\n");  
    getch();

    ClearTerminal();

    // chooses random numbers for each category, validates to avoid duplicates
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

    // gets the content in batches from questions1.c
    GetContent1(nCateg1, strTitle1, Cat1Q1, Cat1Q2, Cat1Q3, Cat1Q4, Cat1Q5);
    GetContent2(nCateg1, Cat1Ch1, Cat1Ch2, Cat1Ch3, Cat1Ch4, Cat1Ch5, &Cat1Ans1, &Cat1Ans2, &Cat1Ans3, &Cat1Ans4, &Cat1Ans5);
    GetContent3(nCateg1, &Cat1P1, &Cat1P2, &Cat1P3, &Cat1P4, &Cat1P5);

    GetContent1(nCateg2, strTitle2, Cat2Q1, Cat2Q2, Cat2Q3, Cat2Q4, Cat2Q5);
    GetContent2(nCateg2, Cat2Ch1, Cat2Ch2, Cat2Ch3, Cat2Ch4, Cat2Ch5, &Cat2Ans1, &Cat2Ans2, &Cat2Ans3, &Cat2Ans4, &Cat2Ans5);
    GetContent3(nCateg2, &Cat2P1, &Cat2P2, &Cat2P3, &Cat2P4, &Cat2P5);

    GetContent1(nCateg3, strTitle3, Cat3Q1, Cat3Q2, Cat3Q3, Cat3Q4, Cat3Q5);
    GetContent2(nCateg3, Cat3Ch1, Cat3Ch2, Cat3Ch3, Cat3Ch4, Cat3Ch5, &Cat3Ans1, &Cat3Ans2, &Cat3Ans3, &Cat3Ans4, &Cat3Ans5);
    GetContent3(nCateg3, &Cat3P1, &Cat3P2, &Cat3P3, &Cat3P4, &Cat3P5);

    GetContent1(nCateg4, strTitle4, Cat4Q1, Cat4Q2, Cat4Q3, Cat4Q4, Cat4Q5);
    GetContent2(nCateg4, Cat4Ch1, Cat4Ch2, Cat4Ch3, Cat4Ch4, Cat4Ch5, &Cat4Ans1, &Cat4Ans2, &Cat4Ans3, &Cat4Ans4, &Cat4Ans5);
    GetContent3(nCateg4, &Cat4P1, &Cat4P2, &Cat4P3, &Cat4P4, &Cat4P5);

    printf("The chosen categories are: \n%s \n%s \n%s \n%s \n", strTitle1, strTitle2, strTitle3, strTitle4);

    printf("\nPress Any Key to Continue\n");  
    getch();

    ClearTerminal();

    printf("It's time for the first round of JEOPARDY!\n");

    SetPlayer(nTurnTracker, strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore, strActivePlayer, &nActiveScore);

    do {
            PrintTable(Cat1P1, Cat2P1, Cat3P1, Cat4P1,
               Cat1P2, Cat2P2, Cat3P2, Cat4P2,
               Cat1P3, Cat2P3, Cat3P3, Cat4P3,
               Cat1P4, Cat2P4, Cat3P4, Cat4P4,
               Cat1P5, Cat2P5, Cat3P5, Cat4P5);

        PickChoice(
                   strTitle1, strTitle2, strTitle3, strTitle4,
        
                   Cat1Q1, Cat2Q1, Cat3Q1, Cat4Q1,
                   Cat1Q2, Cat2Q2, Cat3Q2, Cat4Q2,
                   Cat1Q3, Cat2Q3, Cat3Q3, Cat4Q3,
                   Cat1Q4, Cat2Q4, Cat3Q4, Cat4Q4,
                   Cat1Q5, Cat2Q5, Cat3Q5, Cat4Q5,

                   Cat1Ch1, Cat2Ch1, Cat3Ch1, Cat4Ch1,
                   Cat1Ch2, Cat2Ch2, Cat3Ch2, Cat4Ch2,
                   Cat1Ch3, Cat2Ch3, Cat3Ch3, Cat4Ch3,
                   Cat1Ch4, Cat2Ch4, Cat3Ch4, Cat4Ch4,
                   Cat1Ch5, Cat2Ch5, Cat3Ch5, Cat4Ch5,

                   Cat1Ans1, Cat2Ans1, Cat3Ans1, Cat4Ans1,
                   Cat1Ans2, Cat2Ans2, Cat3Ans2, Cat4Ans2,
                   Cat1Ans3, Cat2Ans3, Cat3Ans3, Cat4Ans3,
                   Cat1Ans4, Cat2Ans4, Cat3Ans4, Cat4Ans4,
                   Cat1Ans5, Cat2Ans5, Cat3Ans5, Cat4Ans5,

                   &Cat1P1, &Cat2P1, &Cat3P1, &Cat4P1,
                   &Cat1P2, &Cat2P2, &Cat3P2, &Cat4P2,
                   &Cat1P3, &Cat2P3, &Cat3P3, &Cat4P3,
                   &Cat1P4, &Cat2P4, &Cat3P4, &Cat4P4,
                   &Cat1P5, &Cat2P5, &Cat3P5, &Cat4P5,

                   &nTurnTracker, nPlayers,

                   strFirst, strSecond, strThird,
                   &nFirstScore, &nSecondScore, &nThirdScore,
                   strActivePlayer, &nActiveScore,

                   &CatAProgress, &CatBProgress, &CatCProgress, &CatDProgress, &CatEProgress, &nJeopardyProgress, nLength2,
                   nDoubleMode
                   );

                // deducts to reduce number of turns
               nJeopardyProgress -= 1;

    } while (nJeopardyProgress > 0);

    printf("End of Jeopardy Round\n");

    // Updates the current player's score
    // Happens because the ChangePlayer only updates the person who answers wrong
        switch (nTurnTracker){
        case 1:{
            nFirstScore = nActiveScore;
            break;
        }
        case 2:{
            nSecondScore = nActiveScore;
            break;
        }
        case 3:{
            nThirdScore = nActiveScore;
            break;
        }
    }

    printf("CURRENT STANDINGS:\n%s: %d\n", strFirst, nFirstScore);

    // prevents printing of nonexistent players
    if (nPlayers >=2 ){
            printf("%s: %d\n", strSecond, nSecondScore);
    }

    if (nPlayers >=3 ){
            printf("%s: %d\n", strThird, nThirdScore);
    }

    // sets the hold variables to be able to take them out of the function
    *nPlayersHold = nPlayers;
    *nTurnTrackerHold = nTurnTracker;
    strcpy(strFirstHold, strFirst);
    strcpy(strSecondHold, strSecond);
    strcpy(strThirdHold, strThird);
    strcpy(strActivePlayerHold, strActivePlayer);

    *nFirstScoreHold = nFirstScore;
    *nSecondScoreHold = nSecondScore;
    *nThirdScoreHold = nThirdScore;
    *nActiveScoreHold = nActiveScore;

    printf("Press Any Key to Continue\n");  
    getch();

    ClearTerminal();
    
}

/*
	Description: Starts the Double round
	Precondition: none
	@ param 
    nLength2 - Set the number of rounds for double round
    nPlayersHold - Will be modified to get the number of players after Jeopardy round
    nTurnTrackerHold - Will be modified to get the current player after Jeopardy round
    strThHold and strActivePlayerHold - Will be modified to get the player names after Jeopardy round
    nThScoreHold and nActiveScoreHold - Will be modified to get the player scores after Jeopardy round
    nDoubleMode - Sets the Double round penalty
    nFinal - The status to show if Final Jeopardy will occur
    nFinaleScore# - The final scores of the players before Final Jeopardy
	@return none
*/
void PlayGame2(int* nLength2, int nPlayersHold, int nTurnTrackerHold, 
              char* strFirstHold, char* strSecondHold, char* strThirdHold, char* strActivePlayerHold, 
              int nFirstScoreHold, int nSecondScoreHold, int nThirdScoreHold, int nActiveScoreHold, int nDoubleMode, int* nFinal,
              int* nFinaleScore1, int* nFinaleScore2, int* nFinaleScore3){

    // set to the hold values to continue from where the game left off
    int nPlayers = nPlayersHold;
    int nTurnTracker = nTurnTrackerHold;

    int nCateg1, nCateg2, nCateg3, nCateg4;

    char strFirst[16];
    char strSecond[16];
    char strThird[16];
    char strActivePlayer[16];

    strcpy(strFirst, strFirstHold);
    strcpy(strSecond, strSecondHold);
    strcpy(strThird, strThirdHold);
    strcpy(strActivePlayer, strActivePlayerHold);

    // Set to the hold values to continue from where the game left off
    int nFirstScore = nFirstScoreHold;
    int nSecondScore = nSecondScoreHold;
    int nThirdScore = nThirdScoreHold;
    int nActiveScore = nActiveScoreHold;

    // this time set to the double round length
    int nJeopardyProgress = *nLength2;

    char strTitle1[30] = "", strTitle2[30] = "", strTitle3[30] = "", strTitle4[30] = "";

    char Cat1Q1[100], Cat1Q2[100], Cat1Q3[100], Cat1Q4[100], Cat1Q5[100];
    char Cat2Q1[100], Cat2Q2[100], Cat2Q3[100], Cat2Q4[100], Cat2Q5[100];
    char Cat3Q1[100], Cat3Q2[100], Cat3Q3[100], Cat3Q4[100], Cat3Q5[100];
    char Cat4Q1[100], Cat4Q2[100], Cat4Q3[100], Cat4Q4[100], Cat4Q5[100];

    char Cat1Ch1[100], Cat1Ch2[100], Cat1Ch3[100], Cat1Ch4[100], Cat1Ch5[100];
    char Cat2Ch1[100], Cat2Ch2[100], Cat2Ch3[100], Cat2Ch4[100], Cat2Ch5[100];
    char Cat3Ch1[100], Cat3Ch2[100], Cat3Ch3[100], Cat3Ch4[100], Cat3Ch5[100];
    char Cat4Ch1[100], Cat4Ch2[100], Cat4Ch3[100], Cat4Ch4[100], Cat4Ch5[100];

    char Cat1Ans1, Cat1Ans2, Cat1Ans3, Cat1Ans4, Cat1Ans5; 
    char Cat2Ans1, Cat2Ans2, Cat2Ans3, Cat2Ans4, Cat2Ans5;
    char Cat3Ans1, Cat3Ans2, Cat3Ans3, Cat3Ans4, Cat3Ans5;
    char Cat4Ans1, Cat4Ans2, Cat4Ans3, Cat4Ans4, Cat4Ans5;

    int Cat1P1, Cat1P2, Cat1P3, Cat1P4, Cat1P5;
    int Cat2P1, Cat2P2, Cat2P3, Cat2P4, Cat2P5;
    int Cat3P1, Cat3P2, Cat3P3, Cat3P4, Cat3P5;
    int Cat4P1, Cat4P2, Cat4P3, Cat4P4, Cat4P5;

    int CatAProgress = 5;
    int CatBProgress = 5;
    int CatCProgress = 5;
    int CatDProgress = 5;
    int CatEProgress = 5;

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

    // this time is GetContent 4-6 since its in questions2.c this time
    GetContent4(nCateg1, strTitle1, Cat1Q1, Cat1Q2, Cat1Q3, Cat1Q4, Cat1Q5);
    GetContent5(nCateg1, Cat1Ch1, Cat1Ch2, Cat1Ch3, Cat1Ch4, Cat1Ch5, &Cat1Ans1, &Cat1Ans2, &Cat1Ans3, &Cat1Ans4, &Cat1Ans5);
    GetContent6(nCateg1, &Cat1P1, &Cat1P2, &Cat1P3, &Cat1P4, &Cat1P5);

    GetContent4(nCateg2, strTitle2, Cat2Q1, Cat2Q2, Cat2Q3, Cat2Q4, Cat2Q5);
    GetContent5(nCateg2, Cat2Ch1, Cat2Ch2, Cat2Ch3, Cat2Ch4, Cat2Ch5, &Cat2Ans1, &Cat2Ans2, &Cat2Ans3, &Cat2Ans4, &Cat2Ans5);
    GetContent6(nCateg2, &Cat2P1, &Cat2P2, &Cat2P3, &Cat2P4, &Cat2P5);

    GetContent4(nCateg3, strTitle3, Cat3Q1, Cat3Q2, Cat3Q3, Cat3Q4, Cat3Q5);
    GetContent5(nCateg3, Cat3Ch1, Cat3Ch2, Cat3Ch3, Cat3Ch4, Cat3Ch5, &Cat3Ans1, &Cat3Ans2, &Cat3Ans3, &Cat3Ans4, &Cat3Ans5);
    GetContent6(nCateg3, &Cat3P1, &Cat3P2, &Cat3P3, &Cat3P4, &Cat3P5);

    GetContent4(nCateg4, strTitle4, Cat4Q1, Cat4Q2, Cat4Q3, Cat4Q4, Cat4Q5);
    GetContent5(nCateg4, Cat4Ch1, Cat4Ch2, Cat4Ch3, Cat4Ch4, Cat4Ch5, &Cat4Ans1, &Cat4Ans2, &Cat4Ans3, &Cat4Ans4, &Cat4Ans5);
    GetContent6(nCateg4, &Cat4P1, &Cat4P2, &Cat4P3, &Cat4P4, &Cat4P5);

    printf("The chosen categories are: \n%s \n%s \n%s \n%s \n", strTitle1, strTitle2, strTitle3, strTitle4);

    printf("\nPress Any Key to Continue\n");  
    getch();

    ClearTerminal();

    printf("It's time for the second round of JEOPARDY! The Double Round\n");

    SetPlayer(nTurnTracker, strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore, strActivePlayer, &nActiveScore);

    do {
            PrintTable(Cat1P1, Cat2P1, Cat3P1, Cat4P1,
               Cat1P2, Cat2P2, Cat3P2, Cat4P2,
               Cat1P3, Cat2P3, Cat3P3, Cat4P3,
               Cat1P4, Cat2P4, Cat3P4, Cat4P4,
               Cat1P5, Cat2P5, Cat3P5, Cat4P5);

        PickChoice(
                   strTitle1, strTitle2, strTitle3, strTitle4,
        
                   Cat1Q1, Cat2Q1, Cat3Q1, Cat4Q1,
                   Cat1Q2, Cat2Q2, Cat3Q2, Cat4Q2,
                   Cat1Q3, Cat2Q3, Cat3Q3, Cat4Q3,
                   Cat1Q4, Cat2Q4, Cat3Q4, Cat4Q4,
                   Cat1Q5, Cat2Q5, Cat3Q5, Cat4Q5,

                   Cat1Ch1, Cat2Ch1, Cat3Ch1, Cat4Ch1,
                   Cat1Ch2, Cat2Ch2, Cat3Ch2, Cat4Ch2,
                   Cat1Ch3, Cat2Ch3, Cat3Ch3, Cat4Ch3,
                   Cat1Ch4, Cat2Ch4, Cat3Ch4, Cat4Ch4,
                   Cat1Ch5, Cat2Ch5, Cat3Ch5, Cat4Ch5,

                   Cat1Ans1, Cat2Ans1, Cat3Ans1, Cat4Ans1,
                   Cat1Ans2, Cat2Ans2, Cat3Ans2, Cat4Ans2,
                   Cat1Ans3, Cat2Ans3, Cat3Ans3, Cat4Ans3,
                   Cat1Ans4, Cat2Ans4, Cat3Ans4, Cat4Ans4,
                   Cat1Ans5, Cat2Ans5, Cat3Ans5, Cat4Ans5,

                   &Cat1P1, &Cat2P1, &Cat3P1, &Cat4P1,
                   &Cat1P2, &Cat2P2, &Cat3P2, &Cat4P2,
                   &Cat1P3, &Cat2P3, &Cat3P3, &Cat4P3,
                   &Cat1P4, &Cat2P4, &Cat3P4, &Cat4P4,
                   &Cat1P5, &Cat2P5, &Cat3P5, &Cat4P5,

                   &nTurnTracker, nPlayers,

                   strFirst, strSecond, strThird,
                   &nFirstScore, &nSecondScore, &nThirdScore,
                   strActivePlayer, &nActiveScore,

                   &CatAProgress, &CatBProgress, &CatCProgress, &CatDProgress, &CatEProgress, &nJeopardyProgress, nLength2,
                   nDoubleMode
                   );

               nJeopardyProgress -= 1;

               if (nJeopardyProgress == 1){
                *nFinal = 1;
               }

    } while (nJeopardyProgress > 0);

    printf("End of Double Round\n");

    // Updates the current player's score
    // Happens because the ChangePlayer only updates the person who answers wrong
        switch (nTurnTracker){
        case 1:{
            nFirstScore = nActiveScore;
            break;
        }
        case 2:{
            nSecondScore = nActiveScore;
            break;
        }
        case 3:{
            nThirdScore = nActiveScore;
            break;
        }
    }

    printf("CURRENT STANDINGS:\n%s: %d\n", strFirst, nFirstScore);

    if (nPlayers >=2 ){
            printf("%s: %d\n", strSecond, nSecondScore);
    }

    if (nPlayers >=3 ){
            printf("%s: %d\n", strThird, nThirdScore);
    }

    printf("Press Any Key to Continue\n");  
    getch();

    // sets the scores for final jeopardy to take it up to the main
    *nFinaleScore1 = nFirstScore;
    *nFinaleScore2 = nSecondScore;
    *nFinaleScore3 = nThirdScore;

    ClearTerminal();
    
}

int main ()
{
    int nGame = 1;
    while (nGame){
        char cMode;
        // for setting the length and validating the turns for Jeopardy round
        int nLength1;
        int nLengthValid1;
        // for setting the length and validating the turns for Double round
        int nLength2;
        int nLengthValid2;

        // Sets whether the score will be multiplied by 0 in double round when a mistake is made
        int nDoubleMode;
        int nDoubleModeInput;

        // Variables to hold final scores for when it is Final Jeopardy
        int nFinaleScore1;
        int nFinaleScore2;
        int nFinaleScore3;

        // Random numbers for setting the Final Jeopardy questions
        int nWagerNum1;
        int nWagerNum2;
        int nWagerNum3;

        // Variables to hold answers for FJ
        char strWagerAns1[100];
        char strWagerAns2[100];
        char strWagerAns3[100];

        // Variables to hold the data for FJ's Questions and Answers
        char F1Q[100];
        char F1A[100];
        char F2Q[100];
        char F2A[100];
        char F3Q[100];
        char F3A[100];

        // Variables to hold FJ bets and validation
        int nWager1Choice;
        int nWager1Verify;
        int nWager2Choice;
        int nWager2Verify;
        int nWager3Choice;
        int nWager3Verify;

        // Whether final jeopardy will occur or not
        int nFinal = 0;

    // for setting the play mode from 1 to 3
    cMode = StartMenu();

    switch (cMode) {
        // play mode
        case '1':
        {
            // Variables to hold and later  retrieve data to be passed across rounds
                int nPlayersHold;
                int nTurnTrackerHold;

                char strFirstHold[16];
                char strSecondHold[16];
                char strThirdHold[16];
                char strActivePlayerHold[16];

                int nFirstScoreHold;
                int nSecondScoreHold;
                int nThirdScoreHold;
                int nActiveScoreHold;

            //Sets jeopardy and double round turn counts
        do {
            printf("Set Jeopardy Round Length (1 to 20): ");
            nLengthValid1 = scanf("%d", &nLength1);

            // input buffer clearer
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);

            if (nLengthValid1 != 1) {
                printf("Invalid input, only put numbers between 1 and 20.\n");
            } else if (nLength1 < 1 || nLength1 > 20) {
                printf("Number out of range, please enter a number between 1 and 20.\n");
            }
         } while (nLengthValid1 != 1 || nLength1 < 1 || nLength1 > 20);

                 do {
            printf("Set Double Round Length (1 to 20): ");
            nLengthValid2 = scanf("%d", &nLength2);

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);

            if (nLengthValid2 != 1) {
                printf("Invalid input, only put numbers between 1 and 20.\n");
            } else if (nLength2 < 1 || nLength2 > 20) {
                printf("Number out of range, please enter a number between 1 and 20.\n");
            }
         } while (nLengthValid2 != 1 || nLength2 < 1 || nLength2 > 20);

        printf("Double Round Penalty: Normal/Zero Mode? [1 or 0]\n ");
        printf("Normal has normal penalties while Zero Mode resets score to 0:  ");
        scanf(" %1d", &nDoubleModeInput);
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);

        if (nDoubleModeInput == 0){
            nDoubleMode = 0;
        } else {
            nDoubleMode = 1;
        }

        printf("Chosen Penalty Mode: %d\n", nDoubleMode);

            PlayGame(nLength1, &nLength2, &nPlayersHold, &nTurnTrackerHold, strFirstHold, strSecondHold, strThirdHold,
                     strActivePlayerHold, &nFirstScoreHold, &nSecondScoreHold, &nThirdScoreHold, &nActiveScoreHold, 1);

            if (nLength2 > 0){
                // is set to be length > 0 to prevent it from happening when the game is quit in jeopardy round
                PrintDouble();

            PlayGame2(&nLength2, nPlayersHold, nTurnTrackerHold, strFirstHold, strSecondHold, strThirdHold, strActivePlayerHold, 
                      nFirstScoreHold, nSecondScoreHold, nThirdScoreHold, nActiveScoreHold, nDoubleMode, &nFinal,
                      &nFinaleScore1, &nFinaleScore2, &nFinaleScore3 );
            }

            // Starts final jeopardy
            if (nFinal){
                PrintFinal();
                printf("\nNow starts Final Jeopardy! Bet up to your maximum points.\nWin or Lose how much you gamble.\nAnswers are singular, one-word, and CAPITALIZED.\n");

                printf("Press Any Key to Continue\n");  
                getch();

                ClearTerminal();

                // Random numbers to pick the questions and answers
                nWagerNum1 = RandMinMax(1, 5);
                nWagerNum2 = RandMinMax(1, 5);
                nWagerNum3 = RandMinMax(1, 5);

                // stops duplicates
                do {
                    nWagerNum2 = RandMinMax(1, 5);
                } while (nWagerNum1 == nWagerNum2);

                do {
                    nWagerNum3 = RandMinMax(1, 5);
                } while (nWagerNum3 == nWagerNum1 || nWagerNum3 == nWagerNum2);

                GetFinal(nWagerNum1, F1Q, F1A);
                GetFinal(nWagerNum2, F2Q, F2A);
                GetFinal(nWagerNum3, F3Q, F3A);

            if (nFinaleScore1 > 0){
                printf("%s can wager from 0 up to %d: ", strFirstHold, nFinaleScore1);

                do {
                    nWager1Verify = scanf("%d", &nWager1Choice);

                    while (getchar() != '\n');

                    if (nWager1Verify != 1 || nWager1Choice < 0 || nWager1Choice > nFinaleScore1) {
                        printf("Invalid input. Please enter a number between 0 and %d:", nFinaleScore1);
                    }
                } while (nWager1Verify != 1 || nWager1Choice < 0 || nWager1Choice > nFinaleScore1);

                printf("Your question is:\n %s\n", F1Q);
                printf("Type your answer (%s): ", F1A);

                scanf("%s", strWagerAns1);
                while (getchar() != '\n');

                if (strcmp(strWagerAns1, F1A) == 0){
                    printf("Correct! You won $%d\n", nWager1Choice);
                    nFinaleScore1 += nWager1Choice;
                } else {
                    printf("That is incorrect, you lost $%d\n", nWager1Choice);
                    nFinaleScore1 -= nWager1Choice;
                }
                
            } else {
                printf("Sorry %s, you don't have enough points to wager.\n", strFirstHold);
            }

            printf("Press Any Key to Continue\n");  
            getch();

            ClearTerminal();

            if (nPlayersHold >= 2){
            if (nFinaleScore2 > 0){
                printf("%s can wager from 0 up to %d: ", strSecondHold, nFinaleScore2);

                do {
                    nWager2Verify = scanf("%d", &nWager2Choice);

                    while (getchar() != '\n');

                    if (nWager2Verify != 1 || nWager2Choice < 0 || nWager2Choice > nFinaleScore2) {
                        printf("Invalid input. Please enter a number between 0 and %d:", nFinaleScore2);
                    }
                } while (nWager2Verify != 1 || nWager2Choice < 0 || nWager2Choice > nFinaleScore2);

                printf("Your question is:\n %s\n", F2Q);
                printf("Type your answer (%s): ", F2A);

                scanf("%s", strWagerAns2);
                while (getchar() != '\n');

                if (strcmp(strWagerAns2, F2A) == 0){
                    printf("Correct! You won $%d\n", nWager2Choice);
                    nFinaleScore2 += nWager2Choice;
                } else {
                    printf("That is incorrect, you lost $%d\n", nWager2Choice);
                    nFinaleScore2 -= nWager2Choice;
                }
                
            } else {
                printf("Sorry %s, you don't have enough points to wager.\n", strSecondHold);
            }

            printf("Press Any Key to Continue\n");  
            getch();

            ClearTerminal();
            }

            if (nPlayersHold >= 3){
            if (nFinaleScore3 > 0){
                printf("%s can wager from 0 up to %d: ", strThirdHold, nFinaleScore3);

                do {
                    nWager3Verify = scanf("%d", &nWager3Choice);

                    while (getchar() != '\n');

                    if (nWager3Verify != 1 || nWager3Choice < 0 || nWager3Choice > nFinaleScore3) {
                        printf("Invalid input. Please enter a number between 0 and %d:", nFinaleScore3);
                    }
                } while (nWager3Verify != 1 || nWager3Choice < 0 || nWager3Choice > nFinaleScore3);

                printf("Your question is:\n %s\n", F3Q);
                printf("Type your answer (%s): ", F3A);

                scanf("%s", strWagerAns3);
                while (getchar() != '\n');

                if (strcmp(strWagerAns3, F3A) == 0){
                    printf("Correct! You won $%d\n", nWager3Choice);
                    nFinaleScore3 += nWager3Choice;
                } else {
                    printf("That is incorrect, you lost $%d\n", nWager3Choice);
                    nFinaleScore3 -= nWager3Choice;
                }
                
            } else {
                printf("Sorry %s, you don't have enough points to wager.\n", strThirdHold);
            }

            printf("Press Any Key to Continue\n");  
            getch();

            ClearTerminal();
            }

            printf("END OF GAME STANDINGS\n");
            printf("%s: %d\n", strFirstHold, nFinaleScore1);

            if (nPlayersHold >= 2){
            printf("%s: %d\n", strSecondHold, nFinaleScore2);
            }

            if (nPlayersHold >=3){
            printf("%s: %d\n\n", strThirdHold, nFinaleScore3);
            }

            if (nPlayersHold == 1){
                printf("Your final score is: $%d\n", nFinaleScore1);
            }

            if (nPlayersHold == 2){
                if (nFinaleScore1 > nFinaleScore2){
                    printf("Congratulations %s! You won Jeopardy with a score of $%d!\n", strFirstHold, nFinaleScore1);
                } else if (nFinaleScore2 > nFinaleScore1){
                    printf("Congratulations %s! You won Jeopardy with a score of $%d!\n", strSecondHold, nFinaleScore2);
                } else {
                    printf("It seems there was a tie!\n");
                }
            }

            if (nPlayersHold == 3){
                if (nFinaleScore1 > nFinaleScore2 && nFinaleScore1 > nFinaleScore3){
                    printf("Congratulations %s! You won Jeopardy with a score of $%d!\n", strFirstHold, nFinaleScore1);          
                } else if (nFinaleScore2 > nFinaleScore1 && nFinaleScore2 > nFinaleScore3){
                    printf("Congratulations %s! You won Jeopardy with a score of $%d!\n", strSecondHold, nFinaleScore2);
                } else if (nFinaleScore3 > nFinaleScore1 && nFinaleScore3 > nFinaleScore2){
                    printf("Congratulations %s! You won Jeopardy with a score of $%d!\n", strThirdHold, nFinaleScore3);
                } else {
                    printf("It seems there was a tie!\n");
                }

            }

            printf("Press Any Key to Continue\n");  
            getch();

            ClearTerminal();
            }
            
        } break;

        // Triggers instructions
        case '2': 
        { 
            ClearTerminal();
            printf("\nWelcome to Jeopardy! Here are the rules:\n");
            printf("1. There may be up to 3 players and you will input your names.\n");
            printf("   Then the play order will be randomly chosen.\n");
            printf("2. The number of turns for the Jeopardy and Double rounds are\n");
            printf("   set at the start of the game.\n");
            printf("3. The game starts with the Jeopardy round where you may select\n");
            printf("   from 4 Categories to answer. After that, a multiple choice question is given. \n");
            printf("   Remember that you must answer with what are CAPITAL LETTERS. \n");
            printf("4. Answering the question correctly gives the corresponding score.\n");
            printf("   Meanwhile, answering the question wrong will deduct the value\n");
            printf("5. When a question is answered incorrectly, the next player will\n");
            printf("   be given a chance to answer the question, answer it right, then\n");
            printf("   you may earn the corresponding points, but answer wrong and it \n");
            printf("   will be deducted from you instead.\n");
            printf("6. Answering correctly after a mistake sets you as the new current\n");
            printf("   player. The mistake rotation will occur until the last player. \n");
            printf("   If nobody can answer the question, it is the initial player's \n");
            printf("   turn once again. \n");
            printf("7. Upon finishing the Jeopardy round, the Double Round begins.\n");
            printf("   It can either be set to Normal or Zero mode.\n");
            printf("8. Normal mode simply deducts the score meanwhile Zero mode\n");
            printf("   sets the player's score to 0 when a mistake is made.\n");
            printf("9. At the end of the Double Round is the Final Jeopardy.\n");
            printf("   Here, each player can set a wager at the start of the game.\n");
            printf("10.When the question is answered correctly, the player earns\n");
            printf("   their wager otherwise, they lose it.\n");
            printf("11.Game may be ended at any point and the final points will be displayed.\n\n");

            printf("Press Any Key to Continue\n");  
            getch();

            ClearTerminal();


        } break;

        // triggers exit
        case '3': 
        { 
            nGame = 0;
            printf("Thank you for playing!\n");  
            getch();
            exit(0);
        } break;
    }
    }
	
	return 0;
}

/*
This is to certify that this project is my own work, based on my personal efforts in studying and applying the concepts
learned. I have consructed the functions and their respective algorithms and corresponding code all by myself. The 
program was run, tested, and debugged by my own efforts. I further certify that I have not copied in part or whole 
or otherwise plagiarized the work of other students and/or persons.

Miranda, Juan Miguel
DLSU ID: 12307513
*/