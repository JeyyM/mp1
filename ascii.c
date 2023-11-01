/*
	Description: Prints the jeopardy logo
	Precondition: none
	@ param none
	@return none
*/
void printJeopardy()
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
	Description: These printers are for making the jeopardy table
	Precondition: none
	@ param the row#x are the price values
	@return none
*/
void printLine() {
    printf("---------------------------------------------\n");
}

void printRow(int column1, int column2, int column3, int column4) {
    printf("| $%-7d | $%-7d | $%-7d | $%-7d |\n", column1, column2, column3, column4);
}

void printTable(int row1a, int row1b, int row1c, int row1d,
                int row2a, int row2b, int row2c, int row2d,
                int row3a, int row3b, int row3c, int row3d,
                int row4a, int row4b, int row4c, int row4d,
                int row5a, int row5b, int row5c, int row5d){
    printLine();
    printf("| %-8s | %-8s | %-8s | %-8s |\n", "A", "B", "C", "D"); // the - makes it so that the space is on the right side
    printLine();
    printRow(row1a, row1b, row1c, row1d);
    printLine();
    printRow(row2a, row2b, row2c, row2d);
    printLine();
    printRow(row3a, row3b, row3c, row3d);
    printLine();
    printRow(row4a, row4b, row4c, row4d);
    printLine();
    printRow(row5a, row5b, row5c, row5d);
    printLine();
}
