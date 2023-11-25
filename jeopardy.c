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
	Description: Starts the game if the user picks 1
	Precondition: none
	@ param none
	@return none
*/

void PlayGame(int nLength1, int* nLength2, int* nPlayersHold, int* nTurnTrackerHold, 
              char* strFirstHold, char* strSecondHold, char* strThirdHold, char* strActivePlayerHold, 
              int* nFirstScoreHold, int* nSecondScoreHold, int* nThirdScoreHold, int* nActiveScoreHold){
    int nPlayers;
    int nTurnTracker;

    int nCateg1, nCateg2, nCateg3, nCateg4;

    char strPlayer1Name[16];
    char strPlayer2Name[16];
    char strPlayer3Name[16];
    char strActivePlayer[16];

    char strFirst[16];
    char strSecond[16];
    char strThird[16];

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

    int nFirstScore;
    int nSecondScore;
    int nThirdScore;
    int nActiveScore;

    int nJeopardyProgress;

    int CatAProgress = 5;
    int CatBProgress = 5;
    int CatCProgress = 5;
    int CatDProgress = 5;
    int CatEProgress = 5;

    nTurnTracker = 1;

    //Sets the number of questions that will be answered per round
    nJeopardyProgress = nLength1;

    nPlayers = getPlayers();
    printf("What are the Player/s' names? \n");

    if (nPlayers >= 1){
        printf("What is Player 1's name (Max of 15 characters long and no spaces): ");
        scanf("%15s", &strPlayer1Name);
        while (getchar() != '\n');
        nFirstScore = 1;
    }

    if (nPlayers >= 2){
        printf("What is Player 2's name (Max of 15 characters long and no spaces): ");
        scanf("%15s", &strPlayer2Name);
        while (getchar() != '\n');
        nSecondScore = 2;
    } 
    
    if (nPlayers >= 3){
        printf("What is Player 3's name (Max of 15 characters long and no spaces): ");
        scanf("%15s", &strPlayer3Name);
        while (getchar() != '\n');
        nThirdScore = 3;
    }

    orderPlayers(&nPlayers, strPlayer1Name, strPlayer2Name, strPlayer3Name, strFirst, strSecond, strThird);

    printf("Press Any Key to Continue\n");  
    getch();

    clearTerminal();

    nCateg1 = randMinMax(1, 7);

    nCateg2 = randMinMax(1, 7);
    if (nCateg2 == nCateg1) {
        do {
            nCateg2 = randMinMax(1, 7);
        } while (nCateg2 == nCateg1);
    } 

    nCateg3 = randMinMax(1, 7);
    if (nCateg3 == nCateg1 || nCateg3 == nCateg2) {
        do {
            nCateg3 = randMinMax(1, 7);
        } while (nCateg3 == nCateg1 || nCateg3 == nCateg2);
    }

    nCateg4 = randMinMax(1, 7);
    if (nCateg4 == nCateg1 || nCateg4 == nCateg2 || nCateg4 == nCateg3) {
        do {
            nCateg4 = randMinMax(1, 7);
        } while (nCateg4 == nCateg1 || nCateg4 == nCateg2 || nCateg4 == nCateg3);
    }

    getContent1(nCateg1, strTitle1, Cat1Q1, Cat1Q2, Cat1Q3, Cat1Q4, Cat1Q5);
    getContent2(nCateg1, Cat1Ch1, Cat1Ch2, Cat1Ch3, Cat1Ch4, Cat1Ch5, &Cat1Ans1, &Cat1Ans2, &Cat1Ans3, &Cat1Ans4, &Cat1Ans5);
    getContent3(nCateg1, &Cat1P1, &Cat1P2, &Cat1P3, &Cat1P4, &Cat1P5);

    getContent1(nCateg2, strTitle2, Cat2Q1, Cat2Q2, Cat2Q3, Cat2Q4, Cat2Q5);
    getContent2(nCateg2, Cat2Ch1, Cat2Ch2, Cat2Ch3, Cat2Ch4, Cat2Ch5, &Cat2Ans1, &Cat2Ans2, &Cat2Ans3, &Cat2Ans4, &Cat2Ans5);
    getContent3(nCateg2, &Cat2P1, &Cat2P2, &Cat2P3, &Cat2P4, &Cat2P5);

    getContent1(nCateg3, strTitle3, Cat3Q1, Cat3Q2, Cat3Q3, Cat3Q4, Cat3Q5);
    getContent2(nCateg3, Cat3Ch1, Cat3Ch2, Cat3Ch3, Cat3Ch4, Cat3Ch5, &Cat3Ans1, &Cat3Ans2, &Cat3Ans3, &Cat3Ans4, &Cat3Ans5);
    getContent3(nCateg3, &Cat3P1, &Cat3P2, &Cat3P3, &Cat3P4, &Cat3P5);

    getContent1(nCateg4, strTitle4, Cat4Q1, Cat4Q2, Cat4Q3, Cat4Q4, Cat4Q5);
    getContent2(nCateg4, Cat4Ch1, Cat4Ch2, Cat4Ch3, Cat4Ch4, Cat4Ch5, &Cat4Ans1, &Cat4Ans2, &Cat4Ans3, &Cat4Ans4, &Cat4Ans5);
    getContent3(nCateg4, &Cat4P1, &Cat4P2, &Cat4P3, &Cat4P4, &Cat4P5);

    printf("The chosen categories are: \n%s \n%s \n%s \n%s \n", strTitle1, strTitle2, strTitle3, strTitle4);

    printf("\nPress Any Key to Continue\n");  
    getch();

    clearTerminal();

    printf("It's time for the first round of JEOPARDY!\n");

    setPlayer(nTurnTracker, strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore, strActivePlayer, &nActiveScore);

    do {
            printTable(Cat1P1, Cat2P1, Cat3P1, Cat4P1,
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

                   &CatAProgress, &CatBProgress, &CatCProgress, &CatDProgress, &CatEProgress, &nJeopardyProgress, nLength2
                   );

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

    if (nPlayers >=2 ){
            printf("%s: %d\n", strSecond, nSecondScore);
    }

    if (nPlayers >=3 ){
            printf("%s: %d\n", strThird, nThirdScore);
    }

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

    clearTerminal();
    
}

void PlayGame2(int* nLength2, int nPlayersHold, int nTurnTrackerHold, 
              char* strFirstHold, char* strSecondHold, char* strThirdHold, char* strActivePlayerHold, 
              int nFirstScoreHold, int nSecondScoreHold, int nThirdScoreHold, int nActiveScoreHold){
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

    int nFirstScore = nFirstScoreHold;
    int nSecondScore = nSecondScoreHold;
    int nThirdScore = nThirdScoreHold;
    int nActiveScore = nActiveScoreHold;

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

    nCateg1 = randMinMax(1, 7);

    nCateg2 = randMinMax(1, 7);
    if (nCateg2 == nCateg1) {
        do {
            nCateg2 = randMinMax(1, 7);
        } while (nCateg2 == nCateg1);
    } 

    nCateg3 = randMinMax(1, 7);
    if (nCateg3 == nCateg1 || nCateg3 == nCateg2) {
        do {
            nCateg3 = randMinMax(1, 7);
        } while (nCateg3 == nCateg1 || nCateg3 == nCateg2);
    }

    nCateg4 = randMinMax(1, 7);
    if (nCateg4 == nCateg1 || nCateg4 == nCateg2 || nCateg4 == nCateg3) {
        do {
            nCateg4 = randMinMax(1, 7);
        } while (nCateg4 == nCateg1 || nCateg4 == nCateg2 || nCateg4 == nCateg3);
    }

    getContent4(nCateg1, strTitle1, Cat1Q1, Cat1Q2, Cat1Q3, Cat1Q4, Cat1Q5);
    getContent5(nCateg1, Cat1Ch1, Cat1Ch2, Cat1Ch3, Cat1Ch4, Cat1Ch5, &Cat1Ans1, &Cat1Ans2, &Cat1Ans3, &Cat1Ans4, &Cat1Ans5);
    getContent6(nCateg1, &Cat1P1, &Cat1P2, &Cat1P3, &Cat1P4, &Cat1P5);

    getContent4(nCateg2, strTitle2, Cat2Q1, Cat2Q2, Cat2Q3, Cat2Q4, Cat2Q5);
    getContent5(nCateg2, Cat2Ch1, Cat2Ch2, Cat2Ch3, Cat2Ch4, Cat2Ch5, &Cat2Ans1, &Cat2Ans2, &Cat2Ans3, &Cat2Ans4, &Cat2Ans5);
    getContent6(nCateg2, &Cat2P1, &Cat2P2, &Cat2P3, &Cat2P4, &Cat2P5);

    getContent4(nCateg3, strTitle3, Cat3Q1, Cat3Q2, Cat3Q3, Cat3Q4, Cat3Q5);
    getContent5(nCateg3, Cat3Ch1, Cat3Ch2, Cat3Ch3, Cat3Ch4, Cat3Ch5, &Cat3Ans1, &Cat3Ans2, &Cat3Ans3, &Cat3Ans4, &Cat3Ans5);
    getContent6(nCateg3, &Cat3P1, &Cat3P2, &Cat3P3, &Cat3P4, &Cat3P5);

    getContent4(nCateg4, strTitle4, Cat4Q1, Cat4Q2, Cat4Q3, Cat4Q4, Cat4Q5);
    getContent5(nCateg4, Cat4Ch1, Cat4Ch2, Cat4Ch3, Cat4Ch4, Cat4Ch5, &Cat4Ans1, &Cat4Ans2, &Cat4Ans3, &Cat4Ans4, &Cat4Ans5);
    getContent6(nCateg4, &Cat4P1, &Cat4P2, &Cat4P3, &Cat4P4, &Cat4P5);

    printf("The chosen categories are: \n%s \n%s \n%s \n%s \n", strTitle1, strTitle2, strTitle3, strTitle4);

    printf("\nPress Any Key to Continue\n");  
    getch();

    clearTerminal();

    printf("It's time for the second round of JEOPARDY! The Double Round\n");

    setPlayer(nTurnTracker, strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore, strActivePlayer, &nActiveScore);

    do {
            printTable(Cat1P1, Cat2P1, Cat3P1, Cat4P1,
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

                   &CatAProgress, &CatBProgress, &CatCProgress, &CatDProgress, &CatEProgress, &nJeopardyProgress, nLength2
                   );

               nJeopardyProgress -= 1;

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

    clearTerminal();
    
}

int main ()
{
    while (1){
	char cMode;
    int nLength1;
    int nLengthValid1;
    int nLength2;
    int nLengthValid2;
    int nDoubleMode;
    int nDoubleModeInput;

    cMode = startMenu();

    switch (cMode) {
        case '1':
        {
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
            //Sets jeopardy and double round scores
        do {
            printf("Set Jeopardy Round Length (1 to 20): ");
            nLengthValid1 = scanf("%d", &nLength1);

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
                     strActivePlayerHold, &nFirstScoreHold, &nSecondScoreHold, &nThirdScoreHold, &nActiveScoreHold);

            if (nLength2 > 0){
                printDouble();

            PlayGame2(&nLength2, nPlayersHold, nTurnTrackerHold, strFirstHold, strSecondHold, strThirdHold, strActivePlayerHold, 
                      nFirstScoreHold, nSecondScoreHold, nThirdScoreHold, nActiveScoreHold);
            }
            
        } break;

        case '2': 
        { 
            clearTerminal();
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

            clearTerminal();


        } break;
        case '3': 
        { 
            exit(0);
        } break;
    }
    }
	
	return 0;
}

