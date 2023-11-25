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
                char* strActivePlayer, int* nActiveScore,

                int* CatAProgress, int* CatBProgress, int* CatCProgress, int* CatDProgress, int* CatEProgress, int* nJeopardyProgress, int* nLength2,
                int nDoubleMode
                )
    {

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
                if (*CatAProgress > 0) {
                    printf("You chose category [A] %s\n", Title1);

                    nValidQ = ValidateQuestion(Cat1P1, Cat1P2, Cat1P3, Cat1P4, Cat1P5);
                    *CatAProgress -= 1;

                    switch (nValidQ){
                        case 1:{
                        
                            PickAnswer(Cat1Q1, Cat1Ch1, Cat1Ans1, Cat1P1, 
                                       nTurnTracker, nPlayers, nFailCounter,
                                       strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore,
                                       strActivePlayer, nActiveScore, nDoubleMode);

                        } break;

                        case 2:{
                            PickAnswer(Cat1Q2, Cat1Ch2, Cat1Ans2, Cat1P2, 
                                       nTurnTracker, nPlayers, nFailCounter,
                                       strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore,
                                       strActivePlayer, nActiveScore, nDoubleMode);
                        } break;

                        case 3:{
                            PickAnswer(Cat1Q3, Cat1Ch3, Cat1Ans3, Cat1P3, 
                                       nTurnTracker, nPlayers, nFailCounter,
                                       strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore,
                                       strActivePlayer, nActiveScore, nDoubleMode);
                        } break;

                        case 4:{
                            PickAnswer(Cat1Q4, Cat1Ch4, Cat1Ans4, Cat1P4, 
                                       nTurnTracker, nPlayers, nFailCounter,
                                       strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore,
                                       strActivePlayer, nActiveScore, nDoubleMode);
                        } break;

                        case 5:{
                            PickAnswer(Cat1Q5, Cat1Ch5, Cat1Ans5, Cat1P5, 
                                       nTurnTracker, nPlayers, nFailCounter,
                                       strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore,
                                       strActivePlayer, nActiveScore, nDoubleMode);
                        } break;               
                    }

                    nChoiceLoop1 = 0;
                } else {
                    printf("The category has been completed. Pick another.\n");
                }
            } else if (cCategChoice == 'B') {
                if (*CatBProgress > 0) {
                    printf("You chose category [B] %s\n", Title2);

                    nValidQ = ValidateQuestion(Cat2P1, Cat2P2, Cat2P3, Cat2P4, Cat2P5);
                    *CatBProgress -= 1;

                    switch (nValidQ){
                        case 1:{
                        
                            PickAnswer(Cat2Q1, Cat2Ch1, Cat2Ans1, Cat2P1, 
                                       nTurnTracker, nPlayers, nFailCounter,
                                       strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore,
                                       strActivePlayer, nActiveScore, nDoubleMode);

                        } break;

                        case 2:{
                            PickAnswer(Cat2Q2, Cat2Ch2, Cat2Ans2, Cat2P2, 
                                       nTurnTracker, nPlayers, nFailCounter,
                                       strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore,
                                       strActivePlayer, nActiveScore, nDoubleMode);
                        } break;

                        case 3:{
                            PickAnswer(Cat2Q3, Cat2Ch3, Cat2Ans3, Cat2P3, 
                                       nTurnTracker, nPlayers, nFailCounter,
                                       strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore,
                                       strActivePlayer, nActiveScore, nDoubleMode);
                        } break;

                        case 4:{
                            PickAnswer(Cat2Q4, Cat2Ch4, Cat2Ans4, Cat2P4, 
                                       nTurnTracker, nPlayers, nFailCounter,
                                       strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore,
                                       strActivePlayer, nActiveScore, nDoubleMode);
                        } break;

                        case 5:{
                            PickAnswer(Cat2Q5, Cat2Ch5, Cat2Ans5, Cat2P5, 
                                       nTurnTracker, nPlayers, nFailCounter,
                                       strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore,
                                       strActivePlayer, nActiveScore, nDoubleMode);
                        } break;               
                    }

                    nChoiceLoop1 = 0;
                } else {
                    printf("The category has been completed. Pick another.\n");
                }
            } else if (cCategChoice == 'C') {
                if (*CatCProgress > 0) {
                    printf("You chose category [C] %s\n", Title3);

                    nValidQ = ValidateQuestion(Cat3P1, Cat3P2, Cat3P3, Cat3P4, Cat3P5);
                    *CatCProgress -= 1;

                    switch (nValidQ){
                        case 1:{
                        
                            PickAnswer(Cat3Q1, Cat3Ch1, Cat3Ans1, Cat3P1, 
                                       nTurnTracker, nPlayers, nFailCounter,
                                       strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore,
                                       strActivePlayer, nActiveScore, nDoubleMode);

                        } break;

                        case 2:{
                            PickAnswer(Cat3Q2, Cat3Ch2, Cat3Ans2, Cat3P2, 
                                       nTurnTracker, nPlayers, nFailCounter,
                                       strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore,
                                       strActivePlayer, nActiveScore, nDoubleMode);
                        } break;

                        case 3:{
                            PickAnswer(Cat3Q3, Cat3Ch3, Cat3Ans3, Cat3P3, 
                                       nTurnTracker, nPlayers, nFailCounter,
                                       strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore,
                                       strActivePlayer, nActiveScore, nDoubleMode);
                        } break;

                        case 4:{
                            PickAnswer(Cat3Q4, Cat3Ch4, Cat3Ans4, Cat3P4, 
                                       nTurnTracker, nPlayers, nFailCounter,
                                       strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore,
                                       strActivePlayer, nActiveScore, nDoubleMode);
                        } break;

                        case 5:{
                            PickAnswer(Cat3Q5, Cat3Ch5, Cat3Ans5, Cat3P5, 
                                       nTurnTracker, nPlayers, nFailCounter,
                                       strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore,
                                       strActivePlayer, nActiveScore, nDoubleMode);
                        } break;               
                    }

                    nChoiceLoop1 = 0;
                } else {
                    printf("The category has been completed. Pick another.\n");
                }
            } else if (cCategChoice == 'D') {
                if (*CatBProgress > 0) {
                    printf("You chose category [D] %s\n", Title4);

                    nValidQ = ValidateQuestion(Cat4P1, Cat4P2, Cat4P3, Cat4P4, Cat4P5);
                    *CatDProgress -= 1;

                    switch (nValidQ){
                        case 1:{
                        
                            PickAnswer(Cat4Q1, Cat4Ch1, Cat4Ans1, Cat4P1, 
                                       nTurnTracker, nPlayers, nFailCounter,
                                       strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore,
                                       strActivePlayer, nActiveScore, nDoubleMode);

                        } break;

                        case 2:{
                            PickAnswer(Cat4Q2, Cat4Ch2, Cat4Ans2, Cat4P2, 
                                       nTurnTracker, nPlayers, nFailCounter,
                                       strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore,
                                       strActivePlayer, nActiveScore, nDoubleMode);
                        } break;

                        case 3:{
                            PickAnswer(Cat4Q3, Cat4Ch3, Cat4Ans3, Cat4P3, 
                                       nTurnTracker, nPlayers, nFailCounter,
                                       strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore,
                                       strActivePlayer, nActiveScore, nDoubleMode);
                        } break;

                        case 4:{
                            PickAnswer(Cat4Q4, Cat4Ch4, Cat4Ans4, Cat4P4, 
                                       nTurnTracker, nPlayers, nFailCounter,
                                       strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore,
                                       strActivePlayer, nActiveScore, nDoubleMode);
                        } break;

                        case 5:{
                            PickAnswer(Cat4Q5, Cat4Ch5, Cat4Ans5, Cat4P5, 
                                       nTurnTracker, nPlayers, nFailCounter,
                                       strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore,
                                       strActivePlayer, nActiveScore, nDoubleMode);
                        } break;               
                    }

                    nChoiceLoop1 = 0;
                } else {
                    printf("The category has been completed. Pick another.\n");
                }
            } else if (cCategChoice == 'E') {
                clearTerminal();
                printf("You chose to exit the game.\n");

                *nJeopardyProgress = 0;
                *nLength2 = 0;
                nChoiceLoop1 = 0;
            } else {
                printf("Invalid choice. Please pick from: [A, B, C, D, E]\n");
            }
        }
        }


