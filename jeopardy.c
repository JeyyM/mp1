#include <stdio.h>
#include <stdlib.h> // gets functions like randomization, etc.
#include <string.h> // allows for operations with strings like strcpy()
#include "ascii.c"
#include "functions.c"
#include "questions1.c"
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
void PlayGame(){
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

    nTurnTracker = 1;

    //Sets the number of questions that will be answered per round
    nJeopardyProgress = 4;

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
    getch();  // waits for a char on key press

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
                   strActivePlayer, &nActiveScore
                   );

               nJeopardyProgress -= 1;

    } while (nJeopardyProgress > 0);

    printf("Regular jeaopardy finish");
    
}

int main ()
{
	char cMode;

    cMode = startMenu();

    switch (cMode) {
        case '1':
        {
            PlayGame();
        } break;

        case '2': 
        { 
            
        } break;
        // put the break at the end of case 3, where the exit statement happens at the end
        case '3': 
        { 
            
        } break;
    }
	
	return 0;
}

