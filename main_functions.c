/*
	Description: 
	Precondition: A valid category was chosen
	@ param p# - the prizes for each item
	@return number of the question
*/
int CheckAnswer(char* CatQ, char* CatCh, char CatAns, int* nActiveScore, int* CatP, char* strActivePlayer, int* CatProgress){
    printf("\n%s \n%s \n%c \n%d \n%d \n%s \n%d\n", CatQ, CatCh, CatAns, nActiveScore, CatP, strActivePlayer, CatProgress);

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
        *CatProgress -= 1;

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
	Description: Checks to see if a question choice is available
	Precondition: A valid category was chosen
	@ param p# - the prizes for each item
	@return number of the question
*/

void PickChoice(
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

                int* nTurnTracker, int nPlayers,

                char* strFirst, char* strSecond, char* strThird,
                int* nFirstScore, int* nSecondScore, int* nThirdScore,
                char* strActivePlayer, int* nActiveScore
                )
    {

    int CatAProgress = 5;
    int CatBProgress = 5;
    int CatCProgress = 5;
    int CatDProgress = 5;
    int CatEProgress = 5;

    int nChoiceLoop1 = 1;
    int nFailCounter = 0;

    char cCategChoice;
    char cQuestionChoice;

    int nAnswerStatus;

    int nValidQ;
    int nFailedQ;
    char cRebound;

        printf("It is currently %s's turn\n Your score is: %d\n", strActivePlayer, *nActiveScore);
        printf("Select which category you want to answer: \n [A] %s\n [B] %s\n [C] %s\n [D] %s\n [E] Exit Game\n", Title1, Title2, Title3, Title4);

    while (nChoiceLoop1) {
            printf("Please choose a category [A, B, C, D, E]: ");
            scanf(" %1c", &cCategChoice);
            while (getchar() != '\n');

            if (cCategChoice == 'A') {
                if (CatAProgress > 0) {
                    printf("You chose category [A] %s\n", Title1);

                    nValidQ = ValidateQuestion(Cat1P1, Cat1P2, Cat1P3, Cat1P4, Cat1P5);

                    switch (nValidQ){
                        case 1:{
                        
                            PickAnswer(Cat1Q1, Cat1Ch1, Cat1Ans1, Cat1P1, 
                                       nTurnTracker, nPlayers, &CatAProgress, nFailCounter,
                                       strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore,
                                       strActivePlayer, nActiveScore);

                        } break;

                        // case 2:{
                        //     nAnswerStatus = CheckAnswer(Cat1Q2, Cat1Ch2, Cat1Ans2, nActiveScore, Cat1P2, strActivePlayer, &CatAProgress);

                        //     if (nAnswerStatus > 0 && nPlayers > 1){
                        //         nFailCounter++;
                        //         nFailedQ = 1;

                        //         do {
                        //             changePlayers(nTurnTracker, nPlayers, strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore, strActivePlayer, nActiveScore);
                        //             printf("What is your answer to the question? ");
                        //             scanf(" %1c", &cRebound);
                        //             while (getchar() != '\n');

                        //             if (cRebound == Cat1Ans2){
                        //                 printf("Correct! You won $%d\n", *Cat1P2);
                        //                 *nActiveScore += *Cat1P2;
                        //                 nFailedQ = 0;

                        //                 printf("Press Any Key to Continue\n");  
                        //                  getch();

                        //                  clearTerminal();
                        //             } else {
                        //                 printf("Sorry but that answer is incorrect. You lost $%d\n\n", *Cat1P2);
                        //                 *nActiveScore -= *Cat1P2;
                        //             }

                        //             nFailCounter += 1;

                        //             if (nFailCounter == nPlayers && cRebound != Cat1Ans2){
                        //                 printf("Nobody got the correct answer.\n");
                        //                 nFailedQ = 0;

                        //                 printf("Press Any Key to Continue\n");  
                        //                  getch();

                        //                  clearTerminal();
                        //             }
                                    
                        //         } while (nFailedQ);
                        //     }

                        //     *Cat1P2 = 0;

                        //     if (nPlayers == 1 && nAnswerStatus > 0){
                        //                 printf("Press Any Key to Continue\n");  
                        //                  getch();

                        //                  clearTerminal();
                        //     }
                            
                        // } break;

                        // case 3:{
                        //     nAnswerStatus = CheckAnswer(Cat1Q3, Cat1Ch3, Cat1Ans3, nActiveScore, Cat1P3, strActivePlayer, &CatAProgress);

                        //     if (nAnswerStatus > 0 && nPlayers > 1){
                        //         nFailCounter++;
                        //         nFailedQ = 1;

                        //         do {
                        //             changePlayers(nTurnTracker, nPlayers, strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore, strActivePlayer, nActiveScore);
                        //             printf("What is your answer to the question? ");
                        //             scanf(" %1c", &cRebound);
                        //             while (getchar() != '\n');

                        //             if (cRebound == Cat1Ans3){
                        //                 printf("Correct! You won $%d\n", *Cat1P3);
                        //                 *nActiveScore += *Cat1P3;
                        //                 nFailedQ = 0;

                        //                 printf("Press Any Key to Continue\n");  
                        //                  getch();

                        //                  clearTerminal();
                        //             } else {
                        //                 printf("Sorry but that answer is incorrect. You lost $%d\n\n", *Cat1P3);
                        //                 *nActiveScore -= *Cat1P3;
                        //             }

                        //             nFailCounter += 1;

                        //             if (nFailCounter == nPlayers && cRebound != Cat1Ans3){
                        //                 printf("Nobody got the correct answer.\n");
                        //                 nFailedQ = 0;

                        //                 printf("Press Any Key to Continue\n");  
                        //                  getch();

                        //                  clearTerminal();
                        //             }
                                    
                        //         } while (nFailedQ);
                        //     }

                        //     *Cat1P3 = 0;

                        //     if (nPlayers == 1 && nAnswerStatus > 0){
                        //                 printf("Press Any Key to Continue\n");  
                        //                  getch();

                        //                  clearTerminal();
                        //     }
                            
                        // } break;

                        // case 4:{
                        //     nAnswerStatus = CheckAnswer(Cat1Q4, Cat1Ch4, Cat1Ans4, nActiveScore, Cat1P4, strActivePlayer, &CatAProgress);

                        //     if (nAnswerStatus > 0 && nPlayers > 1){
                        //         nFailCounter++;
                        //         nFailedQ = 1;

                        //         do {
                        //             changePlayers(nTurnTracker, nPlayers, strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore, strActivePlayer, nActiveScore);
                        //             printf("What is your answer to the question? ");
                        //             scanf(" %1c", &cRebound);
                        //             while (getchar() != '\n');

                        //             if (cRebound == Cat1Ans4){
                        //                 printf("Correct! You won $%d\n", *Cat1P4);
                        //                 *nActiveScore += *Cat1P4;
                        //                 nFailedQ = 0;

                        //                 printf("Press Any Key to Continue\n");  
                        //                  getch();

                        //                  clearTerminal();
                        //             } else {
                        //                 printf("Sorry but that answer is incorrect. You lost $%d\n\n", *Cat1P4);
                        //                 *nActiveScore -= *Cat1P4;
                        //             }

                        //             nFailCounter += 1;

                        //             if (nFailCounter == nPlayers && cRebound != Cat1Ans4){
                        //                 printf("Nobody got the correct answer.\n");
                        //                 nFailedQ = 0;

                        //                 printf("Press Any Key to Continue\n");  
                        //                  getch();

                        //                  clearTerminal();
                        //             }
                                    
                        //         } while (nFailedQ);
                        //     }

                        //     *Cat1P4 = 0;

                        //     if (nPlayers == 1 && nAnswerStatus > 0){
                        //                 printf("Press Any Key to Continue\n");  
                        //                  getch();

                        //                  clearTerminal();
                        //     }
                            
                        // } break;

                        // case 5:{
                        //     nAnswerStatus = CheckAnswer(Cat1Q5, Cat1Ch5, Cat1Ans5, nActiveScore, Cat1P5, strActivePlayer, &CatAProgress);

                        //     if (nAnswerStatus > 0 && nPlayers > 1){
                        //         nFailCounter++;
                        //         nFailedQ = 1;

                        //         do {
                        //             changePlayers(nTurnTracker, nPlayers, strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore, strActivePlayer, nActiveScore);
                        //             printf("What is your answer to the question? ");
                        //             scanf(" %1c", &cRebound);
                        //             while (getchar() != '\n');

                        //             if (cRebound == Cat1Ans5){
                        //                 printf("Correct! You won $%d\n", *Cat1P5);
                        //                 *nActiveScore += *Cat1P5;
                        //                 nFailedQ = 0;

                        //                 printf("Press Any Key to Continue\n");  
                        //                  getch();

                        //                  clearTerminal();
                        //             } else {
                        //                 printf("Sorry but that answer is incorrect. You lost $%d\n\n", *Cat1P5);
                        //                 *nActiveScore -= *Cat1P5;
                        //             }

                        //             nFailCounter += 1;

                        //             if (nFailCounter == nPlayers && cRebound != Cat1Ans5){
                        //                 printf("Nobody got the correct answer.\n");
                        //                 nFailedQ = 0;

                        //                 printf("Press Any Key to Continue\n");  
                        //                  getch();

                        //                  clearTerminal();
                        //             }
                                    
                        //         } while (nFailedQ);
                        //     }

                        //     *Cat1P5 = 0;

                        //     if (nPlayers == 1 && nAnswerStatus > 0){
                        //                 printf("Press Any Key to Continue\n");  
                        //                  getch();

                        //                  clearTerminal();
                        //     }
                            
                        // } break;               
                    }

                    nChoiceLoop1 = 0;
                } else {
                    printf("The category has been completed. Pick another.\n");
                }
            } else if (cCategChoice == 'B') {
                if (CatBProgress > 0) {
                    printf("You chose category B\n");
                    nChoiceLoop1 = 0;
                } else {
                    printf("The category has been completed. Pick another.\n");
                }
            } else if (cCategChoice == 'C') {
                if (CatBProgress > 0) {
                    printf("You chose category B\n");
                    nChoiceLoop1 = 0;
                } else {
                    printf("The category has been completed. Pick another.\n");
                }
            } else if (cCategChoice == 'D') {
                if (CatBProgress > 0) {
                    printf("You chose category B\n");
                    nChoiceLoop1 = 0;
                } else {
                    printf("The category has been completed. Pick another.\n");
                }
            } else if (cCategChoice == 'E') {
                printf("You chose to exit the game\n");
                nChoiceLoop1 = 0;
            } else {
                printf("Invalid choice. Please pick from: [A, B, C, D, E]\n");
            }
        }

    printf("Out of the loop");

        }


