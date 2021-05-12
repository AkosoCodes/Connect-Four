#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define x 7
#define y 6
#define matchSize 4

#define checkerPlayer1 'X'
#define checkerPlayer2 'O'
#define checkerWinner 'Y'

//      Normal Comment
//*     Highlighted Comment
//!     Alert Comment
//?     Query Comment
//      TODO A to do comment

//------------------------------------------------------------------------------------------------

//! VARIABLES
int menuOption; 
int board[y][x];
int returnToMenu;

char PLAYER_1[18];
char PLAYER_2[18];

int result = 0;
int choice = 0;
int currentPlayer;
int gameResult;


//! FUNCTIONS
void startMenu(); //Starts the Main Menu.
void newGame(); //Starts a New Game
void loadMenu();
void endMenu();
void exitGame(int code);

void showBoard(); // Shows the actual board.
int gameLoop();
int boardState(); // board state checks for conditions
bool addChecker(int _column, int _checker);
void fillInMatch(int _row, int _column, int _rowPattern, int _columnPattern);
bool CheckForMatches(int _row, int _column, int _rowPattern, int _columnPattern);
void clearBoard(); //Clears Board
void infoAndrija();
void rules(); // Opens the rules for the game.
void clear(); // Clears the terminal.
bool invalidChar(char *string, char invalidChar);


//* MAIN BODY
int main(){

    //Starts the program with the Start Menu
    startMenu();

    return 0;
}




//*                 Main Menu Functions
//*===================================================

//! Start Menu Function
void startMenu(){

    //* Do-While loop makes sure that it is repeated until the user makes a valid input.
    //  in this case, they select a option from the Menu.
    do
    {
        //clears the terminal
        clear();

        //Prints the Menu and options.
        printf("\n");
        printf("              -=- Connect Four -=-          \n");
        printf("           What would you like to do?       \n");
        printf("        +=============================+\n");
        printf("        |   1. New Game               |  \n");
        printf("        |   2. Load Saved Game        |  \n");
        printf("        |   3. How to play?           |  \n");
        printf("        |   4. Information            |  \n");
        printf("        |   5. Exit Game              |  \n");
        printf("        +=============================+\n");

        //Scans for input
        scanf("%d",&menuOption);

        //Flushes the input and clears the buffer so that a infinite loop doesn't occur.
        fflush(stdin);

    } while (menuOption > 5 || menuOption < 1);     //Checks whether the input is valid. in the case that it is not valid, the whole loop will repeat.


    //* Switch scans the previous input and assigns it to the particular case.
    //  Then, the case applies the code inside it.
    switch (menuOption)
    {

        //* New Game
        case 1:
            newGame();
        break;

        //* Load Game
        case 2:
            loadMenu();
        break;

        //* Rules
        //Opens the Rules function, where the instructions for the game are shown.
        case 3:
            rules();
        break;

        //* Information
        // opens information about me - Andrija :D
        case 4:
            infoAndrija();
        break;

        //* Exit Game
        //ends the switch operation and the startingMenu Function, and starts the code after the function in main.
        case 5:
            endMenu();
        return;
    }
      
}

//! Load Menu Function
void loadMenu(){

    do
    {
        //clears the terminal
        clear();

        //Prints the Menu and options.
        printf("\n");
        printf("              -=- Connect Four -=-          \n");
        printf("           What would you like to do?       \n");
        printf("        +=============================+\n");
        printf("        |   1. Load Game              |  \n");
        printf("        |   2. List all saved games   |  \n");
        printf("        |   3. List all Players       |  \n");
        printf("        |   4. Show a Board with ID   |  \n");
        printf("        |   5. Return to Main menu    |  \n");
        printf("        +=============================+\n");

        //Scans for input
        scanf("%d",&menuOption);

        //Flushes the input and clears the buffer so that a infinite loop doesn't occur.
        fflush(stdin);
    } while (menuOption > 5 || menuOption < 1);
    
    switch(menuOption){

        //* Load Game
        // Loads a saved game
        case 1:
        break;

        //* List Saved Games
        // Lists all the saved games from the save file.
        case 2:
        break;

        //* List Players
        // Lists all the saved players from the save file.
        case 3:
        break;

        //* Show a Board with ID
        // Shows a specific Board with ID
        case 4:
        break;

        //* Return to Main Menu
        // Returns back to Starting Menu
        case 5:
            startMenu();
        break;
    }
}

