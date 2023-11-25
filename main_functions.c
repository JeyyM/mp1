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
                printf("\nCat A progress%d\n", CatAProgress);
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

                        case 2:{
                            PickAnswer(Cat1Q2, Cat1Ch2, Cat1Ans2, Cat1P2, 
                                       nTurnTracker, nPlayers, &CatAProgress, nFailCounter,
                                       strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore,
                                       strActivePlayer, nActiveScore);
                        } break;

                        case 3:{
                            PickAnswer(Cat1Q3, Cat1Ch3, Cat1Ans3, Cat1P3, 
                                       nTurnTracker, nPlayers, &CatAProgress, nFailCounter,
                                       strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore,
                                       strActivePlayer, nActiveScore);
                        } break;

                        case 4:{
                            PickAnswer(Cat1Q4, Cat1Ch4, Cat1Ans4, Cat1P4, 
                                       nTurnTracker, nPlayers, &CatAProgress, nFailCounter,
                                       strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore,
                                       strActivePlayer, nActiveScore);
                        } break;

                        case 5:{
                            PickAnswer(Cat1Q5, Cat1Ch5, Cat1Ans5, Cat1P5, 
                                       nTurnTracker, nPlayers, &CatAProgress, nFailCounter,
                                       strFirst, strSecond, strThird, nFirstScore, nSecondScore, nThirdScore,
                                       strActivePlayer, nActiveScore);
                        } break;               
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


