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
int GetPlayers() {
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
char StartMenu()
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