//! Rules Function
void rules(){

    do
    {
        clear();

        printf("\n");
        printf("                              -=- Connect Four -=-                               \n\n");

        //Description
        printf("Description:\n\n");
        printf("This game is played on a vertical board wich has seven hollow columns and six rows.\nEach column has a hole in the upper part of the board, where pieces are introduced.\nThere is a window for every square, so that pieces can be seen from both sides.\n\n");
    
        //Objective
        printf("Objective:\n\n");
        printf("The aim for both players is to make a straight line of four own pieces.\nThe line can be vertical, horizontal or diagonal.\n\n");
        
        printf("1. Return to Main Menu: ");
        scanf("%d", &returnToMenu);

    } while (returnToMenu != 1);

    if(returnToMenu == 1){
        startMenu();
    }
}

//! Information Function
void infoAndrija(){

    do
    {
    clear();

    printf("This whole program was written by Andrija Stankovic - 2020230164\n");
    //Written by Andrija Stankovic! :)

    printf("1. Return to Main Menu: ");
    scanf("%d", &returnToMenu);

    //Flushes the input and clears the buffer so that a infinite loop doesn't occur.
    fflush(stdin);
    } while (returnToMenu != 1);
    
    startMenu();

}

//! End Menu Function
void endMenu(){


    do
    {
        clear();

        printf("Are you sure you want to quit?\n");
        printf("1. No, take me back.\n");
        printf("2. Yes, quit the game.\n");

        scanf("%d", &returnToMenu);

    } while (returnToMenu>2 || returnToMenu < 1);

    if(returnToMenu == 1){
        startMenu();
    } else 
    exitGame(0);
    
}


//*===================================================

void showBoard(){

        //Clears Intro
        clear();

        //For loop to print horizontal border.      
        for(int i = 0; i<y; i++){

            printf("+");

            for(int k=0; k<x; k++){
                printf("===+");      
            } 
            printf("\n");


            //For loop to print vertical border.  
            printf("|");
            for (int j = 0; j<x; j++){

                switch (board[i][j]){
                    case 1:
                        printf(" %c ", checkerPlayer1);
                        break;

                    case 2:
                        printf(" %c ", checkerPlayer2);
                        break;

                    case 3:
                        printf(" %c ", checkerWinner);
                        break;

                    default:
                        printf("   ");
                        break;

                }
                //ends a column
                printf("|");
                
            }
            printf("\n");
        }

        //For loop to print final horizontal border.
            printf("+");

            for(int k=0; k<x; k++){
                printf("===+");      
            }
            printf("\n");
}

void ClearBoard() {
    //Loop through the elements and set all of them to 0
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            board[x][y] = 0;
        }
    }
}

//! NEW GAME
void newGame(){

    //Player 1 chooses the name
    do {
        clear();

        //Enter names
        printf("STARTING NEW GAME:\n");
        printf("Please enter the name of Player 1: ");
        scanf("%s", &PLAYER_1);

        //Flushes the input and clears the buffer so that a infinite loop doesn't occur.
        fflush(stdin);

    } while (invalidChar(PLAYER_1, ',')); //Checks whether the name contains ',', as that would be an invalid character due to how the games are stored and saved.
    
    //Player 2 chooses the name
    do {
        clear();

        //Enter names
        printf("STARTING NEW GAME:\n");
        printf("Please enter the name of Player 2: ");
        scanf("%s", &PLAYER_2);

        //Flushes the input and clears the buffer so that a infinite loop doesn't occur.
        fflush(stdin);
        
    } while (invalidChar(PLAYER_2, ',')); //Checks whether the name contains ',', as that would be an invalid character due to how the games are stored and saved.

    while(true){
    clearBoard(board); //Clears the board
    currentPlayer = 0; //Sets turn to Player 1
    
    result = gameLoop();

    //Checks the winner
    switch(result){

        //If Player 1 wins.
        case 1:
            printf("%s won the game!\n", PLAYER_1);
            system("pause");
        break;

        //If Player 2 wins.
        case 2:
            printf("%s won the game!\n", PLAYER_2);
            system("pause");
        break;

        //If it is a draw.
        case 3:
            printf("The game is a draw!\n");
            system("pause");
        break;

        //Otherwise, if there is another output for some reason, just break the funtion.
        default:
        break;
    }
    
    //After Game options
    do {
        choice = 0;
        clear();

        printf("What do you want to do next?\n");
        printf("1. Play another game!\n");
        printf("2. Return to Main Menu\n");
        printf("Choose an option: ");

        //scans for input.
        scanf("%d", &choice);

        //Flushes the input and clears the buffer so that a infinite loop doesn't occur.
        fflush(stdin);
    } while (choice != 1 && choice != 2);

        //Check player choice
        if (choice == 1) {
            //If the player choose 1, repeat the game loop
            continue;
        } else {
            //If the player choose 0,break and return to main menu
            startMenu();
        }
        
    }
}

