/*
	Description: Prints the jeopardy logo
	Precondition: none
	@ param none
	@return none
*/
void PrintJeopardy()
{
	const char *banner = 
	"##############################################################################################\n"
	"# 	                                                                                *-++ #\n"
	"#                                                                                       *@@+ #\n"
	"#       .###. +#######= :*######*..#######*-  :*####+   +#######+. :#######+ :##*  .### *@@+ #\n"
	"#       :@@@:=@@@@@@@@* #@@@@@@@@=:@@@@@@@@@: *@@@@@@.  #@@@@@@@@* -@@@@@@@@+-@@%  :@@@ *@@+ #\n"
	"#       :@@@:=@@@@@@@@* #@@@@@@@@=:@@@@@@@@@: %@@@@@@-  #@@@@@@@@* -@@@@@@@@*-@@%  :@@@ *@@+ #\n"
	"#       :@@@:=@@@@@@@@* #@@@@@@@@=:@@@@@@@@@: @@@@@@@+  #@@@@@@@@* -@@@@@@@@*-@@%  :@@@ *@@+ #\n"
	"#       :@@@:=@@@@@@@@* #@@@@@@@@=:@@@@@@@@@:.@@@@@@@#  #@@@@@@@@* -@@@@@@@@*-@@%  :@@@ *@@+ #\n"
	"#       :@@@:=@@@+====: #@@@=+@@@=:@@@+=*@@@:-@@@=#@@@  #@@%==@@@* -@@%==#@@*-@@%  :@@@ *@@+ #\n"
	"#       :@@@:=@@@       #@@%  @@@=:@@@: :@@@:+@@# -@@@  #@@#  #@@* -@@*  =@@*-@@%  :@@@ *@@+ #\n"
	"# .:::  :@@@:=@@@-::::. #@@%  @@@=:@@@-.=@@@:#@@*.-@@@: #@@%.:%@@* -@@*  =@@*-@@@:.=@@@ *@@+ #\n"
	"# =@@@. :@@@:=@@@@@@@@* #@@%  @@@=:@@@@@@@@@.@@@@@@@@@= #@@@@@@@%. -@@*  =@@*.%@@@@@@@@ *@@+ #\n"
	"# =@@@. :@@@:=@@@-::::. #@@%  @@@=:@@@-:::: .@@@=::%@@* #@@%::*@@# -@@*  =@@*  .:::=@@@ *@@+ #\n"
	"# =@@@. :@@@:=@@@       #@@%  @@@=:@@@:     :@@@.  *@@% #@@#  :@@% -@@*  =@@*      :@@@ :--. #\n"
	"# =@@@*+*@@@:=@@@*++++- #@@@+*@@@=:@@@:     =@@@   =@@@ #@@#  :@@% -@@%++#@@*.+++++#@@@ .... #\n"
	"# :%@@@@@@@# .#@@@@@@@* -%@@@@@@%::@@@:     *@@*   :@@@.#@@#  .@@% -@@@@@@@#.-@@@@@@@%= *@@= #\n"
	"#                                                                                            #\n"
	"##############################################################################################\n \n"	
	;
		printf("%s", banner);
}

/*
	Description: Prints the Double Round
	Precondition: none
	@ param none
	@return none
*/
void PrintDouble()
{
	printf("         #####     #####   ##   ##  ######   ####     #######  \n");
    printf("          ## ##   ### ###  ##   ##   ##  ##   ##       ##   #  \n");
    printf("          ##  ##  ##   ##  ##   ##   ##  ##   ##       ##      \n");
    printf("          ##  ##  ##   ##  ##   ##   #####    ##       ####    \n");
    printf("          ##  ##  ##   ##  ##   ##   ##  ##   ##       ##      \n");
    printf("          ## ##   ### ###  ##   ##   ##  ##   ##  ##   ##   #  \n");
    printf("         #####     #####    #####   ######   #######  #######  \n");
    printf("                                                               \n");
    printf("         ######    #####   ##   ##  ##   ##  #####    \n");
    printf("          ##  ##  ### ###  ##   ##  ###  ##   ## ##   \n");
    printf("          ##  ##  ##   ##  ##   ##  #### ##   ##  ##  \n");
    printf("          #####   ##   ##  ##   ##  #######   ##  ##  \n");
    printf("          ## ##   ##   ##  ##   ##  ## ####   ##  ##  \n");
    printf("          ## ##   ### ###  ##   ##  ##  ###   ## ##   \n");
    printf("         #### ##   #####    #####   ##   ##  #####    \n");
    printf("                                                       \n");
}

/*
	Description: Prints the Final Jeopardy
	Precondition: none
	@ param none
	@return none
*/
void PrintFinal() {
    printf("                  ### ###    ####   ###  ##    ##     ####     \n");
    printf("                   ##  ##     ##      ## ##     ##     ##      \n");
    printf("                   ##         ##     # ## #   ## ##    ##      \n");
    printf("                   ## ##      ##     ## ##    ##  ##   ##      \n");
    printf("                   ##         ##     ##  ##   ## ###   ##      \n");
    printf("                   ##         ##     ##  ##   ##  ##   ##  ##  \n");
    printf("                  ####       ####   ###  ##  ###  ##  ### ###  \n");
    printf("                                                               \n");
    printf("   ####  ### ###   ## ##   ### ##     ##     ### ##   ### ##   ##  ##   \n");
    printf("    ##    ##  ##  ##   ##   ##  ##     ##     ##  ##   ##  ##  ##  ##   \n");
    printf("    ##    ##      ##   ##   ##  ##   ## ##    ##  ##   ##  ##  ##  ##   \n");
    printf("    ##    ## ##   ##   ##   ##  ##   ##  ##   ## ##    ##  ##   ## ##   \n");
    printf("##  ##    ##      ##   ##   ## ##    ## ###   ## ##    ##  ##    ##     \n");
    printf("##  ##    ##  ##  ##   ##   ##       ##  ##   ##  ##   ##  ##    ##     \n");
    printf(" ## #    ### ###   ## ##   ####     ###  ##  #### ##  ### ##     ##     \n");
    printf("                                                                       \n");
}

/*
	Description: These prints are for making the jeopardy table
	Precondition: none
	@ param the row#x are the price values
	@return none
*/
void PrintLine() {
    printf("---------------------------------------------\n");
}

void PrintRow(int column1, int column2, int column3, int column4) {
    printf("| $%-7d | $%-7d | $%-7d | $%-7d |\n", column1, column2, column3, column4);
}

void PrintTable(int row1a, int row1b, int row1c, int row1d,
                int row2a, int row2b, int row2c, int row2d,
                int row3a, int row3b, int row3c, int row3d,
                int row4a, int row4b, int row4c, int row4d,
                int row5a, int row5b, int row5c, int row5d){
    PrintLine();
    printf("| %-8s | %-8s | %-8s | %-8s |\n", "A", "B", "C", "D"); // the - makes it so that the space is on the right side
    PrintLine();
    PrintRow(row1a, row1b, row1c, row1d);
    PrintLine();
    PrintRow(row2a, row2b, row2c, row2d);
    PrintLine();
    PrintRow(row3a, row3b, row3c, row3d);
    PrintLine();
    PrintRow(row4a, row4b, row4c, row4d);
    PrintLine();
    PrintRow(row5a, row5b, row5c, row5d);
    PrintLine();
}