//! GAME LOOP
int gameLoop(){

    //Player Input
    int choice = -1;

    //Check Board Input
    int check = 0;

    while(true){
        
        clear();
        check = boardState();

        //Displays the board
        showBoard();
        if(check == 0) {
            //resets the choice
            choice = -1;

            printf("It is %s's turn to play. \n", currentPlayer ? PLAYER_2 : PLAYER_1);
            printf("Select a column (1-%d) or press 0 to save: ", x);

            //Get player input
            scanf("%d", &choice);

            //Flushes the input and clears the buffer so that a infinite loop doesn't occur.
            fflush(stdin);

            if (choice > 0 && choice <=x){
                
                if (addChecker(choice, currentPlayer + 1)){

                    //If we successfully added a checker, change the player
                    currentPlayer = !currentPlayer;
                } else{
                    //If we did not add the checker, then inform that the column is full.
                    printf("Column %d is full, please select a valid column.\n", choice);
                    system("pause");
                }
            } else if(choice == 0){
                //saveGame();
            } else {
                //If the input was not 0, nor in range of the board, the player made an invalid choice
                printf("****Invalid choice****\n");
                system("pause");
            }  
        } else {
            //If our check returns anything other than 0, that means the game came to an end and pass that value back to StartGame
            return check;
        }
    }

    return 0;
}

//! Add Checker
bool addChecker(int _column, int _checker) {
    //Loop through elements vertically
    for (int i = y - 1; i >= 0; i--) {
        if (board[i][_column - 1] == 0) {
            //If we find an empty slot, add a checker
            board[i][_column - 1] = _checker;
            //Return true meaning we successfully added a checker
            return true;
        }
    }
    //If we did not exit the funtion with 1 during the for loop, exit with false
    //meaning that we can't add a checker in this column
    return false;
}

//! Board State
int boardState(){
    //Checks the board for matches

    int winner = 0;

    // Horizontal (-) check
    for (int i = y - 1; i >= 0; i--) {
        for (int j = 0; j <= x - matchSize; j++) {
            //Check if there are any matches
            if (CheckForMatches(i, j, 0, 1)) {
                //If we got a match return the winner and mark the winning match
                winner = board[i][j];
                fillInMatch(i, j, 0, 1);
                return winner;
            }
        }
    }

    // Vertical (|) check
    for (int i = y - 1; i >= (matchSize - 1); i--) {
        for (int j = 0; j < x; j++) {
            //Check if there are any matches
            if (CheckForMatches(i, j, -1, 0)) {
                //If we got a match return the winner and mark the winning match
                winner = board[i][j];
                fillInMatch(i, j, -1, 0);
                return winner;
            }
        }
    }

    // Diagonal (/) check
    for (int i = y - 1; i >= (matchSize - 1); i--) {
        for (int j = 0; j <= x - matchSize; j++) {
            //Check if there are any matches
            if (CheckForMatches(i, j, -1, 1)) {
                //If we got a match return the winner and mark the winning match
                winner = board[i][j];
                fillInMatch(i, j, -1, 1);
                return winner;
            }
            //Go to next element
        }
    }

    // Diagonal (\) check
    for (int i = y - 1; i >= (matchSize - 1); i--) {
        for (int j = x - 1; j >= (matchSize - 1); j--) {
            //Check if there are any matches
            if (CheckForMatches(i, j, -1, -1)) {
                //If we got a match return the winner and mark the winning match
                winner = board[i][j];
                fillInMatch(i, j, -1, -1);
                return winner;
            }
        }
    }

    //If none of the loops matched, check if the board is filled up
    int checkerCount = 0;
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (board[i][j] == 1 || board[i][j] == 2) {
                //Count the amount of checkers in the board
                checkerCount++;
            }
        }
    }

    if (checkerCount == x * y) {
        //If the amount of checkers in the board matches the amount of elements the board has
        //Return 3 which means none of the players won the game
        winner = 3;
    } else {
        //If the board is not full, and we have no winners, continue the game
        winner = 0;
    }
    //return winner value
    return winner;
}

//! Fill in the
void fillInMatch(int _row, int _column, int _rowPattern, int _columnPattern) {
    //Based on the starting element and pattern, loop throught the match size and set
    //every element to Y, marking the winner match
    for (int i = 0; i < matchSize; i++) {
        board[_row + _rowPattern * i][_column + _columnPattern * i] = 3;
    }
}

//! Check for MatchError
bool CheckForMatches(int _row, int _column, int _rowPattern, int _columnPattern) {
    //Count the matches
    int matches = 0;
    //Loop through elements following a pattern and find if any of them match
    for (int i = 0; i < matchSize; i++) {
        //Check if any any of the elements are 0
        if (board[_row + _rowPattern * i][_column + _columnPattern * i] == 0) {
            //If they are, skip this check since we know that 0 is a empty field
            return false;
        } else if (board[_row + _rowPattern * i][_column + _columnPattern * i] == board[_row][_column]) {
            //If the element matches the first element, count the match
            matches++;
        } else {
            //If we don't have a 0 and an element does not match the starting one, skip since we know there is no winner
            return false;
        }
    }
    if (matches == matchSize) {
        //If we matched MATCH_SIZE of elements, return true meaning there is a winner
        return true;
    }
    //If we didn't match MATCH_SIZE, return false meaning we did not find any winners
    return false;
}

//! Clear Board Function
void clearBoard(){
    //Goes from one element to another and sets it to 0.
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            board[x][y] = 0;
        }
    }
}

//! Exit Game Function (Thank you)
void exitGame(int code){
    //Prints out the message
    clear();
    printf(" _______ __   __ _______ __    _ ___   _   __   __ _______ __   __  \n");
    printf("|       |  | |  |   _   |  |  | |   | | | |  | |  |       |  | |  | \n");
    printf("|_     _|  |_|  |  |_|  |   |_| |   |_| | |  |_|  |   _   |  | |  | \n");
    printf("  |   | |       |       |       |      _| |       |  | |  |  |_|  | \n");
    printf("  |   | |       |       |  _    |     |_  |_     _|  |_|  |       | \n");
    printf("  |   | |   _   |   _   | | |   |    _  |   |   | |       |       | \n");
    printf("  |___| |__| |__|__| |__|_|  |__|___| |_|   |___| |_______|_______| \n");
    printf("\n");


    printf("_______ _______ ______     _______ ___     _______ __   __ ___ __    _ _______ __  \n");
    printf("|       |       |    _ |   |       |   |   |   _   |  | |  |   |  |  | |       |  |\n"); 
    printf("|    ___|   _   |   | ||   |    _  |   |   |  |_|  |  |_|  |   |   |_| |    ___|  |\n");
    printf("|   |___|  | |  |   |_||_  |   |_| |   |   |       |       |   |       |   | __|  |\n"); 
    printf("|    ___|  |_|  |    __  | |    ___|   |___|       |_     _|   |  _    |   ||  |__|\n"); 
    printf("|   |   |       |   |  | | |   |   |       |   _   | |   | |   | | |   |   |_| |__ \n"); 
    printf("|___|   |_______|___|  |_| |___|   |_______|__| |__| |___| |___|_|  |__|_______|__|\n"); 

    printf("\n"); printf("\n");

    //Terminates the program
    exit(code);
}

//! Clear Terminal Function
void clear(){
        
    //clears the terminal
    system("cls");

}

//! Invalid Char Boolean Function
bool invalidChar(char *string, char invalidChar){
    //It checks all elements within the string and returns TRUE if there is a ',' character inside it.
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == invalidChar) {
            return true;
        }
    }
    //If not, then it returns false and the program continues.
    return false;
}

